
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common.h"

uint8_t Bcd_ValidateElementIdString(
	registry_string16 String
) {
	if (String.Length != BCD_ELEMENT_ID_STRING_LENGTH)
		return 0;
	uint16_t* aBuffer = String.aBuffer;
	uint8_t bResult = 1;
	bResult &= Bcd_IsHexCharacter(aBuffer[0]);
	bResult &= Bcd_IsHexCharacter(aBuffer[1]);
	bResult &= Bcd_IsHexCharacter(aBuffer[2]);
	bResult &= Bcd_IsHexCharacter(aBuffer[3]);
	bResult &= Bcd_IsHexCharacter(aBuffer[4]);
	bResult &= Bcd_IsHexCharacter(aBuffer[5]);
	bResult &= Bcd_IsHexCharacter(aBuffer[6]);
	bResult &= Bcd_IsHexCharacter(aBuffer[7]);
	return bResult;
}

void Bcd_ElementIdToString(
	bcd_element_id Id,
	registry_string16* pString
) {
	assert(pString->AllocatedLength >= BCD_ELEMENT_ID_STRING_LENGTH);
	pString->Length = BCD_ELEMENT_ID_STRING_LENGTH;
	static const uint16_t aHexMap[] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
	};
	uint16_t* aBuffer = pString->aBuffer;
	aBuffer[0] = aHexMap[(Id >> 28) & 0xF];
	aBuffer[1] = aHexMap[(Id >> 24) & 0xF];
	aBuffer[2] = aHexMap[(Id >> 20) & 0xF];
	aBuffer[3] = aHexMap[(Id >> 16) & 0xF];
	aBuffer[4] = aHexMap[(Id >> 12) & 0xF];
	aBuffer[5] = aHexMap[(Id >> 8) & 0xF];
	aBuffer[6] = aHexMap[(Id >> 4) & 0xF];
	aBuffer[7] = aHexMap[(Id >> 0) & 0xF];
}

bcd_element_id Bcd_StringToElementId(
	registry_string16 String
) {
	assert(Bcd_ValidateElementIdString(String));
	bcd_element_id Id = 0;
	uint16_t* aBuffer = String.aBuffer;
	Id |= Bcd_HexDigitValue(aBuffer[7]) <<  0;
	Id |= Bcd_HexDigitValue(aBuffer[6]) <<  4;
	Id |= Bcd_HexDigitValue(aBuffer[5]) <<  8;
	Id |= Bcd_HexDigitValue(aBuffer[4]) << 12;
	Id |= Bcd_HexDigitValue(aBuffer[3]) << 16;
	Id |= Bcd_HexDigitValue(aBuffer[2]) << 20;
	Id |= Bcd_HexDigitValue(aBuffer[1]) << 24;
	Id |= Bcd_HexDigitValue(aBuffer[0]) << 28;
	return Id;
}

bcd_element_type Bcd_ElementIdToElementType(
	bcd_element_id ElementId
) {
	return (ElementId >> 24) & 0xF;
}

bcd_element_type Bcd_ElementIdStringToElementType(
	registry_string16 String
) {
	assert(Bcd_ValidateElementIdString(String));
	return String.aBuffer[1] - '0';
}

static registry_value_type Bcd_ElementTypeToRegistryValueType(
	bcd_element_type ElementType
) {
	switch (ElementType) {
		case Bcd_ElementType_Device:
			return REGISTRY_BINARY;
		case Bcd_ElementType_String:
			return REGISTRY_STRING;
		case Bcd_ElementType_Guid:
			return REGISTRY_STRING;
		case Bcd_ElementType_GuidList:
			return REGISTRY_MULTI_STRING;
		case Bcd_ElementType_Integer:
			return REGISTRY_BINARY;
		case Bcd_ElementType_Boolean:
			return REGISTRY_BINARY;
		case Bcd_ElementType_IntegerList:
			return REGISTRY_BINARY;
		default:
			return 0xFFFFFFFF;
	}
}

// This runs on after Registry_ValidateValueData
// TODO: Make this public and more logging.
uint8_t Bcd_ValidateElementValueData(
	bcd_element_type ElementType,
	void* pData,
	uint32_t nData
) {
	uint8_t bValid = 1;
	switch (ElementType) {
		case Bcd_ElementType_Device:
			// Observed length for GPT partition is 88.
			// There's MBR partition, VHD and others but that has to be reverse engineered.
			bValid &= (nData == 88);
			break;
		case Bcd_ElementType_String:
			break;
		case Bcd_ElementType_Guid: {
			uint32_t nString = nData / sizeof(uint16_t);
			bValid &= Bcd_ValidateGuidString((registry_string16){nString - 1, nString, pData});
			break;
		}
		case Bcd_ElementType_GuidList: {
			uint32_t nString = nData / sizeof(uint16_t);
			if (nString % (BCD_GUID_STRING_LENGTH + 1) != 1) {
				bValid = 0;
				break;
			}

			uint16_t* ss = pData;
			size_t iOffset = 0;
			while (iOffset < nString && ss[iOffset] != '\0') {
				uint16_t* s = &ss[iOffset];
				size_t nSegment = wcslen(s);
				bValid &= Bcd_ValidateGuidString((registry_string16){nSegment, nSegment, s});
				iOffset += nSegment + 1;
			}
			break;
		}
		case Bcd_ElementType_Integer:
			bValid &= (nData == sizeof(uint64_t));
			break;
		case Bcd_ElementType_Boolean:
			bValid &= (nData == 1);
			break;
		case Bcd_ElementType_IntegerList:
			bValid &= (nData % sizeof(uint64_t) == 0);
			break;
	}
	return bValid;
}

static bcd_status OpenElementByKey(
	h_bcd_object hObject,
	h_key hElementKey,
	bcd_element_id ElementId,
	h_bcd_element* phElement
) {
	// Registry type

	bcd_element_type ElementType = Bcd_ElementIdToElementType(ElementId);
	if (ElementType == 0xFFFFFFFF) {
		BCD_STDERR("Error: Invalid element type.\n");
		return STATUS_INVALID_PARAMETER;
	}
	registry_value_type ValueType = Bcd_ElementTypeToRegistryValueType(ElementType);
	
	bcd_status Status;

	// Element value

	REGISTRY_STRING_DECLARE_ASCII_LITERAL(
		aElementValueName,
		ElementValueName,
		L"Element"
	);

	h_value hElementValue;
	Status = Registry_OpenValue(hElementKey, ElementValueName, &hElementValue);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupEnd;
		BCD_STDERR("Error opening 'Element' value. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupEnd;
	}

	// Type value data

	h_value_data hValueData;
	void* pData;
	uint32_t nData;
	Status = Registry_OpenAndGetValueDataWithType(
		hElementValue,
		&hValueData,
		&pData,
		&nData,
		ValueType
	);
	if (Status) {
		if (Status == STATUS_INVALID_DATA || Status == STATUS_OBJECT_TYPE_MISMATCH) {
			Status = STATUS_NOT_FOUND;
			goto CleanupElementValue;
		}
		BCD_STDERR("Error opening 'Type' value. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupElementValue;
	}

	if (!Bcd_ValidateElementValueData(ElementType, pData, nData)) {
		Status = STATUS_NOT_FOUND;
		goto CleanupValueData;
	}

	// We only need to validate it.
	Registry_CloseValueData(hValueData);

	// Malloc

	bcd_element* pElement = malloc(sizeof(*pElement));
	if (pElement == NULL) {
		REGISTRY_STDERR("Error allocating memory for BCD element.\n");
		Status = STATUS_NO_MEMORY;
		goto CleanupElementValue;
	}
	*pElement = (bcd_element){hObject, hElementKey, hElementValue, ElementId};

	*phElement = pElement;
	return STATUS_SUCCESS;

	CleanupValueData:
	Registry_CloseValueData(hValueData);

	CleanupElementValue:
	Registry_CloseValue(hElementValue);
	
	CleanupEnd:
	return Status;
}

bcd_status Bcd_OpenElementByIdString(
	h_bcd_object hObject,
	registry_string16 IdString,
	h_bcd_object* phElement
) {
	if (!Bcd_ValidateElementIdString(IdString)) {
		BCD_STDERR("Error: Invalid element ID string.\n");
		return STATUS_INVALID_PARAMETER;
	}

	// Element key

	registry_status Status = STATUS_SUCCESS;
	bcd_object* pObject = hObject;

	h_key hElementKey;
	Status = Registry_OpenKey(pObject->hElementsKey, IdString, &hElementKey);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			return Status;
		BCD_STDERR("Error opening element key. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}

	Status = OpenElementByKey(
		hObject,
		hElementKey,
		Bcd_StringToElementId(IdString),
		phElement
	);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupElementKey;
		BCD_STDERR("Error opening element. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupElementKey;
	}

	return STATUS_SUCCESS;

	CleanupElementKey:
	Registry_CloseKey(hElementKey);

	return Status;
}

bcd_status Bcd_OpenElementById(
	h_bcd_object hObject,
	bcd_element_id Id,
	h_bcd_element* phElement
) {
	REGISTRY_STRING_DECLARE_FIXED(
		aIdBuffer,
		IdString,
		BCD_ELEMENT_ID_STRING_LENGTH
	);
	Bcd_ElementIdToString(Id, &IdString);

	return Bcd_OpenElementByIdString(hObject, IdString, phElement);
}

bcd_status Bcd_CloseElement(
	h_bcd_element hElement
) {
	bcd_element* pElement = hElement;
	Registry_CloseValue(pElement->hElementValue);
	Registry_CloseKey(pElement->hKey);
	free(pElement);
	return STATUS_SUCCESS;
}

bcd_status Bcd_QueryElementIdString(
	h_bcd_element hElement,
	registry_string16* pString
) {
	assert(pString->AllocatedLength >= BCD_ELEMENT_ID_STRING_LENGTH);
	bcd_element* pElement = hElement;
	size_t nKeyName;
	bcd_status Status = Registry_QueryKeyName(pElement->hKey, pString, &nKeyName);
	if (Status) {
		BCD_STDERR("Error querying key name. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}
	assert(nKeyName == BCD_ELEMENT_ID_STRING_LENGTH);
	return STATUS_SUCCESS;
}

typedef struct {
	h_bcd_object hObject;
	registry_subkey_iterator iSubKey;
} bcd_element_iterator_internal;

bcd_status Bcd_OpenElementIterator(
	h_bcd_object hObject,
	bcd_element_iterator* piElement
) {
	bcd_object* pObject = hObject;
	registry_subkey_iterator iSubKey;
	bcd_status Status = Registry_OpenSubKeyIterator(
		pObject->hElementsKey,
		&iSubKey
	);
	if (Status) {
		BCD_STDERR("Error opening sub-key iterator. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}

	bcd_element_iterator_internal* pIteratorStruct = malloc(sizeof(*pIteratorStruct));
	if (pIteratorStruct == NULL) {
		BCD_STDERR("Error allocation memory for element iterator.\n");
		Status = STATUS_NO_MEMORY;
		goto CleanupSubKeyIterator;
	}

	*pIteratorStruct = (bcd_element_iterator_internal){hObject, iSubKey};
	*piElement = pIteratorStruct;
	return STATUS_SUCCESS;

	CleanupSubKeyIterator:
	Registry_CloseSubKeyIterator(iSubKey);

	return Status;

}

bcd_status Bcd_CloseElementIterator(
	bcd_element_iterator iElement
) {
	bcd_element_iterator_internal* pIteratorStruct = iElement;
	bcd_status Status = Registry_CloseSubKeyIterator(pIteratorStruct->iSubKey);
	free(pIteratorStruct);
	return Status;
}

bcd_status Bcd_IsElementIteratorEnd(
	bcd_element_iterator iElement,
	uint8_t* pbResult
) {
	bcd_element_iterator_internal* pIteratorStruct = iElement;
	return Registry_IsSubKeyIteratorEnd(pIteratorStruct->iSubKey, pbResult);
}

bcd_status Bcd_OpenNextElement(
	bcd_element_iterator* piNext,
	h_bcd_element* phResultElement
) {
	bcd_element_iterator_internal* pIteratorStruct = *piNext;
	bcd_status Status = STATUS_SUCCESS;
	h_key hNextKey;
	h_bcd_element hElement;
	while (1) {
		Status = Registry_OpenNextSubKey(&pIteratorStruct->iSubKey, &hNextKey);
		if (Status) {
			if (Status == REGISTRY_STATUS_NO_MORE_ENTRIES)
				return Status;
			BCD_STDERR("Error opening next sub-key. NTSTATUS: 0x%"PRIX32"\n", Status);
			return STATUS_UNSUCCESSFUL;
		}

		REGISTRY_STRING_DECLARE_FIXED(
			aKeyName,
			KeyName,
			BCD_ELEMENT_ID_STRING_LENGTH
		);

		size_t RealKeyNameLength;
		Status = Registry_QueryKeyName(hNextKey, &KeyName, &RealKeyNameLength);
		if (Status) {
			BCD_STDERR("Error querying sub-key's name. NTSTATUS: 0x%"PRIX32"\n", Status);
			Status = STATUS_UNSUCCESSFUL;
			goto CleanupNextKeyReturn;
		}
		if (
			RealKeyNameLength != BCD_ELEMENT_ID_STRING_LENGTH ||
			!Bcd_ValidateElementIdString(KeyName)
		) {
			goto CleanupNextKeyContinue;
		}

		Status = OpenElementByKey(
			pIteratorStruct->hObject,
			hNextKey,
			Bcd_StringToElementId(KeyName),
			&hElement
		);
		if (Status) {
			// Invalid element structure.
			if (Status == STATUS_NOT_FOUND)
				goto CleanupNextKeyContinue;
			BCD_STDERR("Error opening element. NTSTATUS: 0x%"PRIX32"\n", Status);
			Status = STATUS_UNSUCCESSFUL;
			goto CleanupNextKeyReturn;
		}
		break;

		CleanupNextKeyContinue:
		Registry_CloseKey(hNextKey);
	}

	*phResultElement = hElement;
	return STATUS_SUCCESS;

	CleanupNextKeyReturn:
	Registry_CloseKey(hNextKey);

	return Status;
}

// The implementation is a bit slow but who cares
bcd_status Bcd_QueryElementId(
	h_bcd_element hElement,
	bcd_element_id* pId
) {
	bcd_element* pElement = hElement;
	*pId = pElement->Id;
	return STATUS_SUCCESS;
}

bcd_status Bcd_QueryElementValue(
	h_bcd_element hElement,
	void* pData,
	uint32_t nData,
	uint32_t* pRealSize
) {
	bcd_element* pElement = hElement;
	bcd_status Status = Registry_QueryValueDataWithTypeNative(
		pElement->hElementValue,
		pData,
		nData,
		pRealSize,
		Bcd_ElementTypeToRegistryValueType(
			Bcd_ElementIdToElementType(pElement->Id)
		)
	);
	// Assuming that the data is valid since
	// it should be validated when opening the element.
	if (Status) {
		BCD_STDERR("Error querying element value data. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}
	return STATUS_SUCCESS;
}

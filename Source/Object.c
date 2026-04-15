
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common.h"

uint8_t Bcd_ValidateGuidString(
	registry_string16 String
) {
	if (String.Length != BCD_GUID_STRING_LENGTH)
		return 0;

	uint16_t* aBuffer = String.aBuffer;
	uint8_t bResult = 1;
	bResult &= (aBuffer[0]) == '{';
	bResult &= Bcd_IsHexCharacter(aBuffer[1]);
	bResult &= Bcd_IsHexCharacter(aBuffer[2]);
	bResult &= Bcd_IsHexCharacter(aBuffer[3]);
	bResult &= Bcd_IsHexCharacter(aBuffer[4]);
	bResult &= Bcd_IsHexCharacter(aBuffer[5]);
	bResult &= Bcd_IsHexCharacter(aBuffer[6]);
	bResult &= Bcd_IsHexCharacter(aBuffer[7]);
	bResult &= Bcd_IsHexCharacter(aBuffer[8]);
	bResult &= (aBuffer[9]) == '-';
	bResult &= Bcd_IsHexCharacter(aBuffer[10]);
	bResult &= Bcd_IsHexCharacter(aBuffer[11]);
	bResult &= Bcd_IsHexCharacter(aBuffer[12]);
	bResult &= Bcd_IsHexCharacter(aBuffer[13]);
	bResult &= (aBuffer[14]) == '-';
	bResult &= Bcd_IsHexCharacter(aBuffer[15]);
	bResult &= Bcd_IsHexCharacter(aBuffer[16]);
	bResult &= Bcd_IsHexCharacter(aBuffer[17]);
	bResult &= Bcd_IsHexCharacter(aBuffer[18]);
	bResult &= (aBuffer[19]) == '-';
	bResult &= Bcd_IsHexCharacter(aBuffer[20]);
	bResult &= Bcd_IsHexCharacter(aBuffer[21]);
	bResult &= Bcd_IsHexCharacter(aBuffer[22]);
	bResult &= Bcd_IsHexCharacter(aBuffer[23]);
	bResult &= (aBuffer[24]) == '-';
	bResult &= Bcd_IsHexCharacter(aBuffer[25]);
	bResult &= Bcd_IsHexCharacter(aBuffer[26]);
	bResult &= Bcd_IsHexCharacter(aBuffer[27]);
	bResult &= Bcd_IsHexCharacter(aBuffer[28]);
	bResult &= Bcd_IsHexCharacter(aBuffer[29]);
	bResult &= Bcd_IsHexCharacter(aBuffer[30]);
	bResult &= Bcd_IsHexCharacter(aBuffer[31]);
	bResult &= Bcd_IsHexCharacter(aBuffer[32]);
	bResult &= Bcd_IsHexCharacter(aBuffer[33]);
	bResult &= Bcd_IsHexCharacter(aBuffer[34]);
	bResult &= Bcd_IsHexCharacter(aBuffer[35]);
	bResult &= Bcd_IsHexCharacter(aBuffer[36]);
	bResult &= (aBuffer[37]) == '}';
	return bResult;
}

void Bcd_GuidToString16(
	bcd_guid pGuid,
	registry_string16 *pString
) {
	assert(pString->AllocatedLength >= BCD_GUID_STRING_LENGTH);
	static const uint16_t aHexMap[] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
	};
	uint16_t* aBuffer = pString->aBuffer;
	aBuffer[0] = '{';
	aBuffer[1] = aHexMap[(pGuid.Data0 >> 28) & 0xF];
	aBuffer[2] = aHexMap[(pGuid.Data0 >> 24) & 0xF];
	aBuffer[3] = aHexMap[(pGuid.Data0 >> 20) & 0xF];
	aBuffer[4] = aHexMap[(pGuid.Data0 >> 16) & 0xF];
	aBuffer[5] = aHexMap[(pGuid.Data0 >> 12) & 0xF];
	aBuffer[6] = aHexMap[(pGuid.Data0 >> 8) & 0xF];
	aBuffer[7] = aHexMap[(pGuid.Data0 >> 4) & 0xF];
	aBuffer[8] = aHexMap[(pGuid.Data0 >> 0) & 0xF];
	aBuffer[9] = '-';
	aBuffer[10] = aHexMap[(pGuid.Data1 >> 12) & 0xF];
	aBuffer[11] = aHexMap[(pGuid.Data1 >> 8) & 0xF];
	aBuffer[12] = aHexMap[(pGuid.Data1 >> 4) & 0xF];
	aBuffer[13] = aHexMap[(pGuid.Data1 >> 0) & 0xF];
	aBuffer[14] = '-';
	aBuffer[15] = aHexMap[(pGuid.Data2 >> 12) & 0xF];
	aBuffer[16] = aHexMap[(pGuid.Data2 >> 8) & 0xF];
	aBuffer[17] = aHexMap[(pGuid.Data2 >> 4) & 0xF];
	aBuffer[18] = aHexMap[(pGuid.Data2 >> 0) & 0xF];
	aBuffer[19] = '-';
	aBuffer[20] = aHexMap[(pGuid.Data3[0] >> 4) & 0xF];
	aBuffer[21] = aHexMap[(pGuid.Data3[0] >> 0) & 0xF];
	aBuffer[22] = aHexMap[(pGuid.Data3[1] >> 4) & 0xF];
	aBuffer[23] = aHexMap[(pGuid.Data3[1] >> 0) & 0xF];
	aBuffer[24] = '-';
	aBuffer[25] = aHexMap[(pGuid.Data4[0] >> 4) & 0xF];
	aBuffer[26] = aHexMap[(pGuid.Data4[0] >> 0) & 0xF];
	aBuffer[27] = aHexMap[(pGuid.Data4[1] >> 4) & 0xF];
	aBuffer[28] = aHexMap[(pGuid.Data4[1] >> 0) & 0xF];
	aBuffer[29] = aHexMap[(pGuid.Data4[2] >> 4) & 0xF];
	aBuffer[30] = aHexMap[(pGuid.Data4[2] >> 0) & 0xF];
	aBuffer[31] = aHexMap[(pGuid.Data4[3] >> 4) & 0xF];
	aBuffer[32] = aHexMap[(pGuid.Data4[3] >> 0) & 0xF];
	aBuffer[33] = aHexMap[(pGuid.Data4[4] >> 4) & 0xF];
	aBuffer[34] = aHexMap[(pGuid.Data4[4] >> 0) & 0xF];
	aBuffer[35] = aHexMap[(pGuid.Data4[5] >> 4) & 0xF];
	aBuffer[36] = aHexMap[(pGuid.Data4[5] >> 0) & 0xF];
	aBuffer[37] = '}';
	pString->Length = BCD_GUID_STRING_LENGTH;
}

static bcd_status OpenObjectByKey(
	h_bcd_store hStore,
	h_key hObjectKey,
	h_bcd_object* phObject
) {
	bcd_status Status = STATUS_SUCCESS;

	// Description key

	REGISTRY_STRING_DECLARE_ASCII_LITERAL(
		aDescriptionKeyName,
		DescriptionKeyName,
		L"Description"
	);

	h_key hDescriptionKey;
	Status = Registry_OpenKey(hObjectKey, DescriptionKeyName, &hDescriptionKey);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			return Status;
		BCD_STDERR("Error opening 'Description' key. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}

	// Type value

	REGISTRY_STRING_DECLARE_ASCII_LITERAL(
		aTypeValueName,
		TypeValueName,
		L"Type"
	);

	h_value hTypeValue;
	Status = Registry_OpenValue(hDescriptionKey, TypeValueName, &hTypeValue);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupDescriptionKey;
		BCD_STDERR("Error opening 'Type' value. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupDescriptionKey;
	}

	// Type value data

	uint32_t ObjectType;
	uint32_t RealSize;
	Status = Registry_QueryValueDataWithTypeNative(
		hTypeValue,
		&ObjectType,
		sizeof(ObjectType),
		&RealSize,
		REGISTRY_INT32LE
	);
	if (Status) {
		if (Status == STATUS_INVALID_DATA) {
			Status = STATUS_NOT_FOUND;
			goto CleanupTypeValue;
		}
		BCD_STDERR("Error opening 'Type' value. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupTypeValue;
	}

	// Elements key

	REGISTRY_STRING_DECLARE_ASCII_LITERAL(
		aElementsKeyName,
		ElementsKeyName,
		L"Elements"
	);

	h_key hElementsKey;
	Status = Registry_OpenKey(hObjectKey, ElementsKeyName, &hElementsKey);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupTypeValue;
		BCD_STDERR("Error opening 'Elements' key. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupTypeValue;
	}

	// Malloc

	bcd_object* pObject = malloc(sizeof(*pObject));
	if (pObject == NULL) {
		REGISTRY_STDERR("Error allocating memory for BCD object.\n");
		Status = STATUS_NO_MEMORY;
		goto CleanupElementsKey;
	}
	*pObject = (bcd_object){hStore, hObjectKey, hDescriptionKey, hTypeValue, hElementsKey, ObjectType};

	*phObject = pObject;
	return STATUS_SUCCESS;

	CleanupElementsKey:
	Registry_CloseKey(hElementsKey);

	CleanupTypeValue:
	Registry_CloseValue(hTypeValue);

	CleanupDescriptionKey:
	Registry_CloseKey(hDescriptionKey);
	
	return Status;
}

// This does not handle stuff like {bootmgr}
bcd_status Bcd_OpenObjectByGuidString(
	h_bcd_store hStore,
	registry_string16 GuidString,
	h_bcd_object* phObject
) {
	// Object key

	registry_status Status = STATUS_SUCCESS;
	bcd_store* pStore = hStore;

	if (!Bcd_ValidateGuidString(GuidString)) {
		BCD_STDERR("Error: Invalid GUID string.\n");
		return STATUS_INVALID_PARAMETER;
	}

	h_key hObjectKey;
	Status = Registry_OpenKey(pStore->hObjectsKey, GuidString, &hObjectKey);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			return Status;
		BCD_STDERR("Error opening object key. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}

	Status = OpenObjectByKey(hStore, hObjectKey, phObject);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupObjectKey;
		BCD_STDERR("Error opening object. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupObjectKey;
	}

	return STATUS_SUCCESS;

	CleanupObjectKey:
	Registry_CloseKey(hObjectKey);

	return Status;
}

bcd_status Bcd_OpenObjectByGuid(
	h_bcd_store hStore,
	const bcd_guid* pGuid,
	h_bcd_object *phObject
) {
	REGISTRY_STRING_DECLARE_FIXED(
		aGuidBuffer,
		GuidString,
		BCD_GUID_STRING_LENGTH
	);
	Bcd_GuidToString16(*pGuid, &GuidString);

	return Bcd_OpenObjectByGuidString(hStore, GuidString, phObject);
}

bcd_status Bcd_CloseObject(
	h_bcd_object hObject
) {
	bcd_object* pObject = hObject;
	Registry_CloseKey(pObject->hElementsKey);
	Registry_CloseValue(pObject->hTypeValue);
	Registry_CloseKey(pObject->hDescriptionKey);
	Registry_CloseKey(pObject->hObjectKey);
	free(pObject);
	return STATUS_SUCCESS; // TODO: Error handling
}

bcd_status Bcd_QueryObjectGuidString(
	h_bcd_object hObject,
	registry_string16* pString
) {
	assert(pString->AllocatedLength >= BCD_GUID_STRING_LENGTH);

	bcd_object* pObject = hObject;
	size_t nKeyName;
	bcd_status Status = Registry_QueryKeyName(pObject->hObjectKey, pString, &nKeyName);
	if (Status) {
		BCD_STDERR("Error querying key name. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}
	assert(nKeyName == BCD_GUID_STRING_LENGTH);

	return STATUS_SUCCESS;
}

bcd_status Bcd_QueryObjectType(
	h_bcd_object hObject,
	bcd_object_type* pResult
) {

	bcd_object* pObject = hObject;
	*pResult = pObject->Type;
	return STATUS_SUCCESS;
}

// Object enum

typedef struct {
	h_bcd_store hStore;
	registry_subkey_iterator iSubKey;
} bcd_object_iterator_internal;

bcd_status Bcd_OpenObjectIterator(
	h_bcd_store hStore,
	bcd_object_iterator* piObject
) {
	bcd_store* pStore = hStore;
	registry_subkey_iterator iSubKey;
	bcd_status Status = Registry_OpenSubKeyIterator(
		pStore->hObjectsKey,
		&iSubKey
	);
	if (Status) {
		BCD_STDERR("Error opening sub-key iterator. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_UNSUCCESSFUL;
	}
	bcd_object_iterator_internal* pIteratorStruct = malloc(sizeof(*pIteratorStruct));
	if (pIteratorStruct == NULL) {
		BCD_STDERR("Error allocation memory for object iterator.\n");
		Status = STATUS_NO_MEMORY;
		goto CleanupSubKeyIterator;
	}
	*pIteratorStruct = (bcd_object_iterator_internal){hStore, iSubKey};

	*piObject = pIteratorStruct;
	return STATUS_SUCCESS;

	CleanupSubKeyIterator:
	Registry_CloseSubKeyIterator(iSubKey);

	return Status;
}

bcd_status Bcd_CloseObjectIterator(
	bcd_object_iterator iObject
) {
	bcd_object_iterator_internal* pIteratorStruct = iObject;
	bcd_status Status = Registry_CloseSubKeyIterator(pIteratorStruct->iSubKey);
	free(pIteratorStruct);
	return Status;
}

bcd_status Bcd_IsObjectIteratorEnd(
	bcd_object_iterator iObject,
	uint8_t* pbResult
) {
	bcd_object_iterator_internal* pIteratorStruct = iObject;
	return Registry_IsSubKeyIteratorEnd(pIteratorStruct->iSubKey, pbResult);
}

bcd_status Bcd_OpenNextObject(
	bcd_object_iterator* piNext,
	h_bcd_object* phResultObject
) {
	bcd_object_iterator_internal* pIteratorStruct = *piNext;
	bcd_status Status = STATUS_SUCCESS;
	h_key hNextKey;
	h_bcd_object hObject;
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
			BCD_GUID_STRING_LENGTH
		);

		size_t RealKeyNameLength;
		Status = Registry_QueryKeyName(hNextKey, &KeyName, &RealKeyNameLength);
		if (Status) {
			BCD_STDERR("Error getting sub-key's name. NTSTATUS: 0x%"PRIX32"\n", Status);
			Status = STATUS_UNSUCCESSFUL;
			goto CleanupNextKeyReturn;
		}
		if (
			RealKeyNameLength != BCD_GUID_STRING_LENGTH ||
			!Bcd_ValidateGuidString(KeyName)
		) {
			goto CleanupNextKeyContinue;
		}

		Status = OpenObjectByKey(pIteratorStruct->hStore, hNextKey, &hObject);
		if (Status) {
			// Invalid object structure.
			if (Status == STATUS_NOT_FOUND)
				goto CleanupNextKeyContinue;
			BCD_STDERR("Error opening object. NTSTATUS: 0x%"PRIX32"\n", Status);
			Status = STATUS_UNSUCCESSFUL;
			goto CleanupNextKeyReturn;
		}
		break;

		CleanupNextKeyContinue:
		Registry_CloseKey(hNextKey);
	}

	*phResultObject = hObject;
	return STATUS_SUCCESS;

	CleanupNextKeyReturn:
	Registry_CloseKey(hNextKey);

	return Status;
}

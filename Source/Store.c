
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common.h"

bcd_status Bcd_LoadStore(
	h_bcd_store* phStore,
	void* pData,
	size_t nData,
	bcd_store_save_handler* pSaveHandler,
	void* SaveParameter
) {
	bcd_status Status;
	h_hive hHive;
	Status = Registry_LoadHive(&hHive, pData, nData, pSaveHandler, SaveParameter);
	if (Status) {
		BCD_STDERR("Error loading registry hive. NTSTATUS: 0x%"PRIX32"\n", Status);
		return STATUS_CANNOT_LOAD_REGISTRY_FILE;
	}

	// Root key

	h_key hRootKey;
	Status = Registry_OpenRootKey(hHive, &hRootKey);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupHive;
		BCD_STDERR("Error opening root key. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupHive;
	}

	// Description key

	REGISTRY_STRING_DECLARE_ASCII_LITERAL(
		aDescriptionKeyName,
		DescriptionKeyName,
		L"Description"
	);

	h_key hDescriptionKey;
	Status = Registry_OpenKey(hRootKey, DescriptionKeyName, &hDescriptionKey);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupRootKey;
		BCD_STDERR("Error opening 'Description' key. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupRootKey;
	}

	// Objects key

	REGISTRY_STRING_DECLARE_ASCII_LITERAL(
		aObjectsKeyName,
		ObjectsKeyName,
		L"Objects"
	);

	h_key hObjectsKey;
	Status = Registry_OpenKey(hRootKey, ObjectsKeyName, &hObjectsKey);
	if (Status) {
		if (Status == STATUS_NOT_FOUND)
			goto CleanupDescriptionKey;
		BCD_STDERR("Error opening 'Objects' key. NTSTATUS: 0x%"PRIX32"\n", Status);
		Status = STATUS_UNSUCCESSFUL;
		goto CleanupDescriptionKey;
	}

	// Malloc

	bcd_store* pBcdStore = malloc(sizeof(*pBcdStore));
	if (pBcdStore == NULL) {
		REGISTRY_STDERR("Error allocating memory for BCD store.\n");
		Status = STATUS_NO_MEMORY;
		goto CleanupObjectsKey;
	}
	*pBcdStore = (bcd_store){hHive, hRootKey, hDescriptionKey, hObjectsKey};

	// Try to find the default object

	REGISTRY_STRING_DECLARE_ASCII_LITERAL(
		aBootMgrGuid,
		BootMgrGuid,
		L"{9dea862c-5cdd-4e70-acc1-f32b344d4795}"
	);
	h_bcd_object hBootMgrObject;
	h_bcd_element hDefaultObjectElement;

	Status = Bcd_OpenObjectByGuidString(pBcdStore, BootMgrGuid, &hBootMgrObject);
	if (Status) {
		if (Status == STATUS_NOT_FOUND) {
			// No default object.
			memset(pBcdStore->aDefaultObject, 0, sizeof(pBcdStore->aDefaultObject));
		} else {
			BCD_STDERR("Error opening {bootmgr} object. NTSTATUS: 0x%"PRIX32"\n", Status);
			Status = STATUS_UNSUCCESSFUL;
			goto CleanupObjectsKey;
		}
	} else {
		Status = Bcd_OpenElementById(hBootMgrObject, Bcd_Element_BootMgr_DefaultObject, &hDefaultObjectElement);
		if (Status) {
			if (Status == STATUS_NOT_FOUND) {
				// No default object.
				memset(pBcdStore->aDefaultObject, 0, sizeof(pBcdStore->aDefaultObject));
			} else {
				BCD_STDERR("Error opening default object element. NTSTATUS: 0x%"PRIX32"\n", Status);
				Status = STATUS_UNSUCCESSFUL;
				goto CleanupBootMgrObject;
			}
		} else {
			uint32_t RealSize;
			Status = Bcd_QueryElementValue(hDefaultObjectElement, pBcdStore->aDefaultObject, sizeof(pBcdStore->aDefaultObject), &RealSize);
			if (Status) {
				BCD_STDERR("Error querying default object element value. NTSTATUS: 0x%"PRIX32"\n", Status);
				Status = STATUS_UNSUCCESSFUL;
				goto CleanupDefaultObjectElement;
			}
			Bcd_CloseElement(hDefaultObjectElement);
		}
		Bcd_CloseObject(hBootMgrObject);
	}

	*phStore = pBcdStore;
	return STATUS_SUCCESS;

	CleanupDefaultObjectElement:
	Bcd_CloseElement(hDefaultObjectElement);

	CleanupBootMgrObject:
	Bcd_CloseObject(hBootMgrObject);

	CleanupObjectsKey:
	Registry_CloseKey(hObjectsKey);

	CleanupDescriptionKey:
	Registry_CloseKey(hDescriptionKey);

	CleanupRootKey:
	Registry_CloseKey(hRootKey);

	CleanupHive:
	Registry_UnloadHive(hHive, 1);
	return Status;
}

bcd_status Bcd_UnloadStore(
	h_bcd_store hStore,
	uint8_t bForce
) {
	bcd_store* pBcdStore = hStore;
	Registry_CloseKey(pBcdStore->hObjectsKey);
	Registry_CloseKey(pBcdStore->hDescriptionKey);
	Registry_CloseKey(pBcdStore->hRootKey);
	Registry_UnloadHive(pBcdStore->hHive, bForce);
	free(pBcdStore);
	return STATUS_SUCCESS;
}

bcd_status Bcd_QueryDefaultObjectGuidString(
	h_bcd_store hStore,
	registry_string16* pGuidString
) {
	bcd_store* pBcdStore = hStore;
	assert(pGuidString->AllocatedLength >= BCD_GUID_STRING_LENGTH);
	memcpy(pGuidString->aBuffer, pBcdStore->aDefaultObject, sizeof(pBcdStore->aDefaultObject));
	pGuidString->Length = BCD_GUID_STRING_LENGTH;
	return STATUS_SUCCESS;
}

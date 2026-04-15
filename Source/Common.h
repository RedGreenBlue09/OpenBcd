
// SPDX-License-Identifier: GPL-2.0-or-later

#include <OpenBcd.h>
#include <Registry.h>

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATUS_SUCCESS                   ((bcd_status)0x00000000)
#define STATUS_UNSUCCESSFUL              ((bcd_status)0xC0000001)
#define STATUS_UNIMPLEMENTED             ((bcd_status)0xC0000002)
#define STATUS_INVALID_DATA				 ((bcd_status)0xC000000D)
#define STATUS_INVALID_PARAMETER		 ((bcd_status)0xC000000E)
#define STATUS_NO_MEMORY                 ((bcd_status)0xC0000017)
#define STATUS_OBJECT_TYPE_MISMATCH      ((bcd_status)0xC0000024)
#define STATUS_NOT_REGISTRY_FILE         ((bcd_status)0xC000015C)
#define STATUS_CANNOT_LOAD_REGISTRY_FILE ((bcd_status)0xC0000218)
#define STATUS_NOT_FOUND                 ((bcd_status)0xC0000225)

#define BCD_MIN(A, B) ((A) < (B) ? (A) : (B))
#define BCD_MAX(A, B) ((A) > (B) ? (A) : (B))
#define BCD_IN_RANGE(X, A, B) ((X) >= (A) && (X) <= (B))
#define BCD_ARRAY_LENGTH(X) (sizeof(X) / sizeof(*(X)))

static inline uint8_t Bcd_IsHexCharacter(uint16_t C) {
	return (C - (uint16_t)'0' <= 9U) | (C - (uint16_t)'A' <= 5U) | (C - (uint16_t)'a' <= 5U);
}

static inline uint8_t Bcd_HexDigitValue(uint16_t C) {
	assert(Bcd_IsHexCharacter(C));
	return (C - '0') - ((C >= 'A') ? ('A' - '0') : 0) - ((C >= 'a') ? ('a' - 'A') : 0);
}

typedef struct {
	h_hive hHive;
	h_key hRootKey;
	h_key hDescriptionKey;
	h_key hObjectsKey;
	uint16_t aDefaultObject[BCD_GUID_STRING_LENGTH];
} bcd_store;

typedef struct {
	h_bcd_store hStore;
	h_key hObjectKey;
	h_key hDescriptionKey;
	h_value hTypeValue;
	h_key hElementsKey;
	bcd_object_type Type;
} bcd_object;

typedef struct {
	h_bcd_object hObject;
	h_key hKey;
	h_value hElementValue;
	bcd_element_id Id;
} bcd_element;

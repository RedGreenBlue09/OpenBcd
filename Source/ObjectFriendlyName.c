
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common.h"

// Since we don't have a standard UTF-16LE string literal in C, we have to use list initializers.

static uint16_t RAW_EMS_SETTINGS_GROUP[]             = {'{', '0', 'c', 'e', '4', '9', '9', '1', 'b', '-', 'e', '6', 'b', '3', '-', '4', 'b', '1', '6', '-', 'b', '2', '3', 'c', '-', '5', 'e', '0', 'd', '9', '2', '5', '0', 'e', '5', 'd', '9', '}', }; // {0ce4991b-e6b3-4b16-b23c-5e0d9250e5d9}
static uint16_t RAW_RESUME_LOADER_SETTINGS_GROUP[]   = {'{', '1', 'a', 'f', 'a', '9', 'c', '4', '9', '-', '1', '6', 'a', 'b', '-', '4', 'a', '5', 'c', '-', '4', 'a', '9', '0', '-', '2', '1', '2', '8', '0', '2', 'd', 'a', '9', '4', '6', '0', '}', }; // {1afa9c49-16ab-4a5c-4a90-212802da9460}
static uint16_t RAW_DEFAULT_BOOT_ENTRY[]             = {'{', '1', 'c', 'a', 'e', '1', 'e', 'b', '7', '-', 'a', '0', 'd', 'f', '-', '4', 'd', '4', 'd', '-', '9', '8', '5', '1', '-', '4', '8', '6', '0', 'e', '3', '4', 'e', 'f', '5', '3', '5', '}', }; // {1cae1eb7-a0df-4d4d-9851-4860e34ef535}
static uint16_t RAW_KERNEL_DEBUGGER_SETTINGS_GROUP[] = {'{', '3', '1', '3', 'e', '8', 'e', 'e', 'd', '-', '7', '0', '9', '8', '-', '4', '5', '8', '6', '-', 'a', '9', 'b', 'f', '-', '3', '0', '9', 'c', '6', '1', 'f', '8', 'd', '4', '4', '9', '}', }; // {313e8eed-7098-4586-a9bf-309c61f8d449}
static uint16_t RAW_DEBUGGER_SETTINGS_GROUP[]        = {'{', '4', '6', '3', '6', '8', '5', '6', 'e', '-', '5', '4', '0', 'f', '-', '4', '1', '7', '0', '-', 'a', '1', '3', '0', '-', 'a', '8', '4', '7', '7', '6', 'f', '4', 'c', '6', '5', '4', '}', }; // {4636856e-540f-4170-a130-a84776f4c654}
static uint16_t RAW_WINDOWS_LEGACY_NTLDR[]           = {'{', '4', '6', '6', 'f', '5', 'a', '8', '8', '-', '0', 'a', 'f', '2', '-', '4', 'f', '7', '6', '-', '9', '0', '3', '8', '-', '0', '9', '5', 'b', '1', '7', '0', 'd', 'c', '2', '1', 'c', '}', }; // {466f5a88-0af2-4f76-9038-095b170dc21c}
static uint16_t RAW_BAD_MEMORY_GROUP[]               = {'{', '5', '1', '8', '9', 'b', '2', '5', 'c', '-', '5', '5', '5', '8', '-', '4', 'b', 'f', '2', '-', 'b', 'c', 'a', '4', '-', '2', '8', '9', 'b', '1', '1', 'b', 'd', '2', '9', 'e', '2', '}', }; // {5189b25c-5558-4bf2-bca4-289b11bd29e2}
static uint16_t RAW_BOOT_LOADER_SETTINGS_GROUP[]     = {'{', '6', 'e', 'f', 'b', '5', '2', 'b', 'f', '-', '1', '7', '6', '6', '-', '4', '1', 'd', 'b', '-', 'a', '6', 'b', '3', '-', '0', 'e', 'e', '5', 'e', 'f', 'f', '7', '2', 'b', 'd', '7', '}', }; // {6efb52bf-1766-41db-a6b3-0ee5eff72bd7}
static uint16_t RAW_GLOBAL_SETTINGS_GROUP[]          = {'{', '7', 'e', 'a', '2', 'e', '1', 'a', 'c', '-', '2', 'e', '6', '1', '-', '4', '7', '2', '8', '-', 'a', 'a', 'a', '3', '-', '8', '9', '6', 'd', '9', 'd', '0', 'a', '9', 'f', '0', 'e', '}', }; // {7ea2e1ac-2e61-4728-aaa3-896d9d0a9f0e}
static uint16_t RAW_HYPERVISOR_SETTINGS_GROUP[]      = {'{', '7', 'f', 'f', '6', '0', '7', 'e', '0', '-', '4', '3', '9', '5', '-', '1', '1', 'd', 'b', '-', 'b', '0', 'd', 'e', '-', '0', '8', '0', '0', '2', '0', '0', 'c', '9', 'a', '6', '6', '}', }; // {7ff607e0-4395-11db-b0de-0800200c9a66}
static uint16_t RAW_WINDOWS_BOOTMGR[]                = {'{', '9', 'd', 'e', 'a', '8', '6', '2', 'c', '-', '5', 'c', 'd', 'd', '-', '4', 'e', '7', '0', '-', 'a', 'c', 'c', '1', '-', 'f', '3', '2', 'b', '3', '4', '4', 'd', '4', '7', '9', '5', '}', }; // {9dea862c-5cdd-4e70-acc1-f32b344d4795}
static uint16_t RAW_FIRMWARE_BOOTMGR[]               = {'{', 'a', '5', 'a', '3', '0', 'f', 'a', '2', '-', '3', 'd', '0', '6', '-', '4', 'e', '9', 'f', '-', 'b', '5', 'f', '4', '-', 'a', '0', '1', 'd', 'f', '9', 'd', '1', 'f', 'c', 'b', 'a', '}', }; // {a5a30fa2-3d06-4e9f-b5f4-a01df9d1fcba}
static uint16_t RAW_WINDOWS_SETUP_RAMDISK_OPTIONS[]  = {'{', 'a', 'e', '5', '5', '3', '4', 'e', '0', '-', 'a', '9', '2', '4', '-', '4', '6', '6', 'c', '-', 'b', '8', '3', '6', '-', '7', '5', '8', '5', '3', '9', 'a', '3', 'e', 'e', '3', 'a', '}', }; // {ae5534e0-a924-466c-b836-758539a3ee3a}
static uint16_t RAW_WINDOWS_MEMORY_TESTER[]          = {'{', 'b', '2', '7', '2', '1', 'd', '7', '3', '-', '1', 'd', 'b', '4', '-', '4', 'c', '6', '2', '-', 'b', 'f', '7', '8', '-', 'c', '5', '4', '8', 'a', '8', '8', '0', '1', '4', '2', 'd', '}', }; // {b2721d73-1db4-4c62-bf78-c548a880142d}
static uint16_t RAW_CURRENT_BOOT_ENTRY[]             = {'{', 'f', 'a', '9', '2', '6', '4', '9', '3', '-', '6', 'f', '1', 'c', '-', '4', '1', '9', '3', '-', 'a', '4', '1', '4', '-', '5', '8', 'f', '0', 'b', '2', '4', '5', '6', 'd', '1', 'e', '}', }; // {fa926493-6f1c-4193-a414-58f0b2456d1e}

static uint16_t FRIENDLY_EMS_SETTINGS_GROUP[]             = {'{', 'e', 'm', 's', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', };                                              // {emssettings}
static uint16_t FRIENDLY_RESUME_LOADER_SETTINGS_GROUP[]   = {'{', 'r', 'e', 's', 'u', 'm', 'e', 'l', 'o', 'a', 'd', 'e', 'r', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', }; // {resumeloadersettings}
static uint16_t FRIENDLY_DEFAULT_BOOT_ENTRY[]             = {'{', 'd', 'e', 'f', 'a', 'u', 'l', 't', '}', };                                                                  // {default}
static uint16_t FRIENDLY_KERNEL_DEBUGGER_SETTINGS_GROUP[] = {'{', 'k', 'e', 'r', 'n', 'e', 'l', 'd', 'b', 'g', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', };                // {kerneldbgsettings}
static uint16_t FRIENDLY_DEBUGGER_SETTINGS_GROUP_0[]      = {'{', 'd', 'b', 'g', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', };                                              // {dbgsettings}
static uint16_t FRIENDLY_DEBUGGER_SETTINGS_GROUP_1[]      = {'{', 'e', 'v', 'e', 'n', 't', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', };                                    // {eventsettings}
static uint16_t FRIENDLY_WINDOWS_LEGACY_NTLDR_0[]         = {'{', 'l', 'e', 'g', 'a', 'c', 'y', '}', };                                                                       // {legacy}
static uint16_t FRIENDLY_WINDOWS_LEGACY_NTLDR_1[]         = {'{', 'n', 't', 'l', 'd', 'r', '}', };                                                                            // {ntldr}
static uint16_t FRIENDLY_BAD_MEMORY_GROUP[]               = {'{', 'b', 'a', 'd', 'm', 'e', 'm', 'o', 'r', 'y', '}', };                                                        // {badmemory}
static uint16_t FRIENDLY_BOOT_LOADER_SETTINGS_GROUP[]     = {'{', 'b', 'o', 'o', 't', 'l', 'o', 'a', 'd', 'e', 'r', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', };           // {bootloadersettings}
static uint16_t FRIENDLY_GLOBAL_SETTINGS_GROUP[]          = {'{', 'g', 'l', 'o', 'b', 'a', 'l', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', };                               // {globalsettings}
static uint16_t FRIENDLY_HYPERVISOR_SETTINGS_GROUP[]      = {'{', 'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 's', 'e', 't', 't', 'i', 'n', 'g', 's', '}', };           // {hypervisorsettings}
static uint16_t FRIENDLY_WINDOWS_BOOTMGR[]                = {'{', 'b', 'o', 'o', 't', 'm', 'g', 'r', '}', };                                                                  // {bootmgr}
static uint16_t FRIENDLY_FIRMWARE_BOOTMGR[]               = {'{', 'f', 'w', 'b', 'o', 'o', 't', 'm', 'g', 'r', '}', };                                                        // {fwbootmgr}
static uint16_t FRIENDLY_WINDOWS_SETUP_RAMDISK_OPTIONS[]  = {'{', 'r', 'a', 'm', 'd', 'i', 's', 'k', 'o', 'p', 't', 'i', 'o', 'n', 's', '}', };                               // {ramdiskoptions}
static uint16_t FRIENDLY_WINDOWS_MEMORY_TESTER[]          = {'{', 'm', 'e', 'm', 'd', 'i', 'a', 'g', '}', };                                                                  // {memdiag}
static uint16_t FRIENDLY_CURRENT_BOOT_ENTRY[]             = {'{', 'c', 'u', 'r', 'r', 'e', 'n', 't', '}', };                                                                  // {current}                                                             // {default}

// Since we can't have constexpr hash map, let's just use binary search.

typedef struct {
	registry_string16 FriendlyName;
	registry_string16 GuidString;
} bcd_friendly_name_pair;

// bcdedit /enum doesn't handle {1cae1eb7-a0df-4d4d-9851-4860e34ef535} quite well
// It will mirrors the actual default object's element and show the guid as
// {1cae1eb7-a0df-4d4d-9851-4860e34ef535} instead of {default}.
// If the default is not set, then it will not show this object at all.
// If the default is set to this one, it will show normally.
// Probably the same for {fa926493-6f1c-4193-a414-58f0b2456d1e}.
// For this program, we'll treat these special guids as a normal.

static const bcd_friendly_name_pair gaFriendlyNameMap[] = {
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_BAD_MEMORY_GROUP),               REGISTRY_STRING_INIT_BUFFER(RAW_BAD_MEMORY_GROUP)},               // {badmemory}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_BOOT_LOADER_SETTINGS_GROUP),     REGISTRY_STRING_INIT_BUFFER(RAW_BOOT_LOADER_SETTINGS_GROUP)},     // {bootloadersettings}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_BOOTMGR),                REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_BOOTMGR)},                // {bootmgr}
	//{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_CURRENT_BOOT_ENTRY),             REGISTRY_STRING_INIT_BUFFER(RAW_CURRENT_BOOT_ENTRY)},             // {current}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_DEBUGGER_SETTINGS_GROUP_0),      REGISTRY_STRING_INIT_BUFFER(RAW_DEBUGGER_SETTINGS_GROUP)},        // {dbgsettings}
	//{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_DEFAULT_BOOT_ENTRY),             REGISTRY_STRING_INIT_BUFFER(RAW_DEFAULT_BOOT_ENTRY)},             // {default}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_EMS_SETTINGS_GROUP),             REGISTRY_STRING_INIT_BUFFER(RAW_EMS_SETTINGS_GROUP)},             // {emssettings}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_DEBUGGER_SETTINGS_GROUP_1),      REGISTRY_STRING_INIT_BUFFER(RAW_DEBUGGER_SETTINGS_GROUP)},        // {eventsettings}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_FIRMWARE_BOOTMGR),               REGISTRY_STRING_INIT_BUFFER(RAW_FIRMWARE_BOOTMGR)},               // {fwbootmgr}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_GLOBAL_SETTINGS_GROUP),          REGISTRY_STRING_INIT_BUFFER(RAW_GLOBAL_SETTINGS_GROUP)},          // {globalsettings}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_HYPERVISOR_SETTINGS_GROUP),      REGISTRY_STRING_INIT_BUFFER(RAW_HYPERVISOR_SETTINGS_GROUP)},      // {hypervisorsettings}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_KERNEL_DEBUGGER_SETTINGS_GROUP), REGISTRY_STRING_INIT_BUFFER(RAW_KERNEL_DEBUGGER_SETTINGS_GROUP)}, // {kerneldbgsettings}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_LEGACY_NTLDR_0),         REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_LEGACY_NTLDR)},           // {legacy}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_MEMORY_TESTER),          REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_MEMORY_TESTER)},          // {memdiag}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_LEGACY_NTLDR_1),         REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_LEGACY_NTLDR)},           // {ntldr}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_SETUP_RAMDISK_OPTIONS),  REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_SETUP_RAMDISK_OPTIONS)},  // {ramdiskoptions}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_RESUME_LOADER_SETTINGS_GROUP),   REGISTRY_STRING_INIT_BUFFER(RAW_RESUME_LOADER_SETTINGS_GROUP)},   // {resumeloadersettings}
};

static const bcd_friendly_name_pair gaRawGuidMap[] = {
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_EMS_SETTINGS_GROUP),             REGISTRY_STRING_INIT_BUFFER(RAW_EMS_SETTINGS_GROUP)},             // {0CE4991B-E6B3-4B16-B23C-5E0D9250E5D9}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_RESUME_LOADER_SETTINGS_GROUP),   REGISTRY_STRING_INIT_BUFFER(RAW_RESUME_LOADER_SETTINGS_GROUP)},   // {1AFA9C49-16AB-4A5C-4A90-212802DA9460}
	//{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_DEFAULT_BOOT_ENTRY),             REGISTRY_STRING_INIT_BUFFER(RAW_DEFAULT_BOOT_ENTRY)},             // {1CAE1EB7-A0DF-4D4D-9851-4860E34EF535}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_KERNEL_DEBUGGER_SETTINGS_GROUP), REGISTRY_STRING_INIT_BUFFER(RAW_KERNEL_DEBUGGER_SETTINGS_GROUP)}, // {313E8EED-7098-4586-A9BF-309C61F8D449}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_DEBUGGER_SETTINGS_GROUP_0),      REGISTRY_STRING_INIT_BUFFER(RAW_DEBUGGER_SETTINGS_GROUP)},        // {4636856E-540F-4170-A130-A84776F4C654}
	//{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_DEBUGGER_SETTINGS_GROUP_1),      REGISTRY_STRING_INIT_BUFFER(RAW_DEBUGGER_SETTINGS_GROUP)},        // {4636856E-540F-4170-A130-A84776F4C654}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_LEGACY_NTLDR_0),         REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_LEGACY_NTLDR)},           // {466F5A88-0AF2-4F76-9038-095B170DC21C}
	//{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_LEGACY_NTLDR_1),         REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_LEGACY_NTLDR)},           // {466F5A88-0AF2-4F76-9038-095B170DC21C}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_BAD_MEMORY_GROUP),               REGISTRY_STRING_INIT_BUFFER(RAW_BAD_MEMORY_GROUP)},               // {5189B25C-5558-4BF2-BCA4-289B11BD29E2}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_BOOT_LOADER_SETTINGS_GROUP),     REGISTRY_STRING_INIT_BUFFER(RAW_BOOT_LOADER_SETTINGS_GROUP)},     // {6EFB52BF-1766-41DB-A6B3-0EE5EFF72BD7}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_GLOBAL_SETTINGS_GROUP),          REGISTRY_STRING_INIT_BUFFER(RAW_GLOBAL_SETTINGS_GROUP)},          // {7EA2E1AC-2E61-4728-AAA3-896D9D0A9F0E}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_HYPERVISOR_SETTINGS_GROUP),      REGISTRY_STRING_INIT_BUFFER(RAW_HYPERVISOR_SETTINGS_GROUP)},      // {7FF607E0-4395-11DB-B0DE-0800200C9A66}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_BOOTMGR),                REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_BOOTMGR)},                // {9DEA862C-5CDD-4E70-ACC1-F32B344D4795}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_FIRMWARE_BOOTMGR),               REGISTRY_STRING_INIT_BUFFER(RAW_FIRMWARE_BOOTMGR)},               // {A5A30FA2-3D06-4E9F-B5F4-A01DF9D1FCBA}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_SETUP_RAMDISK_OPTIONS),  REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_SETUP_RAMDISK_OPTIONS)},  // {AE5534E0-A924-466C-B836-758539A3EE3A}
	{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_WINDOWS_MEMORY_TESTER),          REGISTRY_STRING_INIT_BUFFER(RAW_WINDOWS_MEMORY_TESTER)},          // {B2721D73-1DB4-4C62-BF78-C548A880142D}
	//{REGISTRY_STRING_INIT_BUFFER(FRIENDLY_CURRENT_BOOT_ENTRY),             REGISTRY_STRING_INIT_BUFFER(RAW_CURRENT_BOOT_ENTRY)},             // {FA926493-6F1C-4193-A414-58F0B2456D1E}
};

static uint16_t DESCRIPTION_APP_FWBOOTMGR[]  = {'F', 'i', 'r', 'm', 'w', 'a', 'r', 'e', ' ', 'B', 'o', 'o', 't', ' ', 'M', 'a', 'n', 'a', 'g', 'e', 'r', };                               // Firmware Boot Manager
static uint16_t DESCRIPTION_APP_BOOTMGR[]    = {'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'B', 'o', 'o', 't', ' ', 'M', 'a', 'n', 'a', 'g', 'e', 'r', };                                    // Windows Boot Manager
static uint16_t DESCRIPTION_APP_OSLOADER[]   = {'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'B', 'o', 'o', 't', ' ', 'L', 'o', 'a', 'd', 'e', 'r', };                                         // Windows Boot Loader
static uint16_t DESCRIPTION_APP_RESUME[]     = {'R', 'e', 's', 'u', 'm', 'e', ' ', 'f', 'r', 'o', 'm', ' ', 'H', 'i', 'b', 'e', 'r', 'n', 'a', 't', 'e', };                               // Resume from Hibernate
static uint16_t DESCRIPTION_APP_EMDIAG[]     = {'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'M', 'e', 'm', 'o', 'r', 'y', ' ', 'T', 'e', 's', 't', 'e', 'r', };                               // Windows Memory Tester
static uint16_t DESCRIPTION_APP_NTLDR[]      = {'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'L', 'e', 'g', 'a', 'c', 'y', ' ', 'O', 'S', ' ', 'L', 'o', 'a', 'd', 'e', 'r', };                // Windows Legacy OS Loader
static uint16_t DESCRIPTION_APP_SETUPLDR[]   = {'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'L', 'e', 'g', 'a', 'c', 'y', ' ', 'S', 'e', 't', 'u', 'p', ' ', 'L', 'o', 'a', 'd', 'e', 'r', }; // Windows Legacy Setup Loader
static uint16_t DESCRIPTION_APP_BOOTSECTOR[] = {'R', 'e', 'a', 'l', '-', 'm', 'o', 'd', 'e', ' ', 'B', 'o', 'o', 't', ' ', 'S', 'e', 'c', 't', 'o', 'r', };                               // Real-mode Boot Sector
static uint16_t DESCRIPTION_APP_STARTUP[]    = {'R', 'e', 'a', 'l', '-', 'm', 'o', 'd', 'e', ' ', 'A', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                               // Real-mode Application
static uint16_t DESCRIPTION_APP_BOOTAPP[]    = {'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'B', 'o', 'o', 't', ' ', 'A', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                // Windows Boot Application

static uint16_t DESCRIPTION_INHERIT_GENERIC[]    = {'G', 'e', 'n', 'e', 'r', 'i', 'c', ' ', 'i', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', };                                                                                                                         // Generic inheritable object
static uint16_t DESCRIPTION_INHERIT_FWBOOTMGR[]  = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'F', 'i', 'r', 'm', 'w', 'a', 'r', 'e', ' ', 'B', 'o', 'o', 't', ' ', 'M', 'a', 'n', 'a', 'g', 'e', 'r', };                               // Inheritable object for Firmware Boot Manager
static uint16_t DESCRIPTION_INHERIT_BOOTMGR[]    = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'B', 'o', 'o', 't', ' ', 'M', 'a', 'n', 'a', 'g', 'e', 'r', };                                    // Inheritable object for Windows Boot Manager
static uint16_t DESCRIPTION_INHERIT_OSLOADER[]   = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'B', 'o', 'o', 't', ' ', 'L', 'o', 'a', 'd', 'e', 'r', };                                         // Inheritable object for Windows Boot Loader
static uint16_t DESCRIPTION_INHERIT_RESUME[]     = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'R', 'e', 's', 'u', 'm', 'e', ' ', 'f', 'r', 'o', 'm', ' ', 'H', 'i', 'b', 'e', 'r', 'n', 'a', 't', 'e', };                               // Inheritable object for Resume from Hibernate
static uint16_t DESCRIPTION_INHERIT_EMDIAG[]     = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'M', 'e', 'm', 'o', 'r', 'y', ' ', 'T', 'e', 's', 't', 'e', 'r', };                               // Inheritable object for Windows Memory Tester
static uint16_t DESCRIPTION_INHERIT_NTLDR[]      = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'L', 'e', 'g', 'a', 'c', 'y', ' ', 'O', 'S', ' ', 'L', 'o', 'a', 'd', 'e', 'r', };                // Inheritable object for Windows Legacy OS Loader
static uint16_t DESCRIPTION_INHERIT_SETUPLDR[]   = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'L', 'e', 'g', 'a', 'c', 'y', ' ', 'S', 'e', 't', 'u', 'p', ' ', 'L', 'o', 'a', 'd', 'e', 'r', }; // Inheritable object for Windows Legacy Setup Loader
static uint16_t DESCRIPTION_INHERIT_BOOTSECTOR[] = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'R', 'e', 'a', 'l', '-', 'm', 'o', 'd', 'e', ' ', 'B', 'o', 'o', 't', ' ', 'S', 'e', 'c', 't', 'o', 'r', };                               // Inheritable object for Real-mode Boot Sector
static uint16_t DESCRIPTION_INHERIT_STARTUP[]    = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'R', 'e', 'a', 'l', '-', 'm', 'o', 'd', 'e', ' ', 'A', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                               // Inheritable object for Real-mode Application
static uint16_t DESCRIPTION_INHERIT_BOOTAPP[]    = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'B', 'o', 'o', 't', ' ', 'A', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                // Inheritable object for Windows Boot Application
static uint16_t DESCRIPTION_INHERIT_DEVICEOBJ[]  = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'D', 'e', 'v', 'i', 'c', 'e', ' ', 'O', 'b', 'j', 'e', 'c', 't', };                                                                       // Inheritable object for Device Object

static uint16_t FRIENDLY_FWBOOTMGR[]  = {'f', 'w', 'b', 'o', 'o', 't', 'm', 'g', 'r', };      // fwbootmgr
static uint16_t FRIENDLY_BOOTMGR[]    = {'b', 'o', 'o', 't', 'm', 'g', 'r', };                // bootmgr
static uint16_t FRIENDLY_OSLOADER[]   = {'o', 's', 'l', 'o', 'a', 'd', 'e', 'r', };           // osloader
static uint16_t FRIENDLY_RESUME[]     = {'r', 'e', 's', 'u', 'm', 'e', };                     // resume
static uint16_t FRIENDLY_EMDIAG[]     = {'e', 'm', 'd', 'i', 'a', 'g', };                     // emdiag
static uint16_t FRIENDLY_NTLDR[]      = {'n', 't', 'l', 'd', 'r', };                          // ntldr
static uint16_t FRIENDLY_SETUPLDR[]   = {'s', 'e', 't', 'u', 'p', 'l', 'd', 'r', };           // setupldr
static uint16_t FRIENDLY_BOOTSECTOR[] = {'b', 'o', 'o', 't', 's', 'e', 'c', 't', 'o', 'r', }; // bootsector
static uint16_t FRIENDLY_STARTUP[]    = {'s', 't', 'a', 'r', 't', 'u', 'p', };                // startup
static uint16_t FRIENDLY_BOOTAPP[]    = {'b', 'o', 'o', 't', 'a', 'p', 'p', };                // bootapp

static uint16_t DESCRIPTION_DEVICEOBJ[] = { 'D', 'e', 'v', 'i', 'c', 'e', ' ', 'O', 'b', 'j', 'e', 'c', 't', }; // Device Object

static uint16_t DESCRIPTION_UNKNOWN_APP_WINBOOT[]    = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'W', 'i', 'n', 'd', 'o', 'w', 's', ' ', 'b', 'o', 'o', 't', ' ', 'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                                                             // Unknown Windows boot application
static uint16_t DESCRIPTION_UNKNOWN_APP_LEGAGYLDR[]  = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'l', 'e', 'g', 'a', 'c', 'y', ' ', 'l', 'o', 'a', 'd', 'e', 'r', ' ', 'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                                                        // Unknown legacy loader application
static uint16_t DESCRIPTION_UNKNOWN_APP_FIRMWARE[]   = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'f', 'i', 'r', 'm', 'w', 'a', 'r', 'e', ' ', 'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                                                                                 // Unknown firmware application
static uint16_t DESCRIPTION_UNKNOWN_APP_REALMODE[]   = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'r', 'e', 'a', 'l', '-', 'm', 'o', 'd', 'e', ' ', 'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                                                                            // Unknown real-mode application
static uint16_t DESCRIPTION_UNKNOWN_APP[]            = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };                                                                                                                              // Unknown application
static uint16_t DESCRIPTION_UNKNOWN_INHERIT_APP[]    = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'u', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', };           // Inheritable object for unknown application
//static uint16_t DESCRIPTION_UNKNOWN_INHERIT_DEVICE[] = {'I', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', ' ', 'f', 'o', 'r', ' ', 'u', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'd', 'e', 'v', 'i', 'c', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', }; // Inheritable object for unknown device object
static uint16_t DESCRIPTION_UNKNOWN_INHERIT[]        = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'i', 'n', 'h', 'e', 'r', 'i', 't', 'a', 'b', 'l', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', };                                                                                           // Unknown inheritable object
//static uint16_t DESCRIPTION_UNKNOWN_DEVICEOBJ[]      = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'd', 'e', 'v', 'i', 'c', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', };                                                                                                                    // Unknown device object
static uint16_t DESCRIPTION_UNKNOWN_OBJ[]            = {'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'o', 'b', 'j', 'e', 'c', 't', };                                                                                                                                                       // Unknown object


static const registry_string16 gaAppDescriptionTable[] = {
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_FWBOOTMGR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_BOOTMGR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_OSLOADER),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_RESUME),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_EMDIAG),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_NTLDR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_SETUPLDR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_BOOTSECTOR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_STARTUP),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_APP_BOOTAPP),
};

static const registry_string16 gaInheritDescriptionTable[] = {
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_FWBOOTMGR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_BOOTMGR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_OSLOADER),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_RESUME),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_EMDIAG),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_NTLDR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_SETUPLDR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_BOOTSECTOR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_STARTUP),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_BOOTAPP),
};

static const registry_string16 gaUnknownAppDescriptionTable[] = {
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_APP_WINBOOT),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_APP_LEGAGYLDR),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_APP_FIRMWARE),
	REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_APP_REALMODE),
};

static const registry_string16 S16_DESCRIPTION_INHERIT_GENERIC        = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_GENERIC);
static const registry_string16 S16_DESCRIPTION_INHERIT_DEVICEOBJ      = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_INHERIT_DEVICEOBJ);
static const registry_string16 S16_DESCRIPTION_DEVICEOBJ              = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_DEVICEOBJ);
static const registry_string16 S16_DESCRIPTION_UNKNOWN_APP            = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_APP);
static const registry_string16 S16_DESCRIPTION_UNKNOWN_INHERIT_APP    = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_INHERIT_APP);
//static const registry_string16 S16_DESCRIPTION_UNKNOWN_INHERIT_DEVICE = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_INHERIT_DEVICE);
static const registry_string16 S16_DESCRIPTION_UNKNOWN_INHERIT        = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_INHERIT);
//static const registry_string16 S16_DESCRIPTION_UNKNOWN_DEVICEOBJ      = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_DEVICEOBJ);
static const registry_string16 S16_DESCRIPTION_UNKNOWN_OBJ            = REGISTRY_STRING_INIT_BUFFER(DESCRIPTION_UNKNOWN_OBJ);

static const registry_string16 gaObjectFriendlyTable[] = {
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_FWBOOTMGR),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_BOOTMGR),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_OSLOADER),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_RESUME),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_EMDIAG),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_NTLDR),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_SETUPLDR),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_BOOTSECTOR),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_STARTUP),
	REGISTRY_STRING_INIT_BUFFER(FRIENDLY_BOOTAPP),
};

static inline uint16_t ToUpper16Ascii(uint16_t X) {
	return (X - (uint16_t)'a' <= 25U) ? (X - (uint16_t)'a' + (uint16_t)'A') : X;
}

static int CompareString16Ascii(registry_string16 A, registry_string16 B) {
	size_t CompareLength = BCD_MIN(A.Length, B.Length);
	for (size_t i = 0; i < CompareLength; ++i) {
		uint16_t UpperA = ToUpper16Ascii(A.aBuffer[i]);
		uint16_t UpperB = ToUpper16Ascii(B.aBuffer[i]);
		if (UpperA != UpperB)
			return (UpperA > UpperB) * 2 - 1;
	}
	return (A.Length > B.Length) - (A.Length < B.Length);
}

// TODO: {default}
registry_string16 Bcd_GetObjectFriendlyName(
	registry_string16 GuidString,
	registry_string16 DefaultObjectGuidString,
	registry_string16 CurrentObjectGuidString
) {
	assert(GuidString.Length == BCD_GUID_STRING_LENGTH);

	size_t iLow = 1; // Use 1-based index to avoid underflow
	size_t iHigh = REGISTRY_ARRLEN_LITERAL(gaRawGuidMap);
	while (iLow <= iHigh) {
		size_t iMid = (iLow + iHigh) / 2;
		int Cmp = CompareString16Ascii(GuidString, gaRawGuidMap[iMid - 1].GuidString);
		if (Cmp > 0) {
			iLow = iMid + 1;
		} else if (Cmp < 0) {
			iHigh = iMid - 1;
		} else {
			return gaRawGuidMap[iMid - 1].FriendlyName;
		}
	}

	if (CompareString16Ascii(GuidString, DefaultObjectGuidString) == 0)
		return (registry_string16)REGISTRY_STRING_INIT_BUFFER(FRIENDLY_DEFAULT_BOOT_ENTRY);

	if (CompareString16Ascii(GuidString, CurrentObjectGuidString) == 0)
		return (registry_string16)REGISTRY_STRING_INIT_BUFFER(FRIENDLY_CURRENT_BOOT_ENTRY);

	return (registry_string16){0, 0, NULL};
}

static const uint8_t gaAppTypeLookup[10] = {
	0, 0, 1, 1, 1, 2, 2, 3, 3, 1
};

// TODO: Maybe for special GUIDs too
registry_string16 Bcd_GetObjectDescription(
	bcd_object_type ObjectType
) {
	uint32_t PrimaryType = ObjectType >> 28;
	uint32_t SecondaryType = (ObjectType >> 20) & 0xF;
	uint32_t AppType = ObjectType & 0xFFFFF;
	// Microsoft's BcdEdit doesn't care about (ObjectType >> 24) & 0xF

	switch (PrimaryType) {
		case 1:
			if (BCD_IN_RANGE(SecondaryType, 1, 4)) {
				if (BCD_IN_RANGE(AppType, 1, 10)) {
					if (gaAppTypeLookup[AppType - 1] == SecondaryType - 1)
						return gaAppDescriptionTable[AppType - 1];
				}
				return gaUnknownAppDescriptionTable[SecondaryType - 1];
			}
			return S16_DESCRIPTION_UNKNOWN_APP;
		case 2:
			switch (SecondaryType) {
				case 1:
					if (AppType == 0)
						return S16_DESCRIPTION_INHERIT_GENERIC;
					else
						return S16_DESCRIPTION_UNKNOWN_INHERIT;
				case 2:
					if (BCD_IN_RANGE(AppType, 1, 10))
						return gaInheritDescriptionTable[AppType - 1];
					else
						return S16_DESCRIPTION_UNKNOWN_INHERIT_APP;
				case 3:
					return S16_DESCRIPTION_INHERIT_DEVICEOBJ;
				default:
					return S16_DESCRIPTION_UNKNOWN_INHERIT;
			}
		case 3:
			return S16_DESCRIPTION_DEVICEOBJ;
		default:
			return S16_DESCRIPTION_UNKNOWN_OBJ;
	}
}

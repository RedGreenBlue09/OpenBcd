#pragma once

// SPDX-License-Identifier: GPL-2.0-or-later

#include <RegistryString.h>

typedef int32_t bcd_status;
#define BCD_STATUS_NO_MORE_ENTRIES ((bcd_status)0x8000001A)

typedef uint8_t bcd_store_save_handler(void* pBuffer,size_t nBuffer,void* Parameter);

typedef void* h_bcd_store;
typedef void* h_bcd_object;
typedef void* h_bcd_element;

typedef void* bcd_object_iterator;
typedef void* bcd_element_iterator;

// All types recognized by Microsoft's BcdEdit
typedef enum {
	Bcd_ObjectType_App_FwBootMgr      = 0x10100001,
	Bcd_ObjectType_App_BootMgr        = 0x10100002,
	Bcd_ObjectType_App_OsLoader       = 0x10200003,
	Bcd_ObjectType_App_Resume         = 0x10200004,
	Bcd_ObjectType_App_MemDiag        = 0x10200005,
	Bcd_ObjectType_App_NtLdr          = 0x10300006,
	Bcd_ObjectType_App_SetupLdr       = 0x10300007,
	Bcd_ObjectType_App_BootSector     = 0x10400008,
	Bcd_ObjectType_App_Startup        = 0x10400009,
	Bcd_ObjectType_App_BootApp        = 0x1020000A,
	Bcd_ObjectType_Inherit_Any        = 0x20100000,
	Bcd_ObjectType_Inherit_FwBootMgr  = 0x20100001,
	Bcd_ObjectType_Inherit_BootMgr    = 0x20200002,
	Bcd_ObjectType_Inherit_OsLoader   = 0x20200003,
	Bcd_ObjectType_Inherit_Resume     = 0x20200004,
	Bcd_ObjectType_Inherit_MemDiag    = 0x20200005,
	Bcd_ObjectType_Inherit_NtLdr      = 0x20200006,
	Bcd_ObjectType_Inherit_SetupLdr   = 0x20200007,
	Bcd_ObjectType_Inherit_BootSector = 0x20200008,
	Bcd_ObjectType_Inherit_Startup    = 0x20200009,
	Bcd_ObjectType_Inherit_BootApp    = 0x2020000A,
	Bcd_ObjectType_Inherit_Device     = 0x20300000,
	Bcd_ObjectType_Device             = 0x30000000,
} bcd_object_type;

typedef struct {
	uint32_t Data0;
	uint16_t Data1;
	uint16_t Data2;
	uint8_t Data3[2];
	uint8_t Data4[6];
} bcd_guid;

#define BCD_STDERR(...) fprintf(stderr,__VA_ARGS__);

// Returns STATUS_NOT_FOUND if the content of the hive is unexpected.
bcd_status Bcd_LoadStore(
	h_bcd_store* phStore,
	void* pData,
	size_t nData,
	bcd_store_save_handler* pSaveHandler,
	void* SaveParameter
);

bcd_status Bcd_UnloadStore(
	h_bcd_store hStore,
	uint8_t bForce
);

bcd_status Bcd_QueryDefaultObjectGuidString(
	h_bcd_store hStore,
	registry_string16* pGuidString
);

#define BCD_GUID_STRING_LENGTH 38

uint8_t Bcd_ValidateGuidString(
	registry_string16 String
);

// Requires pString->AllocatedLength >= BCD_GUID_STRING_LENGTH
void Bcd_GuidToString16(
	bcd_guid pGuid,
	registry_string16* pString
);

// This does not handle stuff like {bootmgr}
// Returns STATUS_NOT_FOUND if the content of the hive is unexpected.
bcd_status Bcd_OpenObjectByGuidString(
	h_bcd_store hStore,
	registry_string16 GuidString,
	h_bcd_object* phObject
);

// Returns STATUS_NOT_FOUND if the content of the hive is unexpected.
bcd_status Bcd_OpenObjectByGuid(
	h_bcd_store hStore,
	const bcd_guid* pGuid,
	h_bcd_object* phObject
);

bcd_status Bcd_CloseObject(
	h_bcd_object hObject
);

bcd_status Bcd_QueryObjectGuidString(
	h_bcd_object hObject,
	registry_string16* pString
);

bcd_status Bcd_QueryObjectType(
	h_bcd_object hObject,
	bcd_object_type* pResult
);

bcd_status Bcd_OpenObjectIterator(
	h_bcd_store hStore,
	bcd_object_iterator* piObject
);

bcd_status Bcd_CloseObjectIterator(
	bcd_object_iterator iObject
);

bcd_status Bcd_IsObjectIteratorEnd(
	bcd_object_iterator iObject,
	uint8_t* pbResult
);

// May return BCD_STATUS_NO_MORE_ENTRIES
bcd_status Bcd_OpenNextObject(
	bcd_object_iterator* piNext,
	h_bcd_object* phResultObject
);

// Returns zero struct if there's no friendly name.
// TODO: Accept object handle instead of GUID string
registry_string16 Bcd_GetObjectFriendlyName(
	registry_string16 GuidString,
	registry_string16 DefaultObjectGuidString,
	registry_string16 CurrentObjectGuidString
);

registry_string16 Bcd_GetObjectDescription(
	bcd_object_type ObjectType
);

// All types recognized by Microsoft's BcdEdit
typedef enum {
	Bcd_ElementType_Device = 1,
	Bcd_ElementType_String,
	Bcd_ElementType_Guid,
	Bcd_ElementType_GuidList,
	Bcd_ElementType_Integer,
	Bcd_ElementType_Boolean,
	Bcd_ElementType_IntegerList,
} bcd_element_type;

typedef uint32_t bcd_element_id;

typedef enum {
	Bcd_Element_Library_ApplicationDevice                = 0x11000001,
	Bcd_Element_Library_ApplicationPath                  = 0x12000002,
	Bcd_Element_Library_Description                      = 0x12000004,
	Bcd_Element_Library_PreferredLocale                  = 0x12000005,
	Bcd_Element_Library_InheritedObjects                 = 0x14000006,
	Bcd_Element_Library_TruncatePhysicalMemory           = 0x15000007,
	Bcd_Element_Library_RecoverySequence                 = 0x14000008,
	Bcd_Element_Library_AutoRecoveryEnabled              = 0x16000009,
	Bcd_Element_Library_BadMemoryList                    = 0x1700000A,
	Bcd_Element_Library_AllowBadMemoryAccess             = 0x1600000B,
	Bcd_Element_Library_FirstMegabytePolicy              = 0x1500000C,
	Bcd_Element_Library_RelocatePhysicalMemory           = 0x1500000D,
	Bcd_Element_Library_AvoidLowPhysicalMemory           = 0x1500000E,
	Bcd_Element_Library_TraditionalKsegMappings          = 0x1600000F,
	Bcd_Element_Library_DebuggerEnabled                  = 0x16000010,
	Bcd_Element_Library_DebuggerType                     = 0x15000011,
	Bcd_Element_Library_SerialDebuggerPortAddress        = 0x15000012,
	Bcd_Element_Library_SerialDebuggerPort               = 0x15000013,
	Bcd_Element_Library_SerialDebuggerBaudRate           = 0x15000014,
	Bcd_Element_Library_1394DebuggerChannel              = 0x15000015,
	Bcd_Element_Library_UsbDebuggerTargetName            = 0x12000016,
	Bcd_Element_Library_DebuggerIgnoreUsermodeExceptions = 0x16000017,
	Bcd_Element_Library_DebuggerStartPolicy              = 0x15000018,
	Bcd_Element_Library_DebuggerBusParameters            = 0x12000019,
	Bcd_Element_Library_DebuggerNetHostIP                = 0x1500001A,
	Bcd_Element_Library_DebuggerNetPort                  = 0x1500001B,
	Bcd_Element_Library_DebuggerNetDhcp                  = 0x1600001C,
	Bcd_Element_Library_DebuggerNetKey                   = 0x1200001D,
	Bcd_Element_Library_DebuggerNetVm                    = 0x1600001E,
	Bcd_Element_Library_DebuggerNetHostIpv6              = 0x1200001F,
	Bcd_Element_Library_EmsEnabled                       = 0x16000020,
	Bcd_Element_Library_EmsPort                          = 0x15000022,
	Bcd_Element_Library_EmsBaudRate                      = 0x15000023,
	Bcd_Element_Library_LoadOptionsString                = 0x12000030,
	Bcd_Element_Library_AttemptNonBcdStart               = 0x16000031,
	Bcd_Element_Library_DisplayAdvancedOptions           = 0x16000040,
	Bcd_Element_Library_DisplayOptionsEdit               = 0x16000041,
	Bcd_Element_Library_FVEKeyRingAddress                = 0x15000042,
	Bcd_Element_Library_BsdLogDevice                     = 0x11000043,
	Bcd_Element_Library_BsdLogPath                       = 0x12000044,
	Bcd_Element_Library_BsdPreserveLog                   = 0x16000045,
	Bcd_Element_Library_GraphicsModeDisabled             = 0x16000046,
	Bcd_Element_Library_ConfigAccessPolicy               = 0x15000047,
	Bcd_Element_Library_DisableIntegrityChecks           = 0x16000048,
	Bcd_Element_Library_AllowPrereleaseSignatures        = 0x16000049,
	Bcd_Element_Library_FontPath                         = 0x1200004A,
	Bcd_Element_Library_SiPolicy                         = 0x1500004B,
	Bcd_Element_Library_FveBandId                        = 0x1500004C,
	Bcd_Element_Library_ConsoleExtendedInput             = 0x16000050,
	Bcd_Element_Library_InitialConsoleInput              = 0x15000051,
	Bcd_Element_Library_GraphicsResolution               = 0x15000052,
	Bcd_Element_Library_RestartOnFailure                 = 0x16000053,
	Bcd_Element_Library_GraphicsForceHighestMode         = 0x16000054,
	Bcd_Element_Library_IsolatedExecutionContext         = 0x16000060,
	Bcd_Element_Library_BootUxDisplayMessage             = 0x15000065,
	Bcd_Element_Library_BootUxDisplayMessageOverride     = 0x15000066,
	Bcd_Element_Library_BootUxLogoDisable                = 0x16000067,
	Bcd_Element_Library_BootUxTextDisable                = 0x16000068,
	Bcd_Element_Library_BootUxProgressDisable            = 0x16000069,
	Bcd_Element_Library_BootUxFadeDisable                = 0x1600006A,
	Bcd_Element_Library_BootUxReservePoolDebug           = 0x1600006B,
	Bcd_Element_Library_BootUxDisable                    = 0x1600006C,
	Bcd_Element_Library_BootUxFadeFrames                 = 0x1500006D,
	Bcd_Element_Library_BootUxDumpStats                  = 0x1600006E,
	Bcd_Element_Library_BootUxShowStats                  = 0x1600006F,
	Bcd_Element_Library_MultiBootSystem                  = 0x16000071,
	Bcd_Element_Library_ForceNoKeyboard                  = 0x16000072,
	Bcd_Element_Library_AliasWindowsKey                  = 0x15000073,
	Bcd_Element_Library_BootShutdownDisabled             = 0x16000074,
	Bcd_Element_Library_PerformanceFrequency             = 0x15000075,
	Bcd_Element_Library_SecurebootRawPolicy              = 0x15000076,
	Bcd_Element_Library_AllowedInMemorySettings          = 0x17000077,
	Bcd_Element_Library_Unknown78                        = 0x16000078,
	Bcd_Element_Library_BootUxBitmapTransitionTime       = 0x15000079,
	Bcd_Element_Library_TwoBootImages                    = 0x1600007A,
	Bcd_Element_Library_ForceFipsCrypto                  = 0x1600007B,
	Bcd_Element_Library_BootErrorUx                      = 0x1500007D,
	Bcd_Element_Library_AllowFlightSignatures            = 0x1600007E,
	Bcd_Element_Library_BootMeasurementLogFormat         = 0x1500007F,
	Bcd_Element_Library_DisplayRotation                  = 0x15000080,
	Bcd_Element_Library_LogControl                       = 0x15000081,
	Bcd_Element_Library_NoFirmwareSync                   = 0x16000082,
	Bcd_Element_Library_Unknown83                        = 0x11000083,
	Bcd_Element_Library_WindowsSystemDevice              = 0x11000084,
	Bcd_Element_Library_Unknown85                        = 0x16000085,
	Bcd_Element_Library_Unknown86                        = 0x15000086,
	Bcd_Element_Library_NumLockOn                        = 0x16000087,
	Bcd_Element_Library_AdditionalCiPolicy               = 0x12000088,
	Bcd_Element_Library_LinearAddress57Policy            = 0x15000088,
	Bcd_Element_FfuLoader_OneShotSkipFfuUpdate           = 0x26000202,
	Bcd_Element_FfuLoader_ForceFfu                       = 0x26000203,
	Bcd_Element_Charging_BootThreshold                   = 0x25000510,
	Bcd_Element_Charging_OffModeCharging                 = 0x26000512,
	Bcd_Element_Global_Bootflow                          = 0x25000AAA,
	Bcd_Element_Setup_DeviceType                         = 0x45000001,
	Bcd_Element_Setup_ApplicationRelativePath            = 0x42000002,
	Bcd_Element_Setup_RamdiskDeviceRelativePath          = 0x42000003,
	Bcd_Element_Setup_OmitOsLoaderElements               = 0x46000004,
	Bcd_Element_Setup_ElementsToMigrateList              = 0x47000006,
	Bcd_Element_Setup_RecoveryOs                         = 0x46000010,
	Bcd_Element_BootMgr_DisplayOrder                     = 0x24000001,
	Bcd_Element_BootMgr_BootSequence                     = 0x24000002,
	Bcd_Element_BootMgr_DefaultObject                    = 0x23000003,
	Bcd_Element_BootMgr_Timeout                          = 0x25000004,
	Bcd_Element_BootMgr_AttemptResume                    = 0x26000005,
	Bcd_Element_BootMgr_ResumeObject                     = 0x23000006,
	Bcd_Element_BootMgr_StartupSequence                  = 0x24000007,
	Bcd_Element_BootMgr_ToolsDisplayOrder                = 0x24000010,
	Bcd_Element_BootMgr_DisplayBootMenu                  = 0x26000020,
	Bcd_Element_BootMgr_NoErrorDisplay                   = 0x26000021,
	Bcd_Element_BootMgr_BcdDevice                        = 0x21000022,
	Bcd_Element_BootMgr_BcdFilePath                      = 0x22000023,
	Bcd_Element_BootMgr_HormEnabled                      = 0x26000024,
	Bcd_Element_BootMgr_HiberRoot                        = 0x26000025,
	Bcd_Element_BootMgr_PasswordOverride                 = 0x22000026,
	Bcd_Element_BootMgr_PinpassPhraseOverride            = 0x22000027,
	Bcd_Element_BootMgr_ProcessCustomActionsFirst        = 0x26000028,
	Bcd_Element_BootMgr_Unknown2A                        = 0x2600002A,
	Bcd_Element_BootMgr_CustomActionsList                = 0x27000030,
	Bcd_Element_BootMgr_PersistBootSequence              = 0x26000031,
	Bcd_Element_BootMgr_SkipStartupSequence              = 0x26000032,
	Bcd_Element_BootMgr_FveRecoveryUrl                   = 0x22000040,
	Bcd_Element_BootMgr_FveRecoveryMessage               = 0x22000041,
	Bcd_Element_BootMgr_FlightBootMgr                    = 0x26000042,
	Bcd_Element_BootMgr_FveUnlockRetryCountIpv4          = 0x25000043,
	Bcd_Element_BootMgr_FveUnlockRetryCountIpv6          = 0x25000044,
	Bcd_Element_BootMgr_FveServerAddressIpv4             = 0x22000045,
	Bcd_Element_BootMgr_FveServerAddressIpv6             = 0x22000046,
	Bcd_Element_BootMgr_FveStationAddressIpv4            = 0x22000047,
	Bcd_Element_BootMgr_FveStationAddressIpv6            = 0x22000048,
	Bcd_Element_BootMgr_FveStationSubnetMaskIpv4         = 0x22000049,
	Bcd_Element_BootMgr_FveStationSubnetMaskIpv6         = 0x2200004A,
	Bcd_Element_BootMgr_FveGatewayIpv4                   = 0x2200004B,
	Bcd_Element_BootMgr_FveGatewayIpv6                   = 0x2200004C,
	Bcd_Element_BootMgr_FveNetworkTimeout                = 0x2500004D,
	Bcd_Element_BootMgr_RemotePortIpv4                   = 0x2500004E,
	Bcd_Element_BootMgr_RemotePortIpv6                   = 0x2500004F,
	Bcd_Element_BootMgr_StationPortIpv4                  = 0x25000050,
	Bcd_Element_BootMgr_StationPortIpv6                  = 0x25000051,
	Bcd_Element_OsLoader_OsDevice                        = 0x21000001,
	Bcd_Element_OsLoader_SystemRoot                      = 0x22000002,
	Bcd_Element_OsLoader_AssociatedResumeObject          = 0x23000003,
	Bcd_Element_OsLoader_StampDisks                      = 0x26000004,
	Bcd_Element_OsLoader_Unknown5                        = 0x21000005,
	Bcd_Element_OsLoader_Unknown8                        = 0x25000008,
	Bcd_Element_OsLoader_DetectKernelAndHal              = 0x26000010,
	Bcd_Element_OsLoader_KernelPath                      = 0x22000011,
	Bcd_Element_OsLoader_HalPath                         = 0x22000012,
	Bcd_Element_OsLoader_DbgTransportPath                = 0x22000013,
	Bcd_Element_OsLoader_NxPolicy                        = 0x25000020,
	Bcd_Element_OsLoader_PaePolicy                       = 0x25000021,
	Bcd_Element_OsLoader_WinPeMode                       = 0x26000022,
	Bcd_Element_OsLoader_DisableCrashAutoReboot          = 0x26000024,
	Bcd_Element_OsLoader_UseLastGoodSettings             = 0x26000025,
	Bcd_Element_OsLoader_DisableCodeIntegrityChecks      = 0x26000026,
	Bcd_Element_OsLoader_AllowPrereleaseSignatures       = 0x26000027,
	Bcd_Element_OsLoader_NoLowMemory                     = 0x26000030,
	Bcd_Element_OsLoader_RemoveMemory                    = 0x25000031,
	Bcd_Element_OsLoader_IncreaseUserVa                  = 0x25000032,
	Bcd_Element_OsLoader_PerformaceDataMemory            = 0x25000033,
	Bcd_Element_OsLoader_UseVgaDriver                    = 0x26000040,
	Bcd_Element_OsLoader_DisableBootDisplay              = 0x26000041,
	Bcd_Element_OsLoader_DisableVesaBios                 = 0x26000042,
	Bcd_Element_OsLoader_DisableVgaMode                  = 0x26000043,
	Bcd_Element_OsLoader_ClusterModeAddressing           = 0x25000050,
	Bcd_Element_OsLoader_UsePhysicalDestination          = 0x26000051,
	Bcd_Element_OsLoader_RestrictApicCluster             = 0x25000052,
	Bcd_Element_OsLoader_OsLoaderTypeEVStore             = 0x22000053,
	Bcd_Element_OsLoader_UseLegacyApicMode               = 0x26000054,
	Bcd_Element_OsLoader_X2ApicPolicy                    = 0x25000055,
	Bcd_Element_OsLoader_UseBootProcessorOnly            = 0x26000060,
	Bcd_Element_OsLoader_NumberOfProcessors              = 0x25000061,
	Bcd_Element_OsLoader_ForceMaximumProcessors          = 0x26000062,
	Bcd_Element_OsLoader_ProcessorConfigurationFlags     = 0x25000063,
	Bcd_Element_OsLoader_MaximizeGroupsCreated           = 0x26000064,
	Bcd_Element_OsLoader_ForceGroupAwareness             = 0x26000065,
	Bcd_Element_OsLoader_GroupSize                       = 0x25000066,
	Bcd_Element_OsLoader_UseFirmwarePciSettings          = 0x26000070,
	Bcd_Element_OsLoader_MsiPolicy                       = 0x25000071,
	Bcd_Element_OsLoader_PciExpressPolicy                = 0x25000072,
	Bcd_Element_OsLoader_SafeBoot                        = 0x25000080,
	Bcd_Element_OsLoader_SafeBootAlternateShell          = 0x26000081,
	Bcd_Element_OsLoader_BootLogInitialization           = 0x26000090,
	Bcd_Element_OsLoader_VerboseObjectLoadMode           = 0x26000091,
	Bcd_Element_OsLoader_KernelDebuggerEnabled           = 0x260000A0,
	Bcd_Element_OsLoader_DebuggerHalBreakpoint           = 0x260000A1,
	Bcd_Element_OsLoader_UsePlatformClock                = 0x260000A2,
	Bcd_Element_OsLoader_ForceLegacyPlatform             = 0x260000A3,
	Bcd_Element_OsLoader_UsePlatformTick                 = 0x260000A4,
	Bcd_Element_OsLoader_DisableDynamicTick              = 0x260000A5,
	Bcd_Element_OsLoader_TscSyncPolicy                   = 0x250000A6,
	Bcd_Element_OsLoader_EmsEnabled                      = 0x260000B0,
	Bcd_Element_OsLoader_ForceFailure                    = 0x250000C0,
	Bcd_Element_OsLoader_DriverLoadFailurePolicy         = 0x250000C1,
	Bcd_Element_OsLoader_BootMenuPolicy                  = 0x250000C2,
	Bcd_Element_OsLoader_AdvancedOptionsOneTime          = 0x260000C3,
	Bcd_Element_OsLoader_EditOptionsOneTime              = 0x260000C4,
	Bcd_Element_OsLoader_BootStatusPolicy                = 0x250000E0,
	Bcd_Element_OsLoader_DisableElamDrivers              = 0x260000E1,
	Bcd_Element_OsLoader_HypervisorLaunchType            = 0x250000F0,
	Bcd_Element_OsLoader_HypervisorPath                  = 0x220000F1,
	Bcd_Element_OsLoader_HypervisorDebuggerEnabled       = 0x260000F2,
	Bcd_Element_OsLoader_HypervisorDebuggerType          = 0x250000F3,
	Bcd_Element_OsLoader_HypervisorDebuggerPortNumber    = 0x250000F4,
	Bcd_Element_OsLoader_HypervisorDebuggerBaudrate      = 0x250000F5,
	Bcd_Element_OsLoader_HypervisorDebugger1394Channel   = 0x250000F6,
	Bcd_Element_OsLoader_BootUxPolicy                    = 0x250000F7,
	Bcd_Element_OsLoader_HypervisorSlatDisabled          = 0x260000F8,
	Bcd_Element_OsLoader_HypervisorDebuggerBusParams     = 0x220000F9,
	Bcd_Element_OsLoader_HypervisorNumProc               = 0x250000FA,
	Bcd_Element_OsLoader_HypervisorRootProcPerNode       = 0x250000FB,
	Bcd_Element_OsLoader_HypervisorUseLargeVTlb          = 0x260000FC,
	Bcd_Element_OsLoader_HypervisorDebuggerNetHostIp     = 0x250000FD,
	Bcd_Element_OsLoader_HypervisorDebuggerNetHostPort   = 0x250000FE,
	Bcd_Element_OsLoader_HypervisorDebuggerPages         = 0x250000FF,
	Bcd_Element_OsLoader_TpmBootEntropyPolicy            = 0x25000100,
	Bcd_Element_OsLoader_HypervisorDebuggerNetKey        = 0x22000110,
	Bcd_Element_OsLoader_HypervisorProductSkuType        = 0x22000112,
	Bcd_Element_OsLoader_HypervisorRootProc              = 0x25000113,
	Bcd_Element_OsLoader_HypervisorDebuggerNetDhcp       = 0x26000114,
	Bcd_Element_OsLoader_HypervisorIommuPolicy           = 0x25000115,
	Bcd_Element_OsLoader_HypervisorUseVApic              = 0x26000116,
	Bcd_Element_OsLoader_HypervisorLoadOptions           = 0x22000117,
	Bcd_Element_OsLoader_HypervisorMsrFilterPolicy       = 0x25000118,
	Bcd_Element_OsLoader_HypervisorMmioNxPolicy          = 0x25000119,
	Bcd_Element_OsLoader_HypervisorSchedulerType         = 0x2500011A,
	Bcd_Element_OsLoader_HypervisorRootProcNumaNodes     = 0x2200011B,
	Bcd_Element_OsLoader_HypervisorPerfmon               = 0x2500011C,
	Bcd_Element_OsLoader_HypervisorRootProcPerCore       = 0x2500011D,
	Bcd_Element_OsLoader_HypervisorRootProcNumaNodeLps   = 0x2200011E,
	Bcd_Element_OsLoader_XSavePolicy                     = 0x25000120,
	Bcd_Element_OsLoader_XSaveAddFeature0                = 0x25000121,
	Bcd_Element_OsLoader_XSaveAddFeature1                = 0x25000122,
	Bcd_Element_OsLoader_XSaveAddFeature2                = 0x25000123,
	Bcd_Element_OsLoader_XSaveAddFeature3                = 0x25000124,
	Bcd_Element_OsLoader_XSaveAddFeature4                = 0x25000125,
	Bcd_Element_OsLoader_XSaveAddFeature5                = 0x25000126,
	Bcd_Element_OsLoader_XSaveAddFeature6                = 0x25000127,
	Bcd_Element_OsLoader_XSaveAddFeature7                = 0x25000128,
	Bcd_Element_OsLoader_XSaveRemoveFeature              = 0x25000129,
	Bcd_Element_OsLoader_XSaveProcessorsMask             = 0x2500012A,
	Bcd_Element_OsLoader_XSaveDisable                    = 0x2500012B,
	Bcd_Element_OsLoader_KernelDebuggerType              = 0x2500012C,
	Bcd_Element_OsLoader_kernelDebuggerBusParameters     = 0x2200012D,
	Bcd_Element_OsLoader_kernelDebuggerPortAddress       = 0x2500012E,
	Bcd_Element_OsLoader_KernelDebuggerPortNumber        = 0x2500012F,
	Bcd_Element_OsLoader_FveClaimedDeviceLockCounter     = 0x25000130,
	Bcd_Element_OsLoader_KernelDebugger1394Channel       = 0x25000131,
	Bcd_Element_OsLoader_KernelDebuggerUsbTargetname     = 0x22000132,
	Bcd_Element_OsLoader_KernelDebuggerNetHostIp         = 0x25000133,
	Bcd_Element_OsLoader_KernelDebuggerNetHostPort       = 0x25000134,
	Bcd_Element_OsLoader_KernelDebuggerNetDhcp           = 0x26000135,
	Bcd_Element_OsLoader_KernelDebuggerNetKey            = 0x22000136,
	Bcd_Element_OsLoader_IMCHiveName                     = 0x22000137,
	Bcd_Element_OsLoader_IMCDevice                       = 0x21000138,
	Bcd_Element_OsLoader_KernelDebuggerBaudrate          = 0x25000139,
	Bcd_Element_OsLoader_ManufacturingMode               = 0x22000140,
	Bcd_Element_OsLoader_EventLoggingEnabled             = 0x26000141,
	Bcd_Element_OsLoader_VsmLaunchType                   = 0x25000142,
	Bcd_Element_OsLoader_HypervisorEnforcedCodeIntegrity = 0x25000144,
	Bcd_Element_OsLoader_DtraceEnabled                   = 0x26000145,
	Bcd_Element_OsLoader_SystemDataDevice                = 0x21000150,
	Bcd_Element_OsLoader_OsArcDevice                     = 0x21000151,
	Bcd_Element_OsLoader_Unknown152                      = 0x21000152,
	Bcd_Element_OsLoader_OsDataDevice                    = 0x21000153,
	Bcd_Element_OsLoader_BspDevice                       = 0x21000154,
	Bcd_Element_OsLoader_BspFilepath                     = 0x21000155,
	Bcd_Element_OsLoader_KernelDebuggerNetHostIpv6       = 0x22000156,
	Bcd_Element_OsLoader_HypervisorDebuggerNetHostIpv6   = 0x22000161,
	Bcd_Element_Resume_HiberFileDevice                   = 0x21000001,
	Bcd_Element_Resume_HiberFilePath                     = 0x22000002,
	Bcd_Element_Resume_UseCustomSettings                 = 0x26000003,
	Bcd_Element_Resume_x86PaeMode                        = 0x26000004,
	Bcd_Element_Resume_AssociatedOsDevice                = 0x21000005,
	Bcd_Element_Resume_DebugOptionEnabled                = 0x26000006,
	Bcd_Element_Resume_BootUxPolicy                      = 0x25000007,
	Bcd_Element_Resume_BootMenuPolicy                    = 0x25000008,
	Bcd_Element_Resume_HormEnabled                       = 0x26000024,
	Bcd_Element_Resume_Unknown26                         = 0x21000026,
	Bcd_Element_MemDiag_PassCount                        = 0x25000001,
	Bcd_Element_MemDiag_TestMix                          = 0x25000002,
	Bcd_Element_MemDiag_FailureCount                     = 0x25000003,
	Bcd_Element_MemDiag_CacheEnabled                     = 0x26000003,
	Bcd_Element_MemDiag_TestToFail                       = 0x25000004,
	Bcd_Element_MemDiag_FailuresEnabled                  = 0x26000004,
	Bcd_Element_MemDiag_CacheEnable                      = 0x26000005,
	Bcd_Element_MemDiag_StrideFailureCount               = 0x25000005,
	Bcd_Element_MemDiag_InvcFailureCount                 = 0x25000006,
	Bcd_Element_MemDiag_MatsFailureCount                 = 0x25000007,
	Bcd_Element_MemDiag_RandFailureCount                 = 0x25000008,
	Bcd_Element_MemDiag_ChckrFailureCount                = 0x25000009,
	Bcd_Element_LegacyLdr_BpbString                      = 0x22000001,
	Bcd_Element_Startup_PxeSoftReboot                    = 0x26000001,
	Bcd_Element_Startup_PxeApplicationName               = 0x22000002,
	Bcd_Element_MobileStartup_EnableBootDebugPolicy      = 0x26000145,
	Bcd_Element_MobileStartup_EnableBootOrderClean       = 0x26000146,
	Bcd_Element_MobileStartup_EnableDeviceId             = 0x26000147,
	Bcd_Element_MobileStartup_EnableFfuLoader            = 0x26000148,
	Bcd_Element_MobileStartup_EnableIuLoader             = 0x26000149,
	Bcd_Element_MobileStartup_EnableMassStorage          = 0x2600014A,
	Bcd_Element_MobileStartup_EnableRpmbProvisioning     = 0x2600014B,
	Bcd_Element_MobileStartup_EnableSecureBootPolicy     = 0x2600014C,
	Bcd_Element_MobileStartup_EnableStartCharge          = 0x2600014D,
	Bcd_Element_MobileStartup_EnableResetTpm             = 0x2600014E,
	Bcd_Element_Device_RamdiskImageOffset                = 0x35000001,
	Bcd_Element_Device_TftpClientPort                    = 0x35000002,
	Bcd_Element_Device_SdiDevice                         = 0x31000003,
	Bcd_Element_Device_SdiPath                           = 0x32000004,
	Bcd_Element_Device_RamdiskImageLength                = 0x35000005,
	Bcd_Element_Device_RamdiskExportAsCd                 = 0x36000006,
	Bcd_Element_Device_RamdiskTftpBlockSize              = 0x35000007,
	Bcd_Element_Device_RamdiskTftpWindowSize             = 0x35000008,
	Bcd_Element_Device_RamdiskMulticastEnabled           = 0x36000009,
	Bcd_Element_Device_RamdiskMulticastTftpFallback      = 0x3600000A,
	Bcd_Element_Device_RamdiskTftpVarWindow              = 0x3600000B,
	Bcd_Element_Device_VhdRamdiskBoot                    = 0x3600000C,
	Bcd_Element_Device_UnknownD                          = 0x3500000D,
} bcd_element_defined_id;

#define BCD_ELEMENT_ID_STRING_LENGTH 8

uint8_t Bcd_ValidateElementIdString(
	registry_string16 String
);

void Bcd_ElementIdToString(
	bcd_element_id Id,
	registry_string16* pString
);

bcd_element_id Bcd_StringToElementId(
	registry_string16 String
);

bcd_element_type Bcd_ElementIdToElementType(
	bcd_element_id ElementId
);

bcd_element_type Bcd_ElementIdStringToElementType(
	registry_string16 String
);

uint8_t Bcd_ValidateElementValueData(
	bcd_element_type ElementType,
	void* pData,
	uint32_t nData
);

bcd_status Bcd_OpenElementByIdString(
	h_bcd_object hObject,
	registry_string16 IdString,
	h_bcd_object* phElement
);

bcd_status Bcd_OpenElementById(
	h_bcd_object hObject,
	bcd_element_id Id,
	h_bcd_element* phElement
);

bcd_status Bcd_CloseElement(
	h_bcd_element hElement
);

typedef void* bcd_element_iterator;

bcd_status Bcd_OpenElementIterator(
	h_bcd_object hObject,
	bcd_element_iterator* piElement
);

bcd_status Bcd_CloseElementIterator(
	bcd_element_iterator iElement
);

bcd_status Bcd_IsElementIteratorEnd(
	bcd_element_iterator iElement,
	uint8_t* pbResult
);

bcd_status Bcd_OpenNextElement(
	bcd_element_iterator* piNext,
	h_bcd_element* phResultElement
);

bcd_status Bcd_QueryElementId(
	h_bcd_element hElement,
	bcd_element_id* pId
);

bcd_status Bcd_QueryElementValue(
	h_bcd_element hElement,
	void* pData,
	uint32_t nData,
	uint32_t* pRealSize
);

bcd_status Bcd_QueryElementFriendlyName(
	h_bcd_element hElement,
	registry_string16* pFriendlyName
);

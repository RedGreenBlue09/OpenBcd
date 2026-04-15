
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common.h"

static uint16_t aFriendly_Library_ApplicationDevice[]                = {'d', 'e', 'v', 'i', 'c', 'e', };                                                                                                                              // device
static uint16_t aFriendly_Library_ApplicationPath[]                  = {'p', 'a', 't', 'h', };                                                                                                                                        // path
static uint16_t aFriendly_Library_Description[]                      = {'d', 'e', 's', 'c', 'r', 'i', 'p', 't', 'i', 'o', 'n', };                                                                                                     // description
static uint16_t aFriendly_Library_PreferredLocale[]                  = {'l', 'o', 'c', 'a', 'l', 'e', };                                                                                                                              // locale
static uint16_t aFriendly_Library_InheritedObjects[]                 = {'i', 'n', 'h', 'e', 'r', 'i', 't', };                                                                                                                         // inherit
static uint16_t aFriendly_Library_TruncatePhysicalMemory[]           = {'t', 'r', 'u', 'n', 'c', 'a', 't', 'e', 'm', 'e', 'm', 'o', 'r', 'y', };                                                                                      // truncatememory
static uint16_t aFriendly_Library_RecoverySequence[]                 = {'r', 'e', 'c', 'o', 'v', 'e', 'r', 'y', 's', 'e', 'q', 'u', 'e', 'n', 'c', 'e', };                                                                            // recoverysequence
static uint16_t aFriendly_Library_AutoRecoveryEnabled[]              = {'r', 'e', 'c', 'o', 'v', 'e', 'r', 'y', 'e', 'n', 'a', 'b', 'l', 'e', 'd', };                                                                                 // recoveryenabled
static uint16_t aFriendly_Library_BadMemoryList[]                    = {'b', 'a', 'd', 'm', 'e', 'm', 'o', 'r', 'y', 'l', 'i', 's', 't', };                                                                                           // badmemorylist
static uint16_t aFriendly_Library_AllowBadMemoryAccess[]             = {'b', 'a', 'd', 'm', 'e', 'm', 'o', 'r', 'y', 'a', 'c', 'c', 'e', 's', 's', };                                                                                 // badmemoryaccess
static uint16_t aFriendly_Library_FirstMegabytePolicy[]              = {'f', 'i', 'r', 's', 't', 'm', 'e', 'g', 'a', 'b', 'y', 't', 'e', 'p', 'o', 'l', 'i', 'c', 'y', };                                                             // firstmegabytepolicy
static uint16_t aFriendly_Library_RelocatePhysicalMemory[]           = {'r', 'e', 'l', 'o', 'c', 'a', 't', 'e', 'p', 'h', 'y', 's', 'i', 'c', 'a', 'l', };                                                                            // relocatephysical
static uint16_t aFriendly_Library_AvoidLowPhysicalMemory[]           = {'a', 'v', 'o', 'i', 'd', 'l', 'o', 'w', 'm', 'e', 'm', 'o', 'r', 'y', };                                                                                      // avoidlowmemory
static uint16_t aFriendly_Library_TraditionalKsegMappings[]          = {'t', 'r', 'a', 'd', 'i', 't', 'i', 'o', 'n', 'a', 'l', 'k', 's', 'e', 'g', };                                                                                 // traditionalkseg
static uint16_t aFriendly_Library_DebuggerEnabled[]                  = {'b', 'o', 'o', 't', 'd', 'e', 'b', 'u', 'g', };                                                                                                               // bootdebug
static uint16_t aFriendly_Library_DebuggerType[]                     = {'d', 'e', 'b', 'u', 'g', 't', 'y', 'p', 'e', };                                                                                                               // debugtype
static uint16_t aFriendly_Library_SerialDebuggerPortAddress[]        = {'d', 'e', 'b', 'u', 'g', 'a', 'd', 'd', 'r', 'e', 's', 's', };                                                                                                // debugaddress
static uint16_t aFriendly_Library_SerialDebuggerPort[]               = {'d', 'e', 'b', 'u', 'g', 'p', 'o', 'r', 't', };                                                                                                               // debugport
static uint16_t aFriendly_Library_SerialDebuggerBaudRate[]           = {'b', 'a', 'u', 'd', 'r', 'a', 't', 'e', };                                                                                                                    // baudrate
static uint16_t aFriendly_Library_1394DebuggerChannel[]              = {'c', 'h', 'a', 'n', 'n', 'e', 'l', };                                                                                                                         // channel
static uint16_t aFriendly_Library_UsbDebuggerTargetName[]            = {'t', 'a', 'r', 'g', 'e', 't', 'n', 'a', 'm', 'e', };                                                                                                          // targetname
static uint16_t aFriendly_Library_DebuggerIgnoreUsermodeExceptions[] = {'n', 'o', 'u', 'm', 'e', 'x', };                                                                                                                              // noumex
static uint16_t aFriendly_Library_DebuggerStartPolicy[]              = {'d', 'e', 'b', 'u', 'g', 's', 't', 'a', 'r', 't', };                                                                                                          // debugstart
static uint16_t aFriendly_Library_DebuggerBusParameters[]            = {'b', 'u', 's', 'p', 'a', 'r', 'a', 'm', 's', };                                                                                                               // busparams
static uint16_t aFriendly_Library_DebuggerNetHostIP[]                = {'h', 'o', 's', 't', 'i', 'p', };                                                                                                                              // hostip
static uint16_t aFriendly_Library_DebuggerNetPort[]                  = {'p', 'o', 'r', 't', };                                                                                                                                        // port
static uint16_t aFriendly_Library_DebuggerNetDhcp[]                  = {'d', 'h', 'c', 'p', };                                                                                                                                        // dhcp
static uint16_t aFriendly_Library_DebuggerNetKey[]                   = {'k', 'e', 'y', };                                                                                                                                             // key
static uint16_t aFriendly_Library_DebuggerNetVm[]                    = {'v', 'm', };                                                                                                                                                  // vm
static uint16_t aFriendly_Library_DebuggerNetHostIpv6[]              = {'h', 'o', 's', 't', 'i', 'p', 'v', '6', };                                                                                                                    // hostipv6
static uint16_t aFriendly_Library_EmsEnabled[]                       = {'b', 'o', 'o', 't', 'e', 'm', 's', };                                                                                                                         // bootems
static uint16_t aFriendly_Library_EmsPort[]                          = {'e', 'm', 's', 'p', 'o', 'r', 't', };                                                                                                                         // emsport
static uint16_t aFriendly_Library_EmsBaudRate[]                      = {'e', 'm', 's', 'b', 'a', 'u', 'd', 'r', 'a', 't', 'e', };                                                                                                     // emsbaudrate
static uint16_t aFriendly_Library_LoadOptionsString[]                = {'l', 'o', 'a', 'd', 'o', 'p', 't', 'i', 'o', 'n', 's', };                                                                                                     // loadoptions
//static uint16_t aFriendly_Library_AttemptNonBcdStart[]               = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_DisplayAdvancedOptions[]           = {'a', 'd', 'v', 'a', 'n', 'c', 'e', 'd', 'o', 'p', 't', 'i', 'o', 'n', 's', };                                                                                 // advancedoptions
static uint16_t aFriendly_Library_DisplayOptionsEdit[]               = {'o', 'p', 't', 'i', 'o', 'n', 's', 'e', 'd', 'i', 't', };                                                                                                     // optionsedit
static uint16_t aFriendly_Library_FVEKeyRingAddress[]                = {'k', 'e', 'y', 'r', 'i', 'n', 'g', 'a', 'd', 'd', 'r', 'e', 's', 's', };                                                                                      // keyringaddress
static uint16_t aFriendly_Library_BsdLogDevice[]                     = {'b', 'o', 'o', 't', 's', 't', 'a', 't', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                      // bootstatdevice
static uint16_t aFriendly_Library_BsdLogPath[]                       = {'b', 'o', 'o', 't', 's', 't', 'a', 't', 'f', 'i', 'l', 'e', 'p', 'a', 't', 'h', };                                                                            // bootstatfilepath
static uint16_t aFriendly_Library_BsdPreserveLog[]                   = {'p', 'r', 'e', 's', 'e', 'r', 'v', 'e', 'b', 'o', 'o', 't', 's', 't', 'a', 't', };                                                                            // preservebootstat
static uint16_t aFriendly_Library_GraphicsModeDisabled[]             = {'g', 'r', 'a', 'p', 'h', 'i', 'c', 's', 'm', 'o', 'd', 'e', 'd', 'i', 's', 'a', 'b', 'l', 'e', 'd', };                                                        // graphicsmodedisabled
static uint16_t aFriendly_Library_ConfigAccessPolicy[]               = {'c', 'o', 'n', 'f', 'i', 'g', 'a', 'c', 'c', 'e', 's', 's', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                  // configaccesspolicy
static uint16_t aFriendly_Library_DisableIntegrityChecks[]           = {'n', 'o', 'i', 'n', 't', 'e', 'g', 'r', 'i', 't', 'y', 'c', 'h', 'e', 'c', 'k', 's', };                                                                       // nointegritychecks
static uint16_t aFriendly_Library_AllowPrereleaseSignatures[]        = {'t', 'e', 's', 't', 's', 'i', 'g', 'n', 'i', 'n', 'g', };                                                                                                     // testsigning
static uint16_t aFriendly_Library_FontPath[]                         = {'f', 'o', 'n', 't', 'p', 'a', 't', 'h', };                                                                                                                    // fontpath
static uint16_t aFriendly_Library_SiPolicy[]                         = {'i', 'n', 't', 'e', 'g', 'r', 'i', 't', 'y', 's', 'e', 'r', 'v', 'i', 'c', 'e', 's', };                                                                       // integrityservices
static uint16_t aFriendly_Library_FveBandId[]                        = {'v', 'o', 'l', 'u', 'm', 'e', 'b', 'a', 'n', 'd', 'i', 'd', };                                                                                                // volumebandid
static uint16_t aFriendly_Library_ConsoleExtendedInput[]             = {'e', 'x', 't', 'e', 'n', 'd', 'e', 'd', 'i', 'n', 'p', 'u', 't', };                                                                                           // extendedinput
static uint16_t aFriendly_Library_InitialConsoleInput[]              = {'i', 'n', 'i', 't', 'i', 'a', 'l', 'c', 'o', 'n', 's', 'o', 'l', 'e', 'i', 'n', 'p', 'u', 't', };                                                             // initialconsoleinput
static uint16_t aFriendly_Library_GraphicsResolution[]               = {'g', 'r', 'a', 'p', 'h', 'i', 'c', 's', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', };                                                                  // graphicsresolution
static uint16_t aFriendly_Library_RestartOnFailure[]                 = {'r', 'e', 's', 't', 'a', 'r', 't', 'o', 'n', 'f', 'a', 'i', 'l', 'u', 'r', 'e', };                                                                            // restartonfailure
static uint16_t aFriendly_Library_GraphicsForceHighestMode[]         = {'h', 'i', 'g', 'h', 'e', 's', 't', 'm', 'o', 'd', 'e', };                                                                                                     // highestmode
static uint16_t aFriendly_Library_IsolatedExecutionContext[]         = {'i', 's', 'o', 'l', 'a', 't', 'e', 'd', 'c', 'o', 'n', 't', 'e', 'x', 't', };                                                                                 // isolatedcontext
static uint16_t aFriendly_Library_BootUxDisplayMessage[]             = {'d', 'i', 's', 'p', 'l', 'a', 'y', 'm', 'e', 's', 's', 'a', 'g', 'e', };                                                                                      // displaymessage
static uint16_t aFriendly_Library_BootUxDisplayMessageOverride[]     = {'d', 'i', 's', 'p', 'l', 'a', 'y', 'm', 'e', 's', 's', 'a', 'g', 'e', 'o', 'v', 'e', 'r', 'r', 'i', 'd', 'e', };                                              // displaymessageoverride
//static uint16_t aFriendly_Library_BootUxLogoDisable[]                = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_BootUxTextDisable[]                = {'n', 'o', 'b', 'o', 'o', 't', 'u', 'x', 't', 'e', 'x', 't', };                                                                                                // nobootuxtext
static uint16_t aFriendly_Library_BootUxProgressDisable[]            = {'n', 'o', 'b', 'o', 'o', 't', 'u', 'x', 'p', 'r', 'o', 'g', 'r', 'e', 's', 's', };                                                                            // nobootuxprogress
static uint16_t aFriendly_Library_BootUxFadeDisable[]                = {'n', 'o', 'b', 'o', 'o', 't', 'u', 'x', 'f', 'a', 'd', 'e', };                                                                                                // nobootuxfade
//static uint16_t aFriendly_Library_BootUxReservePoolDebug[]           = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_BootUxDisable[]                    = {'b', 'o', 'o', 't', 'u', 'x', 'd', 'i', 's', 'a', 'b', 'l', 'e', 'd', };                                                                                      // bootuxdisabled
//static uint16_t aFriendly_Library_BootUxFadeFrames[]                 = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Library_BootUxDumpStats[]                  = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Library_BootUxShowStats[]                  = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Library_MultiBootSystem[]                  = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_ForceNoKeyboard[]                  = {'n', 'o', 'k', 'e', 'y', 'b', 'o', 'a', 'r', 'd', };                                                                                                          // nokeyboard
//static uint16_t aFriendly_Library_AliasWindowsKey[]                  = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_BootShutdownDisabled[]             = {'b', 'o', 'o', 't', 's', 'h', 'u', 't', 'd', 'o', 'w', 'n', 'd', 'i', 's', 'a', 'b', 'l', 'e', 'd', };                                                        // bootshutdowndisabled
//static uint16_t aFriendly_Library_PerformanceFrequency[]             = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Library_SecurebootRawPolicy[]              = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_AllowedInMemorySettings[]          = {'a', 'l', 'l', 'o', 'w', 'e', 'd', 'i', 'n', 'm', 'e', 'm', 'o', 'r', 'y', 's', 'e', 't', 't', 'i', 'n', 'g', 's', };                                         // allowedinmemorysettings
//static uint16_t aFriendly_Library_Unknown78[]                        = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_BootUxBitmapTransitionTime[]       = {'b', 'o', 'o', 't', 'u', 'x', 't', 'r', 'a', 'n', 's', 'i', 't', 'i', 'o', 'n', 't', 'i', 'm', 'e', };                                                        // bootuxtransitiontime
static uint16_t aFriendly_Library_TwoBootImages[]                    = {'m', 'o', 'b', 'i', 'l', 'e', 'g', 'r', 'a', 'p', 'h', 'i', 'c', 's', };                                                                                      // mobilegraphics
static uint16_t aFriendly_Library_ForceFipsCrypto[]                  = {'f', 'o', 'r', 'c', 'e', 'f', 'i', 'p', 's', 'c', 'r', 'y', 'p', 't', 'o', };                                                                                 // forcefipscrypto
static uint16_t aFriendly_Library_BootErrorUx[]                      = {'b', 'o', 'o', 't', 'e', 'r', 'r', 'o', 'r', 'u', 'x', };                                                                                                     // booterrorux
static uint16_t aFriendly_Library_AllowFlightSignatures[]            = {'f', 'l', 'i', 'g', 'h', 't', 's', 'i', 'g', 'n', 'i', 'n', 'g', };                                                                                           // flightsigning
static uint16_t aFriendly_Library_BootMeasurementLogFormat[]         = {'m', 'e', 'a', 's', 'u', 'r', 'e', 'd', 'b', 'o', 'o', 't', 'l', 'o', 'g', 'f', 'o', 'r', 'm', 'a', 't', };                                                   // measuredbootlogformat
static uint16_t aFriendly_Library_DisplayRotation[]                  = {'d', 'i', 's', 'p', 'l', 'a', 'y', 'r', 'o', 't', 'a', 't', 'i', 'o', 'n', };                                                                                 // displayrotation
static uint16_t aFriendly_Library_LogControl[]                       = {'l', 'o', 'g', 'c', 'o', 'n', 't', 'r', 'o', 'l', };                                                                                                          // logcontrol
static uint16_t aFriendly_Library_NoFirmwareSync[]                   = {'n', 'o', 'f', 'i', 'r', 'm', 'w', 'a', 'r', 'e', 's', 'y', 'n', 'c', };                                                                                      // nofirmwaresync
//static uint16_t aFriendly_Library_Unknown83[]                        = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_WindowsSystemDevice[]              = {'w', 'i', 'n', 'd', 'o', 'w', 's', 's', 'y', 's', 'p', 'a', 'r', 't', };                                                                                      // windowssyspart
//static uint16_t aFriendly_Library_Unknown85[]                        = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Library_Unknown86[]                        = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Library_NumLockOn[]                        = {'n', 'u', 'm', 'l', 'o', 'c', 'k', };                                                                                                                         // numlock
static uint16_t aFriendly_Library_AdditionalCiPolicy[]               = {'a', 'd', 'd', 'i', 't', 'i', 'o', 'n', 'a', 'l', 'c', 'i', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                  // additionalcipolicy
static uint16_t aFriendly_Library_LinearAddress57Policy[]            = {'l', 'i', 'n', 'e', 'a', 'r', 'a', 'd', 'd', 'r', 'e', 's', 's', '5', '7', };                                                                                 // linearaddress57
static uint16_t aFriendly_FfuLoader_OneShotSkipFfuUpdate[]           = {'s', 'k', 'i', 'p', 'f', 'f', 'u', 'm', 'o', 'd', 'e', };                                                                                                     // skipffumode
static uint16_t aFriendly_FfuLoader_ForceFfu[]                       = {'f', 'o', 'r', 'c', 'e', 'f', 'f', 'u', 'm', 'o', 'd', 'e', };                                                                                                // forceffumode
static uint16_t aFriendly_Charging_BootThreshold[]                   = {'c', 'h', 'a', 'r', 'g', 'e', 't', 'h', 'r', 'e', 's', 'h', 'o', 'l', 'd', };                                                                                 // chargethreshold
static uint16_t aFriendly_Charging_OffModeCharging[]                 = {'o', 'f', 'f', 'm', 'o', 'd', 'e', 'c', 'h', 'a', 'r', 'g', 'i', 'n', 'g', };                                                                                 // offmodecharging
static uint16_t aFriendly_Global_Bootflow[]                          = {'b', 'o', 'o', 't', 'f', 'l', 'o', 'w', };                                                                                                                    // bootflow
//static uint16_t aFriendly_Setup_DeviceType[]                         = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Setup_ApplicationRelativePath[]            = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Setup_RamdiskDeviceRelativePath[]          = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Setup_OmitOsLoaderElements[]               = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_Setup_ElementsToMigrateList[]              = {'e', 'l', 'e', 'm', 'e', 'n', 't', 's', 't', 'o', 'm', 'i', 'g', 'r', 'a', 't', 'e', };                                                                       // elementstomigrate
//static uint16_t aFriendly_Setup_RecoveryOs[]                         = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_BootMgr_DisplayOrder[]                     = {'d', 'i', 's', 'p', 'l', 'a', 'y', 'o', 'r', 'd', 'e', 'r', };                                                                                                // displayorder
static uint16_t aFriendly_BootMgr_BootSequence[]                     = {'b', 'o', 'o', 't', 's', 'e', 'q', 'u', 'e', 'n', 'c', 'e', };                                                                                                // bootsequence
static uint16_t aFriendly_BootMgr_DefaultObject[]                    = {'d', 'e', 'f', 'a', 'u', 'l', 't', };                                                                                                                         // default
static uint16_t aFriendly_BootMgr_Timeout[]                          = {'t', 'i', 'm', 'e', 'o', 'u', 't', };                                                                                                                         // timeout
static uint16_t aFriendly_BootMgr_AttemptResume[]                    = {'r', 'e', 's', 'u', 'm', 'e', };                                                                                                                              // resume
static uint16_t aFriendly_BootMgr_ResumeObject[]                     = {'r', 'e', 's', 'u', 'm', 'e', 'o', 'b', 'j', 'e', 'c', 't', };                                                                                                // resumeobject
static uint16_t aFriendly_BootMgr_StartupSequence[]                  = {'s', 't', 'a', 'r', 't', 'u', 'p', 's', 'e', 'q', 'u', 'e', 'n', 'c', 'e', };                                                                                 // startupsequence
static uint16_t aFriendly_BootMgr_ToolsDisplayOrder[]                = {'t', 'o', 'o', 'l', 's', 'd', 'i', 's', 'p', 'l', 'a', 'y', 'o', 'r', 'd', 'e', 'r', };                                                                       // toolsdisplayorder
static uint16_t aFriendly_BootMgr_DisplayBootMenu[]                  = {'d', 'i', 's', 'p', 'l', 'a', 'y', 'b', 'o', 'o', 't', 'm', 'e', 'n', 'u', };                                                                                 // displaybootmenu
static uint16_t aFriendly_BootMgr_NoErrorDisplay[]                   = {'n', 'o', 'e', 'r', 'r', 'o', 'r', 'd', 'i', 's', 'p', 'l', 'a', 'y', };                                                                                      // noerrordisplay
static uint16_t aFriendly_BootMgr_BcdDevice[]                        = {'b', 'c', 'd', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                                               // bcddevice
static uint16_t aFriendly_BootMgr_BcdFilePath[]                      = {'b', 'c', 'd', 'f', 'i', 'l', 'e', 'p', 'a', 't', 'h', };                                                                                                     // bcdfilepath
//static uint16_t aFriendly_BootMgr_HormEnabled[]                      = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_BootMgr_HiberRoot[]                        = {'h', 'i', 'b', 'e', 'r', 'b', 'o', 'o', 't', };                                                                                                               // hiberboot
//static uint16_t aFriendly_BootMgr_PasswordOverride[]                 = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_PinpassPhraseOverride[]            = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_BootMgr_ProcessCustomActionsFirst[]        = {'p', 'r', 'o', 'c', 'e', 's', 's', 'c', 'u', 's', 't', 'o', 'm', 'a', 'c', 't', 'i', 'o', 'n', 's', 'f', 'i', 'r', 's', 't', };                               // processcustomactionsfirst
//static uint16_t aFriendly_BootMgr_Unknown2A[]                        = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_BootMgr_CustomActionsList[]                = {'c', 'u', 's', 't', 'o', 'm', 'a', 'c', 't', 'i', 'o', 'n', 's', };                                                                                           // customactions
static uint16_t aFriendly_BootMgr_PersistBootSequence[]              = {'p', 'e', 'r', 's', 'i', 's', 't', 'b', 'o', 'o', 't', 's', 'e', 'q', 'u', 'e', 'n', 'c', 'e', };                                                             // persistbootsequence
static uint16_t aFriendly_BootMgr_SkipStartupSequence[]              = {'s', 'k', 'i', 'p', 's', 't', 'a', 'r', 't', 'u', 'p', 's', 'e', 'q', 'u', 'e', 'n', 'c', 'e', };                                                             // skipstartupsequence
static uint16_t aFriendly_BootMgr_FveRecoveryUrl[]                   = {'f', 'v', 'e', 'r', 'e', 'c', 'o', 'v', 'e', 'r', 'y', 'u', 'r', 'l', };                                                                                      // fverecoveryurl
static uint16_t aFriendly_BootMgr_FveRecoveryMessage[]               = {'f', 'v', 'e', 'r', 'e', 'c', 'o', 'v', 'e', 'r', 'y', 'm', 'e', 's', 's', 'a', 'g', 'e', };                                                                  // fverecoverymessage
static uint16_t aFriendly_BootMgr_FlightBootMgr[]                    = {'f', 'l', 'i', 'g', 'h', 't', 'e', 'd', 'b', 'o', 'o', 't', 'm', 'g', 'r', };                                                                                 // flightedbootmgr
//static uint16_t aFriendly_BootMgr_FveUnlockRetryCountIpv4[]          = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveUnlockRetryCountIpv6[]          = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveServerAddressIpv4[]             = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveServerAddressIpv6[]             = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveStationAddressIpv4[]            = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveStationAddressIpv6[]            = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveStationSubnetMaskIpv4[]         = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveStationSubnetMaskIpv6[]         = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveGatewayIpv4[]                   = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveGatewayIpv6[]                   = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_FveNetworkTimeout[]                = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_RemotePortIpv4[]                   = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_RemotePortIpv6[]                   = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_StationPortIpv4[]                  = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_BootMgr_StationPortIpv6[]                  = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_OsLoader_OsDevice[]                        = {'o', 's', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                                                    // osdevice
static uint16_t aFriendly_OsLoader_SystemRoot[]                      = {'s', 'y', 's', 't', 'e', 'm', 'r', 'o', 'o', 't', };                                                                                                          // systemroot
static uint16_t aFriendly_OsLoader_AssociatedResumeObject[]          = {'r', 'e', 's', 'u', 'm', 'e', 'o', 'b', 'j', 'e', 'c', 't', };                                                                                                // resumeobject
static uint16_t aFriendly_OsLoader_StampDisks[]                      = {'s', 't', 'a', 'm', 'p', 'd', 'i', 's', 'k', 's', };                                                                                                          // stampdisks
//static uint16_t aFriendly_OsLoader_Unknown5[]                        = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_OsLoader_Unknown8[]                        = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_OsLoader_DetectKernelAndHal[]              = {'d', 'e', 't', 'e', 'c', 't', 'h', 'a', 'l', };                                                                                                               // detecthal
static uint16_t aFriendly_OsLoader_KernelPath[]                      = {'k', 'e', 'r', 'n', 'e', 'l', };                                                                                                                              // kernel
static uint16_t aFriendly_OsLoader_HalPath[]                         = {'h', 'a', 'l', };                                                                                                                                             // hal
static uint16_t aFriendly_OsLoader_DbgTransportPath[]                = {'d', 'b', 'g', 't', 'r', 'a', 'n', 's', 'p', 'o', 'r', 't', };                                                                                                // dbgtransport
static uint16_t aFriendly_OsLoader_NxPolicy[]                        = {'n', 'x', };                                                                                                                                                  // nx
static uint16_t aFriendly_OsLoader_PaePolicy[]                       = {'p', 'a', 'e', };                                                                                                                                             // pae
static uint16_t aFriendly_OsLoader_WinPeMode[]                       = {'w', 'i', 'n', 'p', 'e', };                                                                                                                                   // winpe
static uint16_t aFriendly_OsLoader_DisableCrashAutoReboot[]          = {'n', 'o', 'c', 'r', 'a', 's', 'h', 'a', 'u', 't', 'o', 'r', 'e', 'b', 'o', 'o', 't', };                                                                       // nocrashautoreboot
static uint16_t aFriendly_OsLoader_UseLastGoodSettings[]             = {'l', 'a', 's', 't', 'k', 'n', 'o', 'w', 'n', 'g', 'o', 'o', 'd', };                                                                                           // lastknowngood
static uint16_t aFriendly_OsLoader_DisableCodeIntegrityChecks[]      = {'o', 's', 'l', 'n', 'o', 'i', 'n', 't', 'e', 'g', 'r', 'i', 't', 'y', 'c', 'h', 'e', 'c', 'k', 's', };                                                        // oslnointegritychecks
static uint16_t aFriendly_OsLoader_AllowPrereleaseSignatures[]       = {'o', 's', 'l', 't', 'e', 's', 't', 's', 'i', 'g', 'n', 'i', 'n', 'g', };                                                                                      // osltestsigning
static uint16_t aFriendly_OsLoader_NoLowMemory[]                     = {'n', 'o', 'l', 'o', 'w', 'm', 'e', 'm', };                                                                                                                    // nolowmem
static uint16_t aFriendly_OsLoader_RemoveMemory[]                    = {'r', 'e', 'm', 'o', 'v', 'e', 'm', 'e', 'm', 'o', 'r', 'y', };                                                                                                // removememory
static uint16_t aFriendly_OsLoader_IncreaseUserVa[]                  = {'i', 'n', 'c', 'r', 'e', 'a', 's', 'e', 'u', 's', 'e', 'r', 'v', 'a', };                                                                                      // increaseuserva
static uint16_t aFriendly_OsLoader_PerformaceDataMemory[]            = {'p', 'e', 'r', 'f', 'm', 'e', 'm', };                                                                                                                         // perfmem
static uint16_t aFriendly_OsLoader_UseVgaDriver[]                    = {'v', 'g', 'a', };                                                                                                                                             // vga
static uint16_t aFriendly_OsLoader_DisableBootDisplay[]              = {'q', 'u', 'i', 'e', 't', 'b', 'o', 'o', 't', };                                                                                                               // quietboot
static uint16_t aFriendly_OsLoader_DisableVesaBios[]                 = {'n', 'o', 'v', 'e', 's', 'a', };                                                                                                                              // novesa
static uint16_t aFriendly_OsLoader_DisableVgaMode[]                  = {'n', 'o', 'v', 'g', 'a', };                                                                                                                                   // novga
static uint16_t aFriendly_OsLoader_ClusterModeAddressing[]           = {'c', 'l', 'u', 's', 't', 'e', 'r', 'm', 'o', 'd', 'e', 'a', 'd', 'd', 'r', 'e', 's', 's', 'i', 'n', 'g', };                                                   // clustermodeaddressing
static uint16_t aFriendly_OsLoader_UsePhysicalDestination[]          = {'u', 's', 'e', 'p', 'h', 'y', 's', 'i', 'c', 'a', 'l', 'd', 'e', 's', 't', 'i', 'n', 'a', 't', 'i', 'o', 'n', };                                              // usephysicaldestination
static uint16_t aFriendly_OsLoader_RestrictApicCluster[]             = {'r', 'e', 's', 't', 'r', 'i', 'c', 't', 'a', 'p', 'i', 'c', 'c', 'l', 'u', 's', 't', 'e', 'r', };                                                             // restrictapiccluster
static uint16_t aFriendly_OsLoader_OsLoaderTypeEVStore[]             = {'e', 'v', 's', 't', 'o', 'r', 'e', };                                                                                                                         // evstore
static uint16_t aFriendly_OsLoader_UseLegacyApicMode[]               = {'u', 's', 'e', 'l', 'e', 'g', 'a', 'c', 'y', 'a', 'p', 'i', 'c', 'm', 'o', 'd', 'e', };                                                                       // uselegacyapicmode
static uint16_t aFriendly_OsLoader_X2ApicPolicy[]                    = {'x', '2', 'a', 'p', 'i', 'c', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                                                // x2apicpolicy
static uint16_t aFriendly_OsLoader_UseBootProcessorOnly[]            = {'o', 'n', 'e', 'c', 'p', 'u', };                                                                                                                              // onecpu
static uint16_t aFriendly_OsLoader_NumberOfProcessors[]              = {'n', 'u', 'm', 'p', 'r', 'o', 'c', };                                                                                                                         // numproc
static uint16_t aFriendly_OsLoader_ForceMaximumProcessors[]          = {'m', 'a', 'x', 'p', 'r', 'o', 'c', };                                                                                                                         // maxproc
static uint16_t aFriendly_OsLoader_ProcessorConfigurationFlags[]     = {'c', 'o', 'n', 'f', 'i', 'g', 'f', 'l', 'a', 'g', 's', };                                                                                                     // configflags
static uint16_t aFriendly_OsLoader_MaximizeGroupsCreated[]           = {'m', 'a', 'x', 'g', 'r', 'o', 'u', 'p', };                                                                                                                    // maxgroup
static uint16_t aFriendly_OsLoader_ForceGroupAwareness[]             = {'g', 'r', 'o', 'u', 'p', 'a', 'w', 'a', 'r', 'e', };                                                                                                          // groupaware
static uint16_t aFriendly_OsLoader_GroupSize[]                       = {'g', 'r', 'o', 'u', 'p', 's', 'i', 'z', 'e', };                                                                                                               // groupsize
static uint16_t aFriendly_OsLoader_UseFirmwarePciSettings[]          = {'u', 's', 'e', 'f', 'i', 'r', 'm', 'w', 'a', 'r', 'e', 'p', 'c', 'i', 's', 'e', 't', 't', 'i', 'n', 'g', 's', };                                              // usefirmwarepcisettings
static uint16_t aFriendly_OsLoader_MsiPolicy[]                       = {'m', 's', 'i', };                                                                                                                                             // msi
static uint16_t aFriendly_OsLoader_PciExpressPolicy[]                = {'p', 'c', 'i', 'e', 'x', 'p', 'r', 'e', 's', 's', };                                                                                                          // pciexpress
static uint16_t aFriendly_OsLoader_SafeBoot[]                        = {'s', 'a', 'f', 'e', 'b', 'o', 'o', 't', };                                                                                                                    // safeboot
static uint16_t aFriendly_OsLoader_SafeBootAlternateShell[]          = {'s', 'a', 'f', 'e', 'b', 'o', 'o', 't', 'a', 'l', 't', 'e', 'r', 'n', 'a', 't', 'e', 's', 'h', 'e', 'l', 'l', };                                              // safebootalternateshell
static uint16_t aFriendly_OsLoader_BootLogInitialization[]           = {'b', 'o', 'o', 't', 'l', 'o', 'g', };                                                                                                                         // bootlog
static uint16_t aFriendly_OsLoader_VerboseObjectLoadMode[]           = {'s', 'o', 's', };                                                                                                                                             // sos
static uint16_t aFriendly_OsLoader_KernelDebuggerEnabled[]           = {'d', 'e', 'b', 'u', 'g', };                                                                                                                                   // debug
static uint16_t aFriendly_OsLoader_DebuggerHalBreakpoint[]           = {'h', 'a', 'l', 'b', 'r', 'e', 'a', 'k', 'p', 'o', 'i', 'n', 't', };                                                                                           // halbreakpoint
static uint16_t aFriendly_OsLoader_UsePlatformClock[]                = {'u', 's', 'e', 'p', 'l', 'a', 't', 'f', 'o', 'r', 'm', 'c', 'l', 'o', 'c', 'k', };                                                                            // useplatformclock
static uint16_t aFriendly_OsLoader_ForceLegacyPlatform[]             = {'f', 'o', 'r', 'c', 'e', 'l', 'e', 'g', 'a', 'c', 'y', 'p', 'l', 'a', 't', 'f', 'o', 'r', 'm', };                                                             // forcelegacyplatform
static uint16_t aFriendly_OsLoader_UsePlatformTick[]                 = {'u', 's', 'e', 'p', 'l', 'a', 't', 'f', 'o', 'r', 'm', 't', 'i', 'c', 'k', };                                                                                 // useplatformtick
static uint16_t aFriendly_OsLoader_DisableDynamicTick[]              = {'d', 'i', 's', 'a', 'b', 'l', 'e', 'd', 'y', 'n', 'a', 'm', 'i', 'c', 't', 'i', 'c', 'k', };                                                                  // disabledynamictick
static uint16_t aFriendly_OsLoader_TscSyncPolicy[]                   = {'t', 's', 'c', 's', 'y', 'n', 'c', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                                           // tscsyncpolicy
static uint16_t aFriendly_OsLoader_EmsEnabled[]                      = {'e', 'm', 's', };                                                                                                                                             // ems
//static uint16_t aFriendly_OsLoader_ForceFailure[]                    = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_OsLoader_DriverLoadFailurePolicy[]         = {'d', 'r', 'i', 'v', 'e', 'r', 'l', 'o', 'a', 'd', 'f', 'a', 'i', 'l', 'u', 'r', 'e', 'p', 'o', 'l', 'i', 'c', 'y', };                                         // driverloadfailurepolicy
static uint16_t aFriendly_OsLoader_BootMenuPolicy[]                  = {'b', 'o', 'o', 't', 'm', 'e', 'n', 'u', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                                      // bootmenupolicy
static uint16_t aFriendly_OsLoader_AdvancedOptionsOneTime[]          = {'o', 'n', 'e', 't', 'i', 'm', 'e', 'a', 'd', 'v', 'a', 'n', 'c', 'e', 'd', 'o', 'p', 't', 'i', 'o', 'n', 's', };                                              // onetimeadvancedoptions
static uint16_t aFriendly_OsLoader_EditOptionsOneTime[]              = {'o', 'n', 'e', 't', 'i', 'm', 'e', 'o', 'p', 't', 'i', 'o', 'n', 's', 'e', 'd', 'i', 't', };                                                                  // onetimeoptionsedit
static uint16_t aFriendly_OsLoader_BootStatusPolicy[]                = {'b', 'o', 'o', 't', 's', 't', 'a', 't', 'u', 's', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                            // bootstatuspolicy
static uint16_t aFriendly_OsLoader_DisableElamDrivers[]              = {'d', 'i', 's', 'a', 'b', 'l', 'e', 'e', 'l', 'a', 'm', 'd', 'r', 'i', 'v', 'e', 'r', 's', };                                                                  // disableelamdrivers
static uint16_t aFriendly_OsLoader_HypervisorLaunchType[]            = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'l', 'a', 'u', 'n', 'c', 'h', 't', 'y', 'p', 'e', };                                                        // hypervisorlaunchtype
static uint16_t aFriendly_OsLoader_HypervisorPath[]                  = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'p', 'a', 't', 'h', };                                                                                      // hypervisorpath
static uint16_t aFriendly_OsLoader_HypervisorDebuggerEnabled[]       = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'd', 'e', 'b', 'u', 'g', };                                                                                 // hypervisordebug
static uint16_t aFriendly_OsLoader_HypervisorDebuggerType[]          = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'd', 'e', 'b', 'u', 'g', 't', 'y', 'p', 'e', };                                                             // hypervisordebugtype
static uint16_t aFriendly_OsLoader_HypervisorDebuggerPortNumber[]    = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'd', 'e', 'b', 'u', 'g', 'p', 'o', 'r', 't', };                                                             // hypervisordebugport
static uint16_t aFriendly_OsLoader_HypervisorDebuggerBaudrate[]      = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'b', 'a', 'u', 'd', 'r', 'a', 't', 'e', };                                                                  // hypervisorbaudrate
static uint16_t aFriendly_OsLoader_HypervisorDebugger1394Channel[]   = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'c', 'h', 'a', 'n', 'n', 'e', 'l', };                                                                       // hypervisorchannel
static uint16_t aFriendly_OsLoader_BootUxPolicy[]                    = {'b', 'o', 'o', 't', 'u', 'x', };                                                                                                                              // bootux
static uint16_t aFriendly_OsLoader_HypervisorSlatDisabled[]          = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'd', 'i', 's', 'a', 'b', 'l', 'e', 's', 'l', 'a', 't', };                                                   // hypervisordisableslat
static uint16_t aFriendly_OsLoader_HypervisorDebuggerBusParams[]     = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'b', 'u', 's', 'p', 'a', 'r', 'a', 'm', 's', };                                                             // hypervisorbusparams
static uint16_t aFriendly_OsLoader_HypervisorNumProc[]               = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'n', 'u', 'm', 'p', 'r', 'o', 'c', };                                                                       // hypervisornumproc
static uint16_t aFriendly_OsLoader_HypervisorRootProcPerNode[]       = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'r', 'o', 'o', 't', 'p', 'r', 'o', 'c', 'p', 'e', 'r', 'n', 'o', 'd', 'e', };                               // hypervisorrootprocpernode
static uint16_t aFriendly_OsLoader_HypervisorUseLargeVTlb[]          = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'u', 's', 'e', 'l', 'a', 'r', 'g', 'e', 'v', 't', 'l', 'b', };                                              // hypervisoruselargevtlb
static uint16_t aFriendly_OsLoader_HypervisorDebuggerNetHostIp[]     = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'h', 'o', 's', 't', 'i', 'p', };                                                                            // hypervisorhostip
static uint16_t aFriendly_OsLoader_HypervisorDebuggerNetHostPort[]   = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'h', 'o', 's', 't', 'p', 'o', 'r', 't', };                                                                  // hypervisorhostport
static uint16_t aFriendly_OsLoader_HypervisorDebuggerPages[]         = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'd', 'e', 'b', 'u', 'g', 'p', 'a', 'g', 'e', 's', };                                                        // hypervisordebugpages
static uint16_t aFriendly_OsLoader_TpmBootEntropyPolicy[]            = {'t', 'p', 'm', 'b', 'o', 'o', 't', 'e', 'n', 't', 'r', 'o', 'p', 'y', };                                                                                      // tpmbootentropy
static uint16_t aFriendly_OsLoader_HypervisorDebuggerNetKey[]        = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'u', 's', 'e', 'k', 'e', 'y', };                                                                            // hypervisorusekey
//static uint16_t aFriendly_OsLoader_HypervisorProductSkuType[]        = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_OsLoader_HypervisorRootProc[]              = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'r', 'o', 'o', 't', 'p', 'r', 'o', 'c', };                                                                  // hypervisorrootproc
static uint16_t aFriendly_OsLoader_HypervisorDebuggerNetDhcp[]       = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'd', 'h', 'c', 'p', };                                                                                      // hypervisordhcp
static uint16_t aFriendly_OsLoader_HypervisorIommuPolicy[]           = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'i', 'o', 'm', 'm', 'u', 'p', 'o', 'l', 'i', 'c', 'y', };                                                   // hypervisoriommupolicy
static uint16_t aFriendly_OsLoader_HypervisorUseVApic[]              = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'u', 's', 'e', 'v', 'a', 'p', 'i', 'c', };                                                                  // hypervisorusevapic
static uint16_t aFriendly_OsLoader_HypervisorLoadOptions[]           = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'l', 'o', 'a', 'd', 'o', 'p', 't', 'i', 'o', 'n', 's', };                                                   // hypervisorloadoptions
static uint16_t aFriendly_OsLoader_HypervisorMsrFilterPolicy[]       = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'm', 's', 'r', 'f', 'i', 'l', 't', 'e', 'r', 'p', 'o', 'l', 'i', 'c', 'y', };                               // hypervisormsrfilterpolicy
static uint16_t aFriendly_OsLoader_HypervisorMmioNxPolicy[]          = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'm', 'm', 'i', 'o', 'n', 'x', 'p', 'o', 'l', 'i', 'c', 'y', };                                              // hypervisormmionxpolicy
static uint16_t aFriendly_OsLoader_HypervisorSchedulerType[]         = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 's', 'c', 'h', 'e', 'd', 'u', 'l', 'e', 'r', 't', 'y', 'p', 'e', };                                         // hypervisorschedulertype
static uint16_t aFriendly_OsLoader_HypervisorRootProcNumaNodes[]     = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'r', 'o', 'o', 't', 'p', 'r', 'o', 'c', 'n', 'u', 'm', 'a', 'n', 'o', 'd', 'e', 's', };                     // hypervisorrootprocnumanodes
static uint16_t aFriendly_OsLoader_HypervisorPerfmon[]               = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'p', 'e', 'r', 'f', 'm', 'o', 'n', };                                                                       // hypervisorperfmon
static uint16_t aFriendly_OsLoader_HypervisorRootProcPerCore[]       = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'r', 'o', 'o', 't', 'p', 'r', 'o', 'c', 'p', 'e', 'r', 'c', 'o', 'r', 'e', };                               // hypervisorrootprocpercore
static uint16_t aFriendly_OsLoader_HypervisorRootProcNumaNodeLps[]   = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'r', 'o', 'o', 't', 'p', 'r', 'o', 'c', 'n', 'u', 'm', 'a', 'n', 'o', 'd', 'e', 'l', 'p', 's', };           // hypervisorrootprocnumanodelps
static uint16_t aFriendly_OsLoader_XSavePolicy[]                     = {'x', 's', 'a', 'v', 'e', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                                                     // xsavepolicy
static uint16_t aFriendly_OsLoader_XSaveAddFeature0[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '0', };                                                                            // xsaveaddfeature0
static uint16_t aFriendly_OsLoader_XSaveAddFeature1[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '1', };                                                                            // xsaveaddfeature1
static uint16_t aFriendly_OsLoader_XSaveAddFeature2[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '2', };                                                                            // xsaveaddfeature2
static uint16_t aFriendly_OsLoader_XSaveAddFeature3[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '3', };                                                                            // xsaveaddfeature3
static uint16_t aFriendly_OsLoader_XSaveAddFeature4[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '4', };                                                                            // xsaveaddfeature4
static uint16_t aFriendly_OsLoader_XSaveAddFeature5[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '5', };                                                                            // xsaveaddfeature5
static uint16_t aFriendly_OsLoader_XSaveAddFeature6[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '6', };                                                                            // xsaveaddfeature6
static uint16_t aFriendly_OsLoader_XSaveAddFeature7[]                = {'x', 's', 'a', 'v', 'e', 'a', 'd', 'd', 'f', 'e', 'a', 't', 'u', 'r', 'e', '7', };                                                                            // xsaveaddfeature7
static uint16_t aFriendly_OsLoader_XSaveRemoveFeature[]              = {'x', 's', 'a', 'v', 'e', 'r', 'e', 'm', 'o', 'v', 'e', 'f', 'e', 'a', 't', 'u', 'r', 'e', };                                                                  // xsaveremovefeature
static uint16_t aFriendly_OsLoader_XSaveProcessorsMask[]             = {'x', 's', 'a', 'v', 'e', 'p', 'r', 'o', 'c', 'e', 's', 's', 'o', 'r', 's', 'm', 'a', 's', 'k', };                                                             // xsaveprocessorsmask
static uint16_t aFriendly_OsLoader_XSaveDisable[]                    = {'x', 's', 'a', 'v', 'e', 'd', 'i', 's', 'a', 'b', 'l', 'e', };                                                                                                // xsavedisable
static uint16_t aFriendly_OsLoader_KernelDebuggerType[]              = {'k', 'e', 'r', 'n', 'e', 'l', 'd', 'e', 'b', 'u', 'g', 't', 'y', 'p', 'e', };                                                                                 // kerneldebugtype
static uint16_t aFriendly_OsLoader_kernelDebuggerBusParameters[]     = {'k', 'e', 'r', 'n', 'e', 'l', 'b', 'u', 's', 'p', 'a', 'r', 'a', 'm', 's', };                                                                                 // kernelbusparams
static uint16_t aFriendly_OsLoader_kernelDebuggerPortAddress[]       = {'k', 'e', 'r', 'n', 'e', 'l', 'd', 'e', 'b', 'u', 'g', 'a', 'd', 'd', 'r', 'e', 's', 's', };                                                                  // kerneldebugaddress
static uint16_t aFriendly_OsLoader_KernelDebuggerPortNumber[]        = {'k', 'e', 'r', 'n', 'e', 'l', 'd', 'e', 'b', 'u', 'g', 'p', 'o', 'r', 't', };                                                                                 // kerneldebugport
static uint16_t aFriendly_OsLoader_FveClaimedDeviceLockCounter[]     = {'c', 'l', 'a', 'i', 'm', 'e', 'd', 't', 'p', 'm', 'c', 'o', 'u', 'n', 't', 'e', 'r', };                                                                       // claimedtpmcounter
static uint16_t aFriendly_OsLoader_KernelDebugger1394Channel[]       = {'k', 'e', 'r', 'n', 'e', 'l', 'c', 'h', 'a', 'n', 'n', 'e', 'l', };                                                                                           // kernelchannel
static uint16_t aFriendly_OsLoader_KernelDebuggerUsbTargetname[]     = {'k', 'e', 'r', 'n', 'e', 'l', 't', 'a', 'r', 'g', 'e', 't', 'n', 'a', 'm', 'e', };                                                                            // kerneltargetname
static uint16_t aFriendly_OsLoader_KernelDebuggerNetHostIp[]         = {'k', 'e', 'r', 'n', 'e', 'l', 'h', 'o', 's', 't', 'i', 'p', };                                                                                                // kernelhostip
static uint16_t aFriendly_OsLoader_KernelDebuggerNetHostPort[]       = {'k', 'e', 'r', 'n', 'e', 'l', 'p', 'o', 'r', 't', };                                                                                                          // kernelport
static uint16_t aFriendly_OsLoader_KernelDebuggerNetDhcp[]           = {'k', 'e', 'r', 'n', 'e', 'l', 'd', 'h', 'c', 'p', };                                                                                                          // kerneldhcp
static uint16_t aFriendly_OsLoader_KernelDebuggerNetKey[]            = {'k', 'e', 'r', 'n', 'e', 'l', 'k', 'e', 'y', };                                                                                                               // kernelkey
static uint16_t aFriendly_OsLoader_IMCHiveName[]                     = {'i', 'm', 'c', 'h', 'i', 'v', 'e', 'n', 'a', 'm', 'e', };                                                                                                     // imchivename
static uint16_t aFriendly_OsLoader_IMCDevice[]                       = {'i', 'm', 'c', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                                               // imcdevice
static uint16_t aFriendly_OsLoader_KernelDebuggerBaudrate[]          = {'k', 'e', 'r', 'n', 'e', 'l', 'b', 'a', 'u', 'd', 'r', 'a', 't', 'e', };                                                                                      // kernelbaudrate
static uint16_t aFriendly_OsLoader_ManufacturingMode[]               = {'m', 'f', 'g', 'm', 'o', 'd', 'e', };                                                                                                                         // mfgmode
static uint16_t aFriendly_OsLoader_EventLoggingEnabled[]             = {'e', 'v', 'e', 'n', 't', };                                                                                                                                   // event
static uint16_t aFriendly_OsLoader_VsmLaunchType[]                   = {'v', 's', 'm', 'l', 'a', 'u', 'n', 'c', 'h', 't', 'y', 'p', 'e', };                                                                                           // vsmlaunchtype
static uint16_t aFriendly_OsLoader_HypervisorEnforcedCodeIntegrity[] = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'e', 'n', 'f', 'o', 'r', 'c', 'e', 'd', 'c', 'o', 'd', 'e', 'i', 'n', 't', 'e', 'g', 'r', 'i', 't', 'y', }; // hypervisorenforcedcodeintegrity
static uint16_t aFriendly_OsLoader_DtraceEnabled[]                   = {'d', 't', 'r', 'a', 'c', 'e', };                                                                                                                              // dtrace
static uint16_t aFriendly_OsLoader_SystemDataDevice[]                = {'s', 'y', 's', 't', 'e', 'm', 'd', 'a', 't', 'a', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                            // systemdatadevice
static uint16_t aFriendly_OsLoader_OsArcDevice[]                     = {'o', 's', 'a', 'r', 'c', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                                     // osarcdevice
//static uint16_t aFriendly_OsLoader_Unknown152[]                      = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_OsLoader_OsDataDevice[]                    = {'o', 's', 'd', 'a', 't', 'a', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                                // osdatadevice
static uint16_t aFriendly_OsLoader_BspDevice[]                       = {'b', 's', 'p', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                                               // bspdevice
static uint16_t aFriendly_OsLoader_BspFilepath[]                     = {'b', 's', 'p', 'f', 'i', 'l', 'e', 'p', 'a', 't', 'h', };                                                                                                     // bspfilepath
static uint16_t aFriendly_OsLoader_KernelDebuggerNetHostIpv6[]       = {'k', 'e', 'r', 'n', 'e', 'l', 'h', 'o', 's', 't', 'i', 'p', 'v', '6', };                                                                                      // kernelhostipv6
static uint16_t aFriendly_OsLoader_HypervisorDebuggerNetHostIpv6[]   = {'h', 'y', 'p', 'e', 'r', 'v', 'i', 's', 'o', 'r', 'h', 'o', 's', 't', 'i', 'p', 'v', '6', };                                                                  // hypervisorhostipv6
static uint16_t aFriendly_Resume_HiberFileDevice[]                   = {'f', 'i', 'l', 'e', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                                                          // filedevice
static uint16_t aFriendly_Resume_HiberFilePath[]                     = {'f', 'i', 'l', 'e', 'p', 'a', 't', 'h', };                                                                                                                    // filepath
static uint16_t aFriendly_Resume_UseCustomSettings[]                 = {'c', 'u', 's', 't', 'o', 'm', 's', 'e', 't', 't', 'i', 'n', 'g', 's', };                                                                                      // customsettings
static uint16_t aFriendly_Resume_x86PaeMode[]                        = {'p', 'a', 'e', };                                                                                                                                             // pae
static uint16_t aFriendly_Resume_AssociatedOsDevice[]                = {'a', 's', 's', 'o', 'c', 'i', 'a', 't', 'e', 'd', 'o', 's', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                  // associatedosdevice
static uint16_t aFriendly_Resume_DebugOptionEnabled[]                = {'d', 'e', 'b', 'u', 'g', 'o', 'p', 't', 'i', 'o', 'n', 'e', 'n', 'a', 'b', 'l', 'e', 'd', };                                                                  // debugoptionenabled
static uint16_t aFriendly_Resume_BootUxPolicy[]                      = {'b', 'o', 'o', 't', 'u', 'x', };                                                                                                                              // bootux
static uint16_t aFriendly_Resume_BootMenuPolicy[]                    = {'b', 'o', 'o', 't', 'm', 'e', 'n', 'u', 'p', 'o', 'l', 'i', 'c', 'y', };                                                                                      // bootmenupolicy
//static uint16_t aFriendly_Resume_HormEnabled[]                       = {'?', };                                                                                                                                                       // ?
//static uint16_t aFriendly_Resume_Unknown26[]                         = {'?', };                                                                                                                                                       // ?
static uint16_t aFriendly_MemDiag_PassCount[]                        = {'p', 'a', 's', 's', 'c', 'o', 'u', 'n', 't', };                                                                                                               // passcount
static uint16_t aFriendly_MemDiag_TestMix[]                          = {'t', 'e', 's', 't', 'm', 'i', 'x', };                                                                                                                         // testmix
static uint16_t aFriendly_MemDiag_FailureCount[]                     = {'f', 'a', 'i', 'l', 'u', 'r', 'e', 'c', 'o', 'u', 'n', 't', };                                                                                                // failurecount
static uint16_t aFriendly_MemDiag_CacheEnabled[]                     = {'c', 'a', 'c', 'h', 'e', 'e', 'n', 'a', 'b', 'l', 'e', };                                                                                                     // cacheenable
static uint16_t aFriendly_MemDiag_TestToFail[]                       = {'t', 'e', 's', 't', 't', 'o', 'f', 'a', 'i', 'l', };                                                                                                          // testtofail
static uint16_t aFriendly_MemDiag_FailuresEnabled[]                  = {'f', 'a', 'i', 'l', 'u', 'r', 'e', 's', 'e', 'n', 'a', 'b', 'l', 'e', 'd', };                                                                                 // failuresenabled
static uint16_t aFriendly_MemDiag_CacheEnable[]                      = {'c', 'a', 'c', 'h', 'e', 'e', 'n', 'a', 'b', 'l', 'e', };                                                                                                     // cacheenable
static uint16_t aFriendly_MemDiag_StrideFailureCount[]               = {'s', 't', 'r', 'i', 'd', 'e', 'f', 'a', 'i', 'l', 'c', 'o', 'u', 'n', 't', };                                                                                 // stridefailcount
static uint16_t aFriendly_MemDiag_InvcFailureCount[]                 = {'i', 'n', 'v', 'c', 'f', 'a', 'i', 'l', 'c', 'o', 'u', 'n', 't', };                                                                                           // invcfailcount
static uint16_t aFriendly_MemDiag_MatsFailureCount[]                 = {'m', 'a', 't', 's', 'f', 'a', 'i', 'l', 'c', 'o', 'u', 'n', 't', };                                                                                           // matsfailcount
static uint16_t aFriendly_MemDiag_RandFailureCount[]                 = {'r', 'a', 'n', 'd', 'f', 'a', 'i', 'l', 'c', 'o', 'u', 'n', 't', };                                                                                           // randfailcount
static uint16_t aFriendly_MemDiag_ChckrFailureCount[]                = {'c', 'h', 'c', 'k', 'r', 'f', 'a', 'i', 'l', 'c', 'o', 'u', 'n', 't', };                                                                                      // chckrfailcount
static uint16_t aFriendly_LegacyLdr_BpbString[]                      = {'b', 'p', 'b', 's', 't', 'r', 'i', 'n', 'g', };                                                                                                               // bpbstring
static uint16_t aFriendly_Startup_PxeSoftReboot[]                    = {'p', 'x', 'e', 's', 'o', 'f', 't', 'r', 'e', 'b', 'o', 'o', 't', };                                                                                           // pxesoftreboot
static uint16_t aFriendly_Startup_PxeApplicationName[]               = {'a', 'p', 'p', 'l', 'i', 'c', 'a', 't', 'i', 'o', 'n', 'n', 'a', 'm', 'e', };                                                                                 // applicationname
static uint16_t aFriendly_MobileStartup_EnableBootDebugPolicy[]      = {'e', 'n', 'a', 'b', 'l', 'e', 'b', 'o', 'o', 't', 'd', 'e', 'b', 'u', 'g', 'p', 'o', 'l', 'i', 'c', 'y', };                                                   // enablebootdebugpolicy
static uint16_t aFriendly_MobileStartup_EnableBootOrderClean[]       = {'e', 'n', 'a', 'b', 'l', 'e', 'b', 'o', 'o', 't', 'o', 'r', 'd', 'e', 'r', 'c', 'l', 'e', 'a', 'n', };                                                        // enablebootorderclean
static uint16_t aFriendly_MobileStartup_EnableDeviceId[]             = {'e', 'n', 'a', 'b', 'l', 'e', 'd', 'e', 'v', 'i', 'c', 'e', 'i', 'd', };                                                                                      // enabledeviceid
static uint16_t aFriendly_MobileStartup_EnableFfuLoader[]            = {'e', 'n', 'a', 'b', 'l', 'e', 'f', 'f', 'u', 'l', 'o', 'a', 'd', 'e', 'r', };                                                                                 // enableffuloader
static uint16_t aFriendly_MobileStartup_EnableIuLoader[]             = {'e', 'n', 'a', 'b', 'l', 'e', 'i', 'u', 'l', 'o', 'a', 'd', 'e', 'r', };                                                                                      // enableiuloader
static uint16_t aFriendly_MobileStartup_EnableMassStorage[]          = {'e', 'n', 'a', 'b', 'l', 'e', 'm', 'a', 's', 's', 's', 't', 'o', 'r', 'a', 'g', 'e', };                                                                       // enablemassstorage
static uint16_t aFriendly_MobileStartup_EnableRpmbProvisioning[]     = {'e', 'n', 'a', 'b', 'l', 'e', 'r', 'p', 'm', 'b', 'p', 'r', 'o', 'v', 'i', 's', 'i', 'o', 'n', 'i', 'n', 'g', };                                              // enablerpmbprovisioning
static uint16_t aFriendly_MobileStartup_EnableSecureBootPolicy[]     = {'e', 'n', 'a', 'b', 'l', 'e', 's', 'e', 'c', 'u', 'r', 'e', 'b', 'o', 'o', 't', 'p', 'o', 'l', 'i', 'c', 'y', };                                              // enablesecurebootpolicy
static uint16_t aFriendly_MobileStartup_EnableStartCharge[]          = {'e', 'n', 'a', 'b', 'l', 'e', 's', 't', 'a', 'r', 't', 'c', 'h', 'a', 'r', 'g', 'e', };                                                                       // enablestartcharge
static uint16_t aFriendly_MobileStartup_EnableResetTpm[]             = {'e', 'n', 'a', 'b', 'l', 'e', 'r', 'e', 's', 'e', 't', 't', 'p', 'm', };                                                                                      // enableresettpm
static uint16_t aFriendly_Device_RamdiskImageOffset[]                = {'r', 'a', 'm', 'd', 'i', 's', 'k', 'i', 'm', 'a', 'g', 'e', 'o', 'f', 'f', 's', 'e', 't', };                                                                  // ramdiskimageoffset
static uint16_t aFriendly_Device_TftpClientPort[]                    = {'r', 'a', 'm', 'd', 'i', 's', 'k', 't', 'f', 't', 'p', 'c', 'l', 'i', 'e', 'n', 't', 'p', 'o', 'r', 't', };                                                   // ramdisktftpclientport
static uint16_t aFriendly_Device_SdiDevice[]                         = {'r', 'a', 'm', 'd', 'i', 's', 'k', 's', 'd', 'i', 'd', 'e', 'v', 'i', 'c', 'e', };                                                                            // ramdisksdidevice
static uint16_t aFriendly_Device_SdiPath[]                           = {'r', 'a', 'm', 'd', 'i', 's', 'k', 's', 'd', 'i', 'p', 'a', 't', 'h', };                                                                                      // ramdisksdipath
static uint16_t aFriendly_Device_RamdiskImageLength[]                = {'r', 'a', 'm', 'd', 'i', 's', 'k', 'i', 'm', 'a', 'g', 'e', 'l', 'e', 'n', 'g', 't', 'h', };                                                                  // ramdiskimagelength
static uint16_t aFriendly_Device_RamdiskExportAsCd[]                 = {'e', 'x', 'p', 'o', 'r', 't', 'a', 's', 'c', 'd', };                                                                                                          // exportascd
static uint16_t aFriendly_Device_RamdiskTftpBlockSize[]              = {'r', 'a', 'm', 'd', 'i', 's', 'k', 't', 'f', 't', 'p', 'b', 'l', 'o', 'c', 'k', 's', 'i', 'z', 'e', };                                                        // ramdisktftpblocksize
static uint16_t aFriendly_Device_RamdiskTftpWindowSize[]             = {'r', 'a', 'm', 'd', 'i', 's', 'k', 't', 'f', 't', 'p', 'w', 'i', 'n', 'd', 'o', 'w', 's', 'i', 'z', 'e', };                                                   // ramdisktftpwindowsize
static uint16_t aFriendly_Device_RamdiskMulticastEnabled[]           = {'r', 'a', 'm', 'd', 'i', 's', 'k', 'm', 'c', 'e', 'n', 'a', 'b', 'l', 'e', 'd', };                                                                            // ramdiskmcenabled
static uint16_t aFriendly_Device_RamdiskMulticastTftpFallback[]      = {'r', 'a', 'm', 'd', 'i', 's', 'k', 'm', 'c', 't', 'f', 't', 'p', 'f', 'a', 'l', 'l', 'b', 'a', 'c', 'k', };                                                   // ramdiskmctftpfallback
static uint16_t aFriendly_Device_RamdiskTftpVarWindow[]              = {'r', 'a', 'm', 'd', 'i', 's', 'k', 't', 'f', 't', 'p', 'v', 'a', 'r', 'w', 'i', 'n', 'd', 'o', 'w', };                                                        // ramdisktftpvarwindow
static uint16_t aFriendly_Device_VhdRamdiskBoot[]                    = {'v', 'h', 'd', 'r', 'a', 'm', 'd', 'i', 's', 'k', 'b', 'o', 'o', 't', };                                                                                      // vhdramdiskboot
//static uint16_t aFriendly_Device_UnknownD[]                          = {'?', };                                                                                                                                                       // ?

#define BCD_EMPTY_STRING {0, 0, NULL}

typedef struct {
	bcd_element_id Id;
	const registry_string16 FriendlyName;
} bcd_id_and_friendly;

static const bcd_id_and_friendly gaIdToFriendlyLibrary[] = {
	{0x11000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_ApplicationDevice)},
	{0x12000002, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_ApplicationPath)},
	{0x10000003, BCD_EMPTY_STRING},
	{0x12000004, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_Description)},
	{0x12000005, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_PreferredLocale)},
	{0x14000006, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_InheritedObjects)},
	{0x15000007, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_TruncatePhysicalMemory)},
	{0x14000008, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_RecoverySequence)},
	{0x16000009, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_AutoRecoveryEnabled)},
	{0x1700000A, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BadMemoryList)},
	{0x1600000B, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_AllowBadMemoryAccess)},
	{0x1500000C, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_FirstMegabytePolicy)},
	{0x1500000D, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_RelocatePhysicalMemory)},
	{0x1500000E, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_AvoidLowPhysicalMemory)},
	{0x1600000F, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_TraditionalKsegMappings)},
	{0x16000010, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerEnabled)},
	{0x15000011, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerType)},
	{0x15000012, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_SerialDebuggerPortAddress)},
	{0x15000013, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_SerialDebuggerPort)},
	{0x15000014, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_SerialDebuggerBaudRate)},
	{0x15000015, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_1394DebuggerChannel)},
	{0x12000016, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_UsbDebuggerTargetName)},
	{0x16000017, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerIgnoreUsermodeExceptions)},
	{0x15000018, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerStartPolicy)},
	{0x12000019, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerBusParameters)},
	{0x1500001A, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerNetHostIP)},
	{0x1500001B, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerNetPort)},
	{0x1600001C, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerNetDhcp)},
	{0x1200001D, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerNetKey)},
	{0x1600001E, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerNetVm)},
	{0x1200001F, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DebuggerNetHostIpv6)},
	{0x16000020, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_EmsEnabled)},
	{0x10000021, BCD_EMPTY_STRING},
	{0x15000022, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_EmsPort)},
	{0x15000023, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_EmsBaudRate)},
	{0x10000024, BCD_EMPTY_STRING},
	{0x10000025, BCD_EMPTY_STRING},
	{0x10000026, BCD_EMPTY_STRING},
	{0x10000027, BCD_EMPTY_STRING},
	{0x10000028, BCD_EMPTY_STRING},
	{0x10000029, BCD_EMPTY_STRING},
	{0x1000002A, BCD_EMPTY_STRING},
	{0x1000002B, BCD_EMPTY_STRING},
	{0x1000002C, BCD_EMPTY_STRING},
	{0x1000002D, BCD_EMPTY_STRING},
	{0x1000002E, BCD_EMPTY_STRING},
	{0x1000002F, BCD_EMPTY_STRING},
	{0x12000030, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_LoadOptionsString)},
	{0x10000031, BCD_EMPTY_STRING},
	{0x10000032, BCD_EMPTY_STRING},
	{0x10000033, BCD_EMPTY_STRING},
	{0x10000034, BCD_EMPTY_STRING},
	{0x10000035, BCD_EMPTY_STRING},
	{0x10000036, BCD_EMPTY_STRING},
	{0x10000037, BCD_EMPTY_STRING},
	{0x10000038, BCD_EMPTY_STRING},
	{0x10000039, BCD_EMPTY_STRING},
	{0x1000003A, BCD_EMPTY_STRING},
	{0x1000003B, BCD_EMPTY_STRING},
	{0x1000003C, BCD_EMPTY_STRING},
	{0x1000003D, BCD_EMPTY_STRING},
	{0x1000003E, BCD_EMPTY_STRING},
	{0x1000003F, BCD_EMPTY_STRING},
	{0x16000040, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DisplayAdvancedOptions)},
	{0x16000041, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DisplayOptionsEdit)},
	{0x15000042, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_FVEKeyRingAddress)},
	{0x11000043, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BsdLogDevice)},
	{0x12000044, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BsdLogPath)},
	{0x16000045, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BsdPreserveLog)},
	{0x16000046, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_GraphicsModeDisabled)},
	{0x15000047, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_ConfigAccessPolicy)},
	{0x16000048, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DisableIntegrityChecks)},
	{0x16000049, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_AllowPrereleaseSignatures)},
	{0x1200004A, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_FontPath)},
	{0x1500004B, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_SiPolicy)},
	{0x1500004C, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_FveBandId)},
	{0x1000004D, BCD_EMPTY_STRING},
	{0x1000004E, BCD_EMPTY_STRING},
	{0x1000004F, BCD_EMPTY_STRING},
	{0x16000050, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_ConsoleExtendedInput)},
	{0x15000051, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_InitialConsoleInput)},
	{0x15000052, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_GraphicsResolution)},
	{0x16000053, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_RestartOnFailure)},
	{0x16000054, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_GraphicsForceHighestMode)},
	{0x10000055, BCD_EMPTY_STRING},
	{0x10000056, BCD_EMPTY_STRING},
	{0x10000057, BCD_EMPTY_STRING},
	{0x10000058, BCD_EMPTY_STRING},
	{0x10000059, BCD_EMPTY_STRING},
	{0x1000005A, BCD_EMPTY_STRING},
	{0x1000005B, BCD_EMPTY_STRING},
	{0x1000005C, BCD_EMPTY_STRING},
	{0x1000005D, BCD_EMPTY_STRING},
	{0x1000005E, BCD_EMPTY_STRING},
	{0x1000005F, BCD_EMPTY_STRING},
	{0x16000060, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_IsolatedExecutionContext)},
	{0x10000061, BCD_EMPTY_STRING},
	{0x10000062, BCD_EMPTY_STRING},
	{0x10000063, BCD_EMPTY_STRING},
	{0x10000064, BCD_EMPTY_STRING},
	{0x15000065, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootUxDisplayMessage)},
	{0x15000066, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootUxDisplayMessageOverride)},
	{0x10000067, BCD_EMPTY_STRING},
	{0x16000068, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootUxTextDisable)},
	{0x16000069, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootUxProgressDisable)},
	{0x1600006A, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootUxFadeDisable)},
	{0x1000006B, BCD_EMPTY_STRING},
	{0x1600006C, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootUxDisable)},
	{0x1000006D, BCD_EMPTY_STRING},
	{0x1000006E, BCD_EMPTY_STRING},
	{0x1000006F, BCD_EMPTY_STRING},
	{0x10000070, BCD_EMPTY_STRING},
	{0x10000071, BCD_EMPTY_STRING},
	{0x16000072, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_ForceNoKeyboard)},
	{0x10000073, BCD_EMPTY_STRING},
	{0x16000074, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootShutdownDisabled)},
	{0x10000075, BCD_EMPTY_STRING},
	{0x10000076, BCD_EMPTY_STRING},
	{0x17000077, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_AllowedInMemorySettings)},
	{0x10000078, BCD_EMPTY_STRING},
	{0x15000079, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootUxBitmapTransitionTime)},
	{0x1600007A, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_TwoBootImages)},
	{0x1600007B, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_ForceFipsCrypto)},
	{0x1000007C, BCD_EMPTY_STRING},
	{0x1500007D, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootErrorUx)},
	{0x1600007E, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_AllowFlightSignatures)},
	{0x1500007F, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_BootMeasurementLogFormat)},
	{0x15000080, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_DisplayRotation)},
	{0x15000081, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_LogControl)},
	{0x16000082, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_NoFirmwareSync)},
	{0x10000083, BCD_EMPTY_STRING},
	{0x11000084, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_WindowsSystemDevice)},
	{0x10000085, BCD_EMPTY_STRING},
	{0x10000086, BCD_EMPTY_STRING},
	{0x16000087, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_NumLockOn)},
	{0x12000088, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_AdditionalCiPolicy)},
	//{0x15000088, REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_LinearAddress57Policy)},
	// Edge case
};

static const bcd_id_and_friendly gaIdToFriendlyApplicationAny[] = {
	{0x26000202, REGISTRY_STRING_INIT_BUFFER(aFriendly_FfuLoader_OneShotSkipFfuUpdate)},
	{0x26000203, REGISTRY_STRING_INIT_BUFFER(aFriendly_FfuLoader_ForceFfu)},
	{0x25000510, REGISTRY_STRING_INIT_BUFFER(aFriendly_Charging_BootThreshold)},
	{0x26000512, REGISTRY_STRING_INIT_BUFFER(aFriendly_Charging_OffModeCharging)},
	{0x25000AAA, REGISTRY_STRING_INIT_BUFFER(aFriendly_Global_Bootflow)},
};

static const bcd_id_and_friendly gaIdToFriendlyTemplate[] = {
	{0x40000001, BCD_EMPTY_STRING},
	{0x40000002, BCD_EMPTY_STRING},
	{0x40000003, BCD_EMPTY_STRING},
	{0x40000004, BCD_EMPTY_STRING},
	{0x40000005, BCD_EMPTY_STRING},
	{0x47000006, REGISTRY_STRING_INIT_BUFFER(aFriendly_Setup_ElementsToMigrateList)},
	/*
	{0x40000007, BCD_EMPTY_STRING},
	{0x40000008, BCD_EMPTY_STRING},
	{0x40000009, BCD_EMPTY_STRING},
	{0x4000000A, BCD_EMPTY_STRING},
	{0x4000000B, BCD_EMPTY_STRING},
	{0x4000000C, BCD_EMPTY_STRING},
	{0x4000000D, BCD_EMPTY_STRING},
	{0x4000000E, BCD_EMPTY_STRING},
	{0x4000000F, BCD_EMPTY_STRING},
	{0x40000010, BCD_EMPTY_STRING},
	*/
};

static const bcd_id_and_friendly gaIdToFriendlyBootMgr[] = {
	{0x24000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_DisplayOrder)},
	{0x24000002, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_BootSequence)},
	{0x23000003, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_DefaultObject)},
	{0x25000004, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_Timeout)},
	{0x26000005, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_AttemptResume)},
	{0x23000006, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_ResumeObject)},
	{0x24000007, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_StartupSequence)},
	{0x20000008, BCD_EMPTY_STRING},
	{0x20000009, BCD_EMPTY_STRING},
	{0x2000000A, BCD_EMPTY_STRING},
	{0x2000000B, BCD_EMPTY_STRING},
	{0x2000000C, BCD_EMPTY_STRING},
	{0x2000000D, BCD_EMPTY_STRING},
	{0x2000000E, BCD_EMPTY_STRING},
	{0x2000000F, BCD_EMPTY_STRING},
	{0x24000010, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_ToolsDisplayOrder)},
	{0x20000011, BCD_EMPTY_STRING},
	{0x20000012, BCD_EMPTY_STRING},
	{0x20000013, BCD_EMPTY_STRING},
	{0x20000014, BCD_EMPTY_STRING},
	{0x20000015, BCD_EMPTY_STRING},
	{0x20000016, BCD_EMPTY_STRING},
	{0x20000017, BCD_EMPTY_STRING},
	{0x20000018, BCD_EMPTY_STRING},
	{0x20000019, BCD_EMPTY_STRING},
	{0x2000001A, BCD_EMPTY_STRING},
	{0x2000001B, BCD_EMPTY_STRING},
	{0x2000001C, BCD_EMPTY_STRING},
	{0x2000001D, BCD_EMPTY_STRING},
	{0x2000001E, BCD_EMPTY_STRING},
	{0x2000001F, BCD_EMPTY_STRING},
	{0x26000020, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_DisplayBootMenu)},
	{0x26000021, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_NoErrorDisplay)},
	{0x21000022, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_BcdDevice)},
	{0x22000023, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_BcdFilePath)},
	{0x20000024, BCD_EMPTY_STRING},
	{0x26000025, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_HiberRoot)},
	{0x20000026, BCD_EMPTY_STRING},
	{0x20000027, BCD_EMPTY_STRING},
	{0x26000028, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_ProcessCustomActionsFirst)},
	{0x20000029, BCD_EMPTY_STRING},
	{0x2000002A, BCD_EMPTY_STRING},
	{0x2000002B, BCD_EMPTY_STRING},
	{0x2000002C, BCD_EMPTY_STRING},
	{0x2000002D, BCD_EMPTY_STRING},
	{0x2000002E, BCD_EMPTY_STRING},
	{0x2000002F, BCD_EMPTY_STRING},
	{0x27000030, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_CustomActionsList)},
	{0x26000031, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_PersistBootSequence)},
	{0x26000032, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_SkipStartupSequence)},
	{0x20000033, BCD_EMPTY_STRING},
	{0x20000034, BCD_EMPTY_STRING},
	{0x20000035, BCD_EMPTY_STRING},
	{0x20000036, BCD_EMPTY_STRING},
	{0x20000037, BCD_EMPTY_STRING},
	{0x20000038, BCD_EMPTY_STRING},
	{0x20000039, BCD_EMPTY_STRING},
	{0x2000003A, BCD_EMPTY_STRING},
	{0x2000003B, BCD_EMPTY_STRING},
	{0x2000003C, BCD_EMPTY_STRING},
	{0x2000003D, BCD_EMPTY_STRING},
	{0x2000003E, BCD_EMPTY_STRING},
	{0x2000003F, BCD_EMPTY_STRING},
	{0x22000040, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_FveRecoveryUrl)},
	{0x22000041, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_FveRecoveryMessage)},
	{0x26000042, REGISTRY_STRING_INIT_BUFFER(aFriendly_BootMgr_FlightBootMgr)},
	/*
	{0x20000043, BCD_EMPTY_STRING},
	{0x20000044, BCD_EMPTY_STRING},
	{0x20000045, BCD_EMPTY_STRING},
	{0x20000046, BCD_EMPTY_STRING},
	{0x20000047, BCD_EMPTY_STRING},
	{0x20000048, BCD_EMPTY_STRING},
	{0x20000049, BCD_EMPTY_STRING},
	{0x2000004A, BCD_EMPTY_STRING},
	{0x2000004B, BCD_EMPTY_STRING},
	{0x2000004C, BCD_EMPTY_STRING},
	{0x2000004D, BCD_EMPTY_STRING},
	{0x2000004E, BCD_EMPTY_STRING},
	{0x2000004F, BCD_EMPTY_STRING},
	{0x20000050, BCD_EMPTY_STRING},
	{0x20000051, BCD_EMPTY_STRING},
	*/
};

static const bcd_id_and_friendly gaIdToFriendlyOsLoader[] = {
	{0x21000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_OsDevice)},
	{0x22000002, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_SystemRoot)},
	{0x23000003, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_AssociatedResumeObject)},
	{0x26000004, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_StampDisks)},
	{0x20000005, BCD_EMPTY_STRING},
	{0x20000006, BCD_EMPTY_STRING},
	{0x20000007, BCD_EMPTY_STRING},
	{0x20000008, BCD_EMPTY_STRING},
	{0x20000009, BCD_EMPTY_STRING},
	{0x2000000A, BCD_EMPTY_STRING},
	{0x2000000B, BCD_EMPTY_STRING},
	{0x2000000C, BCD_EMPTY_STRING},
	{0x2000000D, BCD_EMPTY_STRING},
	{0x2000000E, BCD_EMPTY_STRING},
	{0x2000000F, BCD_EMPTY_STRING},
	{0x26000010, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DetectKernelAndHal)},
	{0x22000011, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelPath)},
	{0x22000012, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HalPath)},
	{0x22000013, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DbgTransportPath)},
	{0x20000014, BCD_EMPTY_STRING},
	{0x20000015, BCD_EMPTY_STRING},
	{0x20000016, BCD_EMPTY_STRING},
	{0x20000017, BCD_EMPTY_STRING},
	{0x20000018, BCD_EMPTY_STRING},
	{0x20000019, BCD_EMPTY_STRING},
	{0x2000001A, BCD_EMPTY_STRING},
	{0x2000001B, BCD_EMPTY_STRING},
	{0x2000001C, BCD_EMPTY_STRING},
	{0x2000001D, BCD_EMPTY_STRING},
	{0x2000001E, BCD_EMPTY_STRING},
	{0x2000001F, BCD_EMPTY_STRING},
	{0x25000020, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_NxPolicy)},
	{0x25000021, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_PaePolicy)},
	{0x26000022, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_WinPeMode)},
	{0x20000023, BCD_EMPTY_STRING},
	{0x26000024, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DisableCrashAutoReboot)},
	{0x26000025, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UseLastGoodSettings)},
	{0x26000026, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DisableCodeIntegrityChecks)},
	{0x26000027, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_AllowPrereleaseSignatures)},
	{0x20000028, BCD_EMPTY_STRING},
	{0x20000029, BCD_EMPTY_STRING},
	{0x2000002A, BCD_EMPTY_STRING},
	{0x2000002B, BCD_EMPTY_STRING},
	{0x2000002C, BCD_EMPTY_STRING},
	{0x2000002D, BCD_EMPTY_STRING},
	{0x2000002E, BCD_EMPTY_STRING},
	{0x2000002F, BCD_EMPTY_STRING},
	{0x26000030, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_NoLowMemory)},
	{0x25000031, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_RemoveMemory)},
	{0x25000032, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_IncreaseUserVa)},
	{0x25000033, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_PerformaceDataMemory)},
	{0x20000034, BCD_EMPTY_STRING},
	{0x20000035, BCD_EMPTY_STRING},
	{0x20000036, BCD_EMPTY_STRING},
	{0x20000037, BCD_EMPTY_STRING},
	{0x20000038, BCD_EMPTY_STRING},
	{0x20000039, BCD_EMPTY_STRING},
	{0x2000003A, BCD_EMPTY_STRING},
	{0x2000003B, BCD_EMPTY_STRING},
	{0x2000003C, BCD_EMPTY_STRING},
	{0x2000003D, BCD_EMPTY_STRING},
	{0x2000003E, BCD_EMPTY_STRING},
	{0x2000003F, BCD_EMPTY_STRING},
	{0x26000040, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UseVgaDriver)},
	{0x26000041, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DisableBootDisplay)},
	{0x26000042, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DisableVesaBios)},
	{0x26000043, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DisableVgaMode)},
	{0x20000044, BCD_EMPTY_STRING},
	{0x20000045, BCD_EMPTY_STRING},
	{0x20000046, BCD_EMPTY_STRING},
	{0x20000047, BCD_EMPTY_STRING},
	{0x20000048, BCD_EMPTY_STRING},
	{0x20000049, BCD_EMPTY_STRING},
	{0x2000004A, BCD_EMPTY_STRING},
	{0x2000004B, BCD_EMPTY_STRING},
	{0x2000004C, BCD_EMPTY_STRING},
	{0x2000004D, BCD_EMPTY_STRING},
	{0x2000004E, BCD_EMPTY_STRING},
	{0x2000004F, BCD_EMPTY_STRING},
	{0x25000050, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_ClusterModeAddressing)},
	{0x26000051, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UsePhysicalDestination)},
	{0x25000052, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_RestrictApicCluster)},
	{0x22000053, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_OsLoaderTypeEVStore)},
	{0x26000054, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UseLegacyApicMode)},
	{0x25000055, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_X2ApicPolicy)},
	{0x20000056, BCD_EMPTY_STRING},
	{0x20000057, BCD_EMPTY_STRING},
	{0x20000058, BCD_EMPTY_STRING},
	{0x20000059, BCD_EMPTY_STRING},
	{0x2000005A, BCD_EMPTY_STRING},
	{0x2000005B, BCD_EMPTY_STRING},
	{0x2000005C, BCD_EMPTY_STRING},
	{0x2000005D, BCD_EMPTY_STRING},
	{0x2000005E, BCD_EMPTY_STRING},
	{0x2000005F, BCD_EMPTY_STRING},
	{0x26000060, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UseBootProcessorOnly)},
	{0x25000061, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_NumberOfProcessors)},
	{0x26000062, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_ForceMaximumProcessors)},
	{0x25000063, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_ProcessorConfigurationFlags)},
	{0x26000064, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_MaximizeGroupsCreated)},
	{0x26000065, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_ForceGroupAwareness)},
	{0x25000066, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_GroupSize)},
	{0x20000067, BCD_EMPTY_STRING},
	{0x20000068, BCD_EMPTY_STRING},
	{0x20000069, BCD_EMPTY_STRING},
	{0x2000006A, BCD_EMPTY_STRING},
	{0x2000006B, BCD_EMPTY_STRING},
	{0x2000006C, BCD_EMPTY_STRING},
	{0x2000006D, BCD_EMPTY_STRING},
	{0x2000006E, BCD_EMPTY_STRING},
	{0x2000006F, BCD_EMPTY_STRING},
	{0x26000070, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UseFirmwarePciSettings)},
	{0x25000071, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_MsiPolicy)},
	{0x25000072, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_PciExpressPolicy)},
	{0x20000073, BCD_EMPTY_STRING},
	{0x20000074, BCD_EMPTY_STRING},
	{0x20000075, BCD_EMPTY_STRING},
	{0x20000076, BCD_EMPTY_STRING},
	{0x20000077, BCD_EMPTY_STRING},
	{0x20000078, BCD_EMPTY_STRING},
	{0x20000079, BCD_EMPTY_STRING},
	{0x2000007A, BCD_EMPTY_STRING},
	{0x2000007B, BCD_EMPTY_STRING},
	{0x2000007C, BCD_EMPTY_STRING},
	{0x2000007D, BCD_EMPTY_STRING},
	{0x2000007E, BCD_EMPTY_STRING},
	{0x2000007F, BCD_EMPTY_STRING},
	{0x25000080, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_SafeBoot)},
	{0x26000081, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_SafeBootAlternateShell)},
	{0x20000082, BCD_EMPTY_STRING},
	{0x20000083, BCD_EMPTY_STRING},
	{0x20000084, BCD_EMPTY_STRING},
	{0x20000085, BCD_EMPTY_STRING},
	{0x20000086, BCD_EMPTY_STRING},
	{0x20000087, BCD_EMPTY_STRING},
	{0x20000088, BCD_EMPTY_STRING},
	{0x20000089, BCD_EMPTY_STRING},
	{0x2000008A, BCD_EMPTY_STRING},
	{0x2000008B, BCD_EMPTY_STRING},
	{0x2000008C, BCD_EMPTY_STRING},
	{0x2000008D, BCD_EMPTY_STRING},
	{0x2000008E, BCD_EMPTY_STRING},
	{0x2000008F, BCD_EMPTY_STRING},
	{0x26000090, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_BootLogInitialization)},
	{0x26000091, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_VerboseObjectLoadMode)},
	{0x20000092, BCD_EMPTY_STRING},
	{0x20000093, BCD_EMPTY_STRING},
	{0x20000094, BCD_EMPTY_STRING},
	{0x20000095, BCD_EMPTY_STRING},
	{0x20000096, BCD_EMPTY_STRING},
	{0x20000097, BCD_EMPTY_STRING},
	{0x20000098, BCD_EMPTY_STRING},
	{0x20000099, BCD_EMPTY_STRING},
	{0x2000009A, BCD_EMPTY_STRING},
	{0x2000009B, BCD_EMPTY_STRING},
	{0x2000009C, BCD_EMPTY_STRING},
	{0x2000009D, BCD_EMPTY_STRING},
	{0x2000009E, BCD_EMPTY_STRING},
	{0x2000009F, BCD_EMPTY_STRING},
	{0x260000A0, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerEnabled)},
	{0x260000A1, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DebuggerHalBreakpoint)},
	{0x260000A2, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UsePlatformClock)},
	{0x260000A3, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_ForceLegacyPlatform)},
	{0x260000A4, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_UsePlatformTick)},
	{0x260000A5, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DisableDynamicTick)},
	{0x250000A6, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_TscSyncPolicy)},
	{0x200000A7, BCD_EMPTY_STRING},
	{0x200000A8, BCD_EMPTY_STRING},
	{0x200000A9, BCD_EMPTY_STRING},
	{0x200000AA, BCD_EMPTY_STRING},
	{0x200000AB, BCD_EMPTY_STRING},
	{0x200000AC, BCD_EMPTY_STRING},
	{0x200000AD, BCD_EMPTY_STRING},
	{0x200000AE, BCD_EMPTY_STRING},
	{0x200000AF, BCD_EMPTY_STRING},
	{0x260000B0, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_EmsEnabled)},
	{0x200000B1, BCD_EMPTY_STRING},
	{0x200000B2, BCD_EMPTY_STRING},
	{0x200000B3, BCD_EMPTY_STRING},
	{0x200000B4, BCD_EMPTY_STRING},
	{0x200000B5, BCD_EMPTY_STRING},
	{0x200000B6, BCD_EMPTY_STRING},
	{0x200000B7, BCD_EMPTY_STRING},
	{0x200000B8, BCD_EMPTY_STRING},
	{0x200000B9, BCD_EMPTY_STRING},
	{0x200000BA, BCD_EMPTY_STRING},
	{0x200000BB, BCD_EMPTY_STRING},
	{0x200000BC, BCD_EMPTY_STRING},
	{0x200000BD, BCD_EMPTY_STRING},
	{0x200000BE, BCD_EMPTY_STRING},
	{0x200000BF, BCD_EMPTY_STRING},
	{0x200000C0, BCD_EMPTY_STRING},
	{0x250000C1, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DriverLoadFailurePolicy)},
	{0x250000C2, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_BootMenuPolicy)},
	{0x260000C3, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_AdvancedOptionsOneTime)},
	{0x260000C4, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_EditOptionsOneTime)},
	{0x200000C5, BCD_EMPTY_STRING},
	{0x200000C6, BCD_EMPTY_STRING},
	{0x200000C7, BCD_EMPTY_STRING},
	{0x200000C8, BCD_EMPTY_STRING},
	{0x200000C9, BCD_EMPTY_STRING},
	{0x200000CA, BCD_EMPTY_STRING},
	{0x200000CB, BCD_EMPTY_STRING},
	{0x200000CC, BCD_EMPTY_STRING},
	{0x200000CD, BCD_EMPTY_STRING},
	{0x200000CE, BCD_EMPTY_STRING},
	{0x200000CF, BCD_EMPTY_STRING},
	{0x200000D0, BCD_EMPTY_STRING},
	{0x200000D1, BCD_EMPTY_STRING},
	{0x200000D2, BCD_EMPTY_STRING},
	{0x200000D3, BCD_EMPTY_STRING},
	{0x200000D4, BCD_EMPTY_STRING},
	{0x200000D5, BCD_EMPTY_STRING},
	{0x200000D6, BCD_EMPTY_STRING},
	{0x200000D7, BCD_EMPTY_STRING},
	{0x200000D8, BCD_EMPTY_STRING},
	{0x200000D9, BCD_EMPTY_STRING},
	{0x200000DA, BCD_EMPTY_STRING},
	{0x200000DB, BCD_EMPTY_STRING},
	{0x200000DC, BCD_EMPTY_STRING},
	{0x200000DD, BCD_EMPTY_STRING},
	{0x200000DE, BCD_EMPTY_STRING},
	{0x200000DF, BCD_EMPTY_STRING},
	{0x250000E0, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_BootStatusPolicy)},
	{0x260000E1, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DisableElamDrivers)},
	{0x200000E2, BCD_EMPTY_STRING},
	{0x200000E3, BCD_EMPTY_STRING},
	{0x200000E4, BCD_EMPTY_STRING},
	{0x200000E5, BCD_EMPTY_STRING},
	{0x200000E6, BCD_EMPTY_STRING},
	{0x200000E7, BCD_EMPTY_STRING},
	{0x200000E8, BCD_EMPTY_STRING},
	{0x200000E9, BCD_EMPTY_STRING},
	{0x200000EA, BCD_EMPTY_STRING},
	{0x200000EB, BCD_EMPTY_STRING},
	{0x200000EC, BCD_EMPTY_STRING},
	{0x200000ED, BCD_EMPTY_STRING},
	{0x200000EE, BCD_EMPTY_STRING},
	{0x200000EF, BCD_EMPTY_STRING},
	{0x250000F0, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorLaunchType)},
	{0x220000F1, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorPath)},
	{0x260000F2, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerEnabled)},
	{0x250000F3, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerType)},
	{0x250000F4, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerPortNumber)},
	{0x250000F5, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerBaudrate)},
	{0x250000F6, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebugger1394Channel)},
	{0x250000F7, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_BootUxPolicy)},
	{0x260000F8, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorSlatDisabled)},
	{0x220000F9, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerBusParams)},
	{0x250000FA, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorNumProc)},
	{0x250000FB, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorRootProcPerNode)},
	{0x260000FC, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorUseLargeVTlb)},
	{0x250000FD, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerNetHostIp)},
	{0x250000FE, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerNetHostPort)},
	{0x250000FF, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerPages)},
	{0x25000100, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_TpmBootEntropyPolicy)},
	{0x20000101, BCD_EMPTY_STRING},
	{0x20000102, BCD_EMPTY_STRING},
	{0x20000103, BCD_EMPTY_STRING},
	{0x20000104, BCD_EMPTY_STRING},
	{0x20000105, BCD_EMPTY_STRING},
	{0x20000106, BCD_EMPTY_STRING},
	{0x20000107, BCD_EMPTY_STRING},
	{0x20000108, BCD_EMPTY_STRING},
	{0x20000109, BCD_EMPTY_STRING},
	{0x2000010A, BCD_EMPTY_STRING},
	{0x2000010B, BCD_EMPTY_STRING},
	{0x2000010C, BCD_EMPTY_STRING},
	{0x2000010D, BCD_EMPTY_STRING},
	{0x2000010E, BCD_EMPTY_STRING},
	{0x2000010F, BCD_EMPTY_STRING},
	{0x22000110, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerNetKey)},
	{0x20000111, BCD_EMPTY_STRING},
	{0x20000112, BCD_EMPTY_STRING},
	{0x25000113, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorRootProc)},
	{0x26000114, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerNetDhcp)},
	{0x25000115, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorIommuPolicy)},
	{0x26000116, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorUseVApic)},
	{0x22000117, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorLoadOptions)},
	{0x25000118, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorMsrFilterPolicy)},
	{0x25000119, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorMmioNxPolicy)},
	{0x2500011A, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorSchedulerType)},
	{0x2200011B, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorRootProcNumaNodes)},
	{0x2500011C, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorPerfmon)},
	{0x2500011D, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorRootProcPerCore)},
	{0x2200011E, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorRootProcNumaNodeLps)},
	{0x2000011F, BCD_EMPTY_STRING},
	{0x25000120, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSavePolicy)},
	{0x25000121, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature0)},
	{0x25000122, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature1)},
	{0x25000123, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature2)},
	{0x25000124, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature3)},
	{0x25000125, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature4)},
	{0x25000126, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature5)},
	{0x25000127, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature6)},
	{0x25000128, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveAddFeature7)},
	{0x25000129, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveRemoveFeature)},
	{0x2500012A, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveProcessorsMask)},
	{0x2500012B, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_XSaveDisable)},
	{0x2500012C, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerType)},
	{0x2200012D, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_kernelDebuggerBusParameters)},
	{0x2500012E, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_kernelDebuggerPortAddress)},
	{0x2500012F, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerPortNumber)},
	{0x25000130, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_FveClaimedDeviceLockCounter)},
	{0x25000131, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebugger1394Channel)},
	{0x22000132, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerUsbTargetname)},
	{0x25000133, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerNetHostIp)},
	{0x25000134, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerNetHostPort)},
	{0x26000135, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerNetDhcp)},
	{0x22000136, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerNetKey)},
	{0x22000137, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_IMCHiveName)},
	{0x21000138, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_IMCDevice)},
	{0x25000139, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerBaudrate)},
	{0x2000013A, BCD_EMPTY_STRING},
	{0x2000013B, BCD_EMPTY_STRING},
	{0x2000013C, BCD_EMPTY_STRING},
	{0x2000013D, BCD_EMPTY_STRING},
	{0x2000013E, BCD_EMPTY_STRING},
	{0x2000013F, BCD_EMPTY_STRING},
	{0x22000140, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_ManufacturingMode)},
	{0x26000141, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_EventLoggingEnabled)},
	{0x25000142, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_VsmLaunchType)},
	{0x20000143, BCD_EMPTY_STRING},
	{0x25000144, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorEnforcedCodeIntegrity)},
	{0x26000145, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_DtraceEnabled)},
	{0x20000146, BCD_EMPTY_STRING},
	{0x20000147, BCD_EMPTY_STRING},
	{0x20000148, BCD_EMPTY_STRING},
	{0x20000149, BCD_EMPTY_STRING},
	{0x2000014A, BCD_EMPTY_STRING},
	{0x2000014B, BCD_EMPTY_STRING},
	{0x2000014C, BCD_EMPTY_STRING},
	{0x2000014D, BCD_EMPTY_STRING},
	{0x2000014E, BCD_EMPTY_STRING},
	{0x2000014F, BCD_EMPTY_STRING},
	{0x21000150, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_SystemDataDevice)},
	{0x21000151, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_OsArcDevice)},
	{0x20000152, BCD_EMPTY_STRING},
	{0x21000153, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_OsDataDevice)},
	{0x21000154, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_BspDevice)},
	{0x21000155, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_BspFilepath)},
	{0x22000156, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_KernelDebuggerNetHostIpv6)},
	{0x20000157, BCD_EMPTY_STRING},
	{0x20000158, BCD_EMPTY_STRING},
	{0x20000159, BCD_EMPTY_STRING},
	{0x2000015A, BCD_EMPTY_STRING},
	{0x2000015B, BCD_EMPTY_STRING},
	{0x2000015C, BCD_EMPTY_STRING},
	{0x2000015D, BCD_EMPTY_STRING},
	{0x2000015E, BCD_EMPTY_STRING},
	{0x2000015F, BCD_EMPTY_STRING},
	{0x20000160, BCD_EMPTY_STRING},
	{0x22000161, REGISTRY_STRING_INIT_BUFFER(aFriendly_OsLoader_HypervisorDebuggerNetHostIpv6)},
};

static const bcd_id_and_friendly gaIdToFriendlyResume[] = {
	{0x21000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_HiberFileDevice)},
	{0x22000002, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_HiberFilePath)},
	{0x26000003, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_UseCustomSettings)},
	{0x26000004, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_x86PaeMode)},
	{0x21000005, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_AssociatedOsDevice)},
	{0x26000006, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_DebugOptionEnabled)},
	{0x25000007, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_BootUxPolicy)},
	{0x25000008, REGISTRY_STRING_INIT_BUFFER(aFriendly_Resume_BootMenuPolicy)},
	/*
	{0x20000009, BCD_EMPTY_STRING},
	{0x2000000A, BCD_EMPTY_STRING},
	{0x2000000B, BCD_EMPTY_STRING},
	{0x2000000C, BCD_EMPTY_STRING},
	{0x2000000D, BCD_EMPTY_STRING},
	{0x2000000E, BCD_EMPTY_STRING},
	{0x2000000F, BCD_EMPTY_STRING},
	{0x20000010, BCD_EMPTY_STRING},
	{0x20000011, BCD_EMPTY_STRING},
	{0x20000012, BCD_EMPTY_STRING},
	{0x20000013, BCD_EMPTY_STRING},
	{0x20000014, BCD_EMPTY_STRING},
	{0x20000015, BCD_EMPTY_STRING},
	{0x20000016, BCD_EMPTY_STRING},
	{0x20000017, BCD_EMPTY_STRING},
	{0x20000018, BCD_EMPTY_STRING},
	{0x20000019, BCD_EMPTY_STRING},
	{0x2000001A, BCD_EMPTY_STRING},
	{0x2000001B, BCD_EMPTY_STRING},
	{0x2000001C, BCD_EMPTY_STRING},
	{0x2000001D, BCD_EMPTY_STRING},
	{0x2000001E, BCD_EMPTY_STRING},
	{0x2000001F, BCD_EMPTY_STRING},
	{0x20000020, BCD_EMPTY_STRING},
	{0x20000021, BCD_EMPTY_STRING},
	{0x20000022, BCD_EMPTY_STRING},
	{0x20000023, BCD_EMPTY_STRING},
	{0x20000024, BCD_EMPTY_STRING},
	{0x20000025, BCD_EMPTY_STRING},
	{0x20000026, BCD_EMPTY_STRING},
	*/
};

static const bcd_id_and_friendly gaIdToFriendlyMemDiag[] = {
	{0x25000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_PassCount)},
	{0x25000002, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_TestMix)},
	{0x25000003, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_FailureCount)},
	{0x26000003, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_CacheEnabled)},
	{0x25000004, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_TestToFail)},
	{0x26000004, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_FailuresEnabled)},
	{0x26000005, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_CacheEnable)},
	{0x25000005, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_StrideFailureCount)},
	{0x25000006, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_InvcFailureCount)},
	{0x25000007, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_MatsFailureCount)},
	{0x25000008, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_RandFailureCount)},
	{0x25000009, REGISTRY_STRING_INIT_BUFFER(aFriendly_MemDiag_ChckrFailureCount)},
};

static const bcd_id_and_friendly gaIdToFriendlyNtLdr[] = {
	{0x22000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_LegacyLdr_BpbString)},
};

static const bcd_id_and_friendly gaIdToFriendlyStartup[] = {
	{0x26000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_Startup_PxeSoftReboot)},
	{0x22000002, REGISTRY_STRING_INIT_BUFFER(aFriendly_Startup_PxeApplicationName)},
};

#define BCD_MOBILE_STARTUP_ID_START 0x145
static const bcd_id_and_friendly gaIdToFriendlyMobileStartup[] = {
	{0x26000145, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableBootDebugPolicy)},
	{0x26000146, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableBootOrderClean)},
	{0x26000147, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableDeviceId)},
	{0x26000148, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableFfuLoader)},
	{0x26000149, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableIuLoader)},
	{0x2600014A, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableMassStorage)},
	{0x2600014B, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableRpmbProvisioning)},
	{0x2600014C, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableSecureBootPolicy)},
	{0x2600014D, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableStartCharge)},
	{0x2600014E, REGISTRY_STRING_INIT_BUFFER(aFriendly_MobileStartup_EnableResetTpm)},
};

static const bcd_id_and_friendly gaIdToFriendlyDevice[] = {
	{0x35000001, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskImageOffset)},
	{0x35000002, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_TftpClientPort)},
	{0x31000003, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_SdiDevice)},
	{0x32000004, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_SdiPath)},
	{0x35000005, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskImageLength)},
	{0x36000006, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskExportAsCd)},
	{0x35000007, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskTftpBlockSize)},
	{0x35000008, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskTftpWindowSize)},
	{0x36000009, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskMulticastEnabled)},
	{0x3600000A, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskMulticastTftpFallback)},
	{0x3600000B, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_RamdiskTftpVarWindow)},
	{0x3600000C, REGISTRY_STRING_INIT_BUFFER(aFriendly_Device_VhdRamdiskBoot)},
	{0x3000000D, BCD_EMPTY_STRING},
};


static registry_string16 GetElementFriendlyNameLibrary(bcd_object_type ObjectType, bcd_element_id ElementId) {
	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyLibrary))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyLibrary[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	if (ElementId == 0x15000088) {
		return (registry_string16)REGISTRY_STRING_INIT_BUFFER(aFriendly_Library_LinearAddress57Policy);
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameApplicationAny(bcd_object_type ObjectType, bcd_element_id ElementId) {
	for (size_t i = 0; i < BCD_ARRAY_LENGTH(gaIdToFriendlyApplicationAny); ++i) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyApplicationAny[i];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameTemplate(bcd_object_type ObjectType, bcd_element_id ElementId) {
	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyTemplate))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyTemplate[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameBootMgr(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if (
		(ObjectType & 0xF00FFFFF) != 0x10000001 &&
		(ObjectType & 0xF0FFFFFF) != 0x20200001 &&
		(ObjectType & 0xF00FFFFF) != 0x10000002 &&
		(ObjectType & 0xF0FFFFFF) != 0x20200002
	) {
		return (registry_string16)BCD_EMPTY_STRING;
	}

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyBootMgr))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyBootMgr[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameOsLoader(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if ((ObjectType & 0xF00FFFFF) != 0x10000003 && (ObjectType & 0xF0FFFFFF) != 0x20200003)
		return (registry_string16)BCD_EMPTY_STRING;

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyOsLoader))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyOsLoader[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameResume(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if ((ObjectType & 0xF00FFFFF) != 0x10000004 && (ObjectType & 0xF0FFFFFF) != 0x20200004)
		return (registry_string16)BCD_EMPTY_STRING;

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyResume))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyResume[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameMemDiag(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if ((ObjectType & 0xF00FFFFF) != 0x10000005 && (ObjectType & 0xF0FFFFFF) != 0x20200005)
		return (registry_string16)BCD_EMPTY_STRING;

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyMemDiag))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyMemDiag[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameNtLdr(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if (
		(ObjectType & 0xF00FFFFF) != 0x10000006 &&
		(ObjectType & 0xF0FFFFFF) != 0x20200006 &&
		(ObjectType & 0xF00FFFFF) != 0x10000007 &&
		(ObjectType & 0xF0FFFFFF) != 0x20200007
	) {
		return (registry_string16)BCD_EMPTY_STRING;
	}

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyNtLdr))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyNtLdr[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameStartup(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if ((ObjectType & 0xF00FFFFF) != 0x10000009 && (ObjectType & 0xF0FFFFFF) != 0x20200009)
		return (registry_string16)BCD_EMPTY_STRING;

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyStartup))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyStartup[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameMobileStartup(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if ((ObjectType & 0xF00FFFFF) != 0x1000000A && (ObjectType & 0xF0FFFFFF) != 0x2020000A)
		return (registry_string16)BCD_EMPTY_STRING;

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (
		BCD_IN_RANGE(
			ElementNumber,
			BCD_MOBILE_STARTUP_ID_START,
			BCD_MOBILE_STARTUP_ID_START + BCD_ARRAY_LENGTH(gaIdToFriendlyMobileStartup) - 1
		)
	) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyMobileStartup[ElementNumber - BCD_MOBILE_STARTUP_ID_START];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

static registry_string16 GetElementFriendlyNameDevice(bcd_object_type ObjectType, bcd_element_id ElementId) {
	if ((ObjectType & 0xF0F00000) != 0x20300000 && (ObjectType & 0xF0000000) != 0x30000000)
		return (registry_string16)BCD_EMPTY_STRING;

	bcd_element_id ElementNumber = ElementId & 0xFFFF;
	if (BCD_IN_RANGE(ElementNumber, 1, BCD_ARRAY_LENGTH(gaIdToFriendlyDevice))) {
		bcd_id_and_friendly IdAndFriendly = gaIdToFriendlyDevice[ElementNumber - 1];
		if (IdAndFriendly.Id == ElementId)
			return IdAndFriendly.FriendlyName;
	}
	return (registry_string16)BCD_EMPTY_STRING;
}

bcd_status Bcd_QueryElementFriendlyName(
	h_bcd_element hElement,
	registry_string16* pFriendlyName
) {
	bcd_element* pElement = hElement;
	bcd_object_type ObjectType;
	bcd_status Status;
	Status = Bcd_QueryObjectType(pElement->hObject, &ObjectType);
	if (Status)
		return STATUS_UNSUCCESSFUL;

	bcd_element_id ElementId;
	Status = Bcd_QueryElementId(hElement, &ElementId);
	if (Status)
		return STATUS_UNSUCCESSFUL;

	registry_string16 FriendlyName;
	FriendlyName = GetElementFriendlyNameDevice(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameMobileStartup(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameStartup(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameNtLdr(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameMemDiag(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameResume(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameOsLoader(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameBootMgr(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameTemplate(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameApplicationAny(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;
	FriendlyName = GetElementFriendlyNameLibrary(ObjectType, ElementId);
	if (FriendlyName.aBuffer != NULL)
		goto Done;

	Done:
	*pFriendlyName = FriendlyName;

	return STATUS_SUCCESS;
}

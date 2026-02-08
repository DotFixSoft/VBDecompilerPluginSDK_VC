/*
 *  VB Decompiler Plugin SDK
 *  Copyright (c) 2001-2026 DotFix Software. All rights reserved.
 *
 *  Website: https://www.vb-decompiler.org
 *  Support: admin@vb-decompiler.org
 *
 *  License:
 *      Permission is hereby granted to use, modify, and distribute this file 
 *      for the purpose of creating plugins for VB Decompiler.
 */

#ifndef _VBDECPDK_H_
#define _VBDECPDK_H_

#include <windows.h>
#include <string>

// --- Exports Macro ---
#ifdef VBDEC_EXPORTS
  #define VBDEC_API __declspec(dllexport)
#else
  #define VBDEC_API __declspec(dllimport)
#endif

// --- Constants (vlType) ---
enum VBD_vlType {
    VBD_GetVBProject = 1,
    VBD_SetVBProject = 2,
    VBD_GetFileName = 3,
    VBD_IsNativeCompilation = 4,
    VBD_ClearAllBuffers = 5,
    VBD_GetCompiler = 6,
    VBD_IsPacked = 7,
    VBD_SetStackCheckBoxValue = 8,
    VBD_SetAnalyzerCheckBoxValue = 9,
    VBD_GetVBFormName = 10,
    VBD_SetVBFormName = 11,
    VBD_GetVBForm = 12,
    VBD_SetVBForm = 13,
    VBD_GetVBFormCount = 14,
    VBD_GetSubMain = 20,
    VBD_SetSubMain = 21,
    VBD_GetModuleName = 30,
    VBD_SetModuleName = 31,
    VBD_GetModule = 32,
    VBD_SetModule = 33,
    VBD_GetModuleStringReferences = 34,
    VBD_SetModuleStringReferences = 35,
    VBD_SetModuleCount = 36,
    VBD_GetModuleFunctionName = 40,
    VBD_SetModuleFunctionName = 41,
    VBD_GetModuleFunctionAddress = 42,
    VBD_SetModuleFunctionAddress = 43,
    VBD_GetModuleFunction = 44,
    VBD_SetModuleFunction = 45,
    VBD_GetModuleFunctionStrRef = 46,
    VBD_SetModuleFunctionStrRef = 47,
    VBD_GetModuleFunctionCount = 48,
    VBD_GetActiveText = 50,
    VBD_SetActiveText = 51,
    VBD_GetActiveDisasmText = 52,
    VBD_SetActiveDisasmText = 53,
    VBD_SetActiveTextLine = 54,
    VBD_GetActiveModuleCoordinats = 55,
    VBD_GetVBDecompilerPath = 56,
    VBD_GetModuleFunctionCode = 57,
    VBD_SetStatusBarText = 58,
    VBD_GetFrxIconCount = 60,
    VBD_GetFrxIconOffset = 61,
    VBD_GetFrxIconSize = 62,
    VBD_GetModuleFunctionDisasm = 70,
    VBD_SetModuleFunctionDisasm = 71,
    VBD_UpdateAll = 100
};

// --- C Linkage Block (Only for DLL Exports and plain C types) ---
#ifdef __cplusplus
extern "C" {
#endif

    // Engine Definition
    typedef void* (__stdcall *TVBDPluginEngine)(int vlType, int vlNumber, int vlFnNumber, void* vlNewValue);
    extern TVBDPluginEngine g_PluginEngine;

    // Init Helper (uses simple types, so can be here)
    BOOL VBDecInit(void* pVBDecGate);

#ifdef __cplusplus
}
#endif

// --- C++ Helpers (Outside extern "C" because they use std::string) ---
#ifdef __cplusplus
    std::string GetValue(int vlType, int vlNumber = 0, int vlFnNumber = 0);
    void SetValue(int vlType, std::string vlNewValue, int vlNumber = 0, int vlFnNumber = 0);
#endif

#endif // _VBDECPDK_H_

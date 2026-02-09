/*
 *  VB Decompiler Plugin SDK
 *  Copyright (c) 2001-2026 Sergey Chubchenko (DotFix Software). All rights reserved.
 *
 *  Website: https://www.vb-decompiler.org
 *  Support: admin@vb-decompiler.org
 *
 *  License:
 *      Permission is hereby granted to use, modify, and distribute this file 
 *      for the purpose of creating plugins for VB Decompiler.
 */
 
#include "VBDecPDK.h"

TVBDPluginEngine g_PluginEngine = NULL;

BOOL VBDecInit(void* pVBDecGate) {
    if (!pVBDecGate || IsBadCodePtr((FARPROC)pVBDecGate)) return FALSE;
    g_PluginEngine = (TVBDPluginEngine)pVBDecGate;
    return TRUE;
}

std::string GetValue(int vlType, int vlNumber, int vlFnNumber) {
    if (!g_PluginEngine) return "";
    void* pResult = g_PluginEngine(vlType, vlNumber, vlFnNumber, NULL);
    if (!pResult) return "";
    
    wchar_t* pWStr = (wchar_t*)pResult;
    int len = WideCharToMultiByte(CP_ACP, 0, pWStr, -1, NULL, 0, NULL, NULL);
    if (len <= 0) return "";
    
    std::string res(len - 1, '\0');
    WideCharToMultiByte(CP_ACP, 0, pWStr, -1, &res[0], len, NULL, NULL);
    return res;
}

void SetValue(int vlType, std::string vlNewValue, int vlNumber, int vlFnNumber) {
    if (!g_PluginEngine) return;
    g_PluginEngine(vlType, vlNumber, vlFnNumber, (void*)vlNewValue.c_str());
}
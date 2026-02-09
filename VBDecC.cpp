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
 
#include <windows.h>
#include <commctrl.h> // For controls init if needed
#include "VBDecPDK.h"
#include "Resource.h"

// --- Global Variables ---
HINSTANCE hInst;
std::string g_ActiveTextBuffer; // To pass text to the dialog

// --- Plugin Info ---
const char* PLUGIN_NAME = "Test plugin written in Visual C++";
const char* PLUGIN_AUTHOR = "YourName, yourmail@somedomain.com";

// --- Dialog Procedure ---
INT_PTR CALLBACK MainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_INITDIALOG:
        SetDlgItemTextA(hDlg, IDC_EDIT_TEXT, g_ActiveTextBuffer.c_str());
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDC_BTN_CLOSE || LOWORD(wParam) == IDCANCEL) {
            MessageBoxA(hDlg, "The plugin worked correctly", "Visual C++ Plugin", MB_OK | MB_ICONINFORMATION);
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// --- DLL Entry Point ---
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        hInst = hModule;
    }
    return TRUE;
}

// --- Exported Functions ---

extern "C" VBDEC_API void __stdcall VBDecompilerPluginName(HWND h, HWND r, char* Buffer, int Void) {
    if (Buffer) strcpy_s(Buffer, 100, PLUGIN_NAME);
}

extern "C" VBDEC_API void __stdcall VBDecompilerPluginAuthor(HWND h, HWND r, char* Buffer, int Void) {
    if (Buffer) strcpy_s(Buffer, 100, PLUGIN_AUTHOR);
}

extern "C" VBDEC_API void __stdcall VBDecompilerPluginLoad(HWND hVBDec, HWND hRich, void* Buffer, void* Engine) {
    
    // Init SDK
    if (!VBDecInit(Engine)) return;

    // Get contents of VB project file
    std::string strData = GetValue(VBD_GetVBProject);
    
    // Change some data
    strData += "\r\nThis text was added by the plugin";
    
    // Set contents
    SetValue(VBD_SetVBProject, strData);
    
    // Update all changed info
    SetValue(VBD_UpdateAll, "");

    // Get text from active window
    // Important: We store it in a global or pass it, because DialogBox is modal
    g_ActiveTextBuffer = GetValue(VBD_GetActiveText, 0, 0);

    // Load form
    DialogBox(hInst, MAKEINTRESOURCE(IDD_MAINDIALOG), hVBDec, MainDlgProc);
}
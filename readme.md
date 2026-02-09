# VB Decompiler Plugin SDK for Visual C++

This repository contains the official Plugin Development Kit (SDK) for [**VB Decompiler**](https://www.vb-decompiler.org), written in **Visual C++**.

This SDK allows you to create native DLL plugins that interact directly with the VB Decompiler core, enabling you to analyze, modify, or extend the decompiled code and internal structures of the application.

## 🚀 Features

*   **Native Interop:** Full support for the VB Decompiler API using standard calling conventions.
*   **Complete API:** Wrappers for all available host functions (Project manipulation, GUI interaction, Code analysis).
*   **Example Project:** A ready-to-use plugin demonstrating text retrieval and UI integration.
*   **Unicode Support:** Correct handling of string conversions between the host and the plugin.

## 📋 Prerequisites

To build the plugin, you will need:

*   **VB Decompiler:** v12.0 or higher (to test the plugin).
*   **Compiler/IDE:**
    *   Visual Studio 2022 (v143 toolset) or newer.

## 🛠️ How to Build

1.  Clone this repository:
    ```bash
    git clone https://github.com/DotFixSoft/VBDecompilerPluginSDK_VC.git
    ```

2.  Open the project in your IDE:

    *   Open `VBDecPlugin.sln`.

3.  Build the project (Select **Release** configuration and **32-bit/x86** target)

4.  The resulting `.dll` file will be generated in the output directory.

## 📦 Installation

To install your compiled plugin:

1.  Navigate to your VB Decompiler installation folder.
2.  Open the `plugins` directory.
3.  Copy your compiled `.dll` file into this folder.
4.  Restart VB Decompiler. Your plugin will appear in the **Plugins** menu.

## 📖 API Documentation

The SDK provides wrappers for the VB Decompiler Callback Engine. The main communication is handled via the `GetValue` and `SetValue` functions.

**Commands**

For a full list of commands and constants, please refer to the `VBDecPDK.h` file in this repository or the [Official Documentation](https://www.vb-decompiler.org/plugins_sdk.htm).

## 📄 License

This SDK is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Permission is hereby granted to use, modify, and distribute this SDK for the purpose of creating commercial or free plugins for VB Decompiler.

---
Copyright (c) 2001-2026 **Sergey Chubchenko (DotFix Software)**. All rights reserved.
[www.vb-decompiler.org](https://www.vb-decompiler.org)


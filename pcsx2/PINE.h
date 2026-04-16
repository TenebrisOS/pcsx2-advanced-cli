// SPDX-FileCopyrightText: 2002-2026 PCSX2 Dev Team
// SPDX-License-Identifier: GPL-3.0+

/* A reference client implementation for interfacing with PINE is available
 * here: https://code.govanify.com/govanify/pine/ */

#pragma once

// PINE uses a concept of "slot" to be able to communicate with multiple
// emulators at the same time, each slot should be unique to each emulator to
// allow PnP and configurable by the end user so that several runs don't
// conflict with each others
#define PINE_DEFAULT_SLOT 28011

namespace PINEServer
{
	bool IsInitialized();
	int GetSlot();

	bool Initialize(int slot = PINE_DEFAULT_SLOT);
	void Deinitialize();
} // namespace PINEServer
  
// PINE IPC Command opcodes  
enum IPCCommand : unsigned char  
{  
    MsgRead8 = 0, /**< Read 8 bit value to memory. */  
    MsgRead16 = 1, /**< Read 16 bit value to memory. */  
    MsgRead32 = 2, /**< Read 32 bit value to memory. */  
    MsgRead64 = 3, /**< Read 64 bit value to memory. */  
    MsgWrite8 = 4, /**< Write 8 bit value to memory. */  
    MsgWrite16 = 5, /**< Write 16 bit value to memory. */  
    MsgWrite32 = 6, /**< Write 32 bit value to memory. */  
    MsgWrite64 = 7, /**< Write 64 bit value to memory. */  
    MsgVersion = 8, /**< Returns PCSX2 version. */  
    MsgSaveState = 9, /**< Saves a savestate. */  
    MsgLoadState = 0xA, /**< Loads a savestate. */  
    MsgTitle = 0xB, /**< Returns the game title. */  
    MsgID = 0xC, /**< Returns the game ID. */  
    MsgUUID = 0xD, /**< Returns the game UUID. */  
    MsgGameVersion = 0xE, /**< Returns the game verion. */  
    MsgStatus = 0xF, /**< Returns the emulator status. */  
    MsgReset = 0x10, /**< Reset the virtual machine */  
    MsgUnimplemented = 0xFF /**< Unimplemented IPC message. */  
};

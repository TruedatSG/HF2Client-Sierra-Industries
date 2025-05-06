#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_DEPRECATE

#undef UNICODE

#include <windows.h>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <list>
#include <math.h>
#include <process.h>
#include <psapi.h>
#include <shlwapi.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <tlhelp32.h>
#include <valarray>
#include <vector>
#include <winbase.h>
#include <windef.h>
#include <winnt.h>
#include <winuser.h>

#include <Xinput.h>

#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "shlwapi.lib")

#pragma comment(lib, "Xinput.lib")

#define EXPORT __declspec(dllexport)
#define FASTCALL __fastcall
#define FUNCCALL __cdecl
#define IMPORT __declspec(dllimport)
#define NAKED __declspec(naked)
#define STDCALL __stdcall

#define NULL_ENTRY	222

#pragma warning(disable : 4311)
#pragma warning(disable : 4312)

#include "Settings.h"

#include "Aim.h"
#include "Array Ex.h"
#include "Common Math.h"
#include "Configuration.h"
#include "Constants.h"
#include "Copy and Paste.h"
#include "D2 Pointers.h"
#include "D2 Stdio.h"
#include "D2 Structs.h"
#include "D2 Stubs.h"
#include "Dupe.h"
#include "Design.h"
#include "Enchant.h"
#include "Escape.h"
#include "Game Filter.h"
#include "Godmode.h"
#include "Handlers.h"
#include "Helpers.h"
#include "Item.h"
#include "Matrix.h"
#include "Message.h"
#include "Miscellaneous.h"
#include "Offset.h"
#include "Packet Received.h"
#include "Packet Sent.h"
#include "Patch Stubs.h"
#include "Potion.h"
#include "Reveal.h"
#include "Skill.h"
#include "Speed.h"
#include "String Hash.h"
#include "Teleport.h"
#include "Threads.h"
#include "Travel.h"
#include "Unit.h"
#include "Vars.h"
#include "Winamp.h"
#include "Rogue.h"

#include "HF2 CDKey.h"
#include "HF2 Data Tables.h"
#include "HF2 Structs.h"
#include "HF2 Data.h"
#include "HF2 Draw.h"
#include "HF2 ExtLevels.h"
#include "HF2 Handlers.h"
#include "HF2 Helpers.h"
#include "HF2 Info.h"
#include "HF2 KeyItems.h"
#include "HF2 Ladder.h"
#include "HF2 Quest.h"
#include "HF2 Xinput.h"

#include "AI Common.h"
#include "AI Move.h"

BOOL Attach(HINSTANCE DLL);
BOOL Detach();

BOOL CDKeys();

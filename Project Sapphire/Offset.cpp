#include "Hack.h"
#include "Patch.h"

VOID DefineOffsets()
{
	LPDWORD Pointer = (LPDWORD)&D2PTRS_START;

	do *Pointer = GetDllOffset(*Pointer);
		while (++Pointer <= (LPDWORD)&D2PTRS_END);

	for (INT i = 0; i < ArraySize(Patches); i++)
		Patches[i].dwAddr = GetDllOffset(Patches[i].dwAddr);
}

DWORD GetDllOffset(LPSTR DLLName, INT Offset)
{
	HMODULE Mod = GetModuleHandleA(DLLName);

	if (!Mod)
		Mod = LoadLibraryA(DLLName);

	if (!Mod)
		return FALSE;

	if (Offset < 0)
		return (DWORD)GetProcAddress(Mod, (LPCSTR)(-Offset));
	
	return (DWORD)Mod + Offset;
}

DWORD GetDllOffset(INT Number)
{
	static LPSTR DLL[] =
	{
		"D2Client.DLL",
		"D2Common.DLL",
		"D2Gfx.DLL",
		"D2Lang.DLL",
		"D2Win.DLL",
		"D2Net.DLL",
		"D2Game.DLL",
		"D2Launch.DLL",
		"Fog.DLL",
		"BNClient.DLL",
		"Storm.DLL",
		"D2Cmp.DLL",
		"D2Multi.DLL",
		"D2MCPClient.DLL"
	};

	return GetDllOffset(DLL[Number & 0xFF], Number >> 8);
}

VOID InstallPatches(BOOL Type)
{
	for (INT i = 0; i < ArraySize(Patches); i++)
	{
		if (Patches[i].Type == Type)
		{
			Patches[i].bOldCode = new BYTE[Patches[i].dwLen];
			memcpy((LPVOID)Patches[i].bOldCode, (LPVOID)Patches[i].dwAddr, Patches[i].dwLen);
			Patches[i].pFunc(Patches[i].dwAddr, Patches[i].dwFunc, Patches[i].dwLen);
		}
	}
}

VOID RemovePatches(BOOL Type)
{
	for (INT i = 0; i < ArraySize(Patches); i++)
	{
		if (Patches[i].Type == Type)
		{
			WriteBytes((LPVOID)Patches[i].dwAddr, Patches[i].bOldCode, Patches[i].dwLen);
			delete Patches[i].bOldCode;
		}
	}
}

BOOL WriteBytes(LPVOID pAddr, VOID * pData, DWORD dwLen)
{
	DWORD dwOld;

	if(!VirtualProtect(pAddr, dwLen, PAGE_READWRITE, &dwOld))
		return FALSE;

	::memcpy(pAddr, pData, dwLen);
	return VirtualProtect(pAddr, dwLen, dwOld, &dwOld);
}

BOOL WriteBytesEx(LPVOID lpAddr, LPVOID lpBuffer, DWORD dwLen)
{
	DWORD dwOldProtect;
	if (!VirtualProtect(lpAddr, dwLen, PAGE_READWRITE, &dwOldProtect))
		return FALSE;

	memcpy(lpAddr, lpBuffer, dwLen);

	if (!VirtualProtect(lpAddr, dwLen, dwOldProtect, &dwOldProtect))
		return FALSE;

	return TRUE;
}

VOID FillBytes(LPVOID Address, BYTE Fill, DWORD Length)
{
	BYTE * Code = new BYTE[Length];
	::memset(Code, Fill, Length);
	WriteBytes(Address, Code, Length);
	delete Code;
}

VOID InterceptLocalCode(BYTE bInst, DWORD pAddr, DWORD pFunc, DWORD dwLen)
{
	BYTE *bCode = new BYTE[dwLen];
	::memset(bCode, 0x90, dwLen);
	DWORD dwFunc = pFunc - (pAddr + 5);

	bCode[0] = bInst;
	*(DWORD *)&bCode[1] = dwFunc;
	WriteBytes((VOID *)pAddr, bCode, dwLen);
	delete bCode;
}

VOID PatchCall(DWORD dwAddr, DWORD dwFunc, DWORD dwLen)
{
	InterceptLocalCode(INST_CALL, dwAddr, dwFunc, dwLen);
}

VOID PatchFill(DWORD dwAddr, DWORD dwFunc, DWORD dwLen)
{
	FillBytes((LPVOID)dwAddr, (BYTE)dwFunc, dwLen);
}

VOID PatchJmp(DWORD dwAddr, DWORD dwFunc, DWORD dwLen)
{
	InterceptLocalCode(INST_JMP, dwAddr, dwFunc, dwLen);
}

VOID PatchBytes(DWORD dwAddr, DWORD dwValue, DWORD dwLen)
{
	BYTE *bCode = new BYTE[dwLen];
	::memset(bCode, (BYTE)dwValue, dwLen);
	WriteBytes((LPVOID)dwAddr, bCode, dwLen);
	delete bCode;
}

VOID PatchEx(BYTE bInst, DWORD pAddr, DWORD pFunc, DWORD dwLen, char* Type)
{
	BYTE *bCode = new BYTE[dwLen];
	if (bInst)
	{
		::memset(bCode, 0x90, dwLen);
		bCode[0] = bInst;
		if (pFunc)
		{
			if (bInst == 0xE8 || bInst == 0xE9)
			{
				DWORD dwFunc = pFunc - (pAddr + 5);
				*(DWORD*)&bCode[1] = dwFunc;
			}
			else
			if (bInst == 0x68 || bInst == 0x05 || bInst == 0x5B)
			{
				*(LPDWORD)&bCode[1] = pFunc;
			}
			else
			if (bInst == 0x83)
			{
				*(WORD*)&bCode[1] = (WORD)pFunc;
			}
			else
			{
				bCode[1] = (BYTE)pFunc;
			}
		}
	}
	else
	{
		if (dwLen == 6)
		{
			::memset(bCode, 0x00, dwLen);
			*(DWORD*)&bCode[0] = pFunc;
		}
		else if (dwLen == 4)
			*(DWORD*)&bCode[0] = pFunc;
		else if (dwLen == 2)
			*(WORD*)&bCode[0] = (WORD)pFunc;
		else if (dwLen == 1)
			*(BYTE*)&bCode[0] = (BYTE)pFunc;
	}

	if (!WriteBytesEx((void*)pAddr, bCode, dwLen))
	{
		delete[] bCode;
	}
	delete[] bCode;
}

VOID GamePatch(BOOL InGame)
{
	if (InGame)
	{
		if (V_PatchInGame == -1)
		{
			V_Design = new Design;
			V_Reveal = new Reveal;
		}

		if (V_PatchInGame == FALSE)
		{
			RemovePatches(OUTGAME);
			InstallPatches(INGAME);
		}

		if (V_PatchOutGame)
		{
			RemovePatches(OUTGAME);
			InstallPatches(INGAME);
			V_PatchOutGame = FALSE;
		}
	}

	else
	{
		if (V_PatchInGame == -1)
		{
			if (V_Design) delete V_Design;
			if (V_Design) delete V_Reveal;
		}

		if (V_PatchInGame == TRUE)
		{
			if (RemovePEHeader(V_DLL))
			{
				RemovePatches(INGAME);

				delete V_Design;
				delete V_Reveal;

				InstallPatches(OUTGAME);
				V_PatchOutGame = TRUE;

				V_PatchInGame = -1;
			}

			else
				TerminateProcess(GetCurrentProcess(), NULL);
		}

		if (!V_PatchOutGame)
		{
			RemovePatches(INGAME);
			InstallPatches(OUTGAME);
			V_PatchOutGame = TRUE;
		}
	}
}

VOID GamePatchMP()
{
	InstallPatches(MPGAME);
}
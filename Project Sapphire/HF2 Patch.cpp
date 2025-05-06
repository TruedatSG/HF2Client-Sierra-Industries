#include "Hack.h"

#define CALL 0xE8
#define JUMP 0xE9
#define NOP 0x90
#define RET 0xC3
#define XOR 0x33
#define CUSTOM 0

/*
BOOL WriteBytes(LPVOID lpAddr, LPVOID lpBuffer, DWORD dwLen)
{
	DWORD dwOldProtect;
	if (!VirtualProtect(lpAddr, dwLen, PAGE_READWRITE, &dwOldProtect))
		return FALSE;

	memcpy(lpAddr, lpBuffer, dwLen);

	if (!VirtualProtect(lpAddr, dwLen, dwOldProtect, &dwOldProtect))
		return FALSE;

	return TRUE;
}

void Patch(BYTE bInst, DWORD pAddr, DWORD pFunc, DWORD dwLen, char* Type)
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

	if (!WriteBytes((void*)pAddr, bCode, dwLen))
	{
		delete[] bCode;

		return;
	}
	delete[] bCode;

	return;
}

VOID ExtLevelsPatch()
{
	Patch(CALL, GetDllOffset("D2Common.dll", 0x4F330), (DWORD)GetActByLevel, 22, "Replace inline GetActByLevel"); //  Ordinal11007
	Patch(CALL, GetDllOffset("D2Common.dll", 0x4F3C7), (DWORD)GetActByLevel, 26, "Replace inline GetActByLevel"); //  Ordinal11051
	Patch(CALL, GetDllOffset("D2Common.dll", 0x4F160), (DWORD)GetActByRoom2, 22, "Replace inline GetActByLevel"); //  Ordinal10301

	Patch(CALL, GetDllOffset("D2Common.dll", 0x2AD76), (DWORD)GetActByLevelNo_STUB1, 20, "Replace inline GetActByLevel"); //  sub_6FD7AD60
	Patch(CALL, GetDllOffset("D2Common.dll", 0x56F40), (DWORD)GetActByLevelNo_STUB1, 20, "Replace inline GetActByLevel"); //  sub_6FDA6EA0
	Patch(CALL, GetDllOffset("D2Common.dll", 0x510A0), (DWORD)GetActByLevelNo_STUB2, 20, "Replace inline GetActByLevel"); //  sub_6FDA1070

	Patch(JUMP, GetDllOffset("D2Common.dll", -10864), (DWORD)GetActByLevelNo, 5, "Replace original GetActByLevelNo");

	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x6FFFB + 1), 4096, 4, "Automap patch I");
	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x7100B + 1), 4096, 4, "Automap patch I");
	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x71044 + 1), 4096, 4, "Automap patch I");
	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x710D9 + 1), 4096, 4, "Automap patch I");
	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x728EA + 1), 4096, 4, "Automap patch I");

	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x70FD6 + 2), 4256, 4, "Automap patch II - stack fix"); // The original value is 416
	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x728A6 + 2), 4172, 4, "Automap patch II - stack fix"); // The original value is 472

	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x70FF6 + 1), 399, 4, "Automap patch III");
	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x728D9 + 1), 399, 4, "Automap patch III");

	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x7101B + 4), 4096, 4, "Automap patch IV");
	Patch(CUSTOM, GetDllOffset("D2Client.dll", 0x728FE + 4), 4096, 4, "Automap patch IV");
}
*/
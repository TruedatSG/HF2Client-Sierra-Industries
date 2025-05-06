#include "Hack.h"

BYTE __fastcall ExExtendedLevels::GetActByLevel(Level* pLevel)
{
	return ExExtendedLevels::GetActByLevelNo(pLevel->dwLevelNo);
}

BYTE __fastcall ExExtendedLevels::GetActByRoom2(int _1, Room2* pRoom2)
{
	return ExExtendedLevels::GetActByLevelNo(pRoom2->pLevel->dwLevelNo);
}

/*
Modified beacuse the original function uses town lvl to determine act
*/
DWORD __stdcall ExExtendedLevels::GetActByLevelNo(DWORD nLevel)
{
	if (nLevel >= (DataTables)->dwLevelsRecs)
	{
		return 0;
	}
	exLevelsTxt* pLevel = &(DataTables)->pLevelsTxt[nLevel];
	if (pLevel)
	{
		return pLevel->nAct;
	}
	return 0;
}

// nLevel@ecx
__declspec(naked) BYTE __fastcall ExExtendedLevels::GetActByLevelNo_STUB1(DWORD nLevel)
{
	__asm
	{
		// They are changed in my GetActByLevelNo, so need to preserve
		push edx
			push ecx
			push edi

			push ecx
			call ExExtendedLevels::GetActByLevelNo


			pop edi
			pop ecx
			pop edx

			mov[esp + 13h + 4h], al
			ret
	}
}

// nLevel@edx
__declspec(naked) BYTE __fastcall ExExtendedLevels::GetActByLevelNo_STUB2(DWORD nLevel)
{
	__asm
	{

		push edx
			push ecx
			push edi


			push edx
			call ExExtendedLevels::GetActByLevelNo


			pop edi
			pop ecx
			pop edx

			mov[esp + 13h + 4h], al
			ret
	}
}

VOID ExtLevelsPatch()
{
#define CALL 0xE8
#define JUMP 0xE9
#define NOP 0x90
#define RET 0xC3
#define XOR 0x33
#define CUSTOM 0

	PatchEx(CALL, GetDllOffset("D2Common.dll", 0x4F330), (DWORD)ExExtendedLevels::GetActByLevel, 22, "Replace inline GetActByLevel"); //  Ordinal11007
	PatchEx(CALL, GetDllOffset("D2Common.dll", 0x4F3C7), (DWORD)ExExtendedLevels::GetActByLevel, 26, "Replace inline GetActByLevel"); //  Ordinal11051
	PatchEx(CALL, GetDllOffset("D2Common.dll", 0x4F160), (DWORD)ExExtendedLevels::GetActByRoom2, 22, "Replace inline GetActByLevel"); //  Ordinal10301

	PatchEx(CALL, GetDllOffset("D2Common.dll", 0x2AD76), (DWORD)ExExtendedLevels::GetActByLevelNo_STUB1, 20, "Replace inline GetActByLevel"); //  sub_6FD7AD60
	PatchEx(CALL, GetDllOffset("D2Common.dll", 0x56F40), (DWORD)ExExtendedLevels::GetActByLevelNo_STUB1, 20, "Replace inline GetActByLevel"); //  sub_6FDA6EA0
	PatchEx(CALL, GetDllOffset("D2Common.dll", 0x510A0), (DWORD)ExExtendedLevels::GetActByLevelNo_STUB2, 20, "Replace inline GetActByLevel"); //  sub_6FDA1070

	PatchEx(JUMP, GetDllOffset("D2Common.dll", -10864), (DWORD)ExExtendedLevels::GetActByLevelNo, 5, "Replace original GetActByLevelNo");

	// The original value is 400
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x6FFFB + 1), 4096, 4, "Automap patch I");
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x7100B + 1), 4096, 4, "Automap patch I");
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x71044 + 1), 4096, 4, "Automap patch I");
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x710D9 + 1), 4096, 4, "Automap patch I");
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x728EA + 1), 4096, 4, "Automap patch I");

	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x70FD6 + 2), 4256, 4, "Automap patch II - stack fix"); // The original value is 416
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x728A6 + 2), 4172, 4, "Automap patch II - stack fix"); // The original value is 472

	// The original value is 99
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x70FF6 + 1), 399, 4, "Automap patch III");
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x728D9 + 1), 399, 4, "Automap patch III");

	// The original value is 400
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x7101B + 4), 4096, 4, "Automap patch IV");
	PatchEx(CUSTOM, GetDllOffset("D2Client.dll", 0x728FE + 4), 4096, 4, "Automap patch IV");
}
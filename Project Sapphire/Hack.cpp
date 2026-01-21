#define PTRS
#define VARS
#define CDKEYS

#include "Hack.h"

//
// RUBY ENTRY POINT
//
BOOL WINAPI DllMain(HINSTANCE DLL, DWORD Reason, LPVOID Reserved)
{
	if (Reason == DLL_PROCESS_ATTACH)
		return Attach(DLL);

	else if (Reason == DLL_PROCESS_DETACH)
		return Detach();

	return TRUE;
}

BOOL Attach(HINSTANCE DLL)
{
	V_Name = "Project Ruby Dreams";
	V_DLL = DLL;
	V_Version = 5.33f;

	V_CDKey[0] = NULL;
	V_Registered = FALSE;

	V_StartingExperience = NULL;
	V_StartingGold = NULL;

	//CreateRegistryEntry();

	DefineOffsets();
	Load();

	SetInfoMenuVars();
	SetQuestsMenuVars();

	PreloadSettings();
	LoadStr();

	LoadDataSettings();
	LoadScriptSettings();

	LoadKeyItemSettings();

	LoadCDKeys();
	CheckCDKey();

	if (D2GFX_GetHwnd())
	{
		V_OldWndProc = (WNDPROC)GetWindowLongA(D2GFX_GetHwnd(), GWL_WNDPROC);
		SetWindowLongA(D2GFX_GetHwnd(), GWL_WNDPROC, (LONG)WindowProc);
	}

	if (ClientReady(FALSE))
	{
		LoadKeyItems();

		V_Design = new Design;
		V_Reveal = new Reveal;

		InstallPatches(INGAME);
		V_PatchInGame = TRUE;
	}

	else
	{
		if (RemovePEHeader(DLL))
		{
			LoadKeyItems();

			InstallPatches(OUTGAME);
			V_PatchOutGame = TRUE;
			V_PatchInGame = -1;
		}

		else
			TerminateProcess(GetCurrentProcess(), NULL);
	}

	V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)PRIMARY);
	V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)REGISTRY);

	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)MOVEPAD));

#ifdef MODWINDOW
	V_ThreadsMain.Add(MakeThread((LPVOID)Threads, (LPVOID)IGNORECLICK));

	SetWindowsHookEx(WH_MOUSE_LL, reinterpret_cast<HOOKPROC>(&LowLevelMouseProc), V_DLL, 0);
#endif

#ifdef EXTLEVELS
	ExtLevelsPatch();
#endif

	return TRUE;
}

BOOL Detach()
{
	DestroyThread(V_PrimaryThread.Handle, PRIMARY, INFINITE);
	DestroyThread(V_PrimaryThread.Handle, REGISTRY, INFINITE);

	DestroyInGameThreads();

	if (ClientReady(FALSE))
		RemovePatches(INGAME);
	else if (!ClientReady(FALSE))
		RemovePatches(OUTGAME);

	if (ClientReady(FALSE) && (!V_HostileImage || V_Design->Hide))
		PatchBytes((DWORD)LoadLibraryA("D2Client.dll") + 0x6E91C, 0x46, 1);

	if (D2GFX_GetHwnd())
		SetWindowLongA(D2GFX_GetHwnd(), GWL_WNDPROC, (LONG)V_OldWndProc);

	if (ClientReady(FALSE))
	{
		V_Reveal->DestroyLevelExits();
		V_Reveal->RemoveMyAutomapCells();
		V_Reveal->DestroyMyAutomapCells();
		//V_Reveal->DeleteShrines();
	}

	DestroyEditBox();
	DestroyFilterBox();
	DestroyTargets();
	DestroyVectors();

	return TRUE;
}

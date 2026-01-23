#include "Hack.h"

static BOOL releasedShift = TRUE;
static BOOL ignoreButton = FALSE;

static BOOL notifiedMenu = FALSE;

VOID Game(BOOL ExitGame)
{
	if (ExitGame)
	{
		if (KILLPROCESS == 0)
		{
			GameEnd();  //This is already patch called when player ends game
		}
		V_Game = FALSE;
	}

	else
	{
		GameStart();
		V_Game = TRUE;
	}
}

VOID GameEnd()
{
#ifdef NOWILDERNESSMENU
	if (!V_InTownTemp)
		V_GameLost = TRUE;
#endif

	V_InGame = FALSE;

	V_Reveal->DestroyLevelExits();
	V_Reveal->RemoveMyAutomapCells();
	V_Reveal->DestroyMyAutomapCells();
	//V_Reveal->DeleteShrines();

	DestroyEnchantQueue();
	DestroyEditBox();
	DestroyTargets();
	DestroyVectors();

	SleepEx(EXITDELAYLADDER, TRUE);

	if(V_BusyUpdData == TRUE && REITERATEDELAY > 0) //Pause to clean up player data threads
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 1) // Looping this is buggy, trying to scoot this along
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 2)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 3)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 4)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 5)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 6)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 7)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 8)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 9)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 10)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 11)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 12)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 13)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 14)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 15)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 16)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 17)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 18)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 19)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 20)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 21)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 22)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 23)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}
	if (V_BusyUpdData == TRUE && REITERATEDELAY > 24)
	{
		SleepEx(EXITDELAYLADDER, TRUE);
	}


	/* Buggy - Sometimes causes game to freeze
	int SleepCount = 0;
	while (V_BusyUpdData == TRUE || V_BusyUpdData2 == TRUE)
	{
		SleepEx(1000, TRUE);

		SleepCount++;

		if (SleepCount > 30)
			break;
	}
	*/

	DestroyInGameThreads();

	SetClockLast();

	if (V_COUNTED == FALSE) //Patchwork, buggy without this, double counts for some reason
	{
		CountGame();

		V_COUNTED = TRUE;
	}

	SavePlayerData();

	ResetIgnoreList();
	
	if(KILLPROCESS == 1)
	{
		TerminateProcess(GetCurrentProcess(), NULL);
	}

	if (KILLPROCESS == 0)
	{
		//GamePatch(FALSE); //Causes game to crash, need to move to another area.  TEST after DestroyVectors
	}
}

VOID GameStart()
{
	V_InGame = TRUE;

	while (!ClientReady(FALSE))
	{
		SleepEx(250, TRUE);
	}

	SleepEx(1000, TRUE);

	while (Me->pPath->pRoom1->pRoom2->pLevel->dwLevelNo == 0)
	{
		SleepEx(DELAYLOAD, TRUE);
	}

	SleepEx(1000, TRUE);

#ifdef LAZARUSMOD
	Print(1, 8, "Engine warming...");
	SleepEx(5000, TRUE);  //Crash fix, plugin seems to load too quick on old systems
#endif

	SetVars();
	
	V_GameTimer = GetTickCount();

	if(LEGITMAP != 1)
	{
		V_Reveal->InitShrines();
		V_Reveal->InitTCList();
	}

	GamePatch(TRUE);

	/*
	LPGAMESTRUCTINFO IPInfo = D2CLIENT_GetGameInfo();
	if (IPInfo->szGameServerIp)
	{
		GamePatchMP();
	}
	*/

	GameInfo();
	HostileImage();
	SetStates();

	CreateInGameThreads();

	if(LEGITSPEED == 0)
		IncreaseSpeedStats();

	sprintf_s(V_CharacterName, "%s", Me->pPlayerData->szName);
	sprintf_s(V_GMName, "%s", GMNAME);
	
	V_GameTimer = GetTickCount();

	V_Difficulty = D2CLIENT_GetDifficulty();

	/* Not working on multiplayer
	if (ClientNet->isHardCoreGame == 1)
	{
		V_Hardcore = TRUE;
	}
	*/
	V_Hardcore = FALSE;

	if (IsLODGame)
	{
		V_Expansion = TRUE;
	}

	if (GetUnitStat(Me, STAT_EXP) < 1)
	{
		V_NewCharacter = TRUE;
	}

#ifndef LAZARUSMOD
	if(*p_D2CLIENT_ScreenSizeX == 640)
	{
		Print(0, 1, "Note: Not all Hellfire II features will be available in low resolution.");
	}
#endif
	
#ifdef DEBUGKEYITEMS
	Print(1, 8, "Debug: All key items enabled.");
#endif

	/*
	switch (EXPANSIONPACK) //Version check. Entry Dialogue
	{
	case 0:

		Print(0, 0, "You wake up one morning as usual.");

		break;

	case 1:

		Print(0, 0, "You begin to dream as you fall deeper into sleep.");

		break;

	case 2:

		Print(0, 0, "As you awaken, you notice a prismatic glare from the sunlight.");

		break;

	case 3:

		Print(0, 0, "You are awakened by an enormous boom from the far distance.");

		break;

	case 4:

		Print(0, 0, "You are awakened by a crow nearby.");

		break;
	}
	*/

	//V_DisableInput = FALSE;
	//V_LoadingNotice = FALSE;

	string Name = (string)V_CharacterName;
	string GMName = (string)V_GMName;

	if (Name == GMName)
	{
		V_GMMode = TRUE;
	}
	else
	{
		V_GMMode = FALSE;
	}

	if(V_Registered == FALSE)
	{
		Print(0, 1, "Unregistered.");
		Print(0, 0, "Enter your ÿc2Identification Number ÿc0by typing ÿc4@id <idnumber> ÿc0.");
	}

	if(V_GMMode == TRUE)
	{
		Print(0, 1, "Project Ruby Dreams ÿc4version 5.34 is loadedÿc4 with ÿc5GM ÿc1mode active.");
		Print(0, 1, "Type ÿc5?gmhelp ÿc1for a list of ÿc5GM ÿc1commandsÿc1.");

		Load();
	}
	else
	{
		Print(0, 1, "Project Ruby Dreams ÿc4version 5.34 is loaded. Type ÿc2?help ÿc4for more information.");
	}

	INT TotalGold = GetUnitStat(Me, STAT_GOLD) + GetUnitStat(Me, STAT_GOLDBANK);

	V_GoldFoundLast = TotalGold;

	LoadPlayerData(); //Load Character Data
	if (LoadSuccess() == FALSE)
	{
		CreateSaveFile(); //Copy New Character File
	}

	PreloadSettings();

	SetAutomap();

	INT Rating = 0;

#ifdef LOSERANK
	Rating = (V_GamesWon * GAMESWONFACTOR) - ((V_GamesLost * GAMESLOSTFACTOR) + (V_GamesDraw * GAMESDRAWFACTOR));
#else
	Rating = (V_GamesWon * GAMESWONFACTOR);
#endif

	if (Rating < 1)
	{
		V_Rank = 1;
	}
	if (Rating >= 1)
	{
		V_Rank = 2;
	}
	if (Rating > 15)
	{
		V_Rank = 3;
	}
	if (Rating > 30)
	{
		V_Rank = 4;
	}
	if (Rating > 150)
	{
		V_Rank = 5;
	}
	if (Rating > 450)
	{
		V_Rank = 6;
	}
	if (Rating > 1250)
	{
		V_Rank = 7;
	}
	if (Rating > 2250)
	{
		V_Rank = 8;
	}
	if (Rating > 5000)
	{
		V_Rank = 9;
	}
	if (Rating > 25000)
	{
		V_Rank = 10;
	}

	LoadPlugY();

	Print(1, 9, "Loading guild ladder.");

#ifdef LAZARUSMOD
	V_LegitMode = FALSE;

	V_AutoRevealAutomap = TRUE;

	V_MonstersMap = TRUE;
	V_VectorsMap = TRUE;
	//V_MonstersMapExt = TRUE;
#endif

	V_BusyUpdData = TRUE;

	LoadLadder();

	RegisterLadder();

	if (V_MyLadderID == 0)
	{
		V_LastLadderID++;

		V_MyLadderID = V_LastLadderID;

		SortLadder();
		SaveLadder();

		LoadLadder();

		Print(1, 9, "New player registered.");

		V_BusyUpdData = FALSE;
	}
	else
	{
		UpdateLadder();
		SortLadder();

		SaveLadder();

		LoadLadder();

		V_BusyUpdData = FALSE;
	}

	Print(1, 9, "Guild ladder loaded!");

	//V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)SECONDARY);
	
}

VOID GameLoop()
{
	if (!ClientReady(FALSE))
		return;

	Exit();
	Town();
	Potion();

	EnumeratePlayers();
	EnumerateVectors();

#ifndef LAZARUSMOD
	if (V_Reveal && V_AutoRevealAutomap && LEGITMAP != 1)
		V_Reveal->RevealAutomap();
#else
	if (V_Reveal && V_AutoRevealAutomap)
		V_Reveal->RevealAutomap();
#endif

	if (V_EditBox && V_CopyPaste)
		CheckEditBox();

	if (InTown(Me))
		SetInTownVars();

	if (InTown(Me))
		V_InTownTemp = TRUE;
	else
		V_InTownTemp = FALSE;

	if (!GetUIVar(UI_INVENTORY) || GetUIVar(UI_TRADE))
		V_ViewingUnit = NULL;

	if (V_ViewingUnit && V_ViewingUnit->dwUnitId)
	{
		if (!GetUnit(V_ViewingUnit->dwUnitId, UNIT_TYPE_PLAYER))
		{
			V_ViewingUnit = NULL;
			D2CLIENT_SetUIVar(UI_INVENTORY, 1, 0);
		}
	}

	V_FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

#ifdef LANMPMODE
	LPGAMESTRUCTINFO Info = D2CLIENT_GetGameInfo();
	if (Info->szGameServerIp[0] != NULL)
	{
		INT RectX = 15;
		INT RectY = 490;

		INT ThisMouseOverX1 = RectX;
		INT ThisMouseOverY1 = RectY;
		INT ThisMouseOverX2 = ThisMouseOverX1 + 12;
		INT ThisMouseOverY2 = ThisMouseOverY1 + 12;


		if ((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
		{
			ignoreButton = TRUE;
		}
		else
		{
			ignoreButton = FALSE;
		}

		if (V_ToggleMenu || V_MenuObject > 0 || ignoreButton || V_ToggleStatMenu || V_ToggleInfoMenu || V_ToggleMissionMenu || V_ToggleAbilityMenu || V_ToggleGuideMenu || V_ToggleSettingMenu || V_CharacterStats)
		{
			if (releasedShift == TRUE)
			{
				INPUT Inputs[1] = { 0 };

				// Set up a generic keyboard event.
				Inputs[0].type = INPUT_KEYBOARD;
				Inputs[0].ki.wScan = 0; // hardware scan code for key
				Inputs[0].ki.time = 0;
				Inputs[0].ki.dwExtraInfo = 0;

				// Press the "Shift" key
				Inputs[0].ki.wVk = 16; // virtual-key code for the "Shift" key
				Inputs[0].ki.dwFlags = 0; // 0 for key press

				SendInput(1, Inputs, sizeof(INPUT));

				releasedShift = FALSE;
			}
		}
		else
		{
			if (V_ClickDelay == FALSE)
			{
				if (releasedShift == FALSE)
				{
					INPUT Inputs[1] = { 0 };

					// Complete a generic keyboard event.
					Inputs[0].type = INPUT_KEYBOARD;
					Inputs[0].ki.wScan = 0; // hardware scan code for key
					Inputs[0].ki.time = 0;
					Inputs[0].ki.dwExtraInfo = 0;

					// Release the "Shift" key
					Inputs[0].ki.wVk = 16; // virtual-key code for the "Shift" key
					Inputs[0].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press

					SendInput(1, Inputs, sizeof(INPUT));

					releasedShift = TRUE;
				}
			}
		}
	}
#endif

}

VOID HostileImage()
{
	if (!V_Design->Hide)
	{
		if (D2CLIENT_GetDifficulty() > 0)
			PatchBytes((DWORD)LoadLibraryA("D2Client.dll") + 0x6E91C, ((strlen(D2CLIENT_GetGameInfo()->szGamePassword) != NULL) ? 0x46 + 0x5F : 0x46 + 0x55), 1);
		else
			PatchBytes((DWORD)LoadLibraryA("D2Client.dll") + 0x6E91C, ((strlen(D2CLIENT_GetGameInfo()->szGamePassword) != NULL) ? 0x46 + 0x4B : 0x46 + 0x41), 1);

		V_HostileImage = TRUE;
	}

	else
		V_HostileImage = FALSE;
}

VOID SetAutomap()
{
	if (V_AutomapOnJoin && !*p_D2CLIENT_AutomapOn && LEGITMAP != 1)
		*p_D2CLIENT_AutomapOn = TRUE;
}

VOID SetStates()
{
	V_AmplifyDamageTimer = GetUnitState(Me, AFFECT_AMPLIFYDAMAGE) ? GetTickCount() : NULL;
	V_BattleCommandTimer = GetUnitState(Me, AFFECT_BATTLECOMMAND) ? GetTickCount() : NULL;
	V_BattleCryTimer = GetUnitState(Me, AFFECT_BATTLECRY) ? GetTickCount() : NULL;
	V_BattleOrdersTimer = GetUnitState(Me, AFFECT_BATTLEORDERS) ? GetTickCount() : NULL;
	V_BoneArmorTimer = GetUnitState(Me, AFFECT_BONEARMOR) ? GetTickCount() : NULL;
	V_BurstOfSpeedTimer = GetUnitState(Me, AFFECT_BURSTOFSPEED) ? GetTickCount() : NULL;
	V_ChillingArmorTimer = GetUnitState(Me, AFFECT_CHILLINGARMOR) ? GetTickCount() : NULL;
	V_ConvictedTimer = GetUnitState(Me, AFFECT_CONVICTED) ? GetTickCount() : NULL;
	V_CycloneArmorTimer = GetUnitState(Me, AFFECT_CYCLONEARMOR) ? GetTickCount() : NULL;
	V_DecrepifyTimer = GetUnitState(Me, AFFECT_DECREPIFY) ? GetTickCount() : NULL;
	V_EnchantTimer = GetUnitState(Me, AFFECT_ENCHANT) ? GetTickCount() : NULL;
	V_EnergyShieldTimer = GetUnitState(Me, AFFECT_ENERGYSHIELD) ? GetTickCount() : NULL;
	V_FadeTimer = GetUnitState(Me, AFFECT_FADE) ? GetTickCount() : NULL;
	V_FrozenTimer = GetUnitState(Me, AFFECT_FREEZE) ? GetTickCount() : NULL;
	V_FrozenArmorTimer = GetUnitState(Me, AFFECT_FROZENARMOR) ? GetTickCount() : NULL;
	V_HolyFrozenTimer = GetUnitState(Me, AFFECT_HOLYFREEZECHILL) ? GetTickCount() : NULL;
	V_HolyShieldTimer = GetUnitState(Me, AFFECT_HOLYSHIELD) ? GetTickCount() : NULL;
	V_InnerSightTimer = GetUnitState(Me, AFFECT_INNERSIGHT) ? GetTickCount() : NULL;
	V_IronMaidenTimer = GetUnitState(Me, AFFECT_IRONMAIDEN) ? GetTickCount() : NULL;
	V_LifeTapTimer = GetUnitState(Me, AFFECT_LIFETAP) ? GetTickCount() : NULL;
	V_LowerResistTimer = GetUnitState(Me, AFFECT_LOWERRESIST) ? GetTickCount() : NULL;
	V_OakSageTimer = GetUnitState(Me, AFFECT_OAKSAGE) ? GetTickCount() : NULL;
	V_OpenWoundsTimer = GetUnitState(Me, AFFECT_OPENWOUNDS) ? GetTickCount() : NULL;
	V_PoisonedTimer = GetUnitState(Me, AFFECT_POISON) ? GetTickCount() : NULL;
	V_ShiverArmorTimer = GetUnitState(Me, AFFECT_SHIVERARMOR) ? GetTickCount() : NULL;
	V_ShoutTimer = GetUnitState(Me, AFFECT_SHOUT) ? GetTickCount() : NULL;
	V_SlowedTimer = GetUnitState(Me, AFFECT_SLOWED) ? GetTickCount() : NULL;
	V_TerrorTimer = GetUnitState(Me, AFFECT_TERROR) ? GetTickCount() : NULL;
	V_ThunderStormTimer = GetUnitState(Me, AFFECT_THUNDERSTORM) ? GetTickCount() : NULL;
	V_VenomTimer = GetUnitState(Me, AFFECT_VENOMCLAWS) ? GetTickCount() : NULL;
}

VOID SetVars()
{
	V_CharacterStats = FALSE;

	V_AutoBlind = FALSE;
	V_AutoKB = FALSE;
	V_CubeOrStashOpened = FALSE;
	V_DelayedChicken = FALSE;
	V_Flash = FALSE;
	V_GoldDrop = FALSE;
	V_KB = FALSE;
	V_Reblind = FALSE;
	V_TP = FALSE;

	V_Blind = NULL;
	V_Target = NULL;
	V_FlashLast = NULL;
	V_InGameDeathCount = NULL;
	V_InGameKillCount = NULL;
	V_LastLevel = NULL;
	V_LifePotLast = NULL;
	V_LifeJuvLast = NULL;
	V_ManaPotLast = NULL;
	V_ManaJuvLast = NULL;

	if(RESETEXPCALC)
		V_StartingExperience = NULL;

	if(RESETGOLDCALC)
	{
		V_StartingGold = NULL;
	}
	V_GainedGold = NULL;

	V_TPLast = NULL;
	V_TPInteractLast = NULL;
	V_ViewingUnit = NULL;

	V_MonsterDescComma = L", ";

	V_CSet = FALSE;
	V_PCopied = FALSE;
	V_ICopied = FALSE;
	V_GMStart = FALSE;
	V_NPCCopied = FALSE;

	V_Block0x30 = FALSE;
	V_DupeComplete = FALSE;

	V_MonstersMap = FALSE;
	V_VectorsMap = FALSE;
	V_MonstersMapExt = FALSE;

	V_BusyThread = FALSE;
	V_WalkingActive = FALSE;

	V_EnableTeleport = FALSE;

	V_SideQuestMenu = FALSE;
	V_ClickDelay = FALSE;

	V_SideQuestExpansion = -1;

	V_SideQuestSelected = 0;

	V_SideQuestBack = FALSE;
	V_SideQuestNext = FALSE;

	V_SideQuestBackText = FALSE;
	V_SideQuestNextText = FALSE;

	V_SideQuestTextPages = 1;

	V_SideQuestListPages = 1;

	V_SelectedQuestPage = 1;

	V_IgnoreList[0] = NULL;
	V_IgnoreTarget = FALSE;

	V_PlayerInfoMenu = FALSE;

	V_PlayerInfoBack = FALSE;
	V_PlayerInfoNext = FALSE;
	V_PlayerInfoBackText = FALSE;
	V_PlayerInfoNextText = FALSE;

	V_PlayerInfoGroup = -1;
	V_PlayerInfoListPages = 1;
	V_PlayerInfoSelected = 0;
	V_PlayerInfoTextPages = 1;

	V_Hardcore = FALSE;
	V_Expansion = FALSE;

	V_Difficulty = 0;

	V_GameWon = FALSE;
	V_GameDraw = FALSE;
	V_GameLost = FALSE;

	V_MinusHealth = FALSE;
	V_BoHealth = FALSE;

	V_UsedWaypoint = FALSE;
	V_UsedHealth = FALSE;
	V_UsedMana = FALSE;
	V_UsedPortal = FALSE;
	V_UsedShrine = FALSE;

	V_NewCharacter = FALSE;
	V_NormalWon = FALSE;
	V_NMWon = FALSE;
	V_HellWon = FALSE;

	V_TravelDistanceN = 0;
	V_TravelDistanceS = 0;
	V_TravelDistanceE = 0;
	V_TravelDistanceW = 0;

	V_DistanceThis = 0;

	V_GoldFoundLast = 0;
	V_GoldFoundThis = 0;
	V_GoldCopper = 0;
	V_GoldSilver = 0;
	V_GoldThousand = 0;
	V_GoldMillion = 0;
	V_GoldBillion = 0;
	V_GoldTrillion = 0;

	V_RegistryNotice = 0;

	V_ClickDelay = FALSE;

	V_MenuObject = 0;
	V_ToggleMenu = FALSE;

	V_ShowLadderPage = 0;

	V_BusyUpdData = FALSE;

	V_LadderDeath = FALSE;

	V_QueueVibrate = FALSE;
	V_QueueVibrateSoft = FALSE;

	V_MyLadderNote[0] = NULL;
	V_TempLadderNote[0] = NULL;

	V_ResetLadderNote = FALSE;

	V_QueueLadderReset = FALSE;
	V_QueueLadderSave = FALSE;
	V_QueueLadderSetNote = FALSE;
	V_QueueLadderDeleteNote = FALSE;

	V_COUNTED = FALSE;

	V_MLBPosX = 0;
	V_MLBPosY = 0;
	V_MLBDifficulty = 0;
	V_MLBMonsterID = 0;

	V_MenuNotice = FALSE;
}

VOID SetInTownVars()
{
	if (V_TP) V_TP = FALSE;
	if (V_TPLast) V_TPLast = NULL;
	if (V_TPInteractLast) V_TPInteractLast = NULL;
	if (V_LifePotLast) V_LifePotLast = NULL;
	if (V_LifeJuvLast) V_LifeJuvLast = NULL;
	if (V_ManaPotLast) V_ManaPotLast = NULL;
	if (V_ManaJuvLast) V_ManaJuvLast = NULL;
	if (!V_TeleportQueue.IsEmpty()) V_TeleportQueue.RemoveAll();
}

VOID SetDeathMessage()
{
	SYSTEMTIME Time;
	GetLocalTime(&Time);

	V_InjectKillCount++;
	V_InGameKillCount++;

	sprintf_s(V_InjectKills, "%i", V_InjectKillCount);
	sprintf_s(V_InGameKills, "%i", V_InGameKillCount);
	sprintf_s(V_LocalDate, "%.2d-%.2d-%.2d", Time.wMonth, Time.wDay, Time.wYear);

	if (Time.wHour < 13 || Time.wHour > 23)
		sprintf_s(V_LocalTime, "%.2d:%.2d:%.2d AM", Time.wHour == 0 ? 12 : Time.wHour, Time.wMinute, Time.wSecond);
	else if (Time.wHour < 24 || Time.wHour > 12)
		sprintf_s(V_LocalTime, "%.2d:%.2d:%.2d PM", Time.wHour == 24 ? 12 : Time.wHour - 12, Time.wMinute, Time.wSecond);
}

VOID KillLog()
{
	SYSTEMTIME Time;
	GetLocalTime(&Time);

	CHAR File[MAX_PATH], Log[200];
	LPGAMESTRUCTINFO Info = D2CLIENT_GetGameInfo();

	if (strlen(Info->szGamePassword) <= NULL)
		sprintf_s(Log, "[%.2d:%.2d:%.2d - %.2d:%.2d:%.2d] %s was slain by %s (Game: %s)\n", Time.wMonth, Time.wDay, Time.wYear,
		Time.wHour, Time.wMinute, Time.wSecond, V_SlainName, Me->pPlayerData->szName, Info->szGameName);
	else
		sprintf_s(Log, "[%.2d:%.2d:%.2d - %.2d:%.2d:%.2d] %s was slain by %s (Game: %s / Password: %s)\n", Time.wMonth, Time.wDay, Time.wYear,
		Time.wHour, Time.wMinute, Time.wSecond, V_SlainName, Me->pPlayerData->szName, Info->szGameName, Info->szGamePassword);

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, "\\Kill Log.txt");

	FILE * KillLog;
	KillLog = fopen(File, "a");

	if (KillLog)
	{
		fputs(Log, KillLog);
		fclose(KillLog);
	}
}

VOID RemainingFrames()
{
	if (Me->dwMode == PLAYER_MODE_CAST)
		Me->wFrameRate = V_CastFrames;
}

VOID ScreenShot()
{
	if (KeyDown(VK_SNAPSHOT))
	{
		BOOL Hide = V_Design->Hide;
		BOOL AntiShake = V_AntiShake;
		BOOL AntiWeather = V_AntiWeather;
		BOOL FullLightRadius = V_FullLightRadius;

		if (!V_Design->Hide) V_Design->Hide = TRUE;
		if (V_AntiShake) V_AntiShake = FALSE;
		if (V_AntiWeather) V_AntiWeather = FALSE;
		if (V_FullLightRadius) V_FullLightRadius = FALSE;

		while (GetAsyncKeyState(VK_SNAPSHOT)) SleepEx(500, TRUE);

		if (V_Design->Hide) V_Design->Hide = Hide;
		if (!V_AntiShake) V_AntiShake = AntiShake;
		if (!V_AntiWeather) V_AntiWeather = AntiWeather;
		if (!V_FullLightRadius) V_FullLightRadius = FullLightRadius;
	}
}

VOID FASTCALL AssignPlayer(LPUNITANY Unit)
{
	if (!Unit)
		return;
}

VOID STDCALL GameShake(LPDWORD lpX, LPDWORD lpY)
{
	D2CLIENT_CalculateShake(lpX, lpY);

	if (!V_AntiShake)
		return;

	*p_D2CLIENT_ShakeX = 0;
	*p_D2CLIENT_ShakeY = 0;
}

BOOL FASTCALL InfraVision(LPUNITANY Unit)
{
	if(!V_ToggleKeyItem[5][3] || V_HaveKeyItemExp4[5] != 6222)
		return FALSE;

	switch(Unit->dwType)
	{
	case UNIT_TYPE_PLAYER:

		if (!Unit->dwMode || Unit->dwMode == PLAYER_MODE_DEAD)
			return FALSE;

		break;

	case UNIT_TYPE_NPC:

		if (!Unit->dwMode || Unit->dwMode == NPC_MODE_DEAD)
			return FALSE;

		break;

	case UNIT_TYPE_ITEM:
		break;

	default:
		return FALSE;
	}

	LPLEVEL Level = GetUnitLevel(Unit);

	if (Level && !D2COMMON_GetFunUnk_5(Level->dwLevelNo))
		return FALSE;

	return D2COMMON_TestFunUnk_6(Me, Unit, 2);
}

VOID FASTCALL MonsterDescComma(WCHAR * String, LPMONSTERTXT Text)
{
	if (Text->flag == 0x1506)
		wcscat(String, V_MonsterDescComma);
}

#ifndef LAZARUSMOD
WCHAR* FASTCALL MonsterLifeBarName(WCHAR* Old, LPDWORD TextSize, LPDWORD Size, DWORD Flag)
{
	if (!Old)
	{
		V_MonsterLifeBarNameOn = FALSE;
		V_MonsterLifeBarName[0] = NULL;

		V_MLBPosX = 0;
		V_MLBPosY = 0;
		V_MLBDifficulty = 0;
		V_MLBMonsterID = 0;
		return NULL;
	}

	if (!V_ViewSocketable)
		wcscpy(V_MonsterLifeBarName, Old);

	else
	{
		wcsrcat(V_MonsterLifeBarName, L"\n\n");
		wcsrcat(V_MonsterLifeBarName, Old);

		if (p_D2CLIENT_MonsterLifeNamePatch1->dwTxtFileNo < GetTextFileNo(V_MonsterLifeBarName))
			*Size = GetTextFileNo(V_MonsterLifeBarName) + p_D2CLIENT_MonsterLifeNamePatch2->dwTxtFileNo;
		else
			*Size = p_D2CLIENT_MonsterLifeNamePatch1->dwTxtFileNo;
	}

	LPUNITANY Unit = D2CLIENT_GetSelectedUnit();

	if (!V_MonsterLifeBarNameOn && Unit)
	{
		DWORD OriginalLength = (DWORD)wcslen(V_MonsterLifeBarName);
		DWORD TrimLength = OriginalLength;

		if (TrimLength > 0)
		{
			WCHAR* P = &V_MonsterLifeBarName[TrimLength - 1];

			while (TrimLength > 0 && *P == ' ')
			{
				--TrimLength;
				*P-- = NULL;
			}
		}

		if (Unit->dwType == UNIT_TYPE_NPC && D2CLIENT_GetMonsterOwner(Unit->dwUnitId) == -1)
		{
			GetMonsterLevelTC(V_MonsterLifeBarName, Unit, 0);
			GetMonsterResists(V_MonsterLifeBarName, Unit, 0);
		}

		DWORD Length = OriginalLength - TrimLength;

		while (Length-- > 0)
			wcscat(V_MonsterLifeBarName, L" ");
	}

	if (wcslen(V_MonsterLifeBarName) >= ARRAYSIZE(V_MonsterLifeBarName))
		wcscpy(V_MonsterLifeBarName, &V_MonsterDesc[wcslen(V_MonsterLifeBarName)]);

	if (!Flag)
		*TextSize += GetTextWidth(Old) / 2 - GetTextWidth(V_MonsterLifeBarName) / 2;

	UnitAny* pUnit = D2CLIENT_GetSelectedUnit();

	BOOL Checked = FALSE;
	if (Unit && Unit->dwType == UNIT_TYPE_NPC)
	{
		if (ValidCounterMonsters(Unit))
		{
			V_CounterPosition = 0;

			if (!Checked)
			{
				MonsterCheckType(Unit, (exUnitAny*)pUnit);
				MonsterCheckResistance(Unit);

				Checked = TRUE;
			}

			for (INT i = 0; i < MAXMONSTERS; i++)
			{
				if ((DWORD)i == Unit->dwTxtFileNo)
				{
					INT PosX = 400;
					INT PosY;

					if (GetUIVar(UI_INVENTORY) || GetUIVar(UI_SKILL))
					{
						PosX -= 200;
					}
					if (GetUIVar(UI_CHARACTER) || GetUIVar(UI_QUEST) || GetUIVar(UI_MERC) || GetUIVar(UI_WPMENU))
					{
						PosX += 200;
					}
					if (GetUIVar(UI_PARTY))
					{
						PosX += 200;
					}
					if (V_CounterPosition == 0)
					{
						PosY = 50;
					}
					if (V_CounterPosition == 1)
					{
						PosY = 61;
					}
					if (V_CounterPosition == 2)
					{
						PosY = 72;
					}

					V_MLBMonsterID = i;
					if (D2CLIENT_GetDifficulty() == 0)
					{
						if ((GetKeyState(VK_LMENU) & 0x100) == 0 && (GetKeyState(VK_RMENU) & 0x100) == 0)
						{
							V_MLBPosX = PosX;
							V_MLBPosY = PosY;
							V_MLBDifficulty = 0;
						}
					}
					else if (D2CLIENT_GetDifficulty() == 1)
					{
						if ((GetKeyState(VK_LMENU) & 0x100) == 0 && (GetKeyState(VK_RMENU) & 0x100) == 0)
						{
							V_MLBPosX = PosX;
							V_MLBPosY = PosY;
							V_MLBDifficulty = 1;
						}
					}
					else if (D2CLIENT_GetDifficulty() == 2)
					{
						if ((GetKeyState(VK_LMENU) & 0x100) == 0 && (GetKeyState(VK_RMENU) & 0x100) == 0)
						{
							V_MLBPosX = PosX;
							V_MLBPosY = PosY;
							V_MLBDifficulty = 2;
						}
					}
				}
			}
		}
	}

	V_MonsterLifeBarNameOn = TRUE;
	return V_MonsterLifeBarName;
}
#else	
WCHAR * FASTCALL MonsterLifeBarName(WCHAR * Old, LPDWORD TextSize, LPDWORD Size, DWORD Flag)
{
	if (!Old)
	{
		V_MonsterLifeBarNameOn = FALSE;
		V_MonsterLifeBarName[0] = NULL;
		return NULL;
	}

	if (!V_ViewSocketable)
		wcscpy(V_MonsterLifeBarName, Old);

	else
	{
		wcsrcat(V_MonsterLifeBarName, L"\n\n");
		wcsrcat(V_MonsterLifeBarName, Old);

		if (p_D2CLIENT_MonsterLifeNamePatch1->dwTxtFileNo < GetTextFileNo(V_MonsterLifeBarName))
			*Size = GetTextFileNo(V_MonsterLifeBarName) + p_D2CLIENT_MonsterLifeNamePatch2->dwTxtFileNo;
		else
			*Size = p_D2CLIENT_MonsterLifeNamePatch1->dwTxtFileNo;
	}

	LPUNITANY Unit = D2CLIENT_GetSelectedUnit();

	if (!V_MonsterLifeBarNameOn && Unit)
	{
		DWORD OriginalLength = (DWORD)wcslen(V_MonsterLifeBarName);
		DWORD TrimLength = OriginalLength;

		if (TrimLength > 0)
		{
			WCHAR * P = &V_MonsterLifeBarName[TrimLength - 1];

			while (TrimLength > 0 && *P == ' ')
			{
				--TrimLength;
				*P-- = NULL;
			}
		}

		if (Unit->dwType == UNIT_TYPE_NPC && D2CLIENT_GetMonsterOwner(Unit->dwUnitId) == -1)
		{
			GetMonsterLevelTC(V_MonsterLifeBarName, Unit, 0);
			GetMonsterResists(V_MonsterLifeBarName, Unit, 0);
		}

		DWORD Length = OriginalLength - TrimLength;

		while (Length-- > 0)
			wcscat(V_MonsterLifeBarName, L" ");
	}

	if (wcslen(V_MonsterLifeBarName) >= ARRAYSIZE(V_MonsterLifeBarName))
		wcscpy(V_MonsterLifeBarName, &V_MonsterDesc[wcslen(V_MonsterLifeBarName)]);

	if (!Flag)
		*TextSize += GetTextWidth(Old) / 2 - GetTextWidth(V_MonsterLifeBarName) / 2;

	UnitAny* pUnit = D2CLIENT_GetSelectedUnit();

	BOOL Checked = FALSE;
	if (Unit && Unit->dwType == UNIT_TYPE_NPC)
	{
		if (ValidCounterMonsters(Unit))
		{
			V_CounterPosition = 0;

			if (!Checked)
			{
				MonsterCheckType(Unit, (exUnitAny*)pUnit);
				MonsterCheckResistance(Unit);

				Checked = TRUE;
			}

			for (INT i = 0; i < MAXMONSTERS; i++)
			{
				if ((DWORD)i == Unit->dwTxtFileNo)
				{
					INT PosX = 320;
					INT PosY;

					if (GetUIVar(UI_INVENTORY) || GetUIVar(UI_SKILL))
					{
						PosX -= 160;
					}
					if (GetUIVar(UI_CHARACTER) || GetUIVar(UI_QUEST) || GetUIVar(UI_MERC) || GetUIVar(UI_WPMENU))
					{
						PosX += 160;
					}
					if (GetUIVar(UI_PARTY))
					{
						PosX += 160;
					}
					if (V_CounterPosition == 0)
					{
						PosY = 50;
					}
					if (V_CounterPosition == 1)
					{
						PosY = 61;
					}
					if (V_CounterPosition == 2)
					{
						PosY = 72;
					}

					if (D2CLIENT_GetDifficulty() == 0)
					{
						if ((GetKeyState(VK_LMENU) & 0x100) == 0 && (GetKeyState(VK_RMENU) & 0x100) == 0)
						{
							V_Design->DrawOutCenter(PosX, PosY, 0, 6, 1, "%s %s", V_CounterBarKilledStr, AddCommas(V_MonsterUnit[0][i], 0));
						}
					}
					else if (D2CLIENT_GetDifficulty() == 1)
					{
						if ((GetKeyState(VK_LMENU) & 0x100) == 0 && (GetKeyState(VK_RMENU) & 0x100) == 0)
						{
							V_Design->DrawOutCenter(PosX, PosY, 0, 6, 1, "%s %s", V_CounterBarKilledStr, AddCommas(V_MonsterUnit[1][i], 0));
						}
					}
					else if (D2CLIENT_GetDifficulty() == 2)
					{
						if ((GetKeyState(VK_LMENU) & 0x100) == 0 && (GetKeyState(VK_RMENU) & 0x100) == 0)
						{
							V_Design->DrawOutCenter(PosX, PosY, 0, 6, 1, "%s %s", V_CounterBarKilledStr, AddCommas(V_MonsterUnit[2][i], 0));
						}
					}
				}
			}
		}
	}

	V_MonsterLifeBarNameOn = TRUE;
	return V_MonsterLifeBarName;
}
#endif

DWORD FASTCALL PlayerBlobs(LPUNITANY Unit)
{
	if (!Unit)
		return 98;

	if (!V_Design->Hide && Unit->dwType == UNIT_TYPE_PLAYER)
	{
		DWORD Flags = GetPvPFlags(Unit->dwUnitId);

		if (Unit->dwUnitId == V_Players[V_Target]->UnitId)
			return V_TargetPlayerColor;

		if (Flags & PVP_HOSTILED_BY_YOU || Flags & PVP_HOSTILED_YOU)
			return V_HostilePlayerColor;
	}

	return 98;
}

VOID FASTCALL OnGameKeyDown(BYTE Key, BYTE Repeat)
{
	if (Key == 71) //G
	{
#ifdef NOWILDERNESSACTIONMENU		
		if (!InTown(Me))
		{
			if (!notifiedMenu)
			{
				Print(0, 9, "Unable to use the action menu outside of town.");

				notifiedMenu = TRUE;
			}

			return;
		}
#endif
		if(V_MenuObject < 1)
		{
			V_ToggleMenu = !V_ToggleMenu;
		}

		V_ClickIgnoreMenu = FALSE;
		V_ClickIgnoreStat = FALSE;
		V_ClickIgnoreInfo = FALSE;
		V_ClickIgnoreMission = FALSE;
		V_ClickIgnoreAbility = FALSE;
		V_ClickIgnoreGuide = FALSE;
		V_ClickIgnoreCalc = FALSE;
		V_ClickIgnoreSetting = FALSE;
	}

	if (Key == K_CloseBackspace || Key == K_CloseEscape)
	{
		if(!GetUIVar(UI_CHAT))
		{
			V_ToggleMenu = FALSE;

			V_ToggleStatMenu = FALSE;
			V_ToggleInfoMenu = FALSE;
			V_ToggleMissionMenu = FALSE;
			V_ToggleAbilityMenu = FALSE;
			V_ToggleGuideMenu = FALSE;
			V_ToggleSettingMenu = FALSE;

			V_CharacterStats = FALSE;

			V_MenuObject = 0;

			V_ShowLadderPage = 0;

			V_ClickIgnore = FALSE;

			V_PlayerInfoGroup = -1;

			ResetInfoMenu();

			V_SelectedCounterPage = 1;
			V_SelectedCounterPageText = 1;

			V_PlayerInfoListPages = 1;

			V_ClickIgnoreInfo2 = FALSE;

			V_SideQuestExpansion = -1;

			ResetQuestsMenu();
			ResetQuestsText();

			V_SelectedQuestPage = 1;
			V_SelectedQuestPageText = 1;

			V_SideQuestListPages = 1;

			V_ClickIgnoreMission2 = FALSE;
			V_ClickIgnoreAbility2 = FALSE;

			V_ClickIgnoreStat2 = FALSE;
			V_ClickIgnoreGuide2 = FALSE;

			D2CLIENT_PlaySound(STAND_PASS);

			//V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)LADDERSAVE));
		}
	}

	if (Key == K_AttackMyselfLeft)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT) && !InTown(Me))
		{
			BOOL Left = V_LeftAttack;
			V_LeftAttack = TRUE;

			UseSkillOnUnit(Me, GetCurrentSkill(V_LeftAttack), TRUE, FALSE, TRUE);
			V_LeftAttack = Left;
		}
	}

	if (Key == K_AttackMyselfRight)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT) && !InTown(Me))
		{
			BOOL Left = V_LeftAttack;
			V_LeftAttack = FALSE;

			UseSkillOnUnit(Me, GetCurrentSkill(V_LeftAttack), FALSE, FALSE, TRUE);
			V_LeftAttack = Left;
		}
	}

	if (Key == K_AttackNearestTargetLeft)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT) && !InTown(Me))
		{
			BOOL Left = V_LeftAttack;
			V_LeftAttack = TRUE;

			AttackNearestTarget();
			V_LeftAttack = Left;
		}
	}

	if (Key == K_AttackNearestTargetRight)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT) && !InTown(Me))
		{
			BOOL Left = V_LeftAttack;
			V_LeftAttack = FALSE;

			AttackNearestTarget();
			V_LeftAttack = Left;
		}
	}

	if (Key == K_AttackTargetLeft)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT) && !InTown(Me))
		{
			BOOL Left = V_LeftAttack;
			V_LeftAttack = TRUE;

			if (!V_Players.IsEmpty())
				AttackTarget(V_Players[V_Target]->UnitId, UNIT_TYPE_PLAYER);
			else
				AttackTarget(Me->dwUnitId, UNIT_TYPE_PLAYER);

			V_LeftAttack = Left;
		}
	}

	if (Key == K_AttackTargetRight)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT) && !InTown(Me))
		{
			BOOL Left = V_LeftAttack;
			V_LeftAttack = FALSE;

			if (!V_Players.IsEmpty())
				AttackTarget(V_Players[V_Target]->UnitId, UNIT_TYPE_PLAYER);
			else
				AttackTarget(Me->dwUnitId, UNIT_TYPE_PLAYER);

			V_LeftAttack = Left;
		}
	}

	if (Key == K_AutoBlind)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			if (!V_Players.IsEmpty())
			{
				if (V_AutoKB)
					V_AutoKB = FALSE;

				V_AutoBlind = !V_AutoBlind;

				if (V_AutoBlind && V_Blind >= 1 && V_Blind <= 4)
					Print(0, 4, "ÿc4Lazarusÿc0: Automatically teleporting to blind spot %d of nearest target", V_Blind);

				else if (V_AutoBlind && (V_Blind == 0 || V_Blind == 5))
					Print(0, 4, "ÿc4Lazarusÿc0: Automatically teleporting to blind spot 1 of nearest target");

				else if (!V_AutoBlind)
					Print(0, 4, "ÿc4Lazarusÿc0: ÿc1Automatic blind spot teleporting is off");
			}
		}
	}

	if (Key == K_AutoKB)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			if (!V_Players.IsEmpty())
			{
				if (V_AutoBlind)
					V_AutoBlind = FALSE;

				V_AutoKB = !V_AutoKB;

				if (V_AutoKB)
					Print(0, 4, "ÿc4Lazarusÿc0: Automatically knocking back the nearest target");
				else
					Print(0, 4, "ÿc4Lazarusÿc0: ÿc1Automatic knockback is off");
			}
		}
	}

	if (Key == K_Blind)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT) && !V_Players.IsEmpty())
		{
			if (V_Blind < 5)
			{
				V_Blind++;

				if (V_Blind >= 1 && V_Blind <= 4)
					Print(0, 4, "ÿc4Lazarusÿc0: Aiming at blind spot ÿc4%d ÿc0of ÿc4%s", V_Blind, V_Players[V_Target]->PlayerName);
				else if (V_Blind == 5)
					Print(0, 4, "ÿc4Lazarusÿc0: Aiming at ÿc4%s's clicking location", V_Players[V_Target]->PlayerName);
			}

			else
			{
				V_Blind = 0;

				if (!V_Players.IsEmpty())
					Print(0, 4, "ÿc4Lazarusÿc0: Aiming at ÿc4%s", V_Players[V_Target]->PlayerName);
			}
		}
	}

	if (Key == K_CurrentSong)
	{
		if (!GetUIVar(UI_CHAT))
		{
			if (MaxTime() != INFINITE)
				Say("%s%s <%.2d:%.2d:%.2d / %.2d:%.2d:%.2d>", V_CurrentSongPhrase, CurrentSong(), (CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60, (MaxTime() / 3600) % 60, (MaxTime() / 60) % 60, MaxTime() % 60);
			else
				Say("%s%s <%.2d:%.2d:%.2d / --:--:-->", V_CurrentSongPhrase, CurrentSong(), (CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60);
		}
	}

	if (Key == K_Clean)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
		{
			V_Design->Hide = !V_Design->Hide;
		}
	}

	if (Key == K_FastForwardSong)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			FastForward();
	}

	if (Key == K_Flash)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT) && !V_Players.IsEmpty())
		{
			V_Players[V_Target]->Flashing = !V_Players[V_Target]->Flashing;

			if (V_Players[V_Target]->Flashing)
				Print(0, 4, "Flashÿc0: Flashing ÿc4%s ÿc0at a rate of ÿc1%d milliseconds", V_Players[V_Target]->PlayerName, V_FlashDelay);
			else
				Print(0, 4, "Flashÿc0: ÿc4Stopped flashing ÿc1%s", V_Players[V_Target]->PlayerName);
		}
	}

	if (Key == K_HigherSongVolume)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			HigherVolume();
	}

	if (Key == K_LowerSongVolume)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			LowerVolume();
	}

	if (Key == K_NextSong)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			NextSong();
	}

	if (Key == K_NextTarget)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT) && !V_Players.IsEmpty())
		{
			NextTarget();
			if (!V_TargetList && !V_TargetInfo) Print(0, 4, "ÿc4Lazarusÿc0: ÿc4%s is targetted", V_Players[V_Target]->PlayerName);
		}
	}

	if (Key == K_Options)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			V_Options = !V_Options;
	}

	if (Key == K_PauseSong)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			Pause();
	}

	if (Key == K_PlaySong)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			Play();
	}

	if (Key == K_PreviousSong)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			PreviousSong();
	}

	if (Key == K_PreviousTarget)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT) && !V_Players.IsEmpty())
		{
			PreviousTarget();
			if (!V_TargetList && !V_TargetInfo) Print(0, 4, "ÿc4Lazarusÿc0: ÿc4%s is targetted", V_Players[V_Target]->PlayerName);
		}
	}

	if (Key == K_ProtectItemSocket)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			V_ProtectItemSocket = !V_ProtectItemSocket;
			Print(0, 4, V_ProtectItemSocket ? "ÿc4Lazarusÿc0: ÿc4Item socket protection enabled" : "ÿc4Lazarusÿc0: ÿc1Item socket protection disabled");
		}
	}

	if (Key == K_RewindSong)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			Rewind();
	}

	if (Key == K_SetKickLeft)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			if (GetCurrentSkill(TRUE) != D2S_KICK)
				SetSkill(D2S_KICK, TRUE);
		}
	}

	if (Key == K_SetKickRight)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			if (GetCurrentSkill(FALSE) != D2S_KICK)
				SetSkill(D2S_KICK, FALSE);
		}
	}

	if (Key == K_Stats)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			V_CharacterStats = !V_CharacterStats;
		}
	}

	if (Key == K_StopSong)
	{
		if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			Stop();
	}

	if (Key == K_TP)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			if (V_TP) V_TP = FALSE;
			if (!V_TP) Portal();
		}
	}

	if (Key == K_ViewItemBasicStats)
	{
		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
		{
			V_ViewItemBasicStats = !V_ViewItemBasicStats;
			Print(0, 4, V_ViewItemBasicStats ? "ÿc4Lazarusÿc0: ÿc4Viewing basic stats of items enabled" : "ÿc4Lazarusÿc0: ÿc1Viewing basic stats of items disabled");
		}
	}

	if (!Repeat)
	{
		if (Key == K_Exit)
		{
			if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				D2CLIENT_ExitGame();
		}

		if (Key == K_NextLevelVector)
		{
			if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
				TeleportToVector(1);
		}

		if (Key == K_PreviousLevelVector)
		{
			if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
				TeleportToVector(2);
		}
		if (Key == K_QuestVector)
		{
			if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
				TeleportToVector(3);
		}

		if (Key == K_TeleHost)
		{
			if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
			{
				LPUNITANY Target = (LPUNITANY)GetUnit(V_Players[V_Target]->UnitId, UNIT_TYPE_PLAYER);

				if (!V_Players.IsEmpty() && Target)
				{
					BLIND Blinds[4] = {{2, 2}, {3, 2}, {-1, 3}, {2.0, -1.2}};

					if (InTown(Me) && !InTown(Target))
						HostilePlayer(Target->dwUnitId);

					if (V_Blind >= 1 && V_Blind <= 4)
						Teleport(Target->pPath->xPos + (WORD)Blinds[V_Blind - 1].X, Target->pPath->yPos + (WORD)Blinds[V_Blind - 1].Y);
					else
						Teleport(Target->pPath->xPos, Target->pPath->yPos);
				}
			}
		}

		if (Key == K_TeleWalk)
		{
			if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
			{
				V_TeleWalk = TRUE;
				Print(0, 4, "ÿc4Lazarusÿc0: ÿc4Teleporting to where you click");
			}
		}

		if (Key == K_Town)
		{
			if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
			{
				if (Portal()) V_TP = TRUE;
			}
		}

		if (Key == K_ViewInventory)
		{
			if (ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			{
				LPUNITANY Unit = D2CLIENT_GetSelectedUnit();

				if (!Unit)
					Unit = (LPUNITANY)GetUnit(V_Players[V_Target]->UnitId, UNIT_TYPE_PLAYER);

				if (Unit && Unit->pInventory && Unit->dwType == UNIT_TYPE_PLAYER)
				{
					if (Unit->dwMode != PLAYER_MODE_DEAD && Unit->dwMode != PLAYER_MODE_DEATH)
						V_ViewingUnit = Unit;

					if (!GetUIVar(UI_INVENTORY))
						D2CLIENT_SetUIVar(UI_INVENTORY, 0, 0);
				}
			}
		}

		if (Key == K_WaypointVector)
		{
			if (ClientReady(TRUE) && !GetUIVar(UI_CHAT))
				TeleportToVector(4);
		}
	}
}

INT FASTCALL OutTownSelect(LPUNITANY Unit)
{
	if (!V_PlayerInTown && TestUnit(Unit))
	{
		if (V_OutTownSelect || InTown(Unit))
			return TRUE;
	}

	return -1;
}

LONG STDCALL WindowProc(HWND HWnd, UINT MSG, WPARAM WParam, LPARAM LParam)
{
	if (MSG == WM_ACTIVATEAPP)
	{
		if (V_AntiMinimize && !WParam)
			return FALSE;
	}

	if (MSG == WM_KEYDOWN || MSG == WM_SYSKEYDOWN)
	{
		if (WParam == K_CurrentSong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
			{
				if (MaxTime() != INFINITE)
					Say("%s%s <%.2d:%.2d:%.2d / %.2d:%.2d:%.2d>", V_CurrentSongPhrase, CurrentSong(), (CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60, (MaxTime() / 3600) % 60, (MaxTime() / 60) % 60, MaxTime() % 60);
				else
					Say("%s%s <%.2d:%.2d:%.2d / --:--:-->", V_CurrentSongPhrase, CurrentSong(), (CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60);
			}
		}

		if (WParam == K_FastForwardSong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				FastForward();
		}

		if (WParam == K_HigherSongVolume)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				HigherVolume();
		}

		if (WParam == K_LoadConfiguration)
		{
			if (!GetUIVar(UI_CHAT))
			{
				if (Load())
				{
					if (!ClientReady(FALSE))
						MessageBeep(0);
					else
						Print(0, 4, "%sÿc0: ÿc4Loaded configuration", V_Name);
				}
			}
		}

		if (WParam == K_LowerSongVolume)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				LowerVolume();
		}

		if (WParam == K_NextSong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				NextSong();
		}

		if (WParam == K_PauseSong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				Pause();
		}

		if (WParam == K_PlaySong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				Play();
		}

		if (WParam == K_PreviousSong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				PreviousSong();
		}

		if (WParam == K_RewindSong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				Rewind();
		}

		if (WParam == K_StopSong)
		{
			if (!ClientReady(FALSE) && !GetUIVar(UI_CHAT))
				Stop();
		}
	}

	if (MSG == WM_LBUTTONDOWN)
	{
		INT X = LOWORD(LParam);
		INT Y = HIWORD(LParam);

		/*if (KeyDown(K_ControlHotkey))
		{
			if (ClientReady(TRUE) && !V_Players.IsEmpty())
			{
				if (X >= V_TargetListX && X <= V_TargetListX + 72 + (2 * LongestCharName(11)))
				{
					if (Y >= V_TargetListY && Y <= V_TargetListY + 22 + (10 * V_Players.GetSize()))
					{
						Print(0, 2, "TEST");
					}
				}
			}

			return FALSE;
		}*/
	}

	if (MSG == WM_LBUTTONDOWN || MSG == WM_RBUTTONDOWN)
	{
		INT X = LOWORD(LParam);
		INT Y = HIWORD(LParam);

		if (GetUIVar(UI_INVENTORY) && V_ViewingUnit && X >= 400)
			return FALSE;

		if (ClientReady(TRUE) && !GetUIVar(UI_CHAT) && V_Design->ClearScreen(3))
		{
			if (V_Options)
			{
				V_ClickIgnore = TRUE;

				if (X >= 0 && X <= 800 && Y >= 485 && Y <= 600)
					V_Options = FALSE;

				if (X >= 0 && X <= 800 && Y >= 0 && Y <= 10)
					V_Options = FALSE;

				if (X >= 0 && X <= 27 && Y >= 0 && Y <= 600)
					V_Options = FALSE;

				if (X >= 775 && X <= 800 && Y >= 0 && Y <= 600)
					V_Options = FALSE;

				if (X >= 26 && X <= 200 && Y > 35 && Y < 50)
				{
					V_LifeTownPercent += 5;

					if (V_LifeTownPercent > 99)
						V_LifeTownPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 50 && Y < 65)
				{
					V_LifeExitPercent += 5;

					if (V_LifeExitPercent > 99)
						V_LifeExitPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 65 && Y < 80)
				{
					V_ManaTownPercent += 5;

					if (V_ManaTownPercent > 99)
						V_ManaTownPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 80 && Y < 95)
				{
					V_ManaExitPercent += 5;

					if (V_ManaExitPercent > 99)
						V_ManaExitPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 115 && Y < 130)
				{
					V_LifePotPercent += 5;

					if (V_LifePotPercent > 99)
						V_LifePotPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 130 && Y < 145)
				{
					V_ManaPotPercent += 5;

					if (V_ManaPotPercent > 99)
						V_ManaPotPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 145 && Y < 160)
				{
					V_LifeJuvPercent += 5;

					if (V_LifeJuvPercent > 99)
						V_LifeJuvPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 160 && Y < 175)
				{
					V_ManaJuvPercent += 5;

					if (V_ManaJuvPercent > 99)
						V_ManaJuvPercent = 0;
				}

				if (X >= 26 && X <= 200 && Y > 200 && Y < 215)
				{
					V_Aim = !V_Aim;
				}

				if (X >= 26 && X <= 200 && Y > 215 && Y < 230)
				{
					V_BlockFakes = !V_BlockFakes;
				}

				if (X >= 26 && X <= 200 && Y > 225 && Y < 240)
				{
					if (V_Blind < 5)
						V_Blind++;
					else
						V_Blind = 0;
				}

				if (X >= 26 && X <= 200 && Y > 260 && Y < 275)
				{
					V_Screenshot = !V_Screenshot;
				}

				if (X >= 26 && X <= 200 && Y > 275 && Y < 290)
				{
					V_Orbs = !V_Orbs;
				}

				if (X >= 26 && X <= 200 && Y > 290 && Y < 305)
				{
					V_Mouse = !V_Mouse;
				}

				if (X >= 26 && X <= 200 && Y > 305 && Y < 320)
				{
					V_PlayerLifePercent = !V_PlayerLifePercent;
				}

				if (X >= 26 && X <= 200 && Y > 320 && Y < 335)
				{
					V_PlayerLifeBar = !V_PlayerLifeBar;
				}

				if (X >= 26 && X <= 200 && Y > 335 && Y < 350)
				{
					V_Vectors = !V_Vectors;
				}

				if (X >= 26 && X <= 200 && Y > 350 && Y < 365)
				{
					V_ExpInfo = !V_ExpInfo;
				}

				if (X >= 26 && X <= 200 && Y > 365 && Y < 380)
				{
					V_StateList = !V_StateList;
				}

				if (X >= 26 && X <= 200 && Y > 380 && Y < 395)
				{
					V_Supplies = !V_Supplies;
				}

				if (X >= 26 && X <= 200 && Y > 395 && Y < 410)
				{
					V_MusicPlayer = !V_MusicPlayer;
				}

				if (X >= 26 && X <= 200 && Y > 410 && Y < 425)
				{
					V_TargetInfo = !V_TargetInfo;
				}

				if (X >= 26 && X <= 200 && Y > 425 && Y < 440)
				{
					V_TargetList = !V_TargetList;
				}

				if (X >= 26 && X <= 200 && Y > 440 && Y < 455)
				{
					V_EscapeInfo = !V_EscapeInfo;
				}

				if (X >= 26 && X <= 200 && Y > 455 && Y < 470)
				{
					V_PotionInfo = !V_PotionInfo;
				}

				if (X >= 250 && X <= 550 && Y > 35 && Y < 50)
				{
					V_DeathMessage = !V_DeathMessage;
				}

				if (X >= 250 && X <= 550 && Y > 50 && Y < 65)
				{
					V_DeathMessageDelay += 10;

					if (V_DeathMessageDelay >= 100)
						V_DeathMessageDelay = 0;
				}

				if (X >= 250 && X <= 550 && Y > 115 && Y < 130)
				{
					V_Enchant = !V_Enchant;
				}

				if (X >= 250 && X <= 550 && Y > 130 && Y < 145)
				{
					V_EnchantNote = !V_EnchantNote;
				}

				if (X >= 250 && X <= 550 && Y > 195 && Y < 210)
				{
					V_AntiFlash = !V_AntiFlash;
				}

				if (X >= 250 && X <= 550 && Y > 210 && Y < 225)
				{
					V_FlashDelay += 100;

					if (V_FlashDelay > 1000)
						V_FlashDelay = 0;
				}

				if (X >= 250 && X <= 550 && Y > 260 && Y < 275)
				{
					V_AntiQuestBox = !V_AntiQuestBox;
				}

				if (X >= 250 && X <= 550 && Y > 275 && Y < 290)
				{
					V_CopyPaste = !V_CopyPaste;
				}

				if (X >= 250 && X <= 550 && Y > 290 && Y < 305)
				{
					V_KillLog = !V_KillLog;
				}

				if (X >= 250 && X <= 550 && Y > 305 && Y < 320)
				{
					V_ModifiedJoinMessage = !V_ModifiedJoinMessage;
				}

				if (X >= 250 && X <= 550 && Y > 320 && Y < 335)
				{
					V_OutTownSelect = !V_OutTownSelect;
				}

				if (X >= 250 && X <= 550 && Y > 335 && Y < 350)
				{
					V_AutomapOnJoin = !V_AutomapOnJoin;
				}

				if (X >= 250 && X <= 550 && Y > 350 && Y < 365)
				{
					V_RememberGameName = !V_RememberGameName;
				}

				if (X >= 250 && X <= 550 && Y > 365 && Y < 380)
				{
					V_RememberGamePassword = !V_RememberGamePassword;
				}

				if (X >= 250 && X <= 550 && Y > 400 && Y < 415)
				{
					Play();
				}

				if (X >= 250 && X <= 550 && Y > 415 && Y < 430)
				{
					Pause();
				}

				if (X >= 250 && X <= 550 && Y > 430 && Y < 445)
				{
					Stop();
				}

				if (X >= 250 && X <= 550 && Y > 445 && Y < 460)
				{
					NextSong();
				}

				if (X >= 250 && X <= 550 && Y > 460 && Y < 475)
				{
					PreviousSong();
				}

				if (X >= 560 && X < 775 && Y > 35 && Y < 50)
				{
					V_Potion = !V_Potion;
				}

				if (X >= 560 && X < 775 && Y > 50 && Y < 65)
				{
					V_Quests = !V_Quests;
				}

				if (X >= 560 && X < 775 && Y > 65 && Y < 80)
				{
					V_LifePot = !V_LifePot;
				}

				if (X >= 560 && X < 775 && Y > 80 && Y < 95)
				{
					V_ManaPot = !V_ManaPot;
				}

				if (X >= 560 && X < 775 && Y > 95 && Y < 110)
				{
					V_LifeJuv = !V_LifeJuv;
				}

				if (X >= 560 && X < 775 && Y > 110 && Y < 125)
				{
					V_ManaJuv = !V_ManaJuv;
				}

				if (X >= 560 && X < 775 && Y > 145 && Y < 160)
				{
					V_AntiShake = !V_AntiShake;
				}

				if (X >= 560 && X < 775 && Y > 160 && Y < 175)
				{
					V_AntiWeather = !V_AntiWeather;
				}

				if (X >= 560 && X < 775 && Y > 175 && Y < 190)
				{
					V_AutoRevealAutomap = !V_AutoRevealAutomap;
				}

				if (X >= 560 && X < 775 && Y > 190 && Y < 205)
				{
					V_Ethereal = !V_Ethereal;
				}

				if (X >= 560 && X < 775 && Y > 205 && Y < 220)
				{
					V_FullLightRadius = !V_FullLightRadius;
				}

				if (X >= 560 && X < 775 && Y > 220 && Y < 235)
				{
					V_ItemLevel = !V_ItemLevel;
				}

				if (X >= 560 && X < 775 && Y > 235 && Y < 250)
				{
					V_ProtectItemSocket = !V_ProtectItemSocket;
				}

				if (X >= 560 && X < 775 && Y > 250 && Y < 265)
				{
					V_Sockets = !V_Sockets;
				}

				if (X >= 560 && X < 775 && Y > 265 && Y < 280)
				{
					V_LevelNames = !V_LevelNames;
				}

				if (X >= 560 && X < 775 && Y > 280 && Y < 295)
				{
					V_ShrineImages = !V_ShrineImages;
				}

				if (X >= 560 && X < 775 && Y > 295 && Y < 310)
				{
					V_ViewItemBasicStats = !V_ViewItemBasicStats;
				}

				if (X >= 560 && X < 775 && Y > 310 && Y < 325)
				{
					V_Missiles = !V_Missiles;
				}

				if (X >= 560 && X < 775 && Y > 325 && Y < 340)
				{
					V_Monsters = !V_Monsters;
				}

				if (X >= 560 && X < 775 && Y > 340 && Y < 355)
				{
					V_MonsterResists = !V_MonsterResists;
				}

				if (X >= 560 && X < 775 && Y > 355 && Y < 370)
				{
					V_MonsterNames = !V_MonsterNames;
				}

				if (X >= 560 && X < 775 && Y > 390 && Y < 405)
				{
					V_SpeedAttack = !V_SpeedAttack;
				}

				if (X >= 560 && X < 775 && Y > 405 && Y < 420)
				{
					V_SpeedCast = !V_SpeedCast;
				}

				if (X >= 560 && X < 775 && Y > 440 && Y < 455)
				{
					V_FastTeleport = !V_FastTeleport;
				}

				if (X >= 560 && X < 775 && Y > 455 && Y < 470)
				{
					V_FarcastTeleport = !V_FarcastTeleport;
				}

				return FALSE;
			}
			else
			{
				V_ClickIgnore = FALSE;
			}
		}
	}

	if (MSG == WM_MBUTTONDOWN)
	{
		if (ClientReady(TRUE) && GetCurrentSkill(FALSE) == D2S_TELEPORT && V_FarcastTeleport)
			SendMessageA(D2GFX_GetHwnd(), WM_RBUTTONDOWN, NULL, LOWORD((MouseX)) | HIWORD((MouseY)));
	}

	if (MSG == WM_MBUTTONUP)
	{
		if (ClientReady(TRUE))
			SendMessageA(D2GFX_GetHwnd(), WM_RBUTTONUP, NULL, LOWORD((MouseX)) | HIWORD((MouseY)));
	}

	if (MSG == WM_RBUTTONDOWN)
	{
		INT X = LOWORD(LParam);
		INT Y = HIWORD(LParam);

		if (KeyDown(K_ControlHotkey))
		{
			if (ClientReady(TRUE) && Me->pInventory->pCursorItem)
			{
				INT nLoc = 0;
				LPUNITANY pCursor = Me->pInventory->pCursorItem;

				if (X > V_Design->GetScreenSizeX() / 2)
				{
					if (GetUIVar(UI_INVENTORY))
						nLoc = 5;

					if (GetUIVar(UI_STASH))
						nLoc = 4;

					if (GetUIVar(UI_CUBE))
						nLoc = 3;

					if (GetUIVar(UI_TRADE))
						nLoc = 2;

					if (GetUIVar(UI_NPCMENU))
						nLoc = 6;
				}

				if (!nLoc && !(GetUIVar(UI_STASH) || GetUIVar(UI_CUBE) || GetUIVar(UI_INVENTORY) || GetUIVar(UI_NPCMENU) || GetUIVar(UI_TRADE)))
					return TRUE;

				LPINVENTORYINFO pLoc = GetInventoryInfo(nLoc);

				if (!pLoc)
				{
					if (nLoc == 5)
						DropItem(pCursor->dwUnitId);

					if (nLoc == 6)
						SendClick(V_Design->GetScreenSizeX() / 4, V_Design->GetScreenSizeY() / 2);

					return FALSE;
				}

				INT nInventory[10][10] = {2};

				for (INT i = 0; i < 10; i++)
					for (INT j = 0; j < 10; j++)
						nInventory[i][j] = 2;

				for (LPUNITANY pItem = Me->pInventory->pFirstItem; pItem; pItem = pItem->pItemData->pNextInvItem)
				{
					if (pItem == pCursor)
						continue;

					if (GetItemLocation(pItem) == nLoc)
					{
						LPITEMTXT pTxt = D2COMMON_GetItemText(pItem->dwTxtFileNo);

						for (INT i = 0; i < pTxt->xSize; i++)
							for (INT j = 0; j < pTxt->ySize; j++)
								nInventory[pItem->pItemPath->dwPosX + i][pItem->pItemPath->dwPosY + j] = 1;
					}
				}

				for (INT i = 0; i < pLoc->nMaxXCells; i++)
					for (INT j = 0; j < pLoc->nMaxYCells; j++)
						if (nInventory[i][j] == 2)
							nInventory[i][j] = 0;

				LPITEMTXT pTxt = D2COMMON_GetItemText(pCursor->dwTxtFileNo);

				for (INT i = 0; i < pLoc->nMaxXCells; i++)
				{
					for (INT j = 0; j < pLoc->nMaxYCells; j++)
					{
						BOOL bWorks = TRUE;

						if (nInventory[i][j] == 1)
							continue;

						for (INT x = 0; x < pTxt->xSize; x++)
							for (INT y = 0; y < pTxt->ySize; y++)
								if (nInventory[i + x][j + y])
									bWorks = FALSE;

						if (!bWorks)
							continue;

						BYTE aPacket[17] = {0};
						aPacket[0] = 0x18;
						*(LPDWORD)&aPacket[1] = pCursor->dwUnitId;
						*(LPDWORD)&aPacket[5] = i;
						*(LPDWORD)&aPacket[9] = j;
						*(LPDWORD)&aPacket[13] = nLoc;
						D2NET_SendPacket(17, 1, aPacket);
						return FALSE;
					}
				}
			}
		}
	}

	return (LONG)CallWindowProcA(V_OldWndProc, HWnd, MSG, WParam, LParam);
}

LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HC_ACTION) {
		MSLLHOOKSTRUCT &msll = *(reinterpret_cast<MSLLHOOKSTRUCT*>(lParam));

		if (wParam == WM_LBUTTONDOWN) {
			POINT p;
			GetCursorPos(&p); 
			ScreenToClient(D2GFX_GetHwnd(), &p);
			/* We don't want this in here.
			if ((p.x > 800 || p.x < 1) || (p.y > 600 || p.y < 1))
			{
				ShowWindow(D2GFX_GetHwnd(), SW_MINIMIZE);
			}
			*/
			if (V_UnhookClick == TRUE) {
				return -1;
			}
		}
		if (wParam == WM_RBUTTONDOWN) {
			if (V_UnhookClick == TRUE) {
				return -1;
			}
		}
	}

	return CallNextHookEx(V_MiHook, nCode, wParam, lParam);
}

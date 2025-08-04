#include "Hack.h"

using namespace std;

static BOOL SelectedMenuObject;

static BOOL MenuNotice = FALSE;

static BOOL notifiedMenu = FALSE;

//Init
Design::Design()
{
	CharacterStats = FALSE;
	Hide = FALSE;
}

Design::~Design()
{
	V_Options = FALSE;
}

//
//Design Functions
BOOL Design::AutomapInfo()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (V_LevelNames && !Hide)
	{
		if (!V_Reveal->m_LevelExits.IsEmpty())
		{
			for (INT i = 0; i < V_Reveal->m_LevelExits.GetSize(); i++)
			{
				if (V_Reveal->m_LevelExits[i]->dwAct != Me->pAct->dwAct)
					continue;

				TextHook(V_Reveal->m_LevelExits[i]->ptPos.x, V_Reveal->m_LevelExits[i]->ptPos.y,
					V_LevelNamesFontColor, TRUE, 6, 1, V_Reveal->m_LevelExits[i]->szName);
			}
		}
	}

	CHAR Difficulty[50], LevelName[50], GameTimer[50], FPSText[50], SkipText[50], PingText[50], LocalTime[50], DayOfWeek[50], CharacterName[50], JapanTime[50];
	INT Y = 0, Seconds = (GetTickCount() - V_GameTimer) / 1000;
	LPGAMESTRUCTINFO Info = D2CLIENT_GetGameInfo();
	GetMapName((INT)GetUnitLevel(Me)->dwLevelNo, LevelName, 50);
	WORD JPHour;

	if (D2CLIENT_GetDifficulty() == 0)
		sprintf_s(Difficulty, "Normal");

	if (D2CLIENT_GetDifficulty() == 1)
		sprintf_s(Difficulty, "Nightmare");

	if (D2CLIENT_GetDifficulty() == 2)
		sprintf_s(Difficulty, "Hell");

	if (!Hide)
	{
		SYSTEMTIME Time;
		GetLocalTime(&Time);

		sprintf_s(GameTimer, "%.2d:%.2d:%.2d", (Seconds / 3600), ((Seconds / 60) % 60), (Seconds % 60));

		if (Time.wHour < 13 || Time.wHour > 23 && strlen(LocalTime) <= 0)
			sprintf_s(LocalTime, "%.2d:%.2d:%.2d AM", Time.wHour == 0 ? 12 : Time.wHour, Time.wMinute, Time.wSecond);
		else if (Time.wHour < 24 || Time.wHour > 12 && strlen(LocalTime) <= 0)
			sprintf_s(LocalTime, "%.2d:%.2d:%.2d PM", Time.wHour == 24 ? 12 : Time.wHour - 12, Time.wMinute, Time.wSecond);

		if (((Time.wMonth >= 10 && Time.wMonth <= 12) || (Time.wMonth >= 1 && Time.wMonth <= 2)) || (Time.wMonth == 11 && Time.wDay >= V_AutomapInfoDSTEnd) || (Time.wMonth == 3 && Time.wDay < V_AutomapInfoDSTStart))
		{
			if (Time.wHour == 0)
			{
				JPHour = 17;
			}
			if (Time.wHour == 1)
			{
				JPHour = 18;
			}
			if (Time.wHour == 2)
			{
				JPHour = 19;
			}
			if (Time.wHour == 3)
			{
				JPHour = 20;
			}
			if (Time.wHour == 4)
			{
				JPHour = 21;
			}
			if (Time.wHour == 5)
			{
				JPHour = 22;
			}
			if (Time.wHour == 6)
			{
				JPHour = 23;
			}
			if (Time.wHour == 7)
			{
				JPHour = 0;
			}
			if (Time.wHour == 8)
			{
				JPHour = 1;
			}
			if (Time.wHour == 9)
			{
				JPHour = 2;
			}
			if (Time.wHour == 10)
			{
				JPHour = 3;
			}
			if (Time.wHour == 11)
			{
				JPHour = 4;
			}
			if (Time.wHour == 12)
			{
				JPHour = 5;
			}
			if (Time.wHour == 13)
			{
				JPHour = 6;
			}
			if (Time.wHour == 14)
			{
				JPHour = 7;
			}
			if (Time.wHour == 15)
			{
				JPHour = 8;
			}
			if (Time.wHour == 16)
			{
				JPHour = 9;
			}
			if (Time.wHour == 17)
			{
				JPHour = 10;
			}
			if (Time.wHour == 18)
			{
				JPHour = 11;
			}
			if (Time.wHour == 19)
			{
				JPHour = 12;
			}
			if (Time.wHour == 20)
			{
				JPHour = 13;
			}
			if (Time.wHour == 21)
			{
				JPHour = 14;
			}
			if (Time.wHour == 22)
			{
				JPHour = 15;
			}
			if (Time.wHour == 23)
			{
				JPHour = 16;
			}
			if (Time.wHour == 24)
			{
				JPHour = 17;
			}
		}
		if((Time.wMonth <= 10 && Time.wMonth >= 4) || (Time.wMonth == 11 && Time.wDay < V_AutomapInfoDSTEnd) || (Time.wMonth == 3 && Time.wDay >= V_AutomapInfoDSTStart))
		{
			if (Time.wHour == 0)
			{
				JPHour = 16;
			}
			if (Time.wHour == 1)
			{
				JPHour = 17;
			}
			if (Time.wHour == 2)
			{
				JPHour = 18;
			}
			if (Time.wHour == 3)
			{
				JPHour = 19;
			}
			if (Time.wHour == 4)
			{
				JPHour = 20;
			}
			if (Time.wHour == 5)
			{
				JPHour = 21;
			}
			if (Time.wHour == 6)
			{
				JPHour = 22;
			}
			if (Time.wHour == 7)
			{
				JPHour = 23;
			}
			if (Time.wHour == 8)
			{
				JPHour = 0;
			}
			if (Time.wHour == 9)
			{
				JPHour = 1;
			}
			if (Time.wHour == 10)
			{
				JPHour = 2;
			}
			if (Time.wHour == 11)
			{
				JPHour = 3;
			}
			if (Time.wHour == 12)
			{
				JPHour = 4;
			}
			if (Time.wHour == 13)
			{
				JPHour = 5;
			}
			if (Time.wHour == 14)
			{
				JPHour = 6;
			}
			if (Time.wHour == 15)
			{
				JPHour = 7;
			}
			if (Time.wHour == 16)
			{
				JPHour = 8;
			}
			if (Time.wHour == 17)
			{
				JPHour = 9;
			}
			if (Time.wHour == 18)
			{
				JPHour = 10;
			}
			if (Time.wHour == 19)
			{
				JPHour = 11;
			}
			if (Time.wHour == 20)
			{
				JPHour = 12;
			}
			if (Time.wHour == 21)
			{
				JPHour = 13;
			}
			if (Time.wHour == 22)
			{
				JPHour = 14;
			}
			if (Time.wHour == 23)
			{
				JPHour = 15;
			}
			if (Time.wHour == 24)
			{
				JPHour = 16;
			}
		}

		if (V_AutomapInfoTimeZonePDT)
		{
			sprintf_s(JapanTime, "%.2d:%.2d:%.2d JP", JPHour, Time.wMinute, Time.wSecond);
		}

		if (Time.wDayOfWeek == 01)
			sprintf_s(DayOfWeek, "%.2d/%.2d/%.2d Mon", Time.wMonth, Time.wDay, Time.wYear);
		if (Time.wDayOfWeek == 02)
			sprintf_s(DayOfWeek, "%.2d/%.2d/%.2d Tue", Time.wMonth, Time.wDay, Time.wYear);
		if (Time.wDayOfWeek == 03)
			sprintf_s(DayOfWeek, "%.2d/%.2d/%.2d Wed", Time.wMonth, Time.wDay, Time.wYear);
		if (Time.wDayOfWeek == 04)
			sprintf_s(DayOfWeek, "%.2d/%.2d/%.2d Thu", Time.wMonth, Time.wDay, Time.wYear);
		if (Time.wDayOfWeek == 05)
			sprintf_s(DayOfWeek, "%.2d/%.2d/%.2d Fri", Time.wMonth, Time.wDay, Time.wYear);
		if (Time.wDayOfWeek == 06)
			sprintf_s(DayOfWeek, "%.2d/%.2d/%.2d Sat", Time.wMonth, Time.wDay, Time.wYear);
		if (Time.wDayOfWeek == 00)
			sprintf_s(DayOfWeek, "%.2d/%.2d/%.2d Sun", Time.wMonth, Time.wDay, Time.wYear);

		sprintf_s(FPSText, "%d", FPS);
		sprintf_s(SkipText, "%d", Skip);
		sprintf_s(PingText, "%d", Ping);

		if(V_Registered)
			V_RegistryNotice = 5;

		switch(V_RegistryNotice){
		case 0:
			sprintf_s(CharacterName, "ÿc1Unregistered");

			break;
		case 1:
			sprintf_s(CharacterName, "ÿc8Demo");

			break;
		case 2:
			sprintf_s(CharacterName, "ÿc9Customer Support");

			break;
		case 3:
			sprintf_s(CharacterName, "ÿc9Type ?help");

			break;
		case 4:
		case 5:
			if (!V_Expansion)
			{
				sprintf_s(CharacterName, "ÿc0(%d)%sÿc4[Lv.%d]", V_Rank, Me->pPlayerData->szName, GetUnitStat(Me, STAT_LEVEL));
			}
			else if (V_Expansion)
			{
				sprintf_s(CharacterName, "ÿc2(%d)%sÿc4[Lv.%d]", V_Rank, Me->pPlayerData->szName, GetUnitStat(Me, STAT_LEVEL));
			}

			break;
		}
	}

	AUTOMAP AutomapInfos[] =
	{
		{"%s", " ", 4, 1},
		{(Hide) ? "%s" : V_AutomapInfoLevelText, LevelName, Hide ? 4 : V_AutomapInfoLevelColor, Hide ? 1 : V_AutomapInfoLevelFont},
		{(Hide) ? "Game: %s" : V_AutomapInfoGameNameText, Info->szGameName, Hide ? 4 : V_AutomapInfoGameNameColor, Hide ? 1 : V_AutomapInfoGameNameFont},
		{(Hide) ? "Password: %s" : V_AutomapInfoGamePasswordText, Info->szGamePassword, Hide ? 4 : V_AutomapInfoGamePasswordColor, Hide ? 1 : V_AutomapInfoGamePasswordFont},
		{(Hide) ? "%s" : V_AutomapInfoDifficultyText, (Hide) ? "v 1.13" : Difficulty, Hide ? 4 : V_AutomapInfoDifficultyColor, Hide ? 1 : V_AutomapInfoDifficultyFont},
		{(Hide) ? "Difficulty: %s" : V_AutomapInfoIPText, (Hide) ? Difficulty : Info->szGameServerIp, Hide ? 4 : V_AutomapInfoIPColor, Hide ? 1 : V_AutomapInfoIPFont},
		{V_AutomapInfoGameTimerText, (Hide) ? "" : GameTimer, V_AutomapInfoGameTimerColor, Hide ? 1 : V_AutomapInfoGameTimerFont},
		{(Hide) ? "%s" : V_AutomapInfoLocalTimeText, (Hide) ? "EXPANSION" : LocalTime, Hide ? 4 : V_AutomapInfoLocalTimeColor, Hide ? 1 : V_AutomapInfoLocalTimeFont},
		{(Hide) ? "%s" : V_AutomapInfoJapanTimeText, (Hide) ? "EXPANSION" : JapanTime, Hide ? 4 : V_AutomapInfoJapanTimeColor, Hide ? 1 : V_AutomapInfoJapanTimeFont},
		{V_AutomapInfoDayOfWeekText, (Hide) ? "" : DayOfWeek, V_AutomapInfoDayOfWeekColor, Hide ? 1 : V_AutomapInfoDayOfWeekFont},
		{V_AutomapInfoFPSText, (Hide) ? "" : FPSText, V_AutomapInfoFPSColor, Hide ? 1 : V_AutomapInfoFPSFont},
		{V_AutomapInfoSkipText, (Hide) ? "" : SkipText, V_AutomapInfoSkipColor, Hide ? 1 : V_AutomapInfoSkipFont},
		{V_AutomapInfoPingText, (Hide) ? "" : PingText, V_AutomapInfoPingColor, Hide ? 1 : V_AutomapInfoPingFont},
		{V_AutomapInfoCharacterNameText, (Hide) ? "" : CharacterName, V_AutomapInfoCharacterNameColor, Hide ? 1 : V_AutomapInfoCharacterNameFont},
	};

	for (INT i = 0; i < ArraySize(AutomapInfos); i++)
	{
		if (strlen(AutomapInfos[i].Data) <= 0)
			continue;

		if (AutomapInfos[i].FontType > 13)
			AutomapInfos[i].FontType = 13;

		if (strlen(AutomapInfos[i].Message) > 0)
		{
			if (i == 0)
				Y += 8;
			else
				Y += 16;

			TextHook(*p_D2CLIENT_ScreenSizeX - 20, Y, AutomapInfos[i].FontColor, 0, AutomapInfos[i].FontType, 0, AutomapInfos[i].Message, AutomapInfos[i].Data);
		}
	}

	return TRUE;
}

BOOL Design::ClearScreen(INT Screen)
{
	BOOL Clear = TRUE;

	if((Screen == 0 || Screen == 3) && Clear)
		Clear = (!GetUIVar(UI_PARTY) && !GetUIVar(UI_MERC) && !GetUIVar(UI_CUBE) && !GetUIVar(UI_WPMENU) && !GetUIVar(UI_CHARACTER));

	if((Screen == 1 || Screen == 3) && Clear)
		Clear = (!GetUIVar(UI_INVENTORY) && !GetUIVar(UI_SKILL));

	if((Screen == 2 || Screen == 3) && Clear)
		Clear = (!GetUIVar(UI_NPCSHOP) && !GetUIVar(UI_STASH) && !GetUIVar(UI_MSGS) && !GetUIVar(UI_TRADE) && !GetUIVar(UI_MAINMENU) && !GetUIVar(UI_HELP));

	if (Screen == 4 && Clear)
		Clear = (!GetUIVar(UI_MAINMENU));

	return Clear;
}

BOOL Design::GameFilter()
{
	if (!V_GameFilter)
		return FALSE;

	if (V_FilterBox && (*p_D2MULTI_GameListControl))
	{
		wstringstream wFilterStream;
		wstring wFilterString = L"Game Filter: ";

		wFilterStream << (INT)(*p_D2MULTI_GameListControl)->dwSelectEnd;
		wFilterString += wFilterStream.str().c_str();
		wFilterString += L"/";
		wFilterStream.str(L"");
		wFilterStream << (INT)V_GameList.size();
		wFilterString += wFilterStream.str().c_str();

		DWORD dwOldSize = D2WIN_SetTextSize(1);
		D2WIN_DrawText_II(wFilterString.c_str(), 424, 179, 4, -1);
		D2WIN_SetTextSize(dwOldSize);
	}

	return TRUE;
}


BOOL Design::Missiles()
{
	if (!V_Design)
		return FALSE;

	if (Hide)
		return FALSE;

	if(!V_Missiles)
		return FALSE;

	if(!ClientReady(FALSE))
		return FALSE;

	for (LPROOM1 Room = Me->pAct->pRoom1; Room; Room = Room->pRoomNext)
	{
		for (LPUNITANY Unit = Room->pUnitFirst; Unit; Unit = Unit->pListNext)
		{
			if (Unit && Unit->dwType == UNIT_TYPE_MISSILE)
			{
				INT Color = 0;

				if (!Unit->dwOwnerId)
					continue;

				if (Unit->dwOwnerId == Me->dwUnitId)
					Color = V_MyColor;

				if (!Color && Unit->dwOwnerType == UNIT_TYPE_PLAYER)
				{
					DWORD Flags = GetPvPFlags(Unit->dwOwnerId);

					if (Flags & PVP_HOSTILED_YOU || Flags & PVP_HOSTILED_BY_YOU)
						Color = V_HostileColor;

					else if (Flags & PVP_ALLIED_WITH_YOU)
						Color = V_PartyColor;

					else
						Color = V_NeutralColor;
				}

				if (!Color && Unit->dwOwnerType == UNIT_TYPE_NPC)
				{
					DWORD Flags = GetPvPFlags(D2CLIENT_GetMonsterOwner(Unit->dwUnitId));

					if (Flags & PVP_HOSTILED_YOU || Flags & PVP_HOSTILED_BY_YOU)
						Color = V_HostileColor;

					else if (Flags & PVP_ALLIED_WITH_YOU)
						Color = V_PartyColor;

					else if (Flags & PVP_ALLIED)
						Color = V_NeutralColor;

					else
						Color = V_HostileColor;
				}

				if (Color)
					BoxHook(Unit->pPath->xPos - 3, Unit->pPath->yPos - 3, 2, 2, Color, 255, TRUE);
			}
		}
	}

	return TRUE;
}

BOOL Design::Monsters()
{
	if (!V_Design)
		return FALSE;

	if (Hide)
		return FALSE;

	if (!V_Monsters || !ClientReady(FALSE))
		return FALSE;

#ifndef LAZARUSMOD
	if ((!V_ToggleKeyItem[4][3] || V_HaveKeyItemExp4[4] != 7763) && !V_MonstersMap)
		return FALSE;
#endif

	for (LPROOM1 Room = Me->pAct->pRoom1; Room; Room = Room->pRoomNext)
	{
		for (LPUNITANY Unit = Room->pUnitFirst; Unit; Unit = Unit->pListNext)
		{
			if (!ValidMonsters(Unit))
				continue;

			if (Unit && Unit->dwType == UNIT_TYPE_NPC)
			{
				INT Color = -1;

				if (Unit->dwOwnerId == Me->dwUnitId)
					continue;

				if (Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp && Color == -1)
					Color = V_BossColor;

				else if (Unit->pMonsterData->fChamp & 1)
					Color = V_ChampionColor;

				else if (Unit->pMonsterData->fMinion & 1)
					Color = V_MinionColor;

				else
					Color = V_NormalColor;

				if (Color)
				{
					DrawCross(Unit->pPath->xPos, Unit->pPath->yPos, Color, 1);

					CHAR Text[50] = "";

					if (((V_MonsterResists && V_MonsterResistsPhysical) || V_MonstersMap) && (INT)GetUnitStat(Unit, STAT_DAMAGERESIST) >= 100)
						strcat_s(Text, "ÿc4i");

					if (((V_MonsterResists && V_MonsterResistsCold) || V_MonstersMap) && (INT)GetUnitStat(Unit, STAT_COLDRESIST) >= 100)
						strcat_s(Text, "ÿc3i");

					if (((V_MonsterResists && V_MonsterResistsFire) || V_MonstersMap) && (INT)GetUnitStat(Unit, STAT_FIRERESIST) >= 100)
						strcat_s(Text, "ÿc1i");

					if (((V_MonsterResists && V_MonsterResistsLightning) || V_MonstersMap) && (INT)GetUnitStat(Unit, STAT_LIGHTNINGRESIST) >= 100)
						strcat_s(Text, "ÿc9i");

					if (((V_MonsterResists && V_MonsterResistsPoison) || V_MonstersMap) && (INT)GetUnitStat(Unit, STAT_POISONRESIST) >= 100)
					{
						if (!V_PoisonResistGreen)
						{
							strcat_s(Text, "ÿc:i");
						}
						if (V_PoisonResistGreen)
						{
							strcat_s(Text, "ÿc2i");
						}
					}

					if (((V_MonsterResists && V_MonsterResistsMagic) || V_MonstersMap) && (INT)GetUnitStat(Unit, STAT_MAGICRESIST) >= 100)
						strcat_s(Text, "ÿc8i");

					if (((V_MonsterUnits && V_MonsterUnitsDevilkinShamans) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 58 && Unit->dwTxtFileNo <= 62) || (Unit->dwTxtFileNo >= 645 && Unit->dwTxtFileNo <= 647)))
						strcat_s(Text, "ÿc0S");

					if (((V_MonsterUnits && V_MonsterUnitsDamned) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 10 && Unit->dwTxtFileNo <= 14) || (Unit->dwTxtFileNo >= 580 && Unit->dwTxtFileNo <= 584)))
						strcat_s(Text, "ÿc0B");

					if (((V_MonsterUnits && V_MonsterUnitsUrdars) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 186 && Unit->dwTxtFileNo <= 189) || (Unit->dwTxtFileNo >= 618 && Unit->dwTxtFileNo <= 619)))
						strcat_s(Text, "ÿc0U");

					if (((V_MonsterUnits && V_MonsterUnitsVampires) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 131 && Unit->dwTxtFileNo <= 135) || (Unit->dwTxtFileNo >= 695 && Unit->dwTxtFileNo <= 697) || Unit->dwTxtFileNo == 731))
						strcat_s(Text, "ÿc0V");

					if (((V_MonsterUnits && V_MonsterUnitsFlayerShamans) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 278 && Unit->dwTxtFileNo <= 282) || (Unit->dwTxtFileNo >= 662 && Unit->dwTxtFileNo <= 664)))
						strcat_s(Text, "ÿc0F");

					if (((V_MonsterUnits && V_MonsterUnitsThornedHulks) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 127 && Unit->dwTxtFileNo <= 130) || Unit->dwTxtFileNo == 609))
						strcat_s(Text, "ÿc0H");

					if (((V_MonsterUnits && V_MonsterUnitsSouls) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 118 && Unit->dwTxtFileNo <= 121) || (Unit->dwTxtFileNo >= 639 && Unit->dwTxtFileNo <= 641) || Unit->dwTxtFileNo == 733))
						strcat_s(Text, "ÿc0L");

					if (((V_MonsterUnits && V_MonsterUnitsDolls) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 212 && Unit->dwTxtFileNo <= 216) || (Unit->dwTxtFileNo >= 690 && Unit->dwTxtFileNo <= 691)))
						strcat_s(Text, "ÿc0D");

					if (((V_MonsterUnits && V_MonsterUnitsPitLords) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 360 && Unit->dwTxtFileNo <= 362) || (Unit->dwTxtFileNo >= 686 && Unit->dwTxtFileNo <= 687) || Unit->dwTxtFileNo == 712))
						strcat_s(Text, "ÿc0P");

					if (((V_MonsterUnits && V_MonsterUnitsKnights) || V_MonstersMapExt) && Unit->dwTxtFileNo == 311)
						strcat_s(Text, "ÿc0K");

					if (((V_MonsterUnits && V_MonsterUnitsOblivions) || V_MonstersMapExt) && (Unit->dwTxtFileNo == 312 || (Unit->dwTxtFileNo >= 701 && Unit->dwTxtFileNo <= 702)))
						strcat_s(Text, "ÿc0O");

					if (((V_MonsterUnits && V_MonsterUnitsMoonLords) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 506 && Unit->dwTxtFileNo <= 510) || (Unit->dwTxtFileNo >= 652 && Unit->dwTxtFileNo <= 653)))
						strcat_s(Text, "ÿc0M");

					if (((V_MonsterUnits && V_MonsterUnitsUnravelers) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 101 && Unit->dwTxtFileNo <= 105) || (Unit->dwTxtFileNo >= 667 && Unit->dwTxtFileNo <= 670)))
						strcat_s(Text, "ÿc0A");

					if (((V_MonsterUnits && V_MonsterUnitsSuicideMinions) || V_MonstersMapExt) && (Unit->dwTxtFileNo >= 461 && Unit->dwTxtFileNo <= 468))
						strcat_s(Text, "ÿc0X");

					if (((V_MonsterUnits && V_MonsterUnitsSuccubusWitches) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 474 && Unit->dwTxtFileNo <= 478) || (Unit->dwTxtFileNo >= 636 && Unit->dwTxtFileNo <= 638) || Unit->dwTxtFileNo == 720))
						strcat_s(Text, "ÿc0W");

					if (((V_MonsterUnits && V_MonsterUnitsSnakes) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 73 && Unit->dwTxtFileNo <= 77) || (Unit->dwTxtFileNo >= 594 && Unit->dwTxtFileNo <= 598)))
						strcat_s(Text, "ÿc0C");

					if (((V_MonsterUnits && V_MonsterUnitsUndeadCharger) || V_MonstersMapExt) && ((Unit->dwTxtFileNo >= 436 && Unit->dwTxtFileNo <= 440) || Unit->dwTxtFileNo == 698))
						strcat_s(Text, "ÿc0R");

					if (((V_MonsterEnchantments && V_MonsterEnchantmentsMight) || V_MonstersMap) && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1 && GetUnitState(Unit, AFFECT_MIGHT))
						strcat_s(Text, "ÿc27");

					if (((V_MonsterEnchantments && V_MonsterEnchantmentsFanaticism) || V_MonstersMap) && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1 && GetUnitState(Unit, AFFECT_FANATICISM))
						strcat_s(Text, "ÿc29");

					if (((V_MonsterEnchantments && V_MonsterEnchantmentsBlessedAim) || V_MonstersMap) && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1 && GetUnitState(Unit, AFFECT_BLESSEDAIM))
						strcat_s(Text, "ÿc25");

					if (((V_MonsterEnchantments && V_MonsterEnchantmentsConviction) || V_MonstersMap) && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1 && GetUnitState(Unit, AFFECT_CONVICTION))
						strcat_s(Text, "ÿc20");

					if (((V_MonsterEnchantments && V_MonsterEnchantmentsHolyShock) || V_MonstersMap) && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1 && GetUnitState(Unit, AFFECT_HOLYSHOCK))
						strcat_s(Text, "ÿc22");

					if (((V_MonsterEnchantments && V_MonsterEnchantmentsHolyFreeze) || V_MonstersMap) && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1 && GetUnitState(Unit, AFFECT_HOLYFREEZE))
						strcat_s(Text, "ÿc23");

					if (((V_MonsterEnchantments && V_MonsterEnchantmentsHolyFire) || V_MonstersMap) && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1 && GetUnitState(Unit, AFFECT_HOLYFIRE))
						strcat_s(Text, "ÿc21");

					if (strlen(Text) > 0)
						TextHook(Unit->pPath->xPos - 5, Unit->pPath->yPos, 0, 1, 6, 1, Text);

					if (V_MonsterNames && Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp & 1)
					{
						WCHAR * MonsterName = (WCHAR *)GetUnitName(Unit);
						CHAR Name[50];

						WideCharToMultiByte(CP_ACP, 0, MonsterName, -1, Name, (INT)sizeof(Name), 0, 0);
						TextHook(Unit->pPath->xPos - 8, Unit->pPath->yPos - 8, V_BossNameColor, 1, 6, 1, Name);
					}
				}
			}
		}
	}

	return TRUE;
}

BOOL Design::Mouse()
{
	if (!ClientReady(FALSE) || !V_Mouse)
		return FALSE;

	Rectangle(*p_D2CLIENT_MouseX, *p_D2CLIENT_MouseY, 40, 50, 0, 1);
	DrawOut(*p_D2CLIENT_MouseX, *p_D2CLIENT_MouseY + 35, 0, 6, "X: %d", *p_D2CLIENT_MouseX);
	DrawOut(*p_D2CLIENT_MouseX, *p_D2CLIENT_MouseY + 45, 0, 6, "Y: %d", *p_D2CLIENT_MouseY);

	return TRUE;
}

BOOL Design::Options()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (!V_Options)
		return FALSE;

	if (GetUIVar(UI_MSGS) || GetUIVar(UI_CHARACTER) || GetUIVar(UI_SKILL) || GetUIVar(UI_INVENTORY) || GetUIVar(UI_MAINMENU))
		if (V_Options)
			V_Options = FALSE;

	Rectangle(25, 10, 750, 495, 0, 1);
	Rectangle(25, 30, 750, 0, 0, 1);
	Rectangle(25, 495, 750, 0, 0, 1);

	DrawOutCenter(400, 26, V_OptionTitleColor, V_OptionTitleFont, 1, "Options");
	DrawOutCenter(400, 498, V_OptionCloseColor, V_OptionCloseFont, 1, "Close");

	if (V_LifeTownPercent > 0)
		DrawOut(26, 45, V_OptionVariableColor, V_OptionVariableFont, "Town Life: %d%%", V_LifeTownPercent);
	else
		DrawOut(26, 45, V_OptionVariableColor, V_OptionVariableFont, "Town Life: Off");

	if (V_LifeExitPercent > 0)
		DrawOut(26, 60, V_OptionVariableColor, V_OptionVariableFont, "Exit Life: %d%%", V_LifeExitPercent);
	else
		DrawOut(26, 60, V_OptionVariableColor, V_OptionVariableFont, "Exit Life: Off");

	if (V_ManaTownPercent > 0)
		DrawOut(26, 75, V_OptionVariableColor, V_OptionVariableFont, "Town Mana: %d%%", V_ManaTownPercent);
	else
		DrawOut(26, 75, V_OptionVariableColor, V_OptionVariableFont, "Town Mana: Off");

	if (V_ManaExitPercent > 0)
		DrawOut(26, 90, V_OptionVariableColor, V_OptionVariableFont, "Exit Mana: %d%%", V_ManaExitPercent);
	else
		DrawOut(26, 90, V_OptionVariableColor, V_OptionVariableFont, "Exit Mana: Off");

	if (V_LifePotPercent > 0)
		DrawOut(26, 125, V_OptionVariableColor, V_OptionVariableFont, "Life Potion: %d%%", V_LifePotPercent);
	else
		DrawOut(26, 125, V_OptionVariableColor, V_OptionVariableFont, "Life Potion: Off");

	if (V_ManaPotPercent > 0)
		DrawOut(26, 140, V_OptionVariableColor, V_OptionVariableFont, "Mana Potion: %d%%", V_ManaPotPercent);
	else
		DrawOut(26, 140, V_OptionVariableColor, V_OptionVariableFont, "Mana Potion: Off");

	if (V_LifeJuvPercent > 0)
		DrawOut(26, 155, V_OptionVariableColor, V_OptionVariableFont, "Life Rejuvenation: %d%%", V_LifeJuvPercent);
	else
		DrawOut(26, 155, V_OptionVariableColor, V_OptionVariableFont, "Life Rejuvenation: Off");

	if (V_ManaJuvPercent > 0)
		DrawOut(26, 170, V_OptionVariableColor, V_OptionVariableFont, "Mana Rejuvenation: %d%%", V_ManaJuvPercent);
	else
		DrawOut(26, 170, V_OptionVariableColor, V_OptionVariableFont, "Mana Rejuvenation: Off");

	if (V_Aim > 0)
		DrawOut(26, 205, V_OptionVariableColor, V_OptionVariableFont, "Aim: On");
	else
		DrawOut(26, 205, V_OptionVariableColor, V_OptionVariableFont, "Aim: Off");

	if (V_BlockFakes > 0)
		DrawOut(26, 220, V_OptionVariableColor, V_OptionVariableFont, "Block Fakes: On");
	else
		DrawOut(26, 220, V_OptionVariableColor, V_OptionVariableFont, "Block Fakes: Off");

	if (V_Blind >= 1 && V_Blind <= 4)
		DrawOut(26, 235, V_OptionVariableColor, V_OptionVariableFont, "Aim Type: Blind %d", V_Blind);
	else if (V_Blind == 0)
		DrawOut(26, 235, V_OptionVariableColor, V_OptionVariableFont, "Aim Type: Normal");
	else if (V_Blind == 5)
		DrawOut(26, 235, V_OptionVariableColor, V_OptionVariableFont, "Aim Type: Click");

	if (V_Screenshot)
		DrawOut(26, 270, V_OptionVariableColor, V_OptionVariableFont, "Clean Screenshots");
	else
		DrawOut(26, 270, V_OptionVariableColor, V_OptionVariableFont, "Dirty Screenshots");

	if (V_Orbs)
		DrawOut(26, 285, V_OptionVariableColor, V_OptionVariableFont, "Orbs: On");
	else
		DrawOut(26, 285, V_OptionVariableColor, V_OptionVariableFont, "Orbs: Off");

	if (V_Mouse)
		DrawOut(26, 300, V_OptionVariableColor, V_OptionVariableFont, "Mouse: On");
	else
		DrawOut(26, 300, V_OptionVariableColor, V_OptionVariableFont, "Mouse: Off");

	if (V_PlayerLifePercent)
		DrawOut(26, 315, V_OptionVariableColor, V_OptionVariableFont, "Life %%: On");
	else
		DrawOut(26, 315, V_OptionVariableColor, V_OptionVariableFont, "Life %%: Off");

	if (V_PlayerLifeBar)
		DrawOut(26, 330, V_OptionVariableColor, V_OptionVariableFont, "Life Bar: On");
	else
		DrawOut(26, 330, V_OptionVariableColor, V_OptionVariableFont, "Life Bar: Off");

	if (V_Vectors)
		DrawOut(26, 345, V_OptionVariableColor, V_OptionVariableFont, "Vectors: On");
	else
		DrawOut(26, 345, V_OptionVariableColor, V_OptionVariableFont, "Vectors: Off");

	if (V_ExpInfo)
		DrawOut(26, 360, V_OptionVariableColor, V_OptionVariableFont, "Experience Info: On");
	else
		DrawOut(26, 360, V_OptionVariableColor, V_OptionVariableFont, "Experience Info: Off");

	if (V_StateList)
		DrawOut(26, 375, V_OptionVariableColor, V_OptionVariableFont, "State List: On");
	else
		DrawOut(26, 375, V_OptionVariableColor, V_OptionVariableFont, "State List: Off");

	if (V_Supplies)
		DrawOut(26, 390, V_OptionVariableColor, V_OptionVariableFont, "Supplies: On");
	else
		DrawOut(26, 390, V_OptionVariableColor, V_OptionVariableFont, "Supplies: Off");

	if (V_MusicPlayer)
		DrawOut(26, 405, V_OptionVariableColor, V_OptionVariableFont, "Music Player: On");
	else
		DrawOut(26, 405, V_OptionVariableColor, V_OptionVariableFont, "Music Player: Off");

	if (V_TargetInfo)
		DrawOut(26, 420, V_OptionVariableColor, V_OptionVariableFont, "Target Info: On");
	else
		DrawOut(26, 420, V_OptionVariableColor, V_OptionVariableFont, "Target Info: Off");

	if (V_TargetList)
		DrawOut(26, 435, V_OptionVariableColor, V_OptionVariableFont, "Target List: On");
	else
		DrawOut(26, 435, V_OptionVariableColor, V_OptionVariableFont, "Target List: Off");

	if (V_EscapeInfo)
		DrawOut(26, 450, V_OptionVariableColor, V_OptionVariableFont, "Escape Info: On");
	else
		DrawOut(26, 450, V_OptionVariableColor, V_OptionVariableFont, "Escape Info: Off");

	if (V_PotionInfo)
		DrawOut(26, 465, V_OptionVariableColor, V_OptionVariableFont, "Potion Info: On");
	else
		DrawOut(26, 465, V_OptionVariableColor, V_OptionVariableFont, "Potion Info: Off");

	if (V_Gold)
		DrawOut(26, 480, V_OptionVariableColor, V_OptionVariableFont, "Gold Info: On");
	else
		DrawOut(26, 480, V_OptionVariableColor, V_OptionVariableFont, "Gold Info: Off");

	if (V_DeathMessage)
		DrawOutCenter(400, 45, V_OptionVariableColor, V_OptionVariableFont, 1, "Death Message: On");
	else
		DrawOutCenter(400, 45, V_OptionVariableColor, V_OptionVariableFont, 1, "Death Message: Off");

	DrawOutCenter(400, 60, V_OptionVariableColor, V_OptionVariableFont, 1, "Death Message Delay: %d", V_DeathMessageDelay);

	if (V_Enchant)
		DrawOutCenter(400, 125, V_OptionVariableColor, V_OptionVariableFont, 1, "Enchant Bot: On");
	else
		DrawOutCenter(400, 125, V_OptionVariableColor, V_OptionVariableFont, 1, "Enchant Bot: Off");

	if (V_EnchantNote)
		DrawOutCenter(400, 140, V_OptionVariableColor, V_OptionVariableFont, 1, "Enchant Note: On");
	else
		DrawOutCenter(400, 140, V_OptionVariableColor, V_OptionVariableFont, 1, "Enchant Note: Off");

	if (V_AntiFlash)
		DrawOutCenter(400, 205, V_OptionVariableColor, V_OptionVariableFont, 1, "Anti Flash: On");
	else
		DrawOutCenter(400, 205, V_OptionVariableColor, V_OptionVariableFont, 1, "Anti Flash: Off");

	DrawOutCenter(400, 220, V_OptionVariableColor, V_OptionVariableFont, 1, "Flash Delay: %d", V_FlashDelay);

	if (V_AntiQuestBox)
		DrawOutCenter(400, 270, V_OptionVariableColor, V_OptionVariableFont, 1, "Anti Quest Box: On");
	else
		DrawOutCenter(400, 270, V_OptionVariableColor, V_OptionVariableFont, 1, "Anti Quest Box: Off");

	if (V_CopyPaste)
		DrawOutCenter(400, 285, V_OptionVariableColor, V_OptionVariableFont, 1, "Copy & Paste: On");
	else
		DrawOutCenter(400, 285, V_OptionVariableColor, V_OptionVariableFont, 1, "Copy & Paste: Off");

	if (V_KillLog)
		DrawOutCenter(400, 300, V_OptionVariableColor, V_OptionVariableFont, 1, "Kill Log: On");
	else
		DrawOutCenter(400, 300, V_OptionVariableColor, V_OptionVariableFont, 1, "Kill Log: Off");

	if (V_ModifiedJoinMessage)
		DrawOutCenter(400, 315, V_OptionVariableColor, V_OptionVariableFont, 1, "Modified Join Message: On");
	else
		DrawOutCenter(400, 315, V_OptionVariableColor, V_OptionVariableFont, 1, "Modified Join Message: Off");

	if (V_OutTownSelect)
		DrawOutCenter(400, 330, V_OptionVariableColor, V_OptionVariableFont, 1, "Select Non-Hostile Players Out Of Town: On");
	else
		DrawOutCenter(400, 330, V_OptionVariableColor, V_OptionVariableFont, 1, "Select Non-Hostile Players Out Of Town: Off");

	if (V_AutomapOnJoin)
		DrawOutCenter(400, 345, V_OptionVariableColor, V_OptionVariableFont, 1, "Start Game With Automap: On");
	else
		DrawOutCenter(400, 345, V_OptionVariableColor, V_OptionVariableFont, 1, "Start Game With Automap: Off");

	if (V_RememberGameName)
		DrawOutCenter(400, 360, V_OptionVariableColor, V_OptionVariableFont, 1, "Remember Game Name: On");
	else
		DrawOutCenter(400, 360, V_OptionVariableColor, V_OptionVariableFont, 1, "Remember Game Name: Off");

	if (V_RememberGamePassword)
		DrawOutCenter(400, 375, V_OptionVariableColor, V_OptionVariableFont, 1, "Remember Game Password: On");
	else
		DrawOutCenter(400, 375, V_OptionVariableColor, V_OptionVariableFont, 1, "Remember Game Password: Off");

	DrawOutCenter(400, 410, V_OptionVariableColor, V_OptionVariableFont, 1, "Play");
	DrawOutCenter(400, 425, V_OptionVariableColor, V_OptionVariableFont, 1, "Pause");
	DrawOutCenter(400, 440, V_OptionVariableColor, V_OptionVariableFont, 1, "Stop");
	DrawOutCenter(400, 455, V_OptionVariableColor, V_OptionVariableFont, 1, "Next");
	DrawOutCenter(400, 470, V_OptionVariableColor, V_OptionVariableFont, 1, "Previous");

	if (V_Potion)
		TextHook(768, 45, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Potion Notifications: On");
	else
		TextHook(768, 45, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Potion Notifications: Off");

	if (V_Quests)
		TextHook(768, 60, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Quest Notifications: On");
	else
		TextHook(768, 60, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Quest Notifications: Off");

	if (V_LifePot)
		TextHook(768, 75, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Life Potion Notifications: On");
	else
		TextHook(768, 75, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Life Potion Notifications: Off");

	if (V_ManaPot)
		TextHook(768, 90, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Mana Potion Notifications: On");
	else
		TextHook(768, 90, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Mana Potion Notifications: Off");

	if (V_LifeJuv)
		TextHook(768, 105, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Life Rejuv. Notifications: On");
	else
		TextHook(768, 105, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Life Rejuv. Notifications: Off");

	if (V_ManaJuv)
		TextHook(768, 120, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Mana Rejuv. Notifications: On");
	else
		TextHook(768, 120, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Mana Rejuv. Notifications: Off");

	if (V_AntiShake)
		TextHook(768, 155, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Anti Shake: On");
	else
		TextHook(768, 155, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Anti Shake: Off");

	if (V_AntiWeather)
		TextHook(768, 170, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Anti Weather: On");
	else
		TextHook(768, 170, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Anti Weather: Off");

	if (V_AutoRevealAutomap)
		TextHook(768, 185, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Automatically Reveal Act: On");
	else
		TextHook(768, 185, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Automatically Reveal Act: Off");

	if (V_Ethereal)
		TextHook(768, 200, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Ethereal Items: On");
	else
		TextHook(768, 200, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Ethereal Items: Off");

	if (V_FullLightRadius)
		TextHook(768, 215, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Full Light Radius: On");
	else
		TextHook(768, 215, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Full Light Radius: Off");

	if (V_ItemLevel)
		TextHook(768, 230, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Item Level: On");
	else
		TextHook(768, 230, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Item Level: Off");

	if (V_ProtectItemSocket)
		TextHook(768, 245, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Item Socket Protection: On");
	else
		TextHook(768, 245, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Item Socket Protection: Off");

	if (V_Sockets)
		TextHook(768, 260, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Item Sockets: On");
	else
		TextHook(768, 260, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Item Sockets: Off");

	if (V_LevelNames)
		TextHook(768, 275, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Level Names: On");
	else
		TextHook(768, 275, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Level Names: Off");

	if (V_ShrineImages)
		TextHook(768, 290, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Shrine Images: On");
	else
		TextHook(768, 290, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Shrine Images: Off");

	if (V_ViewItemBasicStats)
		TextHook(768, 305, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Basic Stats Of Items: On");
	else
		TextHook(768, 305, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Basic Stats Of Items: Off");

	if (V_Missiles)
		TextHook(768, 320, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Missiles: On");
	else
		TextHook(768, 320, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Missiles: Off");

	if (V_Monsters)
		TextHook(768, 335, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Monsters: On");
	else
		TextHook(768, 335, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Monsters: Off");

	if (V_MonsterResists)
		TextHook(768, 350, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Monster Resists: On");
	else
		TextHook(768, 350, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Monster Resists: Off");

	if (V_MonsterNames)
		TextHook(768, 365, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Boss Monster Names: On");
	else
		TextHook(768, 365, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Boss Monster Names: Off");

	if (V_SpeedAttack)
		TextHook(768, 400, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Attack Speed: On");
	else
		TextHook(768, 400, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Attack Speed: Off");

	if (V_SpeedCast)
		TextHook(768, 415, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Cast Rate: On");
	else
		TextHook(768, 415, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Cast Rate: Off");

	if (V_FastTeleport)
		TextHook(768, 450, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Fast Teleport: On");
	else
		TextHook(768, 450, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Fast Teleport: Off");

	if (V_FarcastTeleport)
		TextHook(768, 465, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Farcast Teleport: On");
	else
		TextHook(768, 465, V_OptionVariableColor, 0, V_OptionVariableFont, 0, "Farcast Teleport: Off");

	return TRUE;
}

BOOL Design::Orbs()
{
	if (!ClientReady(FALSE))
		return FALSE;

	LONG LifePercent = CalcPercent((GetUnitStat(Me, STAT_HP) >> 8), (GetUnitStat(Me, STAT_MAXHP) >> 8));
	LONG ManaPercent = CalcPercent((GetUnitStat(Me, STAT_MANA) >> 8), (GetUnitStat(Me, STAT_MAXMANA) >> 8));

	if (Hide || !V_Orbs)
		return FALSE;

	if (!V_Orbs)
		return FALSE;

	Rectangle(49, *p_D2CLIENT_ScreenSizeY - 65, 42, 18, 0, 4);
	Rectangle(*p_D2CLIENT_ScreenSizeX - 92, *p_D2CLIENT_ScreenSizeY - 65, 42, 18, 0, 4);

	TextHook(67, *p_D2CLIENT_ScreenSizeY - 50, V_LifeOrbColor, 0, V_LifeOrbFont, 1, "%d%%", LifePercent);
	TextHook(*p_D2CLIENT_ScreenSizeX - 74, *p_D2CLIENT_ScreenSizeY - 50, V_ManaOrbColor, 0, V_ManaOrbFont, 1, "%d%%", ManaPercent);

	return TRUE;
}

BOOL Design::PlayerLifePercent()
{
	if (V_LegitMode)
		return FALSE;

	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (V_Players.IsEmpty())
		return FALSE;

	V_Players.Lock();

	for (INT i = 0; i < V_Players.GetSize(); i++)
	{
		LPUNITANY Unit = (LPUNITANY)GetUnit(V_Players[i]->UnitId, UNIT_TYPE_PLAYER);

		if (Unit && ClearScreen(3) && !GetUIVar(UI_CUBE))
		{
			INT Color = 2, LifeBar = (INT)V_Players[i]->Life / 5, LifeBarColor = 0x7A;

			if ((INT)V_Players[i]->Life > 100)
				V_Players[i]->Life = 100;

			if (V_Players[i]->Life < 50 && V_Players[i]->Life >= 25)
			{
				Color = 8;
				LifeBarColor = 0x60;
			}

			if (V_Players[i]->Life < 25)
			{
				Color = 1;
				LifeBarColor = 0x62;
			}

			if (Color && V_PlayerLifePercent)
				TextHook(Unit->pPath->xPos + 8, Unit->pPath->yPos + 8, Color, 1, 6, 1, "%d%%", V_Players[i]->Life);

			if (LifeBarColor && V_PlayerLifeBar)
			{
				if (V_PlayerLifePercent)
				{
					BoxHook(Unit->pPath->xPos + 6, Unit->pPath->yPos + 11, 20, 3, 0x00, 255, TRUE);
					BoxHook(Unit->pPath->xPos + 6, Unit->pPath->yPos + 11, LifeBar, 3, LifeBarColor, 255, TRUE);
				}

				else
				{
					BoxHook(Unit->pPath->xPos + 1, Unit->pPath->yPos + 7, 20, 3, 0x00, 255, TRUE);
					BoxHook(Unit->pPath->xPos + 1, Unit->pPath->yPos + 7, LifeBar, 3, LifeBarColor, 255, TRUE);
				}
			}
		}
	}

	V_Players.Unlock();
	return TRUE;
}

BOOL Design::Vectors()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if((!V_ToggleKeyItem[3][3] || V_HaveKeyItemExp4[3] != 2123) && !V_VectorsMap)
		return FALSE;

	POINT Player, Position, Last = {0, 0};
	INT Colors[] = {V_NextLevelVectorColor, V_PreviousLevelVectorColor, V_QuestVectorColor, V_WaypointVectorColor, V_SealVectorColor, V_SealVectorColor, V_SealVectorColor, V_SealVectorColor, V_SealVectorColor};
	ScreenToAutomap(&Player, Me->pPath->xPos * 32, Me->pPath->yPos * 32);

	if (!V_Players.IsEmpty())
	{
		LPUNITANY Unit = (LPUNITANY)GetUnit(V_Players[V_Target]->UnitId, UNIT_TYPE_PLAYER);

		if (Unit)
		{
			if (V_TargetVector)
			{
				ScreenToAutomap(&Position, Unit->pPath->xPos * 32, Unit->pPath->yPos * 32);
				D2GFX_DrawLine(Player.x, Player.y, Position.x, Position.y, V_TargetVectorColor, -1);
			}

			if (V_TargetClick)
				DrawCross(Unit->pPath->xTarget, Unit->pPath->yTarget, V_TargetClickColor, TRUE);
		}
	}

	if (!V_TeleportQueue.IsEmpty())
		TextHook(GetScreenSizeX() / 2, (GetScreenSizeY() - 48) / 2, 5, 0, 8, 1, "Teleporting...");

	if (V_Vectors)
	{
		if (!V_CurrentVectors.IsEmpty())
		{
			V_CurrentVectors.Lock();

			for (INT i = 0; i < V_CurrentVectors.GetSize(); i++)
			{
				ScreenToAutomap(&Position, V_CurrentVectors[i]->Position.x, V_CurrentVectors[i]->Position.y);
				D2GFX_DrawLine(Player.x, Player.y, Position.x, Position.y, Colors[V_CurrentVectors[i]->Type - 1], -1);
				DrawCross(Position.x, Position.y, Colors[V_CurrentVectors[i]->Type - 1], FALSE);
			}

			V_CurrentVectors.Unlock();
		}

		if (!V_TeleportQueue.IsEmpty())
		{
			for (INT i = 0; i < V_TeleportQueue.GetSize(); i++)
			{
				POINT Calculation = {V_TeleportQueue[i].x, V_TeleportQueue[i].y};

				MapToScreenCoords(&Calculation);
				ScreenToAutomapRelative(&Position, Calculation.x, Calculation.y);
				DrawCross(Position.x, Position.y, V_ActiveVectorColor, FALSE);

				if (Last.x && Last.y)
					D2GFX_DrawLine(Last.x, Last.y, Position.x, Position.y, V_ActiveVectorColor, -1);
				else
					D2GFX_DrawLine(Player.x, Player.y, Position.x, Position.y, V_ActiveVectorColor, -1);

				Last.x = Position.x;
				Last.y = Position.y;
			}
		}
	}

	return TRUE;
}

//
//Design Information
BOOL Design::ExperienceInfo()
{
	if (!ClientReady(FALSE))
		return FALSE;

	INT LevelExperience = GetExp(GetUnitStat(Me, STAT_LEVEL)) - GetExp(GetUnitStat(Me, STAT_LEVEL) - 1);
	INT PlayerExperience = GetUnitStat(Me, STAT_EXP) - GetExp(GetUnitStat(Me, STAT_LEVEL) - 1);
	INT GainedExperience = GetUnitStat(Me, STAT_EXP) - V_StartingExperience;
	INT DisplayType;
	INT LadderExp;

	if (!V_StartingExperience)
		V_StartingExperience = GetUnitStat(Me, STAT_EXP);

	if (GetUnitStat(Me, STAT_EXP) > 999999999)
	{
		DisplayType = 2;
		LadderExp = GetUnitStat(Me, STAT_EXP) / 1000000;
	}
	if (GetUnitStat(Me, STAT_EXP) > 999999 && GetUnitStat(Me, STAT_EXP) < 1000000000)
	{
		DisplayType = 1;
		LadderExp = GetUnitStat(Me, STAT_EXP) / 1000;
	}
	if (GetUnitStat(Me, STAT_EXP) <= 999999)
	{
		DisplayType = 0;
	}
	if (GainedExperience > 3520485254)
	{
		GainedExperience = 0;
	}

	if (Hide)
		return FALSE;

	if (CharacterStats || !V_ExpInfo || V_Options || !ClearScreen(3))
		return FALSE;

	if(!V_ToggleKeyItem[1][1] || V_HaveKeyItemExp2[1] != 987)
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	if (V_ToggleMenu)
		return FALSE;

	Rectangle(V_ExpInfoX, V_ExpInfoY, 122, 72, 0, 1);
	DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 12, V_ExpInfoTitleColor, 6, 1, "Experience");

	DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 27, 3, 6, 1, "Levelÿc0: %d ÿc3Exp.ÿc0: %d%%", GetUnitStat(Me, STAT_LEVEL), CalcPercent(PlayerExperience, LevelExperience));
	DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 37, 3, 6, 1, "Currentÿc0: %s", AddCommas(GetUnitStat(Me, STAT_EXP), 0));
	DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 47, 3, 6, 1, "Neededÿc0: %s", AddCommas(GetExp(GetUnitStat(Me, STAT_LEVEL)) - GetUnitStat(Me, STAT_EXP), 0));
	DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 57, 3, 6, 1, "Gainedÿc0: %s", AddCommas(GainedExperience, 0));
	if (DisplayType == 0)
	{
		DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 67, 3, 6, 1, "Ladderÿc0: %s", AddCommas(GetUnitStat(Me, STAT_EXP), 0));
	}
	if (DisplayType == 1)
	{
		DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 67, 3, 6, 1, "Ladderÿc0: %sK", AddCommas(LadderExp, 0));
	}
	if (DisplayType == 2)
	{
		DrawOutCenter(V_ExpInfoX + 61, V_ExpInfoY + 67, 3, 6, 1, "Ladderÿc0: %sM", AddCommas(LadderExp, 0));
	}

	return TRUE;
}

BOOL Design::States()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (CharacterStats || !V_StateList || V_Options || !ClearScreen(3))
		return FALSE;

	if(!V_ToggleKeyItem[2][1] || V_HaveKeyItemExp2[2] != 4702)
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	if (V_ToggleMenu)
		return FALSE;

	STATE States [] =
	{
		{"Amplify Damageÿc0: %d", AFFECT_AMPLIFYDAMAGE, (GetTickCount() - V_AmplifyDamageTimer) / 1000},
		{"Battle Commandÿc0: %d", AFFECT_BATTLECOMMAND, (GetTickCount() - V_BattleCommandTimer) / 1000},
		{"Battle Cryÿc0: %d", AFFECT_BATTLECRY, (GetTickCount() - V_BattleCryTimer) / 1000},
		{"Battle Ordersÿc0: %d", AFFECT_BATTLEORDERS, (GetTickCount() - V_BattleOrdersTimer) / 1000},
		{"Bone Armorÿc0: %d", AFFECT_BONEARMOR, (GetTickCount() - V_BoneArmorTimer) / 1000},
		{"Burst of Speedÿc0: %d", AFFECT_BURSTOFSPEED, (GetTickCount() - V_BurstOfSpeedTimer) / 1000},
		{"Chilling Armorÿc0: %d", AFFECT_CHILLINGARMOR, (GetTickCount() - V_ChillingArmorTimer) / 1000},
		{"Coldÿc0: %d", AFFECT_COLD, (GetTickCount() - V_ColdTimer) / 1000},
		{"Convictedÿc0: %d", AFFECT_CONVICTED, (GetTickCount() - V_ConvictedTimer) / 1000},
		{"Cyclone Armorÿc0: %d", AFFECT_CYCLONEARMOR, (GetTickCount() - V_CycloneArmorTimer) / 1000},
		{"Decrepifyÿc0: %d", AFFECT_DECREPIFY, (GetTickCount() - V_DecrepifyTimer) / 1000},
		{"Enchantÿc0: %d", AFFECT_ENCHANT, (GetTickCount() - V_EnchantTimer) / 1000},
		{"Energy Shieldÿc0: %d", AFFECT_ENERGYSHIELD, (GetTickCount() - V_EnergyShieldTimer) / 1000},
		{"Fadeÿc0: %d", AFFECT_FADE, (GetTickCount() - V_FadeTimer) / 1000},
		{"Frozenÿc0: %d", AFFECT_FREEZE, (GetTickCount() - V_FrozenTimer) / 1000},
		{"Frozen Armorÿc0: %d", AFFECT_FROZENARMOR, (GetTickCount() - V_FrozenArmorTimer) / 1000},
		{"Holy Frozenÿc0: %d", AFFECT_HOLYFREEZECHILL, (GetTickCount() - V_HolyFrozenTimer) / 1000},
		{"Holy Shieldÿc0: %d", AFFECT_HOLYSHIELD, (GetTickCount() - V_HolyShieldTimer) / 1000},
		{"Inner Sightÿc0: %d", AFFECT_INNERSIGHT, (GetTickCount() - V_InnerSightTimer) / 1000},
		{"Iron Maidenÿc0: %d", AFFECT_IRONMAIDEN, (GetTickCount() - V_IronMaidenTimer) / 1000},
		{"Life Tapÿc0: %d", AFFECT_LIFETAP, (GetTickCount() - V_LifeTapTimer) / 1000},
		{"Lower Resistÿc0: %d", AFFECT_LOWERRESIST, (GetTickCount() - V_LowerResistTimer) / 1000},
		{"Oak Sageÿc0: %d", AFFECT_OAKSAGE, (GetTickCount() - V_OakSageTimer) / 1000},
		{"Open Woundsÿc0: %d", AFFECT_OPENWOUNDS, (GetTickCount() - V_OpenWoundsTimer) / 1000},
		{"Poisonedÿc0: %d", AFFECT_POISON, (GetTickCount() - V_PoisonedTimer) / 1000},
		{"Shiver Armorÿc0: %d", AFFECT_SHIVERARMOR, (GetTickCount() - V_ShiverArmorTimer) / 1000},
		{"Shoutÿc0: %d", AFFECT_SHOUT, (GetTickCount() - V_ShoutTimer) / 1000},
		{"Slowedÿc0: %d", AFFECT_SLOWED, (GetTickCount() - V_SlowedTimer) / 1000},
		{"Terrorÿc0: %d", AFFECT_TERROR, (GetTickCount() - V_TerrorTimer) / 1000},
		{"Thunder Stormÿc0: %d", AFFECT_THUNDERSTORM, (GetTickCount() - V_ThunderStormTimer) / 1000},
		{"Venomÿc0: %d", AFFECT_VENOMCLAWS, (GetTickCount() - V_VenomTimer) / 1000}
	};

	INT Y = 0;
	INT Y2 = 0;
	INT X = 10;
	CHAR S[40];
	strcpy(S, "States");

	for (INT i = 0; i < ArraySize(States); i++)
	{
		if (!GetUnitState(Me, States[i].State))
			continue;

		Y += 10;

		if ((INT)strlen(States[i].Text) > X)
		{
			X = (INT)strlen(States[i].Text);
			strcpy(S, States[i].Text);
		}
	}

	Rectangle(V_StateListX, V_StateListY, strlen(S) > 10 ? GetTextWidth(S, 6) + 10 : 60, Y + 22, 0, 1);
	DrawOutCenter(strlen(S) > 10 ? V_StateListX + (GetTextWidth(S, 6) / 2) + 5 : V_StateListX + 30, Y ? V_StateListY + 12 : V_StateListY + 15, V_StateListTitleColor, 6, 1, "States");

	for (INT i = 0; i < ArraySize(States); i++)
	{
		if (!GetUnitState(Me, States[i].State))
			continue;

		Y2 += 10;
		DrawOutCenter(strlen(S) > 10 ? V_StateListX + (GetTextWidth(S, 6) / 2) + 5 : V_StateListX + 30, V_StateListY + 17 + Y2, 3, 6, 1, States[i].Text, States[i].Timer);
	}

	return TRUE;
}

BOOL Design::Supplies()
{
	if (CharacterStats || !V_Supplies || V_Options || !ClearScreen(3) || Hide)
		return FALSE;

	if(!V_ToggleKeyItem[1][1] || V_HaveKeyItemExp2[1] != 987)
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	if (V_ToggleMenu)
		return FALSE;

	INT HP = GetTotalBeltHealth() + GetTotalCubeHealth() + GetTotalInvHealth() + GetTotalStashHealth();
	INT MP = GetTotalBeltMana() + GetTotalCubeMana() + GetTotalInvMana() + GetTotalStashMana();
	INT RP = GetTotalBeltRejuvenation() + GetTotalCubeRejuvenation() + GetTotalInvRejuvenation() + GetTotalStashRejuvenation();
	INT TP = GetTotalBeltTPs() + GetTotalCubeTPs() + GetTotalInvTPs() + GetTotalStashTPs();

	Rectangle(V_SuppliesX, V_SuppliesY, 122, 72, 0, 1);
	DrawOutCenter(V_SuppliesX + 61, V_SuppliesY + 12, V_SuppliesTitleColor, 6, 1, "Supplies");

	DrawOutCenter(V_SuppliesX + 61, V_SuppliesY + 27, 3, 6, 1, "Healingÿc0: %d", HP);
	DrawOutCenter(V_SuppliesX + 61, V_SuppliesY + 37, 3, 6, 1, "Manaÿc0: %d", MP);
	DrawOutCenter(V_SuppliesX + 61, V_SuppliesY + 47, 3, 6, 1, "Rejuvinationÿc0: %d", RP);
	DrawOutCenter(V_SuppliesX + 61, V_SuppliesY + 57, 3, 6, 1, "Town Portalÿc0: %d", TP);
	DrawOutCenter(V_SuppliesX + 61, V_SuppliesY + 67, 3, 6, 1, "Currencyÿc0: %s", AddCommas(GetUnitStat(Me, STAT_GOLD) + GetUnitStat(Me, STAT_GOLDBANK), 0));

	return TRUE;
}

BOOL Design::Gold() //Credits to Ruby
{
	if (!ClientReady(FALSE))
		return FALSE;

	INT TotalGold = GetUnitStat(Me, STAT_GOLD) + GetUnitStat(Me, STAT_GOLDBANK);

	if (!V_StartingGold)
		V_StartingGold = TotalGold;

	if (!V_GainedGold)
		V_GainedGold = 0;

	INT InventoryGold = GetUnitStat(Me, STAT_GOLD);
	INT LevelInventoryGold = GetGold(GetUnitStat(Me, STAT_LEVEL)) + (55535 * GetUnitStat(Me, STAT_LEVEL)); // Updated belt size adds 55535 per level
	INT GoldPercent = CalcPercent(InventoryGold, LevelInventoryGold);
	V_GainedGold = TotalGold - V_StartingGold;
	INT Belt = TotalGold / LevelInventoryGold;

	if (V_GainedGold > 1000000000)
	{
		V_GainedGold = 0;
	}

	if (Hide)
		return FALSE;

	if (CharacterStats || !V_Gold || V_Options || !ClearScreen(3))
		return FALSE;

	if(!V_ToggleKeyItem[3][1] || V_HaveKeyItemExp2[3] != 2387)
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	if (V_ToggleMenu)
		return FALSE;

	Rectangle(V_GoldX, V_GoldY, 122, 72, 0, 1);

#ifndef FFXIVMOD
	DrawOutCenter(V_GoldX + 61, V_GoldY + 12, V_GoldTitleColor, 6, 1, "Gold");
#else
	DrawOutCenter(V_GoldX + 61, V_GoldY + 12, V_GoldTitleColor, 6, 1, "Dyne");
#endif

	DrawOutCenter(V_GoldX + 61, V_GoldY + 27, 3, 6, 1, "Beltsÿc0: %d ÿc3Cap.ÿc0: %d%%", Belt, GoldPercent);
	DrawOutCenter(V_GoldX + 61, V_GoldY + 37, 3, 6, 1, "Totalÿc0: %s", AddCommas(TotalGold, 0));
	DrawOutCenter(V_GoldX + 61, V_GoldY + 47, 3, 6, 1, "Personÿc0: %s", AddCommas(GetUnitStat(Me, STAT_GOLD), 0));
	DrawOutCenter(V_GoldX + 61, V_GoldY + 57, 3, 6, 1, "Neededÿc0: %s", AddCommas(LevelInventoryGold - GetUnitStat(Me, STAT_GOLD), 0));
	DrawOutCenter(V_GoldX + 61, V_GoldY + 67, 3, 6, 1, "Gainedÿc0: %s", AddCommas(V_GainedGold, 0));

	return TRUE;
}

BOOL Design::EscapeInfo()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (!V_ExpInfo || !V_EscapeInfo || V_Options || !ClearScreen(3))
		return FALSE;

	Rectangle(V_EscapeInfoX, V_EscapeInfoY, 100, 62, 0, 1);
	TextHook(V_EscapeInfoX + 46, V_EscapeInfoY + 12, V_EscapeInfoTitleColor, 0, 6, 1, "Escape Info");

	if (V_LifeExitPercent > 100)
		V_LifeExitPercent = 100;

	TextHook(V_EscapeInfoX + 46, V_EscapeInfoY + 27, 3, 0, 6, 1, V_LifeExitPercent ? "Exit Lifeÿc0: %d%%" : "Exit Lifeÿc0: Off", V_LifeExitPercent);

	if (V_ManaExitPercent > 100)
		V_ManaExitPercent = 100;

	TextHook(V_EscapeInfoX + 46, V_EscapeInfoY + 37, 3, 0, 6, 1, V_ManaExitPercent ? "Exit Manaÿc0: %d%%" : "Exit Manaÿc0: Off", V_ManaExitPercent);

	if (V_LifeTownPercent > 100)
		V_LifeTownPercent = 100;

	TextHook(V_EscapeInfoX + 46, V_EscapeInfoY + 47, 3, 0, 6, 1, V_LifeTownPercent ? "Town Lifeÿc0: %d%%" : "Town Lifeÿc0: Off", V_LifeTownPercent);

	if (V_ManaTownPercent > 100)
		V_ManaTownPercent = 100;

	TextHook(V_EscapeInfoX + 46, V_EscapeInfoY + 57, 3, 0, 6, 1, V_ManaTownPercent ? "Town Manaÿc0: %d%%" : "Town Manaÿc0: Off", V_ManaTownPercent);

	return TRUE;
}

BOOL Design::PotionInfo()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (CharacterStats || !V_PotionInfo || V_Options || !ClearScreen(3))
		return FALSE;

	Rectangle(V_PotionInfoX, V_PotionInfoY, 106, 62, 0, 1);
	TextHook(V_PotionInfoX + 50, V_PotionInfoY + 12, V_PotionInfoTitleColor, 0, 6, 1, "Potions");

	if (V_LifePotPercent > 100)
		V_LifePotPercent = 100;

	TextHook(V_PotionInfoX + 50, V_PotionInfoY + 27, 3, 0, 6, 1, V_LifePotPercent ? "Life Potionÿc0: %d%%" : "Life Potionÿc0: Off", V_LifePotPercent);

	if (V_ManaPotPercent > 100)
		V_ManaPotPercent = 100;

	TextHook(V_PotionInfoX + 50, V_PotionInfoY + 37, 3, 0, 6, 1, V_ManaPotPercent ? "Mana Potionÿc0: %d%%" : "Mana Potionÿc0: Off", V_ManaPotPercent);

	if (V_LifeJuvPercent > 100)
		V_LifeJuvPercent = 100;

	TextHook(V_PotionInfoX + 50, V_PotionInfoY + 47, 3, 0, 6, 1, V_LifeJuvPercent ? "Life Rejuv.ÿc0: %d%%" : "Life Rejuv.ÿc0: Off", V_LifeJuvPercent);

	if (V_ManaJuvPercent > 100)
		V_ManaJuvPercent = 100;

	TextHook(V_PotionInfoX + 50, V_PotionInfoY + 57, 3, 0, 6, 1, V_ManaJuvPercent ? "Mana Rejuv.ÿc0: %d%%" : "Mana Rejuv.ÿc0: Off", V_ManaJuvPercent);

	return TRUE;
}

BOOL Design::Targets()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	if (V_TargetList)
	{
		Rectangle(V_TargetListX, V_TargetListY, 68 + (LongestCharName(1) * 5), 22 + (10 * V_Players.GetSize()), 0, 1);
		TextHook(V_TargetListX + 30 + ((LongestCharName(1) * 5) / 2), V_Players.IsEmpty() ? V_TargetListY + 15 : V_TargetListY + 12, V_TargetListTitleColor, 0, 6, 1, "Target List");
	}

	if (V_TargetInfo)
	{
		Rectangle(V_TargetInfoX, V_TargetInfoY, V_Players.IsEmpty() ? 68 : strlen(V_Players[V_Target]->PlayerName) > 11 ? 68 + ((INT)strlen(V_Players[V_Target]->PlayerName) * 2) : 68, V_Players.IsEmpty() ? 22 : 62, 0, 1);
		TextHook(V_Players.IsEmpty() ? V_TargetInfoX + 30 : strlen(V_Players[V_Target]->PlayerName) > 11 ? V_TargetInfoX + 30 + ((INT)strlen(V_Players[V_Target]->PlayerName) * 2 / 2) : V_TargetInfoX + 30, V_Players.IsEmpty() ? V_TargetInfoY + 15 : V_TargetInfoY + 12, V_TargetInfoTitleColor, 0, 6, 1, "Target Info");
	}

	if (V_Players.IsEmpty())
		return FALSE;

	V_Players.Lock();

	for (INT i = 0; i < V_Players.GetSize(); i++)
	{
	if (V_TargetList)
		{
			//LPROSTERUNIT Roster = FindPartyById(V_Players[i]->UnitId);
			TextHook(V_TargetListX + 30 + ((LongestCharName(1) * 5) / 2), V_TargetListY + 27 + (10 * i), (i == V_Target) ? V_TargetListTargettedColor : V_TargetListNonTargettedColor, 0, 12, 1, "%s ÿc2%d%% ÿc5*", V_Players[i]->PlayerName, V_Players[i]->Life);
		}

		if (V_TargetInfo && V_Target == i)
		{
			CHAR Class[20];
			GetPlayerClassName(V_Players[V_Target]->ClassId, Class, 20);

			TextHook(strlen(V_Players[V_Target]->PlayerName) > 11 ? V_TargetInfoX + 30 + ((INT)strlen(V_Players[V_Target]->PlayerName) * 2 / 2) : V_TargetInfoX + 30, V_TargetInfoY + 27, 3, 0, 6, 1, V_Players[V_Target]->PlayerName);
			TextHook(strlen(V_Players[V_Target]->PlayerName) > 11 ? V_TargetInfoX + 30 + ((INT)strlen(V_Players[V_Target]->PlayerName) * 2 / 2) : V_TargetInfoX + 30, V_TargetInfoY + 37, 3, 0, 6, 1, Class);
			TextHook(strlen(V_Players[V_Target]->PlayerName) > 11 ? V_TargetInfoX + 30 + ((INT)strlen(V_Players[V_Target]->PlayerName) * 2 / 2) : V_TargetInfoX + 30, V_TargetInfoY + 47, 3, 0, 6, 1, "Level %d", V_Players[V_Target]->Level);
			TextHook(strlen(V_Players[V_Target]->PlayerName) > 11 ? V_TargetInfoX + 30 + ((INT)strlen(V_Players[V_Target]->PlayerName) * 2 / 2) : V_TargetInfoX + 30, V_TargetInfoY + 57, 3, 0, 6, 1, "%d%% Life", V_Players[V_Target]->Life);
		}
	}

	V_Players.Unlock();

	return TRUE;
}

BOOL Design::MusicPlayer()
{
	if (!V_Design)
		return FALSE;

	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (CharacterStats || !V_MusicPlayer || V_Options || !ClearScreen(3))
		return FALSE;

	BOOL Extend = (strlen(CurrentSong()) > 6) ? TRUE : FALSE;
	INT SongWidth = GetTextWidth(CurrentSong(), 6);

	Rectangle(V_MusicPlayerX, V_MusicPlayerY, Extend ? SongWidth + 10 : 50, strlen(CurrentSong()) > 0 ? 42 : 22, 0, 1);

	DrawOutCenter(Extend ? V_MusicPlayerX + 5 + (SongWidth / 2) : V_MusicPlayerX + 25, strlen(CurrentSong()) > 0 ? V_MusicPlayerY + 12 :
		V_MusicPlayerY + 15, V_MusicPlayerTitleColor, 6, 1, "Winamp");

	if (strlen(CurrentSong()) > 0)
	{
		DrawOutCenter(Extend ? V_MusicPlayerX + 5 + (SongWidth / 2) : V_MusicPlayerX + 25, V_MusicPlayerY + 27, 3, 6, 1, CurrentSong());

		if (MaxTime() != INFINITE)
			DrawOutCenter(Extend ? V_MusicPlayerX + 5 + (SongWidth / 2) : V_MusicPlayerX + 25, V_MusicPlayerY + 37, 0, 6, 1, "%.2d:%.2d:%.2d / %.2d:%.2d:%.2d",
			(CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60, (MaxTime() / 3600) % 60, (MaxTime() / 60) % 60, MaxTime() % 60);
		else
			DrawOutCenter(Extend ? V_MusicPlayerX + 5 + (SongWidth / 2) : V_MusicPlayerX + 25, V_MusicPlayerY + 37, 0, 6, 1, "%.2d:%.2d:%.2d / --:--:--",
			(CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60);
	}

	return TRUE;
}

//Design Interals
VOID Design::DrawBox(INT X1, INT Y1, INT X2, INT Y2, INT LineColor, INT BackGroundColor, INT Transparency)
{
	D2GFX_DrawRectangle(X1, Y1, X2, Y2, BackGroundColor, Transparency);
	D2GFX_DrawLine(X1, Y1, X1 + (X2 - X1), Y1, LineColor, -1);
	D2GFX_DrawLine(X1 + (X2 - X1), Y1, X1 + (X2 - X1), Y1 + (Y2 - Y1), LineColor, -1);
	D2GFX_DrawLine(X1 + (X2 - X1), Y1 + (Y2 - Y1), X1, Y1 + (Y2 - Y1), LineColor, -1);
	D2GFX_DrawLine(X1, Y1 + (Y2 - Y1), X1, Y1, LineColor, -1);
}

VOID Design::DrawCross(INT X, INT Y, DWORD Color, BOOL Automap)
{
	POINT Position = {X, Y};

	if (Automap)
	{
		if (!p_D2CLIENT_AutomapOn)
			return;

		ScreenToAutomap(&Position, X * 32, Y * 32);
	}

	CHAR Lines[][2] = {0, -2, 4, -4, 8, -2, 4, 0, 8, 2, 4, 4, 0, 2, -4, 4, -8, 2, -4, 0, -8, -2, -4, -4, 0, -2};

	for (INT i = 0; i < ArraySize(Lines) - 1; i++)
		D2GFX_DrawLine(Position.x + Lines[i][0], Position.y + Lines[i][1], Position.x + Lines[i + 1][0], Position.y + Lines[i + 1][1], Color, -1);
}

VOID Design::DrawOut(INT X, INT Y, INT Color, INT Size, LPSTR Format, ...)
{
	WCHAR wTemp[0x400] = L"";
	CHAR szTemp[0x400] = "";
	DWORD dwOldSize;
	va_list Args;

	va_start(Args, Format);
	vsprintf_s(szTemp, Format, Args);
	va_end(Args);

	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szTemp, (INT)strlen(szTemp), wTemp, (INT)strlen(szTemp));

	dwOldSize = D2WIN_SetTextSize(Size);
	D2WIN_DrawText_II(wTemp, X, Y, Color, -1);
	D2WIN_SetTextSize(dwOldSize);
}

BOOL Design::DrawOutCenter(INT xPos, INT yPos, DWORD dwColor, DWORD dwSize, DWORD dwDiv, LPSTR lpFormat, ...)
{
	CHAR szOutput[0x800] = "";
	WCHAR wOutput[0x800] = L"";
	DWORD dwOldSize, dwWidth;
	va_list Args;

	if (!ClientReady(FALSE))
		return FALSE;

	va_start(Args, lpFormat);
	vsprintf(szOutput, lpFormat, Args);
	va_end(Args);

	MyMultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szOutput, (INT)strlen(szOutput), wOutput, (INT)strlen(szOutput));

	dwOldSize = D2WIN_SetTextSize(dwSize);
	dwWidth = GetTextWidth(szOutput, dwSize);
	D2WIN_DrawText_II(wOutput, (xPos - (GetTextWidth(szOutput, dwSize) >> dwDiv)), yPos, dwColor, 0);
	D2WIN_SetTextSize(dwOldSize);

	return TRUE;
}

VOID Design::TextHook(INT X, INT Y, DWORD Color, BOOL Automap, INT Font, INT Center, LPSTR Text, ...)
{
	POINT nPos = {X, Y};
	DWORD dwOldSize, wWidth, dwFileNo;

	if (Automap)
	{
		if (!*p_D2CLIENT_AutomapOn)
			return;

		ScreenToAutomap(&nPos, X * 32, Y * 32);
	}

	CHAR szBuffer[800] = "";
	va_list Args;
	va_start(Args, Text);
	vsprintf_s(szBuffer, Text, Args);
	va_end(Args);

	WCHAR wBuffer[0x130];
	MultiByteToWideChar(0, 1, szBuffer, 100, wBuffer, 100);

	dwOldSize = D2WIN_SetTextSize(Font);

	if (Center != -1)
	{
		D2WIN_GetTextWidthFileNo(wBuffer, &wWidth, &dwFileNo);
		nPos.x -= (wWidth >> Center);
	}

	D2WIN_DrawText_II(wBuffer, nPos.x, nPos.y, Color, -1);
	D2WIN_SetTextSize(dwOldSize);
}

VOID Design::BoxHook(INT X, INT Y, INT XSize, INT YSize, DWORD Color, DWORD Transparency, BOOL Automap)
{
	POINT Start = {X, Y};
	POINT End = {XSize, YSize};

	if (Automap)
	{
		if (*p_D2CLIENT_AutomapOn)
			return;

		ScreenToAutomap(&Start, X * 32, Y * 32);
	}

	return D2GFX_DrawRectangle(Start.x, Start.y, End.x + Start.x, End.y + Start.y, Color, Transparency);
}

VOID Design::Rectangle(INT X, INT Y, INT X2, INT Y2, INT Color, INT Transparency)
{
	RECT RECTANGLE;
	RECTANGLE.left = X;
	RECTANGLE.top = Y;
	RECTANGLE.right = X2 + X;
	RECTANGLE.bottom = Y2 + Y;
	BoxHook(X, Y, X2, Y2, Color, Transparency, FALSE);
	DrawRectangleFrameSTUB(&RECTANGLE);
}

VOID Design::Frame(INT X, INT Y, INT X2, INT Y2)
{
	RECT RECTANGLE;
	RECTANGLE.left = X;
	RECTANGLE.top = Y;
	RECTANGLE.right = X2 + X;
	RECTANGLE.bottom = Y2 + Y;
	DrawRectangleFrameSTUB(&RECTANGLE);
}

VOID Design::GetPlayerPosition(LPPOINT Player)
{
	if (!V_Design)
		return;

	ScreenToAutomapRelative(Player, GetScreenSizeX() / 2, (GetScreenSizeY() - 48) / 2);
}

INT Design::GetScreenSizeX()
{
	if (!V_Design)
		return FALSE;

	INT Sizes[2] = {640, 800};
	return Sizes[D2GFX_GetScreenSize() / 2];
}

INT Design::GetScreenSizeX2()
{
	if (!V_Design)
		return FALSE;

	INT Sizes[2] = {640, 800};
	return Sizes[D2GFX_GetScreenSize2() / 2];
}

INT Design::GetScreenSizeY()
{
	if (!V_Design)
		return FALSE;

	INT Sizes[2] = {480, 600};
	return Sizes[D2GFX_GetScreenSize() / 2];
}

INT Design::GetScreenSizeY2()
{
	if (!V_Design)
		return FALSE;

	INT Sizes[2] = {480, 600};
	return Sizes[D2GFX_GetScreenSize2() / 2];
}

VOID Design::MapToScreenCoords(LPPOINT Position)
{
	D2COMMON_MapToAbsScreen(&Position->x, &Position->y);
	Position->x -= D2CLIENT_GetPlayerXOffset();
	Position->y -= D2CLIENT_GetPlayerYOffset();
}


VOID Design::ScreenToAutomap(LPPOINT Position, INT X, INT Y)
{
	Position->x = ((X - Y) / 2 / (*(INT*)p_D2CLIENT_Divisor)) - (*p_D2CLIENT_Offset).x + 8;
	Position->y = ((X + Y) / 4 / (*(INT*)p_D2CLIENT_Divisor)) - (*p_D2CLIENT_Offset).y - 8;

	if (D2CLIENT_GetAutomapSize())
	{
		--Position->x;
		Position->y += 5;
	}
}

VOID Design::ScreenToAutoMap(LPPOINT Point)
{
	POINT Mouse = {(*p_D2CLIENT_MouseX), (*p_D2CLIENT_MouseY)};
	POINT MouseOffset = {(*p_D2CLIENT_MouseOffsetX), (*p_D2CLIENT_MouseOffsetY)};

	Mouse.x += MouseOffset.x;
	Mouse.y += MouseOffset.y;

	D2COMMON_AbsScreenToMap(&Mouse.x, &Mouse.y);

	Point->x = Mouse.x;
	Point->y = Mouse.y;

	/*LONG MX = (*p_D2CLIENT_MouseX);
	LONG MY = (*p_D2CLIENT_MouseY);
	DWORD New = MX;

	LONG MZ = (*p_D2CLIENT_MouseOffsetX);
	MY += (*p_D2CLIENT_MouseOffsetY);
	MZ -= (*p_D2CLIENT_MouseOffsetZ);
	MZ += New;

	D2COMMON_AbsScreenToMap(&MZ, &MY);

	Point->x = MZ;
	Point->y = MY;*/
}

VOID Design::ScreenToAutomapRelative(LPPOINT ptPos, INT x, INT y)
{
	x += D2CLIENT_GetPlayerXOffset();
	y += D2CLIENT_GetPlayerYOffset();
	ScreenToAutomap(ptPos, y * 2 + x, y * 2 - x);

	if (!ClearScreen(1))
		ptPos->x += 8;
}

//
//D2Gfx Stuff
VOID Design::GameDraw()
{
#ifdef NOWILDERNESSMENU
	if (!ClearScreen(4) && !InTown(Me) && ClientReady(FALSE))
	{
		INPUT Inputs[2] = { 0 };

		// Set up a generic keyboard event.
		Inputs[0].type = INPUT_KEYBOARD;
		Inputs[0].ki.wScan = 0; // hardware scan code for key
		Inputs[0].ki.time = 0;
		Inputs[0].ki.dwExtraInfo = 0;

		// Press the "Esc" key
		Inputs[0].ki.wVk = 27; // virtual-key code for the "Esc" key
		Inputs[0].ki.dwFlags = 0; // 0 for key press

		// Complete a generic keyboard event.
		Inputs[1].type = INPUT_KEYBOARD;
		Inputs[1].ki.wScan = 0; // hardware scan code for key
		Inputs[1].ki.time = 0;
		Inputs[1].ki.dwExtraInfo = 0;

		// Release the "Esc" key
		Inputs[1].ki.wVk = 27; // virtual-key code for the "Esc" key
		Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
		SendInput(2, Inputs, sizeof(INPUT));

		if (MenuNotice == FALSE)
		{
			Print(0, 9, "Unable to use the main menu outside of town.");

			MenuNotice = TRUE;
		}

	}
#endif // NOWILDERNESSMENU

#ifdef LAZARUSMOD
	if (V_GMMode) { V_Design->DrawGMTag2(); }
#endif

	if(*p_D2CLIENT_ScreenSizeX == 640 || !V_Registered)
		return;

	V_Design->Options();
	V_Design->Targets();
	V_Design->GoldMeter();

	V_Design->Stats();
	V_Design->Ability();
	V_Design->Guide();
	//V_Design->Settings();

	if (V_GMMode) { V_Design->DrawGMTag2(); }
}

VOID Design::GameDraw2()
{
#ifdef LAZARUSMOD
	V_Design->AdvanceClassesLazarus();
#endif

	if(*p_D2CLIENT_ScreenSizeX == 640 || !V_Registered)
		return;

	V_Design->Orbs();
	V_Design->MusicPlayer();

	V_Design->AdvanceClasses();
	V_Design->SideQuestsMenu();
	V_Design->PlayerInfoMenu();
}

VOID Design::GameDraw3()
{
	if(*p_D2CLIENT_ScreenSizeX == 640 || !V_Registered)
		return;

	V_Design->UIDash();
	V_Design->ExpMeter();
	V_Design->EscapeInfo();
	V_Design->ExperienceInfo();
	V_Design->PotionInfo();
	V_Design->Mouse();
	V_Design->Supplies();
	V_Design->States();
	V_Design->Gold();
	V_Design->LifeDots();

	V_Design->MenuButton();

	V_Design->MenuStatButton();
	V_Design->MenuInfoButton();
	V_Design->MenuMissionButton();
	V_Design->MenuAbilityButton();
	V_Design->MenuGuideButton();
	V_Design->MenuCalcButton();
	//V_Design->MenuSettingButton();

	V_Design->MenuMiniPanel();

	if (V_GMMode) { V_Design->DrawGMTag(); }
}

VOID Design::GameDraw4()
{
}

VOID Design::GameDrawAutomap()
{
	V_Design->AutomapInfo();
	V_Design->Missiles();
	V_Design->Monsters();
	V_Design->PlayerLifePercent();
	V_Design->Vectors();
}

VOID Design::WinDraw()
{
	GameFilter();
}

/*
VOID GameDrawOOG_Intercept()
{
	WinDraw2();
}

VOID WinDraw2()
{
	D2WIN_DrawSprites();
	if (V_LoadingNotice) { DrawNotice(); }
	if (V_VersionNotice) { DrawVersionInfo(); }
}
*/

BOOL Design::DrawGMTag()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_CHAT) || V_Options || !V_UIDash || (!ClearScreen(3) && !GetUIVar(UI_MSGS)))
		return FALSE;

	if (GetUIVar(UI_MINISKILL))
		return FALSE;

	if (!ClearScreen(3))
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	DrawTag();

	return TRUE;
}

BOOL Design::DrawGMTag2()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if(!GetUIVar(UI_CHARACTER))
		return FALSE;

	DrawTag2();

	return TRUE;
}

BOOL Design::DrawGMTag2Lazarus()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (!GetUIVar(UI_CHARACTER))
		return FALSE;

	DrawTag2();

	return TRUE;
}

//
//Project Ruby Ports
BOOL Design::UIDash()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_CHAT) || V_Options || !V_UIDash || (!ClearScreen(3) && !GetUIVar(UI_MSGS)))
		return FALSE;

	if (GetUIVar(UI_MINISKILL))
		return FALSE;

	if (!ClearScreen(3))
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	INT RP;

	Rectangle(115, 510, 45, 33, 0, 1);
	TextHook(133, 522, 0, 0, 6, 1, "Level");
	DrawOutCenter(139, 537, 0, 1, 1, "%d", GetUnitStat(Me, STAT_LEVEL));


	if(UILARGEEXPBOX != 1)
	{
		Rectangle(170, 510, 120, 33, 0, 1);
		TextHook(225, 522, 0, 0, 6, 1, "Experience");
		DrawOutCenter(232, 537, 0, 1, 1, "%s", AddCommas(GetUnitStat(Me, STAT_EXP), 0));

		Rectangle(300, 510, 120, 33, 0, 1);
		TextHook(355, 522, 0, 0, 6, 1, "Next Level");
		DrawOutCenter(362, 537, 0, 1, 1, "%s", AddCommas(GetExp(GetUnitStat(Me, STAT_LEVEL)), 0));

		RP = GetTotalBeltRejuvenation() + GetTotalCubeRejuvenation() + GetTotalInvRejuvenation() + GetTotalStashRejuvenation();
		Rectangle(430, 510, 45, 33, 0, 1);
		TextHook(448, 522, 0, 0, 6, 1, "Rejuv.");
		if (RP == 0)
			DrawOutCenter(454, 537, 0, 0, 1, "0");
		if (RP > 0)
			DrawOutCenter(454, 537, 3, 0, 1, "%d", RP);
	}
	else if(UILARGEEXPBOX == 1)
	{
		Rectangle(170, 510, 147, 33, 0, 1);
		TextHook(238, 522, 0, 0, 6, 1, "Experience");
		DrawOutCenter(245, 537, 0, 1, 1, "%s", AddCommas(GetUnitStat(Me, STAT_EXP), 0));

		Rectangle(328, 510, 148, 33, 0, 1);
		TextHook(395, 523, 0, 0, 6, 1, "Next Level");
		DrawOutCenter(402, 537, 0, 1, 1, "%s", AddCommas(GetExp(GetUnitStat(Me, STAT_LEVEL)), 0));
	}

	if (V_TransparentNametag)
	{
		Rectangle(485, 510, 198, 33, 0, 1);
	}
	else if (!V_TransparentNametag)
	{
		Rectangle(485, 510, 198, 33, 1, 5);
	}

	INT NameX;
	INT OffsetX = GMNAMEOFFSETX;

	if (V_GMMode)
	{
		NameX = 580 + OffsetX;
	}
	else
	{
		NameX = 580;
	}

#ifdef COLOREXPNAMETAG
	if (!V_Expansion)
	{
		TextHook(NameX, 537, 0, 0, 7, 1, "%s", Me->pPlayerData->szName);
	}
	else if (V_Expansion)
	{
		TextHook(NameX, 537, 2, 0, 7, 1, "%s", Me->pPlayerData->szName);
	}
#else
	if (!V_GMMode)
	{
		TextHook(NameX, 537, 0, 0, 7, 1, "%s", Me->pPlayerData->szName);
	}
	else
	{
		TextHook(NameX, 537, 1, 0, 7, 1, "%s", Me->pPlayerData->szName);
	}
#endif
	
	return TRUE;
}

BOOL Design::LifeDots()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE) || V_Options || !V_LifeDots || GetUIVar(UI_MSGS))
		return FALSE;

	DrawOutCenter(500, 100, 1, 1, 1, "-Life-");

	INT CurrentHP = GetUnitStat(Me, STAT_HP);
	INT BallColor;
	INT Ball1X = 533;
	INT Ball2X = 545;
	INT Ball3X = 557;
	INT Ball4X = 569;
	INT Ball5X = 581;
	INT Ball6X = 593;
	INT Ball7X = 605;
	INT Ball8X = 617;
	INT Ball9X = 629;
	INT Ball10X = 641;
	INT BallY = 100;
	INT BallY2 = 112;

	if(CurrentHP < 2750001)
	{
		BallColor = 98;
	}
	else if(CurrentHP > 2750000)
	{
		BallColor = 13;
	}

	if(CurrentHP > 0 && CurrentHP < 250000)
	{
		DrawDot(Ball1X, BallY, BallColor, 0);
	}
	if(CurrentHP > 250001 && CurrentHP < 375000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
	}
	if(CurrentHP > 375001 && CurrentHP < 500000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 0);
	}
	if(CurrentHP > 500000 && CurrentHP < 625000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
	}
	if(CurrentHP > 625001 && CurrentHP < 750000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 0);
	}
	if(CurrentHP > 750001 && CurrentHP < 875000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
	}
	if(CurrentHP > 875001 && CurrentHP < 1000000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 0);
	}
	if(CurrentHP > 1000001 && CurrentHP < 1125000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
	}
	if(CurrentHP > 1125001 && CurrentHP < 1250000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 0);
	}
	if(CurrentHP > 1250001 && CurrentHP < 1375000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
	}
	if(CurrentHP > 1375001 && CurrentHP < 1500000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 0);
	}
	if(CurrentHP > 1500001 && CurrentHP < 1625000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
	}
	if(CurrentHP > 1625001 && CurrentHP < 1750000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 0);
	}
	if(CurrentHP > 1750001 && CurrentHP < 1875000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 1);
	}
	if(CurrentHP > 1875001 && CurrentHP < 2000000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 1);
		DrawDot(Ball3X, BallY2, BallColor, 0);
	}
	if(CurrentHP > 2000001 && CurrentHP < 2125000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 1);
		DrawDot(Ball3X, BallY2, BallColor, 1);
	}
	if(CurrentHP > 2125001 && CurrentHP < 2250000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 1);
		DrawDot(Ball3X, BallY2, BallColor, 1);
		DrawDot(Ball4X, BallY2, BallColor, 0);
	}
	if(CurrentHP > 2250001 && CurrentHP < 2375000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 1);
		DrawDot(Ball3X, BallY2, BallColor, 1);
		DrawDot(Ball4X, BallY2, BallColor, 1);
	}
	if(CurrentHP > 2375001 && CurrentHP < 2500000)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 1);
		DrawDot(Ball3X, BallY2, BallColor, 1);
		DrawDot(Ball4X, BallY2, BallColor, 1);
		DrawDot(Ball5X, BallY2, BallColor, 0);
	}
	if(CurrentHP > 2500001)
	{
		DrawDot(Ball1X, BallY, BallColor, 1);
		DrawDot(Ball2X, BallY, BallColor, 1);
		DrawDot(Ball3X, BallY, BallColor, 1);
		DrawDot(Ball4X, BallY, BallColor, 1);
		DrawDot(Ball5X, BallY, BallColor, 1);
		DrawDot(Ball1X, BallY2, BallColor, 1);
		DrawDot(Ball2X, BallY2, BallColor, 1);
		DrawDot(Ball3X, BallY2, BallColor, 1);
		DrawDot(Ball4X, BallY2, BallColor, 1);
		DrawDot(Ball5X, BallY2, BallColor, 1);
	}
	
	return TRUE;
}

BOOL Design::GoldMeter()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (!V_GoldMeter)
		return FALSE;

	if (GetUIVar(UI_INVENTORY))
		return FALSE;

	if (GetUIVar(UI_STASH))
		return FALSE;

	if (GetUIVar(UI_CUBE))
		return FALSE;

	if (GetUIVar(UI_MERC))
		return FALSE;

	if (GetUIVar(UI_QUEST))
		return FALSE;

	if (GetUIVar(UI_MINISKILL))
		return FALSE;

	if (!ClearScreen(3))
		return FALSE;

	INT MeterColor;
	INT MeterHeight;

	INT BoxWidth;
	INT BoxX;
	INT BoxY;

	if(DIRECT3DSUPPORT != 1)
	{
		MeterHeight = 2;

		BoxWidth = 120;
		BoxX = 256;
		BoxY = 562;
	}
	else
	{
		MeterHeight = 3;

		BoxWidth = 121;
		BoxX = 255;
		BoxY = 561;
	}

	MeterColor = GOLDMETERCOLOR;

	INT TotalGold = GetUnitStat(Me, STAT_GOLD) + GetUnitStat(Me, STAT_GOLDBANK);

	INT InventoryGold = GetUnitStat(Me, STAT_GOLD);
	INT LevelInventoryGold = GetGold(GetUnitStat(Me, STAT_LEVEL)) + (55535 * GetUnitStat(Me, STAT_LEVEL));  // Updated belt size is 65535 per level
	INT GoldPercent = CalcPercent(InventoryGold, LevelInventoryGold);

	INT GoldMax = 16777214; // Updated stash size is 16777214
	INT TotalGoldMax = LevelInventoryGold + GoldMax; 

	BoxHook(BoxX, BoxY, BoxWidth, MeterHeight, 256, 5, 0);

	CHAR Gold[100];

	DWORD ThisMouseOverX1 = 247;
	DWORD ThisMouseOverY1 = 556;
	DWORD ThisMouseOverX2 = ThisMouseOverX1 + 136;
	DWORD ThisMouseOverY2 = ThisMouseOverY1 + 11;
	INT ThisMouseOverTextX = ThisMouseOverX1 + 30;
	INT ThisMouseOverTextY = ThisMouseOverY1 - 7;
	INT ThisMouseOverBoxX = ThisMouseOverX1 - 140;
	INT ThisMouseOverBoxY = ThisMouseOverY1 - 51;

	switch (GoldPercent)
	{
	case 0:
		break;
	case 1:
		BoxHook(BoxX, BoxY, 1, MeterHeight, MeterColor, 5, 0);

		break;
	case 2:
		BoxHook(BoxX, BoxY, 2, MeterHeight, MeterColor, 5, 0);

		break;
	case 3:
		BoxHook(BoxX, BoxY, 3, MeterHeight, MeterColor, 5, 0);

		break;
	case 4:
		BoxHook(BoxX, BoxY, 4, MeterHeight, MeterColor, 5, 0);

		break;
	case 5:
		BoxHook(BoxX, BoxY, 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 6:
		BoxHook(BoxX, BoxY, 7, MeterHeight, MeterColor, 5, 0);

		break;
	case 7:
		BoxHook(BoxX, BoxY, 8, MeterHeight, MeterColor, 5, 0);

		break;
	case 8:
		BoxHook(BoxX, BoxY, 9, MeterHeight, MeterColor, 5, 0);

		break;
	case 9:
		BoxHook(BoxX, BoxY, 10, MeterHeight, MeterColor, 5, 0);

		break;
	case 10:
		BoxHook(BoxX, BoxY, 11, MeterHeight, MeterColor, 5, 0);

		break;
	case 11:
		BoxHook(BoxX, BoxY, 13, MeterHeight, MeterColor, 5, 0);

		break;
	case 12:
		BoxHook(BoxX, BoxY, 14, MeterHeight, MeterColor, 5, 0);

		break;
	case 13:
		BoxHook(BoxX, BoxY, 15, MeterHeight, MeterColor, 5, 0);

		break;
	case 14:
		BoxHook(BoxX, BoxY, 16, MeterHeight, MeterColor, 5, 0);

		break;
	case 15:
		BoxHook(BoxX, BoxY, 17, MeterHeight, MeterColor, 5, 0);

		break;
	case 16:
		BoxHook(BoxX, BoxY, 19, MeterHeight, MeterColor, 5, 0);

		break;
	case 17:
		BoxHook(BoxX, BoxY, 20, MeterHeight, MeterColor, 5, 0);

		break;
	case 18:
		BoxHook(BoxX, BoxY, 21, MeterHeight, MeterColor, 5, 0);

		break;
	case 19:
		BoxHook(BoxX, BoxY, 22, MeterHeight, MeterColor, 5, 0);

		break;
	case 20:
		BoxHook(BoxX, BoxY, 23, MeterHeight, MeterColor, 5, 0);

		break;
	case 21:
		BoxHook(BoxX, BoxY, 25, MeterHeight, MeterColor, 5, 0);

		break;
	case 22:
		BoxHook(BoxX, BoxY, 26, MeterHeight, MeterColor, 5, 0);

		break;
	case 23:
		BoxHook(BoxX, BoxY, 27, MeterHeight, MeterColor, 5, 0);

		break;
	case 24:
		BoxHook(BoxX, BoxY, 28, MeterHeight, MeterColor, 5, 0);

		break;
	case 25:
		BoxHook(BoxX, BoxY, 29, MeterHeight, MeterColor, 5, 0);

		break;
	case 26:
		BoxHook(BoxX, BoxY, 31, MeterHeight, MeterColor, 5, 0);

		break;
	case 27:
		BoxHook(BoxX, BoxY, 32, MeterHeight, MeterColor, 5, 0);

		break;
	case 28:
		BoxHook(BoxX, BoxY, 33, MeterHeight, MeterColor, 5, 0);

		break;
	case 29:
		BoxHook(BoxX, BoxY, 34, MeterHeight, MeterColor, 5, 0);

		break;
	case 30:
		BoxHook(BoxX, BoxY, 35, MeterHeight, MeterColor, 5, 0);

		break;
	case 31:
		BoxHook(BoxX, BoxY, 37, MeterHeight, MeterColor, 5, 0);

		break;
	case 32:
		BoxHook(BoxX, BoxY, 38, MeterHeight, MeterColor, 5, 0);

		break;
	case 33:
		BoxHook(BoxX, BoxY, 39, MeterHeight, MeterColor, 5, 0);

		break;
	case 34:
		BoxHook(BoxX, BoxY, 40, MeterHeight, MeterColor, 5, 0);

		break;
	case 35:
		BoxHook(BoxX, BoxY, 41, MeterHeight, MeterColor, 5, 0);

		break;
	case 36:
		BoxHook(BoxX, BoxY, 43, MeterHeight, MeterColor, 5, 0);

		break;
	case 37:
		BoxHook(BoxX, BoxY, 44, MeterHeight, MeterColor, 5, 0);

		break;
	case 38:
		BoxHook(BoxX, BoxY, 45, MeterHeight, MeterColor, 5, 0);

		break;
	case 39:
		BoxHook(BoxX, BoxY, 46, MeterHeight, MeterColor, 5, 0);

		break;
	case 40:
		BoxHook(BoxX, BoxY, 47, MeterHeight, MeterColor, 5, 0);

		break;
	case 41:
		BoxHook(BoxX, BoxY, 49, MeterHeight, MeterColor, 5, 0);

		break;
	case 42:
		BoxHook(BoxX, BoxY, 50, MeterHeight, MeterColor, 5, 0);

		break;
	case 43:
		BoxHook(BoxX, BoxY, 51, MeterHeight, MeterColor, 5, 0);

		break;
	case 44:
		BoxHook(BoxX, BoxY, 52, MeterHeight, MeterColor, 5, 0);

		break;
	case 45:
		BoxHook(BoxX, BoxY, 53, MeterHeight, MeterColor, 5, 0);

		break;
	case 46:
		BoxHook(BoxX, BoxY, 55, MeterHeight, MeterColor, 5, 0);

		break;
	case 47:
		BoxHook(BoxX, BoxY, 56, MeterHeight, MeterColor, 5, 0);

		break;
	case 48:
		BoxHook(BoxX, BoxY, 57, MeterHeight, MeterColor, 5, 0);

		break;
	case 49:
		BoxHook(BoxX, BoxY, 58, MeterHeight, MeterColor, 5, 0);

		break;
	case 50:
		BoxHook(BoxX, BoxY, 59, MeterHeight, MeterColor, 5, 0);

		break;
	case 51:
		BoxHook(BoxX, BoxY, 61, MeterHeight, MeterColor, 5, 0);

		break;
	case 52:
		BoxHook(BoxX, BoxY, 62, MeterHeight, MeterColor, 5, 0);

		break;
	case 53:
		BoxHook(BoxX, BoxY, 63, MeterHeight, MeterColor, 5, 0);

		break;
	case 54:
		BoxHook(BoxX, BoxY, 64, MeterHeight, MeterColor, 5, 0);

		break;
	case 55:
		BoxHook(BoxX, BoxY, 65, MeterHeight, MeterColor, 5, 0);

		break;
	case 56:
		BoxHook(BoxX, BoxY, 67, MeterHeight, MeterColor, 5, 0);

		break;
	case 57:
		BoxHook(BoxX, BoxY, 68, MeterHeight, MeterColor, 5, 0);

		break;
	case 58:
		BoxHook(BoxX, BoxY, 69, MeterHeight, MeterColor, 5, 0);

		break;
	case 59:
		BoxHook(BoxX, BoxY, 70, MeterHeight, MeterColor, 5, 0);

		break;
	case 60:
		BoxHook(BoxX, BoxY, 71, MeterHeight, MeterColor, 5, 0);

		break;
	case 61:
		BoxHook(BoxX, BoxY, 73, MeterHeight, MeterColor, 5, 0);

		break;
	case 62:
		BoxHook(BoxX, BoxY, 74, MeterHeight, MeterColor, 5, 0);

		break;
	case 63:
		BoxHook(BoxX, BoxY, 75, MeterHeight, MeterColor, 5, 0);

		break;
	case 64:
		BoxHook(BoxX, BoxY, 76, MeterHeight, MeterColor, 5, 0);

		break;
	case 65:
		BoxHook(BoxX, BoxY, 77, MeterHeight, MeterColor, 5, 0);

		break;
	case 66:
		BoxHook(BoxX, BoxY, 79, MeterHeight, MeterColor, 5, 0);

		break;
	case 67:
		BoxHook(BoxX, BoxY, 80, MeterHeight, MeterColor, 5, 0);

		break;
	case 68:
		BoxHook(BoxX, BoxY, 81, MeterHeight, MeterColor, 5, 0);

		break;
	case 69:
		BoxHook(BoxX, BoxY, 82, MeterHeight, MeterColor, 5, 0);

		break;
	case 70:
		BoxHook(BoxX, BoxY, 83, MeterHeight, MeterColor, 5, 0);

		break;
	case 71:
		BoxHook(BoxX, BoxY, 85, MeterHeight, MeterColor, 5, 0);

		break;
	case 72:
		BoxHook(BoxX, BoxY, 86, MeterHeight, MeterColor, 5, 0);

		break;
	case 73:
		BoxHook(BoxX, BoxY, 87, MeterHeight, MeterColor, 5, 0);

		break;
	case 74:
		BoxHook(BoxX, BoxY, 88, MeterHeight, MeterColor, 5, 0);

		break;
	case 75:
		BoxHook(BoxX, BoxY, 89, MeterHeight, MeterColor, 5, 0);

		break;
	case 76:
		BoxHook(BoxX, BoxY, 91, MeterHeight, MeterColor, 5, 0);

		break;
	case 77:
		BoxHook(BoxX, BoxY, 92, MeterHeight, MeterColor, 5, 0);

		break;
	case 78:
		BoxHook(BoxX, BoxY, 93, MeterHeight, MeterColor, 5, 0);

		break;
	case 79:
		BoxHook(BoxX, BoxY, 94, MeterHeight, MeterColor, 5, 0);

		break;
	case 80:
		BoxHook(BoxX, BoxY, 95, MeterHeight, MeterColor, 5, 0);

		break;
	case 81:
		BoxHook(BoxX, BoxY, 97, MeterHeight, MeterColor, 5, 0);

		break;
	case 82:
		BoxHook(BoxX, BoxY, 98, MeterHeight, MeterColor, 5, 0);

		break;
	case 83:
		BoxHook(BoxX, BoxY, 99, MeterHeight, MeterColor, 5, 0);

		break;
	case 84:
		BoxHook(BoxX, BoxY, 100, MeterHeight, MeterColor, 5, 0);

		break;
	case 85:
		BoxHook(BoxX, BoxY, 101, MeterHeight, MeterColor, 5, 0);

		break;
	case 86:
		BoxHook(BoxX, BoxY, 103, MeterHeight, MeterColor, 5, 0);

		break;
	case 87:
		BoxHook(BoxX, BoxY, 104, MeterHeight, MeterColor, 5, 0);

		break;
	case 88:
		BoxHook(BoxX, BoxY, 105, MeterHeight, MeterColor, 5, 0);

		break;
	case 89:
		BoxHook(BoxX, BoxY, 106, MeterHeight, MeterColor, 5, 0);

		break;
	case 90:
		BoxHook(BoxX, BoxY, 107, MeterHeight, MeterColor, 5, 0);

		break;
	case 91:
		BoxHook(BoxX, BoxY, 109, MeterHeight, MeterColor, 5, 0);

		break;
	case 92:
		BoxHook(BoxX, BoxY, 110, MeterHeight, MeterColor, 5, 0);

		break;
	case 93:
		BoxHook(BoxX, BoxY, 111, MeterHeight, MeterColor, 5, 0);

		break;
	case 94:
		BoxHook(BoxX, BoxY, 112, MeterHeight, MeterColor, 5, 0);

		break;
	case 95:
		BoxHook(BoxX, BoxY, 113, MeterHeight, MeterColor, 5, 0);

		break;
	case 96:
		BoxHook(BoxX, BoxY, 115, MeterHeight, MeterColor, 5, 0);

		break;
	case 97:
		BoxHook(BoxX, BoxY, 116, MeterHeight, MeterColor, 5, 0);

		break;
	case 98:
		BoxHook(BoxX, BoxY, 118, MeterHeight, MeterColor, 5, 0);

		break;
	case 99:
		BoxHook(BoxX, BoxY, 119, MeterHeight, MeterColor, 5, 0);

	case 100:
		if(DIRECT3DSUPPORT != 1)
		{
			BoxHook(BoxX, BoxY, 120, MeterHeight, MeterColor, 5, 0);
		}
		else if(DIRECT3DSUPPORT == 1)
		{
			BoxHook(BoxX, BoxY, 121, MeterHeight, MeterColor, 5, 0);
		}

		break;
	}

	CHAR CommaTotalGold[100];
	CHAR CommaTotalGoldMax[100];
	sprintf_s(CommaTotalGold, "%s", AddCommas(TotalGold, 0));
	sprintf_s(CommaTotalGoldMax, "%s", AddCommas(TotalGoldMax, 0));

#ifndef FFXIVMOD
	sprintf_s(Gold, "Total Gold: %s / %s", CommaTotalGold, CommaTotalGoldMax);
#else
	sprintf_s(Gold, "Total Dyne: %s / %s", CommaTotalGold, CommaTotalGoldMax);
#endif

	if ((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		BoxHook(ThisMouseOverBoxX, ThisMouseOverBoxY, 346, 46, 256, 5, 0);

		DrawMenuFrame(ThisMouseOverBoxX - 2, ThisMouseOverBoxY - 2, 346 + 4, 46 + 4, 13);
		if (GetSkill(D2S_FINDITEM) != NULL)
		{
			TextHook(ThisMouseOverBoxX + (2 + 183), ThisMouseOverTextY - 30, 0, 0, 6, -1, "%sÿc0: Level %d", "Find Item", GetSkill(D2S_FINDITEM));
		}
		else
		{
			TextHook(ThisMouseOverBoxX + (2 + 183), ThisMouseOverTextY - 30, 0, 0, 6, -1, "%sÿc0: Unavailable", "Find Item");
		}
		TextHook(ThisMouseOverBoxX + 2, ThisMouseOverTextY - 30, 0, 0, 6, -1, "%sÿc0: %d%%", V_ModStatCurrencyFind, GetUnitStat(Me, STAT_GOLDFIND));
		TextHook(ThisMouseOverBoxX + 2, ThisMouseOverTextY - 20, 0, 0, 6, -1, "%sÿc0: %d%%", V_ModStatMagicFind, GetUnitStat(Me, STAT_MAGICFIND));

		TextHook(ThisMouseOverBoxX + 2, ThisMouseOverTextY, 0, 0, 6, -1, Gold);
	}

	TextHook(BoxX + 60, BoxY + 28, 1, 0, 0, 1, "[ ÿc2Gold: %d%%ÿc1 ]", GoldPercent);

	return TRUE;
}

BOOL Design::ExpMeter()
{
	if (Hide)
		return FALSE;

	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_CHAT) || V_Options || !V_ExpMeter || (!ClearScreen(3) && !GetUIVar(UI_MSGS)))
		return FALSE;

	if (GetUIVar(UI_MINISKILL))
		return FALSE;

	if (!ClearScreen(3))
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	INT BoxWidth = 55;
	INT BoxHeight = 12;
	INT BoxTransparency = 1;
	INT MeterHeight;
	INT MeterColor = 10;
	INT CursorColor = 13;

	INT Box1X = 115;
	INT BoxY = 490;
	INT BoxGap = 2;
	INT MeterYOffset;

	INT ClockX = 400;
	INT ClockY = 484;

	INT BoxTraversion = BoxWidth + BoxGap;
	INT CurrentMeterX;

	INT Box2X = Box1X + BoxTraversion;
	INT Box3X = Box2X + BoxTraversion;
	INT Box4X = Box3X + BoxTraversion;
	INT Box5X = Box4X + BoxTraversion;
	INT Box6X = Box5X + BoxTraversion;
	INT Box7X = Box6X + BoxTraversion;
	INT Box8X = Box7X + BoxTraversion;
	INT Box9X = Box8X + BoxTraversion;
	INT Box10X = Box9X + BoxTraversion;

	INT TotalExp;
	INT TotalLastLevelExp;
	INT TotalNextLevelExp;

	TotalExp = GetUnitStat(Me, STAT_EXP);
	TotalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1);
	TotalNextLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL));

	INT CurrentExp = TotalExp - TotalLastLevelExp;
	INT CurrentNextLevelExp;
	INT CurrentExpPercent;

	INT DecimalExp;
	INT DecimalLastLevelExp;
	INT DecimalNextLevelExp;
	INT DecimalExpPercent;

	INT CurrentBox;

	CurrentNextLevelExp = TotalNextLevelExp - TotalLastLevelExp;
	CurrentExpPercent = CalcPercent(CurrentExp, CurrentNextLevelExp);

	DecimalNextLevelExp = CurrentNextLevelExp / 10;

	if (!V_UIDash)
	{
		BoxY = 532;
		ClockY = 525;
	}

	if(DIRECT3DSUPPORT != 1)
	{
		MeterHeight = 8;

		MeterYOffset = 2;
	}
	else
	{
		MeterHeight = 9;

		MeterYOffset = 1;
	}

	if (CurrentExpPercent >= 100)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 10);
		CurrentBox = 10;
	}
	if (CurrentExpPercent >= 90)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 9);
		CurrentBox = 9;
	}
	if (CurrentExpPercent >= 80 && CurrentExpPercent < 90)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 8);
		CurrentBox = 8;
	}
	if (CurrentExpPercent >= 70 && CurrentExpPercent < 80)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 7);
		CurrentBox = 7;
	}
	if (CurrentExpPercent >= 60 && CurrentExpPercent < 70)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 6);
		CurrentBox = 6;
	}
	if (CurrentExpPercent >= 50 && CurrentExpPercent < 60)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 5);
		CurrentBox = 5;
	}
	if (CurrentExpPercent >= 40 && CurrentExpPercent < 50)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 4);
		CurrentBox = 4;
	}
	if (CurrentExpPercent >= 30 && CurrentExpPercent < 40)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 3);
		CurrentBox = 3;
	}
	if (CurrentExpPercent >= 20 && CurrentExpPercent < 30)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + (DecimalNextLevelExp * 2);
		CurrentBox = 2;
	}
	if (CurrentExpPercent >= 10 && CurrentExpPercent < 20)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1) + DecimalNextLevelExp;
		CurrentBox = 1;
	}
	if (CurrentExpPercent >= 0 && CurrentExpPercent < 10)
	{
		DecimalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1);
		CurrentBox = 0;
	}

	DecimalExp = TotalExp - DecimalLastLevelExp;
	DecimalExpPercent = CalcPercent(DecimalExp, DecimalNextLevelExp);

	if (CurrentExpPercent >= 100)
	{
		DecimalExpPercent = 100;
	}

	if (CurrentBox == 0)
		CurrentMeterX = Box1X;
	if (CurrentBox == 1)
		CurrentMeterX = Box2X;
	if (CurrentBox == 2)
		CurrentMeterX = Box3X;
	if (CurrentBox == 3)
		CurrentMeterX = Box4X;
	if (CurrentBox == 4)
		CurrentMeterX = Box5X;
	if (CurrentBox == 5)
		CurrentMeterX = Box6X;
	if (CurrentBox == 6)
		CurrentMeterX = Box7X;
	if (CurrentBox == 7)
		CurrentMeterX = Box8X;
	if (CurrentBox == 8)
		CurrentMeterX = Box9X;
	if (CurrentBox == 9)
		CurrentMeterX = Box10X;
	if (CurrentBox == 10)
		CurrentMeterX = Box10X;

	Rectangle(Box1X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box2X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box3X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box4X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box5X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box6X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box7X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box8X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box9X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);
	Rectangle(Box10X, BoxY, BoxWidth, BoxHeight, 0, BoxTransparency);

	switch (CurrentBox)
	{
	case 0:
		break;
	case 1:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 2:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 3:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 4:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box4X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 5:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box4X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box5X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 6:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box4X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box5X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box6X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 7:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box4X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box5X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box6X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box7X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 8:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box4X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box5X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box6X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box7X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box8X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 9:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box4X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box5X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box6X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box7X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box8X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box9X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	case 10:
		BoxHook(Box1X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box2X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box3X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box4X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box5X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box6X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box7X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box8X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box9X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(Box10X + 4, BoxY + MeterYOffset, BoxWidth - 5, MeterHeight, MeterColor, 5, 0);

		break;
	}

	switch (DecimalExpPercent)
	{
	case 0:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 1:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 1, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 5, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 2:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 1, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 5, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 3:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 2, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 6, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 4:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 2, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 6, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 5:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 3, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 7, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 6:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 3, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 7, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 7:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 4, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 8, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 8:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 4, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 8, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 9:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 9, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 10:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 5, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 9, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 11:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 6, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 10, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 12:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 6, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 10, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 13:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 7, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 11, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 14:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 7, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 11, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 15:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 8, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 12, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 16:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 8, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 12, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 17:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 9, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 13, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 18:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 9, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 13, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 19:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 10, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 14, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 20:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 10, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 14, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 21:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 11, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 15, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 22:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 11, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 15, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 23:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 12, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 16, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 24:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 12, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 16, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 25:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 13, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 17, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 26:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 13, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 17, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 27:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 14, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 18, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 28:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 14, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 18, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 29:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 15, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 19, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 30:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 15, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 19, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 31:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 16, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 20, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 32:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 16, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 20, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 33:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 17, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 21, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 34:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 17, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 21, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 35:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 18, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 22, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 36:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 18, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 22, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 37:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 19, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 23, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 38:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 19, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 23, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 39:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 20, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 24, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 40:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 20, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 24, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 41:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 21, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 25, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 42:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 21, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 25, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 43:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 22, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 26, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 44:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 22, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 26, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 45:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 23, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 27, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 46:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 23, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 27, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 47:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 24, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 28, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 48:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 24, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 28, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 49:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 25, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 29, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 50:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 25, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 29, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 51:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 26, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 30, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 52:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 26, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 30, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 53:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 27, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 31, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 54:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 27, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 31, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 55:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 28, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 32, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 56:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 28, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 32, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 57:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 29, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 33, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 58:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 29, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 33, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 59:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 30, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 34, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 60:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 30, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 34, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 61:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 31, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 35, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 62:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 31, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 35, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 63:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 32, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 36, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 64:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 32, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 36, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 65:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 33, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 37, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 66:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 33, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 37, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 67:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 34, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 38, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 68:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 34, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 38, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 69:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 35, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 39, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 70:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 35, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 39, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 71:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 36, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 40, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 72:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 36, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 40, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 73:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 37, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 41, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 74:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 37, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 41, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 75:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 38, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 42, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 76:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 38, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 42, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 77:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 39, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 43, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 78:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 39, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 43, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 79:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 40, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 44, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 80:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 40, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 44, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 81:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 41, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 45, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 82:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 41, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 45, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 83:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 42, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 46, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 84:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 42, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 46, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 85:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 43, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 47, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 86:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 43, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 47, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 87:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 44, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 48, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 88:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 44, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 48, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 89:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 45, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 49, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 90:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 45, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 49, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 91:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 46, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 50, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 92:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 46, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 50, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 93:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 47, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 51, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 94:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 47, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 51, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 95:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 48, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 52, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 96:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 48, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 52, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 97:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 49, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 53, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 98:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 49, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 53, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 99:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 49, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 53, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	case 100:
		BoxHook(CurrentMeterX + 4, BoxY + MeterYOffset, 49, MeterHeight, MeterColor, 5, 0);
		BoxHook(CurrentMeterX + 53, BoxY + MeterYOffset, 1, MeterHeight, CursorColor, 5, 0);

		break;
	}

	if(V_UIClock)
	{
		SYSTEMTIME Time;
		GetLocalTime(&Time);

		CHAR LocalTime[50];
		LPSTR CHour;

		if (Time.wHour == 0)
		{
			CHour = "12";
		}
		if (Time.wHour == 1)
		{
			CHour = "1";
		}
		if (Time.wHour == 2)
		{
			CHour = "2";
		}
		if (Time.wHour == 3)
		{
			CHour = "3";
		}
		if (Time.wHour == 4)
		{
			CHour = "4";
		}
		if (Time.wHour == 5)
		{
			CHour = "5";
		}
		if (Time.wHour == 6)
		{
			CHour = "6";
		}
		if (Time.wHour == 7)
		{
			CHour = "7";
		}
		if (Time.wHour == 8)
		{
			CHour = "8";
		}
		if (Time.wHour == 9)
		{
			CHour = "9";
		}
		if (Time.wHour == 10)
		{
			CHour = "10";
		}
		if (Time.wHour == 11)
		{
			CHour = "11";
		}
		if (Time.wHour == 12)
		{
			CHour = "12";
		}
		if (Time.wHour == 13)
		{
			CHour = "1";
		}
		if (Time.wHour == 14)
		{
			CHour = "2";
		}
		if (Time.wHour == 15)
		{
			CHour = "3";
		}
		if (Time.wHour == 16)
		{
			CHour = "4";
		}
		if (Time.wHour == 17)
		{
			CHour = "5";
		}
		if (Time.wHour == 18)
		{
			CHour = "6";
		}
		if (Time.wHour == 19)
		{
			CHour = "7";
		}
		if (Time.wHour == 20)
		{
			CHour = "8";
		}
		if (Time.wHour == 21)
		{
			CHour = "9";
		}
		if (Time.wHour == 22)
		{
			CHour = "10";
		}
		if (Time.wHour == 23)
		{
			CHour = "11";
		}
		if (Time.wHour == 24)
		{
			CHour = "12";
		}

		sprintf_s(LocalTime, "%s:%.2d", CHour, Time.wMinute);

		if(V_Block0x30)
		{
			TextHook(ClockX, ClockY, 1, 0, 1, 1, "Block 0x30");
		}
		else
		{
			TextHook(ClockX, ClockY, 4, 0, 1, 1, LocalTime);
		}
	}

	CHAR Experience[100];

	if(!V_ExpAddComma)
	{
		sprintf_s(Experience, "Experience: %d / %d", CurrentExp, CurrentNextLevelExp);
	}
	if(V_ExpAddComma)
	{
		CHAR CommaCurrentExp[100];
		CHAR CommaCurrentNextLevelExp[100];
		sprintf_s(CommaCurrentExp, "%s", AddCommas(CurrentExp, 0));
		sprintf_s(CommaCurrentNextLevelExp, "%s", AddCommas(CurrentNextLevelExp, 0));

		if (GetExp(GetUnitStat(Me, STAT_LEVEL)) == MODMAXLEVEL)
		{
			sprintf_s(Experience, "Experience: 0 / 0", CommaCurrentExp, CommaCurrentNextLevelExp);
		}
		else
		{
			sprintf_s(Experience, "Experience: %s / %s", CommaCurrentExp, CommaCurrentNextLevelExp);
		}

	}

	if(V_UIDash)
	{
		if((*p_D2CLIENT_MouseX >= 115 && *p_D2CLIENT_MouseX <= 685) && (*p_D2CLIENT_MouseY >= 488 && *p_D2CLIENT_MouseY <= 500))
		{
			TextHook(400, 500, 0, 0, 1, 1, Experience);
		}
	}
	if(!V_UIDash)
	{
		if((*p_D2CLIENT_MouseX >= 115 && *p_D2CLIENT_MouseX <= 685) && (*p_D2CLIENT_MouseY >= 532 && *p_D2CLIENT_MouseY <= 544))
		{
			TextHook(400, 544, 0, 0, 1, 1, Experience);
		}
	}

	return TRUE;
}

//
//Project Ruby Internals
VOID Design::DrawDot(INT X, INT Y, INT DotColor, INT Type)
{
	switch(Type){
	case 0:
		BoxHook(X - 1, Y + 1, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 1, 1, 1, DotColor, 5, 0);

		BoxHook(X - 2, Y + 2, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 2, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 2, 1, 1, DotColor, 5, 0);

		BoxHook(X - 3, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X - 2, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 3, 1, 1, DotColor, 5, 0);

		BoxHook(X - 3, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X - 2, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 4, 1, 1, DotColor, 5, 0);

		BoxHook(X - 3, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X - 2, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 5, 1, 1, DotColor, 5, 0);

		BoxHook(X - 2, Y + 6, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 6, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 6, 1, 1, DotColor, 5, 0);

		BoxHook(X - 1, Y + 7, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 7, 1, 1, DotColor, 5, 0);

		break;
	case 1:
		BoxHook(X - 1, Y + 1, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 1, 1, 1, DotColor, 5, 0);
		BoxHook(X + 1, Y + 1, 1, 1, DotColor, 5, 0);
		BoxHook(X + 2, Y + 1, 1, 1, DotColor, 5, 0);

		BoxHook(X - 2, Y + 2, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 2, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 2, 1, 1, DotColor, 5, 0);
		BoxHook(X + 1, Y + 2, 1, 1, DotColor, 5, 0);
		BoxHook(X + 2, Y + 2, 1, 1, DotColor, 5, 0);
		BoxHook(X + 3, Y + 2, 1, 1, DotColor, 5, 0);

		BoxHook(X - 3, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X - 2, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X + 1, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X + 2, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X + 3, Y + 3, 1, 1, DotColor, 5, 0);
		BoxHook(X + 4, Y + 3, 1, 1, DotColor, 5, 0);

		BoxHook(X - 3, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X - 2, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X + 1, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X + 2, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X + 3, Y + 4, 1, 1, DotColor, 5, 0);
		BoxHook(X + 4, Y + 4, 1, 1, DotColor, 5, 0);

		BoxHook(X - 3, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X - 2, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X + 1, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X + 2, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X + 3, Y + 5, 1, 1, DotColor, 5, 0);
		BoxHook(X + 4, Y + 5, 1, 1, DotColor, 5, 0);

		BoxHook(X - 2, Y + 6, 1, 1, DotColor, 5, 0);
		BoxHook(X - 1, Y + 6, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 6, 1, 1, DotColor, 5, 0);
		BoxHook(X + 1, Y + 6, 1, 1, DotColor, 5, 0);
		BoxHook(X + 2, Y + 6, 1, 1, DotColor, 5, 0);
		BoxHook(X + 3, Y + 6, 1, 1, DotColor, 5, 0);

		BoxHook(X - 1, Y + 7, 1, 1, DotColor, 5, 0);
		BoxHook(X, Y + 7, 1, 1, DotColor, 5, 0);
		BoxHook(X + 1, Y + 7, 1, 1, DotColor, 5, 0);
		BoxHook(X + 2, Y + 7, 1, 1, DotColor, 5, 0);

		break;
	}
}

//
//Hellfire II Menu
//Main
BOOL Design::MenuButton()
{
	if(Hide)
		return FALSE;

	if(!ClientReady(FALSE))
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	if (V_MenuObject > 0)
		return FALSE;

	INT RectX = 15;
	INT RectY = 490;
	INT TextX = RectX + 6;
	INT TextY = RectY + 12;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + 12;
	INT ThisMouseOverY2 = ThisMouseOverY1 + 12;


	if(!V_ToggleMenu)
	{
		BoxHook(RectX, RectY, 11, 10, V_BoxColorMenu, 5, 0);
		DrawOutCenter(TextX, TextY, 1, 1, 1, "+");

		//DrawMenuFrame(RectX - 2, RectY - 2, 15, 14, 13);
	}
	else
	{
		BoxHook(RectX, RectY, 11, 10, 98, 5, 0);
		DrawOutCenter(TextX, TextY, 4, 1, 1, "+");

		DrawMenuFrame(RectX - 2, RectY - 2, 15, 14, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		if(!V_ToggleMenu)
		{
			V_BoxColorMenu = 10;
		}

		if (!V_SoundMenu)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundMenu = TRUE;

		}

		INT MenuStrX = V_MenuStrContextX;
		INT MenuStrY = V_MenuStrContextY;
		INT MenuStrRectX = V_MenuStrRectX;
		INT MenuStrRectY = V_MenuStrRectY;
		INT MenuStrWidth = V_MenuStrRectWidth;
		INT MenuStrHeight = V_MenuStrRectHeight;

		V_ClickIgnoreMenu = TRUE;

		BoxHook(MenuStrRectX, MenuStrRectY, MenuStrWidth, MenuStrHeight, 256, 1, 0);
		DrawOutCenter(MenuStrX, MenuStrY, 0, 1, 1, V_MenuStr);

		if(!V_ClickDelay)
		{
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
#ifdef NOWILDERNESSACTIONMENU	
				if (!InTown(Me))
				{
					if (!notifiedMenu)
					{
						Print(0, 9, "Unable to use the action menu outside of town.");

						notifiedMenu = TRUE;
					}

					return FALSE;
				}
#endif

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

				V_ToggleMenu = !V_ToggleMenu;

				V_ClickIgnoreMenu = FALSE;
			}
		}
	}
	else
	{
		if(!V_ToggleStatMenu)
		{
			V_BoxColorMenu = 256;
		}

		V_ClickIgnoreMenu = FALSE;

		V_SoundMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuStatButton()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 452;
	INT TextX = RectX + 6;
	INT TextY = RectY + 15;

	INT BoxSizeX = 111;
	INT BoxSizeY = 18;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + BoxSizeX;
	INT ThisMouseOverY2 = ThisMouseOverY1 + BoxSizeY;

	if(!V_ToggleStatMenu)
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, V_BoxColorStatMenu, 5, 0);
		TextHook(TextX, TextY, 1, 0, 1, -1, V_MenuStrStat);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}
	else
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 98, 5, 0);
		TextHook(TextX, TextY, 4, 0, 1, -1, V_MenuStrStat);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		if(!V_ToggleStatMenu)
		{
			V_BoxColorStatMenu = 10;
		}

		if (!V_SoundStatMenu)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundStatMenu = TRUE;

		}

		V_ClickIgnoreStat = TRUE;

		if(!V_ClickDelay)
		{
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

				V_MenuObject = 1;

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		if(!V_ToggleStatMenu)
		{
			V_BoxColorStatMenu = 256;
		}

		V_ClickIgnoreStat = FALSE;

		V_SoundStatMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuInfoButton()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 427;
	INT TextX = RectX + 6;
	INT TextY = RectY + 15;

	INT BoxSizeX = 111;
	INT BoxSizeY = 18;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + BoxSizeX;
	INT ThisMouseOverY2 = ThisMouseOverY1 + BoxSizeY;

	if(!V_ToggleInfoMenu)
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, V_BoxColorInfoMenu, 5, 0);
		TextHook(TextX, TextY, 1, 0, 1, -1, V_MenuStrInfo);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}
	else
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 98, 5, 0);
		TextHook(TextX, TextY, 4, 0, 1, -1, V_MenuStrInfo);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		if(!V_ToggleInfoMenu)
		{
			V_BoxColorInfoMenu = 10;
		}

		if (!V_SoundInfoMenu)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundInfoMenu = TRUE;

		}

		V_ClickIgnoreInfo = TRUE;

		if(!V_ClickDelay)
		{
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

				V_MenuObject = 2;

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		if(!V_ToggleInfoMenu)
		{
			V_BoxColorInfoMenu = 256;
		}

		V_ClickIgnoreInfo = FALSE;

		V_SoundInfoMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuMissionButton()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 402;
	INT TextX = RectX + 6;
	INT TextY = RectY + 15;

	INT BoxSizeX = 111;
	INT BoxSizeY = 18;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + BoxSizeX;
	INT ThisMouseOverY2 = ThisMouseOverY1 + BoxSizeY;

	if(!V_ToggleMissionMenu)
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, V_BoxColorMissionMenu, 5, 0);
		TextHook(TextX, TextY, 1, 0, 1, -1, V_MenuStrMission);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}
	else
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 98, 5, 0);
		TextHook(TextX, TextY, 4, 0, 1, -1, V_MenuStrMission);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		if(!V_ToggleMissionMenu)
		{
			V_BoxColorMissionMenu = 10;
		}

		if (!V_SoundMissionMenu)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundMissionMenu = TRUE;

		}

		V_ClickIgnoreMission = TRUE;

		if(!V_ClickDelay)
		{
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

				V_MenuObject = 3;

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		if(!V_ToggleMissionMenu)
		{
			V_BoxColorMissionMenu = 256;
		}

		V_ClickIgnoreMission = FALSE;

		V_SoundMissionMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuAbilityButton()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 377;
	INT TextX = RectX + 6;
	INT TextY = RectY + 15;

	INT BoxSizeX = 111;
	INT BoxSizeY = 18;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + BoxSizeX;
	INT ThisMouseOverY2 = ThisMouseOverY1 + BoxSizeY;

	if(!V_ToggleAbilityMenu)
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, V_BoxColorAbilityMenu, 5, 0);
		TextHook(TextX, TextY, 1, 0, 1, -1, V_MenuStrAbility);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}
	else
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 98, 5, 0);
		TextHook(TextX, TextY, 4, 0, 1, -1, V_MenuStrAbility);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		if(!V_ToggleAbilityMenu)
		{
			V_BoxColorAbilityMenu = 10;
		}

		if (!V_SoundAbilityMenu)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundAbilityMenu = TRUE;

		}

		V_ClickIgnoreAbility = TRUE;

		if(!V_ClickDelay)
		{
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

				V_MenuObject = 4;

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		if(!V_ToggleAbilityMenu)
		{
			V_BoxColorAbilityMenu = 256;
		}

		V_ClickIgnoreAbility = FALSE;

		V_SoundAbilityMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuGuideButton()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 352;
	INT TextX = RectX + 6;
	INT TextY = RectY + 15;

	INT BoxSizeX = 111;
	INT BoxSizeY = 18;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + BoxSizeX;
	INT ThisMouseOverY2 = ThisMouseOverY1 + BoxSizeY;

	if(!V_ToggleGuideMenu)
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, V_BoxColorGuideMenu, 5, 0);
		TextHook(TextX, TextY, 1, 0, 1, -1, V_MenuStrGuide);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}
	else
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 98, 5, 0);
		TextHook(TextX, TextY, 4, 0, 1, -1, V_MenuStrGuide);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		if(!V_ToggleGuideMenu)
		{
			V_BoxColorGuideMenu = 10;
		}

		if (!V_SoundGuideMenu)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundGuideMenu = TRUE;
		}

		V_ClickIgnoreGuide = TRUE;

		if(!V_ClickDelay)
		{
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

				V_MenuObject = 5;

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		if(!V_ToggleGuideMenu)
		{
			V_BoxColorGuideMenu = 256;
		}

		V_ClickIgnoreGuide = FALSE;

		V_SoundGuideMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuCalcButton()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 327;
	INT TextX = RectX + 6;
	INT TextY = RectY + 15;

	INT BoxSizeX = 111;
	INT BoxSizeY = 18;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + BoxSizeX;
	INT ThisMouseOverY2 = ThisMouseOverY1 + BoxSizeY;

	if(!V_ToggleCalcMenu)
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, V_BoxColorCalcMenu, 5, 0);

		if(V_ToggleKeyItem[1][1] != TRUE)
		{
			TextHook(TextX, TextY, 5, 0, 1, -1, V_MenuStrCalc);
		}
		else
		{
			TextHook(TextX, TextY, 1, 0, 1, -1, V_MenuStrCalc);
		}

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}
	else
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 401, 5, 0);
		TextHook(TextX, TextY, 4, 0, 1, -1, V_MenuStrCalc);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		V_ClickIgnoreCalc = TRUE;

		if(V_ToggleKeyItem[1][1] == TRUE)
		{
			if(!V_ToggleCalcMenu)
			{
				V_BoxColorCalcMenu = 10;
			}

			if (!V_SoundCalcMenu)
			{
				D2CLIENT_PlaySound(STAND_PASS);

				V_SoundCalcMenu = TRUE;

			}

			if(!V_ClickDelay)
			{
				if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

					if(V_ToggleCalcMenu)
					{
						V_ToggleCalcMenu = FALSE;

						V_ExpInfo = FALSE;
						V_Supplies = FALSE;
						V_StateList = FALSE;
						V_Gold = FALSE;
					}
					else
					{
						V_ToggleCalcMenu = TRUE;

						V_ExpInfo = TRUE;
						V_Supplies = TRUE;
						V_StateList = TRUE;
						V_Gold = TRUE;
					}

					V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
				}
			}
		}
	}
	else
	{
		if(!V_ToggleCalcMenu)
		{
			V_BoxColorCalcMenu = 256;
		}

		V_ClickIgnoreCalc = FALSE;

		V_SoundCalcMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuSettingButton()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 302;
	INT TextX = RectX + 6;
	INT TextY = RectY + 15;

	INT BoxSizeX = 111;
	INT BoxSizeY = 18;

	INT ThisMouseOverX1 = RectX;
	INT ThisMouseOverY1 = RectY;
	INT ThisMouseOverX2 = ThisMouseOverX1 + BoxSizeX;
	INT ThisMouseOverY2 = ThisMouseOverY1 + BoxSizeY;

	if(!V_ToggleSettingMenu)
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, V_BoxColorSettingMenu, 5, 0);
		TextHook(TextX, TextY, 1, 0, 1, -1, V_MenuStrSetting);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}
	else
	{
		BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 98, 5, 0);
		TextHook(TextX, TextY, 4, 0, 1, -1, V_MenuStrSetting);

		DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);
	}

	if((*p_D2CLIENT_MouseX >= ThisMouseOverX1 && *p_D2CLIENT_MouseX <= ThisMouseOverX2) && (*p_D2CLIENT_MouseY >= ThisMouseOverY1 && *p_D2CLIENT_MouseY <= ThisMouseOverY2))
	{
		if(!V_ToggleSettingMenu)
		{
			V_BoxColorSettingMenu = 10;
		}

		if (!V_SoundSettingMenu)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundSettingMenu = TRUE;

		}

		V_ClickIgnoreSetting = TRUE;

		if(!V_ClickDelay)
		{
			if((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK);

				V_MenuObject = 6;

				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		if(!V_ToggleSettingMenu)
		{
			V_BoxColorSettingMenu = 256;
		}

		V_ClickIgnoreSetting = FALSE;

		V_SoundSettingMenu = FALSE;
	}

	return TRUE;
}

BOOL Design::MenuMiniPanel()
{
	if(!ClientReady(FALSE))
		return FALSE;

	if (!V_ToggleKeyItem[1][0])
		return FALSE;

	if(Hide)
		return FALSE;

	if(!V_ToggleMenu)
		return FALSE;

	if(CharacterStats || V_Options || !ClearScreen(3))
		return FALSE;

	INT RectX = 15;
	INT RectY = 90;
	INT BoxSizeX = 130;
	INT BoxSizeY = 132;

	RegisterLadder();

	UpdateLadder();

	BoxHook(RectX, RectY, BoxSizeX, BoxSizeY, 256, 5, 0);
	DrawMenuFrame(RectX - 2, RectY - 2, BoxSizeX + 4, BoxSizeY + 4, 13);

	INT64 TotalExp;
	if (GetUnitStat(Me, STAT_LEVEL) == 99)
	{
#ifndef FFXIVMOD
		TotalExp = 3520485254LL;
#else
		TotalExp = 1995350;
#endif
	}
	else
	{
		TotalExp = GetUnitStat(Me, STAT_EXP);
	}
	INT64 TotalLastLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL) - 1);
	INT64 TotalNextLevelExp = GetExp(GetUnitStat(Me, STAT_LEVEL));
	INT64 CurrentExp = TotalExp - TotalLastLevelExp;
	INT64 ToNextLevel = TotalNextLevelExp - TotalExp;;

	INT64 CurrentNextLevelExp = TotalNextLevelExp - TotalLastLevelExp;
	INT CurrentExpPercent = CalcPercent(CurrentExp, CurrentNextLevelExp);

	if (GetUnitStat(Me, STAT_LEVEL) == MODMAXLEVEL)
		ToNextLevel = 0;

	CHAR NameStr1[64];
	strncpy_s(NameStr1, sizeof(NameStr1), V_MyLadderName, sizeof(NameStr1));

	CHAR LevelStr1[64];
	strncpy_s(LevelStr1, sizeof(LevelStr1), "Level", sizeof(LevelStr1));

	CHAR LevelStr2[64];
	strncpy_s(LevelStr2, sizeof(LevelStr2), V_LadderClassAbrv[V_MyLadderClass], sizeof(LevelStr2));
	strcat_s(LevelStr2, AddCommas(V_MyLadderLevel, 0));

	CHAR RankStr1[64];
	strncpy_s(RankStr1, sizeof(RankStr1), "Rank", sizeof(RankStr1));

	CHAR RankStr2[64];
	strncpy_s(RankStr2, sizeof(RankStr2), AddCommas(V_MyLadderRank, 0), sizeof(RankStr2));
	strcat_s(RankStr2, "/10");

	CHAR ExpStr1[64];
	strncpy_s(ExpStr1, sizeof(ExpStr1), "Exp.", sizeof(ExpStr1));

	CHAR ExpStr2[64];
	strncpy_s(ExpStr2, sizeof(ExpStr2), AddCommas(CurrentExp, 0), sizeof(ExpStr2));

	CHAR TnlStr1[64];
	strncpy_s(TnlStr1, sizeof(TnlStr1), "Tnl.", sizeof(TnlStr1));

	CHAR TnlStr2[64];
	strncpy_s(TnlStr2, sizeof(TnlStr2), AddCommas(ToNextLevel, 0), sizeof(TnlStr2));

	//DrawOut(RectX, RectY + 16, 4, 0, NameStr1); //Name to the Left
	DrawOut(RectX, RectY + 40, 4, 0, LevelStr1);
	DrawOut(RectX, RectY + 56, 4, 0, RankStr1);
	DrawOut(RectX, RectY + 72, 4, 0, ExpStr1);
	DrawOut(RectX, RectY + 88, 4, 0, TnlStr1);

	TextHook(RectX + 120, RectY + 16, 4, 0, 0, 0, NameStr1); //Name to the right
	TextHook(RectX + 120, RectY + 40, 4, 0, 0, 0, LevelStr2);
	TextHook(RectX + 120, RectY + 56, 4, 0, 0, 0, RankStr2);
	TextHook(RectX + 120, RectY + 72, 4, 0, 0, 0, ExpStr2);
	TextHook(RectX + 120, RectY + 88, 4, 0, 0, 0, TnlStr2);

	INT Rect2X = 30;
	INT Rect2Y = RectY + 108;
	INT BoxSize2X = 100;
	INT BoxSize2Y = 10;

	BoxHook(Rect2X, Rect2Y, BoxSize2X, BoxSize2Y, 256, 5, 0);

	INT XR = Rect2X - 1;
	INT YB = Rect2Y - 1;

	BoxHook(Rect2X, Rect2Y, BoxSize2X + 2, 1, 13, 5, 0);
	BoxHook(Rect2X, YB + (BoxSize2Y + 2), BoxSize2X + 2, 1, 13, 5, 0);
	BoxHook(Rect2X, Rect2Y, 1, BoxSize2Y + 2, 13, 5, 0);
	BoxHook(XR + (BoxSize2X + 2), Rect2Y, 1, BoxSize2Y + 2, 13, 5, 0);

	BoxHook(Rect2X + 1, Rect2Y + 1, CurrentExpPercent, BoxSize2Y, 10, 5, 0);

	return TRUE;
}

VOID Design::AdvanceClasses()
{
	if(ADVANCECLASSES != 1)
		return;

	if (!ClientReady(FALSE))
		return;

	if (!GetUIVar(UI_CHARACTER))
		return;

	//Using Max Magic Resist as a flag for now since it is a generally unused stat
	// +1% Magic Resist == Ranger
	// +2% Magic Resist == Rogue
	// +3% Magic Resist == Thief
	// Etc.

	DWORD FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

	//Wings of the Goddess
	if (FLAG == 1)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[1 + 7]);
		V_Class[0] = 1348;
	}
	else if (FLAG == 2)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[2 + 7]);
		V_Class[1] = 1794;
	}
	else if (FLAG == 3)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[3 + 7]);
		V_Class[2] = 1553;
	}
	else if (FLAG == 4)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[4 + 7]);
		V_Class[3] = 1929;
	}
	else if (FLAG == 5)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[5 + 7]);
		V_Class[4] = 1003;
	}
	else if (FLAG == 6)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[6 + 7]);
		V_Class[5] = 1228;
	}
	else if (FLAG == 7)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[7 + 7]);
		V_Class[6] = 1542;
	}
	else if (FLAG == 8)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[8 + 7]);
		V_Class[7] = 1775;
	}
	else if (FLAG == 20)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[9 + 7]);
		V_Class[8] = 1994;
	}
	else if (FLAG == 21)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[10 + 7]);
		V_Class[9] = 1083;
	}
	else if (FLAG == 22)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[11 + 7]);
		V_Class[10] = 1330;
	}
	else if (FLAG == 23)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[12 + 7]);
		V_Class[11] = 1951;
	}
	else if (FLAG == 24)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[13 + 7]);
		V_Class[12] = 1539;
	}
	else if (FLAG == 25)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[14 + 7]);
		V_Class[13] = 1743;
	}
	else if (FLAG == 26)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[15 + 7]);
		V_Class[14] = 1884;
	}
	else if (FLAG == 27)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[16 + 7]);
		V_Class[15] = 1136;
	}
	else if (FLAG == 28)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[17 + 7]);
		V_Class[16] = 1093;
	}
	else if (FLAG == 29)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[18 + 7]);
		V_Class[17] = 1073;
	}
	else if (FLAG == 30)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[19 + 7]);
		V_Class[18] = 1237;
	}
	else if (FLAG >= 31)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[20 + 7]);
		V_Class[19] = 1138;
	}
	//New Sands of Calypso
	else if (FLAG == 17)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[21 + 7]);
		V_Class[20] = 1863;
	}
	else if (FLAG == 18)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[22 + 7]);
		V_Class[21] = 4837;
	}
	else if (FLAG == 19)
	{
		DrawClassBlock(274, 72);
		V_Design->TextHook(329, 85, 0, 0, 1, 1, V_ClassStr[23 + 7]);
		V_Class[22] = 3371;
	}
	return;
}

VOID Design::AdvanceClassesLazarus()
{
	if (ADVANCECLASSES != 1)
		return;

	if (!ClientReady(FALSE))
		return;

	if (!GetUIVar(UI_CHARACTER))
		return;

	//Using Max Magic Resist as a flag for now since it is a generally unused stat
	// +1% Magic Resist == Ranger
	// +2% Magic Resist == Rogue
	// +3% Magic Resist == Thief
	// Etc.

	DWORD FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

	if (FLAG == 1)
	{
		DrawClassBlock(194, 12);  //Difference of 80x60
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[1 + 7]);
		V_Class[0] = 1348;
	}
	else if (FLAG == 2)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[2 + 7]);
		V_Class[1] = 1794;
	}
	else if (FLAG == 3)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[3 + 7]);
		V_Class[2] = 1553;
	}
	else if (FLAG == 4)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[4 + 7]);
		V_Class[3] = 1929;
	}
	else if (FLAG == 5)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[5 + 7]);
		V_Class[4] = 1003;
	}
	else if (FLAG == 6)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[6 + 7]);
		V_Class[5] = 1228;
	}
	else if (FLAG == 7)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[7 + 7]);
		V_Class[6] = 1542;
	}
	else if (FLAG == 8)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[8 + 7]);
		V_Class[7] = 1775;
	}
	else if (FLAG == 20)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[9 + 7]);
		V_Class[8] = 1994;
	}
	else if (FLAG == 21)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[10 + 7]);
		V_Class[9] = 1083;
	}
	else if (FLAG == 22)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[11 + 7]);
		V_Class[10] = 1330;
	}
	else if (FLAG == 23)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[12 + 7]);
		V_Class[11] = 1951;
	}
	else if (FLAG == 24)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[13 + 7]);
		V_Class[12] = 1539;
	}
	else if (FLAG == 25)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[14 + 7]);
		V_Class[13] = 1743;
	}
	else if (FLAG == 26)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[15 + 7]);
		V_Class[14] = 1884;
	}
	else if (FLAG == 27)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[16 + 7]);
		V_Class[15] = 1136;
	}
	else if (FLAG == 28)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[17 + 7]);
		V_Class[16] = 1093;
	}
	else if (FLAG == 29)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[18 + 7]);
		V_Class[17] = 1073;
	}
	else if (FLAG == 30)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[19 + 7]);
		V_Class[18] = 1237;
	}
	else if (FLAG >= 31)
	{
		DrawClassBlock(194, 12);
		V_Design->TextHook(249, 25, 0, 0, 1, 1, V_ClassStr[20 + 7]);
		V_Class[19] = 1138;
	}
	return;
}

//Hellfire II Menu Pages
BOOL Design::PlayerInfoMenu()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_MAINMENU) || V_Options || !ClearScreen(3) || CharacterStats)
	{
		V_PlayerInfoGroup = -1;

		ResetInfoMenu();

		V_SelectedCounterPage = 1;
		V_SelectedCounterPageText = 1;

		V_PlayerInfoListPages = 1;

		V_MenuObject = 0;
	}

	if (V_MenuObject != 2)
	{
		V_ClickIgnoreInfo2 = FALSE;

		return FALSE;
	}

	//Ignore Click
	V_ClickIgnoreInfo2 = TRUE;

	//Menu Boxes
	Rectangle(5, 30, 780, 470, 0, 2);
	Frame(5, 65, 780, 400);
	Frame(5, 65, 390, 400);

	//Title
	V_Design->TextHook(TitleTextX, TitleTextY, 4, 0, 1, 1, V_CounterMainStr);

	//Close Button
	if ((*p_D2CLIENT_MouseX >= MouseOverX1 && *p_D2CLIENT_MouseX <= MouseOverX2) && (*p_D2CLIENT_MouseY >= MouseOverY1 && *p_D2CLIENT_MouseY <= MouseOverY2))
	{
		V_Design->TextHook(TextBX, TextBY, 3, 0, 1, 1, V_CounterCloseStr);

		if (!V_SoundPlus)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundPlus = TRUE;

		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_PlayerInfoGroup = -1;

				ResetInfoMenu();

				V_SelectedCounterPage = 1;
				V_SelectedCounterPageText = 1;

				V_PlayerInfoListPages = 1;

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

				V_ToggleInfoMenu = FALSE;
				V_MenuObject = 0;
				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		V_Design->TextHook(TextBX, TextBY, 0, 0, 1, 1, V_CounterCloseStr);

		V_SoundPlus = FALSE;
	}

	//Event Back Button List
	if (V_PlayerInfoBack)
	{
		ResetInfoMenu();

		if (V_SelectedCounterPage == 1)
		{
			V_PlayerInfoGroup = -1;
		}
		else if (V_SelectedCounterPage > 1)
		{
			V_SelectedCounterPage -= 1;
		}

		V_PlayerInfoBack = FALSE;
	}

	//Event Next Button List
	if (V_PlayerInfoNext)
	{
		ResetInfoMenu();

		if (V_PlayerInfoGroup > -1)
		{
			if (V_SelectedCounterPage < V_PlayerInfoListPages)
			{
				V_SelectedCounterPage += 1;
			}
		}

		V_PlayerInfoNext = FALSE;
	}

	//Event Back Button Text
	if (V_PlayerInfoBackText)
	{
		ResetInfoText();

		if (V_SelectedCounterPageText > 1)
		{
			V_SelectedCounterPageText -= 1;
		}

		SetInfoText(V_PlayerInfoGroup, V_PlayerInfoSelected, V_SelectedCounterPageText);

		V_PlayerInfoBackText = FALSE;
	}

	//Event Next Button Text
	if (V_PlayerInfoNextText)
	{
		ResetInfoText();

		if (V_SelectedCounterPageText < V_PlayerInfoTextPages)
		{
			V_SelectedCounterPageText += 1;
		}

		SetInfoText(V_PlayerInfoGroup, V_PlayerInfoSelected, V_SelectedCounterPageText);

		V_PlayerInfoNextText = FALSE;
	}

	if (V_PlayerInfoGroup > -1)
	{
		//List Hooks
		DrawInfoList(V_PlayerInfoGroup);

		//Text Hooks
		if (V_PlayerInfoSelected > -1)
		{
			DrawInfoText();
		}
	}
	else
	{
		//Main Hooks
		DrawInfoMain();
	}

	return TRUE;
}

BOOL Design::SideQuestsMenu()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_MAINMENU) || V_Options || !V_Design->ClearScreen(3) || V_Design->CharacterStats)
	{
		V_SideQuestExpansion = -1;

		ResetQuestsMenu();
		ResetQuestsText();

		V_SelectedQuestPage = 1;
		V_SelectedQuestPageText = 1;

		V_SideQuestListPages = 1;

		V_MenuObject = 0;
	}

	if (V_MenuObject != 3)
	{
		V_ClickIgnoreMission2 = FALSE;

		return FALSE;
	}

	//Ignore Click
	V_ClickIgnoreMission2 = TRUE;

	//Menu Boxes
	Rectangle(5, 30, 780, 470, 0, 2);
	Frame(5, 65, 780, 400);
	Frame(5, 65, 390, 400);

	//Title
	TextHook(TitleTextX, TitleTextY, 4, 0, 1, 1, V_SideQuestStrMain);

	//Close Button
	if ((*p_D2CLIENT_MouseX >= MouseOverX1 && *p_D2CLIENT_MouseX <= MouseOverX2) && (*p_D2CLIENT_MouseY >= MouseOverY1 && *p_D2CLIENT_MouseY <= MouseOverY2))
	{
		V_Design->TextHook(TextBX, TextBY, 3, 0, 1, 1, V_SideQuestStrClose);

		if (!V_SoundPlus)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundPlus = TRUE;

		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_SideQuestExpansion = -1;

				ResetQuestsMenu();

				V_SelectedQuestPage = 1;
				V_SelectedQuestPageText = 1;

				V_SideQuestListPages = 1;

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

				V_ToggleMissionMenu = FALSE;
				V_MenuObject = 0;
				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		TextHook(TextBX, TextBY, 0, 0, 1, 1, V_SideQuestStrClose);

		V_SoundPlus = FALSE;
	}

	//Event Back Button List
	if (V_SideQuestBack)
	{
		ResetQuestsMenu();

		if (V_SelectedQuestPage == 1)
		{
			V_SideQuestExpansion = -1;
		}
		else if (V_SelectedQuestPage > 1)
		{
			V_SelectedQuestPage -= 1;
		}

		V_SideQuestBack = FALSE;
	}

	//Event Next Button List
	if (V_SideQuestNext)
	{
		if (V_SideQuestExpansion > -1)
		{
			if (V_SelectedQuestPage < V_SideQuestListPages)
			{
				V_SelectedQuestPage += 1;
			}
		}

		V_SideQuestNext = FALSE;
	}

	//Event Back Button Text
	if (V_SideQuestBackText)
	{
		//V_D2NonQ->ResetQuestsText();

		if (V_SelectedQuestPageText > 1)
		{
			V_SelectedQuestPageText -= 1;
		}

		LoadScriptText(V_SideQuestSelected, V_SelectedQuestPageText);

		V_SideQuestBackText = FALSE;
	}

	//Event Next Button Text
	if (V_SideQuestNextText)
	{
		//V_D2NonQ->ResetQuestsText();

		if (V_SelectedQuestPageText < V_SideQuestTextPages)
		{
			V_SelectedQuestPageText += 1;
		}

		LoadScriptText(V_SideQuestSelected, V_SelectedQuestPageText);

		V_SideQuestNextText = FALSE;
	}

	if (V_SideQuestExpansion > -1)
	{
		//Load script list
		LoadScriptList(V_SideQuestExpansion, V_SelectedQuestPage);

		//List Hooks
		DrawQuestList();

		//Text Hooks
		DrawQuestText();
	}
	else
	{
		//Main Hooks
		DrawQuestMain();
	}

	return TRUE;
}

BOOL Design::Stats()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_MAINMENU) || V_Options || !V_Design->ClearScreen(3) || V_Design->CharacterStats)
	{
		V_MenuObject = 0;
	}

	if (V_MenuObject != 1)
	{
		V_ClickIgnoreStat2 = FALSE;

		return FALSE;
	}

	INT LevelExperience = GetExp(GetUnitStat(Me, STAT_LEVEL)) - GetExp(GetUnitStat(Me, STAT_LEVEL) - 1);
	INT PlayerExperience = GetUnitStat(Me, STAT_EXP) - GetExp(GetUnitStat(Me, STAT_LEVEL) - 1);
	INT Resists[3] = {0, -40, -100};

	if (!V_StartingExperience)
		V_StartingExperience = GetUnitStat(Me, STAT_EXP);

	Rectangle(5, 80, 220, 425, 0, 1);

	DrawOut(5, 95, 3, 6, "%sÿc0: %d%%", V_ModStatAttackSpeed, GetUnitStat(Me, STAT_IAS));
	DrawOut(5, 105, 3, 6, "%sÿc0: %d%%", V_ModStatBlockRate, GetUnitStat(Me, STAT_FASTERBLOCK));
	DrawOut(5, 115, 3, 6, "%sÿc0: %d%%", V_ModStatCastRate, GetUnitStat(Me, STAT_FASTERCAST));
	DrawOut(5, 125, 3, 6, "%sÿc0: %d%%", V_ModStatHitRecovery, GetUnitStat(Me, STAT_FASTERHITRECOVERY));
	DrawOut(5, 135, 3, 6, "%sÿc0: %d%%", V_ModStatRunWalkSpeed, GetUnitStat(Me, STAT_FASTERRUNWALK));
	DrawOut(5, 145, 3, 6, "%sÿc0: %d%%", V_ModStatVelocity, GetUnitStat(Me, STAT_VELOCITYPERCENT));

	if (GetUnitStat(Me, STAT_REPLENISHLIFE) == 0)
	{
		DrawOut(5, 165, 3, 6, "%sÿc0: -", V_ModStatReplenishLife);
	}
	if (GetUnitStat(Me, STAT_REPLENISHLIFE) > 0)
	{
		DrawOut(5, 165, 3, 6, "%sÿc0: %d", V_ModStatReplenishLife, GetUnitStat(Me, STAT_REPLENISHLIFE));
	}
	DrawOut(5, 175, 3, 6, "%sÿc0: %d%%", V_ModStatRegenerateMana, GetUnitStat(Me, STAT_REGENERATEMANA) + 100);

	if (GetUnitStat(Me, STAT_DAMAGETOMANA) == 0)
	{
		DrawOut(5, 195, 3, 6, "%sÿc0: -%%", V_ModStatDamageTakenGoesToMana);
	}
	if (GetUnitStat(Me, STAT_DAMAGETOMANA) > 0)
	{
		DrawOut(5, 195, 3, 6, "%sÿc0: %d%%", V_ModStatDamageTakenGoesToMana, GetUnitStat(Me, STAT_DAMAGETOMANA));
	}

	if (GetUnitStat(Me, STAT_GOLDFIND) == 0)
	{
		DrawOut(5, 215, 3, 6, "%sÿc0: -%%", V_ModStatCurrencyFind);
	}
	if (GetUnitStat(Me, STAT_GOLDFIND) > 0)
	{
		DrawOut(5, 215, 3, 6, "%sÿc0: %d%%", V_ModStatCurrencyFind, GetUnitStat(Me, STAT_GOLDFIND));
	}

	if (GetUnitStat(Me, STAT_MAGICFIND) == 0)
	{
		DrawOut(5, 225, 3, 6, "%sÿc0: -%%", V_ModStatMagicFind);
	}
	if (GetUnitStat(Me, STAT_MAGICFIND) > 0)
	{
		DrawOut(5, 225, 3, 6, "%sÿc0: %d%%", V_ModStatMagicFind, GetUnitStat(Me, STAT_MAGICFIND));
	}

	DrawOut(5, 245, 3, 6, "%sÿc0: %d%%", V_ModStatFireResist, GetUnitStat(Me, STAT_FIRERESIST) + Resists[D2CLIENT_GetDifficulty()], GetUnitStat(Me, STAT_MAXFIRERESIST));
	DrawOut(5, 255, 3, 6, "%sÿc0: %d%%", V_ModStatColdResist, GetUnitStat(Me, STAT_COLDRESIST) + Resists[D2CLIENT_GetDifficulty()], GetUnitStat(Me, STAT_MAXCOLDRESIST));
	DrawOut(5, 265, 3, 6, "%sÿc0: %d%%", V_ModStatLightningResist, GetUnitStat(Me, STAT_LIGHTNINGRESIST) + Resists[D2CLIENT_GetDifficulty()], GetUnitStat(Me, STAT_MAXLIGHTNINGRESIST));
	DrawOut(5, 275, 3, 6, "%sÿc0: %d%%", V_ModStatPoisonResist, GetUnitStat(Me, STAT_POISONRESIST) + Resists[D2CLIENT_GetDifficulty()], GetUnitStat(Me, STAT_MAXPOISONRESIST));
	if (GetUnitStat(Me, STAT_DAMAGERESIST) == 0)
	{
		DrawOut(5, 285, 3, 6, "%sÿc0: -%%", V_ModStatPhysicalResist);
	}
	if (GetUnitStat(Me, STAT_DAMAGERESIST) > 0)
	{
		DrawOut(5, 285, 3, 6, "%sÿc0: %d%%", V_ModStatPhysicalResist, GetUnitStat(Me, STAT_DAMAGERESIST));
	}
	if (GetUnitStat(Me, STAT_MAGICRESIST) == 0)
	{
		DrawOut(5, 295, 3, 6, "%sÿc0: -%%", V_ModStatMagicResist);
	}
	if (GetUnitStat(Me, STAT_MAGICRESIST) > 0)
	{
		DrawOut(5, 295, 3, 6, "%sÿc0: %d%%", V_ModStatMagicResist, GetUnitStat(Me, STAT_MAGICRESIST));
	}

	DrawOut(5, 315, 3, 6, "%sÿc0: %d%%", V_ModStatMaximumFireResist, GetUnitStat(Me, STAT_MAXFIRERESIST) + 75);
	DrawOut(5, 325, 3, 6, "%sÿc0: %d%%", V_ModStatMaximumColdResist, GetUnitStat(Me, STAT_MAXCOLDRESIST) + 75);
	DrawOut(5, 335, 3, 6, "%sÿc0: %d%%", V_ModStatMaximumLightningResist, GetUnitStat(Me, STAT_MAXLIGHTNINGRESIST) + 75);
	DrawOut(5, 345, 3, 6, "%sÿc0: %d%%", V_ModStatMaximumPoisonResist, GetUnitStat(Me, STAT_MAXPOISONRESIST) + 75);

	if (GetUnitStat(Me, STAT_DAMAGEREDUCTION) == 0)
	{
		DrawOut(5, 365, 3, 6, "%sÿc0: -", V_ModStatDamageReduction);
	}
	if (GetUnitStat(Me, STAT_DAMAGEREDUCTION) > 0)
	{
		DrawOut(5, 365, 3, 6, "%sÿc0: %d", V_ModStatDamageReduction, GetUnitStat(Me, STAT_DAMAGEREDUCTION));
	}
	if (GetUnitStat(Me, STAT_MAGICDAMAGEREDUCTION) == 0)
	{
		DrawOut(5, 375, 3, 6, "%sÿc0: -", V_ModStatMagicDamageReduction);
	}
	if (GetUnitStat(Me, STAT_MAGICDAMAGEREDUCTION) > 0)
	{
		DrawOut(5, 375, 3, 6, "%sÿc0: %d", V_ModStatMagicDamageReduction, GetUnitStat(Me, STAT_MAGICDAMAGEREDUCTION));
	}

	if (GetUnitStat(Me, STAT_FIREABSORB) == 0 && GetUnitStat(Me, STAT_FIREABSORBPERCENT) == 0)
	{
		DrawOut(5, 395, 3, 6, "%sÿc0: - / -%%", V_ModStatFireAbsorb);
	}
	if (GetUnitStat(Me, STAT_FIREABSORB) > 0 && GetUnitStat(Me, STAT_FIREABSORBPERCENT) == 0)
	{
		DrawOut(5, 395, 3, 6, "%sÿc0: %d / -%%", V_ModStatFireAbsorb, GetUnitStat(Me, STAT_FIREABSORB));
	}
	if (GetUnitStat(Me, STAT_FIREABSORB) == 0 && GetUnitStat(Me, STAT_FIREABSORBPERCENT) > 0)
	{
		DrawOut(5, 395, 3, 6, "%sÿc0: - / %d%%", V_ModStatFireAbsorb, GetUnitStat(Me, STAT_FIREABSORBPERCENT));
	}
	if (GetUnitStat(Me, STAT_FIREABSORB) > 0 && GetUnitStat(Me, STAT_FIREABSORBPERCENT) > 0)
	{
		DrawOut(5, 395, 3, 6, "%sÿc0: %d / %d%%", V_ModStatFireAbsorb, GetUnitStat(Me, STAT_FIREABSORB), GetUnitStat(Me, STAT_FIREABSORBPERCENT));
	}
	if (GetUnitStat(Me, STAT_COLDABSORB) == 0 && GetUnitStat(Me, STAT_COLDABSORBPERCENT) == 0)
	{
		DrawOut(5, 405, 3, 6, "%sÿc0: - / -%%", V_ModStatColdAbsorb);
	}
	if (GetUnitStat(Me, STAT_COLDABSORB) > 0 && GetUnitStat(Me, STAT_COLDABSORBPERCENT) == 0)
	{
		DrawOut(5, 405, 3, 6, "%sÿc0: %d / -%%", V_ModStatColdAbsorb, GetUnitStat(Me, STAT_COLDABSORB));
	}
	if (GetUnitStat(Me, STAT_COLDABSORB) == 0 && GetUnitStat(Me, STAT_COLDABSORBPERCENT) > 0)
	{
		DrawOut(5, 405, 3, 6, "%sÿc0: - / %d%%", V_ModStatColdAbsorb, GetUnitStat(Me, STAT_COLDABSORBPERCENT));
	}
	if (GetUnitStat(Me, STAT_COLDABSORB) > 0 && GetUnitStat(Me, STAT_COLDABSORBPERCENT) > 0)
	{
		DrawOut(5, 405, 3, 6, "%sÿc0: %d / %d%%", V_ModStatColdAbsorb, GetUnitStat(Me, STAT_COLDABSORB), GetUnitStat(Me, STAT_COLDABSORBPERCENT));
	}
	if (GetUnitStat(Me, STAT_LIGHTNINGABSORB) == 0 && GetUnitStat(Me, STAT_LIGHTNINGABSORBPERCENT) == 0)
	{
		DrawOut(5, 415, 3, 6, "%sÿc0: - / -%%", V_ModStatLightningAbsorb);
	}
	if (GetUnitStat(Me, STAT_LIGHTNINGABSORB) > 0 && GetUnitStat(Me, STAT_LIGHTNINGABSORBPERCENT) == 0)
	{
		DrawOut(5, 415, 3, 6, "%sÿc0: %d / -%%", V_ModStatLightningAbsorb, GetUnitStat(Me, STAT_LIGHTNINGABSORB));
	}
	if (GetUnitStat(Me, STAT_LIGHTNINGABSORB) == 0 && GetUnitStat(Me, STAT_LIGHTNINGABSORBPERCENT) > 0)
	{
		DrawOut(5, 415, 3, 6, "%sÿc0: - / %d%%", V_ModStatLightningAbsorb, GetUnitStat(Me, STAT_LIGHTNINGABSORBPERCENT));
	}
	if (GetUnitStat(Me, STAT_LIGHTNINGABSORB) > 0 && GetUnitStat(Me, STAT_LIGHTNINGABSORBPERCENT) > 0)
	{
		DrawOut(5, 415, 3, 6, "%sÿc0: %d / %d%%", V_ModStatLightningAbsorb, GetUnitStat(Me, STAT_LIGHTNINGABSORB), GetUnitStat(Me, STAT_LIGHTNINGABSORBPERCENT));
	}
	if (GetUnitStat(Me, STAT_MAGICABSORB) == 0 && GetUnitStat(Me, STAT_MAGICABSORBPERCENT) == 0)
	{
		DrawOut(5, 425, 3, 6, "%sÿc0: - / -%%", V_ModStatMagicAbsorb);
	}
	if (GetUnitStat(Me, STAT_MAGICABSORB) > 0 && GetUnitStat(Me, STAT_MAGICABSORBPERCENT) == 0)
	{
		DrawOut(5, 425, 3, 6, "%sÿc0: %d / -%%", V_ModStatMagicAbsorb, GetUnitStat(Me, STAT_MAGICABSORB));
	}
	if (GetUnitStat(Me, STAT_MAGICABSORB) == 0 && GetUnitStat(Me, STAT_MAGICABSORBPERCENT) > 0)
	{
		DrawOut(5, 425, 3, 6, "%sÿc0: - / %d%%", V_ModStatMagicAbsorb, GetUnitStat(Me, STAT_MAGICABSORBPERCENT));
	}
	if (GetUnitStat(Me, STAT_MAGICABSORB) > 0)
	{
		DrawOut(5, 425, 3, 6, "%sÿc0: %d / %d%%", V_ModStatMagicAbsorb, GetUnitStat(Me, STAT_MAGICABSORB), GetUnitStat(Me, STAT_MAGICABSORBPERCENT));
	}

	if (GetUnitStat(Me, STAT_CRUSHINGBLOW) > 0)
	{
		DrawOut(5, 445, 3, 6, "%sÿc0: %d%%", V_ModStatCrushingBlow, GetUnitStat(Me, STAT_CRUSHINGBLOW));
	}
	if (GetUnitStat(Me, STAT_CRUSHINGBLOW) == 0)
	{
		DrawOut(5, 445, 3, 6, "%sÿc0: -%%", V_ModStatCrushingBlow);
	}
	if (GetUnitStat(Me, STAT_DEADLYSTRIKE) > 0)
	{
		DrawOut(5, 455, 3, 6, "%sÿc0: %d%%", V_ModStatDeadlyStrike, GetUnitStat(Me, STAT_DEADLYSTRIKE));
	}
	if (GetUnitStat(Me, STAT_DEADLYSTRIKE) == 0)
	{
		DrawOut(5, 455, 3, 6, "%sÿc0: -%%", V_ModStatDeadlyStrike);
	}
	if (GetUnitStat(Me, STAT_OPENWOUNDS) > 0)
	{
		DrawOut(5, 465, 3, 6, "%sÿc0: %d%%", V_ModStatOpenWounds, GetUnitStat(Me, STAT_OPENWOUNDS));
	}
	if (GetUnitStat(Me, STAT_OPENWOUNDS) == 0)
	{
		DrawOut(5, 465, 3, 6, "%sÿc0: -%%", V_ModStatOpenWounds);
	}
	if (GetUnitStat(Me, STAT_LIFELEECH) > 0)
	{
		DrawOut(5, 485, 3, 6, "%sÿc0: %d%%", V_ModStatLifeStolenPerHit, GetUnitStat(Me, STAT_LIFELEECH));
	}
	if (GetUnitStat(Me, STAT_LIFELEECH) == 0)
	{
		DrawOut(5, 485, 3, 6, "%sÿc0: -%%", V_ModStatLifeStolenPerHit);
	}
	if (GetUnitStat(Me, STAT_MANALEECH) > 0)
	{
		DrawOut(5, 495, 3, 6, "%sÿc0: %d%%", V_ModStatManaStolenPerHit, GetUnitStat(Me, STAT_MANALEECH));
	}
	if (GetUnitStat(Me, STAT_MANALEECH) == 0)
	{
		DrawOut(5, 495, 3, 6, "%sÿc0: -%%", V_ModStatManaStolenPerHit);
	}

	//Close Button
	if ((*p_D2CLIENT_MouseX >= MouseOverX1X1 && *p_D2CLIENT_MouseX <= MouseOverX2X1) && (*p_D2CLIENT_MouseY >= MouseOverY1X1 && *p_D2CLIENT_MouseY <= MouseOverY2X1))
	{
		V_ClickIgnoreStat2 = TRUE;

		V_Design->TextHook(TextBX2, TextBY2, 1, 0, 6, 1, "X");

		if (!V_SoundPlus)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundPlus = TRUE;

		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

				V_ToggleStatMenu = FALSE;
				V_MenuObject = 0;
				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		V_ClickIgnoreStat2 = FALSE;

		V_Design->TextHook(TextBX2, TextBY2, 0, 0, 6, 1, "X");

		V_SoundPlus = FALSE;
	}

	return TRUE;
}

BOOL Design::Ability()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_MAINMENU) || V_Options || !V_Design->ClearScreen(3) || V_Design->CharacterStats)
	{
		V_SideQuestExpansion = -1;

		ResetQuestsMenu();
		ResetQuestsText();

		V_SelectedQuestPage = 1;
		V_SelectedQuestPageText = 1;

		V_SideQuestListPages = 1;

		V_MenuObject = 0;
	}

	if (V_MenuObject != 4)
	{
		V_ClickIgnoreAbility2 = FALSE;

		return FALSE;
	}

	//Ignore Click
	V_ClickIgnoreAbility2 = TRUE;

	//Menu Boxes
	Rectangle(5, 30, 780, 470, 0, 2);
	Frame(5, 65, 780, 400);
	Frame(5, 65, 390, 400);

	//Title
	TextHook(TitleTextX, TitleTextY, 4, 0, 1, 1, V_KeyItemStrMain);

	//Close Button
	if ((*p_D2CLIENT_MouseX >= MouseOverX1 && *p_D2CLIENT_MouseX <= MouseOverX2) && (*p_D2CLIENT_MouseY >= MouseOverY1 && *p_D2CLIENT_MouseY <= MouseOverY2))
	{
		V_Design->TextHook(TextBX, TextBY, 3, 0, 1, 1, V_SideQuestStrClose);

		if (!V_SoundPlus)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundPlus = TRUE;

		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_SideQuestExpansion = -1;

				ResetQuestsMenu();
				ResetQuestsText();

				V_SelectedQuestPage = 1;
				V_SelectedQuestPageText = 1;

				V_SideQuestListPages = 1;

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

				V_ToggleAbilityMenu = FALSE;
				V_MenuObject = 0;
				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		TextHook(TextBX, TextBY, 0, 0, 1, 1, V_SideQuestStrClose);

		V_SoundPlus = FALSE;
	}

	//Event Back Button List
	if (V_SideQuestBack)
	{
		ResetQuestsMenu();

		if (V_SelectedQuestPage == 1)
		{
			V_SideQuestExpansion = -1;
		}
		else if (V_SelectedQuestPage > 1)
		{
			V_SelectedQuestPage -= 1;
		}

		V_SideQuestBack = FALSE;
	}

	//Event Next Button List
	if (V_SideQuestNext)
	{
		if (V_SideQuestExpansion > -1)
		{
			if (V_SelectedQuestPage < V_SideQuestListPages)
			{
				V_SelectedQuestPage += 1;
			}
		}

		V_SideQuestNext = FALSE;
	}

	//Event Back Button Text
	if (V_SideQuestBackText)
	{
		V_ToggleKeyItem[V_SideQuestSelected][V_SideQuestExpansion] = 0;

		V_SideQuestBackText = FALSE;
	}

	//Event Next Button Text
	if (V_SideQuestNextText)
	{
		V_ToggleKeyItem[V_SideQuestSelected][V_SideQuestExpansion] = 1;

		V_SideQuestNextText = FALSE;
	}

	if (V_SideQuestExpansion > -1)
	{
		//Load script list
		LoadKeyItemList(V_SideQuestExpansion, V_SelectedQuestPage);

		//List Hooks
		DrawQuestList();

		//Text Hooks
		DrawQuestText();
	}
	else
	{
		//Main Hooks
		DrawQuestMain();
	}

	return TRUE;
}

BOOL Design::Guide()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (GetUIVar(UI_MAINMENU) || V_Options || !V_Design->ClearScreen(3) || V_Design->CharacterStats)
	{
		V_MenuObject = 0;
	}

	if (V_MenuObject != 5)
	{
		V_ShowLadderPage = 0;

		V_ClickIgnoreGuide2 = FALSE;
		V_ClickIgnoreGuide3 = FALSE;
		V_ClickIgnoreGuide4 = FALSE;

		return FALSE;
	}

	Rectangle(5, 60, 790, 425, 0, 5); //Transparency 1 - Transparent, 5 - Opaque
	Rectangle(5, 30, 100, 30, 0, 5);

	if (!V_Expansion)
	{
		DrawOut(18, 44, 4, 1, V_LadderSoftStr);
	}
	else
	{
		DrawOut(18, 44, 2, 1, V_LadderLodStr);
	}

	DrawOut(10, 80, 4, 0, "No.");
	DrawOut(55, 80, 4, 0, V_LadderLevelStr);
	DrawOut(92, 80, 4, 0, V_LadderRankStr);
	DrawOut(130, 80, 4, 0, V_LadderClassStr);
	DrawOut(180, 80, 4, 0, V_LadderNameStr);
	DrawOut(340, 80, 4, 0, V_LadderExpStr);
	DrawOut(450, 80, 4, 0, V_LadderNoteStr);

	DrawOut(10, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, "%d.", 1 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, AddCommasNoZero(V_LadderLevel[0 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, AddCommasNoZero(V_LadderRank[0 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[0 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, V_LadderClassAbrv[V_LadderClass[0 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, V_LadderClassAbrv[V_LadderClass[0 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, V_LadderName[0 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, AddCommasNoZeroNotice(V_LadderExp[0 + (V_ShowLadderPage * 25)], 0, 0));
	DrawOut(450, 80 + 16, CheckEntryColor((V_ShowLadderPage * 25) + 0), 0, V_LadderNote[0 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, "%d.", 2 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, AddCommasNoZero(V_LadderLevel[1 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, AddCommasNoZero(V_LadderRank[1 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[1 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, V_LadderClassAbrv[V_LadderClass[1 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, V_LadderClassAbrv[V_LadderClass[1 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, V_LadderName[1 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, AddCommasNoZeroNotice(V_LadderExp[1 + (V_ShowLadderPage * 25)], 0, 1));
	DrawOut(450, 80 + (16 * 2), CheckEntryColor((V_ShowLadderPage * 25) + 1), 0, V_LadderNote[1 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, "%d.", 3 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, AddCommasNoZero(V_LadderLevel[2 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, AddCommasNoZero(V_LadderRank[2 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[2 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, V_LadderClassAbrv[V_LadderClass[2 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, V_LadderClassAbrv[V_LadderClass[2 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, V_LadderName[2 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, AddCommasNoZeroNotice(V_LadderExp[2 + (V_ShowLadderPage * 25)], 0, 2));
	DrawOut(450, 80 + (16 * 3), CheckEntryColor((V_ShowLadderPage * 25) + 2), 0, V_LadderNote[2 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, "%d.", 4 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, AddCommasNoZero(V_LadderLevel[3 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, AddCommasNoZero(V_LadderRank[3 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[3 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, V_LadderClassAbrv[V_LadderClass[3 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, V_LadderClassAbrv[V_LadderClass[3 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, V_LadderName[3 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, AddCommasNoZeroNotice(V_LadderExp[3 + (V_ShowLadderPage * 25)], 0, 3));
	DrawOut(450, 80 + (16 * 4), CheckEntryColor((V_ShowLadderPage * 25) + 3), 0, V_LadderNote[3 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, "%d.", 5 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, AddCommasNoZero(V_LadderLevel[4 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, AddCommasNoZero(V_LadderRank[4 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[4 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, V_LadderClassAbrv[V_LadderClass[4 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, V_LadderClassAbrv[V_LadderClass[4 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, V_LadderName[4 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, AddCommasNoZeroNotice(V_LadderExp[4 + (V_ShowLadderPage * 25)], 0, 4));
	DrawOut(450, 80 + (16 * 5), CheckEntryColor((V_ShowLadderPage * 25) + 4), 0, V_LadderNote[4 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, "%d.", 6 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, AddCommasNoZero(V_LadderLevel[5 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, AddCommasNoZero(V_LadderRank[5 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[5 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, V_LadderClassAbrv[V_LadderClass[5 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, V_LadderClassAbrv[V_LadderClass[5 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, V_LadderName[5 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, AddCommasNoZeroNotice(V_LadderExp[5 + (V_ShowLadderPage * 25)], 0, 5));
	DrawOut(450, 80 + (16 * 6), CheckEntryColor((V_ShowLadderPage * 25) + 5), 0, V_LadderNote[5 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, "%d.", 7 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, AddCommasNoZero(V_LadderLevel[6 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, AddCommasNoZero(V_LadderRank[6 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[6 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, V_LadderClassAbrv[V_LadderClass[6 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, V_LadderClassAbrv[V_LadderClass[6 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, V_LadderName[6 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, AddCommasNoZeroNotice(V_LadderExp[6 + (V_ShowLadderPage * 25)], 0, 6));
	DrawOut(450, 80 + (16 * 7), CheckEntryColor((V_ShowLadderPage * 25) + 6), 0, V_LadderNote[6 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, "%d.", 8 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, AddCommasNoZero(V_LadderLevel[7 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, AddCommasNoZero(V_LadderRank[7 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[7 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, V_LadderClassAbrv[V_LadderClass[7 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, V_LadderClassAbrv[V_LadderClass[7 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, V_LadderName[7 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, AddCommasNoZeroNotice(V_LadderExp[7 + (V_ShowLadderPage * 25)], 0, 7));
	DrawOut(450, 80 + (16 * 8), CheckEntryColor((V_ShowLadderPage * 25) + 7), 0, V_LadderNote[7 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, "%d.", 9 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, AddCommasNoZero(V_LadderLevel[8 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, AddCommasNoZero(V_LadderRank[8 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[8 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, V_LadderClassAbrv[V_LadderClass[8 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, V_LadderClassAbrv[V_LadderClass[8 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, V_LadderName[8 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, AddCommasNoZeroNotice(V_LadderExp[8 + (V_ShowLadderPage * 25)], 0, 8));
	DrawOut(450, 80 + (16 * 9), CheckEntryColor((V_ShowLadderPage * 25) + 8), 0, V_LadderNote[8 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, "%d.", 10 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, AddCommasNoZero(V_LadderLevel[9 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, AddCommasNoZero(V_LadderRank[9 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[9 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, V_LadderClassAbrv[V_LadderClass[9 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, V_LadderClassAbrv[V_LadderClass[9 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, V_LadderName[9 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, AddCommasNoZeroNotice(V_LadderExp[9 + (V_ShowLadderPage * 25)], 0, 9));
	DrawOut(450, 80 + (16 * 10), CheckEntryColor((V_ShowLadderPage * 25) + 9), 0, V_LadderNote[9 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, "%d.", 11 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, AddCommasNoZero(V_LadderLevel[10 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, AddCommasNoZero(V_LadderRank[10 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[10 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, V_LadderClassAbrv[V_LadderClass[10 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, V_LadderClassAbrv[V_LadderClass[10 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, V_LadderName[10 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, AddCommasNoZeroNotice(V_LadderExp[10 + (V_ShowLadderPage * 25)], 0, 10));
	DrawOut(450, 80 + (16 * 11), CheckEntryColor((V_ShowLadderPage * 25) + 10), 0, V_LadderNote[10 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, "%d.", 12 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, AddCommasNoZero(V_LadderLevel[11 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, AddCommasNoZero(V_LadderRank[11 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[11 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, V_LadderClassAbrv[V_LadderClass[11 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, V_LadderClassAbrv[V_LadderClass[11 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, V_LadderName[11 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, AddCommasNoZeroNotice(V_LadderExp[11 + (V_ShowLadderPage * 25)], 0, 11));
	DrawOut(450, 80 + (16 * 12), CheckEntryColor((V_ShowLadderPage * 25) + 11), 0, V_LadderNote[11 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, "%d.", 13 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, AddCommasNoZero(V_LadderLevel[12 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, AddCommasNoZero(V_LadderRank[12 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[12 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, V_LadderClassAbrv[V_LadderClass[12 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, V_LadderClassAbrv[V_LadderClass[12 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, V_LadderName[12 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, AddCommasNoZeroNotice(V_LadderExp[12 + (V_ShowLadderPage * 25)], 0, 12));
	DrawOut(450, 80 + (16 * 13), CheckEntryColor((V_ShowLadderPage * 25) + 12), 0, V_LadderNote[12 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, "%d.", 14 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, AddCommasNoZero(V_LadderLevel[13 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, AddCommasNoZero(V_LadderRank[13 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[13 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, V_LadderClassAbrv[V_LadderClass[13 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, V_LadderClassAbrv[V_LadderClass[13 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, V_LadderName[13 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, AddCommasNoZeroNotice(V_LadderExp[13 + (V_ShowLadderPage * 25)], 0, 13));
	DrawOut(450, 80 + (16 * 14), CheckEntryColor((V_ShowLadderPage * 25) + 13), 0, V_LadderNote[13 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, "%d.", 15 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, AddCommasNoZero(V_LadderLevel[14 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, AddCommasNoZero(V_LadderRank[14 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[14 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, V_LadderClassAbrv[V_LadderClass[14 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, V_LadderClassAbrv[V_LadderClass[14 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, V_LadderName[14 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, AddCommasNoZeroNotice(V_LadderExp[14 + (V_ShowLadderPage * 25)], 0, 14));
	DrawOut(450, 80 + (16 * 15), CheckEntryColor((V_ShowLadderPage * 25) + 14), 0, V_LadderNote[14 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, "%d.", 16 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, AddCommasNoZero(V_LadderLevel[15 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, AddCommasNoZero(V_LadderRank[15 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[15 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, V_LadderClassAbrv[V_LadderClass[15 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, V_LadderClassAbrv[V_LadderClass[15 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, V_LadderName[15 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, AddCommasNoZeroNotice(V_LadderExp[15 + (V_ShowLadderPage * 25)], 0, 15));
	DrawOut(450, 80 + (16 * 16), CheckEntryColor((V_ShowLadderPage * 25) + 15), 0, V_LadderNote[15 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, "%d.", 17 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, AddCommasNoZero(V_LadderLevel[16 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, AddCommasNoZero(V_LadderRank[16 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[16 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, V_LadderClassAbrv[V_LadderClass[16 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, V_LadderClassAbrv[V_LadderClass[16 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, V_LadderName[16 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, AddCommasNoZeroNotice(V_LadderExp[16 + (V_ShowLadderPage * 25)], 0, 16));
	DrawOut(450, 80 + (16 * 17), CheckEntryColor((V_ShowLadderPage * 25) + 16), 0, V_LadderNote[16 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, "%d.", 18 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, AddCommasNoZero(V_LadderLevel[17 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, AddCommasNoZero(V_LadderRank[17 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[17 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, V_LadderClassAbrv[V_LadderClass[17 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, V_LadderClassAbrv[V_LadderClass[17 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, V_LadderName[17 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, AddCommasNoZeroNotice(V_LadderExp[17 + (V_ShowLadderPage * 25)], 0, 17));
	DrawOut(450, 80 + (16 * 18), CheckEntryColor((V_ShowLadderPage * 25) + 17), 0, V_LadderNote[17 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, "%d.", 19 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, AddCommasNoZero(V_LadderLevel[18 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, AddCommasNoZero(V_LadderRank[18 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[18 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, V_LadderClassAbrv[V_LadderClass[18 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, V_LadderClassAbrv[V_LadderClass[18 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, V_LadderName[18 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, AddCommasNoZeroNotice(V_LadderExp[18 + (V_ShowLadderPage * 25)], 0, 18));
	DrawOut(450, 80 + (16 * 19), CheckEntryColor((V_ShowLadderPage * 25) + 18), 0, V_LadderNote[18 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, "%d.", 20 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, AddCommasNoZero(V_LadderLevel[19 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, AddCommasNoZero(V_LadderRank[19 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[19 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, V_LadderClassAbrv[V_LadderClass[19 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, V_LadderClassAbrv[V_LadderClass[19 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, V_LadderName[19 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, AddCommasNoZeroNotice(V_LadderExp[19 + (V_ShowLadderPage * 25)], 0, 19));
	DrawOut(450, 80 + (16 * 20), CheckEntryColor((V_ShowLadderPage * 25) + 19), 0, V_LadderNote[19 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, "%d.", 21 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, AddCommasNoZero(V_LadderLevel[20 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, AddCommasNoZero(V_LadderRank[20 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[20 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, V_LadderClassAbrv[V_LadderClass[20 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, V_LadderClassAbrv[V_LadderClass[20 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, V_LadderName[20 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, AddCommasNoZeroNotice(V_LadderExp[20 + (V_ShowLadderPage * 25)], 0, 20));
	DrawOut(450, 80 + (16 * 21), CheckEntryColor((V_ShowLadderPage * 25) + 20), 0, V_LadderNote[20 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, "%d.", 22 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, AddCommasNoZero(V_LadderLevel[21 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, AddCommasNoZero(V_LadderRank[21 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[21 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, V_LadderClassAbrv[V_LadderClass[21 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, V_LadderClassAbrv[V_LadderClass[21 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, V_LadderName[21 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, AddCommasNoZeroNotice(V_LadderExp[21 + (V_ShowLadderPage * 25)], 0, 21));
	DrawOut(450, 80 + (16 * 22), CheckEntryColor((V_ShowLadderPage * 25) + 21), 0, V_LadderNote[21 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, "%d.", 23 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, AddCommasNoZero(V_LadderLevel[22 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, AddCommasNoZero(V_LadderRank[22 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[22 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, V_LadderClassAbrv[V_LadderClass[22 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, V_LadderClassAbrv[V_LadderClass[22 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, V_LadderName[22 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, AddCommasNoZeroNotice(V_LadderExp[22 + (V_ShowLadderPage * 25)], 0, 22));
	DrawOut(450, 80 + (16 * 23), CheckEntryColor((V_ShowLadderPage * 25) + 22), 0, V_LadderNote[22 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, "%d.", 24 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, AddCommasNoZero(V_LadderLevel[23 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, AddCommasNoZero(V_LadderRank[23 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[23 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, V_LadderClassAbrv[V_LadderClass[23 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, V_LadderClassAbrv[V_LadderClass[23 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, V_LadderName[23 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, AddCommasNoZeroNotice(V_LadderExp[23 + (V_ShowLadderPage * 25)], 0, 23));
	DrawOut(450, 80 + (16 * 24), CheckEntryColor((V_ShowLadderPage * 25) + 23), 0, V_LadderNote[23 + (V_ShowLadderPage * 25)]);

	DrawOut(10, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, "%d.", 25 + (V_ShowLadderPage * 25));
	DrawOut(55, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, AddCommasNoZero(V_LadderLevel[24 + (V_ShowLadderPage * 25)], 0));
	DrawOut(92, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, AddCommasNoZero(V_LadderRank[24 + (V_ShowLadderPage * 25)], 0));
	if (V_LadderClass[24 + (V_ShowLadderPage * 25)] > 400)
	{
		DrawOut(130, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, V_LadderClassAbrv[V_LadderClass[24 + (V_ShowLadderPage * 25)] - 400]);
	}
	else
	{
		DrawOut(130, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, V_LadderClassAbrv[V_LadderClass[24 + (V_ShowLadderPage * 25)]]);
	}
	DrawOut(180, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, V_LadderName[24 + (V_ShowLadderPage * 25)]);
	DrawOut(340, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, AddCommasNoZeroNotice(V_LadderExp[24 + (V_ShowLadderPage * 25)], 0, 24));
	DrawOut(450, 80 + (16 * 25), CheckEntryColor((V_ShowLadderPage * 25) + 24), 0, V_LadderNote[24 + (V_ShowLadderPage * 25)]);

	//Close Button
	if ((*p_D2CLIENT_MouseX >= MouseOverX1X2 && *p_D2CLIENT_MouseX <= MouseOverX2X2) && (*p_D2CLIENT_MouseY >= MouseOverY1X2 && *p_D2CLIENT_MouseY <= MouseOverY2X2))
	{
		V_ClickIgnoreGuide2 = TRUE;

		V_Design->TextHook(TextBX3, TextBY3, 1, 0, 6, 1, "X");

		if (!V_SoundCloseB)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundCloseB = TRUE;

		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

				V_ToggleGuideMenu = FALSE;
				V_MenuObject = 0;
				V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CLOSEMENU);
			}
		}
	}
	else
	{
		V_ClickIgnoreGuide2 = FALSE;

		V_Design->TextHook(TextBX3, TextBY3, 0, 0, 6, 1, "X");

		V_SoundCloseB = FALSE;
	}

	//Minus Button
	if ((*p_D2CLIENT_MouseX >= MouseOverX1X3 && *p_D2CLIENT_MouseX <= MouseOverX2X3) && (*p_D2CLIENT_MouseY >= MouseOverY1X3 && *p_D2CLIENT_MouseY <= MouseOverY2X3))
	{
		V_ClickIgnoreGuide3 = TRUE;

		V_Design->TextHook(TextBX4, TextBY4, 3, 0, 6, 1, "-");

		if (!V_SoundMinus)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundMinus = TRUE;

		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

				if (V_ShowLadderPage > 0)
					V_ShowLadderPage--;
			}
		}
	}
	else
	{
		V_ClickIgnoreGuide3 = FALSE;

		V_Design->TextHook(TextBX4, TextBY4, 0, 0, 6, 1, "-");

		V_SoundMinus = FALSE;
	}

	//Plus Button
	if ((*p_D2CLIENT_MouseX >= MouseOverX1X4 && *p_D2CLIENT_MouseX <= MouseOverX2X4) && (*p_D2CLIENT_MouseY >= MouseOverY1X4 && *p_D2CLIENT_MouseY <= MouseOverY2X4))
	{
		V_ClickIgnoreGuide4 = TRUE;

		V_Design->TextHook(TextBX5, TextBY5, 3, 0, 6, 1, "+");

		if (!V_SoundPlus)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundPlus = TRUE;

		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

				if (V_ShowLadderPage < 39)
					V_ShowLadderPage++;
			}
		}
	}
	else
	{
		V_ClickIgnoreGuide4 = FALSE;

		V_Design->TextHook(TextBX5, TextBY5, 0, 0, 6, 1, "+");

		V_SoundPlus = FALSE;
	}

	//Page Number
	V_Design->TextHook(TextBX6, TextBY6, 0, 0, 4, 1, "Page %d", V_ShowLadderPage + 1);

	return TRUE;
}

BOOL Design::Settings()
{
	if (!ClientReady(FALSE))
		return FALSE;

	if (V_MenuObject != 6)
		return FALSE;

	Rectangle(5, 80, 220, 425, 0, 1);

	DrawOut(10, 100, 0, 1, "Coming soon...");

	return TRUE;
}

//Hellfire II Menu Internals
VOID Design::DrawMenuFrame(INT X, INT Y, INT SizeX, INT SizeY, INT FrameColor)
{
	INT XR = X - 2;
	INT YB = Y - 2;

	BoxHook(X, Y, SizeX, 2, FrameColor, 5, 0);
	BoxHook(X, YB + SizeY, SizeX, 2, FrameColor, 5, 0);
	BoxHook(X, Y, 2, SizeY, FrameColor, 5, 0);
	BoxHook(XR + SizeX, Y, 2, SizeY, FrameColor, 5, 0);
}

VOID Design::DrawClassBlock(INT X, INT Y)
{
	INT Wide = 115;
	INT Tall = 15;

	V_Design->BoxHook(X, Y, Wide, Tall, 15, 5, 0);
}
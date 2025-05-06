#include "Hack.h"

#include "HF2 Ladder.h"

using namespace std;

typedef INT64 far* LPINT64;

CONFIGURATION DATA_SETTINGS[] =
{
	{ "Default", "MenuStr", NULL, STRING, &V_MenuStr },
	{ "Default", "MenuStrContextX", NULL, INTEGER, &V_MenuStrContextX },
	{ "Default", "MenuStrContextY", NULL, INTEGER, &V_MenuStrContextY },
	{ "Default", "MenuStrRectX", NULL, INTEGER, &V_MenuStrRectX },
	{ "Default", "MenuStrRectY", NULL, INTEGER, &V_MenuStrRectY },
	{ "Default", "MenuStrRectWidth", NULL, INTEGER, &V_MenuStrRectWidth },
	{ "Default", "MenuStrRectHeight", NULL, INTEGER, &V_MenuStrRectHeight },

	{ "Default", "MenuStrStat", NULL, STRING, &V_MenuStrStat },
	{ "Default", "MenuStrInfo", NULL, STRING, &V_MenuStrInfo },
	{ "Default", "MenuStrMission", NULL, STRING, &V_MenuStrMission },
	{ "Default", "MenuStrAbility", NULL, STRING, &V_MenuStrAbility },
	{ "Default", "MenuStrGuide", NULL, STRING, &V_MenuStrGuide },
	{ "Default", "MenuStrCalc", NULL, STRING, &V_MenuStrCalc },
	{ "Default", "MenuStrSetting", NULL, STRING, &V_MenuStrSetting },

	{ "Default", "MenuStrSpace", NULL, STRING, &V_MenuStrSpace },

	{ "Default", "ModStatAttackSpeed", NULL, STRING, &V_ModStatAttackSpeed },
	{ "Default", "ModStatBlockRate", NULL, STRING, &V_ModStatBlockRate },
	{ "Default", "ModStatCastRate", NULL, STRING, &V_ModStatCastRate },
	{ "Default", "ModStatHitRecovery", NULL, STRING, &V_ModStatHitRecovery },
	{ "Default", "ModStatRunWalkSpeed", NULL, STRING, &V_ModStatRunWalkSpeed },
	{ "Default", "ModStatVelocity", NULL, STRING, &V_ModStatVelocity },
	{ "Default", "ModStatReplenishLife", NULL, STRING, &V_ModStatReplenishLife },
	{ "Default", "ModStatRegenerateMana", NULL, STRING, &V_ModStatRegenerateMana },
	{ "Default", "ModStatDamageTakenGoesToMana", NULL, STRING, &V_ModStatDamageTakenGoesToMana },
	{ "Default", "ModStatCurrencyFind", NULL, STRING, &V_ModStatCurrencyFind },
	{ "Default", "ModStatMagicFind", NULL, STRING, &V_ModStatMagicFind },
	{ "Default", "ModStatFireResist", NULL, STRING, &V_ModStatFireResist },
	{ "Default", "ModStatColdResist", NULL, STRING, &V_ModStatColdResist },
	{ "Default", "ModStatLightningResist", NULL, STRING, &V_ModStatLightningResist },
	{ "Default", "ModStatPoisonResist", NULL, STRING, &V_ModStatPoisonResist },
	{ "Default", "ModStatPhysicalResist", NULL, STRING, &V_ModStatPhysicalResist },
	{ "Default", "ModStatMagicResist", NULL, STRING, &V_ModStatMagicResist },
	{ "Default", "ModStatMaximumFireResist", NULL, STRING, &V_ModStatMaximumFireResist },
	{ "Default", "ModStatMaximumColdResist", NULL, STRING, &V_ModStatMaximumColdResist },
	{ "Default", "ModStatMaximumLightningResist", NULL, STRING, &V_ModStatMaximumLightningResist },
	{ "Default", "ModStatMaximumPoisonResist", NULL, STRING, &V_ModStatMaximumPoisonResist },
	{ "Default", "ModStatDamageReduction", NULL, STRING, &V_ModStatDamageReduction },
	{ "Default", "ModStatMagicDamageReduction", NULL, STRING, &V_ModStatMagicDamageReduction },
	{ "Default", "ModStatFireAbsorb", NULL, STRING, &V_ModStatFireAbsorb },
	{ "Default", "ModStatColdAbsorb", NULL, STRING, &V_ModStatColdAbsorb },
	{ "Default", "ModStatLightningAbsorb", NULL, STRING, &V_ModStatLightningAbsorb },
	{ "Default", "ModStatMagicAbsorb", NULL, STRING, &V_ModStatMagicAbsorb },
	{ "Default", "ModStatCrushingBlow", NULL, STRING, &V_ModStatCrushingBlow },
	{ "Default", "ModStatDeadlyStrike", NULL, STRING, &V_ModStatDeadlyStrike },
	{ "Default", "ModStatOpenWounds", NULL, STRING, &V_ModStatOpenWounds },
	{ "Default", "ModStatLifeStolenPerHit", NULL, STRING, &V_ModStatLifeStolenPerHit },
	{ "Default", "ModStatManaStolenPerHit", NULL, STRING, &V_ModStatManaStolenPerHit },
	{ "Default", "ModStatReduceVendorPrice", NULL, STRING, &V_ModStatReduceVendorPrice },

	{ "Default", "MainStr", NULL, STRING, &V_CounterMainStr },
	{ "Default", "CloseStr", NULL, STRING, &V_CounterCloseStr },
	{ "Default", "BackStr", NULL, STRING, &V_CounterBackStr },
	{ "Default", "NextStr", NULL, STRING, &V_CounterNextStr },
	{ "Default", "KilledStr", NULL, STRING, &V_CounterKilledStr },
	{ "Default", "BarKilledStr", NULL, STRING, &V_CounterBarKilledStr },
	{ "Default", "UnknownStr", NULL, STRING, &V_CounterUnknownStr },
	{ "Default", "UnavailableStr", NULL, STRING, &V_QuestUnavailableStr },

	{ "Default", "MainStrContextX", NULL, INTEGER, &V_MainStrContextX },
	{ "Default", "MainStrContextY", NULL, INTEGER, &V_MainStrContextY },
	{ "Default", "MainStrRectX", NULL, INTEGER, &V_MainStrRectX },
	{ "Default", "MainStrRectY", NULL, INTEGER, &V_MainStrRectY },
	{ "Default", "MainStrRectWidth", NULL, INTEGER, &V_MainStrRectWidth },
	{ "Default", "MainStrRectHeight", NULL, INTEGER, &V_MainStrRectHeight },
	{ "Default", "MainStrMouseOverX1", NULL, INTEGER, &V_MainStrMouseOverX1 },
	{ "Default", "MainStrMouseOverY1", NULL, INTEGER, &V_MainStrMouseOverY1 },
	{ "Default", "MainButtonWidth", NULL, INTEGER, &V_MainButtonWidth },
	{ "Default", "MainButtonHeight", NULL, INTEGER, &V_MainButtonHeight },

	{ "Default", "ClockStr", NULL, STRING, &V_ClockStr },
	{ "Default", "DobStr", NULL, STRING, &V_DobStr },
	{ "Default", "LastStr", NULL, STRING, &V_LastStr },
	{ "Default", "ClockMillisecondsStr", NULL, STRING, &V_ClockMillisecondsStr },
	{ "Default", "ClockSecondsStr", NULL, STRING, &V_ClockSecondsStr },
	{ "Default", "ClockMinutesStr", NULL, STRING, &V_ClockMinutesStr },
	{ "Default", "ClockHoursStr", NULL, STRING, &V_ClockHoursStr },

	{ "Default", "RankStr", NULL, STRING, &V_RankStr },

	{ "Default", "GameNormStr", NULL, STRING, &V_GameNormStr },
	{ "Default", "GameNmStr", NULL, STRING, &V_GameNmStr },
	{ "Default", "GameHellStr", NULL, STRING, &V_GameHellStr },

	{ "Default", "GameWonStr", NULL, STRING, &V_GameWonStr },
	{ "Default", "GameDrawStr", NULL, STRING, &V_GameDrawStr },
	{ "Default", "GameLostStr", NULL, STRING, &V_GameLostStr },

	{ "Default", "TimesKilledStr", NULL, STRING, &V_TimesKilledStr },

	{ "Default", "HealthUsedStr", NULL, STRING, &V_HealthUsedStr },
	{ "Default", "ManaUsedStr", NULL, STRING, &V_ManaUsedStr },
	{ "Default", "PortalsTakenStr", NULL, STRING, &V_PortalsTakenStr },
	{ "Default", "WaypointUsedStr", NULL, STRING, &V_WaypointUsedStr },
	{ "Default", "ChangedAreaStr", NULL, STRING, &V_ChangedAreaStr },
	{ "Default", "ShrineUsedStr", NULL, STRING, &V_ShrineUsedStr },
	{ "Default", "TimesHealedStr", NULL, STRING, &V_TimesHealedStr },

	{ "Default", "TravelDistanceStr", NULL, STRING, &V_TravelDistanceStr },
	{ "Default", "TravelYardStr", NULL, STRING, &V_TravelYardStr },
	{ "Default", "TravelMileStr", NULL, STRING, &V_TravelMileStr },

	{ "Default", "TotalGoldStr", NULL, STRING, &V_TotalGoldStr },
	{ "Default", "GoldThousandStr", NULL, STRING, &V_GoldThousandStr },
	{ "Default", "GoldMillionStr", NULL, STRING, &V_GoldMillionStr },
	{ "Default", "GoldBillionStr", NULL, STRING, &V_GoldBillionStr },
	{ "Default", "GoldTrillionStr", NULL, STRING, &V_GoldTrillionStr },

	{ "Default", "EquipWeaponStr", NULL, STRING, &V_EquipWeaponStr },
	{ "Default", "EquipArmorStr", NULL, STRING, &V_EquipArmorStr },
	{ "Default", "EquipMiscStr", NULL, STRING, &V_EquipMiscStr },

	{ "Default", "BestAndyStr", NULL, STRING, &V_BestAndyStr },
	{ "Default", "BestDurielStr", NULL, STRING, &V_BestDurielStr },
	{ "Default", "BestMephStr", NULL, STRING, &V_BestMephStr },
	{ "Default", "BestDiabloStr", NULL, STRING, &V_BestDiabloStr },
	{ "Default", "BestBaalStr", NULL, STRING, &V_BestBaalStr },

	{ "Default", "BestAndyNMStr", NULL, STRING, &V_BestAndyNMStr },
	{ "Default", "BestDurielNMStr", NULL, STRING, &V_BestDurielNMStr },
	{ "Default", "BestMephNMStr", NULL, STRING, &V_BestMephNMStr },
	{ "Default", "BestDiabloNMStr", NULL, STRING, &V_BestDiabloNMStr },
	{ "Default", "BestBaalNMStr", NULL, STRING, &V_BestBaalNMStr },

	{ "Default", "BestAndyHellStr", NULL, STRING, &V_BestAndyHellStr },
	{ "Default", "BestDurielHellStr", NULL, STRING, &V_BestDurielHellStr },
	{ "Default", "BestMephHellStr", NULL, STRING, &V_BestMephHellStr },
	{ "Default", "BestDiabloHellStr", NULL, STRING, &V_BestDiabloHellStr },
	{ "Default", "BestBaalHellStr", NULL, STRING, &V_BestBaalHellStr },

	{ "Default", "LadderLevelStr", NULL, STRING, &V_LadderLevelStr },
	{ "Default", "LadderClassStr", NULL, STRING, &V_LadderClassStr },
	{ "Default", "LadderNameStr", NULL, STRING, &V_LadderNameStr },
	{ "Default", "LadderExpStr", NULL, STRING, &V_LadderExpStr },
	{ "Default", "LadderRankStr", NULL, STRING, &V_LadderRankStr },
	{ "Default", "LadderSoftStr", NULL, STRING, &V_LadderSoftStr },
	{ "Default", "LadderHardStr", NULL, STRING, &V_LadderHardStr },
	{ "Default", "LadderLodStr", NULL, STRING, &V_LadderLodStr },
	{ "Default", "LadderNoteStr", NULL, STRING, &V_LadderNoteStr }
};

CONFIGURATION PLAYER_DATA[] =
{
	{ "Default", "Test0", NULL, INTEGER, &V_LoadTest },
	{ "Default", "Update0", NULL, INTEGER, &V_LoadUpdate },

	{ "Default", "Games0", NULL, INTEGER, &V_Games0 },
	{ "Default", "Games1", NULL, INTEGER, &V_Games1 },
	{ "Default", "Games2", NULL, INTEGER, &V_Games2 },

	{ "Default", "GamesWon", NULL, INTEGER, &V_GamesWon },
	{ "Default", "GamesDraw", NULL, INTEGER, &V_GamesDraw },
	{ "Default", "GamesLost", NULL, INTEGER, &V_GamesLost },

	{ "Default", "TimesKilled", NULL, INTEGER, &V_TimesKilled },

	{ "Default", "HealthUsed", NULL, INTEGER, &V_HealthUsed },
	{ "Default", "ManaUsed", NULL, INTEGER, &V_ManaUsed },
	{ "Default", "PortalsTaken", NULL, INTEGER, &V_PortalsTaken },
	{ "Default", "TimesHealed", NULL, INTEGER, &V_TimesHealed },
	{ "Default", "WaypointUsed", NULL, INTEGER, &V_WaypointUsed },
	{ "Default", "ChangedArea", NULL, INTEGER, &V_ChangedArea },
	{ "Default", "ShrineUsed", NULL, INTEGER, &V_ShrineUsed },

	{ "Default", "ClockMilliseconds", NULL, INTEGER, &V_ClockMilliseconds },
	{ "Default", "ClockSeconds", NULL, INTEGER, &V_ClockSeconds },
	{ "Default", "ClockMinutes", NULL, INTEGER, &V_ClockMinutes },
	{ "Default", "ClockHours", NULL, INTEGER, &V_ClockHours },

	{ "Default", "BornYear", NULL, INTEGER, &V_ClockDoBYear },
	{ "Default", "BornMonth", NULL, INTEGER, &V_ClockDoBMonth },
	{ "Default", "BornDay", NULL, INTEGER, &V_ClockDoBDay },
	{ "Default", "BornSecond", NULL, INTEGER, &V_ClockDoBSecond },
	{ "Default", "BornMinute", NULL, INTEGER, &V_ClockDoBMinute },
	{ "Default", "BornHour", NULL, INTEGER, &V_ClockDoBHour },

	{ "Default", "LastYear", NULL, INTEGER, &V_ClockLastYear },
	{ "Default", "LastMonth", NULL, INTEGER, &V_ClockLastMonth },
	{ "Default", "LastDay", NULL, INTEGER, &V_ClockLastDay },
	{ "Default", "LastSecond", NULL, INTEGER, &V_ClockLastSecond },
	{ "Default", "LastMinute", NULL, INTEGER, &V_ClockLastMinute },
	{ "Default", "LastHour", NULL, INTEGER, &V_ClockLastHour },

	{ "Default", "BestAndyHour", NULL, INTEGER, &V_BestAndyHour },
	{ "Default", "BestAndyMin", NULL, INTEGER, &V_BestAndyMin },
	{ "Default", "BestAndySec", NULL, INTEGER, &V_BestAndySec },
	{ "Default", "BestDurielHour", NULL, INTEGER, &V_BestDurielHour },
	{ "Default", "BestDurielMin", NULL, INTEGER, &V_BestDurielMin },
	{ "Default", "BestDurielSec", NULL, INTEGER, &V_BestDurielSec },
	{ "Default", "BestMephHour", NULL, INTEGER, &V_BestMephHour },
	{ "Default", "BestMephMin", NULL, INTEGER, &V_BestMephMin },
	{ "Default", "BestMephSec", NULL, INTEGER, &V_BestMephSec },
	{ "Default", "BestDiabloHour", NULL, INTEGER, &V_BestDiabloHour },
	{ "Default", "BestDiabloMin", NULL, INTEGER, &V_BestDiabloMin },
	{ "Default", "BestDiabloSec", NULL, INTEGER, &V_BestDiabloSec },
	{ "Default", "BestBaalHour", NULL, INTEGER, &V_BestBaalHour },
	{ "Default", "BestBaalMin", NULL, INTEGER, &V_BestBaalMin },
	{ "Default", "BestBaalSec", NULL, INTEGER, &V_BestBaalSec },

	{ "Default", "BestAndyNMHour", NULL, INTEGER, &V_BestAndyNMHour },
	{ "Default", "BestAndyNMMin", NULL, INTEGER, &V_BestAndyNMMin },
	{ "Default", "BestAndyNMSec", NULL, INTEGER, &V_BestAndyNMSec },
	{ "Default", "BestDurielNMHour", NULL, INTEGER, &V_BestDurielNMHour },
	{ "Default", "BestDurielNMMin", NULL, INTEGER, &V_BestDurielNMMin },
	{ "Default", "BestDurielNMSec", NULL, INTEGER, &V_BestDurielNMSec },
	{ "Default", "BestMephNMHour", NULL, INTEGER, &V_BestMephNMHour },
	{ "Default", "BestMephNMMin", NULL, INTEGER, &V_BestMephNMMin },
	{ "Default", "BestMephNMSec", NULL, INTEGER, &V_BestMephNMSec },
	{ "Default", "BestDiabloNMHour", NULL, INTEGER, &V_BestDiabloNMHour },
	{ "Default", "BestDiabloNMMin", NULL, INTEGER, &V_BestDiabloNMMin },
	{ "Default", "BestDiabloNMSec", NULL, INTEGER, &V_BestDiabloNMSec },
	{ "Default", "BestBaalNMHour", NULL, INTEGER, &V_BestBaalNMHour },
	{ "Default", "BestBaalNMMin", NULL, INTEGER, &V_BestBaalNMMin },
	{ "Default", "BestBaalNMSec", NULL, INTEGER, &V_BestBaalNMSec },

	{ "Default", "BestAndyHellHour", NULL, INTEGER, &V_BestAndyHellHour },
	{ "Default", "BestAndyHellMin", NULL, INTEGER, &V_BestAndyHellMin },
	{ "Default", "BestAndyHellSec", NULL, INTEGER, &V_BestAndyHellSec },
	{ "Default", "BestDurielHellHour", NULL, INTEGER, &V_BestDurielHellHour },
	{ "Default", "BestDurielHellMin", NULL, INTEGER, &V_BestDurielHellMin },
	{ "Default", "BestDurielHellSec", NULL, INTEGER, &V_BestDurielHellSec },
	{ "Default", "BestMephHellHour", NULL, INTEGER, &V_BestMephHellHour },
	{ "Default", "BestMephHellMin", NULL, INTEGER, &V_BestMephHellMin },
	{ "Default", "BestMephHellSec", NULL, INTEGER, &V_BestMephHellSec },
	{ "Default", "BestDiabloHellHour", NULL, INTEGER, &V_BestDiabloHellHour },
	{ "Default", "BestDiabloHellMin", NULL, INTEGER, &V_BestDiabloHellMin },
	{ "Default", "BestDiabloHellSec", NULL, INTEGER, &V_BestDiabloHellSec },
	{ "Default", "BestBaalHellHour", NULL, INTEGER, &V_BestBaalHellHour },
	{ "Default", "BestBaalHellMin", NULL, INTEGER, &V_BestBaalHellMin },
	{ "Default", "BestBaalHellSec", NULL, INTEGER, &V_BestBaalHellSec },

	{ "Default", "NewCharacter", NULL, BOOLEAN, &V_NewCharacter },
	{ "Default", "NormalWon", NULL, BOOLEAN, &V_NormalWon },
	{ "Default", "NMWon", NULL, BOOLEAN, &V_NMWon },
	{ "Default", "HellWon", NULL, BOOLEAN, &V_HellWon },

	{ "Default", "TravelDistanceMile", NULL, INTEGER, &V_TravelDistanceMile },
	{ "Default", "TravelDistanceYard", NULL, INTEGER, &V_TravelDistanceYard },

	{ "Default", "GoldCopper", NULL, INTEGER, &V_GoldCopper },
	{ "Default", "GoldSilver", NULL, INTEGER, &V_GoldSilver },
	{ "Default", "GoldThousand", NULL, INTEGER, &V_GoldThousand },
	{ "Default", "GoldMillion", NULL, INTEGER, &V_GoldMillion },
	{ "Default", "GoldBillion", NULL, INTEGER, &V_GoldBillion },
	{ "Default", "GoldTrillion", NULL, INTEGER, &V_GoldTrillion },

	{ "Default", "EquipHead", NULL, INTEGER, &V_EquipHead },

	{ "Default", "EquipHead", NULL, INTEGER, &V_EquipHead },
	{ "Default", "EquipAmulet", NULL, INTEGER, &V_EquipAmulet },
	{ "Default", "EquipBody", NULL, INTEGER, &V_EquipBody },
	{ "Default", "EquipRightW", NULL, INTEGER, &V_EquipRightW },
	{ "Default", "EquipLeftW", NULL, INTEGER, &V_EquipLeftW },
	{ "Default", "EquipRightR", NULL, INTEGER, &V_EquipRightR },
	{ "Default", "EquipLeftR", NULL, INTEGER, &V_EquipLeftR },
	{ "Default", "EquipBelt", NULL, INTEGER, &V_EquipBelt },
	{ "Default", "EquipFeet", NULL, INTEGER, &V_EquipFeet },
	{ "Default", "EquipGloves", NULL, INTEGER, &V_EquipGloves },
	{ "Default", "EquipRight2W", NULL, INTEGER, &V_EquipRight2W },
	{ "Default", "EquipLeft2W", NULL, INTEGER, &V_EquipLeft2W },

	{ "Default", "EquipHead", NULL, INTEGER, &V_EquipHead },

	{ "Default", "LadderId", NULL, INTEGER, &V_MyLadderID },
	{ "Default", "LadderNote", NULL, STRING, &V_MyLadderNote }
};

CONFIGURATION LADDER_DATA[] =
{
	{ "Default", "LastLadderId", NULL, INTEGER, &V_LastLadderID },
};

BOOL LoadDataSettings()
{
	CHAR File[MAX_PATH], Returned[100000];

	CHAR Key[32];

	GetModuleDirectory();

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, "\\Interface\\Data\\Data_Settings.ini");

	for (INT i = 0; i < ArraySize(DATA_SETTINGS); i++)
	{
		GetPrivateProfileStringA(DATA_SETTINGS[i].Section, DATA_SETTINGS[i].Name, DATA_SETTINGS[i].Default, Returned, sizeof(Returned), File);

		if (DATA_SETTINGS[i].Type == BOOLEAN)
			*(LPBOOL)DATA_SETTINGS[i].Variable = Bool(Returned);

		else if (DATA_SETTINGS[i].Type == INTEGER)
			*(LPINT)DATA_SETTINGS[i].Variable = Integer(Returned);

		else if (DATA_SETTINGS[i].Type == STRING)
			strncpy_s((LPSTR)DATA_SETTINGS[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	for (INT i = 0; i < 20; i++)
	{
		sprintf_s(Key, "InfoList0Str%d", i);

		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_InfoListMainStr[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "InfoList1Str%d", i);

		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_InfoListOneStr[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "InfoList2Str%d", i);

		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_InfoListTwoStr[i], sizeof(Returned), Returned, sizeof(Returned));
	}

	for (INT i = 0; i < MAXCLASSES + 8; i++)
	{
		sprintf_s(Key, "ClassStr%d", i);

		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_ClassStr[i], sizeof(Returned), Returned, sizeof(Returned));
	}

	for (INT i = 0; i < MAXCLASSES + 8; i++)
	{
		sprintf_s(Key, "ClassStrAbrv%d", i);

		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_LadderClassAbrv[i], sizeof(Returned), Returned, sizeof(Returned));
	}

	for (INT i = 0; i < MAXMONSTERS; i++)
	{
		sprintf_s(Key, "MonsterStr%d", i);

		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_MonsterStr[i], sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL LoadLadder()
{
	CHAR File[MAX_PATH], Returned[100000];

	CHAR Key[32];

	GetModuleDirectory();

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));

	if(V_Expansion)
		strcat_s(File, "\\Interface\\Data\\Ladder.ini");
	else
		strcat_s(File, "\\Interface\\Data\\LadderStnd.ini");

	for (INT i = 0; i < ArraySize(LADDER_DATA); i++)
	{
		GetPrivateProfileStringA(LADDER_DATA[i].Section, LADDER_DATA[i].Name, LADDER_DATA[i].Default, Returned, sizeof(Returned), File);

		if (LADDER_DATA[i].Type == BOOLEAN)
			*(LPBOOL)LADDER_DATA[i].Variable = Bool(Returned);

		else if (LADDER_DATA[i].Type == INTEGER)
			*(LPINT)LADDER_DATA[i].Variable = Integer(Returned);

		else if (LADDER_DATA[i].Type == STRING)
			strncpy_s((LPSTR)LADDER_DATA[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		sprintf_s(Key, "LadderName%d", i);

		GetPrivateProfileStringA("Ladder", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_LadderName[i], sizeof(Returned), Returned, sizeof(Returned));
		strncpy_s(V_LadderNameStart[i], sizeof(Returned), Returned, sizeof(Returned));
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		sprintf_s(Key, "LadderId%d", i);

		GetPrivateProfileStringA("Ladder", Key, NULL, Returned, sizeof(Returned), File);

		V_LadderID[i] = Integer(Returned);
		V_LadderIDStart[i] = Integer(Returned);
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		sprintf_s(Key, "LadderLevel%d", i);

		GetPrivateProfileStringA("Ladder", Key, NULL, Returned, sizeof(Returned), File);

		V_LadderLevel[i] = Integer(Returned);
		V_LadderLevelStart[i] = Integer(Returned);
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		sprintf_s(Key, "LadderClass%d", i);

		GetPrivateProfileStringA("Ladder", Key, NULL, Returned, sizeof(Returned), File);

		V_LadderClass[i] = Integer(Returned);
		V_LadderClassStart[i] = Integer(Returned);
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		sprintf_s(Key, "LadderExp%d", i);

		GetPrivateProfileStringA("Ladder", Key, NULL, Returned, sizeof(Returned), File);

		V_LadderExp[i] = Integer64(Returned);
		V_LadderExpStart[i] = Integer64(Returned);
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		sprintf_s(Key, "LadderRank%d", i);

		GetPrivateProfileStringA("Ladder", Key, NULL, Returned, sizeof(Returned), File);

		V_LadderRank[i] = Integer(Returned);
		V_LadderRankStart[i] = Integer(Returned);
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		sprintf_s(Key, "LadderNote%d", i);

		GetPrivateProfileStringA("Ladder", Key, NULL, Returned, sizeof(Returned), File);

		strncpy_s(V_LadderNote[i], sizeof(Returned), Returned, sizeof(Returned));
		strncpy_s(V_LadderNoteStart[i], sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL SaveLadder()
{
	CHAR File[MAX_PATH], Returned[100000];

	CHAR Key[32];

	GetModuleDirectory();

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	if (V_Expansion)
		strcat_s(File, "\\Interface\\Data\\Ladder.ini");
	else
		strcat_s(File, "\\Interface\\Data\\LadderStnd.ini");

	for (INT i = 0; i < ArraySize(LADDER_DATA); i++)
	{
		if (LADDER_DATA[i].Type == BOOLEAN)
			WritePrivateProfileIntA(LADDER_DATA[i].Section, LADDER_DATA[i].Name, *(LPBOOL)LADDER_DATA[i].Variable, File);

		else if (LADDER_DATA[i].Type == INTEGER)
			WritePrivateProfileIntA(LADDER_DATA[i].Section, LADDER_DATA[i].Name, *(LPINT)LADDER_DATA[i].Variable, File);
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if (V_UpdLadderName[i] != V_LadderNameStart[i])
		{
			sprintf_s(Key, "LadderName%d", i);

			WritePrivateProfileStringA("Ladder", Key, V_UpdLadderName[i], File);
		}
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if (V_UpdLadderID[i] != V_LadderIDStart[i])
		{
			sprintf_s(Key, "LadderId%d", i);

			WritePrivateProfileIntA("Ladder", Key, V_UpdLadderID[i], File);
		}
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if (V_UpdLadderLevel[i] != V_LadderLevelStart[i])
		{
			sprintf_s(Key, "LadderLevel%d", i);

			WritePrivateProfileIntA("Ladder", Key, V_UpdLadderLevel[i], File);
		}
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if (V_UpdLadderClass[i] != V_LadderClassStart[i])
		{
			sprintf_s(Key, "LadderClass%d", i);

			WritePrivateProfileIntA("Ladder", Key, V_UpdLadderClass[i], File);
		}
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if (V_UpdLadderExp[i] != V_LadderExpStart[i])
		{
			sprintf_s(Key, "LadderExp%d", i);

			WritePrivateProfileInt64A("Ladder", Key, V_UpdLadderExp[i], File);
		}
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if (V_UpdLadderRank[i] != V_LadderRankStart[i])
		{
			sprintf_s(Key, "LadderRank%d", i);

			WritePrivateProfileIntA("Ladder", Key, V_UpdLadderRank[i], File);
		}
	}

	for (INT i = 0; i < MAXLADDER; i++)
	{
		if (V_UpdLadderNote[i] != V_LadderNoteStart[i])
		{
			sprintf_s(Key, "LadderNote%d", i);

			WritePrivateProfileStringA("Ladder", Key, V_UpdLadderNote[i], File);
		}
	}

	return TRUE;
}

BOOL SavePlayerData()
{
	CHAR File[MAX_PATH];

	CHAR Key[32];

	std::string str;
	char* data = V_CharacterName;
	int size = sizeof(V_CharacterName);
	str.assign(data, size);

	V_FilePath = SAVEPATH + str;
	
	GetModuleDirectory();

	std::vector<char> v(V_FilePath.length() + 1);
	std::strcpy(&v[0], V_FilePath.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < ArraySize(PLAYER_DATA); i++)
	{
		if (PLAYER_DATA[i].Type == BOOLEAN)
			WritePrivateProfileIntA(PLAYER_DATA[i].Section, PLAYER_DATA[i].Name, *(LPBOOL)PLAYER_DATA[i].Variable, File);

		else if (PLAYER_DATA[i].Type == INTEGER)
			WritePrivateProfileIntA(PLAYER_DATA[i].Section, PLAYER_DATA[i].Name, *(LPINT)PLAYER_DATA[i].Variable, File);
	}

	if (D2CLIENT_GetDifficulty() == 0)
	{
		for (INT i = 0; i < MAXMONSTERS; i++)
		{
			if (V_MonsterUnit[0][i] != V_MonsterUnitStart[0][i])
			{
				sprintf_s(Key, "Monster%d", i);

				WritePrivateProfileIntA("Monster", Key, V_MonsterUnit[0][i], File);
			}
		}
	}
	else if (D2CLIENT_GetDifficulty() == 1)
	{
		for (INT i = 0; i < MAXMONSTERS; i++)
		{
			if (V_MonsterUnit[1][i] != V_MonsterUnitStart[1][i])
			{
				sprintf_s(Key, "MonsterNm%d", i);

				WritePrivateProfileIntA("Monster", Key, V_MonsterUnit[1][i], File);
			}
		}
	}
	else if (D2CLIENT_GetDifficulty() == 2)
	{
		for (INT i = 0; i < MAXMONSTERS; i++)
		{
			if (V_MonsterUnit[2][i] != V_MonsterUnitStart[2][i])
			{
				sprintf_s(Key, "MonsterHell%d", i);

				WritePrivateProfileIntA("Monster", Key, V_MonsterUnit[2][i], File);
			}
		}
	}

	for (INT i = 0; i < MAXCLASSES; i++)
	{
		sprintf_s(Key, "Class%d", i);

		WritePrivateProfileIntA("Class", Key, V_Class[i], File);
	}

	for (INT i = 0; i < 7; i++)
	{
		for (INT j = 0; j < MAXKEYITEMS; j++)
		{
			sprintf_s(Key, "ToggleKeyItem%dE%d", j, i);

			WritePrivateProfileIntA("Keyitem", Key, V_ToggleKeyItem[j][i], File);
		}
	}

	return TRUE;
}

BOOL LoadPlayerData()
{
	CHAR File[MAX_PATH], Returned[100000];

	CHAR Key[32];

	std::string str;
	char* data = V_CharacterName;
	int size = sizeof(V_CharacterName);
	str.assign(data, size);

	V_FilePath = SAVEPATH + str;

	GetModuleDirectory();

	std::vector<char> v(V_FilePath.length() + 1);
	std::strcpy(&v[0], V_FilePath.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < ArraySize(PLAYER_DATA); i++)
	{
		GetPrivateProfileStringA(PLAYER_DATA[i].Section, PLAYER_DATA[i].Name, PLAYER_DATA[i].Default, Returned, sizeof(Returned), File);

		if (PLAYER_DATA[i].Type == BOOLEAN)
			*(LPBOOL)PLAYER_DATA[i].Variable = Bool(Returned);

		else if (PLAYER_DATA[i].Type == INTEGER)
			*(LPINT)PLAYER_DATA[i].Variable = Integer(Returned);

		else if (PLAYER_DATA[i].Type == STRING)
			strncpy_s((LPSTR)PLAYER_DATA[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	if (D2CLIENT_GetDifficulty() == 0)
	{
		for (INT i = 0; i < MAXMONSTERS; i++)
		{
			sprintf_s(Key, "Monster%d", i);

			GetPrivateProfileStringA("Monster", Key, NULL, Returned, sizeof(Returned), File);

			V_MonsterUnit[0][i] = Integer(Returned);
			V_MonsterUnitStart[0][i] = Integer(Returned);
		}
	}
	else if (D2CLIENT_GetDifficulty() == 1)
	{
		for (INT i = 0; i < MAXMONSTERS; i++)
		{
			sprintf_s(Key, "MonsterNm%d", i);

			GetPrivateProfileStringA("Monster", Key, NULL, Returned, sizeof(Returned), File);

			V_MonsterUnit[1][i] = Integer(Returned);
			V_MonsterUnitStart[1][i] = Integer(Returned);
		}
	}
	else if (D2CLIENT_GetDifficulty() == 2)
	{
		for (INT i = 0; i < MAXMONSTERS; i++)
		{
			sprintf_s(Key, "MonsterHell%d", i);

			GetPrivateProfileStringA("Monster", Key, NULL, Returned, sizeof(Returned), File);

			V_MonsterUnit[2][i] = Integer(Returned);
			V_MonsterUnitStart[2][i] = Integer(Returned);
		}
	}

	for (INT i = 0; i < MAXCLASSES; i++)
	{
		sprintf_s(Key, "Class%d", i);

		GetPrivateProfileStringA("Class", Key, NULL, Returned, sizeof(Returned), File);

		V_Class[i] = Integer(Returned);
	}

	for (INT i = 0; i < 6; i++)
	{
		for (INT j = 0; j < MAXKEYITEMS; j++)
		{
			sprintf_s(Key, "ToggleKeyItem%dE%d", j, i);

			GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);

			V_ToggleKeyItem[j][i] = Integer(Returned);
		}
	}

	return TRUE;
}

BOOL CreateSaveFile()
{
	CHAR File[MAX_PATH];
	CHAR FileB[MAX_PATH];

	std::string str;
	char* data = V_CharacterName;
	int size = sizeof(V_CharacterName);
	str.assign(data, size);

	V_FilePath = SAVEPATH + str;

	GetModuleDirectory();

	std::vector<char> v(V_FilePath.length() + 1);
	std::strcpy(&v[0], V_FilePath.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	strncpy_s(FileB, sizeof(FileB), V_FileNamePath, sizeof(FileB));
	strcat_s(FileB, "\\Interface\\Data\\Default.ini");

    ifstream source(FileB, ios::binary);
    ofstream dest(File, ios::binary);

    istreambuf_iterator<char> begin_source(source);
    istreambuf_iterator<char> end_source;
    ostreambuf_iterator<char> begin_dest(dest); 
    copy(begin_source, end_source, begin_dest);

    source.close();
    dest.close();

	return TRUE;
}

BOOL LoadSuccess()
{
	if (V_LoadTest == NULL_ENTRY)
	{
		V_LoadUpdate = 0;

		SetInfoVars();
		V_LoadTest = 1;

		SetClockDoB();

		V_NewCharacter = FALSE;
		V_NormalWon = FALSE;
		V_NMWon = FALSE;
		V_HellWon = FALSE;

		V_LoadUpdate = DATAUPDATE + 1;

		return FALSE;
	}	

	if (V_LoadUpdate < (DATAUPDATE + 1))
	{
		SetInfoVars();
		V_LoadTest = 1;

		V_LoadUpdate = DATAUPDATE + 1;
	}

	return TRUE;
}
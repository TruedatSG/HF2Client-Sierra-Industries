#include "Hack.h"

VOID SetClockDoB()
{
	SYSTEMTIME Time;
	GetLocalTime(&Time);

	V_ClockDoBYear = Time.wYear;
	V_ClockDoBMonth = Time.wMonth;
	V_ClockDoBDay = Time.wDay;
	V_ClockDoBHour = Time.wHour;
	V_ClockDoBMinute = Time.wMinute;
	V_ClockDoBSecond = Time.wSecond;
}

VOID SetClockLast()
{
	SYSTEMTIME Time;
	GetLocalTime(&Time);

	V_ClockLastYear = Time.wYear;
	V_ClockLastMonth = Time.wMonth;
	V_ClockLastDay = Time.wDay;
	V_ClockLastHour = Time.wHour;
	V_ClockLastMinute = Time.wMinute;
	V_ClockLastSecond = Time.wSecond;
}

VOID SetInfoMenuVars()
{
	V_MainStrContextX = 0;
	V_MainStrContextY = 0;
	V_MainStrRectX = 0;
	V_MainStrRectY = 0;
	V_MainStrRectWidth = 0;
	V_MainStrRectHeight = 0;
	V_MainStrMouseOverX1 = 0;
	V_MainStrMouseOverY1 = 0;
	V_MainButtonWidth = 0;
	V_MainButtonHeight = 0;

	V_CounterMainStr[0] = NULL;
	V_CounterBackStr[0] = NULL;
	V_CounterNextStr[0] = NULL;
	V_CounterCloseStr[0] = NULL;
	V_CounterKilledStr[0] = NULL;
	V_CounterBarKilledStr[0] = NULL;
	V_CounterUnknownStr[0] = NULL;

	V_ClockStr[0] = NULL;
	V_DobStr[0] = NULL;
	V_LastStr[0] = NULL;
	V_ClockMillisecondsStr[0] = NULL;
	V_ClockSecondsStr[0] = NULL;
	V_ClockMinutesStr[0] = NULL;
	V_ClockHoursStr[0] = NULL;

	V_BestAndyStr[0] = NULL;
	V_BestDurielStr[0] = NULL;
	V_BestMephStr[0] = NULL;
	V_BestDiabloStr[0] = NULL;
	V_BestBaalStr[0] = NULL;

	V_BestAndyNMStr[0] = NULL;
	V_BestDurielNMStr[0] = NULL;
	V_BestMephNMStr[0] = NULL;
	V_BestDiabloNMStr[0] = NULL;
	V_BestBaalNMStr[0] = NULL;

	V_BestAndyHellStr[0] = NULL;
	V_BestDurielHellStr[0] = NULL;
	V_BestMephHellStr[0] = NULL;
	V_BestDiabloHellStr[0] = NULL;
	V_BestBaalHellStr[0] = NULL;

	V_GameNormStr[0] = NULL;
	V_GameNmStr[0] = NULL;
	V_GameHellStr[0] = NULL;

	V_GameWonStr[0] = NULL;
	V_GameDrawStr[0] = NULL;
	V_GameLostStr[0] = NULL;

	V_TimesKilledStr[0] = NULL;

	V_HealthUsedStr[0] = NULL;
	V_ManaUsedStr[0] = NULL;
	V_PortalsTakenStr[0] = NULL;
	V_WaypointUsedStr[0] = NULL;
	V_ChangedAreaStr[0] = NULL;
	V_ShrineUsedStr[0] = NULL;
	V_TimesHealedStr[0] = NULL;

	V_TravelDistanceStr[0] = NULL;
	V_TravelYardStr[0] = NULL;
	V_TravelMileStr[0] = NULL;

	V_TotalGoldStr[0] = NULL;
	V_GoldThousandStr[0] = NULL;
	V_GoldMillionStr[0] = NULL;
	V_GoldBillionStr[0] = NULL;
	V_GoldTrillionStr[0] = NULL;

	V_EquipWeaponStr[0] = NULL;
	V_EquipArmorStr[0] = NULL;
	V_EquipMiscStr[0] = NULL;

	for (INT i = 0; i < 27; i++)
	{
		V_ClassStr[i][0] = NULL;
	}

	for (INT i = 0; i < 20; i++)
	{
		V_InfoListMainStr[i][0] = NULL;
		V_InfoListOneStr[i][0] = NULL;
		V_InfoListTwoStr[i][0] = NULL;
		V_InfoListThreeStr[i][0] = NULL;
		V_InfoListFourStr[i][0] = NULL;
		V_InfoListFiveStr[i][0] = NULL;
		V_InfoListSixStr[i][0] = NULL;
		V_InfoListSevenStr[i][0] = NULL;
		V_InfoListEightStr[i][0] = NULL;
		V_InfoListNineStr[i][0] = NULL;
		V_InfoListTenStr[i][0] = NULL;
		V_InfoListElevenStr[i][0] = NULL;
		V_InfoListTwelveStr[i][0] = NULL;
		V_InfoListThirteenStr[i][0] = NULL;
		V_InfoListFourteenStr[i][0] = NULL;
		V_InfoListFifteenStr[i][0] = NULL;
		V_InfoListSixteenStr[i][0] = NULL;
		V_InfoListSeventeenStr[i][0] = NULL;
		V_InfoListEighteenStr[i][0] = NULL;
		V_InfoListNineteenStr[i][0] = NULL;
		V_InfoListTwentyStr[i][0] = NULL;
	}
}

VOID SetInfoVars()
{
	//Info data updates
	//Checking for NULL entries
	if (V_LoadUpdate < 2)
	{
		//Update1
		V_Games0 = 0;
		V_Games1 = 0;
		V_Games2 = 0;
	}

	if (V_LoadUpdate < 3)
	{
		//Update2
		V_ClockMilliseconds = 0;
		V_ClockSeconds = 0;
		V_ClockMinutes = 0;
		V_ClockHours = 0;

		V_ClockLastYear = 0;
		V_ClockLastMonth = 0;
		V_ClockLastDay = 0;
		V_ClockLastHour = 0;
		V_ClockLastMinute = 0;
		V_ClockLastSecond = 0;
	}

	if (V_LoadUpdate < 4)
	{
		//Update3
		for (INT i = 0; i < MAXCLASSES; i++)
		{
			V_Class[i] = 0;
		}
	}

	if (V_LoadUpdate < 5)
	{
		//Update4
		V_TimesKilled = 0;
	}

	if (V_LoadUpdate < 6)
	{
		//Update5
		V_GamesWon = 0;
		V_GamesDraw = 0;
		V_GamesLost = 0;
	}

	if (V_LoadUpdate < 7)
	{
		//Update6
		V_HealthUsed = 0;
		V_ManaUsed = 0;
		V_PortalsTaken = 0;
		V_TimesHealed = 0;
		V_WaypointUsed = 0;

		V_BestAndyHour = 0;
		V_BestAndyMin = 0;
		V_BestAndySec = 0;
		V_BestDurielHour = 0;
		V_BestDurielMin = 0;
		V_BestDurielSec = 0;
		V_BestMephHour = 0;
		V_BestMephMin = 0;
		V_BestMephSec = 0;
		V_BestDiabloHour = 0;
		V_BestDiabloMin = 0;
		V_BestDiabloSec = 0;
		V_BestBaalHour = 0;
		V_BestBaalMin = 0;
		V_BestBaalSec = 0;

		V_BestAndyNMHour = 0;
		V_BestAndyNMMin = 0;
		V_BestAndyNMSec = 0;
		V_BestDurielNMHour = 0;
		V_BestDurielNMMin = 0;
		V_BestDurielNMSec = 0;
		V_BestMephNMHour = 0;
		V_BestMephNMMin = 0;
		V_BestMephNMSec = 0;
		V_BestDiabloNMHour = 0;
		V_BestDiabloNMMin = 0;
		V_BestDiabloNMSec = 0;
		V_BestBaalNMHour = 0;
		V_BestBaalNMMin = 0;
		V_BestBaalNMSec = 0;

		V_BestAndyHellHour = 0;
		V_BestAndyHellMin = 0;
		V_BestAndyHellSec = 0;
		V_BestDurielHellHour = 0;
		V_BestDurielHellMin = 0;
		V_BestDurielHellSec = 0;
		V_BestMephHellHour = 0;
		V_BestMephHellMin = 0;
		V_BestMephHellSec = 0;
		V_BestDiabloHellHour = 0;
		V_BestDiabloHellMin = 0;
		V_BestDiabloHellSec = 0;
		V_BestBaalHellHour = 0;
		V_BestBaalHellMin = 0;
		V_BestBaalHellSec = 0;
	}

	if (V_LoadUpdate < 8)
	{
		//Update7
		V_TravelDistanceYard = 0;
		V_TravelDistanceMile = 0;

		V_EquipHead = 0;
		V_EquipAmulet = 0;
		V_EquipBody = 0;
		V_EquipRightW = 0;
		V_EquipLeftW = 0;
		V_EquipRightR = 0;
		V_EquipLeftR = 0;
		V_EquipBelt = 0;
		V_EquipFeet = 0;
		V_EquipGloves = 0;
		V_EquipRight2W = 0;
		V_EquipLeft2W = 0;
	}

	if (V_LoadUpdate < 9)
	{
		//Update8
		V_GoldCopper = 0;
		V_GoldSilver = 0;
		V_GoldThousand = 0;
		V_GoldMillion = 0;
		V_GoldBillion = 0;
		V_GoldTrillion = 0;
	}

	if (V_LoadUpdate < 11)
	{
		//Update 10
		V_MyLadderID = 0;
	}

	if (V_LoadUpdate < 12)
	{
		//Update 11
		V_ChangedArea = 0;
		V_ShrineUsed = 0;
	}

	if (V_LoadUpdate < 13)
	{
		//Update 12
		V_MyLadderNote[0] = NULL;
	}

	if (V_LoadUpdate < 14)
	{
		//Update9b + 13
		for (INT i = 0; i < 7; i++)
		{
			for (INT j = 0; j < MAXKEYITEMS; j++)
			{
				V_ToggleKeyItem[j][i] = NULL;
			}
		}
	}
	if (V_LoadUpdate < 15)
	{
		//Update0
		for (INT i = 0; i < MAXMONSTERS; i++)
		{
			V_MonsterUnit[0][i] = 0;
			V_MonsterUnit[1][i] = 0;
			V_MonsterUnit[2][i] = 0;
		}
	}
}

VOID ResetInfoMenu()
{
	V_SelectedCounterPageText = 1;
	V_PlayerInfoTextPages = 1;

	V_PlayerInfoSelected = -1;

	V_PlayerInfoText1[0] = NULL;
	V_PlayerInfoText2[0] = NULL;
	V_PlayerInfoText3[0] = NULL;
	V_PlayerInfoText4[0] = NULL;
	V_PlayerInfoText5[0] = NULL;
	V_PlayerInfoText6[0] = NULL;
	V_PlayerInfoText7[0] = NULL;
	V_PlayerInfoText8[0] = NULL;
	V_PlayerInfoText9[0] = NULL;
	V_PlayerInfoText10[0] = NULL;
	V_PlayerInfoText11[0] = NULL;
	V_PlayerInfoText12[0] = NULL;
	V_PlayerInfoText13[0] = NULL;
	V_PlayerInfoText14[0] = NULL;
	V_PlayerInfoText15[0] = NULL;
	V_PlayerInfoText16[0] = NULL;
	V_PlayerInfoText17[0] = NULL;
	V_PlayerInfoText18[0] = NULL;
	V_PlayerInfoText19[0] = NULL;
	V_PlayerInfoText20[0] = NULL;
	V_PlayerInfoText21[0] = NULL;
}

VOID ResetInfoText()
{
	V_PlayerInfoText1[0] = NULL;
	V_PlayerInfoText2[0] = NULL;
	V_PlayerInfoText3[0] = NULL;
	V_PlayerInfoText4[0] = NULL;
	V_PlayerInfoText5[0] = NULL;
	V_PlayerInfoText6[0] = NULL;
	V_PlayerInfoText7[0] = NULL;
	V_PlayerInfoText8[0] = NULL;
	V_PlayerInfoText9[0] = NULL;
	V_PlayerInfoText10[0] = NULL;
	V_PlayerInfoText11[0] = NULL;
	V_PlayerInfoText12[0] = NULL;
	V_PlayerInfoText13[0] = NULL;
	V_PlayerInfoText14[0] = NULL;
	V_PlayerInfoText15[0] = NULL;
	V_PlayerInfoText16[0] = NULL;
	V_PlayerInfoText17[0] = NULL;
	V_PlayerInfoText18[0] = NULL;
	V_PlayerInfoText19[0] = NULL;
	V_PlayerInfoText20[0] = NULL;
	V_PlayerInfoText21[0] = NULL;
}

VOID ResetIgnoreList()
{
	for (INT i = 0; i < MAXIGNORE; i++)
	{
		V_IgnoreList[i] = 0;
	}
}

VOID ResetQuestsMenu()
{
	V_SelectedQuestPageText = 1;
	V_SideQuestTextPages = 1;

	V_SideQuestSelected = 0;

	V_PlayerInfoText1[0] = NULL;
	V_PlayerInfoText2[0] = NULL;
	V_PlayerInfoText3[0] = NULL;
	V_PlayerInfoText4[0] = NULL;
	V_PlayerInfoText5[0] = NULL;
	V_PlayerInfoText6[0] = NULL;
	V_PlayerInfoText7[0] = NULL;
	V_PlayerInfoText8[0] = NULL;
	V_PlayerInfoText9[0] = NULL;
	V_PlayerInfoText10[0] = NULL;
	V_PlayerInfoText11[0] = NULL;
	V_PlayerInfoText12[0] = NULL;
	V_PlayerInfoText13[0] = NULL;
	V_PlayerInfoText14[0] = NULL;
	V_PlayerInfoText15[0] = NULL;
	V_PlayerInfoText16[0] = NULL;
	V_PlayerInfoText17[0] = NULL;
	V_PlayerInfoText18[0] = NULL;
	V_PlayerInfoText19[0] = NULL;
	V_PlayerInfoText20[0] = NULL;
	V_PlayerInfoText21[0] = NULL;

	V_SideQuestListStrL1[0] = NULL;
	V_SideQuestListStrL2[0] = NULL;
	V_SideQuestListStrL3[0] = NULL;
	V_SideQuestListStrL4[0] = NULL;
	V_SideQuestListStrL5[0] = NULL;
	V_SideQuestListStrL6[0] = NULL;
	V_SideQuestListStrL7[0] = NULL;
	V_SideQuestListStrL8[0] = NULL;
	V_SideQuestListStrL9[0] = NULL;
	V_SideQuestListStrL10[0] = NULL;
	V_SideQuestListStrL11[0] = NULL;
	V_SideQuestListStrL12[0] = NULL;
	V_SideQuestListStrL13[0] = NULL;
	V_SideQuestListStrL14[0] = NULL;
	V_SideQuestListStrL15[0] = NULL;
	V_SideQuestListStrL16[0] = NULL;
	V_SideQuestListStrL17[0] = NULL;
	V_SideQuestListStrL18[0] = NULL;
	V_SideQuestListStrL19[0] = NULL;
	V_SideQuestListStrL20[0] = NULL;
}

VOID ResetQuestsText()
{
	V_PlayerInfoText1[0] = NULL;
	V_PlayerInfoText2[0] = NULL;
	V_PlayerInfoText3[0] = NULL;
	V_PlayerInfoText4[0] = NULL;
	V_PlayerInfoText5[0] = NULL;
	V_PlayerInfoText6[0] = NULL;
	V_PlayerInfoText7[0] = NULL;
	V_PlayerInfoText8[0] = NULL;
	V_PlayerInfoText9[0] = NULL;
	V_PlayerInfoText10[0] = NULL;
	V_PlayerInfoText11[0] = NULL;
	V_PlayerInfoText12[0] = NULL;
	V_PlayerInfoText13[0] = NULL;
	V_PlayerInfoText14[0] = NULL;
	V_PlayerInfoText15[0] = NULL;
	V_PlayerInfoText16[0] = NULL;
	V_PlayerInfoText17[0] = NULL;
	V_PlayerInfoText18[0] = NULL;
	V_PlayerInfoText19[0] = NULL;
	V_PlayerInfoText20[0] = NULL;
	V_PlayerInfoText21[0] = NULL;
}

VOID SetQuestsMenuVars()
{
	V_SideQuestListStrL1[0] = NULL;
	V_SideQuestListStrL2[0] = NULL;
	V_SideQuestListStrL3[0] = NULL;
	V_SideQuestListStrL4[0] = NULL;
	V_SideQuestListStrL5[0] = NULL;
	V_SideQuestListStrL6[0] = NULL;
	V_SideQuestListStrL7[0] = NULL;
	V_SideQuestListStrL8[0] = NULL;
	V_SideQuestListStrL9[0] = NULL;
	V_SideQuestListStrL10[0] = NULL;
	V_SideQuestListStrL11[0] = NULL;
	V_SideQuestListStrL12[0] = NULL;
	V_SideQuestListStrL13[0] = NULL;
	V_SideQuestListStrL14[0] = NULL;
	V_SideQuestListStrL15[0] = NULL;
	V_SideQuestListStrL16[0] = NULL;
	V_SideQuestListStrL17[0] = NULL;
	V_SideQuestListStrL18[0] = NULL;
	V_SideQuestListStrL19[0] = NULL;
	V_SideQuestListStrL20[0] = NULL;

	V_SideQuestTagExpansion1[0] = NULL;
	V_SideQuestTagExpansion2[0] = NULL;
	V_SideQuestTagExpansion3[0] = NULL;
	V_SideQuestTagExpansion4[0] = NULL;
	V_SideQuestTagExpansion5[0] = NULL;
	V_SideQuestTagExpansion6[0] = NULL;
	V_SideQuestTagExpansion7[0] = NULL;
	V_SideQuestTagExpansion8[0] = NULL;
	V_SideQuestTagExpansion9[0] = NULL;
	V_SideQuestTagExpansion10[0] = NULL;
	V_SideQuestTagExpansion11[0] = NULL;
	V_SideQuestTagExpansion12[0] = NULL;
	V_SideQuestTagExpansion13[0] = NULL;
	V_SideQuestTagExpansion14[0] = NULL;
	V_SideQuestTagExpansion15[0] = NULL;
	V_SideQuestTagExpansion16[0] = NULL;
	V_SideQuestTagExpansion17[0] = NULL;
	V_SideQuestTagExpansion18[0] = NULL;
	V_SideQuestTagExpansion19[0] = NULL;
	V_SideQuestTagExpansion20[0] = NULL;

	V_SideQuestTitleExpansion1[0] = NULL;
	V_SideQuestTitleExpansion2[0] = NULL;
	V_SideQuestTitleExpansion3[0] = NULL;
	V_SideQuestTitleExpansion4[0] = NULL;
	V_SideQuestTitleExpansion5[0] = NULL;
	V_SideQuestTitleExpansion6[0] = NULL;
	V_SideQuestTitleExpansion7[0] = NULL;
	V_SideQuestTitleExpansion8[0] = NULL;
	V_SideQuestTitleExpansion9[0] = NULL;
	V_SideQuestTitleExpansion10[0] = NULL;
	V_SideQuestTitleExpansion11[0] = NULL;
	V_SideQuestTitleExpansion12[0] = NULL;
	V_SideQuestTitleExpansion13[0] = NULL;
	V_SideQuestTitleExpansion14[0] = NULL;
	V_SideQuestTitleExpansion15[0] = NULL;
	V_SideQuestTitleExpansion16[0] = NULL;
	V_SideQuestTitleExpansion17[0] = NULL;
	V_SideQuestTitleExpansion18[0] = NULL;
	V_SideQuestTitleExpansion19[0] = NULL;
	V_SideQuestTitleExpansion20[0] = NULL;

	V_SideQuestStrMain[0] = NULL;
	V_SideQuestStrBack[0] = NULL;
	V_SideQuestStrNext[0] = NULL;
	V_SideQuestStrClose[0] = NULL;

	V_QuestStrContextX = 0;
	V_QuestStrContextY = 0;
	V_QuestStrRectX = 0;
	V_QuestStrRectY = 0;
	V_QuestStrRectWidth = 0;
	V_QuestStrRectHeight = 0;
	V_QuestStrMouseOverX1 = 0;
	V_QuestStrMouseOverY1 = 0;
	V_QuestButtonWidth = 0;
	V_QuestButtonHeight = 0;

	V_KeyItemStrMain[0] = NULL;
	V_KeyItemStrBack[0] = NULL;
	V_KeyItemStrNext[0] = NULL;
	V_KeyItemStrClose[0] = NULL;
	V_KeyItemStrOn[0] = NULL;
	V_KeyItemStrOff[0] = NULL;
}
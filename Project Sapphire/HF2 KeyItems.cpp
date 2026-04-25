#include "Hack.h"

using namespace std;

CONFIGURATION KEYITEM_SETTINGS[] =
{
	{ "Default", "MainStr", NULL, STRING, &V_KeyItemStrMain },
	{ "Default", "BackStr", NULL, STRING, &V_KeyItemStrBack },
	{ "Default", "NextStr", NULL, STRING, &V_KeyItemStrNext },
	{ "Default", "CloseStr", NULL, STRING, &V_KeyItemStrClose },
	{ "Default", "OnStr", NULL, STRING, &V_KeyItemStrOn},
	{ "Default", "OffStr", NULL, STRING, &V_KeyItemStrOff },
};

CONFIGURATION KEYITEM_LIST[] =
{
	{ "Default", "ListMaxPages", NULL, INTEGER, &V_SideQuestListPages },

	{ "Default", "KeyItem1", NULL, STRING, &V_SideQuestListStrL1 },
	{ "Default", "KeyItem2", NULL, STRING, &V_SideQuestListStrL2 },
	{ "Default", "KeyItem3", NULL, STRING, &V_SideQuestListStrL3 },
	{ "Default", "KeyItem4", NULL, STRING, &V_SideQuestListStrL4 },
	{ "Default", "KeyItem5", NULL, STRING, &V_SideQuestListStrL5 },
	{ "Default", "KeyItem6", NULL, STRING, &V_SideQuestListStrL6 },
	{ "Default", "KeyItem7", NULL, STRING, &V_SideQuestListStrL7 },
	{ "Default", "KeyItem8", NULL, STRING, &V_SideQuestListStrL8 },
	{ "Default", "KeyItem9", NULL, STRING, &V_SideQuestListStrL9 },
	{ "Default", "KeyItem10", NULL, STRING, &V_SideQuestListStrL10 },
	{ "Default", "KeyItem11", NULL, STRING, &V_SideQuestListStrL11 },
	{ "Default", "KeyItem12", NULL, STRING, &V_SideQuestListStrL12 },
	{ "Default", "KeyItem13", NULL, STRING, &V_SideQuestListStrL13 },
	{ "Default", "KeyItem14", NULL, STRING, &V_SideQuestListStrL14 },
	{ "Default", "KeyItem15", NULL, STRING, &V_SideQuestListStrL15 },
	{ "Default", "KeyItem16", NULL, STRING, &V_SideQuestListStrL16 },
	{ "Default", "KeyItem17", NULL, STRING, &V_SideQuestListStrL17 },
	{ "Default", "KeyItem18", NULL, STRING, &V_SideQuestListStrL18 },
	{ "Default", "KeyItem19", NULL, STRING, &V_SideQuestListStrL19 },
	{ "Default", "KeyItem20", NULL, STRING, &V_SideQuestListStrL20 }
};

CONFIGURATION KEYITEM_TEXT[] =
{
	{ "Default", "Line1", NULL, STRING, &V_PlayerInfoText1 },
	{ "Default", "Line2", NULL, STRING, &V_PlayerInfoText2 },
	{ "Default", "Line3", NULL, STRING, &V_PlayerInfoText3 },
	{ "Default", "Line4", NULL, STRING, &V_PlayerInfoText4 },
	{ "Default", "Line5", NULL, STRING, &V_PlayerInfoText5 },
	{ "Default", "Line6", NULL, STRING, &V_PlayerInfoText6 },
	{ "Default", "Line7", NULL, STRING, &V_PlayerInfoText7 },
	{ "Default", "Line8", NULL, STRING, &V_PlayerInfoText8 },
	{ "Default", "Line9", NULL, STRING, &V_PlayerInfoText9 },
	{ "Default", "Line10", NULL, STRING, &V_PlayerInfoText10 },
	{ "Default", "Line11", NULL, STRING, &V_PlayerInfoText11 },
	{ "Default", "Line12", NULL, STRING, &V_PlayerInfoText12 },
	{ "Default", "Line13", NULL, STRING, &V_PlayerInfoText13 },
	{ "Default", "Line14", NULL, STRING, &V_PlayerInfoText14 },
	{ "Default", "Line15", NULL, STRING, &V_PlayerInfoText15 },
	{ "Default", "Line16", NULL, STRING, &V_PlayerInfoText16 },
	{ "Default", "Line17", NULL, STRING, &V_PlayerInfoText17 },
	{ "Default", "Line18", NULL, STRING, &V_PlayerInfoText18 },
	{ "Default", "Line19", NULL, STRING, &V_PlayerInfoText19 },
	{ "Default", "Line20", NULL, STRING, &V_PlayerInfoText20 },
	{ "Default", "Line21", NULL, STRING, &V_PlayerInfoText21 }
};

BOOL LoadKeyItemSettings()
{
	CHAR File[MAX_PATH], Returned[100000];

	V_FilePathC = "\\Interface\\Scripts\\KeyItem\\KeyItems.ini";

	GetModuleDirectory();

	CHAR Key[32];

	std::vector<char> v(V_FilePathC.length() + 1);
	std::strcpy(&v[0], V_FilePathC.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < ArraySize(KEYITEM_SETTINGS); i++)
	{
		GetPrivateProfileStringA(KEYITEM_SETTINGS[i].Section, KEYITEM_SETTINGS[i].Name, KEYITEM_SETTINGS[i].Default, Returned, sizeof(Returned), File);

		if (KEYITEM_SETTINGS[i].Type == BOOLEAN)
			*(LPBOOL)KEYITEM_SETTINGS[i].Variable = Bool(Returned);

		else if (KEYITEM_SETTINGS[i].Type == INTEGER)
			*(LPINT)KEYITEM_SETTINGS[i].Variable = Integer(Returned);

		else if (KEYITEM_SETTINGS[i].Type == STRING)
			strncpy_s((LPSTR)KEYITEM_SETTINGS[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	for (INT i = 0; i < MAXKEYITEMS; i++)
	{
		sprintf_s(Key, "KeyItemA%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp1[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemB%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp2[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemC%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp3[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemD%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp4[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemE%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp5[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemF%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp6[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemG%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp7[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemH%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp8[i], sizeof(Returned), Returned, sizeof(Returned));

		sprintf_s(Key, "KeyItemI%d", i);
		GetPrivateProfileStringA("Default", Key, NULL, Returned, sizeof(Returned), File);
		strncpy_s(V_KeyItemStrExp9[i], sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL LoadKeyItemList(INT iExpansionTag, INT iPageTag)
{
	switch (iExpansionTag)
	{
	case 0:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion1;

		break;
	case 1:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion2;

		break;
	case 2:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion3;

		break;
	case 3:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion4;

		break;
	case 4:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion5;

		break;
	case 5:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion6;

		break;
	case 6:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion7;

		break;
	case 7:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion8;

		break;
	case 8:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion9;

		break;
	case 9:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion10;

		break;
	case 10:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion11;

		break;
	case 11:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion12;

		break;
	case 12:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion13;

		break;
	case 13:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion14;

		break;
	case 14:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion15;

		break;
	case 15:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion16;

		break;
	case 16:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion17;

		break;
	case 17:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion18;

		break;
	case 18:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion19;

		break;
	case 19:
		V_SideQuestTagExpansion = V_SideQuestTagExpansion20;

		break;
	}
	long double PageTag = iPageTag;
	std::string str = std::to_string(PageTag);
	V_SideQuestTagPage = str;

	CHAR File[MAX_PATH], Returned[100000];
	V_FilePath = "\\Interface\\Scripts\\KeyItem\\KeyItem_List_" + V_SideQuestTagExpansion + "_P" + V_SideQuestTagPage + ".ini";
	GetModuleDirectory();

	std::vector<char> v(V_FilePath.length() + 1);
	std::strcpy(&v[0], V_FilePath.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < ArraySize(KEYITEM_LIST); i++)
	{
		GetPrivateProfileStringA(KEYITEM_LIST[i].Section, KEYITEM_LIST[i].Name, KEYITEM_LIST[i].Default, Returned, sizeof(Returned), File);

		if (KEYITEM_LIST[i].Type == BOOLEAN)
			*(LPBOOL)KEYITEM_LIST[i].Variable = Bool(Returned);

		else if (KEYITEM_LIST[i].Type == INTEGER)
			*(LPINT)KEYITEM_LIST[i].Variable = Integer(Returned);

		else if (KEYITEM_LIST[i].Type == STRING)
			strncpy_s((LPSTR)KEYITEM_LIST[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL LoadKeyItemText(INT iQuestTag, INT iPageTag)
{
	long double QuestNoStr = iQuestTag;
	long double PageNoStr = iPageTag;
	std::string str = std::to_string(QuestNoStr);
	V_SideQuestTagQuest = str;

	std::string page = std::to_string(PageNoStr);

	CHAR File[MAX_PATH], Returned[100000];

	V_FilePathB = "\\Interface\\Scripts\\KeyItem\\KeyItem_Text_" + V_SideQuestTagExpansion + "_P" + V_SideQuestTagPage + "_Q" + V_SideQuestTagQuest + ".ini";

	GetModuleDirectory();

	//Hf2Log("Loading Quest...");

	std::vector<char> v(V_FilePathB.length() + 1);
	std::strcpy(&v[0], V_FilePathB.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	Hf2Log(fp);

	for (INT i = 0; i < ArraySize(KEYITEM_TEXT); i++)
	{
		GetPrivateProfileStringA(KEYITEM_TEXT[i].Section, KEYITEM_TEXT[i].Name, KEYITEM_TEXT[i].Default, Returned, sizeof(Returned), File);

		if (KEYITEM_TEXT[i].Type == BOOLEAN)
			*(LPBOOL)KEYITEM_TEXT[i].Variable = Bool(Returned);

		else if (KEYITEM_TEXT[i].Type == INTEGER)
			*(LPINT)KEYITEM_TEXT[i].Variable = Integer(Returned);

		else if (KEYITEM_TEXT[i].Type == STRING)
			strncpy_s((LPSTR)KEYITEM_TEXT[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL SaveKeyItems()
{
	CHAR File[MAX_PATH];

	CHAR Key[32];

	std::string str;
	char* data = V_CharacterName;
	int size = sizeof(V_CharacterName);
	str.assign(data, size);

	V_FilePath = "\\Interface\\Scripts\\KeyItem\\KeyItems.ini";
	
	GetModuleDirectory();

	std::vector<char> v(V_FilePath.length() + 1);
	std::strcpy(&v[0], V_FilePath.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < MAXKEYITEMS; i++)
	{
		sprintf_s(Key, "KeyItemA%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp1[i], File);

		sprintf_s(Key, "KeyItemB%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp2[i], File);

		sprintf_s(Key, "KeyItemC%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp3[i], File);

		sprintf_s(Key, "KeyItemD%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp4[i], File);

		sprintf_s(Key, "KeyItemE%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp5[i], File);

		sprintf_s(Key, "KeyItemF%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp6[i], File);

		sprintf_s(Key, "KeyItemG%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp7[i], File);

		sprintf_s(Key, "KeyItemH%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp8[i], File);

		sprintf_s(Key, "KeyItemI%d", i);
		WritePrivateProfileIntA("Keyitem", Key, V_HaveKeyItemExp9[i], File);
	}

	return TRUE;
}

BOOL LoadKeyItems()
{
	CHAR File[MAX_PATH], Returned[100000];

	CHAR Key[32];

	std::string str;
	char* data = V_CharacterName;
	int size = sizeof(V_CharacterName);
	str.assign(data, size);

	V_FilePath = "\\Interface\\Scripts\\KeyItem\\KeyItems.ini";

	GetModuleDirectory();

	std::vector<char> v(V_FilePath.length() + 1);
	std::strcpy(&v[0], V_FilePath.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < MAXKEYITEMS; i++)
	{
		sprintf_s(Key, "KeyItemA%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp1[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemB%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp2[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemC%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp3[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemD%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp4[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemE%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp5[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemF%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp6[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemG%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp7[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemH%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp8[i] = Integer(Returned);

		sprintf_s(Key, "KeyItemI%d", i);
		GetPrivateProfileStringA("Keyitem", Key, NULL, Returned, sizeof(Returned), File);
		V_HaveKeyItemExp9[i] = Integer(Returned);
	}

	return TRUE;
}

BOOL LookForKeyItems()
{
	DWORD FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

	//Classic
	//////
	UnitAny* pUnit;

	pUnit = D2CLIENT_GetSelectedUnit();
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if(pUnit->dwTxtFileNo == 150)
		{
			if(CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (V_HaveKeyItemExp1[1] != KEYITEMCODEXP1NO0 && V_Registered)
				{
					Print(0, 0, "Kashya is looking through her records...");
					SleepEx(60000 * KEYITEMSKASHYAMIN, TRUE);

					if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
					{
						if (pUnit->dwTxtFileNo == 150)
						{
							if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
							{

								if (V_HaveKeyItemExp1[1] != KEYITEMCODEXP1NO0 && V_Registered)
								{
									Print(0, 0, "Kashya hands you a scroll and a card...");

									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp1[0]);
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp1[1]);

									V_HaveKeyItemExp1[0] = KEYITEMCODEXP1NO1;
									V_HaveKeyItemExp1[1] = KEYITEMCODEXP1NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
				if (V_HaveKeyItemExp1[0] == KEYITEMCODEXP1NO1)
				{
					if ((V_ToggleKeyItem[1][0] && V_HaveKeyItemExp1[2] != KEYITEMCODEXP1NO2 && GetUnitStat(Me, STAT_LEVEL) > 11) || WOWMOD)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp1[2]);

						V_HaveKeyItemExp1[2] = KEYITEMCODEXP1NO2;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if ((V_ToggleKeyItem[1][0] && V_HaveKeyItemExp1[3] != KEYITEMCODEXP1NO3 && GetUnitStat(Me, STAT_LEVEL) >= 40) || WOWMOD)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp1[3]);

						V_HaveKeyItemExp1[3] = KEYITEMCODEXP1NO3;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if ((V_ToggleKeyItem[1][0] && V_HaveKeyItemExp1[4] != KEYITEMCODEXP1NO4 && GetUnitStat(Me, STAT_LEVEL) >= 50) || WOWMOD)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp1[4]);

						V_HaveKeyItemExp1[4] = KEYITEMCODEXP1NO4;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if ((V_ToggleKeyItem[1][0] && V_HaveKeyItemExp1[5] != KEYITEMCODEXP1NO5 && GetUnitStat(Me, STAT_LEVEL) >= 50) || WOWMOD)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp1[5]);

						V_HaveKeyItemExp1[5] = KEYITEMCODEXP1NO5;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
				}
			}
		}
	}
	//Lord of Destruction
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if(pUnit->dwTxtFileNo == 175)
		{
			if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 10 && V_Rank == 2)
				{
					if (V_HaveKeyItemExp2[0] != KEYITEMCODEXP2NO0 && V_Registered)
					{
						Print(0, 0, "Warriv is searching through his pockets looking for something...");

						SleepEx(60000 * KEYITEMSWARRIVMIN, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 175)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp2[0]);

									V_HaveKeyItemExp2[0] = KEYITEMCODEXP2NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
				if (V_HaveKeyItemExp2[0] == KEYITEMCODEXP2NO0)
				{
					if (V_ToggleKeyItem[0][1] && V_HaveKeyItemExp2[1] != KEYITEMCODEXP2NO1 && GetUnitStat(Me, STAT_LEVEL) > 34)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp2[1]);

						V_HaveKeyItemExp2[1] = KEYITEMCODEXP2NO1;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if (V_ToggleKeyItem[0][1] && V_HaveKeyItemExp2[2] != KEYITEMCODEXP2NO2 && GetUnitStat(Me, STAT_LEVEL) > 39)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp2[2]);

						V_HaveKeyItemExp2[2] = KEYITEMCODEXP2NO2;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if (V_ToggleKeyItem[0][1] && V_HaveKeyItemExp2[3] != KEYITEMCODEXP2NO3 && GetUnitStat(Me, STAT_LEVEL) > 44)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp2[3]);

						V_HaveKeyItemExp2[3] = KEYITEMCODEXP2NO3;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
				}
			}
		}
	}

	//Project Ruby Dreams
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if(pUnit->dwTxtFileNo == 200)
		{
			if(CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 35 && V_Rank == 9)
				{
					if(V_HaveKeyItemExp3[0] != KEYITEMCODEXP3NO0 && V_Registered)
					{
						Print(0, 0, "Geglash pauses from talking while you are standing near him...");

						SleepEx(60000 * KEYITEMSGEGLASHMIN, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 200)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp3[0]);

									V_HaveKeyItemExp3[0] = KEYITEMCODEXP3NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
				if (V_HaveKeyItemExp3[0] == KEYITEMCODEXP3NO0)
				{
					if (V_ToggleKeyItem[0][2] && V_HaveKeyItemExp3[1] != KEYITEMCODEXP3NO1 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp3[1]);

						V_HaveKeyItemExp3[1] = KEYITEMCODEXP3NO1;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if (V_ToggleKeyItem[0][2] && V_HaveKeyItemExp3[2] != KEYITEMCODEXP3NO2 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp3[2]);

						V_HaveKeyItemExp3[2] = KEYITEMCODEXP3NO2;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if (V_ToggleKeyItem[0][2] && V_HaveKeyItemExp3[3] != KEYITEMCODEXP3NO3 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp3[3]);

						V_HaveKeyItemExp3[3] = KEYITEMCODEXP3NO3;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if (V_ToggleKeyItem[0][2] && V_HaveKeyItemExp3[4] != KEYITEMCODEXP3NO4 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp3[4]);

						V_HaveKeyItemExp3[4] = KEYITEMCODEXP3NO4;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if (V_ToggleKeyItem[0][2] && V_HaveKeyItemExp3[5] != KEYITEMCODEXP3NO5 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp3[5]);

						V_HaveKeyItemExp3[5] = KEYITEMCODEXP3NO5;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
				}
			}
		}
	}

	//Wings of the Goddess
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if(pUnit->dwTxtFileNo == 257)
		{
			if(CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 45 && V_Rank == 4)
				{
					if(V_HaveKeyItemExp4[0] != KEYITEMCODEXP4NO0 && V_Registered)
					{
						Print(0, 0, "Halbu yells something at Jamella you can't understand...");

						SleepEx(60000 * KEYITEMSHALBUMIN, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 257)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp4[0]);

									V_HaveKeyItemExp4[0] = KEYITEMCODEXP4NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
				if (V_HaveKeyItemExp4[0] == KEYITEMCODEXP4NO0)
				{
					if (V_ToggleKeyItem[0][3] && V_HaveKeyItemExp4[1] != KEYITEMCODEXP4NO1 && GetUnitStat(Me, STAT_LEVEL) >= 45)
					{
						if (FLAG == 30 && V_MonsterUnit[0][5] > 5463)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp4[1]);

							V_HaveKeyItemExp4[1] = KEYITEMCODEXP4NO1;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][3] && V_ToggleKeyItem[1][3] && V_HaveKeyItemExp4[2] != KEYITEMCODEXP4NO2 && GetUnitStat(Me, STAT_LEVEL) > 47)
					{
						FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

						if (FLAG == 30 && V_MonsterUnit[0][307] > 700)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp4[2]);

							V_HaveKeyItemExp4[2] = KEYITEMCODEXP4NO2;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][3] && V_ToggleKeyItem[1][3] && V_HaveKeyItemExp4[3] != KEYITEMCODEXP4NO3 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

						if (FLAG == 30 && V_MonsterUnit[0][19] > 666)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp4[3]);

							V_HaveKeyItemExp4[3] = KEYITEMCODEXP4NO3;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][3] && V_ToggleKeyItem[1][3] && V_HaveKeyItemExp4[4] != KEYITEMCODEXP4NO4 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

						if (FLAG == 30 && V_MonsterUnit[0][136] > 49 && V_MonsterUnit[0][137] > 49 && V_MonsterUnit[0][138] > 49 && V_MonsterUnit[0][139] > 49 && V_MonsterUnit[0][140] > 49)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp4[4]);

							V_HaveKeyItemExp4[4] = KEYITEMCODEXP4NO4;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][3] && V_ToggleKeyItem[1][3] && V_HaveKeyItemExp4[5] != KEYITEMCODEXP4NO5 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						FLAG = GetUnitStat(Me, STAT_MAXMAGICRESIST);

						if (FLAG == 30)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp4[5]);

							V_HaveKeyItemExp4[5] = KEYITEMCODEXP4NO5;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
				}
			}
		}
	}

	// Origins of Silence
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if(pUnit->dwTxtFileNo == 148)
		{
			if(CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 50 && V_Rank == 8)
				{
					if(V_HaveKeyItemExp5[0] != KEYITEMCODEXP5NO0 && V_Registered)
					{
						Print(0, 0, "Akara looks like she is deep in thought...");

						SleepEx(60000 * KEYITEMSAKARAMIN, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 148)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp5[0]);

									V_HaveKeyItemExp5[0] = KEYITEMCODEXP5NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
				if (V_HaveKeyItemExp5[0] == KEYITEMCODEXP5NO0)
				{
					if (V_ToggleKeyItem[0][4] && V_HaveKeyItemExp5[1] != KEYITEMCODEXP5NO1 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp5[1]);

						V_HaveKeyItemExp5[1] = KEYITEMCODEXP5NO1;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
					if (V_ToggleKeyItem[0][4] && V_HaveKeyItemExp5[2] != KEYITEMCODEXP5NO2 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						if (V_MonsterUnit[0][738] > 199)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp5[2]);

							V_HaveKeyItemExp5[2] = KEYITEMCODEXP5NO2;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][4] && V_HaveKeyItemExp5[3] != KEYITEMCODEXP5NO3 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						if (FLAG == 3 && V_MonsterUnit[0][310] > 9999)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp5[3]);

							V_HaveKeyItemExp5[3] = KEYITEMCODEXP5NO3;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][4] && V_HaveKeyItemExp5[4] != KEYITEMCODEXP5NO4 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp5[4]);

						V_HaveKeyItemExp5[4] = KEYITEMCODEXP5NO4;

						D2CLIENT_PlaySound(STAND_PICKUP);
						SaveKeyItems();
					}
				}
			}
		}
	}

	//From a Grace Fallen
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if(pUnit->dwTxtFileNo == 405)
		{
			if(CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 50 && V_Rank == 3)
				{
					if(V_HaveKeyItemExp6[0] != KEYITEMCODEXP6NO0 && V_Registered)
					{
						Print(0, 0, "Jamella is peering at her books...");

						SleepEx(60000 * KEYITEMSJAMELLAMIN, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 405)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp6[0]);

									V_HaveKeyItemExp6[0] = KEYITEMCODEXP6NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
				if (V_HaveKeyItemExp6[0] == KEYITEMCODEXP6NO0)
				{
					if (V_ToggleKeyItem[0][5] && V_HaveKeyItemExp6[1] != KEYITEMCODEXP6NO1 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						if (V_MonsterUnit[0][812] > 9999)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp6[1]);

							V_HaveKeyItemExp6[1] = KEYITEMCODEXP6NO1;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][5] && V_HaveKeyItemExp6[2] != KEYITEMCODEXP6NO2 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						if (FLAG == 4 && V_MonsterUnit[0][811] > 34)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp6[2]);

							V_HaveKeyItemExp6[2] = KEYITEMCODEXP6NO2;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][5] && V_HaveKeyItemExp6[3] != KEYITEMCODEXP6NO3 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						if (V_MonsterUnit[0][472] > 19)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp6[3]);

							V_HaveKeyItemExp6[3] = KEYITEMCODEXP6NO3;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
					if (V_ToggleKeyItem[0][5] && V_HaveKeyItemExp6[4] != KEYITEMCODEXP6NO4 && GetUnitStat(Me, STAT_LEVEL) >= 50)
					{
						if (V_MonsterUnit[0][1] > 2397)
						{
							Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp6[4]);

							V_HaveKeyItemExp6[4] = KEYITEMCODEXP6NO4;

							D2CLIENT_PlaySound(STAND_PICKUP);
							SaveKeyItems();
						}
					}
				}
			}
		}
	}

	//Guild Pact
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if (pUnit->dwTxtFileNo == 405)
		{
			if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 50 && V_Rank == 7)
				{
					if (V_HaveKeyItemExp7[0] != KEYITEMCODEXP7NO0 && V_Registered)
					{
						Print(0, 0, "Jamella points to the sky as a meteor falls to the earth in the distance.");

						SleepEx(60000 * KEYITEMSJAMELLAMINTWO, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 405)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp6[0]);

									V_HaveKeyItemExp7[0] = KEYITEMCODEXP7NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
					if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
					{
						if (pUnit->dwTxtFileNo == 405)
						{
							if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
							{

								if (V_ToggleKeyItem[0][6] && V_HaveKeyItemExp7[1] != KEYITEMCODEXP7NO1 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp7[1]);

									V_HaveKeyItemExp7[1] = KEYITEMCODEXP7NO1;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][6] && V_HaveKeyItemExp7[2] != KEYITEMCODEXP7NO2 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp7[2]);

									V_HaveKeyItemExp7[2] = KEYITEMCODEXP7NO2;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][6] && V_HaveKeyItemExp7[3] != KEYITEMCODEXP7NO3 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp7[2]);

									V_HaveKeyItemExp7[3] = KEYITEMCODEXP7NO3;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
			}
		}
	}

	//A New Hope
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if (pUnit->dwTxtFileNo == 405)
		{
			if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 50 && V_Rank == 8)
				{
					if (V_HaveKeyItemExp8[0] != KEYITEMCODEXP8NO0 && V_Registered)
					{
						Print(0, 0, "Jamella pours a drink in a glass and asks you if you would like some.");

						SleepEx(60000 * KEYITEMSJAMELLAMINTHREE, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 405)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp8[0]);

									V_HaveKeyItemExp8[0] = KEYITEMCODEXP8NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
					if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
					{
						if (pUnit->dwTxtFileNo == 405)
						{
							if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
							{

								if (V_ToggleKeyItem[0][7] && V_HaveKeyItemExp8[1] != KEYITEMCODEXP8NO1 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp8[0]);

									V_HaveKeyItemExp8[1] = KEYITEMCODEXP8NO1;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][7] && V_HaveKeyItemExp8[2] != KEYITEMCODEXP8NO2 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp8[0]);

									V_HaveKeyItemExp8[2] = KEYITEMCODEXP8NO2;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][7] && V_HaveKeyItemExp8[3] != KEYITEMCODEXP8NO3 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp8[0]);

									V_HaveKeyItemExp8[3] = KEYITEMCODEXP8NO3;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][7] && V_HaveKeyItemExp8[4] != KEYITEMCODEXP8NO4 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp8[0]);

									V_HaveKeyItemExp8[4] = KEYITEMCODEXP8NO4;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
			}
		}
	}

	//Sands of Calypso
	//////
	if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
	{
		if (pUnit->dwTxtFileNo == 405)
		{
			if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
			{
				if (GetUnitStat(Me, STAT_LEVEL) >= 50 && V_Rank == 9)
				{
					if (V_HaveKeyItemExp9[0] != KEYITEMCODEXP9NO0 && V_Registered)
					{
						Print(0, 0, "Jamella lights a cigarette and passes it to you.");

						SleepEx(60000 * KEYITEMSJAMELLAMINFOUR, TRUE);

						if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
						{
							if (pUnit->dwTxtFileNo == 405)
							{
								if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp9[0]);

									V_HaveKeyItemExp9[0] = KEYITEMCODEXP9NO0;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();

								}
							}
						}
					}
					if (pUnit && pUnit->dwType == UNIT_TYPE_NPC)
					{
						if (pUnit->dwTxtFileNo == 405)
						{
							if (CalculateDistance((LONG)Me->pPath->xPos, (LONG)Me->pPath->yPos, (LONG)pUnit->pPath->xPos, (LONG)pUnit->pPath->yPos) < 10)
							{
								if (V_ToggleKeyItem[0][8] && V_HaveKeyItemExp9[1] != KEYITEMCODEXP9NO1 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp9[0]);

									V_HaveKeyItemExp9[1] = KEYITEMCODEXP9NO1;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][8] && V_HaveKeyItemExp9[2] != KEYITEMCODEXP9NO2 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp9[0]);

									V_HaveKeyItemExp9[2] = KEYITEMCODEXP9NO2;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][8] && V_HaveKeyItemExp9[3] != KEYITEMCODEXP9NO3 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp9[0]);

									V_HaveKeyItemExp9[3] = KEYITEMCODEXP9NO3;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
								if (V_ToggleKeyItem[0][8] && V_HaveKeyItemExp9[4] != KEYITEMCODEXP9NO4 && GetUnitStat(Me, STAT_LEVEL) >= 50)
								{
									Print(0, 2, "You obtained the key item %s.", V_KeyItemStrExp9[0]);

									V_HaveKeyItemExp9[4] = KEYITEMCODEXP9NO4;

									D2CLIENT_PlaySound(STAND_PICKUP);
									SaveKeyItems();
								}
							}
						}
					}
				}
			}
		}
	}

	//Toggle Correction/Alignment
	if(!V_ToggleCalcMenu)
	{
		if(V_ToggleKeyItem[1][1])
		{
			V_ExpInfo = FALSE;
		}
		if(V_Supplies)
		{
			V_Supplies = FALSE;
		}
		if(V_StateList)
		{
			V_StateList = FALSE;
		}
		if(V_Gold)
		{
			V_Gold = FALSE;
		}
	}
	if(!V_ToggleKeyItem[1][1])
	{
		V_ToggleCalcMenu = FALSE;
	}

	return TRUE;
}

BOOL ResetKeyItems()
{
	V_HaveKeyItemExp1[0] = 0;
	V_HaveKeyItemExp1[1] = 0;
	V_HaveKeyItemExp1[2] = 0;
	V_HaveKeyItemExp1[3] = 0;
	V_HaveKeyItemExp1[4] = 0;
	V_HaveKeyItemExp1[5] = 0;
	V_HaveKeyItemExp2[0] = 0;
	V_HaveKeyItemExp2[1] = 0;
	V_HaveKeyItemExp2[2] = 0;
	V_HaveKeyItemExp2[3] = 0;
	V_HaveKeyItemExp3[0] = 0;
	V_HaveKeyItemExp3[1] = 0;
	V_HaveKeyItemExp3[2] = 0;
	V_HaveKeyItemExp3[3] = 0;
	V_HaveKeyItemExp3[4] = 0;
	V_HaveKeyItemExp3[5] = 0;
	V_HaveKeyItemExp4[0] = 0;
	V_HaveKeyItemExp4[1] = 0;
	V_HaveKeyItemExp4[2] = 0;
	V_HaveKeyItemExp4[3] = 0;
	V_HaveKeyItemExp4[4] = 0;
	V_HaveKeyItemExp4[5] = 0;
	V_HaveKeyItemExp5[0] = 0;
	V_HaveKeyItemExp5[1] = 0;
	V_HaveKeyItemExp5[2] = 0;
	V_HaveKeyItemExp5[3] = 0;
	V_HaveKeyItemExp5[4] = 0;
	V_HaveKeyItemExp6[0] = 0;
	V_HaveKeyItemExp6[1] = 0;
	V_HaveKeyItemExp6[2] = 0;
	V_HaveKeyItemExp6[3] = 0;
	V_HaveKeyItemExp6[4] = 0;
	V_HaveKeyItemExp7[0] = 0;
	V_HaveKeyItemExp7[1] = 0;
	V_HaveKeyItemExp7[2] = 0;
	V_HaveKeyItemExp7[3] = 0;
	V_HaveKeyItemExp8[0] = 0;
	V_HaveKeyItemExp8[1] = 0;
	V_HaveKeyItemExp8[2] = 0;
	V_HaveKeyItemExp8[3] = 0;
	V_HaveKeyItemExp8[4] = 0;
	V_HaveKeyItemExp9[0] = 0;
	V_HaveKeyItemExp9[1] = 0;
	V_HaveKeyItemExp9[2] = 0;
	V_HaveKeyItemExp9[3] = 0;
	V_HaveKeyItemExp9[4] = 0;

	SaveKeyItems();

	return FALSE;
}
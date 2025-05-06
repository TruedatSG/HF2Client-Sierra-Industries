#include "Hack.h"

CONFIGURATION SCRIPT_SETTINGS[] =
{
	{ "Default", "MainStr", NULL, STRING, &V_SideQuestStrMain },
	{ "Default", "BackStr", NULL, STRING, &V_SideQuestStrBack },
	{ "Default", "NextStr", NULL, STRING, &V_SideQuestStrNext },
	{ "Default", "CloseStr", NULL, STRING, &V_SideQuestStrClose },

	{ "Default", "QuestStrContextX", NULL, INTEGER, &V_QuestStrContextX },
	{ "Default", "QuestStrContextY", NULL, INTEGER, &V_QuestStrContextY },
	{ "Default", "QuestStrRectX", NULL, INTEGER, &V_QuestStrRectX },
	{ "Default", "QuestStrRectY", NULL, INTEGER, &V_QuestStrRectY },
	{ "Default", "QuestStrRectWidth", NULL, INTEGER, &V_QuestStrRectWidth },
	{ "Default", "QuestStrRectHeight", NULL, INTEGER, &V_QuestStrRectHeight },
	{ "Default", "QuestStrMouseOverX1", NULL, INTEGER, &V_QuestStrMouseOverX1 },
	{ "Default", "QuestStrMouseOverY1", NULL, INTEGER, &V_QuestStrMouseOverY1 },
	{ "Default", "QuestButtonWidth", NULL, INTEGER, &V_QuestButtonWidth },
	{ "Default", "QuestButtonHeight", NULL, INTEGER, &V_QuestButtonHeight },

	{ "Default", "ExpansionTitle1", NULL, STRING, &V_SideQuestTitleExpansion1 },
	{ "Default", "ExpansionTag1", NULL, STRING, &V_SideQuestTagExpansion1 },
	{ "Default", "ExpansionTitle2", NULL, STRING, &V_SideQuestTitleExpansion2 },
	{ "Default", "ExpansionTag2", NULL, STRING, &V_SideQuestTagExpansion2 },
	{ "Default", "ExpansionTitle3", NULL, STRING, &V_SideQuestTitleExpansion3 },
	{ "Default", "ExpansionTag3", NULL, STRING, &V_SideQuestTagExpansion3 },
	{ "Default", "ExpansionTitle4", NULL, STRING, &V_SideQuestTitleExpansion4 },
	{ "Default", "ExpansionTag4", NULL, STRING, &V_SideQuestTagExpansion4 },
	{ "Default", "ExpansionTitle5", NULL, STRING, &V_SideQuestTitleExpansion5 },
	{ "Default", "ExpansionTag5", NULL, STRING, &V_SideQuestTagExpansion5 },
	{ "Default", "ExpansionTitle6", NULL, STRING, &V_SideQuestTitleExpansion6 },
	{ "Default", "ExpansionTag6", NULL, STRING, &V_SideQuestTagExpansion6 },
	{ "Default", "ExpansionTitle7", NULL, STRING, &V_SideQuestTitleExpansion7 },
	{ "Default", "ExpansionTag7", NULL, STRING, &V_SideQuestTagExpansion7 },
	{ "Default", "ExpansionTitle8", NULL, STRING, &V_SideQuestTitleExpansion8 },
	{ "Default", "ExpansionTag8", NULL, STRING, &V_SideQuestTagExpansion8 },
	{ "Default", "ExpansionTitle9", NULL, STRING, &V_SideQuestTitleExpansion9 },
	{ "Default", "ExpansionTag9", NULL, STRING, &V_SideQuestTagExpansion9 },
	{ "Default", "ExpansionTitle10", NULL, STRING, &V_SideQuestTitleExpansion10 },
	{ "Default", "ExpansionTag10", NULL, STRING, &V_SideQuestTagExpansion10 },
	{ "Default", "ExpansionTitle11", NULL, STRING, &V_SideQuestTitleExpansion11 },
	{ "Default", "ExpansionTag11", NULL, STRING, &V_SideQuestTagExpansion11 },
	{ "Default", "ExpansionTitle12", NULL, STRING, &V_SideQuestTitleExpansion12 },
	{ "Default", "ExpansionTag12", NULL, STRING, &V_SideQuestTagExpansion12 },
	{ "Default", "ExpansionTitle13", NULL, STRING, &V_SideQuestTitleExpansion13 },
	{ "Default", "ExpansionTag13", NULL, STRING, &V_SideQuestTagExpansion13 },
	{ "Default", "ExpansionTitle14", NULL, STRING, &V_SideQuestTitleExpansion14 },
	{ "Default", "ExpansionTag14", NULL, STRING, &V_SideQuestTagExpansion14 },
	{ "Default", "ExpansionTitle15", NULL, STRING, &V_SideQuestTitleExpansion15 },
	{ "Default", "ExpansionTag15", NULL, STRING, &V_SideQuestTagExpansion15 },
	{ "Default", "ExpansionTitle16", NULL, STRING, &V_SideQuestTitleExpansion16 },
	{ "Default", "ExpansionTag16", NULL, STRING, &V_SideQuestTagExpansion16 },
	{ "Default", "ExpansionTitle17", NULL, STRING, &V_SideQuestTitleExpansion17 },
	{ "Default", "ExpansionTag17", NULL, STRING, &V_SideQuestTagExpansion17 },
	{ "Default", "ExpansionTitle18", NULL, STRING, &V_SideQuestTitleExpansion18 },
	{ "Default", "ExpansionTag18", NULL, STRING, &V_SideQuestTagExpansion18 },
	{ "Default", "ExpansionTitle19", NULL, STRING, &V_SideQuestTitleExpansion19 },
	{ "Default", "ExpansionTag19", NULL, STRING, &V_SideQuestTagExpansion19 },
	{ "Default", "ExpansionTitle20", NULL, STRING, &V_SideQuestTitleExpansion20 },
	{ "Default", "ExpansionTag20", NULL, STRING, &V_SideQuestTagExpansion20 }
};

CONFIGURATION SCRIPT_LIST[] =
{
	{ "Default", "ListMaxPages", NULL, INTEGER, &V_SideQuestListPages },

	{ "Default", "Quest1", NULL, STRING, &V_SideQuestListStrL1 },
	{ "Default", "Quest2", NULL, STRING, &V_SideQuestListStrL2 },
	{ "Default", "Quest3", NULL, STRING, &V_SideQuestListStrL3 },
	{ "Default", "Quest4", NULL, STRING, &V_SideQuestListStrL4 },
	{ "Default", "Quest5", NULL, STRING, &V_SideQuestListStrL5 },
	{ "Default", "Quest6", NULL, STRING, &V_SideQuestListStrL6 },
	{ "Default", "Quest7", NULL, STRING, &V_SideQuestListStrL7 },
	{ "Default", "Quest8", NULL, STRING, &V_SideQuestListStrL8 },
	{ "Default", "Quest9", NULL, STRING, &V_SideQuestListStrL9 },
	{ "Default", "Quest10", NULL, STRING, &V_SideQuestListStrL10 },
	{ "Default", "Quest11", NULL, STRING, &V_SideQuestListStrL11 },
	{ "Default", "Quest12", NULL, STRING, &V_SideQuestListStrL12 },
	{ "Default", "Quest13", NULL, STRING, &V_SideQuestListStrL13 },
	{ "Default", "Quest14", NULL, STRING, &V_SideQuestListStrL14 },
	{ "Default", "Quest15", NULL, STRING, &V_SideQuestListStrL15 },
	{ "Default", "Quest16", NULL, STRING, &V_SideQuestListStrL16 },
	{ "Default", "Quest17", NULL, STRING, &V_SideQuestListStrL17 },
	{ "Default", "Quest18", NULL, STRING, &V_SideQuestListStrL18 },
	{ "Default", "Quest19", NULL, STRING, &V_SideQuestListStrL19 },
	{ "Default", "Quest20", NULL, STRING, &V_SideQuestListStrL20 },

	{ "Default", "QuestLevel1", NULL, INTEGER, &V_SideQuestLevel[1] },
	{ "Default", "QuestLevel2", NULL, INTEGER, &V_SideQuestLevel[2] },
	{ "Default", "QuestLevel3", NULL, INTEGER, &V_SideQuestLevel[3] },
	{ "Default", "QuestLevel4", NULL, INTEGER, &V_SideQuestLevel[4] },
	{ "Default", "QuestLevel5", NULL, INTEGER, &V_SideQuestLevel[5] },
	{ "Default", "QuestLevel6", NULL, INTEGER, &V_SideQuestLevel[6] },
	{ "Default", "QuestLevel7", NULL, INTEGER, &V_SideQuestLevel[7] },
	{ "Default", "QuestLevel8", NULL, INTEGER, &V_SideQuestLevel[8] },
	{ "Default", "QuestLevel9", NULL, INTEGER, &V_SideQuestLevel[9] },
	{ "Default", "QuestLevel10", NULL, INTEGER, &V_SideQuestLevel[10] },
	{ "Default", "QuestLevel11", NULL, INTEGER, &V_SideQuestLevel[11] },
	{ "Default", "QuestLevel12", NULL, INTEGER, &V_SideQuestLevel[12] },
	{ "Default", "QuestLevel13", NULL, INTEGER, &V_SideQuestLevel[13] },
	{ "Default", "QuestLevel14", NULL, INTEGER, &V_SideQuestLevel[14] },
	{ "Default", "QuestLevel15", NULL, INTEGER, &V_SideQuestLevel[15] },
	{ "Default", "QuestLevel16", NULL, INTEGER, &V_SideQuestLevel[16] },
	{ "Default", "QuestLevel17", NULL, INTEGER, &V_SideQuestLevel[17] },
	{ "Default", "QuestLevel18", NULL, INTEGER, &V_SideQuestLevel[18] },
	{ "Default", "QuestLevel19", NULL, INTEGER, &V_SideQuestLevel[19] },
	{ "Default", "QuestLevel20", NULL, INTEGER, &V_SideQuestLevel[20] }
};

CONFIGURATION SCRIPT_TEXT[] =
{
	{ "Default", "Pages", NULL, INTEGER, &V_SideQuestTextPages },

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

BOOL LoadScriptSettings()
{
	CHAR File[MAX_PATH], Returned[100000];
	V_FilePathC = "\\Interface\\Scripts\\Script_Settings.ini";
	GetModuleDirectory();

	std::vector<char> v(V_FilePathC.length() + 1);
	std::strcpy(&v[0], V_FilePathC.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < ArraySize(SCRIPT_SETTINGS); i++)
	{
		GetPrivateProfileStringA(SCRIPT_SETTINGS[i].Section, SCRIPT_SETTINGS[i].Name, SCRIPT_SETTINGS[i].Default, Returned, sizeof(Returned), File);

		if (SCRIPT_SETTINGS[i].Type == BOOLEAN)
			*(LPBOOL)SCRIPT_SETTINGS[i].Variable = Bool(Returned);

		else if (SCRIPT_SETTINGS[i].Type == INTEGER)
			*(LPINT)SCRIPT_SETTINGS[i].Variable = Integer(Returned);

		else if (SCRIPT_SETTINGS[i].Type == STRING)
			strncpy_s((LPSTR)SCRIPT_SETTINGS[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL LoadScriptList(INT iExpansionTag, INT iPageTag)
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
	V_FilePath = "\\Interface\\Scripts\\Script_List_" + V_SideQuestTagExpansion + "_P" + V_SideQuestTagPage + ".ini";
	GetModuleDirectory();

	std::vector<char> v(V_FilePath.length() + 1);
	std::strcpy(&v[0], V_FilePath.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	for (INT i = 0; i < ArraySize(SCRIPT_LIST); i++)
	{
		GetPrivateProfileStringA(SCRIPT_LIST[i].Section, SCRIPT_LIST[i].Name, SCRIPT_LIST[i].Default, Returned, sizeof(Returned), File);

		if (SCRIPT_LIST[i].Type == BOOLEAN)
			*(LPBOOL)SCRIPT_LIST[i].Variable = Bool(Returned);

		else if (SCRIPT_LIST[i].Type == INTEGER)
			*(LPINT)SCRIPT_LIST[i].Variable = Integer(Returned);

		else if (SCRIPT_LIST[i].Type == STRING)
			strncpy_s((LPSTR)SCRIPT_LIST[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL LoadScriptText(INT iQuestTag, INT iPageTag)
{
	long double QuestNoStr = iQuestTag;
	long double PageNoStr = iPageTag;
	std::string str = std::to_string(QuestNoStr);
	V_SideQuestTagQuest = str;

	std::string page = std::to_string(PageNoStr);
	long double SideQuestTextPages = V_SideQuestTextPages;

	CHAR File[MAX_PATH], Returned[100000];

	if (V_SideQuestTextPages < 1)
	{
		V_FilePathB = "\\Interface\\Scripts\\Script_Text_" + V_SideQuestTagExpansion + "_P" + V_SideQuestTagPage + "_Q" + V_SideQuestTagQuest + "_P1.ini";
	}
	else
	{
		std::string str = std::to_string(SideQuestTextPages);
		V_FilePathB = "\\Interface\\Scripts\\Script_Text_" + V_SideQuestTagExpansion + "_P" + V_SideQuestTagPage + "_Q" + V_SideQuestTagQuest + "_P" + page + ".ini";
	}
	GetModuleDirectory();

	//Hf2Log("Loading Quest...");

	std::vector<char> v(V_FilePathB.length() + 1);
	std::strcpy(&v[0], V_FilePathB.c_str());
	char* fp = &v[0];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, fp);

	Hf2Log(fp);

	for (INT i = 0; i < ArraySize(SCRIPT_TEXT); i++)
	{
		GetPrivateProfileStringA(SCRIPT_TEXT[i].Section, SCRIPT_TEXT[i].Name, SCRIPT_TEXT[i].Default, Returned, sizeof(Returned), File);

		if (SCRIPT_TEXT[i].Type == BOOLEAN)
			*(LPBOOL)SCRIPT_TEXT[i].Variable = Bool(Returned);

		else if (SCRIPT_TEXT[i].Type == INTEGER)
			*(LPINT)SCRIPT_TEXT[i].Variable = Integer(Returned);

		else if (SCRIPT_TEXT[i].Type == STRING)
			strncpy_s((LPSTR)SCRIPT_TEXT[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}
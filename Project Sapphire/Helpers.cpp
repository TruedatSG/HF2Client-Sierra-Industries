#include "Hack.h"

#include <map>
#include <io.h>

std::map<unsigned __int32, LPCELLFILEII> mCachedCellFiles;

LPSTR AddCommas(DOUBLE f, INT places)
{
	static CHAR tmp[40];
	LPSTR s;
	INT i = 0;

	if ((places < 0) || (places > 38)) 
	{
		tmp[0] = 0;
		return tmp;
	}

	sprintf_s(tmp, "%#.*f", places, f);
	s = strchr(tmp, '.');
	if (!places)
		*s = '\0';

	while (--s > tmp) 
	{
		if (i++ == 2) 
		{
			if (s[-1] == '-') break;
			i = 0;
			memmove(s + 1, s, strlen(s) + 1);
			*s = ',';
		}
	}

	return tmp;
}

LPSTR AddCommasNoZero(DOUBLE f, INT places)
{
	static CHAR tmp[40];
	LPSTR s;
	INT i = 0;

	if(f < 1)
	{
		sprintf_s(tmp, "", places, f);

		return tmp;
	}

	if ((places < 0) || (places > 38)) 
	{
		tmp[0] = 0;
		return tmp;
	}

	sprintf_s(tmp, "%#.*f", places, f);
	s = strchr(tmp, '.');
	if (!places)
		*s = '\0';

	while (--s > tmp) 
	{
		if (i++ == 2) 
		{
			if (s[-1] == '-') break;
			i = 0;
			memmove(s + 1, s, strlen(s) + 1);
			*s = ',';
		}
	}

	return tmp;
}

LPSTR AddCommasNoZeroNotice(DOUBLE f, INT places, INT entry)
{
	static CHAR tmp[40];
	LPSTR s;
	INT i = 0;

	if (f < 1 && V_LadderName[entry + (V_ShowLadderPage * 25)][0] != NULL)
	{
		sprintf_s(tmp, "Loading...", places, f);

		return tmp;
	}
	else if (f < 1)
	{
		sprintf_s(tmp, "", places, f);

		return tmp;
	}

	if ((places < 0) || (places > 38))
	{
		tmp[0] = 0;
		return tmp;
	}

	sprintf_s(tmp, "%#.*f", places, f);
	s = strchr(tmp, '.');
	if (!places)
		*s = '\0';

	while (--s > tmp)
	{
		if (i++ == 2)
		{
			if (s[-1] == '-') break;
			i = 0;
			memmove(s + 1, s, strlen(s) + 1);
			*s = ',';
		}
	}

	return tmp;
}

LPBYTE AllocReadFile(LPSTR FileName)
{
	HANDLE hFile = OpenFileRead(FileName);
	INT FileSize = GetFileSize(hFile, 0);
	
	if (FileSize <= 0)
		return 0;

	LPBYTE Buffer = new BYTE[FileSize];
	ReadFile(hFile, Buffer, FileSize);

	CloseHandle(hFile);
	return Buffer;
}

VOID DeleteCellFile(LPCELLFILE File)
{
	if (File)
	{
		D2CMP_DeleteCellFile(File);
		delete File;
	}
}

BOOL DropGold(DWORD ID, INT Amount)
{
	if (Amount <= 0)
		return FALSE;

	LPBYTE Packet = new BYTE[9];
	Packet[0] = 0x50;
	*(LPDWORD)&Packet[1] = ID;
	*(LPDWORD)&Packet[5] = Amount;
	D2NET_SendPacket(9, 1, Packet);
	delete [] Packet;
	return TRUE;
}

BOOL EnableDebugPrivileges()
{
	HANDLE Token;
	LUID DebugNameValue;
	TOKEN_PRIVILEGES TokenPrivilege;
	
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &Token);
	LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &DebugNameValue);
	
	TokenPrivilege.PrivilegeCount = 1;
	TokenPrivilege.Privileges[0].Luid = DebugNameValue;
	TokenPrivilege.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(Token, FALSE, &TokenPrivilege, sizeof(TokenPrivilege), NULL, NULL);

	CloseHandle(GetCurrentProcess());
	CloseHandle(Token);
	return TRUE;
}

DWORD GetExp(DWORD Level)
{
#ifndef FFXIVMOD
	INT64 Experience[] =
	{
		0, 500, 1500, 3750, 7875, 14175, 22680, 32886, 44396, 57715, 72144, 90180, 112725, 140906, 176132, 220165, 275207, 344008, 
		430010, 537513, 671891, 839864, 1049830, 1312287, 1640359, 2050449, 2563061, 3203826, 3902260, 4663553, 5493363, 
		6397855, 7383752, 8458379, 9629723, 10906488, 12298162, 13815086, 15468534, 17270791, 19235252, 21376515, 23710491, 
		26254525, 29027522, 32050088, 35344686, 38935798, 42850109, 47116709, 51767302, 56836449, 62361819, 68384473, 74949165, 
		82104680, 89904191, 98405658, 107672256, 117772849, 128782495, 140783010, 153863570, 168121381, 183662396, 200602101, 
		219066380, 239192444, 261129853, 285041630, 311105466, 339515048, 370481492, 404234916, 441026148, 481128591, 524840254, 
		572485967, 624419793, 681027665, 742730244, 809986056, 883294891, 963201521, 1050299747, 1145236814, 1248718217, 
		1361512946, 1484459201, 1618470619, 1764543065, 1923762030, 2097310703, 2286478756LL, 2492671933LL, 2717422497LL, 2962400612LL, 
		3229426756LL, 3520485254LL, 3837739017LL, 4154992780LL, 4472246543LL, 4789500306LL, 5106754069LL, 5424007832LL, 5741261595LL, 6058515358LL,
		6375769121LL, 6693022884LL, 7010276647LL, 7327530410LL

	};
#else
	INT64 Experience[] =
	{
		0, 500, 1250, 2250, 3500, 5000, 6750, 8750, 10950, 13350, 15950, 18750, 21750, 24750, 28350, 31950, 35750,
		39750, 43950, 48350, 52950, 57750, 62750, 67850, 73050, 78350, 83750, 89250, 94850, 100550, 106350, 112250,
		118250, 124350, 130550, 136850, 143250, 149250, 156350, 163050, 169850, 176750, 183750, 190850, 198050, 205350,
		212750, 220250, 227850, 235550, 243350, 251350, 260550, 270950, 282550, 295350, 309350, 324550, 340950, 358550,
		337350, 397350, 418850, 441850, 466350, 492350, 519850, 548850, 579350, 611350, 645350, 681350, 719350, 759350,
		801350, 845350, 889850, 934850, 980350, 1026350, 1072850, 1119850, 1167350, 1215350, 1263850, 1312850, 1362350,
		1412350, 1462850, 1513850, 1565350, 1617350, 1669850, 1722850, 1776350, 1830350, 1884850, 1939850, 1995350, 2051350, 
		2107850
	};
#endif
	
	return Experience[Level];
}

DWORD GetGold(DWORD Level)
{
	INT Gold[] =
	{
		0, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 110000, 120000, 130000, 140000,
		150000, 160000, 170000, 180000, 190000, 200000, 210000, 220000, 230000, 240000, 250000, 260000, 270000, 
		280000, 290000, 300000, 310000, 320000, 330000, 340000, 350000, 360000, 370000, 380000, 390000, 400000, 
		410000, 420000, 430000, 440000, 450000, 460000, 470000, 480000, 490000, 500000, 510000, 520000, 530000, 
		540000, 550000, 560000, 570000, 580000, 590000, 600000, 610000, 620000, 630000, 640000, 650000, 660000, 
		670000, 680000, 690000, 700000, 710000, 720000, 730000, 740000, 750000, 760000, 770000, 780000, 790000, 
		800000, 810000, 820000, 830000, 840000, 850000, 860000, 870000, 880000, 890000, 900000, 910000, 920000, 
		930000, 940000, 950000, 960000, 970000, 980000, 990000, 990000, 990000, 990000, 990000, 990000, 990000,
		990000, 990000, 990000, 990000, 990000, 990000
	};
	
	return Gold[Level];
}

BOOL GetMapName(BYTE iMapID, LPSTR lpszBuffer, DWORD dwMaxChars)
{
	if(lpszBuffer == NULL)
		return FALSE;

	lpszBuffer[0] = '\0';
	::memset(lpszBuffer, 0, sizeof(TCHAR) * dwMaxChars);
	if(dwMaxChars == 0)
		return FALSE;

	switch (iMapID)
	{	
		///////////////////////////////////////////////////
		// Act 1 Maps (Lord of Destruction)
		///////////////////////////////////////////////////
	case MAP_A1_ROGUE_ENCAMPMENT:
		strncpy(lpszBuffer, "Rogue Encampment", dwMaxChars);
		break;

	case MAP_A1_BLOOD_MOOR:
		strncpy(lpszBuffer, "Blood Moor", dwMaxChars);
		break;

	case MAP_A1_COLD_PLAINS:
		strncpy(lpszBuffer, "Cold Plains", dwMaxChars);
		break;

	case MAP_A1_STONY_FIELD:
		strncpy(lpszBuffer, "Stony Field", dwMaxChars);
		break;

	case MAP_A1_DARK_WOOD:
		strncpy(lpszBuffer, "Dark Wood", dwMaxChars);
		break;

	case MAP_A1_BLACK_MARSH:
		strncpy(lpszBuffer, "Black Marsh", dwMaxChars);
		break;

	case MAP_A1_DEN_OF_EVIL:
		strncpy(lpszBuffer, "Den of Evil", dwMaxChars);
		break;

	case MAP_A1_CAVE_LEVEL_1:
		strncpy(lpszBuffer, "Cave Level 1", dwMaxChars);
		break;

	case MAP_A1_UNDERGROUND_PASSAGE_LEVEL_1:
		strncpy(lpszBuffer, "Underground Passage Level 1", dwMaxChars);
		break;

	case MAP_A1_HOLE_LEVEL_1:
		strncpy(lpszBuffer, "Hole Level 1", dwMaxChars);
		break;

	case MAP_A1_PIT_LEVEL_1:
		strncpy(lpszBuffer, "Pit Level 1", dwMaxChars);
		break;

	case MAP_A1_CAVE_LEVEL_2:
		strncpy(lpszBuffer, "Cave Level 2", dwMaxChars);
		break;

	case MAP_A1_UNDERGROUND_PASSAGE_LEVEL_2:
		strncpy(lpszBuffer, "Underground Passage Level 2", dwMaxChars);
		break;

	case MAP_A1_HOLE_LEVEL_2:
		strncpy(lpszBuffer, "Hole Level 2", dwMaxChars);
		break;

	case MAP_A1_PIT_LEVEL_2:
		strncpy(lpszBuffer, "Pit Level 2", dwMaxChars);
		break;

	case MAP_A1_BURIAL_GROUNDS:
		strncpy(lpszBuffer, "Burial Grounds", dwMaxChars);
		break;

	case MAP_A1_CRYPT:
		strncpy(lpszBuffer, "Crypt", dwMaxChars);
		break;

	case MAP_A1_MAUSOLEUM:
		strncpy(lpszBuffer, "Mausoleum", dwMaxChars);
		break;

	case MAP_A1_FORGOTTEN_TOWER:
		strncpy(lpszBuffer, "Forgotten Tower", dwMaxChars);
		break;

	case MAP_A1_TOWER_CELLAR_LEVEL_1:
		strncpy(lpszBuffer, "Tower Cellar Level 1", dwMaxChars);
		break;

	case MAP_A1_TOWER_CELLAR_LEVEL_2:
		strncpy(lpszBuffer, "Tower Cellar Level 2", dwMaxChars);
		break;

	case MAP_A1_TOWER_CELLAR_LEVEL_3:
		strncpy(lpszBuffer, "Tower Cellar Level 3", dwMaxChars);
		break;

	case MAP_A1_TOWER_CELLAR_LEVEL_4:
		strncpy(lpszBuffer, "Tower Cellar Level 4", dwMaxChars);
		break;

	case MAP_A1_TOWER_CELLAR_LEVEL_5:
		strncpy(lpszBuffer, "Tower Cellar Level 5", dwMaxChars);
		break;

	case MAP_A1_TAMOE_HIGHLAND:
		strncpy(lpszBuffer, "Tamoe Highland", dwMaxChars);
		break;

	case MAP_A1_MONASTERY_GATE:
		strncpy(lpszBuffer, "Monastery Gate", dwMaxChars);
		break;

	case MAP_A1_OUTER_CLOISTER:
		strncpy(lpszBuffer, "Outer Cloister", dwMaxChars);
		break;

	case MAP_A1_BARRACKS:
		strncpy(lpszBuffer, "Barracks", dwMaxChars);
		break;

	case MAP_A1_JAIL_LEVEL_1:
		strncpy(lpszBuffer, "Jail Level 1", dwMaxChars);
		break;

	case MAP_A1_JAIL_LEVEL_2:
		strncpy(lpszBuffer, "Jail Level 2", dwMaxChars);
		break;

	case MAP_A1_JAIL_LEVEL_3:
		strncpy(lpszBuffer, "Jail Level 3", dwMaxChars);
		break;

	case MAP_A1_INNER_CLOISTER:
	case MAP_A1_INNER_CLOISTER_2:
		strncpy(lpszBuffer, "Inner Cloister", dwMaxChars);
		break;

	case MAP_A1_CATACOMBS_LEVEL_1:
		strncpy(lpszBuffer, "Catacombs Level 1", dwMaxChars);
		break;

	case MAP_A1_CATACOMBS_LEVEL_2:
		strncpy(lpszBuffer, "Catacombs Level 2", dwMaxChars);
		break;

	case MAP_A1_CATACOMBS_LEVEL_3:
		strncpy(lpszBuffer, "Catacombs Level 3", dwMaxChars);
		break;

	case MAP_A1_CATACOMBS_LEVEL_4:
		strncpy(lpszBuffer, "Catacombs Level 4", dwMaxChars);
		break;

	case MAP_A1_TRISTRAM:
		strncpy(lpszBuffer, "Tristram", dwMaxChars);
		break;

	case MAP_A1_THE_SECRET_COW_LEVEL:
		strncpy(lpszBuffer, "The Secret Cow Level", dwMaxChars);
		break;


		///////////////////////////////////////////////////
		// Act 2 Maps
		///////////////////////////////////////////////////
	case MAP_A2_LUT_GHOLEIN:
		strncpy(lpszBuffer, "Lut Gholein", dwMaxChars);
		break;

	case MAP_A2_ROCKY_WASTE:
		strncpy(lpszBuffer, "Rocky Waste", dwMaxChars);
		break;

	case MAP_A2_DRY_HILLS:
		strncpy(lpszBuffer, "Dry Hills", dwMaxChars);
		break;

	case MAP_A2_FAR_OASIS:
		strncpy(lpszBuffer, "Far Oasis", dwMaxChars);
		break;

	case MAP_A2_LOST_CITY:
		strncpy(lpszBuffer, "Lost City", dwMaxChars);
		break;

	case MAP_A2_VALLEY_OF_SNAKES:
		strncpy(lpszBuffer, "Valley of Snakes", dwMaxChars);
		break;

	case MAP_A2_CANYON_OF_THE_MAGI:
		strncpy(lpszBuffer, "Cayon of the Magi", dwMaxChars);
		break;

	case MAP_A2_SEWERS_LEVEL_1:
		strncpy(lpszBuffer, "Sewers Level 1", dwMaxChars);
		break;

	case MAP_A2_SEWERS_LEVEL_2:
		strncpy(lpszBuffer, "Sewers Level 2", dwMaxChars);
		break;

	case MAP_A2_SEWERS_LEVEL_3:
		strncpy(lpszBuffer, "Sewers Level 3", dwMaxChars);
		break;

	case MAP_A2_HAREM_LEVEL_1:
		strncpy(lpszBuffer, "Harem Level 1", dwMaxChars);
		break;

	case MAP_A2_HAREM_LEVEL_2:
		strncpy(lpszBuffer, "Harem Level 2", dwMaxChars);
		break;

	case MAP_A2_PALACE_CELLAR_LEVEL_1:
		strncpy(lpszBuffer, "Palace Cellar Level 1", dwMaxChars);
		break;

	case MAP_A2_PALACE_CELLAR_LEVEL_2:
		strncpy(lpszBuffer, "Palace Cellar Level 2", dwMaxChars);
		break;

	case MAP_A2_PALACE_CELLAR_LEVEL_3:
		strncpy(lpszBuffer, "Palace Cellar Level 3", dwMaxChars);
		break;

	case MAP_A2_STONY_TOMB_LEVEL_1:
		strncpy(lpszBuffer, "Stony Tomb Level 1", dwMaxChars);
		break;

	case MAP_A2_HALLS_OF_THE_DEAD_LEVEL_1:
		strncpy(lpszBuffer, "Halls of the Dead Level 1", dwMaxChars);
		break;

	case MAP_A2_HALLS_OF_THE_DEAD_LEVEL_2:
		strncpy(lpszBuffer, "Halls of the Dead Level 2", dwMaxChars);
		break;

	case MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_1:
		strncpy(lpszBuffer, "Claw Viper Temple Level 1", dwMaxChars);
		break;

	case MAP_A2_STONY_TOMB_LEVEL_2:
		strncpy(lpszBuffer, "Stony Tomb Level 2", dwMaxChars);
		break;

	case MAP_A2_HALLS_OF_THE_DEAD_LEVEL_3:
		strncpy(lpszBuffer, "Halls of the Dead Level 3", dwMaxChars);
		break;

	case MAP_A2_CLAW_VIPER_TEMPLE_LEVEL_2:
		strncpy(lpszBuffer, "Claw Viper Temple Level 2", dwMaxChars);
		break;

	case MAP_A2_MAGGOT_LAIR_LEVEL_1:
		strncpy(lpszBuffer, "Maggot Lair Level 1", dwMaxChars);
		break;

	case MAP_A2_MAGGOT_LAIR_LEVEL_2:
		strncpy(lpszBuffer, "Maggot Lair Level 2", dwMaxChars);
		break;

	case MAP_A2_MAGGOT_LAIR_LEVEL_3:
		strncpy(lpszBuffer, "Maggot Lair Level 3", dwMaxChars);
		break;

	case MAP_A2_ANCIENT_TUNNELS:
		strncpy(lpszBuffer, "Ancient Tunnels", dwMaxChars);
		break;

	case MAP_A2_TAL_RASHAS_TOMB_1:
	case MAP_A2_TAL_RASHAS_TOMB_2:
	case MAP_A2_TAL_RASHAS_TOMB_3:
	case MAP_A2_TAL_RASHAS_TOMB_4:
	case MAP_A2_TAL_RASHAS_TOMB_5:
	case MAP_A2_TAL_RASHAS_TOMB_6:
	case MAP_A2_TAL_RASHAS_TOMB_7:
		strncpy(lpszBuffer, "Tal Rasha's Tomb", dwMaxChars);
		break;

	case MAP_A2_TAL_RASHAS_CHAMBER:
		strncpy(lpszBuffer, "Tal Rasha's Chamber", dwMaxChars);
		break;

	case MAP_A2_ARCANE_SANCTUARY:
		strncpy(lpszBuffer, "Arcane Sanctuary", dwMaxChars);
		break;


		///////////////////////////////////////////////////
		// Act 3 Maps
		///////////////////////////////////////////////////
	case MAP_A3_KURAST_DOCKS:
		strncpy(lpszBuffer, "Kurast Docks", dwMaxChars);
		break;

	case MAP_A3_SPIDER_FOREST:
		strncpy(lpszBuffer, "Spider Forest", dwMaxChars);
		break;

	case MAP_A3_GREAT_MARSH:
		strncpy(lpszBuffer, "Great Marsh", dwMaxChars);
		break;

	case MAP_A3_FLAYER_JUNGLE:
		strncpy(lpszBuffer, "Flayer Jungle", dwMaxChars);
		break;

	case MAP_A3_LOWER_KURAST:
		strncpy(lpszBuffer, "Lower Kurast", dwMaxChars);
		break;

	case MAP_A3_KURAST_BAZAAR:
		strncpy(lpszBuffer, "Kurast Bazaar", dwMaxChars);
		break;

	case MAP_A3_UPPER_KURAST:
		strncpy(lpszBuffer, "Upper Kurast", dwMaxChars);
		break;

	case MAP_A3_KURAST_CAUSEWAY:
		strncpy(lpszBuffer, "Kurast Causeway", dwMaxChars);
		break;

	case MAP_A3_TRAVINCAL:
		strncpy(lpszBuffer, "Travincal", dwMaxChars);
		break;

	case MAP_A3_ARCHNID_LAIR:
		strncpy(lpszBuffer, "Arachnid Lair", dwMaxChars);
		break;

	case MAP_A3_SPIDER_CAVERN:
		strncpy(lpszBuffer, "Spider Cavern", dwMaxChars);
		break;

	case MAP_A3_SWAMPY_PIT_LEVEL_1:
		strncpy(lpszBuffer, "Swampy Pit Level 1", dwMaxChars);
		break;

	case MAP_A3_SWAMPY_PIT_LEVEL_2:
		strncpy(lpszBuffer, "Swampy Pit Level 2", dwMaxChars);
		break;

	case MAP_A3_FLAYER_DUNGEON_LEVEL_1:
		strncpy(lpszBuffer, "Flayer Dungeon Level 1", dwMaxChars);
		break;

	case MAP_A3_FLAYER_DUNGEON_LEVEL_2:
		strncpy(lpszBuffer, "Flayer Dungeon Level 2", dwMaxChars);
		break;

	case MAP_A3_SWAMPY_PIT_LEVEL_3:
		strncpy(lpszBuffer, "Swampy Pit Level 3", dwMaxChars);
		break;

	case MAP_A3_FLAYER_DUNGEON_LEVEL_3:
		strncpy(lpszBuffer, "Flayer Dungeon Level 3", dwMaxChars);
		break;

	case MAP_A3_SEWERS_LEVEL_1:
		strncpy(lpszBuffer, "Sewers Level 1", dwMaxChars);
		break;

	case MAP_A3_SEWERS_LEVEL_2:
		strncpy(lpszBuffer, "Sewers Level 2", dwMaxChars);
		break;

	case MAP_A3_RUINED_TEMPLE:
		strncpy(lpszBuffer, "Ruined Temple", dwMaxChars);
		break;

	case MAP_A3_DISUSED_FANE:
		strncpy(lpszBuffer, "Disused Fane", dwMaxChars);
		break;

	case MAP_A3_FORGOTTEN_RELIQUARY:
		strncpy(lpszBuffer, "Forgotten Reliquary", dwMaxChars);
		break;

	case MAP_A3_FORGOTTEN_TEMPLE:
		strncpy(lpszBuffer, "Forgotten Temple", dwMaxChars);
		break;

	case MAP_A3_RUINED_FANE:
		strncpy(lpszBuffer, "Ruined Fane", dwMaxChars);
		break;

	case MAP_A3_DISUSED_RELIQUARY:
		strncpy(lpszBuffer, "Disused Reliquary", dwMaxChars);
		break;

	case MAP_A3_DURANCE_OF_HATE_LEVEL_1:
		strncpy(lpszBuffer, "Durance of Hate Level 1", dwMaxChars);
		break;

	case MAP_A3_DURANCE_OF_HATE_LEVEL_2:
		strncpy(lpszBuffer, "Durance of Hate Level 2", dwMaxChars);
		break;

	case MAP_A3_DURANCE_OF_HATE_LEVEL_3:
		strncpy(lpszBuffer, "Durance of Hate Level 3", dwMaxChars);
		break;

		///////////////////////////////////////////////////
		// Act 4 Maps
		///////////////////////////////////////////////////
	case MAP_A4_THE_PANDEMONIUM_FORTRESS:
		strncpy(lpszBuffer, "The Pandemonium Fortress", dwMaxChars);
		break;

	case MAP_A4_OUTER_STEPPES:
		strncpy(lpszBuffer, "Outer Steppes", dwMaxChars);
		break;

	case MAP_A4_PLAINS_OF_DESPAIR:
		strncpy(lpszBuffer, "Plains of Despair", dwMaxChars);
		break;

	case MAP_A4_CITY_OF_THE_DAMNED:
		strncpy(lpszBuffer, "City of the Damned", dwMaxChars);
		break;

	case MAP_A4_RIVER_OF_FLAME:
		strncpy(lpszBuffer, "River of Flame", dwMaxChars);
		break;

	case MAP_A4_THE_CHAOS_SANCTUARY:
		strncpy(lpszBuffer, "The Chaos Sanctuary", dwMaxChars);
		break;

		///////////////////////////////////////////////////
		// Act 5 Maps (Ruby Dreams)
		///////////////////////////////////////////////////
	case MAP_A5_HARROGATH:
		strncpy(lpszBuffer, "Harrogath", dwMaxChars);
		break;

	case MAP_A5_THE_BLOODY_FOOTHILLS:
		strncpy(lpszBuffer, "The Bloody Foothills", dwMaxChars);
		break;

	case MAP_A5_FRIGID_HIGHLANDS:
		strncpy(lpszBuffer, "Frigid Highlands", dwMaxChars);
		break;

	case MAP_A5_ARREAT_PLATEAU:
		strncpy(lpszBuffer, "Arreat Plateau", dwMaxChars);
		break;

	case MAP_A5_CRYSTALLINE_PASSAGE:
		strncpy(lpszBuffer, "Crystalline Passage", dwMaxChars);
		break;

	case MAP_A5_FROZEN_RIVER:
		strncpy(lpszBuffer, "Frozen River", dwMaxChars);
		break;

	case MAP_A5_GLACIAL_TRAIL:
		strncpy(lpszBuffer, "Glacial Trail", dwMaxChars);
		break;

	case MAP_A5_DRIFTER_CAVERN:
		strncpy(lpszBuffer, "Drifter Cavern", dwMaxChars);
		break;

	case MAP_A5_FROZEN_TUNDRA:
		strncpy(lpszBuffer, "Frozen Tundra", dwMaxChars);
		break;

	case MAP_A5_THE_ANCIENTS_WAY:
		strncpy(lpszBuffer, "The Ancients' Way", dwMaxChars);
		break;

	case MAP_A5_ICY_CELLAR:
		strncpy(lpszBuffer, "Icy Cellar", dwMaxChars);
		break;

	case MAP_A5_ARREAT_SUMMIT:
		strncpy(lpszBuffer, "Arreat Summit", dwMaxChars);
		break;

	case MAP_A5_HALLS_OF_PAIN:
		strncpy(lpszBuffer, "Halls of Pain", dwMaxChars);
		break;

	case MAP_A5_ABADDON:
		strncpy(lpszBuffer, "Abaddon", dwMaxChars);
		break;

	case MAP_A5_PIT_OF_ACHERON:
		strncpy(lpszBuffer, "Pit of Acheron", dwMaxChars);
		break;

	case MAP_A5_INFERNAL_PIT:
		strncpy(lpszBuffer, "Infernal Pit", dwMaxChars);
		break;

	case MAP_A5_NIHLATHAKS_TEMPLE:
		strncpy(lpszBuffer, "Nihlathak's Temple", dwMaxChars);
		break;

	case MAP_A5_HALLS_OF_ANGUISH:
		strncpy(lpszBuffer, "Halls of Anguish", dwMaxChars);
		break;

	case MAP_A5_HALLS_OF_VAUGHT:
		strncpy(lpszBuffer, "Halls of Vaught", dwMaxChars);
		break;	

	case MAP_A5_WORLDSTONE_KEEP_LEVEL_1:
		strncpy(lpszBuffer, "Worldstone Keep Level 1", dwMaxChars);
		break;

	case MAP_A5_WORLDSTONE_KEEP_LEVEL_2:
		strncpy(lpszBuffer, "Worldstone Keep Level 2", dwMaxChars);
		break;

	case MAP_A5_WORLDSTONE_KEEP_LEVEL_3:
		strncpy(lpszBuffer, "Worldstone Keep Level 3", dwMaxChars);
		break;

	case MAP_A5_THRONE_OF_DESTRUCTION:
		strncpy(lpszBuffer, "Throne of Destruction", dwMaxChars);
		break;

	case MAP_A5_WORLDSTONE_KEEP:
		strncpy(lpszBuffer, "The Worldstone Chamber", dwMaxChars);
		break;

		///////////////////////////////////////////////////
		// Act 6 Maps (Wings of the Goddess)
		///////////////////////////////////////////////////
	case MAP_A6_BIBIKI_BAY:
		strncpy(lpszBuffer, "Bibiki Bay", dwMaxChars);
		break;

	case MAP_A6_HIDDEN_PASSAGE:
		strncpy(lpszBuffer, "The Hidden Passage", dwMaxChars);
		break;

	case MAP_A6_OUTRIGGER_TUNNEL:
		strncpy(lpszBuffer, "The Outrigger Tunnel", dwMaxChars);
		break;

	case MAP_A6_RAVEN_CEMETERY:
		strncpy(lpszBuffer, "Raven Cemetery", dwMaxChars);
		break;

	case MAP_A6_BIBIKIS_TOMB:
		strncpy(lpszBuffer, "Bibiki's Tomb", dwMaxChars);
		break;

	case MAP_A6_CROSBYS_HIDEOUT:
		strncpy(lpszBuffer, "Crosby's Hideout", dwMaxChars);
		break;

	case MAP_A6_DIAMOND_CAVERN:
		strncpy(lpszBuffer, "Diamond Cavern", dwMaxChars);
		break;

	case MAP_A6_TRAVELLERS_CRYPT:
		strncpy(lpszBuffer, "Traveller's Crypt", dwMaxChars);
		break;

	case MAP_A6_FORGOTTEN_CELLAR:
		strncpy(lpszBuffer, "Forgotten Cellar", dwMaxChars);
		break;

	case MAP_A6_EMERALD_COVE:
		strncpy(lpszBuffer, "Emerald Cove", dwMaxChars);
		break;

	case MAP_A6_RACCOON_FOREST:
		strncpy(lpszBuffer, "Raccoon Forest", dwMaxChars);
		break;

		///////////////////////////////////////////////////
		// Act 7 Maps (Origins of Silence)
		///////////////////////////////////////////////////
	case MAP_A7_SANITARIUM_BASEMENT:
		strncpy(lpszBuffer, "Sanitarium Basement", dwMaxChars);
		break;

	case MAP_A7_SANITARIUM_LEVEL_1:
		strncpy(lpszBuffer, "Sanitarium Level 1", dwMaxChars);
		break;

	case MAP_A7_SANITARIUM_LEVEL_2:
		strncpy(lpszBuffer, "Sanitarium Level 2", dwMaxChars);
		break;

	case MAP_A7_LABORATORY:
		strncpy(lpszBuffer, "Laboratory", dwMaxChars);
		break;

	case MAP_A7_ELEVATOR_SHAFT:
		strncpy(lpszBuffer, "Elevator Shaft", dwMaxChars);
		break;

	case MAP_A7_SANITARIUM_LEVEL_28:
		strncpy(lpszBuffer, "Sanitarium Level 28", dwMaxChars);
		break;

	case MAP_A7_SANITARIUM_LEVEL_29:
		strncpy(lpszBuffer, "Sanitarium Level 29", dwMaxChars);
		break;

	case MAP_A7_SANITARIUM_LEVEL_30:
		strncpy(lpszBuffer, "Sanitarium Level 30", dwMaxChars);
		break;

	case MAP_A7_PENTHOUSE_SUITE:
		strncpy(lpszBuffer, "Penthouse Suite", dwMaxChars);
		break;

	case MAP_A7_CHAMBER_OF_INTOLERANCE:
		strncpy(lpszBuffer, "Chamber of Intolerance", dwMaxChars);
		break;

	case MAP_A7_PALACE_GARDEN:
		strncpy(lpszBuffer, "Palace Garden", dwMaxChars);
		break;

	case MAP_A7_SAND_MOUNTAIN_LEVEL_1:
		strncpy(lpszBuffer, "Sand Mountain Level 1", dwMaxChars);
		break;

	case MAP_A7_DIAMOND_CAVERN:
		strncpy(lpszBuffer, "Diamond Cavern", dwMaxChars);
		break;

	case MAP_A7_FORGOTTEN_CELLAR:
		strncpy(lpszBuffer, "Forgotten Cellar", dwMaxChars);
		break;

	case MAP_A7_SAND_MOUNTAIN_LEVEL_2:
		strncpy(lpszBuffer, "Sand Mountain Level 2", dwMaxChars);
		break;

	case MAP_A7_SAND_MOUNTAIN_LEVEL_3:
		strncpy(lpszBuffer, "Sand Mountain Level 3", dwMaxChars);
		break;

	default:
		return 0;
		break;
	}

	return FALSE;
}

INT GetPlayerClassName(INT nClass, LPSTR szBuffer, DWORD dwMaxLen)
{
	switch(nClass)
	{
	case 0:
		sprintf(szBuffer, "Amazon");
		break;
	case 1:
		sprintf(szBuffer, "Sorceress");
		break;
	case 2:
		sprintf(szBuffer, "Necromancer");
		break;
	case 3:
		sprintf(szBuffer, "Paladin");
		break;
	case 4:
		sprintf(szBuffer, "Barbarian");
		break;
	case 5:
		sprintf(szBuffer, "Druid");
		break;
	case 6:
		sprintf(szBuffer, "Assassin");
		break;
	}

	return (INT)strlen(szBuffer);
}

INT GetPlayerClassNameShort(INT nClass, LPSTR szBuffer, DWORD dwMaxLen)
{
	switch(nClass)
	{
	case 0:
		sprintf(szBuffer, "Ama");
		break;
	case 1:
		sprintf(szBuffer, "Sor");
		break;
	case 2:
		sprintf(szBuffer, "Nec");
		break;
	case 3:
		sprintf(szBuffer, "Pal");
		break;
	case 4:
		sprintf(szBuffer, "Bar");
		break;
	case 5:
		sprintf(szBuffer, "Dru");
		break;
	case 6:
		sprintf(szBuffer, "Asn");
		break;
	}

	return (INT)strlen(szBuffer);
}

LPSTR GetShrinesFolder(LPSTR dest, CHAR ch)
{
	GetModuleFileNameA(V_DLL, dest, MAX_PATH);
	PathRemoveFileSpecA(dest);
	strcat(dest, "\\Interface\\Shrines\\");
	return strrchr(dest, ch) + 1;
}

DWORD GetTextFileNo(WCHAR * str)
{
	DWORD width, fileno;
	D2WIN_GetTextWidthFileNo(str, &width, &fileno);
	return fileno;
}

DWORD GetTextWidth(WCHAR * str)
{
	DWORD width, fileno;
	D2WIN_GetTextWidthFileNo(str, &width, &fileno);
	return width;
}

BOOL HostilePlayer(DWORD dwUnitId)
{
	if (!ClientReady(TRUE))
		return FALSE;

	DWORD dwFlags = GetPvPFlags(dwUnitId);

	if (dwFlags & PVP_HOSTILED_BY_YOU || dwFlags & PVP_HOSTILED_YOU)
		return FALSE;

	if (!FindPartyById(dwUnitId))
		return FALSE;

	LPBYTE Packet = new BYTE[7];
	Packet[0] = 0x5D;
	*(LPWORD)&Packet[1] = 0x104;
	*(LPDWORD)&Packet[3] = dwUnitId;
	D2NET_SendPacket(7, 1, Packet);
	delete [] Packet;
	return TRUE;
}

LPCELLFILE InitCellFile(LPCELLFILE File)
{
	if (File) D2CMP_InitCellFile(File, &File, "?", 0, -1, "?");
	return File;
}

BOOL Interact(DWORD ID, DWORD Type, BOOL Check)
{
	if (!ClientReady(TRUE))
		return FALSE;

	if (Check && !GetUnit(ID, Type))
		return FALSE;

	LPBYTE Packet = new BYTE[9];
	Packet[0] = 0x13;
	*(LPDWORD)&Packet[1] = Type;
	*(LPDWORD)&Packet[5] = ID;
	D2NET_SendPacket(9, 1, Packet);
	delete [] Packet;
	return TRUE;
}

LPCELLFILE LoadBMPCellFile(BYTE * Buffer, INT Width, INT Height)
{
	/*BYTE *buf2 = new BYTE[(Width*Height*2)+Height], *dest = buf2;

	for (int i = 0; i < Height; i++) {
		BYTE *src = Buffer+(i*((Width+3)&-4)), *limit = src+Width;
		while (src < limit) {
			BYTE *start = src, *limit2 = min(limit, src+0x7f), trans = !*src;
			do src++; while ((trans == (BYTE)!*src) && (src < limit2));
			if (!trans || (src < limit)) *dest++ = (trans?0x80:0)+(src-start);
			if (!trans) while (start < src) *dest++ = *start++;
		}
		*dest++ = 0x80;
	}

	static DWORD dc6head[] = {6, 1, 0, 0xeeeeeeee, 1, 1, 0x1c,  0, -1, -1, 0, 0, 0, -1, -1};
	dc6head[8] = Width;
	dc6head[9] = Height;
	BYTE *ret = new BYTE[dc6head[13] = sizeof(dc6head)+(dc6head[14] = dest-buf2)+3];
	memset(memcpy2(memcpy2(ret, dc6head, sizeof(dc6head)), buf2, dc6head[14]), 0xee, 3);
	delete buf2;

	return (CellFile *)ret;*/
	BYTE * Buffer2 = new BYTE[(Width * Height * 2) + Height], *Destination = Buffer2;

	for (INT i = 0; i < Height; i++)
	{
		BYTE * Source = Buffer + (i * ((Width + 3) & -4)), *Limit = Source + Width;
		
		while (Source < Limit)
		{
			BYTE * Start = Source, *Limit2 = min(Limit, Source + 0x7F), Transparency = !*Source;
			do Source++; while ((Transparency == (BYTE)!*Source) && (Source < Limit2));

			if (!Transparency || (Source < Limit)) *Destination++ = (BYTE)((Transparency ? 0x80 : 0) + (Source - Start));
			if (!Transparency) while (Start < Source) *Destination++ = *Start++;
		}
		
		*Destination++ = 0x80;
	}

	DWORD DC6[] = {6, 1, 0, 0xEEEEEEEE, 1, 1, 0x1C,  0, -1, -1, 0, 0, 0, -1, -1};
	DC6[8] = Width;
	DC6[9] = Height;

	BYTE * Return = new BYTE[DC6[13] = sizeof(DC6) + (DC6[14] = (DWORD)(Destination - Buffer2)) + 3];
	memset(memcpy2(memcpy2(Return, DC6, sizeof(DC6)), Buffer2, DC6[14]), 0xEE, 3);
	delete Buffer2;

	return (LPCELLFILE)Return;
}

LPCELLFILE LoadBMPCellFile(LPSTR FileName)
{
	/*BYTE *ret = 0;
		
	BYTE *buf1 = AllocReadFile(FileName);
	BITMAPFILEHEADER *bmphead1 = (BITMAPFILEHEADER *)buf1;
	BITMAPINFOHEADER *bmphead2 = (BITMAPINFOHEADER *)(buf1+sizeof(BITMAPFILEHEADER));
	if (buf1 && (bmphead1->bfType == 'MB') && (bmphead2->biBitCount == 8) && (bmphead2->biCompression == BI_RGB)) {
		ret = (BYTE *)LoadBMPCellFile(buf1+bmphead1->bfOffBits, bmphead2->biWidth, bmphead2->biHeight);
	}
	delete buf1;

	return (CellFile *)ret;*/
	LPBYTE Return = 0;
	LPBYTE Buffer = AllocReadFile(FileName);
	
	BITMAPFILEHEADER * BMP1 = (BITMAPFILEHEADER *)Buffer;
	BITMAPINFOHEADER * BMP2 = (BITMAPINFOHEADER *)(Buffer + sizeof(BITMAPFILEHEADER));
	
	if (Buffer && (BMP1->bfType == 'MB') && (BMP2->biBitCount == 8) && (BMP2->biCompression == BI_RGB))
		Return = (LPBYTE)LoadBMPCellFile(Buffer + BMP1->bfOffBits, BMP2->biWidth, BMP2->biHeight);

	delete Buffer;
	return (LPCELLFILE)Return;
}

VOID * memcpy2(LPVOID Destination, CONST VOID * Source, size_t Count)
{
	return (LPSTR)memcpy(Destination, Source, Count) + Count;
}

HANDLE OpenFileRead(LPSTR filename)
{
	return CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

HANDLE OpenFileWrite(LPSTR filename)
{
	return CreateFile(filename, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
}

DWORD ReadFile(HANDLE hFile, LPVOID buf, DWORD len)
{
	DWORD numdone = 0;
	ReadFile(hFile, buf, len, &numdone, NULL);
	return numdone;
}

BOOL RemovePEHeader(HMODULE DLL)
{
	PIMAGE_DOS_HEADER DOSHD = (PIMAGE_DOS_HEADER)(DLL);
	PIMAGE_NT_HEADERS NTHD;	

	if (DOSHD->e_magic == IMAGE_DOS_SIGNATURE)
	{
		NTHD = (PIMAGE_NT_HEADERS)((DWORD)DOSHD + DOSHD->e_lfanew);

		if (NTHD->Signature == IMAGE_NT_SIGNATURE)
		{
			DWORD OldProtect;
			VirtualProtect((LPVOID)NTHD, sizeof(IMAGE_NT_HEADERS), PAGE_READWRITE, &OldProtect);
			::memset(NTHD, NULL, sizeof(IMAGE_NT_HEADERS));

			VirtualProtect((LPVOID)NTHD, sizeof(IMAGE_NT_HEADERS), OldProtect, &OldProtect);
			VirtualProtect((LPVOID)DOSHD, sizeof(IMAGE_DOS_HEADER), PAGE_READWRITE, &OldProtect);

			::memset(DOSHD, NULL, sizeof(IMAGE_DOS_HEADER));
			VirtualProtect((LPVOID)DOSHD, sizeof(IMAGE_DOS_HEADER), OldProtect, &OldProtect);
			return TRUE;
		}
	}
	
	return FALSE;
}

LPSTR ReplaceString(CHAR * Source, CHAR * Old, CHAR * New)
{
	CHAR * Original = new CHAR[strlen(Source)];
	CHAR * Temporary = new CHAR[500];
	INT OldLength = (INT)strlen(Old);
	INT i, j, k, Location = -1;
	strcpy(Original, Source);
	
	for (i = 0; Source[i] && Location == -1; ++i)
		for (j = i, k = 0; Source[j] == Old[k]; j++, k++)
			if (!Old[k + 1])
				Location = i;
	
	if (Location != -1)
	{
		for (j = 0; j < Location; j++)
			Temporary[j] = Source[j];
		
		for (i = 0; New[i]; i++, j++)
			Temporary[j] = New[i];

		for (k = Location + OldLength; Source[k]; k++, j++)
			Temporary[j] = Source[k];
		
		Temporary[j] = NULL;
		
		for (i = 0; Source[i] = Temporary[i]; i++);
	}
	
	delete Original;
	return Temporary;
}

BOOL ReassignPlayer(LPUNITANY Unit, WORD X, WORD Y)
{
	if (!GetUnit(Unit->dwUnitId, Unit->dwType))
		return FALSE;

	LPBYTE Packet = new BYTE[11];
	Packet[0] = 0x15;
	*(LPDWORD)&Packet[1] = Unit->dwType;
	*(LPDWORD)&Packet[2] = Unit->dwUnitId;
	*(LPWORD)&Packet[6] = X;
	*(LPWORD)&Packet[8] = Y;
	D2NET_ReceivePacket(Packet, 11);
	delete [] Packet;
	return TRUE;
}

BOOL ResynchPlayer(DWORD ID, INT Type)
{
	if (!GetUnit(ID, Type))
		return FALSE;

	LPBYTE Packet = new BYTE[9];
	Packet[0] = 0x4B;
	*(LPDWORD)&Packet[1] = Type;
	*(LPDWORD)&Packet[5] = ID;
	D2NET_SendPacket(9, 1, Packet);
	delete [] Packet;
	return TRUE;
}

VOID SendClick(INT nX, INT nY)
{
	LPARAM lPos = ((SHORT)nY << 16) + (SHORT)nX;
	HWND hD2 = D2GFX_GetHwnd();
	HWND hFg = GetForegroundWindow();
	POINT ptPos;

	GetCursorPos(&ptPos);
	SetForegroundWindow(hD2);
	PostMessage(hD2, WM_MOUSEMOVE, NULL, lPos);
	PostMessage(hD2, WM_LBUTTONDOWN, MK_LBUTTON, lPos);
	PostMessage(hD2, WM_LBUTTONUP, MK_LBUTTON, lPos);
	SetCursorPos(ptPos.x, ptPos.y);
	SetForegroundWindow(hFg);
}

BOOL SpoofTownPortal(BYTE State, BYTE AreaID, DWORD UnitID)
{
	LPBYTE Packet = new BYTE[7];
	Packet[0] = 0x60;
	Packet[1] = State;
	Packet[2] = AreaID;
	*(LPDWORD)&Packet[3] = UnitID;
	D2NET_ReceivePacket(Packet, 7);
	delete [] Packet;
	return TRUE;
}

INT StringTokenize(CHAR * Input, CHAR Separator, LPSTR * TokenBuffer, INT MaxTokens)
{
	CHAR * P = Input;
	INT i = 0;
	
	do
	{
		TokenBuffer[i] = P;
		P = strchr(P, Separator);
		
		if (P)
			*(P++) = 0;
	}
	
	while (P && ++i < MaxTokens);
	return ++i;
}

BOOL ValidHostileMonsters(LPUNITANY Unit)
{
	if (!Unit)
		return FALSE;

	if (Unit->dwMode == NPC_MODE_DEATH || Unit->dwMode == NPC_MODE_DEAD)
		return FALSE;

	if (Unit->dwTxtFileNo >= 110 && Unit->dwTxtFileNo <= 113 || Unit->dwTxtFileNo == 608 && Unit->dwMode == NPC_MODE_USESKILL1)
		return FALSE;
	
	if (Unit->dwTxtFileNo == 68 && Unit->dwMode == NPC_MODE_SEQUENCE)
		return FALSE;

	if ((Unit->dwTxtFileNo == 258 || Unit->dwTxtFileNo == 261) && Unit->dwMode == NPC_MODE_SEQUENCE)
		return FALSE;

	if ((Unit->dwTxtFileNo == 356 || Unit->dwTxtFileNo == 357 || Unit->dwTxtFileNo == 424 || Unit->dwTxtFileNo == 425 ||
		Unit->dwTxtFileNo == 418 || Unit->dwTxtFileNo == 419 || Unit->dwTxtFileNo == 421))
		return FALSE;
	
	DWORD Bad[] =
	{
		146, 147, 148, 150, 154, 155, 175, 176, 177, 178, 198, 199, 200, 201, 202, 210, 244, 245, 246, 251, 252, 253, 254, 255, 257, 264,
		265, 266, 270, 283, 297, 326, 327, 328, 329, 330, 331, 338, 351, 352, 353, 359, 366, 367, 405, 406, 408, 410, 411, 412, 413, 414,
		415, 416, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 528, 535, 542, 543, 812
	};

	for (DWORD i = 0; i < ArraySize(Bad) - 1; i++)
		if (Unit->dwTxtFileNo == Bad[i])
			return FALSE;

	WCHAR * Name1 = (WCHAR *)GetUnitName(Unit);
	CHAR MonsterName[50];

	WideCharToMultiByte(CP_ACP, 0, Name1, -1, MonsterName, (INT)sizeof(MonsterName), 0, 0);

	if ((strcmp(MonsterName, "an evil force") == 0) || (strcmp(MonsterName, "dummy") == 0))
		return FALSE;

	return TRUE;
}

BOOL ValidMonsters(LPUNITANY Unit)
{
	if (!Unit)
		return FALSE;

	if (Unit->dwMode == NPC_MODE_DEATH || Unit->dwMode == NPC_MODE_DEAD)
		return FALSE;
	
	if (Unit->dwTxtFileNo == 68 && Unit->dwMode == NPC_MODE_SEQUENCE)
		return FALSE;

	if ((Unit->dwTxtFileNo == 258 || Unit->dwTxtFileNo == 261) && Unit->dwMode == NPC_MODE_SEQUENCE)
		return FALSE;

	if ((Unit->dwTxtFileNo == 356 || Unit->dwTxtFileNo == 357 || Unit->dwTxtFileNo == 424 || Unit->dwTxtFileNo == 425 ||
		Unit->dwTxtFileNo == 418 || Unit->dwTxtFileNo == 419 || Unit->dwTxtFileNo == 421) && Unit->dwOwnerId == Me->dwUnitId)
		return FALSE;

	if (Unit->dwTxtFileNo == 812)
		return FALSE;
	
	DWORD Bad[] =
	{
		146, 147, 148, 150, 154, 155, 175, 176, 177, 178, 198, 199, 200, 201, 202, 210, 244, 245, 246, 251, 252, 253, 254, 255, 257, 264,
		265, 266, 270, 283, 297, 326, 327, 328, 329, 330, 331, 338, 351, 352, 353, 359, 366, 367, 405, 406, 408, 410, 411, 412, 413, 414,
		415, 416, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 528, 535, 542, 543
	};

	for (DWORD i = 0; i < ArraySize(Bad) - 1; i++)
		if (Unit->dwTxtFileNo == Bad[i])
			return FALSE;

	WCHAR * Name = (WCHAR *)GetUnitName(Unit);
	CHAR MonsterName[50];

	WideCharToMultiByte(CP_ACP, 0, Name, -1, MonsterName, (INT)sizeof(MonsterName), 0, 0);

	if (!strcmp(MonsterName, "an evil force") || !strcmp(MonsterName, "dummy"))
		return FALSE;

	return TRUE;
}

VOID wcscpy(WCHAR * dest, CHAR * src)
{
	do *dest++ = *src;
	while (*src++);
}

WCHAR * wcsrcat(WCHAR * dest, WCHAR * src)
{
	memmove(dest + wcslen(src), dest, (wcslen(dest) + 1) * sizeof(WCHAR));
	memcpy(dest, src, wcslen(src) * sizeof(WCHAR));
	return dest;
}

WCHAR * FUNCCALL wsprintfW2(WCHAR * dest, LPSTR fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	INT len = wvsprintf((LPSTR)dest, fmt, va);

	for (INT i = len; i >= 0; i--)
		dest[i] = ((LPSTR)dest)[i];

	return dest;
}

WCHAR * FUNCCALL wsprintfW2Colour(WCHAR * dest, INT col, LPSTR fmt, ...)
{
	/*
	dest[0] = 0xff;
	dest[1] = 'c';
	dest[2] = '0'+(int)col;
	dest += 3;
	*/

	va_list va;
	va_start(va, fmt);

	INT len = wvsprintf((LPSTR)dest, fmt, va);

	for (INT i = len; i >= 0; i--)
		dest[i] = ((LPSTR)dest)[i];

	return dest;
}

DWORD WriteFile(HANDLE hFile, LPVOID buf, DWORD len)
{
	DWORD numdone = 0;
	WriteFile(hFile, buf, len, &numdone, NULL);
	return numdone;
}

wchar_t* AnsiToUnicode(const char* str)
{
	wchar_t* buf = NULL;
	int len = MultiByteToWideChar(CP_ACP, 0, str, -1, buf, 0);
	buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, str, -1, buf, len);
	return buf;
}

char* UnicodeToAnsi(const wchar_t* str)
{
	char* buf = NULL;
	int len = WideCharToMultiByte(CP_ACP, 0, str, -1, buf, 0, "?", NULL);
	buf = new char[len];
	WideCharToMultiByte(CP_ACP, 0, str, -1, buf, len, "?", NULL);
	return buf;
}

CHAR StrToChar(std::string str)
{
	CHAR Result[256];

	std::vector<char> v(str.length() + 1);
	std::strcpy(&v[0], str.c_str());
	char* fp = &v[0];

	strncpy_s(Result, sizeof(Result), V_FileNamePath, sizeof(Result));
	strcat_s(Result, fp);

	return (CHAR)Result;
}

//D2BS stuff
OOG_Location OOG_GetLocation(void)
{
	if (ClientState() != ClientStateMenu)
		return OOG_NONE;

	if (findControl(CONTROL_BUTTON, 5103, -1, 330, 416, 128, 35))
		return OOG_MAIN_MENU_CONNECTING;					//21 Connecting to Battle.net	
	else if (findControl(CONTROL_BUTTON, 5102, -1, 335, 412, 128, 35))
		return OOG_LOGIN_ERROR;								//10 Login Error	
	else if (findControl(CONTROL_BUTTON, 5102, -1, 351, 337, 96, 32))	//5102 =OK
	{
		if (findControl(CONTROL_TEXTBOX, 5351, -1, 268, 320, 264, 120))
			return OOG_LOST_CONNECTION;						//17 lost connection	
		else if (findControl(CONTROL_TEXTBOX, 5347, -1, 268, 320, 264, 120))
			return OOG_DISCONNECTED;						//14  Disconnected
		else
			return OOG_CHARACTER_CREATE_ALREADY_EXISTS;		//30 Character Create - Dupe Name									
	}
	else if (findControl(CONTROL_BUTTON, 5103, -1, 351, 337, 96, 32))		//5103 = CANCEL
	{
		if (findControl(CONTROL_TEXTBOX, 5243, -1, 268, 300, 264, 100))
			return OOG_CHARACTER_SELECT_PLEASE_WAIT;		//16 char select please wait...
		if (findControl(CONTROL_TEXTBOX, (char *)NULL, -1, 268, 320, 264, 120))
			return OOG_PLEASE_WAIT;							//25 "Please Wait..."single player already exists also
	}
	else if (findControl(CONTROL_BUTTON, 5103, -1, 433, 433, 96, 32))
	{
		if (findControl(CONTROL_TEXTBOX, (char *)NULL, -1, 427, 234, 300, 100))
			return OOG_INLINE;								//2 waiting in line	
		else if (findControl(CONTROL_TEXTBOX, 10018, -1, 459, 380, 150, 12))
			return OOG_CREATE;								//4 Create game
		else if (findControl(CONTROL_BUTTON, 5119, -1, 594, 433, 172, 32))
			return OOG_JOIN;								// 5 Join Game
		else if (findControl(CONTROL_BUTTON, 5102, -1, 671, 433, 96, 32))
			return OOG_CHANNEL;								//7 "Channel List"
		else
			return OOG_LADDER;								//6 "Ladder"		
	}
	else if (findControl(CONTROL_BUTTON, 5101, -1, 33, 572, 128, 35))		//5101 = EXIT
	{
		if (findControl(CONTROL_BUTTON, 5288, -1, 264, 484, 272, 35))
			return OOG_LOGIN;								//9 Login
		if (findControl(CONTROL_BUTTON, 5102, -1, 495, 438, 96, 32))
			return OOG_CHARACTER_SELECT_CHANGE_REALM;		//43 char select change realm						
		if (findControl(CONTROL_BUTTON, 5102, -1, 627, 572, 128, 35) && findControl(CONTROL_BUTTON, 10832, -1, 33, 528, 168, 60)) //10832=create new
		{
			if (findControl(CONTROL_BUTTON, 10018, -1, 264, 297, 272, 35)) //NORMAL
				return OOG_DIFFICULTY;						//20 single char Difficulty
			LPCONTROLII pControl = findControl(CONTROL_TEXTBOX, (char *)NULL, -1, 37, 178, 200, 92);
			if (pControl && pControl->pFirstText && pControl->pFirstText->pNext)
				return OOG_CHAR_SELECT;						//12 char select
			else
			{
				if (findControl(CONTROL_TEXTBOX, 11162, -1, 45, 318, 531, 140) || findControl(CONTROL_TEXTBOX, 11066, -1, 45, 318, 531, 140))
					return OOG_REALM_DOWN;
				// Look for CONNECTING... string
				else if (findControl(CONTROL_TEXTBOX, 11065, -1, 0x2D, 0x13E, 0x213, 0x8C))
					return OOG_CONNECTING;
				else
					return OOG_CHARACTER_SELECT_NO_CHARS;	//42 char info not loaded 
			}
		}
		if (findControl(CONTROL_BUTTON, 5101, -1, 33, 572, 128, 35))		//5101=Exit
		{
			if (findControl(CONTROL_BUTTON, 5102, 0, 627, 572, 128, 35))			//5102=ok
				return OOG_CHARACTER_CREATE;				//29 char create screen with char selected
			else
			{
				if (findControl(CONTROL_TEXTBOX, 5226, -1, 321, 448, 300, 32))
					return OOG_NEW_ACCOUNT;					//32 create new bnet account
				else
					return OOG_NEW_CHARACTER;				//15 char create screen no char selected
			}
		}
	}
	if (findControl(CONTROL_BUTTON, 5102, -1, 335, 450, 128, 35))
	{
		if (findControl(CONTROL_TEXTBOX, 5200, -1, 162, 270, 477, 50))
			return OOG_CDKEY_IN_USE;						//19 CD-KEY in use
		else if (findControl(CONTROL_TEXTBOX, 5190, -1, 162, 420, 477, 100))		 //5190="If using a modem"
			return OOG_UNABLE_TO_CONNECT;					//11 unable to connect
		else
			return OOG_INVALID_CDKEY;						//22 invalid CD-KEY 		
	}
	else if (findControl(CONTROL_TEXTBOX, 5159, -1, 438, 300, 326, 150))
		return OOG_GAME_DOES_NOT_EXIST;						//28 game doesn't exist
	else if (findControl(CONTROL_TEXTBOX, 5161, -1, 438, 300, 326, 150))
		return OOG_GAME_IS_FULL;							//38 Game is full
	else if (findControl(CONTROL_TEXTBOX, 5138, -1, 438, 300, 326, 150))
		return OOG_GAME_EXIST;								//26 Game already exists
	else if (findControl(CONTROL_TEXTBOX, 5139, -1, 438, 300, 326, 150))
		return OOG_SERVER_DOWN;								//24 server down	
	else if (findControl(CONTROL_BUTTON, 5106, -1, 264, 324, 272, 35))				//5106="SINGLE PLAYER"
		return OOG_MAIN_MENU;								//8 Main Menu
	else if (findControl(CONTROL_BUTTON, 11126, -1, 27, 480, 120, 20))					//11126=ENTER CHAT
		return OOG_LOBBY;									//1 base bnet 
	else if (findControl(CONTROL_BUTTON, 5308, -1, 187, 470, 80, 20))					//5308="HELP"
		return OOG_CHAT;									//3 chat bnet 
	else if (findControl(CONTROL_TEXTBOX, 21882, -1, 100, 580, 600, 80))
		return OOG_D2SPLASH;								//18 Spash	
	else if (findControl(CONTROL_BUTTON, 5102, -1, 281, 538, 96, 32))
		return OOG_GATEWAY;									//27 select gateway
	else if (findControl(CONTROL_BUTTON, 5181, -1, 525, 513, 128, 35))
		return OOG_AGREE_TO_TERMS;							//31 agree to terms
	else if (findControl(CONTROL_BUTTON, 5102, -1, 525, 513, 128, 35))
		return OOG_PLEASE_READ;								//33 please read
	else if (findControl(CONTROL_BUTTON, 11097, -1, 265, 527, 272, 35))
		return OOG_REGISTER_EMAIL;							//34 register email
	else if (findControl(CONTROL_BUTTON, 5101, -1, 33, 578, 128, 35))
		return OOG_CREDITS;									//35 Credits
	else if (findControl(CONTROL_BUTTON, 5103, -1, 334, 488, 128, 35))
		return OOG_CINEMATICS;								//36 Cinematics
	else if (findControl(CONTROL_BUTTON, 5116, -1, 264, 350, 272, 35))
		return	OOG_OTHER_MULTIPLAYER;						//39 other multi player
	else if (findControl(CONTROL_BUTTON, 5103, -1, 281, 337, 96, 32))
		return OOG_ENTER_IP_ADDRESS;						//41 enter ip	
	else if (findControl(CONTROL_BUTTON, 5118, -1, 265, 206, 272, 35))
		return	OOG_TCP_IP;									//40 tcp-ip

	return OOG_NONE;
}

LPCONTROLII findControl(INT Type, INT LocaleID, INT Disabled, INT PosX, INT PosY, INT SizeX, INT SizeY)
{
	if (ClientState() != ClientStateMenu)
		return NULL;

	char* localeStr = NULL;
	if (LocaleID >= 0)
	{
		localeStr = UnicodeToAnsi(D2LANG_GetLocaleText((WORD)LocaleID));
		if (!localeStr)
			return NULL;
		LPCONTROLII res = findControl(Type, localeStr, Disabled, PosX, PosY, SizeX, SizeY);
		delete[] localeStr;
		return res;
	}

	return NULL;
}

LPCONTROLII findControl(INT Type, char* Text, INT Disabled, INT PosX, INT PosY, INT SizeX, INT SizeY)
{
	if (ClientState() != ClientStateMenu)
		return NULL;

	if (Type == -1 && Text == NULL && Disabled == -1 && PosX == -1 && PosY == -1 && SizeX == -1 && SizeY == -1)
		return *p_D2WIN_FirstControl_II;

	BOOL bFound = FALSE;

	for (LPCONTROLII pControl = *p_D2WIN_FirstControl_II; pControl; pControl = pControl->pNext)
	{
		if (Type >= 0 && static_cast<int>(pControl->dwType) == Type)
			bFound = TRUE;
		else if (Type >= 0 && static_cast<int>(pControl->dwType) != Type)
		{
			bFound = FALSE;
			continue;
		}

		if (Disabled >= 0 && static_cast<int>(pControl->dwDisabled) == Disabled)
		{
			if (pControl->dwType == CONTROL_BUTTON && pControl->unkState == 1)
			{
				bFound = FALSE;
				continue;
			}
			bFound = TRUE;
		}
		else if (Disabled >= 0 && static_cast<int>(pControl->dwDisabled) != Disabled)
		{
			bFound = FALSE;
			continue;
		}

		if (PosX >= 0 && static_cast<int>(pControl->dwPosX) == PosX)
			bFound = TRUE;
		else if (PosX >= 0 && static_cast<int>(pControl->dwPosX) != PosX)
		{
			bFound = FALSE;
			continue;
		}

		if (PosY >= 0 && static_cast<int>(pControl->dwPosY) == PosY)
			bFound = TRUE;
		else if (PosY >= 0 && static_cast<int>(pControl->dwPosY) != PosY)
		{
			bFound = FALSE;
			continue;
		}

		if (SizeX >= 0 && static_cast<int>(pControl->dwSizeX) == SizeX)
			bFound = TRUE;
		else if (SizeX >= 0 && static_cast<int>(pControl->dwSizeX) != SizeX)
		{
			bFound = FALSE;
			continue;
		}

		if (SizeY >= 0 && static_cast<int>(pControl->dwSizeY) == SizeY)
			bFound = TRUE;
		else if (SizeY >= 0 && static_cast<int>(pControl->dwSizeY) != SizeY)
		{
			bFound = FALSE;
			continue;
		}

		if (Text && pControl->dwType == CONTROL_BUTTON)
		{
			char* text2 = UnicodeToAnsi(pControl->wText2);
			if (!text2)
				return NULL;
			if (strcmp(text2, Text) == 0)
			{
				bFound = TRUE;
				delete[] text2;
			}
			else
			{
				bFound = FALSE;
				delete[] text2;
				continue;
			}
		}

		if (Text && pControl->dwType == CONTROL_TEXTBOX)
		{
			if (pControl->pFirstText != NULL && pControl->pFirstText->wText[0] != NULL)
			{
				char* text2 = UnicodeToAnsi(pControl->pFirstText->wText[0]);
				if (!text2)
					return NULL;
				if (strstr(Text, text2) != 0)
				{
					bFound = TRUE;
					delete[] text2;
				}
				else
				{
					bFound = FALSE;
					delete[] text2;
					continue;
				}
			}
			else
			{
				bFound = FALSE;
				continue;
			}
		}
		if (bFound)
			return pControl;
	}

	return NULL;
}

ClientGameState ClientState(void)
{
	ClientGameState state = ClientStateNull;
	LPUNITANYII player = D2CLIENT_GetPlayerUnit_II();
	LPCONTROLII firstControl = *p_D2WIN_FirstControl_II;

	if (player && !firstControl)
	{
		if (player && player->pUpdateUnit)
		{
			state = ClientStateBusy;
			return state;
		}
		if (player->pInventory &&
			player->pPath &&
			//player->pPath->xPos &&
			player->pPath->pRoom1 &&
			player->pPath->pRoom1->pRoom2 &&
			player->pPath->pRoom1->pRoom2->pLevel &&
			player->pPath->pRoom1->pRoom2->pLevel->dwLevelNo)
			state = ClientStateInGame;
		else
			state = ClientStateBusy;
	}
	else if (!player && firstControl)
		state = ClientStateMenu;
	else if (!player && !firstControl)
		state = ClientStateNull;

	return state;
}

bool isFullscreen(HWND Window)
{
    RECT a, b;
    GetWindowRect(Window, &a);
    GetWindowRect(GetDesktopWindow(), &b);
    return (a.left   == b.left  &&
            a.top    == b.top   &&
            a.right  == b.right &&
            a.bottom == b.bottom);
}

VOID myDrawAutomapCell(LPCELLFILEII cellfile, INT xpos, INT ypos, BYTE col)
{
	if (!cellfile)return;
	jspCellContext ct;
	memset(&ct, 0, sizeof(ct));
	ct.pCellFile = cellfile;

	xpos -= (cellfile->cells[0]->width / 2);
	ypos += (cellfile->cells[0]->height / 2);

	int xpos2 = xpos - cellfile->cells[0]->xoffs, ypos2 = ypos - cellfile->cells[0]->yoffs;
	if ((xpos2 >= D2GetScreenSizeX()) || ((xpos2 + (int)cellfile->cells[0]->width) <= 0) || (ypos2 >= D2GetScreenSizeY()) || ((ypos2 + (int)cellfile->cells[0]->height) <= 0)) return;

	static BYTE coltab[2][256];//, tabno = 0, lastcol = 0;
	if (!coltab[0][1]) for (int k = 0; k < 255; k++) coltab[0][k] = coltab[1][k] = (BYTE)k;
	cellfile->mylastcol = coltab[cellfile->mytabno ^= (col != cellfile->mylastcol)][255] = col;

	D2GFX_DrawAutomapCell_II(&ct, xpos, ypos, (DWORD)-1, 5, coltab[cellfile->mytabno]);
}

LPCELLFILEII LoadBmpCellFileII(BYTE* buf1, INT width, INT height)
{
	BYTE* buf2 = new BYTE[(width * height * 2) + height], * dest = buf2;

	for (int i = 0; i < height; i++) {
		BYTE* src = buf1 + (i * ((width + 3) & -4)), * limit = src + width;
		while (src < limit) {
			BYTE* start = src, * limit2 = min(limit, src + 0x7f), trans = !*src;
			do src++; while ((trans == (BYTE)!*src) && (src < limit2));
			if (!trans || (src < limit)) *dest++ = (BYTE)((trans ? 0x80 : 0) + (src - start));
			if (!trans) while (start < src) *dest++ = *start++;
		}
		*dest++ = 0x80;
	}

	static DWORD dc6head[] = { 6, 1, 0, 0xeeeeeeee, 1, 1, 0x1c, 0, (DWORD)-1, (DWORD)-1, 0, 0, 0, (DWORD)-1, (DWORD)-1 };
	dc6head[8] = width;
	dc6head[9] = height;
	dc6head[14] = dest - buf2;
	dc6head[13] = sizeof(dc6head) + (dc6head[14]) + 3;
	BYTE* ret = new BYTE[dc6head[13]];
	memset(memcpy2(memcpy2(ret, dc6head, sizeof(dc6head)), buf2, dc6head[14]), 0xee, 3);
	delete[] buf2;

	return (LPCELLFILEII)ret;
}

LPCELLFILEII LoadBmpCellFileII(char* filename)
{
	BYTE* ret = 0;

	BYTE* buf1 = AllocReadFile(filename);
	BITMAPFILEHEADER* bmphead1 = (BITMAPFILEHEADER*)buf1;
	BITMAPINFOHEADER* bmphead2 = (BITMAPINFOHEADER*)(buf1 + sizeof(BITMAPFILEHEADER));
	if (buf1 && (bmphead1->bfType == 'MB') && (bmphead2->biBitCount == 8) && (bmphead2->biCompression == BI_RGB)) {
		ret = (BYTE*)LoadBmpCellFileII(buf1 + bmphead1->bfOffBits, bmphead2->biWidth, bmphead2->biHeight);
	}
	delete[] buf1;

	return (LPCELLFILEII)ret;
}

LPCELLFILEII myInitCellFile(LPCELLFILEII cf)
{
	if (cf)
		D2CMP_InitCellFile_II(cf, &cf, "?", 0, (DWORD)-1, "?");
	return cf;
}

LPCELLFILEII LoadCellFile(char* lpszPath, DWORD bMPQ)
{
	// AutoDetect the Cell File
	if (bMPQ == 3)
	{
		// Check in our directory first
		char path[_MAX_FNAME + _MAX_PATH];
		sprintf_s(path, sizeof(path), lpszPath);


		HANDLE hFile = OpenFileRead(path);

		if (hFile != INVALID_HANDLE_VALUE)
		{
			CloseHandle(hFile);
			return LoadCellFile(path, FALSE);
		}
		else
		{
			return LoadCellFile(lpszPath, TRUE);
		}

		//return NULL;
	}

	unsigned __int32 hash = sfh(lpszPath, (int)strlen(lpszPath));
	if (mCachedCellFiles.count(hash) > 0)
		return mCachedCellFiles[hash];
	if (bMPQ == TRUE)
	{
		LPCELLFILEII result = (LPCELLFILEII)D2WIN_LoadCellFile(lpszPath, 0);
		mCachedCellFiles[hash] = result;
		return result;
	}
	else if (bMPQ == FALSE)
	{
		// see if the file exists first
		if (!(_access(lpszPath, 0) != 0 && errno == ENOENT))
		{
			LPCELLFILEII result = myInitCellFile((LPCELLFILEII)LoadBmpCellFileII(lpszPath));
			mCachedCellFiles[hash] = result;
			return result;
		}
	}

	return NULL;
}

VOID DrawTag(void)
{
	static char img[_MAX_PATH + _MAX_FNAME] = "";

	string D2ExDir;

	char filename[MAX_PATH];
	GetModuleFileName((HMODULE)V_DLL, filename, MAX_PATH);
	D2ExDir.assign(filename, strrchr(filename, '\\') + 1);

	if (img[0] == '\0')
		sprintf_s(img, sizeof(img), "%sInterface\\mstrtag.bmp", D2ExDir);

	LPCELLFILEII vimg = LoadCellFile(img, FALSE);
	myDrawAutomapCell(vimg, GMTAGX, 526, 0);
}

VOID DrawTag2(void)
{
	static char img[_MAX_PATH + _MAX_FNAME] = "";

	string D2ExDir;

	char filename[MAX_PATH];
	GetModuleFileName((HMODULE)V_DLL, filename, MAX_PATH);
	D2ExDir.assign(filename, strrchr(filename, '\\') + 1);

	if (img[0] == '\0')
		sprintf_s(img, sizeof(img), "%sInterface\\mstrchr.bmp", D2ExDir);

	LPCELLFILEII vimg = LoadCellFile(img, FALSE);

#ifndef LAZARUSMOD
	myDrawAutomapCell(vimg, GMTAGX2, 79, 0);
#else
	myDrawAutomapCell(vimg, (GMTAGX2 - 80), (79 - 60), 0);
#endif
}

POINT GetScreenSize()
{
	// HACK: p_D2CLIENT_ScreenSize is wrong for out of game, which is hardcoded to 800x600
	POINT ingame = { *p_D2CLIENT_ScreenSizeX, *p_D2CLIENT_ScreenSizeY },
		oog = { 800, 600 },
		p = { 0 };
	if (ClientState() == ClientStateMenu) p = oog;
	else p = ingame;
	return p;
}

INT D2GetScreenSizeX()
{
	return GetScreenSize().x;
}

INT D2GetScreenSizeY()
{
	return GetScreenSize().y;
}

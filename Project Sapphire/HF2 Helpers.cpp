#include "Hack.h"

static BOOL COUNTED = FALSE;

BOOL ValidCounterMonsters(LPUNITANY Unit)
{
	if (!Unit)
		return FALSE;

	if (Unit->dwMode == NPC_MODE_DEATH || Unit->dwMode == NPC_MODE_DEAD)
		return FALSE;

	/*
	if (Unit->dwTxtFileNo >= 110 && Unit->dwTxtFileNo <= 113 || Unit->dwTxtFileNo == 608 && Unit->dwMode == NPC_MODE_USESKILL1)
	return FALSE;

	if (Unit->dwTxtFileNo == 68 && Unit->dwMode == NPC_MODE_SEQUENCE)
	return FALSE;

	if ((Unit->dwTxtFileNo == 258 || Unit->dwTxtFileNo == 261) && Unit->dwMode == NPC_MODE_SEQUENCE)
	return FALSE;
	*/

	if ((Unit->dwTxtFileNo == 356 || Unit->dwTxtFileNo == 357 || Unit->dwTxtFileNo == 424 || Unit->dwTxtFileNo == 425 ||
		Unit->dwTxtFileNo == 418 || Unit->dwTxtFileNo == 419 || Unit->dwTxtFileNo == 421))
		return FALSE;

	DWORD Bad[] =
	{
		146, 147, 148, 150, 154, 155, 175, 176, 177, 178, 198, 199, 200, 201, 202, 210, 244, 245, 246, 251, 252, 253, 254, 255, 257, 264,
		265, 266, 270, 283, 297, 326, 327, 328, 329, 330, 331, 338, 351, 352, 353, 359, 366, 367, 368, 405, 406, 408, 410, 411, 412, 413, 414,
		415, 416, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 535, 543
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

BOOL MonsterCheckType(LPUNITANY Unit, exUnitAny* exUnit)
{
	if (!Unit || !exUnit)
		return FALSE;

	BOOL IncreasePos = FALSE;
	INT Color = -1;


	DWORD Bad[] =  //Monsters with desc strings
	{
		68, 69, 70, 71, 72, 58, 59, 60, 61, 62, 87, 88, 89, 90, 101, 102, 103, 104, 105, 114,
		115, 116, 117, 136, 137, 138, 139, 140, 238, 239, 240, 241, 310, 311, 312, 701, 702, 278,
		279, 280, 281, 282, 662, 663, 664, 645, 646, 647, 650, 651, 667, 668, 669, 670, 673, 674,
		679, 715	  
	};

	for (DWORD i = 0; i < ArraySize(Bad); i++)
	if (Unit->dwTxtFileNo == Bad[i])
		IncreasePos = TRUE;

	if (Unit->pMonsterData->fBoss & 1 && !Unit->pMonsterData->fChamp && Color == -1)
		IncreasePos = TRUE;

	/*
	else if (Unit->pMonsterData->fChamp & 1)
	IncreasePos = TRUE;
	*/

	else if (Unit->pMonsterData->fMinion & 1)
		IncreasePos = TRUE;

	if (exUnit->pMonsterData->pMonStatsTxt->dwFlags.blUndead)
		IncreasePos = TRUE;

	if (exUnit->pMonsterData->pMonStatsTxt->dwFlags.bhUndead)
		IncreasePos = TRUE;

	if (exUnit->pMonsterData->pMonStatsTxt->dwFlags.bDemon)
		IncreasePos = TRUE;

	DWORD Ignore[] =  //Bosses to ignore
	{
		250, 256, 540, 541, 542, 526
	};

	for (DWORD i = 0; i < ArraySize(Ignore); i++)
	{
		if (Unit->dwTxtFileNo == Ignore[i])
		{
			if (D2CLIENT_GetDifficulty() == 0 || (D2CLIENT_GetDifficulty() >= 1 && Unit->dwTxtFileNo == 250))
			{
				IncreasePos = FALSE;
			}
			if (D2CLIENT_GetDifficulty() == 0 || (D2CLIENT_GetDifficulty() >= 1 && Unit->dwTxtFileNo == 256))
			{
				IncreasePos = FALSE;
			}
		}
	}

	if (IncreasePos == TRUE)
		V_CounterPosition += 1;

	return TRUE;
}

BOOL MonsterCheckResistance(LPUNITANY Unit)
{
	if (!Unit)
		return FALSE;

	BOOL IncreasePos = FALSE;

	if ((INT)GetUnitStat(Unit, STAT_FIRERESIST) >= 100)
		IncreasePos = TRUE;

	if ((INT)GetUnitStat(Unit, STAT_COLDRESIST) >= 100)
		IncreasePos = TRUE;

	if ((INT)GetUnitStat(Unit, STAT_LIGHTNINGRESIST) >= 100)
		IncreasePos = TRUE;

	if ((INT)GetUnitStat(Unit, STAT_POISONRESIST) >= 100)
		IncreasePos = TRUE;

	if ((INT)GetUnitStat(Unit, STAT_DAMAGERESIST) >= 100)
		IncreasePos = TRUE;

	if ((INT)GetUnitStat(Unit, STAT_MAGICRESIST) >= 100)
		IncreasePos = TRUE;

	if (IncreasePos == TRUE)
		V_CounterPosition += 1;

	return TRUE;
}

BOOL CountGame()
{
	if (V_NewCharacter && V_Difficulty == 0 && !V_NormalWon)
		V_NewCharacter = FALSE;

	else if (V_NewCharacter && V_Difficulty == 1 && !V_NMWon)
		V_NewCharacter = FALSE;

	else if (V_NewCharacter && V_Difficulty == 2 && !V_HellWon)
		V_NewCharacter = FALSE;

	if (V_Difficulty == 0)
		V_Games0++;

	else if (V_Difficulty == 1)
		V_Games1++;

	else if (V_Difficulty == 2)
		V_Games2++;

	if (!V_GameLost)
	{
		if (V_GameWon)
		{
			V_GamesWon++;

			return TRUE;
		}
		if (V_GameDraw)
		{
			V_GamesDraw++;

			return TRUE;
		}
	}
	V_GamesLost++;

	return FALSE;
}

VOID EventGetTime(INT Type)
{
	if (Type == 0)
	{
		//Print(0, 4, "Questÿc0: ÿc4Andariel");
		if (V_BestAndyHour == 0 && V_BestAndyMin == 0 && V_BestAndySec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 0)
			{
				V_BestAndyHour = V_ClockHours;
				V_BestAndyMin = V_ClockMinutes;
				V_BestAndySec = V_ClockSeconds;
			}
		}
		if (V_BestAndyNMHour == 0 && V_BestAndyNMMin == 0 && V_BestAndyNMSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 1)
			{
				V_BestAndyNMHour = V_ClockHours;
				V_BestAndyNMMin = V_ClockMinutes;
				V_BestAndyNMSec = V_ClockSeconds;
			}
		}
		if (V_BestAndyHellHour == 0 && V_BestAndyHellMin == 0 && V_BestAndyHellSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 2)
			{
				V_BestAndyHellHour = V_ClockHours;
				V_BestAndyHellMin = V_ClockMinutes;
				V_BestAndyHellSec = V_ClockSeconds;
			}
		}
		if (!V_GameLost)
		{
			if (!V_GameWon)
			{
				V_GameWon = TRUE;
			}
		}
	}

	if (Type == 1)
	{
		//Print(0, 4, "Questÿc0: ÿc4Duriel");
		if (V_BestDurielHour == 0 && V_BestDurielMin == 0 && V_BestDurielSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 0)
			{
				V_BestDurielHour = V_ClockHours;
				V_BestDurielMin = V_ClockMinutes;
				V_BestDurielSec = V_ClockSeconds;
			}
		}
		if (V_BestDurielNMHour == 0 && V_BestDurielNMMin == 0 && V_BestDurielNMSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 1)
			{
				V_BestDurielNMHour = V_ClockHours;
				V_BestDurielNMMin = V_ClockMinutes;
				V_BestDurielNMSec = V_ClockSeconds;
			}
		}
		if (V_BestDurielHellHour == 0 && V_BestDurielHellMin == 0 && V_BestDurielHellSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 2)
			{
				V_BestDurielHellHour = V_ClockHours;
				V_BestDurielHellMin = V_ClockMinutes;
				V_BestDurielHellSec = V_ClockSeconds;
			}
		}
		if (!V_GameLost)
		{
			if (!V_GameWon)
			{
				V_GameWon = TRUE;
			}
		}
	}

	if (Type == 2)
	{
		//Print(0, 4, "Questÿc0: ÿc4Mephisto");
		if (V_BestMephHour == 0 && V_BestMephMin == 0 && V_BestMephSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 0)
			{
				V_BestMephHour = V_ClockHours;
				V_BestMephMin = V_ClockMinutes;
				V_BestMephSec = V_ClockSeconds;
			}
		}
		if (V_BestMephNMHour == 0 && V_BestMephNMMin == 0 && V_BestMephNMSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 1)
			{
				V_BestMephNMHour = V_ClockHours;
				V_BestMephNMMin = V_ClockMinutes;
				V_BestMephNMSec = V_ClockSeconds;
			}
		}
		if (V_BestMephHellHour == 0 && V_BestMephHellMin == 0 && V_BestMephHellSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 2)
			{
				V_BestMephHellHour = V_ClockHours;
				V_BestMephHellMin = V_ClockMinutes;
				V_BestMephHellSec = V_ClockSeconds;
			}
		}
		if (!V_GameLost)
		{
			if (!V_GameWon)
			{
				V_GameWon = TRUE;
			}
		}
	}

	if (Type == 3)
	{
		//Print(0, 4, "Questÿc0: ÿc4Diablo");
		if (V_BestDiabloHour == 0 && V_BestDiabloMin == 0 && V_BestDiabloSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 0)
			{
				V_BestDiabloHour = V_ClockHours;
				V_BestDiabloMin = V_ClockMinutes;
				V_BestDiabloSec = V_ClockSeconds;
			}
		}
		if (V_BestDiabloNMHour == 0 && V_BestDiabloNMMin == 0 && V_BestDiabloNMSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 1)
			{
				V_BestDiabloNMHour = V_ClockHours;
				V_BestDiabloNMMin = V_ClockMinutes;
				V_BestDiabloNMSec = V_ClockSeconds;
			}
		}
		if (V_BestDiabloHellHour == 0 && V_BestDiabloHellMin == 0 && V_BestDiabloHellSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 2)
			{
				V_BestDiabloHellHour = V_ClockHours;
				V_BestDiabloHellMin = V_ClockMinutes;
				V_BestDiabloHellSec = V_ClockSeconds;
			}
		}
		if (!V_GameLost)
		{
			if (!V_GameWon)
			{
				V_GameWon = TRUE;
			}
		}
	}

	if (Type == 4)
	{
		//Print(0, 4, "Questÿc0: ÿc4Baal");
		if (V_BestBaalHour == 0 && V_BestBaalMin == 0 && V_BestBaalSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 0)
			{
				V_BestBaalHour = V_ClockHours;
				V_BestBaalMin = V_ClockMinutes;
				V_BestBaalSec = V_ClockSeconds;
			}
		}
		if (V_BestBaalNMHour == 0 && V_BestBaalNMMin == 0 && V_BestBaalNMSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 1)
			{
				V_BestBaalNMHour = V_ClockHours;
				V_BestBaalNMMin = V_ClockMinutes;
				V_BestBaalNMSec = V_ClockSeconds;
			}
		}
		if (V_BestBaalHellHour == 0 && V_BestBaalHellMin == 0 && V_BestBaalHellSec == 0)
		{
			if (D2CLIENT_GetDifficulty() == 2)
			{
				V_BestBaalHellHour = V_ClockHours;
				V_BestBaalHellMin = V_ClockMinutes;
				V_BestBaalHellSec = V_ClockSeconds;
			}
		}
		if (!V_GameLost)
		{
			if (!V_GameWon)
			{
				V_GameWon = TRUE;
			}
		}
	}
	//Bonus Areas
	if (Type == 5)
	{
		//Print(0, 4, "Questÿc0: ÿc4X303");
		if (!V_GameLost)
		{
			if (!V_GameWon)
			{
				V_GameWon = TRUE;
			}
		}
	}
	if (Type == 6)
	{
		//Print(0, 4, "Questÿc0: ÿc4Na-Krul");
		if (!V_GameLost)
		{
			if (!V_GameWon)
			{
				V_GameWon = TRUE;
			}
		}
	}
}

BOOL PlayMenuSound(INT Number, INT Reset)
{
	if (Reset == 0)
	{
		if (!V_SoundSelectB[Number - 1])
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_SoundSelectB[Number - 1] = TRUE;
		}
	}
	else if (Reset == 1)
	{
		V_SoundSelectB[Number - 1] = FALSE;
	}

	return TRUE;
}

std::string SingleDigitToString(int iDigit)
{
	std::string szResult;

	long double Digit = iDigit;

	if (iDigit > 9)
	{
		szResult = std::to_string(Digit);
	}
	else
	{
		szResult = "0" + std::to_string(Digit);
	}

	return szResult;
}

void Hf2Log(char* Msg...)
{
	va_list arguments;
	va_start(arguments, Msg);

	int len = _vscprintf(Msg, arguments) + 1;
	char * text = new char[len];
	vsprintf_s(text, len, Msg, arguments);
	va_end(arguments);

	char sTime[9];
	_strtime_s(sTime, 9);
	FILE* plik;
	fopen_s(&plik, "HF2Log.txt", "a");
	if (plik)
	{
		fprintf(plik, "[%s] %s\n", sTime, text);
		fclose(plik);
	}

	delete[] text;
}
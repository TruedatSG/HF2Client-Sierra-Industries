#include "Hack.h"
#include <boost/lexical_cast.hpp>

VOID DeathMessage()
{
	if (ClientReady(FALSE))
	{
		CHAR String[10000], Buffer[10000];
		LPSTR Message[20] = {V_Line1, V_Line2, V_Line3, V_Line4, V_Line5, V_Line6, V_Line7, V_Line8, V_Line9, V_Line10,
			V_Line11, V_Line12, V_Line13, V_Line14, V_Line15, V_Line16, V_Line17, V_Line18, V_Line19, V_Line20};

		for (INT i = 0; i < ArraySize(Message) && i <= 20; i++)
		{
			if (strlen(Message[i]) <= NULL)
				continue;

			if (strcpy(String, Message[i]) && strcpy(Buffer, Message[i]))
			{
				if (strstr(String, "#My Account Name#"))
					strcpy_s(Buffer, ReplaceString(String, "#My Account Name#", D2CLIENT_GetGameInfo()->szAccountName));

				if (strstr(String, "#My Character Name#"))
					strcpy_s(Buffer, ReplaceString(String, "#My Character Name#", D2CLIENT_GetGameInfo()->szCharName));

				if (strstr(String, "#Realm Name#"))
					strcpy_s(Buffer, ReplaceString(String, "#Realm Name#", D2CLIENT_GetGameInfo()->szRealmName));

				if (strstr(String, "#Slain Name#"))
					strcpy_s(Buffer, ReplaceString(String, "#Slain Name#", V_SlainName));

				if (strstr(String, "#Current Song#"))
					strcpy_s(Buffer, ReplaceString(String, "#Current Song#", CurrentSong()));

				if (strstr(String, "#Date#"))
					strcpy_s(Buffer, ReplaceString(String, "#Date#", V_LocalDate));

				if (strstr(String, "#Time#"))
					strcpy_s(Buffer, ReplaceString(String, "#Time#", V_LocalTime));

				if (strstr(String, "#Total Kill Count#"))
					strcpy_s(Buffer, ReplaceString(String, "#Total Kill Count#", V_InjectKills));

				if (strstr(String, "#In-Game Kill Count#"))
					strcpy_s(Buffer, ReplaceString(String, "#In-Game Kill Count#", V_InGameKills));

				if (strstr(String, "#Total Death Count#"))
					strcpy_s(Buffer, ReplaceString(String, "#Total Death Count#", V_InjectDeaths));

				if (strstr(String, "#In-Game Death Count#"))
					strcpy_s(Buffer, ReplaceString(String, "#In-Game Death Count#", V_InGameDeaths));

				if (Say(String))
					SleepEx(V_DeathMessageDelay, TRUE);
			}
		}
	}
}

BOOL FASTCALL Input(WCHAR * Text)
{
	CHAR Buffer[100];
	CHAR Message[100];
	CHAR * Argument[32];

	WideCharToMultiByte(CP_ACP, 0, Text, -1, Buffer, sizeof(Buffer), 0, 0);
	strcpy(Message, Buffer);
	INT Arguments = StringTokenize(Buffer + 1, ' ', Argument, 32);

	if (Buffer[0] == ';')
	{
		if (!_stricmp(Argument[0], "hc"))
		{
			V_HideCommands = !V_HideCommands;
			Print(0, 4, V_HideCommands ? "%s�c0: �c4Commands are hidden" : "%s�c0: �c1Commands aren't hidden", V_Name);
			return FALSE;
		}
	}

	if (V_HideCommands)
		return TRUE;

	if (Buffer[0] == '.')
	{
		if(!V_GMMode)
			return FALSE;

		if (!_stricmp(Argument[0], "0"))
		{
			SYSTEMTIME Time;
			GetLocalTime(&Time);
			sprintf_s(V_LocalDate, "%.2d-%.2d-%.2d", Time.wMonth, Time.wDay, Time.wYear);

			if (Time.wHour < 13 || Time.wHour > 23)
				sprintf_s(V_LocalTime, "%.2d:%.2d:%.2d AM", Time.wHour == 0 ? 12 : Time.wHour, Time.wMinute, Time.wSecond);
			else if (Time.wHour < 24 || Time.wHour > 12)
				sprintf_s(V_LocalTime, "%.2d:%.2d:%.2d PM", Time.wHour == 24 ? 12 : Time.wHour - 12, Time.wMinute, Time.wSecond);

			V_DeathMessageIteration = TRUE;
			return FALSE;
		}

		if (!_stricmp(Argument[0], "aa"))
		{
			V_Aim = !V_Aim;
			Print(0, 4, V_Aim ? "�c4Lazarus�c0: �c4Enabled" : "�c4Lazarus�c0: �c1Disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "af"))
		{
			V_AntiFlash = !V_AntiFlash;
			Print(0, 4, V_AntiFlash ? "Flash�c0: �c4Anti Flash is enabled" : "Flash�c0: �c1Anti Flash is disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "aig"))
		{
			V_AntiItemGlitch = !V_AntiItemGlitch;
			Print(0, 4, V_AntiItemGlitch ? "%s�c0: �c4Anti Flash is enabled" : "%s�c0: �c1Anti Flash is disabled", V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "am"))
		{
			V_AntiMinimize = !V_AntiMinimize;
			Print(0, 4, V_AntiMinimize ? "%s�c0: �c4Anti Minimize is enabled" : "%s�c0: �c1Anti Minimize is disabled", V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "ap"))
		{
			V_AutoParty = !V_AutoParty;
			Print(0, 4, V_AutoParty ? "%s�c0: �c4Auto Party is enabled" : "%s�c0: �c1Auto Party is disabled", V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "aqb"))
		{
			V_AntiQuestBox = !V_AntiQuestBox;
			Print(0, 4, V_AntiQuestBox ? "%s�c0: �c4Anti Quest Box is enabled" : "%s�c0: �c1Anti Quest Box is disabled", V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "as"))
		{
			if (Argument[1])
			{
				ChangeStat(STAT_IAS, (atoi(Argument[1]) < 255) ? atoi(Argument[1]) : 255);
				
				if (atoi(Argument[1]) > 0)
					Print(0, 4, "�c4Lazarus�c0: Increased attack speed by �c3%s%%�c0.", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Decreased attack speed to normal %%");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "bf"))
		{
			V_BlockFakes = !V_BlockFakes;
			Print(0, 4, V_BlockFakes ? "�c4Lazarus�c0: Blocking fake attacks and casts" : "�c4Lazarus�c0: �c1Not blocking fake attacks and casts");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "br"))
		{
			if (Argument[1])
			{
				ChangeStat(STAT_FASTERBLOCK, (atoi(Argument[1]) < 255) ? atoi(Argument[1]) : 255);
				
				if (atoi(Argument[1]) > 0)
					Print(0, 4, "�c4Lazarus�c0: Increased block rate by �c3%s%%", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Decreased block rate to normal %%");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "btp"))
		{
			V_BlockTP = !V_BlockTP;
			Print(0, 4, V_BlockTP ? "�c4Lazarus�c0: Blocking town portal interaction when towned by life/mana %%" : "�c4Lazarus�c0: �c1Not blocking town portal interaction when towned by life/mana %%");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "clean"))
		{
			V_Design->Hide = !V_Design->Hide;
			return FALSE;
		}

		if (!_stricmp(Argument[0], "cr"))
		{
			if (Argument[1])
			{
				ChangeStat(STAT_FASTERCAST, (atoi(Argument[1]) < 255) ? atoi(Argument[1]) : 255);
				
				if (atoi(Argument[1]) > 0)
					Print(0, 4, "�c4Lazarus�c0: Increased cast rate by �c3%s%%", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Decreased cast rate to normal %%");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "cs"))
		{
			if (Argument[1])
			{
				CHAR Temporary[10000];

				if (MaxTime() != INFINITE)
					sprintf_s(Temporary, "/f m �c%s%s%s <%.2d:%.2d:%.2d / %.2d:%.2d:%.2d>", Argument[1], V_CurrentSongPhrase, CurrentSong(), (CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60, (MaxTime() / 3600) % 60, (MaxTime() / 60) % 60, MaxTime() % 60);
				else
					sprintf_s(Temporary, "/f m �c%s%s%s <%.2d:%.2d:%.2d / --:--:-->", Argument[1], V_CurrentSongPhrase, CurrentSong(), (CurrentTime() / 3600000) % 60, (CurrentTime() / 60000) % 60, (CurrentTime() / 1000) % 60);

				BNCLIENT_SendBNMessage(Temporary);
				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "cube"))
		{
			if (!GetUIVar(UI_CUBE))
			{
				BYTE Packet[2];
				Packet[0] = 0x77;
				Packet[1] = 0x15;
				D2NET_ReceivePacket(Packet, 2);
				V_CubeOrStashOpened = TRUE;
			}

			else
			{
				D2CLIENT_SetUIVar(UI_CUBE, 1, 0);
				return FALSE;
			}

			return FALSE;
		}

		if (!_stricmp(Argument[0], "dg"))
		{
			if (GetUnitStat(Me, STAT_GOLD) <= 0)
			{
				Print(0, 4, "%s�c0: �c1No gold found in inventory", V_Name);
				return FALSE;
			}

			if (Argument[1] && GetUnitStat(Me, STAT_GOLD) > 0)
			{
				V_GoldAmount = atoi(Argument[1]);
				V_GoldDrop = !V_GoldDrop;

				if (V_GoldDrop)
					Print(0, 4, "%s�c0: Dropping %s gold", V_Name, Argument[1]);
				else
					Print(0, 4, "%s�c0: �c1Stopped dropping gold", V_Name);

				return FALSE;
			}

			V_GoldDrop = FALSE;
			Print(0, 4, "%s�c0: �c1Stopped dropping gold", V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "dm"))
		{
			V_DeathMessage = !V_DeathMessage;
			Print(0, 4, V_DeathMessage ? "Death �c4Lazarus�c0: �c4Enabled" : "Death �c4Lazarus�c0: �c1Disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "eb"))
		{
			V_Enchant = !V_Enchant;
			Print(0, 4, V_Enchant ? "�c4Lazarus�c0: �c4Enabled" : "�c4Lazarus�c0: �c1Disabled");

			if (V_Enchant && V_EnchantNote)
				V_EnchantNoteIteration = TRUE;
			else if (!V_Enchant && V_EnchantNote)
				Say("%s's Enchant Bot is disabled", V_Name);

			return FALSE;
		}

		if (!_stricmp(Argument[0], "ebn"))
		{
			V_EnchantNote = !V_EnchantNote;
			Print(0, 4, V_EnchantNote ? "�c4Lazarus�c0: �c4Note is enabled" : "�c4Lazarus�c0: �c1Note is disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "el"))
		{
			if (Argument[1])
			{
				V_LifeExitPercent = atoi(Argument[1]);

				if (V_LifeExitPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Escaping out of game at �c1%s%% life", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Escaping out of game at �c1life %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "em"))
		{
			if (Argument[1])
			{
				V_ManaExitPercent = atoi(Argument[1]);

				if (V_ManaExitPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Escaping out of game at �c3%s%% mana", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Escaping out of game at �c3mana %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "fake"))
		{
			if (Argument[2])
			{
				SYSTEMTIME Time;
				GetLocalTime(&Time);
				sprintf_s(V_LocalDate, "%.2d-%.2d-%.2d", Time.wMonth, Time.wDay, Time.wYear);

				if (Time.wHour < 13 || Time.wHour > 23)
					sprintf_s(V_LocalTime, "%.2d:%.2d:%.2d AM", Time.wHour == 0 ? 12 : Time.wHour, Time.wMinute, Time.wSecond);
				else if (Time.wHour < 24 || Time.wHour > 12)
					sprintf_s(V_LocalTime, "%.2d:%.2d:%.2d PM", Time.wHour == 24 ? 12 : Time.wHour - 12, Time.wMinute, Time.wSecond);

				if (Print(0, 4, "%s was slain by %s", Argument[1], Me->pPlayerData->szName))
					Print(0, 4, "%s(%s) left our world. Diablo's minions weaken.", Argument[1], Argument[2]);

				if (V_DeathMessage)
				{
					strcpy(V_SlainName, Argument[1]);
					V_DeathMessageIteration = TRUE;
				}

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "fc"))
		{
			for (INT i = 0; i < V_Players.GetSize(); i++)
			{
				if (V_Players[i]->Flashing)
				{
					V_Players[i]->Flashing = FALSE;
					Print(0, 4, "Flash�c0: �c4Stopped flashing �c1%s", V_Players[i]->PlayerName);
				}
			}

			return FALSE;
		}

		if (!_stricmp(Argument[0], "fd"))
		{
			if (Argument[1])
			{
				V_FlashDelay = atoi(Argument[1]);

				if (V_FlashDelay > 0)
					Print(0, 4, "�c4Lazarus�c0: Delay set to �c3%d milliseconds", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: �c1Disabled");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "fm"))
		{
			if (Argument[2])
			{
				CHAR Temporary[500];
				sprintf_s(Temporary, "/f m �c%s%s", Argument[1], Message + 6);
				BNCLIENT_SendBNMessage(Temporary);
				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "ftp"))
		{
			V_FastTP = !V_FastTP;
			Print(0, 4, V_FastTP ? "�c4Lazarus�c0: �c4Fast Town Portal is enabled" : "�c4Lazarus�c0: �c1Fast Town Portal is disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "hack"))
		{
			if (!GetSkill(D2S_CONFUSE))
				SetSkill(D2S_CONFUSE, FALSE);
			else
				SetSkill(D2S_HOLYSHIELD, FALSE);

			return FALSE;
		}

		if (!_stricmp(Argument[0], "hp"))
		{
			if (Argument[1])
			{
				V_LifePotPercent = atoi(Argument[1]);

				if (V_LifePotPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Drinking health potions at �c1%s%% life", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Drinking health potions at �c1life %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "hr"))
		{
			if (Argument[1])
			{
				ChangeStat(STAT_FASTERHITRECOVERY, (atoi(Argument[1]) < 255) ? atoi(Argument[1]) : 255);
				
				if (atoi(Argument[1]) > 0)
					Print(0, 4, "�c4Lazarus�c0: Increased hit recovery rate by �c3%s%%", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Decreased hit recovery rate to �c1normal %%");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "load"))
		{
			Load();
			Print(0, 4, "%s�c0: �c4Loaded configuration", V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "mh"))
		{
			BOOL Map = V_AutoRevealAutomap;

			if (V_AutoRevealAutomap) V_AutoRevealAutomap = FALSE;
			if (V_Reveal) V_Reveal->RevealAutomap();
			if (!V_AutoRevealAutomap) V_AutoRevealAutomap = Map;

			Print(0, 4, "�c4Lazarus�c0: �c4Revealed Act %d", Me->pAct->dwAct + 1);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "mm"))
		{
			V_MonstersMap = !V_MonstersMap;
			Print(0, 4, V_MonstersMap ? "Lazarus�c0: �c1Showing monsters on map" : "Lazarus�c0: �c1Hiding monsters on map");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "mn"))
		{
			V_MonstersMapExt = !V_MonstersMapExt;
			Print(0, 4, V_MonstersMapExt ? "Lazarus�c0: �c1Showing notorious monsters on map" : "Lazarus�c0: �c1Hiding notorious on map");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "mv"))
		{
			V_VectorsMap = !V_VectorsMap;
			Print(0, 4, V_VectorsMap ? "Lazarus�c0: �c1Showing vectors on map" : "Lazarus�c0: �c1Hiding vectors on map");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "mp"))
		{
			if (Argument[1])
			{
				V_ManaPotPercent = atoi(Argument[1]);

				if (V_ManaPotPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Drinking mana potions at �c3%s%% mana", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Drinking mana potions at �c3mana %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "next"))
		{
			NextSong();
			return FALSE;
		}

		if (!_stricmp(Argument[0], "nl"))
		{
			TeleportToVector(1);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "ots"))
		{
			V_OutTownSelect = !V_OutTownSelect;
			Print(0, 4, V_OutTownSelect ? "%s�c0: �c4Players out of town are selectable" : "%s�c0: �c1Players out of town are unselectable", V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "pause"))
		{
			Pause();
			return FALSE;
		}

		if (!_stricmp(Argument[0], "pl"))
		{
			TeleportToVector(2);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "play"))
		{
			Play();
			return FALSE;
		}

		if (!_stricmp(Argument[0], "prev"))
		{
			PreviousSong();
			return FALSE;
		}

		if (!_stricmp(Argument[0], "qu"))
		{
			TeleportToVector(3);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "rl"))
		{
			if (Argument[1])
			{
				V_LifeJuvPercent = atoi(Argument[1]);

				if (V_LifeJuvPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Drinking rejuvenation potions at �c1%s%% life", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Drinking rejuvenation potions at �c1life %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "rm"))
		{
			if (Argument[1])
			{
				V_ManaJuvPercent = atoi(Argument[1]);

				if (V_ManaJuvPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Drinking rejuvenation potions at �c3%s%% mana", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Drinking rejuvenation potions at �c3mana %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "rw"))
		{
			if (Argument[1])
			{
				ChangeStat(STAT_FASTERRUNWALK, (atoi(Argument[1]) < 255) ? atoi(Argument[1]) : 255);
				
				if (atoi(Argument[1]) > 0)
					Print(0, 4, "�c4Lazarus�c0: Increased run/walk speed by �c3%s%%", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Decreased run/walk speed to normal %%");

				return FALSE;
			}
		}
		if (!_stricmp(Argument[0], "s1"))
		{
			TeleportToVector(5);
			return FALSE;
		}
		if (!_stricmp(Argument[0], "s2"))
		{
			TeleportToVector(6);
			return FALSE;
		}
		if (!_stricmp(Argument[0], "s3"))
		{
			TeleportToVector(7);
			return FALSE;
		}
		if (!_stricmp(Argument[0], "s4"))
		{
			TeleportToVector(8);
			return FALSE;
		}
		if (!_stricmp(Argument[0], "s5"))
		{
			TeleportToVector(9);
			return FALSE;
		}
		if (!_stricmp(Argument[0], "save"))
		{
			Save();
			Print(0, 4, "%s�c0: �c4Saved configuration");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "sp"))
		{
			V_ProtectItemSocket = !V_ProtectItemSocket;
			Print(0, 4, V_ProtectItemSocket ? "�c4Lazarus�c0: �c4Item socket protection enabled" : "�c4Lazarus�c0: �c1Item socket protection disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "ss"))
		{
			V_Screenshot = !V_Screenshot;
			Print(0, 4, V_Screenshot ? "Design�c0: Hide on screenshot enabled" : "Design�c0: �c1Hide on screenshot disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "stash"))
		{
			if (!GetUIVar(UI_STASH))
			{
				BYTE Packet[2];
				Packet[0] = 0x77;
				Packet[1] = 0x10;
				D2NET_ReceivePacket(Packet, 2);
				V_CubeOrStashOpened = TRUE;
			}

			else
			{
				D2CLIENT_SetUIVar(UI_STASH, 1, 0);
				return FALSE;
			}

			return FALSE;
		}

		if (!_stricmp(Argument[0], "stop"))
		{
			Stop();
			return FALSE;
		}
		if (!_stricmp(Argument[0], "t1"))
		{
			if (V_TP) V_TP = FALSE;
			if (!V_TP) Portal();
			return FALSE;
		}
		if (!_stricmp(Argument[0], "t2"))
		{
			if (Portal()) V_TP = TRUE;
			return FALSE;
		}
		if (!_stricmp(Argument[0], "ta"))
		{
			V_TPWhenAttacked = !V_TPWhenAttacked;
			
			if (V_TPWhenAttacked)
				Print(0, 4, "�c4Lazarus�c0: �c4Escaping to town when attacked");
			else
				Print(0, 4, "�c4Lazarus�c0: �c1Escaping to town when attacked is off");

			return FALSE;
		}

		if (!_stricmp(Argument[0], "th"))
		{
			V_TPWhenHostiled = !V_TPWhenHostiled;
			
			if (V_TPWhenHostiled)
				Print(0, 4, "�c4Lazarus�c0: �c4Escaping to town when hostiled");
			else
				Print(0, 4, "�c4Lazarus�c0: �c1Escaping to town when hostiled is off");

			return FALSE;
		}

		if (!_stricmp(Argument[0], "tl"))
		{
			if (Argument[1])
			{
				V_LifeTownPercent = atoi(Argument[1]);

				if (V_LifeTownPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Escaping to town at �c1%s%% life", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: Escaping to town at �c1life %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "tm"))
		{
			if (Argument[1])
			{
				V_ManaTownPercent = atoi(Argument[1]);

				if (V_ManaTownPercent > 0)
					Print(0, 4, "�c4Lazarus�c0: �c4Escaping to town at �c3%s%% mana", Argument[1]);
				else
					Print(0, 4, "�c4Lazarus�c0: �c0Escaping to town at �c3mana %% �c0is off");

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "unload"))
		{
			Detach();
			Print(0, 19, "%s is unloaded, restart Diablo II to reload %s", V_Name, V_Name);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "vbs"))
		{
			V_ViewItemBasicStats = !V_ViewItemBasicStats;
			Print(0, 4, V_ViewItemBasicStats ? "�c4Lazarus�c0: �c4Viewing basic stats of items is enabled" : "�c4Lazarus�c0: �c1Viewing basic stats of items is disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "vs"))
		{
			V_ViewSocketables = !V_ViewSocketables;
			Print(0, 4, V_ViewSocketables ? "�c4Lazarus�c0: �c4Viewing socketables of items is enabled" : "�c4Lazarus�c0: �c1Viewing socketables of items is disabled");
			return FALSE;
		}

		if (!_stricmp(Argument[0], "vp"))
		{
			if (Argument[1])
			{
				ChangeStat(STAT_VELOCITYPERCENT, (atoi(Argument[1]) < 255) ? atoi(Argument[1]) : 255);
				
				if (atoi(Argument[1]) > 100)
					Print(0, 4, "�c4Lazarus�c0: Increased velocity by �c3%s%%", Argument[1]);
				else if (atoi(Argument[1]) == 100)
					Print(0, 4, "�c4Lazarus�c0: Decreased velocity to normal %%");
				else if (atoi(Argument[1]) < 100)
					Print(0, 4, "�c4Lazarus�c0: Decreased velocity by �c3%s%%", Argument[1]);

				return FALSE;
			}
		}

		if (!_stricmp(Argument[0], "wp"))
		{
			TeleportToVector(4);
			return FALSE;
		}

		if (!_stricmp(Argument[0], "dupe"))
		{
			Print(0, 4, "�c4Lazarus�c0: �c1Step 1�c0 - Enter �c2/dupe1�c0 to block packet 0x30.");
			Print(0, 4, "�c4Lazarus�c0: �c1Step 2�c0 - Go near waypoint and enter trade then enter �c2/dupe2�c0.");
			Print(0, 4, "�c4Lazarus�c0: �c1Step 3�c0 - Enter �c2/dupe3�c0 and drop the items then close trade.");

			return FALSE;
		}

		if (!_stricmp(Argument[0], "travel"))
		{
			Print(0, 4, "�c4Lazarus�c0: �c1Go Act 5�c0 - Enter �c2/travel1�c0 to take waypoint to Act 5.");
			Print(0, 4, "�c4Lazarus�c0: �c1Give Act 5�c0 - Enter �c2/travel2�c0 to give Act 5 waypoint.");
			Print(0, 4, "�c4Lazarus�c0: �c1Get Act 5�c0 - Enter �c2/travel3�c0 to get Act 5 waypoint.");

			return FALSE;
		}

		if (!_stricmp(Argument[0], "god"))
		{
			if (V_LegitMode)
			{
				Print(0, 0, "�c1Hack modules not enabled.");
				return FALSE;
			}
			if (Argument[1] != NULL)
			{
				if (!_stricmp(Argument[1], "set"))
				{
					GodmodeSet();

					return FALSE;
				}
				if (!_stricmp(Argument[1], "start"))
				{
					GodmodeStart();

					return FALSE;
				}
				if (!_stricmp(Argument[1], "stop"))
				{
					GodmodeStop();

					return FALSE;
				}
				if (!_stricmp(Argument[1], "heal"))
				{
					GodmodeHeal();

					return FALSE;
				}
				if (!_stricmp(Argument[1], "buy"))
				{
					GodmodeBuy();

					return FALSE;
				}
			}
			Print(0, 0, "�c4Godmode:�c0 Type '�c5?god�c0' for help.");

			return FALSE;
		}
	}

	if (Buffer[0] == '?')
	{
		if (V_GMMode)
		{
			if (!_stricmp(Argument[0], "god"))
			{
				Print(0, 0, "�c4Godmode:�c0 Commands:");
				Print(0, 0, "�c4Godmode:�c0 '�c5set�c0' - Prime module for use");
				Print(0, 0, "�c4Godmode:�c0 '�c5start�c0' - Activate module");
				Print(0, 0, "�c4Godmode:�c0 '�c5stop�c0' - Stop module");
				Print(0, 0, "�c4Godmode:�c0 '�c5heal�c0' - Heal yourself");
				Print(0, 0, "�c4Godmode:�c0 '�c5buy�c0' - Buy health from any NPC");

				return FALSE;
			}
		}

		if (V_GMMode)
		{
			if (!_stricmp(Argument[0], "gmhelp"))
			{
				Print(0, 0, "GM Commands:");
				Print(0, 0, "Enter '�c2.cube�c0' to open cube.");
				Print(0, 0, "Enter '�c2.stash�c0' to open stash.");

				Print(0, 0, "Enter '�c2.as <amount>�c0' to speed up attack speed.");
				Print(0, 0, "Enter '�c2.cr <amount>�c0' to speed up cast rate.");
				Print(0, 0, "Enter '�c2.hr <amount>�c0' to speed up hit recovery rate.");
				Print(0, 0, "Enter '�c2.br <amount>�c0' to speed up block rate.");
				Print(0, 0, "Enter '�c2.rw <amount>�c0' to speed up run/walk percent.");
				Print(0, 0, "Enter '�c2.vp <amount>�c0' to speed up hit velocity percent.");

				Print(0, 0, "Enter '�c2.hp <amount>�c0' to set auto health potion.");
				Print(0, 0, "Enter '�c2.mp <amount>�c0' to set auto mana potion.");
				Print(0, 0, "Enter '�c2.rl <amount>�c0' to set auto life rejuvination potion.");
				Print(0, 0, "Enter '�c2.rm <amount>�c0' to set auto mana rejuvination potion.");
				Print(0, 0, "Enter '�c2.tl <amount>�c0' to set life town threshold.");
				Print(0, 0, "Enter '�c2.tm <amount>�c0' to set mana town threshold.");
				Print(0, 0, "Enter '�c2.el <amount>�c0' to set life exit threshold.");
				Print(0, 0, "Enter '�c2.em <amount>�c0' to set mana exit threshold.");

				Print(0, 0, "Enter '�c2.mh�c0' to reveal map.");
				Print(0, 0, "Enter '�c2.mm�c0' to show monsters on map.");
				Print(0, 0, "Enter '�c2.mn�c0' to show notorious monsters on map.");
				Print(0, 0, "Enter '�c2.mv�c0' to show vectors on map.");
				Print(0, 0, "Enter '�c2.nl�c0' to teleport to next level.");
				Print(0, 0, "Enter '�c2.pl�c0' to teleport to previous level.");
				Print(0, 0, "Enter '�c2.qu�c0' to teleport to quest destination.");
				Print(0, 0, "Enter '�c2.wp�c0' to teleport to waypoint in level.");
				Print(0, 0, "Enter '�c2.ta�c0' to town when attacked.");
				Print(0, 0, "Enter '�c2.th�c0' to town when hostiled.");
				Print(0, 0, "Enter '�c2.ftp�c0' to enable fast town portal.");
				Print(0, 0, "Enter '�c2.btp <amount>�c0' to block town portal when below threshold.");
				Print(0, 0, "Enter '�c2.af�c0' to enable anti-flash.");
				Print(0, 0, "Enter '�c2.sp�c0' to use socket protection.");
				Print(0, 0, "Enter '�c2.dg <amount>�c0' to enable drop gold.");
				Print(0, 0, "Enter '�c2.eb�c0' to enable enchant bot.");
				Print(0, 0, "Enter '�c2.ebm�c0' to enable enchant bot message.");
				Print(0, 0, "Enter '�c2.ots�c0' to select player outside of town.");
				Print(0, 0, "Enter '�c2.hack�c0' unknown skill hack.");
				Print(0, 0, "Enter '�c2.dupe�c0' for instructions on how to dupe.");
				Print(0, 0, "Enter '�c2.travel�c0' for travel information.");
				Print(0, 0, "Enter '�c2.god�c0' for godmode information.");
				

				return FALSE;
			}
		}
		if (!_stricmp(Argument[0], "help"))
		{
			Print(0, 0, "Commands:");
			Print(0, 0, "Enter '�c2@id <user id number>�c0' to start activation.");
			Print(0, 0, "Enter '�c2/players <number of players>�c0' to change monster difficulty.");
			Print(0, 0, "Enter '�c2/timeinfo�c0' to view date/time information.");
			Print(0, 0, "Enter '�c2/playerinfo�c0' to view player information.");
			Print(0, 0, "Enter '�c2/travelinfo�c0' to view travel information.");
			Print(0, 0, "Enter '�c2/ladderinfo�c0' to view ladder information.");
			Print(0, 0, "Enter '�c2/saveladder�c0' to save the guild ladder.");
			Print(0, 0, "Enter '�c2/resetladder�c0' to reset the guild ladder.");
			Print(0, 0, "Enter '�c2/setnote�c0' to set a player note.");
			Print(0, 0, "Enter '�c2/deletenote�c0' to remove player note.");
#ifndef FFXIVMOD
			Print(0, 0, "Enter '�c2/mpmode <on or off>�c0' to toggle multiplayer mode.");
#endif
#ifndef LAZARUSMOD
			Print(0, 0, "Enter '�c2/resetkeyitems�c0' to reset key items.");
#endif

			return FALSE;
		}
		if (!_stricmp(Argument[0], "date"))
		{
			if (Say("?%s", Argument[0]))
			{
				CHAR LocalTime[50];
				SYSTEMTIME Time;
				GetLocalTime(&Time);
				
				sprintf_s(LocalTime, "%.2d-%.2d-%.2d", Time.wMonth, Time.wDay, Time.wYear);
				Say(LocalTime);
			}

			return FALSE;
		}

		if (!_stricmp(Argument[0], "ping"))
		{
			if (Say("?%s", Argument[0]))
				Say("Current FPS: %d, Skip: %d, Ping: %d", *p_D2CLIENT_FPS, *p_D2CLIENT_Skip, *p_D2CLIENT_Ping);

			return FALSE;
		}

		if (!_stricmp(Argument[0], "score"))
		{
			if (Say("?%s", Argument[0]))
				Say("Global kills: %i, Global Deaths: %i, Kills in this game: %i, Deaths in this game: %i",
				V_InjectKillCount, V_InjectDeathCount, V_InGameKillCount, V_InGameDeathCount);

			return FALSE;
		}

		if (!_stricmp(Argument[0], "time"))
		{
			if (Say("?%s", Argument[0]))
			{
				CHAR LocalTime[50];
				SYSTEMTIME Time;
				GetLocalTime(&Time);

				if (Time.wHour < 13 || Time.wHour > 23 && strlen(LocalTime) <= 0)
					sprintf_s(LocalTime, "%.2d:%.2d:%.2d AM", Time.wHour == 0 ? 12 : Time.wHour, Time.wMinute, Time.wSecond);
				else if (Time.wHour < 24 || Time.wHour > 12 && strlen(LocalTime) <= 0)
					sprintf_s(LocalTime, "%.2d:%.2d:%.2d PM", Time.wHour == 24 ? 12 : Time.wHour - 12, Time.wMinute, Time.wSecond);

				Say(LocalTime);
			}

			return FALSE;
		}
	}

	if(Buffer[0] == '/')
	{
		if (!_stricmp(Argument[0], "timeinfo"))
		{
			ResetInfoText();

			INT ClockDoBHour = V_ClockDoBHour;
			INT ClockLastHour = V_ClockLastHour;

			V_DoBTimeOfDay = "AM";
			V_LastTimeOfDay = "AM";

			if (V_ClockDoBHour >= 13 && V_ClockDoBHour <= 24)
			{
				ClockDoBHour = V_ClockDoBHour - 12;

				V_DoBTimeOfDay = "PM";
			}
			if (V_ClockLastHour >= 13 && V_ClockLastHour <= 24)
			{
				ClockLastHour = V_ClockLastHour - 12;

				V_LastTimeOfDay = "PM";
			}

			std::string Sla = "/";
			std::string Spa = " ";
			std::string Col = ":";

			std::string ClockStr = V_ClockStr;
			std::string DobStr = V_DobStr;
			std::string LastStr = V_LastStr;

			std::string MsStr = V_ClockMillisecondsStr;
			std::string SecStr = V_ClockSecondsStr;
			std::string MinStr = V_ClockMinutesStr;
			std::string HourStr = V_ClockHoursStr;

			std::string BestAndyStr = V_BestAndyStr;
			std::string BestDurielStr = V_BestDurielStr;
			std::string BestMephStr = V_BestMephStr;
			std::string BestDiabloStr = V_BestDiabloStr;
			std::string BestBaalStr = V_BestBaalStr;

			std::string BestAndyNMStr = V_BestAndyNMStr;
			std::string BestDurielNMStr = V_BestDurielNMStr;
			std::string BestMephNMStr = V_BestMephNMStr;
			std::string BestDiabloNMStr = V_BestDiabloNMStr;
			std::string BestBaalNMStr = V_BestBaalNMStr;

			std::string BestAndyHellStr = V_BestAndyHellStr;
			std::string BestDurielHellStr = V_BestDurielHellStr;
			std::string BestMephHellStr = V_BestMephHellStr;
			std::string BestDiabloHellStr = V_BestDiabloHellStr;
			std::string BestBaalHellStr = V_BestBaalHellStr;

			std::string Hours = std::to_string((double long)V_ClockHours);
			std::string Mins = std::to_string((double long)V_ClockMinutes);
			std::string Secs = std::to_string((double long)V_ClockSeconds);
			std::string Mss = std::to_string((double long)V_ClockMilliseconds);

			std::string DoBYear = std::to_string((double long)V_ClockDoBYear);
			std::string DoBMon = std::to_string((double long)V_ClockDoBMonth);
			std::string DoBDay = std::to_string((double long)V_ClockDoBDay);
			std::string DoBHour = std::to_string((double long)ClockDoBHour);
			std::string DoBMin = SingleDigitToString(V_ClockDoBMinute);
			std::string DoBSec = SingleDigitToString(V_ClockDoBSecond);

			std::string LastYear = std::to_string((double long)V_ClockLastYear);
			std::string LastMon = std::to_string((double long)V_ClockLastMonth);
			std::string LastDay = std::to_string((double long)V_ClockLastDay);
			std::string LastHour = std::to_string((double long)ClockLastHour);
			std::string LastMin = SingleDigitToString(V_ClockLastMinute);
			std::string LastSec = SingleDigitToString(V_ClockLastSecond);

			std::string BestAndyHour = std::to_string((double long)V_BestAndyHour);
			std::string BestAndyMin = std::to_string((double long)V_BestAndyMin);
			std::string BestAndySec = std::to_string((double long)V_BestAndySec);
			std::string BestDurielHour = std::to_string((double long)V_BestDurielHour);
			std::string BestDurielMin = std::to_string((double long)V_BestDurielMin);
			std::string BestDurielSec = std::to_string((double long)V_BestDurielSec);
			std::string BestMephHour = std::to_string((double long)V_BestMephHour);
			std::string BestMephMin = std::to_string((double long)V_BestMephMin);
			std::string BestMephSec = std::to_string((double long)V_BestMephSec);
			std::string BestDiabloHour = std::to_string((double long)V_BestDiabloHour);
			std::string BestDiabloMin = std::to_string((double long)V_BestDiabloMin);
			std::string BestDiabloSec = std::to_string((double long)V_BestDiabloSec);
			std::string BestBaalHour = std::to_string((double long)V_BestBaalHour);
			std::string BestBaalMin = std::to_string((double long)V_BestBaalMin);
			std::string BestBaalSec = std::to_string((double long)V_BestBaalSec);

			std::string BestAndyNMHour = std::to_string((double long)V_BestAndyNMHour);
			std::string BestAndyNMMin = std::to_string((double long)V_BestAndyNMMin);
			std::string BestAndyNMSec = std::to_string((double long)V_BestAndyNMSec);
			std::string BestDurielNMHour = std::to_string((double long)V_BestDurielNMHour);
			std::string BestDurielNMMin = std::to_string((double long)V_BestDurielNMMin);
			std::string BestDurielNMSec = std::to_string((double long)V_BestDurielNMSec);
			std::string BestMephNMHour = std::to_string((double long)V_BestMephNMHour);
			std::string BestMephNMMin = std::to_string((double long)V_BestMephNMMin);
			std::string BestMephNMSec = std::to_string((double long)V_BestMephNMSec);
			std::string BestDiabloNMHour = std::to_string((double long)V_BestDiabloNMHour);
			std::string BestDiabloNMMin = std::to_string((double long)V_BestDiabloNMMin);
			std::string BestDiabloNMSec = std::to_string((double long)V_BestDiabloNMSec);
			std::string BestBaalNMHour = std::to_string((double long)V_BestBaalNMHour);
			std::string BestBaalNMMin = std::to_string((double long)V_BestBaalNMMin);
			std::string BestBaalNMSec = std::to_string((double long)V_BestBaalNMSec);

			std::string BestAndyHellHour = std::to_string((double long)V_BestAndyHellHour);
			std::string BestAndyHellMin = std::to_string((double long)V_BestAndyHellMin);
			std::string BestAndyHellSec = std::to_string((double long)V_BestAndyHellSec);
			std::string BestDurielHellHour = std::to_string((double long)V_BestDurielHellHour);
			std::string BestDurielHellMin = std::to_string((double long)V_BestDurielHellMin);
			std::string BestDurielHellSec = std::to_string((double long)V_BestDurielHellSec);
			std::string BestMephHellHour = std::to_string((double long)V_BestMephHellHour);
			std::string BestMephHellMin = std::to_string((double long)V_BestMephHellMin);
			std::string BestMephHellSec = std::to_string((double long)V_BestMephHellSec);
			std::string BestDiabloHellHour = std::to_string((double long)V_BestDiabloHellHour);
			std::string BestDiabloHellMin = std::to_string((double long)V_BestDiabloHellMin);
			std::string BestDiabloHellSec = std::to_string((double long)V_BestDiabloHellSec);
			std::string BestBaalHellHour = std::to_string((double long)V_BestBaalHellHour);
			std::string BestBaalHellMin = std::to_string((double long)V_BestBaalHellMin);
			std::string BestBaalHellSec = std::to_string((double long)V_BestBaalHellSec);

			V_PlayerInfoTextStrR1 = ClockStr + Hours + HourStr + Mins + MinStr + Secs + SecStr;
			V_PlayerInfoTextStrR2 = DobStr + DoBMon + Sla + DoBDay + Sla + DoBYear + Spa + DoBHour + Col + DoBMin + Col + DoBSec + Spa + V_DoBTimeOfDay;
			V_PlayerInfoTextStrR3 = LastStr + LastMon + Sla + LastDay + Sla + LastYear + Spa + LastHour + Col + LastMin + Col + LastSec + Spa + V_LastTimeOfDay;
			V_PlayerInfoTextStrR5 = BestAndyStr + BestAndyHour + HourStr + BestAndyMin + MinStr + BestAndySec + SecStr;
			V_PlayerInfoTextStrR6 = BestDurielStr + BestDurielHour + HourStr + BestDurielMin + MinStr + BestDurielSec + SecStr;
			V_PlayerInfoTextStrR7 = BestMephStr + BestMephHour + HourStr + BestMephMin + MinStr + BestMephSec + SecStr;
			V_PlayerInfoTextStrR8 = BestDiabloStr + BestDiabloHour + HourStr + BestDiabloMin + MinStr + BestDiabloSec + SecStr;
			V_PlayerInfoTextStrR9 = BestBaalStr + BestBaalHour + HourStr + BestBaalMin + MinStr + BestBaalSec + SecStr;
			V_PlayerInfoTextStrR10 = BestAndyNMStr + BestAndyNMHour + HourStr + BestAndyNMMin + MinStr + BestAndyNMSec + SecStr;
			V_PlayerInfoTextStrR11 = BestDurielNMStr + BestDurielNMHour + HourStr + BestDurielNMMin + MinStr + BestDurielNMSec + SecStr;
			V_PlayerInfoTextStrR12 = BestMephNMStr + BestMephNMHour + HourStr + BestMephNMMin + MinStr + BestMephNMSec + SecStr;
			V_PlayerInfoTextStrR13 = BestDiabloNMStr + BestDiabloNMHour + HourStr + BestDiabloNMMin + MinStr + BestDiabloNMSec + SecStr;
			V_PlayerInfoTextStrR14 = BestBaalNMStr + BestBaalNMHour + HourStr + BestBaalNMMin + MinStr + BestBaalNMSec + SecStr;
			V_PlayerInfoTextStrR15 = BestAndyHellStr + BestAndyHellHour + HourStr + BestAndyHellMin + MinStr + BestAndyHellSec + SecStr;
			V_PlayerInfoTextStrR16 = BestDurielHellStr + BestDurielHellHour + HourStr + BestDurielHellMin + MinStr + BestDurielHellSec + SecStr;
			V_PlayerInfoTextStrR17 = BestMephHellStr + BestMephHellHour + HourStr + BestMephHellMin + MinStr + BestMephHellSec + SecStr;
			V_PlayerInfoTextStrR18 = BestDiabloHellStr + BestDiabloHellHour + HourStr + BestDiabloHellMin + MinStr + BestDiabloHellSec + SecStr;
			V_PlayerInfoTextStrR19 = BestBaalHellStr + BestBaalHellHour + HourStr + BestBaalHellMin + MinStr + BestBaalHellSec + SecStr;

			strcpy(V_PlayerInfoText1, V_PlayerInfoTextStrR1.c_str());
			strcpy(V_PlayerInfoText2, V_PlayerInfoTextStrR2.c_str());
			strcpy(V_PlayerInfoText3, V_PlayerInfoTextStrR3.c_str());
			strcpy(V_PlayerInfoText5, V_PlayerInfoTextStrR5.c_str());
			strcpy(V_PlayerInfoText6, V_PlayerInfoTextStrR6.c_str());
			strcpy(V_PlayerInfoText7, V_PlayerInfoTextStrR7.c_str());
			strcpy(V_PlayerInfoText8, V_PlayerInfoTextStrR8.c_str());
			strcpy(V_PlayerInfoText9, V_PlayerInfoTextStrR9.c_str());
			strcpy(V_PlayerInfoText10, V_PlayerInfoTextStrR10.c_str());
			strcpy(V_PlayerInfoText11, V_PlayerInfoTextStrR11.c_str());
			strcpy(V_PlayerInfoText12, V_PlayerInfoTextStrR12.c_str());
			strcpy(V_PlayerInfoText13, V_PlayerInfoTextStrR13.c_str());
			strcpy(V_PlayerInfoText14, V_PlayerInfoTextStrR14.c_str());
			strcpy(V_PlayerInfoText15, V_PlayerInfoTextStrR15.c_str());
			strcpy(V_PlayerInfoText16, V_PlayerInfoTextStrR16.c_str());
			strcpy(V_PlayerInfoText17, V_PlayerInfoTextStrR17.c_str());
			strcpy(V_PlayerInfoText18, V_PlayerInfoTextStrR18.c_str());
			strcpy(V_PlayerInfoText19, V_PlayerInfoTextStrR19.c_str());

			Print(1, 9, "Printing date/time data...");

			Print(0, 0, "Date/Time Information:");

			Print(0, 0, "%s", V_PlayerInfoText1);
			Print(0, 0, "%s", V_PlayerInfoText2);
			Print(0, 0, "%s", V_PlayerInfoText3);
			Print(0, 0, "%s", V_PlayerInfoText5);
			Print(0, 0, "%s", V_PlayerInfoText6);
			Print(0, 0, "%s", V_PlayerInfoText7);
			Print(0, 0, "%s", V_PlayerInfoText8);
			Print(0, 0, "%s", V_PlayerInfoText9);
			Print(0, 0, "%s", V_PlayerInfoText10);
			Print(0, 0, "%s", V_PlayerInfoText11);
			Print(0, 0, "%s", V_PlayerInfoText12);
			Print(0, 0, "%s", V_PlayerInfoText13);
			Print(0, 0, "%s", V_PlayerInfoText14);
			Print(0, 0, "%s", V_PlayerInfoText15);
			Print(0, 0, "%s", V_PlayerInfoText16);
			Print(0, 0, "%s", V_PlayerInfoText17);
			Print(0, 0, "%s", V_PlayerInfoText18);
			Print(0, 0, "%s", V_PlayerInfoText19);

			return FALSE;
		}
		if (!_stricmp(Argument[0], "playerinfo"))
		{
			ResetInfoText();

			std::string RankStr = V_RankStr;

			std::string NormStr = V_GameNormStr;
			std::string NmStr = V_GameNmStr;
			std::string HellStr = V_GameHellStr;

			std::string KilledStr = V_TimesKilledStr;

			std::string WonStr = V_GameWonStr;
			std::string DrawStr = V_GameDrawStr;
			std::string LostStr = V_GameLostStr;

			std::string HealthStr = V_HealthUsedStr;
			std::string ManaStr = V_ManaUsedStr;
			std::string HealedStr = V_TimesHealedStr;

			std::string WeaponStr = V_EquipWeaponStr;
			std::string ArmorStr = V_EquipArmorStr;
			std::string MiscStr = V_EquipMiscStr;

			std::string TotalGoldStr = V_TotalGoldStr;
			std::string GoldTrillionStr = V_GoldTrillionStr;
			std::string GoldBillionStr = V_GoldBillionStr;
			std::string GoldMillionStr = V_GoldMillionStr;
			std::string GoldThousandStr = V_GoldThousandStr;

			INT Weapon;
			INT Armor;
			INT Misc;
			Weapon = V_EquipRightW + V_EquipLeftW + V_EquipRight2W + V_EquipLeft2W;
			Armor = V_EquipHead + V_EquipBody + V_EquipBelt + V_EquipFeet + V_EquipGloves;
			Misc = V_EquipAmulet + V_EquipRightR + V_EquipLeftR;

			V_PlayerInfoTextStrR1 = RankStr + AddCommas(V_Rank, 0);
			V_PlayerInfoTextStrR3 = NormStr + AddCommas(V_Games0, 0);
			V_PlayerInfoTextStrR4 = NmStr + AddCommas(V_Games1, 0);
			V_PlayerInfoTextStrR5 = HellStr + AddCommas(V_Games2, 0);
			V_PlayerInfoTextStrR7 = KilledStr + AddCommas(V_TimesKilled, 0);
			V_PlayerInfoTextStrR9 = WonStr + AddCommas(V_GamesWon, 0);
			V_PlayerInfoTextStrR10 = LostStr + AddCommas(V_GamesLost, 0);
			V_PlayerInfoTextStrR11 = DrawStr + AddCommas(V_GamesDraw, 0);
			V_PlayerInfoTextStrR13 = HealthStr + AddCommas(V_HealthUsed, 0);
			V_PlayerInfoTextStrR14 = ManaStr + AddCommas(V_ManaUsed, 0);
			V_PlayerInfoTextStrR15 = HealedStr + AddCommas(V_TimesHealed, 0);
			if (V_GoldBillion < 1)
			{
				V_PlayerInfoTextStrR17 = TotalGoldStr + AddCommas(V_GoldMillion, 0) + GoldMillionStr + ", " + AddCommas(V_GoldThousand, 0) + GoldThousandStr;
			}
			if (V_GoldBillion >= 1)
			{
				V_PlayerInfoTextStrR17 = TotalGoldStr + AddCommas(V_GoldBillion, 0) + GoldBillionStr + ", " + AddCommas(V_GoldMillion, 0) + GoldMillionStr + ", " + AddCommas(V_GoldThousand, 0) + GoldThousandStr;
			}
			if (V_GoldTrillion >= 1)
			{
				V_PlayerInfoTextStrR17 = TotalGoldStr + AddCommas(V_GoldTrillion, 0) + GoldTrillionStr + ", " + AddCommas(V_GoldBillion, 0) + GoldBillionStr + ", " + AddCommas(V_GoldMillion, 0) + GoldMillionStr + ", " + AddCommas(V_GoldThousand, 0) + GoldThousandStr;
			}
			V_PlayerInfoTextStrR19 = WeaponStr + AddCommas(Weapon, 0);
			V_PlayerInfoTextStrR20 = ArmorStr + AddCommas(Armor, 0);
			V_PlayerInfoTextStrR21 = MiscStr + AddCommas(Misc, 0);

			strcpy(V_PlayerInfoText1, V_PlayerInfoTextStrR1.c_str());
			strcpy(V_PlayerInfoText3, V_PlayerInfoTextStrR3.c_str());
			strcpy(V_PlayerInfoText4, V_PlayerInfoTextStrR4.c_str());
			strcpy(V_PlayerInfoText5, V_PlayerInfoTextStrR5.c_str());
			strcpy(V_PlayerInfoText7, V_PlayerInfoTextStrR7.c_str());
			strcpy(V_PlayerInfoText9, V_PlayerInfoTextStrR9.c_str());
			strcpy(V_PlayerInfoText10, V_PlayerInfoTextStrR10.c_str());
			strcpy(V_PlayerInfoText11, V_PlayerInfoTextStrR11.c_str());
			strcpy(V_PlayerInfoText13, V_PlayerInfoTextStrR13.c_str());
			strcpy(V_PlayerInfoText14, V_PlayerInfoTextStrR14.c_str());
			strcpy(V_PlayerInfoText15, V_PlayerInfoTextStrR15.c_str());
			strcpy(V_PlayerInfoText17, V_PlayerInfoTextStrR17.c_str());
			strcpy(V_PlayerInfoText19, V_PlayerInfoTextStrR19.c_str());
			strcpy(V_PlayerInfoText20, V_PlayerInfoTextStrR20.c_str());
			strcpy(V_PlayerInfoText21, V_PlayerInfoTextStrR21.c_str());

			Print(1, 9, "Printing player data...");

			Print(0, 0, "Player Information:");
			Print(0, 0,	"%s", V_PlayerInfoText1); //Rank
			Print(0, 0, "%s", V_PlayerInfoText3); //Games Normal
			Print(0, 0, "%s", V_PlayerInfoText4); //Games Nightmare
			Print(0, 0, "%s", V_PlayerInfoText5); //Games Hell
			Print(0, 0, "%s", V_PlayerInfoText7); //Times Killed
			Print(0, 0, "%s", V_PlayerInfoText9); //Games Won
			Print(0, 0, "%s", V_PlayerInfoText10); //Games Lost
			Print(0, 0, "%s", V_PlayerInfoText11); //Games Draw
			Print(0, 0, "%s", V_PlayerInfoText13); //Health Pots Used
			Print(0, 0, "%s", V_PlayerInfoText14); //Mana Pots Used
			Print(0, 0, "%s", V_PlayerInfoText15); //Times Healed
			Print(0, 0, "%s", V_PlayerInfoText17); //Gold Found
			Print(0, 0, "%s", V_PlayerInfoText19); //Weapons Equipped
			Print(0, 0, "%s", V_PlayerInfoText20); //Armor Equipped
			Print(0, 0, "%s", V_PlayerInfoText21); //Misc. Equipped

			return FALSE;
		}

		if (!_stricmp(Argument[0], "travelinfo"))
		{
			ResetInfoText();

			std::string AreaChangedStr = V_ChangedAreaStr;
			std::string PortalStr = V_PortalsTakenStr;
			std::string WaypointStr = V_WaypointUsedStr;
			std::string ShrineStr = V_ShrineUsedStr;

			std::string DistanceStr = V_TravelDistanceStr;
			std::string MileStr = V_TravelMileStr;
			std::string YardStr = V_TravelYardStr;

			V_PlayerInfoTextStrR1 = AreaChangedStr + AddCommas(V_ChangedArea, 0);
			V_PlayerInfoTextStrR2 = PortalStr + AddCommas(V_PortalsTaken, 0);
			V_PlayerInfoTextStrR3 = WaypointStr + AddCommas(V_WaypointUsed, 0);
			V_PlayerInfoTextStrR5 = ShrineStr + AddCommas(V_ShrineUsed, 0);
			V_PlayerInfoTextStrR7 = DistanceStr + AddCommas(V_TravelDistanceMile, 0) + MileStr + AddCommas(V_TravelDistanceYard, 0) + YardStr;

			strcpy(V_PlayerInfoText1, V_PlayerInfoTextStrR1.c_str());
			strcpy(V_PlayerInfoText2, V_PlayerInfoTextStrR2.c_str());
			strcpy(V_PlayerInfoText3, V_PlayerInfoTextStrR3.c_str());
			strcpy(V_PlayerInfoText5, V_PlayerInfoTextStrR5.c_str());
			strcpy(V_PlayerInfoText7, V_PlayerInfoTextStrR7.c_str());

			Print(1, 9, "Printing travel data...");

			Print(0, 0, "Travel Information:");
			Print(0, 0, "%s", V_PlayerInfoText1); //Areas Changed
			Print(0, 0, "%s", V_PlayerInfoText2); //Portals Taken
			Print(0, 0, "%s", V_PlayerInfoText3); //Waypoints Used
			Print(0, 0, "%s", V_PlayerInfoText5); //Shrines Used
			Print(0, 0, "%s", V_PlayerInfoText7); //Distance Traveled

			return FALSE;
		}

		if (!_stricmp(Argument[0], "ladderinfo"))
		{
			if (V_BusyUpdData == TRUE)
			{
				Print(1, 9, "Busy updating ladder data...");

				return FALSE;
			}
			RegisterLadder();

			UpdateLadder();

			Print(1, 9, "Printing ladder data...");
			Print(0, 0, "Player Ladder:");
			for (INT i = 0; i < 25; i++)
			{
				if (V_LadderExp[i] < 1)
				{
					Print(0, 0, "No.: %d, Name: -, Lv.: -, Rank: -, Class: AMA, Exp.: -",
						i + 1);

					Print(0, 0, "No player note");
				}
				else
				{
					Print(0, 0, "No.: %d, Name: %s, Lv.: %d, Rank: %d, Class: %s, Exp.: %s",
						i + 1, V_LadderName[i], V_LadderLevel[i], V_LadderRank[i], V_LadderClassAbrv[V_LadderClass[i]], AddCommas(V_LadderExp[i], 0));
					if (V_LadderNote[i][0] == NULL)
					{
						Print(0, 0, "No player note");
					}
					else
					{
						Print(0, 0, "%s", V_LadderNote[i]);
					}
				}
			}

			return FALSE;
		}

#ifndef FFXIVMOD
		if (V_ToggleKeyItem[5][0] || V_GMMode)
		{
			if (!_stricmp(Argument[0], "dupe1"))
			{
				V_Block0x30 = !V_Block0x30;

				if (V_Block0x30)
				{
					Print(0, 0, "�c2Blocking Packet 0x30");
				}
				else
				{
					Print(0, 0, "�c2Unblocking Packet 0x30");
				}

				return FALSE;
			}
			if (!_stricmp(Argument[0], "dupe2"))
			{
				GetUnitWaypoint();

				return FALSE;
			}
			if (!_stricmp(Argument[0], "dupe3"))
			{
				DupeCloseTrade();

				return FALSE;
			}
			if (!_stricmp(Argument[0], "travel1"))
			{
				TravelGoA5();

				return FALSE;
			}
			if (!_stricmp(Argument[0], "travel2"))
			{
				TravelGiveA5();

				return FALSE;
			}
			if (!_stricmp(Argument[0], "travel3"))
			{
				TravelGetA5();

				return FALSE;
			}
		}
#endif
		if (!_stricmp(Argument[0], "players"))
		{
			if (Argument[1] != NULL)
			{
				try 
				{
					LoadPlugY();
					INT memPlayersbyDefault = V_NBPlayersByDefault;

					V_NBPlayersByDefault = boost::lexical_cast<int>(Argument[1]);

					if (V_NBPlayersByDefault == memPlayersbyDefault)
						return FALSE;

					SavePlugY();

					if (V_NBPlayersByDefault > memPlayersbyDefault)
					{
						Print(0, 4, "Diablo's minions grow stronger.");
					}
					else if (V_NBPlayersByDefault < memPlayersbyDefault)
					{
						Print(0, 4, "Diablo's minions weaken.");
					}

					return FALSE;
				}
				catch(boost::bad_lexical_cast const &e)
				{
					Print(1, 1, "Error saving new multiplayer settings!");

					return FALSE;
				}
			}
			Print(1, 9, "Please enter new amount of players...");
			return FALSE;
		}
#ifndef FFXIVMOD
		if (!_stricmp(Argument[0], "mpmode"))
		{
			if (Argument[1] != NULL)
			{
				if (!_stricmp(Argument[1], "on"))
				{
					V_ActiveMultiPageStash = 0;
					V_ActiveSharedStash = 0;

					V_MultiPlayerMode = 1;

					SavePlugY();

					Print(1, 9, "Multiplayer mode activated!");
					Print(1, 9, "Extra and shared stash will no longer be available.");

					return FALSE;
				}
				if (!_stricmp(Argument[1], "off"))
				{
					V_ActiveMultiPageStash = 1;
					V_ActiveSharedStash = 1;

					V_MultiPlayerMode = 0;

					SavePlugY();

					Print(1, 9, "Multiplayer mode disabled!");
					Print(1, 9, "Extra and shared stash will be available next game.");

					return FALSE;
				}
			}
			Print(1, 9, "Would you like to turn Multiplayer mode on or off?  Try again...");
			return FALSE;
		}
#endif
		if (!_stricmp(Argument[0], "resetladder"))
		{
			V_QueueLadderReset = TRUE;

			return FALSE;
		}
		if (!_stricmp(Argument[0], "saveladder"))
		{
			V_QueueLadderSave = TRUE;

			return FALSE;
		}
		if (!_stricmp(Argument[0], "setnote"))
		{
			if (!Argument[1])
			{
				Print(1, 9, "You must enter a note!");

				return FALSE;
			}

			std::string Note = Message;
			if (Note.length() > 59) //50 + 9 = 59
			{
				Print(1, 9, "Player note too long!");

				return FALSE;
			}

			strncpy_s(V_TempLadderNote, sizeof(V_TempLadderNote), Argument[1], sizeof(V_TempLadderNote));

			if (Argument[2])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[2]);
			}
			if (Argument[3])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[3]);
			}
			if (Argument[4])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[4]);
			}
			if (Argument[5])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[5]);
			}
			if (Argument[6])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[6]);
			}
			if (Argument[7])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[7]);
			}
			if (Argument[8])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[8]);
			}
			if (Argument[9])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[9]);
			}
			if (Argument[10])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[10]);
			}
			if (Argument[11])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[11]);
			}
			if (Argument[12])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[12]);
			}
			if (Argument[13])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[13]);
			}
			if (Argument[14])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[14]);
			}
			if (Argument[15])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[15]);
			}
			if (Argument[16])
			{
				strcat_s(V_TempLadderNote, " ");
				strcat_s(V_TempLadderNote, Argument[16]);
			}

			V_QueueLadderSetNote = TRUE;

			return FALSE;
		}
		if (!_stricmp(Argument[0], "deletenote"))
		{
			V_QueueLadderDeleteNote = TRUE;

			return FALSE;
		}
		if (!_stricmp(Argument[0], "resetkeyitems"))
		{
			ResetKeyItems();

			Print(1, 9, "Key items reset.");

			return FALSE;
		}
	}
	if(Buffer[0] == '@')
	{
		if (!_stricmp(Argument[0], "id"))
		{
			if (Argument[1] != NULL)
			{
				try 
				{
					V_IDEntry = boost::lexical_cast<int>(Argument[1]);

					Print(0, 0, "Looking up your key...");
					V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)GETKEY);
				}
				catch(boost::bad_lexical_cast const &e)
				{
					Print(0, 1, "Error processing identification...");

					return FALSE;
				}
				return FALSE;
			}
			Print(0, 0, "Enter your �c2Identification �c0number.");

			return FALSE;
		}
		if(!_stricmp(Argument[0], "key"))
		{
			if (Argument[1] != NULL)
			{
				try 
				{
					V_KeyEntry = boost::lexical_cast<int>(Argument[1]);

					Print(0, 0, "Checking your �c2Key�c0...");
					V_PrimaryThread.Handle = MakeThread((LPVOID)Threads, (LPVOID)CHECKKEY);
				}
				catch(boost::bad_lexical_cast const &e)
				{
					Print(0, 1, "Error processing key...");

					return FALSE;
				}
				return FALSE;
			}
			Print(0, 0, "Enter a valid �c2Key �c0number.");

			return FALSE;
		}

		if(!_stricmp(Argument[0], "89509"))
		{
			V_Validated = TRUE;

			Print(0, 2, "Key validated.");
			Print(0, 0, "Enter time of release �c4@<HHMM> �c0to register.");

			return FALSE;
		}
		if (!_stricmp(Argument[0], "826") && V_Validated == TRUE)
		{
			V_Registered = TRUE;

			if(!V_GMMode)
			{
				V_GMMode = TRUE;

				Print(0, 1, "Turning �c5GM Mode�c1 on.");
			}
			else
			{
				Print(0, 1, "Turning �c5GM Mode�c1 off.");

				V_GMMode = FALSE;
			}

			if(Argument[1] != NULL)
			{
				if(!_stricmp(Argument[1], "1862"))
				{
					if(Argument[2] != NULL)
					{
						if(!_stricmp(Argument[2], "10569483"))
						{
							if(Argument[3] != NULL)
							{
								if(!_stricmp(Argument[3], "13"))
								{
									if(!V_GMMode)
									{
										V_GMMode = TRUE;

										Print(0, 1, "Registered successfully in �c5GM Mode�c1.");
									}
									else
									{
										Print(0, 1, "You are already registered in �c5GM Mode�c1.");
									}

									if(KEYMAKER == 1)
									{
										MakeKeys();
									}

									return FALSE;
								}
							}
							Print(0, 1, "You dropped something.");
						}
					}
				}
			}
			return FALSE;
		}
	}

	if (Buffer[0] == '$')
	{
		if(!_stricmp(Argument[0], "9192"))
		{
			Print(0, 3, "You unlock Yojimbo's chest.");

			Print(0, 4, "Blood-stained Katana Grip");

			return FALSE;
		}
	}

	return TRUE;
}
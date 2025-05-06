#include "Hack.h"

BOOL FASTCALL OnGamePacketSent(LPBYTE Packet, DWORD Length)
{
	if (Packet[0] <= 0x11)
	{
		//
		//HF2 Menu START
		if (V_ClickIgnore)
			return FALSE;

		if (V_ClickIgnoreMenu)
			return FALSE;

		if (V_ClickIgnoreStat)
			return FALSE;

		if (V_ClickIgnoreInfo)
			return FALSE;

		if (V_ClickIgnoreMission)
			return FALSE;

		if (V_ClickIgnoreAbility)
			return FALSE;

		if (V_ClickIgnoreGuide)
			return FALSE;

		if (V_ClickIgnoreCalc)
			return FALSE;

		if (V_ClickIgnoreSetting)
			return FALSE;

		if (V_ClickIgnoreInfo2)
			return FALSE;

		if (V_ClickIgnoreMission2)
			return FALSE;

		if (V_ClickIgnoreAbility2)
			return FALSE;

		if (V_ClickIgnoreStat2)
			return FALSE;

		if (V_ClickIgnoreGuide2)
			return FALSE;

		if (V_ClickIgnoreGuide3)
			return FALSE;

		if (V_ClickIgnoreGuide4)
			return FALSE;
		//HF2 Menu END
		//

		if (V_TP)
			return FALSE;

		if (!V_TeleportQueue.IsEmpty())
			V_TeleportQueue.RemoveAll();

		if (V_TeleWalk)
		{
			Teleport(*(LPWORD)&Packet[1], *(LPWORD)&Packet[3]);
			V_TeleWalk = FALSE;
		}
	}

	if (Packet[0] == 0x13)
	{
		if (V_BlockTP && ClientReady(TRUE))
		{
			LPUNITANY Unit = (LPUNITANY)GetUnit(*(LPDWORD)&Packet[5], UNIT_TYPE_OBJECT);
			DOUBLE LifePercent = CalcPercent((GetUnitStat(Me, STAT_HP) >> 8), (GetUnitStat(Me, STAT_MAXHP) >> 8));
			DOUBLE ManaPercent = CalcPercent((GetUnitStat(Me, STAT_MANA) >> 8), (GetUnitStat(Me, STAT_MAXMANA) >> 8));

			if (Unit && Unit->dwTxtFileNo == 0x3B && InTown(Me))
			{
				if (V_LifeTownPercent > 0 && LifePercent <= V_LifeTownPercent || V_ManaTownPercent > 0 && ManaPercent <= V_ManaTownPercent)
					return FALSE;
			}
		}
	}

	if (Packet[0] == 0x18)
	{
		if (V_CubeOrStashOpened)
			if ((*(LPDWORD)&Packet[13] == STORAGE_STASH || *(LPDWORD)&Packet[13] == STORAGE_CUBE) && !InTown(Me))
				return FALSE;
	}

	if (Packet[0] == 0x19)
	{
		if (V_CubeOrStashOpened)
		{
			LPUNITANY Unit = (LPUNITANY)GetUnit(*(LPDWORD)&Packet[1], UNIT_TYPE_ITEM);

			if (Unit && (GetItemLocation(Unit) == STORAGE_STASH || GetItemLocation(Unit) == STORAGE_CUBE))
				return FALSE;
		}
	}

	//Godmode
	if (Packet[0] == 0x24)
	{
		if (V_CSet == TRUE)
		{
			V_Heal[5] = Packet[1];
			Print(0, 4, "ÿc2Godmode: Potion ID copied.ÿc0");

			V_PCopied = TRUE;
		}
	}

	/* Godmode UNUSED/OUTDATED
	if (Packet[0] == 0x19)
	{
		if (V_CSet == TRUE)
		{
			V_Heal[1] = Packet[1];
			Print(0, 4, "ÿc2Godmode: Item ID copied.ÿc0");

			V_ICopied = TRUE;
		}
	}
	*/

	if (Packet[0] == 0x1a)
	{
		if (*(LPWORD)&Packet[5] == EQUIP_HEAD)
			V_EquipHead += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_AMULET)
			V_EquipAmulet += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_BODY)
			V_EquipBody += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_RIGHT_PRIMARY)
			V_EquipRightW += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_LEFT_PRIMARY)
			V_EquipLeftW += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_RIGHT_RING)
			V_EquipRightR += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_LEFT_RING)
			V_EquipLeftR += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_BELT)
			V_EquipBelt += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_FEET)
			V_EquipFeet += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_GLOVES)
			V_EquipGloves += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_RIGHT_SECONDARY)
			V_EquipRight2W += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_LEFT_SECONDARY)
			V_EquipLeft2W += 1;

		//Godmode
		if (V_CSet == TRUE)
		{
			V_Heal[1] = Packet[1];
			Print(0, 4, "ÿc2Godmode: Hat ID copied.ÿc0");

			V_ICopied = TRUE;
		}
	}

	if (Packet[0] == 0x1d)
	{
		if (*(LPWORD)&Packet[5] == EQUIP_HEAD)
			V_EquipHead += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_AMULET)
			V_EquipAmulet += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_BODY)
			V_EquipBody += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_RIGHT_PRIMARY)
			V_EquipRightW += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_LEFT_PRIMARY)
			V_EquipLeftW += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_RIGHT_RING)
			V_EquipRightR += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_LEFT_RING)
			V_EquipLeftR += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_BELT)
			V_EquipBelt += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_FEET)
			V_EquipFeet += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_GLOVES)
			V_EquipGloves += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_RIGHT_SECONDARY)
			V_EquipRight2W += 1;

		if (*(LPWORD)&Packet[5] == EQUIP_LEFT_SECONDARY)
			V_EquipLeft2W += 1;
	}

	//Godmode
	if ((Packet[0] == 0x13) && (Packet[1] == 0x01))
	{
		if (V_CSet == TRUE)
		{
			V_BuyHeal[1] = Packet[5];
			Print(0, 4, "ÿc2Godmode: NPC ID copied. You may now use 'ÿc5.god buyÿc2' to buy health from the NPC.ÿc0");

			V_NPCCopied = TRUE;
		}
	}

	if (Packet[0] == 0x30)
	{
		if(V_Block0x30)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}

	return TRUE;
}
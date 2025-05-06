#include "Hack.h"

VOID SetInfoText(INT iInfoGroup, INT iInfoId, INT iSelectedPage)
{
	//
	//Player
	if (iInfoGroup == 1)
	{
		//Date/Time
		if (iInfoId == 1)
		{
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
			V_PlayerInfoTextStrR4 = "";
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
			V_PlayerInfoTextStrR20 = "";
			V_PlayerInfoTextStrR21 = "";
		}

		//Game
		if (iInfoId == 2)
		{
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
			V_PlayerInfoTextStrR2 = "";
			V_PlayerInfoTextStrR3 = NormStr + AddCommas(V_Games0, 0);
			V_PlayerInfoTextStrR4 = NmStr + AddCommas(V_Games1, 0);
			V_PlayerInfoTextStrR5 = HellStr + AddCommas(V_Games2, 0);
			V_PlayerInfoTextStrR6 = "";
			V_PlayerInfoTextStrR7 = KilledStr + AddCommas(V_TimesKilled, 0);
			V_PlayerInfoTextStrR8 = "";
			V_PlayerInfoTextStrR9 = WonStr + AddCommas(V_GamesWon, 0);
			V_PlayerInfoTextStrR10 = LostStr + AddCommas(V_GamesLost, 0);
			V_PlayerInfoTextStrR11 = DrawStr + AddCommas(V_GamesDraw, 0);
			V_PlayerInfoTextStrR12 = "";
			V_PlayerInfoTextStrR13 = HealthStr + AddCommas(V_HealthUsed, 0);
			V_PlayerInfoTextStrR14 = ManaStr + AddCommas(V_ManaUsed, 0);
			V_PlayerInfoTextStrR15 = HealedStr + AddCommas(V_TimesHealed, 0);
			V_PlayerInfoTextStrR16 = "";
			if(V_GoldBillion < 1)
			{
				V_PlayerInfoTextStrR17 = TotalGoldStr + AddCommas(V_GoldMillion, 0) + GoldMillionStr + ", " + AddCommas(V_GoldThousand, 0) + GoldThousandStr;
			}
			if(V_GoldBillion >= 1)
			{
				V_PlayerInfoTextStrR17 = TotalGoldStr + AddCommas(V_GoldBillion, 0) + GoldBillionStr + ", " + AddCommas(V_GoldMillion, 0) + GoldMillionStr + ", " + AddCommas(V_GoldThousand, 0) + GoldThousandStr;
			}
			if(V_GoldTrillion >= 1)
			{
				V_PlayerInfoTextStrR17 = TotalGoldStr + AddCommas(V_GoldTrillion, 0) + GoldTrillionStr + ", " + AddCommas(V_GoldBillion, 0) + GoldBillionStr + ", " + AddCommas(V_GoldMillion, 0) + GoldMillionStr + ", " + AddCommas(V_GoldThousand, 0) + GoldThousandStr;
			}
			V_PlayerInfoTextStrR18 = "";
			V_PlayerInfoTextStrR19 = WeaponStr + AddCommas(Weapon, 0);
			V_PlayerInfoTextStrR20 = ArmorStr + AddCommas(Armor, 0);
			V_PlayerInfoTextStrR21 = MiscStr + AddCommas(Misc, 0);
		}

		//Classes
		if (iInfoId == 3)
		{
			LPROSTERUNIT pMe = *p_D2CLIENT_PlayerUnitList;
			if (pMe->dwClassId == CLASS_AMA) { V_PlayerInfoTextStrR1 = V_ClassStr[1]; }
			if (pMe->dwClassId == CLASS_SOR) { V_PlayerInfoTextStrR1 = V_ClassStr[2]; }
			if (pMe->dwClassId == CLASS_NEC) { V_PlayerInfoTextStrR1 = V_ClassStr[3]; }
			if (pMe->dwClassId == CLASS_PAL) { V_PlayerInfoTextStrR1 = V_ClassStr[4]; }
			if (pMe->dwClassId == CLASS_BAR) { V_PlayerInfoTextStrR1 = V_ClassStr[5]; }
			if (pMe->dwClassId == CLASS_DRU) { V_PlayerInfoTextStrR1 = V_ClassStr[6]; }
			if (pMe->dwClassId == CLASS_ASN) { V_PlayerInfoTextStrR1 = V_ClassStr[7]; }
			if (V_Class[0] != 1348) { V_PlayerInfoTextStrR2 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR2 = V_ClassStr[1 + 7]; }
			if (V_Class[1] != 1794) { V_PlayerInfoTextStrR3 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR3 = V_ClassStr[2 + 7]; }
			if (V_Class[2] != 1553) { V_PlayerInfoTextStrR4 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR4 = V_ClassStr[3 + 7]; }
			if (V_Class[3] != 1929) { V_PlayerInfoTextStrR5 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR5 = V_ClassStr[4 + 7]; }
			if (V_Class[4] != 1003) { V_PlayerInfoTextStrR6 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR6 = V_ClassStr[5 + 7]; }
			if (V_Class[5] != 1228) { V_PlayerInfoTextStrR7 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR7 = V_ClassStr[6 + 7]; }
			if (V_Class[6] != 1542) { V_PlayerInfoTextStrR8 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR8 = V_ClassStr[7 + 7]; }
			if (V_Class[7] != 1775) { V_PlayerInfoTextStrR9 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR9 = V_ClassStr[8 + 7]; }
			if (V_Class[8] != 1994) { V_PlayerInfoTextStrR10 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR10 = V_ClassStr[9 + 7]; }
			if (V_Class[9] != 1083) { V_PlayerInfoTextStrR11 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR11 = V_ClassStr[10 + 7]; }
			if (V_Class[10] != 1330) { V_PlayerInfoTextStrR12 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR12 = V_ClassStr[11 + 7]; }
			if (V_Class[11] != 1951) { V_PlayerInfoTextStrR13 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR13 = V_ClassStr[12 + 7]; }
			if (V_Class[12] != 1539) { V_PlayerInfoTextStrR14 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR14 = V_ClassStr[13 + 7]; }
			if (V_Class[13] != 1743) { V_PlayerInfoTextStrR15 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR15 = V_ClassStr[14 + 7]; }
			if (V_Class[14] != 1884) { V_PlayerInfoTextStrR16 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR16 = V_ClassStr[15 + 7]; }
			if (V_Class[15] != 1136) { V_PlayerInfoTextStrR17 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR17 = V_ClassStr[16 + 7]; }
			if (V_Class[16] != 1093) { V_PlayerInfoTextStrR18 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR18 = V_ClassStr[17 + 7]; }
			if (V_Class[17] != 1073) { V_PlayerInfoTextStrR19 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR19 = V_ClassStr[18 + 7]; }
			if (V_Class[18] != 1237) { V_PlayerInfoTextStrR20 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR20 = V_ClassStr[19 + 7]; }
			if (V_Class[19] != 1138) { V_PlayerInfoTextStrR21 = V_ClassStr[0]; }
			else { V_PlayerInfoTextStrR21 = V_ClassStr[20 + 7]; }
		}

		//Travel
		if (iInfoId == 4)
		{
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
			V_PlayerInfoTextStrR4 = "";
			V_PlayerInfoTextStrR5 = ShrineStr + AddCommas(V_ShrineUsed, 0);
			V_PlayerInfoTextStrR6 = "";
			V_PlayerInfoTextStrR7 = DistanceStr + AddCommas(V_TravelDistanceMile, 0) + MileStr + AddCommas(V_TravelDistanceYard, 0) + YardStr;
			V_PlayerInfoTextStrR8 = "";
			V_PlayerInfoTextStrR9 = "";
			V_PlayerInfoTextStrR10 = "";
			V_PlayerInfoTextStrR11 = "";
			V_PlayerInfoTextStrR12 = "";
			V_PlayerInfoTextStrR13 = "";
			V_PlayerInfoTextStrR14 = "";
			V_PlayerInfoTextStrR15 = "";
			V_PlayerInfoTextStrR16 = "";
			V_PlayerInfoTextStrR17 = "";
			V_PlayerInfoTextStrR18 = "";
			V_PlayerInfoTextStrR19 = "";
			V_PlayerInfoTextStrR20 = "";
			V_PlayerInfoTextStrR21 = "";
		}
	}

	//
	//Monsters
	if (iInfoGroup == 2)
	{
		std::string KilledStr = V_CounterKilledStr;

		//Act 1
		if (iInfoId == 1)
		{
			V_PlayerInfoTextPages = 3;

			if (iSelectedPage == 1)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[5] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][5], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[19] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][19], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[63] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][63], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[28] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][28], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[58] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][58], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[43] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][43], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[165] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][165], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[0] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][0], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[6] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][6], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[160] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][160], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[15] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][15], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[206] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][206], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[53] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][53], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[12] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][12], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[20] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][20], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[44] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][44], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[170] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][170], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[64] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][64], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[166] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][166], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[16] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][16], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[207] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][207], 0);

			}
			if (iSelectedPage == 2)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[1] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][1], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[24] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][24], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[54] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][54], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[59] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][59], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[161] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][161], 0);
				INT DevilkinHF2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][21] + V_MonsterUnit[D2CLIENT_GetDifficulty()][813];
				V_PlayerInfoTextStrR6 = V_MonsterStr[21] + KilledStr + AddCommas(DevilkinHF2, 0);
				INT GhostHF2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][38] + V_MonsterUnit[D2CLIENT_GetDifficulty()][814];
				V_PlayerInfoTextStrR7 = V_MonsterStr[38] + KilledStr + AddCommas(GhostHF2, 0);
				INT BloodClanHF2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][55] + V_MonsterUnit[D2CLIENT_GetDifficulty()][815];
				V_PlayerInfoTextStrR8 = V_MonsterStr[55] + KilledStr + AddCommas(BloodClanHF2, 0);
				INT DarkArcherHF2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][162] + V_MonsterUnit[D2CLIENT_GetDifficulty()][816];
				V_PlayerInfoTextStrR9 = V_MonsterStr[162] + KilledStr + AddCommas(DarkArcherHF2, 0);
				INT DarkStalkerHF2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][45] + V_MonsterUnit[D2CLIENT_GetDifficulty()][817];
				V_PlayerInfoTextStrR10 = V_MonsterStr[45] + KilledStr + AddCommas(DarkStalkerHF2, 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[65] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][65], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[167] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][167], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[171] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][171], 0);
				INT Returned = V_MonsterUnit[D2CLIENT_GetDifficulty()][383] + V_MonsterUnit[D2CLIENT_GetDifficulty()][387] + V_MonsterUnit[D2CLIENT_GetDifficulty()][379] + V_MonsterUnit[D2CLIENT_GetDifficulty()][274];
				V_PlayerInfoTextStrR14 = V_MonsterStr[383] + KilledStr + AddCommas(Returned, 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[2] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][2], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[13] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][13], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[25] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][25], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[46] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][46], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[60] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][60], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[66] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][66], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[57] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][57], 0);
			}
			if (iSelectedPage == 3)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[172] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][172], 0);
				INT Bone = V_MonsterUnit[D2CLIENT_GetDifficulty()][384] + V_MonsterUnit[D2CLIENT_GetDifficulty()][380] + V_MonsterUnit[D2CLIENT_GetDifficulty()][388] + V_MonsterUnit[D2CLIENT_GetDifficulty()][275];
				V_PlayerInfoTextStrR2 = V_MonsterStr[384] + KilledStr + AddCommas(Bone, 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[22] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][22], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[39] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][39], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[163] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][163], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[11] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][11], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[61] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][61], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[141] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][141], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[122] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][122], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[7] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][7], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[10] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][10], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[135] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][135], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[391] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][391], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[365] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][365], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[402] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][402], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[156] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][156], 0);
				V_PlayerInfoTextStrR17 = "";
				V_PlayerInfoTextStrR18 = "";
				V_PlayerInfoTextStrR19 = "";
				V_PlayerInfoTextStrR20 = "";
				V_PlayerInfoTextStrR21 = "";
			}
		}

		//Act 2
		if (iInfoId == 2)
		{
			V_PlayerInfoTextPages = 3;

			if (iSelectedPage == 1)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[3] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][3], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[29] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][29], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[96] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][96], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[173] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][173], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[83] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][83], 0);
				INT BurningDead = V_MonsterUnit[D2CLIENT_GetDifficulty()][385] + V_MonsterUnit[D2CLIENT_GetDifficulty()][389] + V_MonsterUnit[D2CLIENT_GetDifficulty()][276];
				V_PlayerInfoTextStrR6 = V_MonsterStr[385] + KilledStr + AddCommas(BurningDead, 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[78] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][78], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[91] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][91], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[110] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][110], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[373] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][373], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[4] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][4], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[79] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][79], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[84] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][84], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[111] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][111], 0);
				INT SpearCats = V_MonsterUnit[D2CLIENT_GetDifficulty()][374] + V_MonsterUnit[D2CLIENT_GetDifficulty()][394];
				V_PlayerInfoTextStrR15 = V_MonsterStr[394] + KilledStr + AddCommas(SpearCats, 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[97] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][97], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[101] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][101], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[136] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][136], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[17] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][17], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[208] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][208], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[68] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][68], 0);

			}
			if (iSelectedPage == 2)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[87] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][87], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[92] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][92], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[69] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][69], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[88] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][88], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[93] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][93], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[9] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][9], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[30] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][30], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[80] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][80], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[85] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][85], 0);
				INT NightSlinger = V_MonsterUnit[D2CLIENT_GetDifficulty()][395] + V_MonsterUnit[D2CLIENT_GetDifficulty()][375];
				V_PlayerInfoTextStrR10 = V_MonsterStr[395] + KilledStr + AddCommas(NightSlinger, 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[31] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][31], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[98] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][98], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[74] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][74], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[75] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][75], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[102] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][102], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[48] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][48], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[174] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][174], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[186] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][186], 0);
				INT Horrors = V_MonsterUnit[D2CLIENT_GetDifficulty()][386] + V_MonsterUnit[D2CLIENT_GetDifficulty()][382] + V_MonsterUnit[D2CLIENT_GetDifficulty()][390] + V_MonsterUnit[D2CLIENT_GetDifficulty()][277];
				V_PlayerInfoTextStrR19 = V_MonsterStr[386] + KilledStr + AddCommas(Horrors, 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[40] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][40], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[56] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][56], 0);
			}
			if (iSelectedPage == 3)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[131] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][131], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[41] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][41], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[94] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][94], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[99] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][99], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[103] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][103], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[187] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][187], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[229] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][229], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[284] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][284], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[250] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][250], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[211] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][211], 0);
				V_PlayerInfoTextStrR11 = "";
				V_PlayerInfoTextStrR12 = "";
				V_PlayerInfoTextStrR13 = "";
				V_PlayerInfoTextStrR14 = "";
				V_PlayerInfoTextStrR15 = "";
				V_PlayerInfoTextStrR16 = "";
				V_PlayerInfoTextStrR17 = "";
				V_PlayerInfoTextStrR18 = "";
				V_PlayerInfoTextStrR19 = "";
				V_PlayerInfoTextStrR20 = "";
				V_PlayerInfoTextStrR21 = "";
			}
		}

		//Act 3
		if (iInfoId == 3)
		{
			V_PlayerInfoTextPages = 3;

			if (iSelectedPage == 1)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[50] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][50], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[114] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][114], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[127] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][127], 0);
				INT Fetishes = V_MonsterUnit[D2CLIENT_GetDifficulty()][142] + V_MonsterUnit[D2CLIENT_GetDifficulty()][397];
				V_PlayerInfoTextStrR4 = V_MonsterStr[142] + KilledStr + AddCommas(Fetishes, 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[18] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][18], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[124] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][124], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[125] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][125], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[137] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][137], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[71] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][71], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[247] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][247], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[248] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][248], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[128] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][128], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[8] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][8], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[279] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][279], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[118] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][118], 0);
				INT Flayers = V_MonsterUnit[D2CLIENT_GetDifficulty()][143] + V_MonsterUnit[D2CLIENT_GetDifficulty()][398];
				V_PlayerInfoTextStrR16 = V_MonsterStr[143] + KilledStr + AddCommas(Flayers, 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[280] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][280], 0);
				INT SoulKillers = V_MonsterUnit[D2CLIENT_GetDifficulty()][144] + V_MonsterUnit[D2CLIENT_GetDifficulty()][399];
				V_PlayerInfoTextStrR18 = V_MonsterStr[144] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][144], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[281] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][281], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[113] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][113], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[249] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][249], 0);
			}
			if (iSelectedPage == 2)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[215] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][215], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[216] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][216], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[138] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][138], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[42] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][42], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[214] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][214], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[51] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][51], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[81] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][81], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[112] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][112], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[235] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][235], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[129] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][129], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[90] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][90], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[236] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][236], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[238] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][238], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[27] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][27], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[237] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][237], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[239] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][239], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[77] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][77], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[95] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][95], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[139] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][139], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[164] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][164], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[32] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][32], 0);

			}
			if (iSelectedPage == 3)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[52] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][52], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[240] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][240], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[132] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][132], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[100] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][100], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[133] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][133], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[188] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][188], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[134] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][134], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[261] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][261], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[262] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][262], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[263] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][263], 0);
				INT Council = V_MonsterUnit[D2CLIENT_GetDifficulty()][345] + V_MonsterUnit[D2CLIENT_GetDifficulty()][346] + V_MonsterUnit[D2CLIENT_GetDifficulty()][347];
				V_PlayerInfoTextStrR11 = V_MonsterStr[345] + KilledStr + AddCommas(Council, 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[242] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][242], 0);
				V_PlayerInfoTextStrR13 = "";
				V_PlayerInfoTextStrR14 = "";
				V_PlayerInfoTextStrR15 = "";
				V_PlayerInfoTextStrR16 = "";
				V_PlayerInfoTextStrR17 = "";
				V_PlayerInfoTextStrR18 = "";
				V_PlayerInfoTextStrR19 = "";
				V_PlayerInfoTextStrR20 = "";
				V_PlayerInfoTextStrR21 = "";
			}
		}

		//Act 4
		if (iInfoId == 4)
		{
			V_PlayerInfoTextPages = 2;

			if (iSelectedPage == 1)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[82] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][82], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[298] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][298], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[304] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][304], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[307] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][307], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[310] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][310], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[360] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][360], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[362] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][362], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[120] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][120], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[14] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][14], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[140] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][140], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[299] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][299], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[305] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][305], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[308] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][308], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[311] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][311], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[361] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][361], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[72] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][72], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[189] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][189], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[300] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][300], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[309] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][309], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[306] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][306], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[312] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][312], 0);
			}
			if (iSelectedPage == 2)
			{
				INT Souls = V_MonsterUnit[D2CLIENT_GetDifficulty()][403] + V_MonsterUnit[D2CLIENT_GetDifficulty()][404];
				V_PlayerInfoTextStrR1 = V_MonsterStr[403] + KilledStr + AddCommas(Souls, 0);
				INT Glass = V_MonsterUnit[D2CLIENT_GetDifficulty()][392] + V_MonsterUnit[D2CLIENT_GetDifficulty()][393];
				V_PlayerInfoTextStrR2 = V_MonsterStr[392] + KilledStr + AddCommas(Glass, 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[256] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][256], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[409] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][409], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[243] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][243], 0);
				V_PlayerInfoTextStrR6 = "";
				V_PlayerInfoTextStrR7 = "";
				V_PlayerInfoTextStrR8 = "";
				V_PlayerInfoTextStrR9 = "";
				V_PlayerInfoTextStrR10 = "";
				V_PlayerInfoTextStrR11 = "";
				V_PlayerInfoTextStrR12 = "";
				V_PlayerInfoTextStrR13 = "";
				V_PlayerInfoTextStrR14 = "";
				V_PlayerInfoTextStrR15 = "";
				V_PlayerInfoTextStrR16 = "";
				V_PlayerInfoTextStrR17 = "";
				V_PlayerInfoTextStrR18 = "";
				V_PlayerInfoTextStrR19 = "";
				V_PlayerInfoTextStrR20 = "";
				V_PlayerInfoTextStrR21 = "";
			}
		}

		//Act 5
		if (iInfoId == 5)
		{
			V_PlayerInfoTextPages = 8;

			if (iSelectedPage == 1)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[453] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][453], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[529] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][529], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[442] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][442], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[480] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][480], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[501] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][501], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[471] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][471], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[447] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][447], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[473] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][473], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[436] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][436], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[531] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][531], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[437] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][437], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[502] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][502], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[446] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][446], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[470] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][470], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[503] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][503], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[449] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][449], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[438] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][438], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[507] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][507], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[530] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][530], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[546] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][546], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[458] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][458], 0);
			}
			if (iSelectedPage == 2)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[547] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][547], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[508] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][508], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[493] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][493], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[455] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][455], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[481] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][481], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[440] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][440], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[510] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][510], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[496] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][496], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[549] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][549], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[476] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][476], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[479] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][479], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[443] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][443], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[528] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][528], 0);
				INT Catapults = V_MonsterUnit[D2CLIENT_GetDifficulty()][516] + V_MonsterUnit[D2CLIENT_GetDifficulty()][517] + V_MonsterUnit[D2CLIENT_GetDifficulty()][518] + V_MonsterUnit[D2CLIENT_GetDifficulty()][519];
				V_PlayerInfoTextStrR14 = V_MonsterStr[516] + KilledStr + AddCommas(Catapults, 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[575] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][575], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[605] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][605], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[590] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][590], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[608] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][608], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[609] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][609], 0);
				INT Slinger2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][610] + V_MonsterUnit[D2CLIENT_GetDifficulty()][611] + V_MonsterUnit[D2CLIENT_GetDifficulty()][612];
				V_PlayerInfoTextStrR20 = V_MonsterStr[610] + KilledStr + AddCommas(Slinger2, 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[441] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][441], 0);
			}
			if (iSelectedPage == 3)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[613] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][613], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[615] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][615], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[618] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][618], 0);
				INT Returned2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][620] + V_MonsterUnit[D2CLIENT_GetDifficulty()][622];
				V_PlayerInfoTextStrR4 = V_MonsterStr[620] + KilledStr + AddCommas(Returned2, 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[586] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][586], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[642] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][642], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[645] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][645], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[600] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][600], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[629] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][629], 0);
				INT Bone3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][624] + V_MonsterUnit[D2CLIENT_GetDifficulty()][729];
				V_PlayerInfoTextStrR10 = V_MonsterStr[624] + KilledStr + AddCommas(Bone3, 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[631] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][631], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[594] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][594], 0);
				INT Succubus = V_MonsterUnit[D2CLIENT_GetDifficulty()][634] + V_MonsterUnit[D2CLIENT_GetDifficulty()][469];
				V_PlayerInfoTextStrR13 = V_MonsterStr[634] + KilledStr + AddCommas(Succubus, 0);
				INT Dominus = V_MonsterUnit[D2CLIENT_GetDifficulty()][636] + V_MonsterUnit[D2CLIENT_GetDifficulty()][474];
				V_PlayerInfoTextStrR14 = V_MonsterStr[636] + KilledStr + AddCommas(Dominus, 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[639] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][639], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[616] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][616], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[648] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][648], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[632] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][632], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[650] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][650], 0);
				INT Lords = V_MonsterUnit[D2CLIENT_GetDifficulty()][652] + V_MonsterUnit[D2CLIENT_GetDifficulty()][506];
				V_PlayerInfoTextStrR20 = V_MonsterStr[652] + KilledStr + AddCommas(Lords, 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[595] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][595], 0);
			}
			if (iSelectedPage == 4)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[580] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][580], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[532] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][532], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[576] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][576], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[589] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][589], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[628] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][628], 0);
				INT Lords2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][653] + V_MonsterUnit[D2CLIENT_GetDifficulty()][509];
				V_PlayerInfoTextStrR6 = V_MonsterStr[653] + KilledStr + AddCommas(Lords2, 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[606] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][606], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[533] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][533], 0);
				INT Skeleton3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][725] + V_MonsterUnit[D2CLIENT_GetDifficulty()][649];
				V_PlayerInfoTextStrR9 = V_MonsterStr[725] + KilledStr + AddCommas(Skeleton3, 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[630] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][630], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[643] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][643], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[646] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][646], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[654] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][654], 0);
				INT Flayer2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][656] + V_MonsterUnit[D2CLIENT_GetDifficulty()][659];
				V_PlayerInfoTextStrR14 = V_MonsterStr[656] + KilledStr + AddCommas(Flayer2, 0);
				INT Horrors2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][623] + V_MonsterUnit[D2CLIENT_GetDifficulty()][625] + V_MonsterUnit[D2CLIENT_GetDifficulty()][626] + V_MonsterUnit[D2CLIENT_GetDifficulty()][728] + V_MonsterUnit[D2CLIENT_GetDifficulty()][730];
				V_PlayerInfoTextStrR15 = V_MonsterStr[623] + KilledStr + AddCommas(Horrors2, 0);
				INT Baboons = V_MonsterUnit[D2CLIENT_GetDifficulty()][665] + V_MonsterUnit[D2CLIENT_GetDifficulty()][666];
				V_PlayerInfoTextStrR16 = V_MonsterStr[665] + KilledStr + AddCommas(Baboons, 0);
				INT Heirophant = V_MonsterUnit[D2CLIENT_GetDifficulty()][673] + V_MonsterUnit[D2CLIENT_GetDifficulty()][674];
				V_PlayerInfoTextStrR17 = V_MonsterStr[673] + KilledStr + AddCommas(Heirophant, 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[588] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][588], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[607] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][607], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[667] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][667], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[675] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][675], 0);
			}
			if (iSelectedPage == 5)
			{
				INT Minion2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][682] + V_MonsterUnit[D2CLIENT_GetDifficulty()][454];
				V_PlayerInfoTextStrR1 = V_MonsterStr[682] + KilledStr + AddCommas(Minion2, 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[578] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][578], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[662] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][662], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[295] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][295], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[597] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][597], 0);
				INT Imp = V_MonsterUnit[D2CLIENT_GetDifficulty()][688] + V_MonsterUnit[D2CLIENT_GetDifficulty()][492];
				V_PlayerInfoTextStrR6 = V_MonsterStr[688] + KilledStr + AddCommas(Imp, 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[686] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][686], 0);
				INT Witches = V_MonsterUnit[D2CLIENT_GetDifficulty()][637] + V_MonsterUnit[D2CLIENT_GetDifficulty()][478];
				V_PlayerInfoTextStrR8 = V_MonsterStr[637] + KilledStr + AddCommas(Witches, 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[644] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][644], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[647] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][647], 0);
				INT Archers4 = V_MonsterUnit[D2CLIENT_GetDifficulty()][726] + V_MonsterUnit[D2CLIENT_GetDifficulty()][579];
				V_PlayerInfoTextStrR11 = V_MonsterStr[726] + KilledStr + AddCommas(Archers4, 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[690] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][690], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[692] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][692], 0);
				INT Minion3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][683] + V_MonsterUnit[D2CLIENT_GetDifficulty()][457];
				V_PlayerInfoTextStrR14 = V_MonsterStr[683] + KilledStr + AddCommas(Minion3, 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[596] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][596], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[619] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][619], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[668] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][668], 0);
				INT BurningDead3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][621] + V_MonsterUnit[D2CLIENT_GetDifficulty()][727];
				V_PlayerInfoTextStrR18 = V_MonsterStr[621] + KilledStr + AddCommas(BurningDead3, 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[587] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][587], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[694] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][694], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[456] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][456], 0);
			}
			if (iSelectedPage == 6)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[482] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][482], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[695] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][695], 0);
				INT Dolls = V_MonsterUnit[D2CLIENT_GetDifficulty()][657] + V_MonsterUnit[D2CLIENT_GetDifficulty()][660];
				V_PlayerInfoTextStrR3 = V_MonsterStr[657] + KilledStr + AddCommas(Dolls, 0);
				INT UnholyCorpse = V_MonsterUnit[D2CLIENT_GetDifficulty()][698] + V_MonsterUnit[D2CLIENT_GetDifficulty()][439];
				V_PlayerInfoTextStrR4 = V_MonsterStr[698] + KilledStr + AddCommas(UnholyCorpse, 0);
				INT Knights2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][699] + V_MonsterUnit[D2CLIENT_GetDifficulty()][700];
				V_PlayerInfoTextStrR5 = V_MonsterStr[699] + KilledStr + AddCommas(Knights2, 0);
				INT Knights3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][701] + V_MonsterUnit[D2CLIENT_GetDifficulty()][702] + V_MonsterUnit[D2CLIENT_GetDifficulty()][713];
				V_PlayerInfoTextStrR6 = V_MonsterStr[701] + KilledStr + AddCommas(Knights3, 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[602] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][602], 0);
				INT Black3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][723] + V_MonsterUnit[D2CLIENT_GetDifficulty()][617];
				V_PlayerInfoTextStrR8 = V_MonsterStr[723] + KilledStr + AddCommas(Black3, 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[676] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][676], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[696] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][696], 0);
				INT SoulKillers2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][658] + V_MonsterUnit[D2CLIENT_GetDifficulty()][661];
				V_PlayerInfoTextStrR11 = V_MonsterStr[658] + KilledStr + AddCommas(SoulKillers2, 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[664] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][664], 0);
				INT Minion4 = V_MonsterUnit[D2CLIENT_GetDifficulty()][684] + V_MonsterUnit[D2CLIENT_GetDifficulty()][459];
				V_PlayerInfoTextStrR13 = V_MonsterStr[684] + KilledStr + AddCommas(Minion4, 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[651] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][651], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[598] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][598], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[703] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][703], 0);
				INT Horadrim = V_MonsterUnit[D2CLIENT_GetDifficulty()][669] + V_MonsterUnit[D2CLIENT_GetDifficulty()][670];
				V_PlayerInfoTextStrR17 = V_MonsterStr[669] + KilledStr + AddCommas(Horadrim, 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[640] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][640], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[693] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][693], 0);
				INT Ghost3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][633] + V_MonsterUnit[D2CLIENT_GetDifficulty()][732];
				V_PlayerInfoTextStrR20 = V_MonsterStr[633] + KilledStr + AddCommas(Ghost3, 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[691] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][691], 0);
			}
			if (iSelectedPage == 7)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[603] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][603], 0);
				INT Souls3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][641] + V_MonsterUnit[D2CLIENT_GetDifficulty()][733];
				V_PlayerInfoTextStrR2 = V_MonsterStr[641] + KilledStr + AddCommas(Souls3, 0);
				INT Vampire3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][697] + V_MonsterUnit[D2CLIENT_GetDifficulty()][731];
				V_PlayerInfoTextStrR3 = V_MonsterStr[697] + KilledStr + AddCommas(Vampire3, 0);
				INT Witches3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][719] + V_MonsterUnit[D2CLIENT_GetDifficulty()][635] + V_MonsterUnit[D2CLIENT_GetDifficulty()][472];
				V_PlayerInfoTextStrR4 = V_MonsterStr[719] + KilledStr + AddCommas(Witches3, 0);
				INT Witches4 = V_MonsterUnit[D2CLIENT_GetDifficulty()][720] + V_MonsterUnit[D2CLIENT_GetDifficulty()][638] + V_MonsterUnit[D2CLIENT_GetDifficulty()][475];
				V_PlayerInfoTextStrR5 = V_MonsterStr[719] + KilledStr + AddCommas(Witches4, 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[721] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][721], 0);
				INT Archers2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][722] + V_MonsterUnit[D2CLIENT_GetDifficulty()][614];
				V_PlayerInfoTextStrR7 = V_MonsterStr[722] + KilledStr + AddCommas(Archers2, 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[715] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][715], 0);
				INT Maggots2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][716] + V_MonsterUnit[D2CLIENT_GetDifficulty()][679];
				V_PlayerInfoTextStrR9 = V_MonsterStr[716] + KilledStr + AddCommas(Maggots2, 0);
				INT Arach2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][717] + V_MonsterUnit[D2CLIENT_GetDifficulty()][685];
				V_PlayerInfoTextStrR10 = V_MonsterStr[717] + KilledStr + AddCommas(Arach2, 0);
				INT Scarab2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][718] + V_MonsterUnit[D2CLIENT_GetDifficulty()][655];
				V_PlayerInfoTextStrR11 = V_MonsterStr[718] + KilledStr + AddCommas(Scarab2, 0);
				INT Overseer2 = V_MonsterUnit[D2CLIENT_GetDifficulty()][724] + V_MonsterUnit[D2CLIENT_GetDifficulty()][483];
				V_PlayerInfoTextStrR12 = V_MonsterStr[724] + KilledStr + AddCommas(Overseer2, 0);
				INT PitLords = V_MonsterUnit[D2CLIENT_GetDifficulty()][712] + V_MonsterUnit[D2CLIENT_GetDifficulty()][687];
				V_PlayerInfoTextStrR13 = V_MonsterStr[712] + KilledStr + AddCommas(PitLords, 0);
				INT Imp3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][714] + V_MonsterUnit[D2CLIENT_GetDifficulty()][689] + V_MonsterUnit[D2CLIENT_GetDifficulty()][495];
				V_PlayerInfoTextStrR14 = V_MonsterStr[714] + KilledStr + AddCommas(Imp3, 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[494] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][494], 0);
				INT Door3 = V_MonsterUnit[D2CLIENT_GetDifficulty()][432] + V_MonsterUnit[D2CLIENT_GetDifficulty()][433];
				V_PlayerInfoTextStrR16 = V_MonsterStr[432] + KilledStr + AddCommas(Door3, 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[434] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][434], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[435] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][435], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[23] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][23], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[62] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][62], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[105] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][105], 0);
			}
			if (iSelectedPage == 8)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[381] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][381], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[557] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][557], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[558] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][558], 0);
				INT Minion = V_MonsterUnit[D2CLIENT_GetDifficulty()][571] + V_MonsterUnit[D2CLIENT_GetDifficulty()][572] + V_MonsterUnit[D2CLIENT_GetDifficulty()][573];
				V_PlayerInfoTextStrR4 = V_MonsterStr[571] + KilledStr + AddCommas(Minion, 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[526] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][526], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[540] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][540], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[541] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][541], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[542] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][542], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[544] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][544], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[704] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][704], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[705] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][705], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[706] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][706], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[707] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][707], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[708] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][708], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[709] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][709], 0);
				V_PlayerInfoTextStrR16 = "";
				V_PlayerInfoTextStrR17 = "";
				V_PlayerInfoTextStrR18 = "";
				V_PlayerInfoTextStrR19 = "";
				V_PlayerInfoTextStrR20 = "";
				V_PlayerInfoTextStrR21 = "";
			}
		}

		//Act 6
		if (iInfoId == 6)
		{
			V_PlayerInfoTextPages = 1;

			if (iSelectedPage == 1)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[740] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][740], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[738] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][738], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[741] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][741], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[739] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][739], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[737] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][737], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[736] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][736], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[734] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][734], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[735] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][735], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[742] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][742], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[744] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][744], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[745] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][745], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[746] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][746], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[747] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][747], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[748] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][748], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[749] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][749], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[750] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][750], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[751] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][751], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[810] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][810], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[811] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][811], 0);
				V_PlayerInfoTextStrR20 = "";
				V_PlayerInfoTextStrR21 = "";
			}
		}

		//Act 7
		if (iInfoId == 7)
		{
			V_PlayerInfoTextPages = 3;

			if (iSelectedPage == 1)
			{
				INT Fallen = V_MonsterUnit[D2CLIENT_GetDifficulty()][753] + V_MonsterUnit[D2CLIENT_GetDifficulty()][754];
				V_PlayerInfoTextStrR1 = V_MonsterStr[753] + KilledStr + AddCommas(Fallen, 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[767] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][767], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[780] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][780], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[786] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][786], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[773] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][773], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[769] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][769], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[776] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][776], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[775] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][775], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[759] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][759], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[791] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][791], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[795] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][795], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[801] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][801], 0);
				INT Goatman = V_MonsterUnit[D2CLIENT_GetDifficulty()][755] + V_MonsterUnit[D2CLIENT_GetDifficulty()][781];
				V_PlayerInfoTextStrR13 = V_MonsterStr[755] + KilledStr + AddCommas(Goatman, 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[752] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][752], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[785] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][785], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[790] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][790], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[770] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][770], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[758] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][758], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[803] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][803], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[804] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][804], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[764] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][764], 0);
			}
			if (iSelectedPage == 2)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[762] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][762], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[793] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][793], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[768] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][768], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[784] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][784], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[765] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][765], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[783] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][783], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[792] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][792], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[794] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][794], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[807] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][807], 0);
				V_PlayerInfoTextStrR10 = V_MonsterStr[796] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][796], 0);
				V_PlayerInfoTextStrR11 = V_MonsterStr[774] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][774], 0);
				V_PlayerInfoTextStrR12 = V_MonsterStr[805] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][805], 0);
				V_PlayerInfoTextStrR13 = V_MonsterStr[772] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][772], 0);
				V_PlayerInfoTextStrR14 = V_MonsterStr[799] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][799], 0);
				V_PlayerInfoTextStrR15 = V_MonsterStr[800] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][800], 0);
				V_PlayerInfoTextStrR16 = V_MonsterStr[771] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][771], 0);
				V_PlayerInfoTextStrR17 = V_MonsterStr[779] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][779], 0);
				V_PlayerInfoTextStrR18 = V_MonsterStr[806] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][806], 0);
				V_PlayerInfoTextStrR19 = V_MonsterStr[808] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][808], 0);
				V_PlayerInfoTextStrR20 = V_MonsterStr[743] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][743], 0);
				V_PlayerInfoTextStrR21 = V_MonsterStr[809] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][809], 0);
			}
			if (iSelectedPage == 3)
			{
				V_PlayerInfoTextStrR1 = V_MonsterStr[802] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][802], 0);
				V_PlayerInfoTextStrR2 = V_MonsterStr[813] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][813], 0);
				V_PlayerInfoTextStrR3 = V_MonsterStr[814] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][814], 0);
				V_PlayerInfoTextStrR4 = V_MonsterStr[815] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][815], 0);
				V_PlayerInfoTextStrR5 = V_MonsterStr[816] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][816], 0);
				V_PlayerInfoTextStrR6 = V_MonsterStr[817] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][817], 0);
				V_PlayerInfoTextStrR7 = V_MonsterStr[818] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][818], 0);
				V_PlayerInfoTextStrR8 = V_MonsterStr[819] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][819], 0);
				V_PlayerInfoTextStrR9 = V_MonsterStr[820] + KilledStr + AddCommas(V_MonsterUnit[D2CLIENT_GetDifficulty()][820], 0);
				V_PlayerInfoTextStrR10 = "";
				V_PlayerInfoTextStrR11 = "";
				V_PlayerInfoTextStrR12 = "";
				V_PlayerInfoTextStrR13 = "";
				V_PlayerInfoTextStrR14 = "";
				V_PlayerInfoTextStrR15 = "";
				V_PlayerInfoTextStrR16 = "";
				V_PlayerInfoTextStrR17 = "";
				V_PlayerInfoTextStrR18 = "";
				V_PlayerInfoTextStrR19 = "";
				V_PlayerInfoTextStrR20 = "";
				V_PlayerInfoTextStrR21 = "";
			}
		}
	}

	strcpy(V_PlayerInfoText1, V_PlayerInfoTextStrR1.c_str());
	strcpy(V_PlayerInfoText2, V_PlayerInfoTextStrR2.c_str());
	strcpy(V_PlayerInfoText3, V_PlayerInfoTextStrR3.c_str());
	strcpy(V_PlayerInfoText4, V_PlayerInfoTextStrR4.c_str());
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
	strcpy(V_PlayerInfoText20, V_PlayerInfoTextStrR20.c_str());
	strcpy(V_PlayerInfoText21, V_PlayerInfoTextStrR21.c_str());
}
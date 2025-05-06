#include "Hack.h"
#include "Vars.h"

BOOL GodmodeSet(){
	//Print(0, 4, "ÿc4Godmode:ÿc0 Pick up any item from your ÿc1inventoryÿc0 and a ÿc;Full Rejuvinationÿc0 potion from your ÿc1beltÿc0.");
	Print(0, 4, "ÿc4Godmode:ÿc0 Pick up your hat from your ÿc1equipmentÿc0 and a ÿc;Full Rejuvinationÿc0 potion from your ÿc1beltÿc0.");
	Print(0, 4, "ÿc4Godmode:ÿc0 Also click the ÿc1NPCÿc0 you want to use for 'ÿc4.god buyÿc0'.");
	
	V_CSet = TRUE;

	return TRUE;
}

BOOL GodmodeStart(){
	if ((V_ICopied == TRUE) && (V_PCopied == TRUE))
	{
		Print(0, 4, "ÿc4Godmode:ÿc0 Godmode activated!");
		V_GMOn = TRUE;
	}
	else
	{
		Print(0, 4, "ÿc4Godmode:ÿc0 Please type 'ÿc5.god setÿc0' and pick up the full rejuv from your belt and item from your inventory first.");
	}

	return TRUE;
}

BOOL GodmodeStop(){
	Print(0, 4, "ÿc4Godmode:ÿc0 All flags disabled.");
	V_GMOn = FALSE;

	return TRUE;
}

BOOL GodmodeHeal(){
	if ((V_ICopied == TRUE) && (V_PCopied == TRUE))
	{
		INT Length = 9;
		LPBYTE Packet = new BYTE[Length];
		Packet[0] = 0x27;
		*(LPDWORD)&Packet[1] = V_Heal[1];
		*(LPDWORD)&Packet[5] = V_Heal[5];

		D2NET_SendPacket(Length, 1, Packet);

		delete [] Packet;

		Print(0, 4, "ÿc4Godmode:ÿc0 Healed.");
	}
	else
	{
		Print(0, 4, "ÿc4Godmode:ÿc0 Please type 'ÿc5.god setÿc0' and pick up the full rejuv from your belt and item from your inventory first.");
	}

	return TRUE;
}

BOOL GodmodeBuy(){
	if (V_NPCCopied == TRUE)
	{
		Print(0, 4, "ÿc4Godmode:ÿc0 Health purchased.");

		INT Length = 5;
		LPBYTE Packet = new BYTE[Length];
		Packet[0] = 0x39;
		*(LPDWORD)&Packet[1] = V_BuyHeal[1];

		D2NET_SendPacket(Length, 1, Packet);

		delete [] Packet;
	}

	return TRUE;
}
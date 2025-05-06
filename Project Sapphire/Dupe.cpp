#include "Hack.h"

BOOL DupeOpenGate(){
	LPUNITANY Cursor = D2CLIENT_GetCursorItem();
	V_A5Gate = GetUnitGate();

	if(!Cursor)
	{
		Print(0, 4, "ÿc4Duplicator:ÿc0 Pick an item up and type 'ÿc5.dupe send 44ÿc0' again...");

		return FALSE;
	}
	if(!V_A5Gate)
	{
		Print(0, 4, "ÿc4Duplicator:ÿc0 Move closer to the gate and type 'ÿc5.dupe send 44ÿc0' again...");

		return FALSE;
	}

	Print(0, 4, "ÿc4Duplicator:ÿc0 Gate open, now enter trade and type 'ÿc5.dupe send 31ÿc0'.");

	INT Length = 17;
	LPBYTE Packet = new BYTE[Length];
	Packet[0] = 0x44;
	*(LPDWORD)&Packet[1] = 0x02;
	*(LPDWORD)&Packet[5] = V_A5Gate->dwUnitId;
	*(LPDWORD)&Packet[9] = Cursor->dwUnitId;
	*(LPDWORD)&Packet[13] = 0x03;

	D2NET_SendPacket(17, 1, Packet);

	delete [] Packet;

	return TRUE;
}

BOOL DupeMoveNPC(){
	Print(0, 4, "ÿc4Duplicator:ÿc0 NPC moved, type 'ÿc5.dupe receive 77ÿc0' to close trade window.");

	INT Length = 9;
	LPBYTE Packet = new BYTE[Length];
	Packet[0] = 0x31;
	Packet[1] = 0xFF;
	Packet[2] = 0xFF;
	Packet[3] = 0xFF;
	Packet[4] = 0xFF;
	Packet[5] = 0xA3;
	Packet[6] = 0x4E;
	*(LPWORD)&Packet[7] = 0x00;

	D2NET_SendPacket(Length, 1, Packet);

	delete [] Packet;

	return TRUE;
}

BOOL DupeCloseTrade(){
	Print(0, 4, "ÿc4Duplicator:ÿc0 All done, drop your items and cancel trade to dupe.");

	INT Length = 2;
	LPBYTE Packet = new BYTE[Length];
	Packet[0] = 0x77;
	Packet[1] = 0x0C;

	D2NET_ReceivePacket(Packet, Length);

	delete [] Packet;

	V_DupeComplete = TRUE;

	return TRUE;
}

LPUNITANY GetUnitGate(){
	for (LPROOM1 Room = Me->pAct->pRoom1; Room; Room = Room->pRoomNext)
	{
		for (LPUNITANY Unit = Room->pUnitFirst; Unit; Unit = Unit->pListNext)
		{
			if (Unit && Unit->dwType == UNIT_TYPE_OBJECT)
			{
				if (Unit->dwTxtFileNo == 449)
				{
					return Unit;
				}
			}
		}
	}

	return FALSE;
}

LPUNITANY GetUnitWaypoint() {

	Print(0, 0, "ÿc4Duplicator:ÿc0 Activating waypoint.");

	V_ActiveWP = GetWaypoint();

	if (!V_ActiveWP)
	{
		Print(0, 1, "ÿc1Waypoint not found, get closer and try again.");

		V_BusyThread = FALSE;
		DestroyThread(GetCurrentThread(), NULL, INFINITE);
		while (TRUE) SleepEx(1, TRUE);
	}

	Interact(V_ActiveWP->dwUnitId, UNIT_TYPE_OBJECT, TRUE);

	return FALSE;
}

BOOL DupeInteractWP(DWORD ID, DWORD Type, BOOL Check)
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
	delete[] Packet;
	return TRUE;
}
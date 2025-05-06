#include "Hack.h"

BOOL MoveToQueue(WORD X, WORD Y)
{
	if (!ClientReady(TRUE))
		return FALSE;

	BOOL HaveTele;	

	if(X == Me->pPath->xPos && Y == Me->pPath->yPos) 
	{ 
		return TRUE; 
	}
	
	if(InTown(Me) || GetSkill(D2S_TELEPORT) == NULL || V_Direction > 0) 
	{ 
		HaveTele = FALSE; 
	}
	else 
	{ 
		HaveTele = TRUE; 
	}

    if (HaveTele && CalculateDistance(Me->pPath->xPos, Me->pPath->yPos, X, Y) < 30) {// houstin add
        return Teleport(X, Y);
	}
	
	if(HaveTele == FALSE)
	{
		WalkToQueue(X, Y); // get walking path
	}
	else if(HaveTele == TRUE)
	{
		TeleportToQueue(X, Y); // get walking path
	}

	if (V_TeleportQueue.IsEmpty())
	{
		//Print(0, 1, "There are no nodes to teleport to");

		return FALSE;
	}

	V_TeleportQueue.Lock();
	while (!V_TeleportQueue.IsEmpty())
	{
		if(HaveTele == TRUE)
		{
			TeleportTo((WORD)V_TeleportQueue[0].x, (WORD)V_TeleportQueue[0].y);

			V_TeleportQueue.RemoveAt(0);
			V_TeleportQueue.FreeExtra();
		}
		else if(HaveTele == FALSE)
		{
			WalkTo((DWORD)V_TeleportQueue[0].x, (DWORD)V_TeleportQueue[0].y);
			
			V_TeleportQueue.RemoveAt(0);	
			V_TeleportQueue.FreeExtra();
		}
		SleepEx(1, TRUE);
	}
	V_TeleportQueue.RemoveAll();
	V_TeleportQueue.Unlock();
	
	return TRUE;
}

BOOL WalkToQueue(WORD X1, WORD Y1)
{
	if (!ClientReady(TRUE))
		return FALSE;

	if (V_TeleportQueue.IsLocked || !V_TeleportQueue.IsEmpty())
		return FALSE;

	V_FarcastTeleportMemory = V_FarcastTeleport;

	if(V_FarcastTeleport)
		V_FarcastTeleport = FALSE;

	V_WalkingActive = TRUE;

	POINT Start, End, PaTh[200] = {0};
	INT Count = 0;
	CMatrix<WORD, WORD> Map;
	CPathFinder TeleportPaTh;

	V_Reveal->CreateCollisionMap();
	V_Reveal->ExportCollisionMap(Map);

	V_LevelX = GetUnitLevel(Me)->dwPosX * 5;
	V_LevelY = GetUnitLevel(Me)->dwPosY * 5;

	Start.x = Me->pPath->xPos - V_LevelX;
	Start.y = Me->pPath->yPos - V_LevelY;

	if (!Map.IsValidIndex(Start.x, Start.y))
	{
		//Print(0, 1, "Failed to generate path, starting point is not a valid index.");
		V_FarcastTeleport = V_FarcastTeleportMemory;
		V_WalkingActive = FALSE;
		return FALSE;
	}

	End.x = X1 - V_LevelX;
	End.y = Y1 - V_LevelY;

	if (!Map.IsValidIndex((INT)End.x, (INT)End.y))
	{
		//Print(0, 1, "Failed to generate path, ending point is not a valid index.");
		V_FarcastTeleport = V_FarcastTeleportMemory;
		V_WalkingActive = FALSE;
		return FALSE;
	}

	TeleportPaTh.SetPathingMap(Map.GetData(), Map.GetCX(), Map.GetCY());
	Count = TeleportPaTh.CreateBestPath(Start, End, PaTh, 200);

	if (!Count)
	{
		//Print(0, 1, "Failed to generate path, could not generate any nodes.");
		V_FarcastTeleport = V_FarcastTeleportMemory;
		V_WalkingActive = FALSE;
		return FALSE;
	}

	for (INT i = 1; i < Count; i++)
	{
		PaTh[i].x += V_LevelX;
		PaTh[i].y += V_LevelY;

		V_TeleportQueue.Add(PaTh[i]);
	}

	V_FarcastTeleport = V_FarcastTeleportMemory;
	V_WalkingActive = FALSE;

	return TRUE;
}

BOOL TeleportToQueue(WORD X1, WORD Y1)
{
	if (!ClientReady(TRUE) || InTown(Me))
		return FALSE;

	if (V_TeleportQueue.IsLocked || !V_TeleportQueue.IsEmpty())
		return FALSE;

	if (V_LegitMode && !V_GMMode)
		return FALSE;

	V_CurrentVector = NULL;

	POINT Start, End, PaTh[200] = {0};
	INT Count = 0;
	CMatrix<WORD, WORD> Map;
	CPathFinder TeleportPaTh;

	V_Reveal->CreateCollisionMap();
	V_Reveal->ExportCollisionMap(Map);

	V_LevelX = GetUnitLevel(Me)->dwPosX * 5;
	V_LevelY = GetUnitLevel(Me)->dwPosY * 5;

	Start.x = Me->pPath->xPos - V_LevelX;
	Start.y = Me->pPath->yPos - V_LevelY;
	
	if (!Map.IsValidIndex(Start.x, Start.y))
	{
		//Print(0, 1, "Failed to generate path, starting point is not a valid index.");
		return FALSE;
	}

	End.x = X1 - V_LevelX;
	End.y = Y1 - V_LevelY;

	if (!Map.IsValidIndex((INT)End.x, (INT)End.y))
	{
		//Print(0, 1, "Failed to generate path, ending point is not a valid index.");
		return FALSE;
	}

	TeleportPaTh.SetPathingMap(Map.GetData(), Map.GetCX(), Map.GetCY());
	Count = TeleportPaTh.CreateBestPath(Start, End, PaTh, 200);

	if (!Count)
	{
		//Print(0, 1, "Failed to generate path, could not generate any nodes.");
		return FALSE;
	}

	for (INT i = 1; i < Count; i++)
	{
		PaTh[i].x += V_LevelX;
		PaTh[i].y += V_LevelY;

		V_TeleportQueue.Add(PaTh[i]);
	}

	return TRUE;
}

BOOL WalkTo(DWORD X, DWORD Y)
{
	if (!ClientReady(TRUE))
		return FALSE;

	DWORD nTimer;
	INT attemptCount = 0;
	INT nFail = 0;

	INT v1 = rand() % 6 + 1;
	INT v2 = rand() % 6 + 1;
	INT WalkingOffset = v1 - v2;

	WalkingOffset = 0; //Turn off offset

	if(X < 1)
		return TRUE;

	if(Y < 1)
		return TRUE;

	V_LevelX = GetUnitLevel(Me)->dwPosX * 5;
	V_LevelY = GetUnitLevel(Me)->dwPosY * 5;

	while (CalculateDistance((LONG)Me->pPath->xPos - V_LevelX, (LONG)Me->pPath->yPos - V_LevelY, (LONG)X - V_LevelX, (LONG)Y - V_LevelY) > 3) 
	{
		ClickMap(CLICK_LDOWN, (DWORD)X + WalkingOffset, (DWORD)Y + WalkingOffset, SHIFT_NONE, NULL);
		SleepEx(40, TRUE);
		ClickMap(CLICK_LUP, (DWORD)X + WalkingOffset, (DWORD)Y + WalkingOffset, SHIFT_NONE, NULL);
		
		attemptCount += 1;
		nTimer = GetTickCount();
				
		while (Me->dwMode != 2 && Me->dwMode != 3 && Me->dwMode != 6) 
		{
			if ((GetTickCount() - nTimer) > 500) 
			{
				nFail++;
				
				if (nFail == 2) 
				{
					//Print(0, 1, "Failed to reach node.");

					return FALSE;
				}
				
				ClickMap(CLICK_LDOWN, (DWORD)X + WalkingOffset, (DWORD)Y + WalkingOffset, SHIFT_NONE, NULL);
				SleepEx(40, TRUE);
				ClickMap(CLICK_LUP, (DWORD)X + WalkingOffset, (DWORD)Y + WalkingOffset, SHIFT_NONE, NULL);
			}
		}
			
		while (Me->dwMode != 1 && Me->dwMode != 5 && Me->dwMode != 17) {
			SleepEx(1, TRUE);
		}
		
		if (attemptCount >= 3) 
		{
			//Print(0, 1, "Failed to reach node.");

			return FALSE;
		}
	}

	return TRUE;
}

BOOL TeleportTo(WORD X, WORD Y)
{
	if (!ClientReady(TRUE))
		return FALSE;

	if(X < 1)
		return TRUE;

	if(Y < 1)
		return TRUE;

	INT Iterations = 0;
	BOOL Arrived = FALSE;

	if (GetCurrentSkill(V_LeftAttack) != D2S_TELEPORT)
		SetSkill(D2S_TELEPORT, V_LeftAttack);

	while (GetCurrentSkill(V_LeftAttack) != D2S_TELEPORT)
		SleepEx(1, TRUE);

	LPBYTE Packet = new BYTE[5];
	Packet[0] = V_LeftAttack ? 0x05 : 0x0C;
	*(LPWORD)&Packet[1] = X;
	*(LPWORD)&Packet[3] = Y;
	D2NET_SendPacket(5, 1, Packet);
	delete [] Packet;

	while (Iterations < 1000)
	{
		V_LevelX = GetUnitLevel(Me)->dwPosX * 5;
		V_LevelY = GetUnitLevel(Me)->dwPosY * 5;

		if (!ClientReady(TRUE) || InTown(Me) || V_TeleportQueue.IsEmpty())
			break;

		if (CalculateDistance((LONG)Me->pPath->xPos - V_LevelX, (LONG)Me->pPath->yPos - V_LevelY, (LONG)X - V_LevelX, (LONG)Y - V_LevelX) <= 5)
		{
			Arrived = TRUE;
			break;
		}

		Iterations++;
		SleepEx(1, TRUE);
	}

	if (!Arrived)
	{
		Print(0, 1, "Failed to reach target, terminating teleport sequence.");

		return FALSE;
	}

	return TRUE;
}

LPUNITANY GetWaypoint()
{
	DWORD WP [] = {119, 145, 156, 157, 237, 238, 288, 323, 324, 398, 402, 429, 494, 496, 511, 539};

	for (LPROOM1 Room = Me->pAct->pRoom1; Room; Room = Room->pRoomNext)
	{
		for (LPUNITANY Unit = Room->pUnitFirst; Unit; Unit = Unit->pListNext)
		{
			if (Unit && Unit->dwType == UNIT_TYPE_OBJECT)
			{
				for (INT i = 0; i < ArraySize(WP); i++)
				{
					if (Unit->dwTxtFileNo == WP[i])
					{
						return Unit;
					}
				}
			}
		}
	}

	return FALSE;
}

BOOL GetPortalspotA1()
{
	for (LPROOM1 Room = Me->pAct->pRoom1; Room; Room = Room->pRoomNext)
	{
		for (LPUNITANY Unit = Room->pUnitFirst; Unit; Unit = Unit->pListNext)
		{
			if (Unit && Unit->dwType == UNIT_TYPE_OBJECT)
			{
				if (Unit->dwTxtFileNo == 39)
				{
					WORD FireX = Unit->pPath->xTarget;
					WORD FireY = Unit->pPath->yTarget;

					V_Portalspot[0] = FireX+10;
					V_Portalspot[1] = FireY+18;

					return TRUE;
				}
			}
		}
	}

	Print(0, 1, "ÿc1Campfire not found.");

	return FALSE;
}

/*
function GetLeader(name) {
	_party = GetPlayerUnit();
	
	if (_party) {
		do {
			if (_party.name === name) {
				return _party;
			}
		} while (_party.GetNext());
	}
	
	return false;
}

function GetLeaderUnit(name) {
	var _unit = NTC_FindUnit(NTC_UNIT_PLAYER);
	
	if (_unit) {
		do {
			if (_unit.name === name) {
				return _unit;
			}
		} while (_unit.GetNext());
	}
	
	return false;
}


function CheckLeaderAct(leader) {
	if (leader.areaid <= 39) {
		return 1;
	} else if(leader.areaid >= 40 && leader.areaid <= 74) {
		return 2;
	} else if(leader.areaid >= 75 && leader.areaid <= 102) {
		return 3;
	} else if(leader.areaid >= 103 && leader.areaid <= 108) {
		return 4;
	}
	
	return 5;
}



function CheckExit(leader, area) {
	var _unit = GetPresetUnits(me.areaid, NTC_UNIT_TILE);
	
	if (_unit) {
		for (var i = 0; i < _unit.length; i += 1) {
			if (_unit[i].subareaid === area) {
				return 1;
			}
		}
	}
	
	_unit = NTC_FindUnit(NTC_UNIT_OBJECT, GetLocaleString(3226));
	
	if (_unit) {
		do {
			if (_unit.subareaid === area || _unit.subareaid === area + 256 || _unit.subareaid === area + 768) {
				return 2;
			}
		} while (_unit.GetNext());
	}
	
	if (NTC_InTown(leader)) {
		_unit = NTM_GetWaypointInt();
		
		if (_unit) {
			return 3;
		}
	}
	
	if((me.areaid === 74 && area === 54 || me.areaid === 54 && area === 74)) { // arcane portal
		NTM_TakeUnit(NTC_UNIT_OBJECT, 298);
		return 4;
	}
	
	if (me.areaid >= 66 && me.areaid <= 72 && area === 73) { // duriel's wall
		NTM_TakeUnit(NTC_UNIT_OBJECT, 100);
		return 4;
	}
	
	/*if (me.areaid === 92 && area === 93) {	// kurast sewers
		???
	}*/
	
/*
	if (me.areaid === 131 && area === 132) { // throne of destruction
		NTM_TakeUnit(NTC_UNIT_OBJECT, 563);
		return 4;
	}
	
	return 0;
}
*/
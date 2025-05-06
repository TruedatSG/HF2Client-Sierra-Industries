#include "Hack.h"

BOOL ClickMap(DWORD dwClickType, INT wX, INT wY, BOOL bShift, LPUNITANY pUnit)
{
	if (!ClientReady(TRUE))
		return FALSE;

	POINT Click = {wX, wY};
	if(pUnit)
	{
		Click.x = D2CLIENT_GetUnitX(pUnit);
		Click.y = D2CLIENT_GetUnitY(pUnit);
	}

	D2COMMON_MapToAbsScreen(&Click.x, &Click.y);

	Click.x -= *p_D2CLIENT_ViewportX;
	Click.y -= *p_D2CLIENT_ViewportY;

	POINT OldMouse = {0, 0};
	OldMouse.x = *p_D2CLIENT_MouseX;
	OldMouse.y = *p_D2CLIENT_MouseY;
	*p_D2CLIENT_MouseX = 0;
	*p_D2CLIENT_MouseY = 0;

	if(pUnit && pUnit != D2CLIENT_GetPlayerUnit())
	{
		V_SelectedUnitId = pUnit->dwUnitId;
		V_SelectedUnitType = pUnit->dwType;

		V_ClickAction = TRUE;
		
		D2CLIENT_ClickMap(dwClickType, Click.x, Click.y, bShift ? 0x0C : (*p_D2CLIENT_AlwaysRun ? 0x08 : 0));
		D2CLIENT_SetSelectedUnit_I(NULL);

		V_ClickAction = FALSE;
		V_SelectedUnitId = NULL;
		V_SelectedUnitType = NULL;
	}
	else
	{
		V_SelectedUnitId = NULL;
		V_SelectedUnitType = NULL;

		V_ClickAction = TRUE;
		D2CLIENT_ClickMap(dwClickType, Click.x, Click.y, bShift ? 0x0C : (*p_D2CLIENT_AlwaysRun ? 0x08 : 0));
		V_ClickAction = FALSE;
	}

	*p_D2CLIENT_MouseX = OldMouse.x;
	*p_D2CLIENT_MouseY = OldMouse.y;

	return TRUE;
}

/*
function FL_Say(msg) {
	if (Follower_Messages) {
		Say(msg);
	}
	
	return true;
}
*/

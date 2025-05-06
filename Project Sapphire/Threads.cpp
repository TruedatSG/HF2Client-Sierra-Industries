#include "Hack.h"
#include <boost/lexical_cast.hpp>

static LPLEVEL CurrentLevel;

static BOOL DeathCounted;
static BOOL LoadingNotice;
static BOOL MarkedPosition;
static BOOL MarkedArea;

static INT aSize;
static INT mPosX;
static INT mPosY;
static INT pPosX;
static INT pPosY;
static INT rDistX;
static INT rDistY;
static INT pArea;
static INT mArea;
static INT mMin;

static INT mIdleSec;
static INT mIdleMin;

static INT TotalGold;

static BOOL BUSY = TRUE;
static BOOL REMPATCH = TRUE;

static BOOL AIStop = false;
static BOOL AIPortalSpot = false;

static CXBOXController* Player1;

static BOOL releasedLClick = TRUE;
static BOOL releasedRClick = TRUE;
static BOOL releasedAlt = TRUE;
static BOOL releasedShift = TRUE;

static BOOL holdAlt = FALSE;
static BOOL unholdAlt = FALSE;

static BOOL DeathCountedLadder = FALSE;

static INT mLife;

static BOOL CloseMenu = FALSE;

static BOOL XinputLoaded = FALSE;
static BOOL XinputNotice = TRUE;

BOOL STDCALL Threads(LPVOID Parameter)
{
	INT Thread = (INT)Parameter;

	switch (Thread)
	{
	case REGISTRY:

		SleepEx(DELAYLOAD, TRUE);

		while(BUSY == TRUE)
		{
			SleepEx(DELAYAD, TRUE);

			V_RegistryNotice++;

			if(V_Registered && V_RegistryNotice <= 5)
			{
				V_RegistryNotice = 4;

				break;
			}

			if(!V_Registered && V_RegistryNotice == 4)
			{
				V_RegistryNotice = 0;
			}
		}

		break;

	case PRIMARY:

		while (TRUE)
		{
			SleepEx(50, TRUE);

			if (Me && !V_Game)
				Game(FALSE);
			else if (!Me && V_Game)
				Game(TRUE);

			if (REMPATCH == TRUE && (OOG_GetLocation() == OOG_MAIN_MENU || OOG_GetLocation() == OOG_LOBBY))
			{
				GamePatch(FALSE);

				REMPATCH = FALSE;
			}

			if (!ClientReady(FALSE))
				continue;

			REMPATCH = TRUE;

			if (V_DelayedChicken)
			{
				SleepEx(500, TRUE);
				V_DelayedChicken = FALSE;
			}

			if (V_DeathMessageIteration)
			{
				V_DeathMessageIteration = FALSE;
				DeathMessage();
			}
		}

		break;

	case SECONDARY:

		SleepEx(3000, TRUE);

		break;

	case DELAYCLICK:

		SleepEx(MENUCLICKDELAY, TRUE);

		V_ClickDelay = FALSE;

		break;

	case IGNORECLICK:

		while(TRUE)
		{
			SleepEx(100, TRUE);

#ifdef MODWINDOW
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(D2GFX_GetHwnd(), &p);

			/* Borderless Window Design
			if(!isFullscreen(D2GFX_GetHwnd()))
			{
				LONG lStyle = GetWindowLong(D2GFX_GetHwnd(), GWL_STYLE);
				lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU);
				SetWindowLong(D2GFX_GetHwnd(), GWL_STYLE, lStyle);

				RECT rc;

				HWND hwndParent = GetDesktopWindow();
				GetClientRect(hwndParent, &rc);


				MoveWindow(
					D2GFX_GetHwnd(),
					(rc.right - rc.left - 800) / 2,
					(rc.bottom - rc.top - 600) / 2,
					800,
					600,
					TRUE
				);
			}
			*/
			if(IsWindowVisible(D2GFX_GetHwnd()))
			{
				/* Extra Stuff - don't need this with launcher lite
				if(OOG_GetLocation() == OOG_CHARACTER_CREATE)
				{
					if ((p.x >= 1 && p.x <= 599) && (p.y >= 1 && p.y <= 799))
					{
						V_UnhookClick = TRUE;
					}
					else
					{
						V_UnhookClick = FALSE;
					}
					if ((p.x >= 34 && p.x <= 160) && (p.y >= 535 && p.y <= 572))
					{
						V_UnhookClick = FALSE;
					}
				}
				if (OOG_GetLocation() == OOG_CHAR_SELECT)
				{
					if ((p.x >= 32 && p.x <= 600) && (p.y >= 468 && p.y <= 534))
					{
						V_UnhookClick = TRUE;
					}
					else
					{
						V_UnhookClick = FALSE;
					}
				}
				*/
				if(OOG_GetLocation() == OOG_MAIN_MENU)
				{
					if ((p.x >= 266 && p.x <= 532) && (p.y >= 324 && p.y <= 396))
					{
						V_UnhookClick = TRUE;
					}
					else
					{
						V_UnhookClick = FALSE;
					}
				}
			}
#endif
		}

		break;

	case LOBBYDELAY:

		while(TRUE)
		{
			while(!V_InGame)
			{
				if (!V_ClickDelay)
				{
					if ((GetKeyState(VK_LBUTTON) & 0x100) != 0 || (GetKeyState(VK_RBUTTON) & 0x100) != 0)
					{
						V_ClickDelay = TRUE;

						V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));

						if(IsWindowVisible(D2GFX_GetHwnd()))
						{
							V_UnhookClick = TRUE;

							SleepEx(DELAYLOBBY, TRUE);

							V_UnhookClick = FALSE;
						}
					}
				}
				SleepEx(LOOPDELAY, TRUE);
			}
			SleepEx(50, TRUE);
		}

		break;

	case MOVEKEYS:

#ifdef DIRECTIONALINPUT
		while(TRUE)
		{
			if(GetUIVar(UI_CHAT))
				continue;

			V_Direction = 0;

			if(GetKeyState('W') & 0x8000 && GetKeyState('A') & 0x8000)
			{
				V_Direction = DIRECTION_NWEST;
				MoveToQueue(Me->pPath->xPos - 6, Me->pPath->yPos);

				continue;
			}
			if(GetKeyState('S') & 0x8000 && GetKeyState('D') & 0x8000)
			{
				V_Direction = DIRECTION_SEAST;
				MoveToQueue(Me->pPath->xPos + 6, Me->pPath->yPos);

				continue;
			}
			if(GetKeyState('S') & 0x8000 && GetKeyState('A') & 0x8000)
			{
				V_Direction = DIRECTION_SWEST;
				MoveToQueue(Me->pPath->xPos, Me->pPath->yPos + 6);

				continue;
			}
			if(GetKeyState('W') & 0x8000 && GetKeyState('D') & 0x8000)
			{
				V_Direction = DIRECTION_NEAST;
				MoveToQueue(Me->pPath->xPos, Me->pPath->yPos - 6);

				continue;
			}
			if(GetKeyState('W') & 0x8000)
			{
				V_Direction = DIRECTION_NORTH;
				MoveToQueue(Me->pPath->xPos - 6, Me->pPath->yPos - 6);

				continue;
			}
			if(GetKeyState('S') & 0x8000)
			{
				V_Direction = DIRECTION_SOUTH;
				MoveToQueue(Me->pPath->xPos + 6, Me->pPath->yPos + 6);

				continue;
			}
			if(GetKeyState('A') & 0x8000)
			{
				V_Direction = DIRECTION_WEST;
				MoveToQueue(Me->pPath->xPos - 4, Me->pPath->yPos + 6);

				continue;
			}
			if(GetKeyState('D') & 0x8000)
			{
				V_Direction = DIRECTION_EAST;
				MoveToQueue(Me->pPath->xPos + 4, Me->pPath->yPos - 6);

				continue;
			}

			SleepEx(1, TRUE);
		}
#endif

		break;

	case MOVEPAD:

#ifdef XINPUT

		while (true)
		{
			//V_MultiPlayerMode = 0; // Override config
			if(V_MultiPlayerMode == 0)
			{
				if (!XinputLoaded)
				{
					Player1 = new CXBOXController(1);

					if (Player1->IsConnected())
					{
						XinputLoaded = TRUE;
						XinputNotice = FALSE;
					}
				}

				if (Player1->IsConnected())
				{
					if (IsWindowVisible(D2GFX_GetHwnd()))
					{
						POINT p = { 0 };
						GetCursorPos(&p);

						SHORT PointerTravel = POINTERDIST;

						//Joy 1
						float rightThumbX = Player1->GetState().Gamepad.sThumbRX;
						float rightThumbY = Player1->GetState().Gamepad.sThumbRY;

						//Joy 2
						float leftThumbX = Player1->GetState().Gamepad.sThumbLX;
						float leftThumbY = Player1->GetState().Gamepad.sThumbLY;

						//Loop Checks
						if (unholdAlt == TRUE)
						{
							INPUT Inputs[1] = { 0 };

							// Complete a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Release the "Alt" key
							Inputs[0].ki.wVk = 18; // virtual-key code for the "Alt" key
							Inputs[0].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press

							SendInput(1, Inputs, sizeof(INPUT));

							releasedAlt = TRUE;
							holdAlt = FALSE;
							unholdAlt = FALSE;

							Sleep(BUTTONDELAY);
						}

						//Combo Buttons
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
						{
						}
						else
						{
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X)
						{
						}
						else
						{
						}

						/* Old skill buttons
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
						{
							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
						{
							Sleep(BUTTONDELAY);

							continue;
						}
						*/

						// Number keys / Belt
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbX < -16384)
						{
							//5
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "5" key
							Inputs[0].ki.wVk = 53; // virtual-key code for the "5" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "5" key
							Inputs[1].ki.wVk = 53; // virtual-key code for the "5" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbX > 16383)
						{
							//6
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "6" key
							Inputs[0].ki.wVk = 54; // virtual-key code for the "6" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "6" key
							Inputs[1].ki.wVk = 54; // virtual-key code for the "6" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbY < -16384)
						{
							//7
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "7" key
							Inputs[0].ki.wVk = 55; // virtual-key code for the "7" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "7" key
							Inputs[1].ki.wVk = 55; // virtual-key code for the "7" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbY > 16383)
						{
							//8
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "8" key
							Inputs[0].ki.wVk = 56; // virtual-key code for the "8" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "8" key
							Inputs[1].ki.wVk = 56; // virtual-key code for the "8" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbX < -16384)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "G" key
							Inputs[0].ki.wVk = 71; // virtual-key code for the "G" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "G" key
							Inputs[1].ki.wVk = 71; // virtual-key code for the "G" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbX > 16383)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "U" key
							Inputs[0].ki.wVk = 85; // virtual-key code for the "U" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "U" key
							Inputs[1].ki.wVk = 85; // virtual-key code for the "U" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbY < -16384)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "X" key
							Inputs[0].ki.wVk = 88; // virtual-key code for the "X" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "X" key
							Inputs[1].ki.wVk = 88; // virtual-key code for the "X" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && rightThumbY > 16383)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Space" key
							Inputs[0].ki.wVk = 32; // virtual-key code for the "Space" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Space" key
							Inputs[1].ki.wVk = 32; // virtual-key code for the "Space" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}

						// Number keys / Belt
						if (rightThumbX < -16384)
						{
							//1
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "1" key
							Inputs[0].ki.wVk = 49; // virtual-key code for the "1" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "1" key
							Inputs[1].ki.wVk = 49; // virtual-key code for the "1" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (rightThumbX > 16383)
						{
							//2
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "2" key
							Inputs[0].ki.wVk = 50; // virtual-key code for the "2" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "2" key
							Inputs[1].ki.wVk = 50; // virtual-key code for the "2" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (rightThumbY < -16384)
						{
							//3
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "3" key
							Inputs[0].ki.wVk = 51; // virtual-key code for the "3" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "3" key
							Inputs[1].ki.wVk = 51; // virtual-key code for the "3" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (rightThumbY > 16383)
						{
							//4
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "4" key
							Inputs[0].ki.wVk = 52; // virtual-key code for the "4" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "4" key
							Inputs[1].ki.wVk = 52; // virtual-key code for the "4" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if ((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) && (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER))
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "9" key
							Inputs[0].ki.wVk = 57; // virtual-key code for the "9" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "9" key
							Inputs[1].ki.wVk = 57; // virtual-key code for the "9" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						/* Don't really need this in expansion
						if ((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) && !(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER))
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "`" key
							Inputs[0].ki.wVk = 192; // virtual-key code for the "`" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "`" key
							Inputs[1].ki.wVk = 192; // virtual-key code for the "`" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						*/
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
						{
							if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
							{
								INPUT Inputs[2] = { 0 };

								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Alt" key
								Inputs[0].ki.wVk = 18; // virtual-key code for the "Alt" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								Sleep(25);

								// Complete a generic keyboard event.
								Inputs[1].type = INPUT_KEYBOARD;
								Inputs[1].ki.wScan = 0; // hardware scan code for key
								Inputs[1].ki.time = 0;
								Inputs[1].ki.dwExtraInfo = 0;

								// Press the "Esc" key
								Inputs[1].ki.wVk = 27; // virtual-key code for the "Esc" key
								Inputs[1].ki.dwFlags = 0; // 0 for key press

								SendInput(2, Inputs, sizeof(INPUT));

								Sleep(25);

								INPUT Inputs2[1] = { 0 };

								// Set up a generic keyboard event.
								Inputs2[0].type = INPUT_KEYBOARD;
								Inputs2[0].ki.wScan = 0; // hardware scan code for key
								Inputs2[0].ki.time = 0;
								Inputs2[0].ki.dwExtraInfo = 0;

								// Release the "Esc" key
								Inputs2[0].ki.wVk = 27; // virtual-key code for the "Tab" key
								Inputs2[0].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press

								// Complete a generic keyboard event.
								Inputs2[1].type = INPUT_KEYBOARD;
								Inputs2[1].ki.wScan = 0; // hardware scan code for key
								Inputs2[1].ki.time = 0;
								Inputs2[1].ki.dwExtraInfo = 0;

								// Release the "Alt" key
								Inputs2[1].ki.wVk = 18; // virtual-key code for the "Alt" key
								Inputs2[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
								SendInput(2, Inputs2, sizeof(INPUT));

								Sleep(BUTTONDELAY);

								continue;
							}
							INPUT Inputs[1] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Alt" key
							Inputs[0].ki.wVk = 18; // virtual-key code for the "Alt" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							SendInput(1, Inputs, sizeof(INPUT));

							releasedAlt = FALSE;
						}
						else
						{
							if (releasedAlt == FALSE)
							{
								INPUT Inputs[1] = { 0 };

								// Complete a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Release the "Alt" key
								Inputs[0].ki.wVk = 18; // virtual-key code for the "Alt" key
								Inputs[0].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press

								SendInput(1, Inputs, sizeof(INPUT));

								Sleep(BUTTONDELAY); // Need a release delay here

								releasedAlt = TRUE;
								if (holdAlt == TRUE)
								{
									holdAlt = FALSE;
								}
							}
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "O" key
							Inputs[0].ki.wVk = 79; // virtual-key code for the "O" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "O" key
							Inputs[1].ki.wVk = 79; // virtual-key code for the "O" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "W" key
							Inputs[0].ki.wVk = 87; // virtual-key code for the "W" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "W" key
							Inputs[1].ki.wVk = 87; // virtual-key code for the "W" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if ((Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && holdAlt == FALSE)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "P" key
							Inputs[0].ki.wVk = 80; // virtual-key code for the "P" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "P" key
							Inputs[1].ki.wVk = 80; // virtual-key code for the "P" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}

						//Buttons
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START)
						{
							//New configuration for arrows to speed up input
							if ((!(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && leftThumbY > 16383) && holdAlt == FALSE)
							{
								INPUT Inputs[2] = { 0 };
								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Up Arrow" key
								Inputs[0].ki.wVk = 38; // virtual-key code for the "Up Arrow" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								Sleep(3);

								// Complete a generic keyboard event.
								Inputs[1].type = INPUT_KEYBOARD;
								Inputs[1].ki.wScan = 0; // hardware scan code for key
								Inputs[1].ki.time = 0;
								Inputs[1].ki.dwExtraInfo = 0;

								// Release the "Up Arrow" key
								Inputs[1].ki.wVk = 38; // virtual-key code for the "Up Arrow" key
								Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
								SendInput(2, Inputs, sizeof(INPUT));

								Sleep(3);

								continue;
							}
							if ((!(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && leftThumbY < -16384) && holdAlt == FALSE)
							{
								INPUT Inputs[2] = { 0 };

								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Down Arrow" key
								Inputs[0].ki.wVk = 40; // virtual-key code for the "Down Arrow" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								Sleep(3);

								// Complete a generic keyboard event.
								Inputs[1].type = INPUT_KEYBOARD;
								Inputs[1].ki.wScan = 0; // hardware scan code for key
								Inputs[1].ki.time = 0;
								Inputs[1].ki.dwExtraInfo = 0;

								// Release the "Down Arrow" key
								Inputs[1].ki.wVk = 40; // virtual-key code for the "Down Arrow" key
								Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
								SendInput(2, Inputs, sizeof(INPUT));

								Sleep(3);

								continue;
							}
							if (holdAlt == FALSE)
							{
								INPUT Inputs[1] = { 0 };

								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Alt" key
								Inputs[0].ki.wVk = 18; // virtual-key code for the "Alt" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								SendInput(1, Inputs, sizeof(INPUT));

								holdAlt = TRUE;

								Sleep(BUTTONDELAY);
							}
							else if (holdAlt == TRUE)
							{
								INPUT Inputs[1] = { 0 };

								// Complete a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Release the "Alt" key
								Inputs[0].ki.wVk = 18; // virtual-key code for the "Alt" key
								Inputs[0].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press

								SendInput(1, Inputs, sizeof(INPUT));

								releasedAlt = TRUE;
								holdAlt = FALSE;

								Sleep(BUTTONDELAY);
							}
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
						{
							INPUT Inputs[1] = { 0 };

							Inputs[0].type = INPUT_MOUSE;
							Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

							SendInput(1, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							releasedLClick = FALSE;
						}
						else
						{
							if (releasedLClick == FALSE)
							{
								INPUT Inputs[1] = { 0 };

								Inputs[0].type = INPUT_MOUSE;
								Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;

								SendInput(1, Inputs, sizeof(INPUT));

								releasedLClick = TRUE;
							}
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X)
						{
							INPUT Inputs[1] = { 0 };

							Inputs[0].type = INPUT_MOUSE;
							Inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

							SendInput(1, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							releasedRClick = FALSE;
						}
						else
						{
							if (releasedRClick == FALSE)
							{
								INPUT Inputs[1] = { 0 };

								Inputs[0].type = INPUT_MOUSE;
								Inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

								SendInput(1, Inputs, sizeof(INPUT));

								releasedRClick = TRUE;
							}
						}

						//Expansion configuration for Y Button
						/*
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "W" key
							Inputs[0].ki.wVk = 87; // virtual-key code for the "W" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "W" key
							Inputs[1].ki.wVk = 87; // virtual-key code for the "W" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);
						}
						*/
						//New configuration for Y Button
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "R" key
							Inputs[0].ki.wVk = 82; // virtual-key code for the "R" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "R" key
							Inputs[1].ki.wVk = 82; // virtual-key code for the "R" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK && holdAlt == FALSE)
						{
							if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
							{
								continue;
							}

							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Tab" key
							Inputs[0].ki.wVk = 9; // virtual-key code for the "Tab" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Tab" key
							Inputs[1].ki.wVk = 9; // virtual-key code for the "Tab" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START)
						{
							Sleep(BUTTONDELAY);
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
						{
							if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
							{
								INPUT Inputs[1] = { 0 };

								// Complete a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Release the "Shift" key
								Inputs[0].ki.wVk = 16; // virtual-key code for the "Shift" key
								Inputs[0].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press

								SendInput(1, Inputs, sizeof(INPUT));
							}
							else
							{
								INPUT Inputs[1] = { 0 };

								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Shift" key
								Inputs[0].ki.wVk = 16; // virtual-key code for the "Shift" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								SendInput(1, Inputs, sizeof(INPUT));

								releasedShift = FALSE;
							}
						}
						else
						{
							if (releasedShift == FALSE)
							{
								INPUT Inputs[1] = { 0 };

								// Complete a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Release the "Shift" key
								Inputs[0].ki.wVk = 16; // virtual-key code for the "Shift" key
								Inputs[0].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press

								SendInput(1, Inputs, sizeof(INPUT));

								releasedShift = TRUE;
							}
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
						{
							if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER || holdAlt == TRUE)
							{
								unholdAlt = TRUE;

								continue;
							}
							if (V_ToggleMenu || V_ToggleStatMenu || V_ToggleInfoMenu || V_ToggleMissionMenu || V_ToggleAbilityMenu || V_ToggleGuideMenu || V_ToggleSettingMenu)
							{
								if (V_ToggleMenu != FALSE)
								{
									CloseMenu = TRUE;

									V_ToggleMenu = FALSE;
								}

								V_ToggleStatMenu = FALSE;
								V_ToggleInfoMenu = FALSE;
								V_ToggleMissionMenu = FALSE;
								V_ToggleAbilityMenu = FALSE;
								V_ToggleGuideMenu = FALSE;
								V_ToggleSettingMenu = FALSE;

								V_CharacterStats = FALSE;

								if (V_MenuObject != 0)
								{
									CloseMenu = TRUE;

									V_MenuObject = 0;
								}

								V_ClickIgnore = FALSE;

								V_PlayerInfoGroup = -1;

								ResetInfoMenu();

								V_SelectedCounterPage = 1;
								V_SelectedCounterPageText = 1;

								V_PlayerInfoListPages = 1;

								V_ClickIgnoreInfo2 = FALSE;

								V_SideQuestExpansion = -1;

								ResetQuestsMenu();
								ResetQuestsText();

								V_SelectedQuestPage = 1;
								V_SelectedQuestPageText = 1;

								V_SideQuestListPages = 1;

								V_ClickIgnoreMission2 = FALSE;
								V_ClickIgnoreAbility2 = FALSE;

								V_ClickIgnoreStat2 = FALSE;
								V_ClickIgnoreGuide2 = FALSE;

								D2CLIENT_PlaySound(STAND_PASS);

								/*
								if (*p_D2CLIENT_ScreenSizeX == 640)
								{
									SetCursorPos(320, 240);
								}
								else
								{
									SetCursorPos(400, 300);
								}
								*/

								continue;
							}

							/*
							if (*p_D2CLIENT_ScreenSizeX == 640)
							{
								SetCursorPos(320, 240);
							}
							else
							{
								SetCursorPos(400, 300);
							}
							*/

							INPUT Inputs[2] = { 0 };

							if (CloseMenu == TRUE)
							{
								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Backspace" key
								Inputs[0].ki.wVk = 8; // virtual-key code for the "Esc" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								// Complete a generic keyboard event.
								Inputs[1].type = INPUT_KEYBOARD;
								Inputs[1].ki.wScan = 0; // hardware scan code for key
								Inputs[1].ki.time = 0;
								Inputs[1].ki.dwExtraInfo = 0;

								// Release the "Backspace" key
								Inputs[1].ki.wVk = 8; // virtual-key code for the "Esc" key
								Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
								SendInput(2, Inputs, sizeof(INPUT));

								Sleep(BUTTONDELAY);

								CloseMenu = FALSE;
							}
							else
							{
								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Esc" key
								Inputs[0].ki.wVk = 27; // virtual-key code for the "Esc" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								// Complete a generic keyboard event.
								Inputs[1].type = INPUT_KEYBOARD;
								Inputs[1].ki.wScan = 0; // hardware scan code for key
								Inputs[1].ki.time = 0;
								Inputs[1].ki.dwExtraInfo = 0;

								// Release the "Esc" key
								Inputs[1].ki.wVk = 27; // virtual-key code for the "Esc" key
								Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
								SendInput(2, Inputs, sizeof(INPUT));

								Sleep(BUTTONDELAY);
							}
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
						{
							PointerTravel = POINTERDIST;
						}
						else
						{
							PointerTravel = POINTERDISTADD;
						}

						if (leftThumbX < -16384 && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "T" key
							Inputs[0].ki.wVk = 84; // virtual-key code for the "T" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "T" key
							Inputs[1].ki.wVk = 84; // virtual-key code for the "T" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (leftThumbX > 16383 && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "I" key
							Inputs[0].ki.wVk = 73; // virtual-key code for the "I" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "I" key
							Inputs[1].ki.wVk = 73; // virtual-key code for the "I" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (leftThumbY < -16384 && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "C" key
							Inputs[0].ki.wVk = 67; // virtual-key code for the "C" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "C" key
							Inputs[1].ki.wVk = 67; // virtual-key code for the "C" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (leftThumbY > 16383 && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Q" key
							Inputs[0].ki.wVk = 81; // virtual-key code for the "Q" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Q" key
							Inputs[1].ki.wVk = 81; // virtual-key code for the "Q" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (!(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && leftThumbY > 16383)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Up Arrow" key
							Inputs[0].ki.wVk = 38; // virtual-key code for the "Up Arrow" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							Sleep(50);

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Up Arrow" key
							Inputs[1].ki.wVk = 38; // virtual-key code for the "Up Arrow" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(50);

							continue;
						}
						if (!(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && leftThumbY < -16384)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Down Arrow" key
							Inputs[0].ki.wVk = 40; // virtual-key code for the "Down Arrow" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							Sleep(50);

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Down Arrow" key
							Inputs[1].ki.wVk = 40; // virtual-key code for the "Down Arrow" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(50);

							continue;
						}
						if (!(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && leftThumbX < -16384)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Left Arrow" key
							Inputs[0].ki.wVk = 37; // virtual-key code for the "Left Arrow" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							Sleep(50);

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Left Arrow" key
							Inputs[1].ki.wVk = 37; // virtual-key code for the "Left Arrow" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(50);

							continue;
						}
						if (!(Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) && leftThumbX > 16383)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Right Arrow" key
							Inputs[0].ki.wVk = 39; // virtual-key code for the "Right Arrow" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							Sleep(50);

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Right Arrow" key
							Inputs[1].ki.wVk = 39; // virtual-key code for the "Right Arrow" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(50);

							continue;
						}

						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && (leftThumbX < -15000 && leftThumbY < -15001))
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F6" key
							Inputs[0].ki.wVk = 117; // virtual-key code for the "F6" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F6" key
							Inputs[1].ki.wVk = 117; // virtual-key code for the "F6" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && (leftThumbX > 15000 && leftThumbY > 15001))
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F2" key
							Inputs[0].ki.wVk = 113; // virtual-key code for the "F2" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F2" key
							Inputs[1].ki.wVk = 113; // virtual-key code for the "F2" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && (leftThumbX < -15000 && leftThumbY > 15001))
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F8" key
							Inputs[0].ki.wVk = 119; // virtual-key code for the "F8" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F8" key
							Inputs[1].ki.wVk = 119; // virtual-key code for the "F8" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && (leftThumbX > 15000 && leftThumbY < -15001))
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F4" key
							Inputs[0].ki.wVk = 115; // virtual-key code for the "F4" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F4" key
							Inputs[1].ki.wVk = 115; // virtual-key code for the "F4" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && leftThumbY < -30000)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F5" key
							Inputs[0].ki.wVk = 116; // virtual-key code for the "F5" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F5" key
							Inputs[1].ki.wVk = 116; // virtual-key code for the "F5" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && leftThumbY > 30001)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F1" key
							Inputs[0].ki.wVk = 112; // virtual-key code for the "F1" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F1" key
							Inputs[1].ki.wVk = 112; // virtual-key code for the "F1" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && leftThumbX < -30000)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F7" key
							Inputs[0].ki.wVk = 118; // virtual-key code for the "F7" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F7" key
							Inputs[1].ki.wVk = 118; // virtual-key code for the "F7" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER && leftThumbX > 30001)
						{
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "F3" key
							Inputs[0].ki.wVk = 114; // virtual-key code for the "F3" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "F3" key
							Inputs[1].ki.wVk = 114; // virtual-key code for the "F3" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));

							Sleep(BUTTONDELAY);

							continue;
						}

						//Dpad
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
						{
							SetCursorPos(p.x - PointerTravel, p.y - PointerTravel);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
						{
							SetCursorPos(p.x + PointerTravel, p.y - PointerTravel);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
						{
							SetCursorPos(p.x - PointerTravel, p.y + PointerTravel);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN && Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
						{
							SetCursorPos(p.x + PointerTravel, p.y + PointerTravel);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
						{
							SetCursorPos(p.x, p.y - PointerTravel);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
						{
							SetCursorPos(p.x, p.y + PointerTravel);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
						{
							SetCursorPos(p.x - PointerTravel, p.y);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
						if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
						{
							SetCursorPos(p.x + PointerTravel, p.y);

							SleepEx(POINTERSPEED, TRUE);

							continue;
						}
					}
					else
					{
						XinputLoaded = FALSE;
						if (!XinputNotice)
						{
							Print(0, 1, "Error: Unable to locate XBOX One controller...");

							XinputNotice = TRUE;

							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Esc" key
							Inputs[0].ki.wVk = 27; // virtual-key code for the "Esc" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Esc" key
							Inputs[1].ki.wVk = 27; // virtual-key code for the "Esc" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));
						}
					}
					SleepEx(25, TRUE);
				}
				else
				{			
					XinputLoaded = FALSE;
					if (ClientReady(FALSE))
					{
						if (!XinputNotice)
						{
							Print(0, 8, "Debug: Unable to locate XBOX One controller...");

							XinputNotice = TRUE;

							if (GetUIVar(UI_CHAT))
							{
								INPUT Inputs[2] = { 0 };

								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Esc" key
								Inputs[0].ki.wVk = 27; // virtual-key code for the "Esc" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								// Complete a generic keyboard event.
								Inputs[1].type = INPUT_KEYBOARD;
								Inputs[1].ki.wScan = 0; // hardware scan code for key
								Inputs[1].ki.time = 0;
								Inputs[1].ki.dwExtraInfo = 0;

								// Release the "Esc" key
								Inputs[1].ki.wVk = 27; // virtual-key code for the "Esc" key
								Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
								SendInput(2, Inputs, sizeof(INPUT));
							}
							if (!V_Design->ClearScreen(3))
							{
								INPUT Inputs[2] = { 0 };

								// Set up a generic keyboard event.
								Inputs[0].type = INPUT_KEYBOARD;
								Inputs[0].ki.wScan = 0; // hardware scan code for key
								Inputs[0].ki.time = 0;
								Inputs[0].ki.dwExtraInfo = 0;

								// Press the "Esc" key
								Inputs[0].ki.wVk = 27; // virtual-key code for the "Esc" key
								Inputs[0].ki.dwFlags = 0; // 0 for key press

								// Complete a generic keyboard event.
								Inputs[1].type = INPUT_KEYBOARD;
								Inputs[1].ki.wScan = 0; // hardware scan code for key
								Inputs[1].ki.time = 0;
								Inputs[1].ki.dwExtraInfo = 0;

								// Release the "Esc" key
								Inputs[1].ki.wVk = 27; // virtual-key code for the "Esc" key
								Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
								SendInput(2, Inputs, sizeof(INPUT));

								SleepEx(125, TRUE);
							}
							INPUT Inputs[2] = { 0 };

							// Set up a generic keyboard event.
							Inputs[0].type = INPUT_KEYBOARD;
							Inputs[0].ki.wScan = 0; // hardware scan code for key
							Inputs[0].ki.time = 0;
							Inputs[0].ki.dwExtraInfo = 0;

							// Press the "Esc" key
							Inputs[0].ki.wVk = 27; // virtual-key code for the "Esc" key
							Inputs[0].ki.dwFlags = 0; // 0 for key press

							// Complete a generic keyboard event.
							Inputs[1].type = INPUT_KEYBOARD;
							Inputs[1].ki.wScan = 0; // hardware scan code for key
							Inputs[1].ki.time = 0;
							Inputs[1].ki.dwExtraInfo = 0;

							// Release the "Esc" key
							Inputs[1].ki.wVk = 27; // virtual-key code for the "Esc" key
							Inputs[1].ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
							SendInput(2, Inputs, sizeof(INPUT));
						}
					}
				}
			}
		}

#endif

		break;

	case VIBRATEPAD:

		while (TRUE)
		{
			SleepEx(LOOPDELAY, TRUE);

			if (!ClientReady(FALSE))
				continue;

			SleepEx(20, TRUE);

			//Vibrate Heartbeat
			if (V_QueueVibrateSoft == TRUE)
			{
				if (!ClientReady(FALSE))
					return FALSE;

				Player1->Vibrate(8192, 0);
				Sleep(100);
				Player1->Vibrate(0, 0);
				Sleep(100);
				Player1->Vibrate(8192, 0);
				Sleep(100);
				Player1->Vibrate(0, 0);

				V_QueueVibrateSoft = FALSE;
			}

			/*
			//Vibrate Rumble
			if (V_QueueVibrate == TRUE)
			{
				if (!ClientReady(FALSE))
					return FALSE;

				Player1->Vibrate(65535, 0);
				Sleep(3000);
				Player1->Vibrate(0, 0);

				V_QueueVibrate = FALSE;
			}
			*/
		}

		break;

	case VIBRATEPAD2:

		while (TRUE)
		{
			mLife = GetUnitStat(Me, STAT_HP);

			SleepEx(50, TRUE);

			//Detect Vibration
			if (GetUnitStat(Me, STAT_HP) < mLife)
			{
				V_QueueVibrateSoft = TRUE;
			}

			/*
			if (GetUnitState(Me, AFFECT_JUSTHIT))
			{
				V_QueueVibrate = TRUE;
			}
			*/
		}

		break;

	case KEYITEMS:

		while(TRUE)
		{
			SleepEx(SECONDSDELAY, TRUE);

#ifndef LAZARUSMOD
			LookForKeyItems();
#endif
		}

		break;

	case CLOSEMENU:

		SleepEx(MENUCLOSEDELAY, TRUE);

		switch(V_MenuObject)
		{
		case 0:

			break;

		case 1:

			V_ToggleStatMenu = TRUE;
			V_CharacterStats = TRUE;

			break;

		case 2:

			V_ToggleInfoMenu = TRUE;

			break;

		case 3:

			V_ToggleMissionMenu = TRUE;

			break;

		case 4:

			V_ToggleAbilityMenu = TRUE;

			break;

		case 5:

			V_ToggleGuideMenu = TRUE;

			break;

		case 6:

			V_ToggleSettingMenu = TRUE;

			break;
		}

		V_ToggleMenu = FALSE;

		SleepEx(250, TRUE);

		V_ClickIgnore = FALSE;
		V_ClickIgnoreMenu = FALSE;
		V_ClickIgnoreStat = FALSE;
		V_ClickIgnoreInfo = FALSE;
		V_ClickIgnoreMission = FALSE;
		V_ClickIgnoreAbility = FALSE;
		V_ClickIgnoreGuide = FALSE;
		V_ClickIgnoreCalc = FALSE;
		V_ClickIgnoreSetting = FALSE;

		V_ClickDelay = FALSE;

		break;

	case GETKEY:

		V_KeyReturn = (V_IDEntry + LOCKNUM) + THOBNUM;

		SleepEx(MESSAGEDELAY, TRUE);

		if(V_Registered == FALSE)
		{
			Print(0, 0, "Your ÿc2Key ÿc0is ÿc4%dÿc0. Type ÿc4@key <key>ÿc0 to activate.", V_KeyReturn);
		}
		else
		{
			Print(0, 0, "You already have your ÿc2Registration Papersÿc0.");
		}

		break;

	case CHECKKEY:

		SleepEx(MESSAGEDELAY, TRUE);

		if(V_Registered == TRUE)
		{
			Print(0, 0, "You already have your ÿc2Registration Papersÿc0.");

			break;
		}

		EnterCDKey(V_KeyEntry);

		if(V_Registered == TRUE)
		{
			Print(0, 2, "Your Key has been validated successfully.");
			SleepEx(MESSAGEDELAY, TRUE);
			Print(0, 8, "Note: Hellfire II won't be fully active until next time you join a game.");

			V_Key = V_KeyEntry;
			Save();
		}
		else
		{
			Print(0, 1, "Invalid Key.");
		}

		break;

	case COUNTER:

		aSize = 0;

		DeathCounted = FALSE;

		while (TRUE)
		{
			SleepEx(LOOPDELAY, TRUE);

			if (!ClientReady(FALSE))
				continue;

			//
			//Count Deaths
			LPUNITANY pMe = Me;
			if (InTown(Me))
			{
				DeathCounted = FALSE;
			}
			if ((pMe->dwMode == NPC_MODE_DEATH || pMe->dwMode == NPC_MODE_DEAD) && GetUnitStat(Me, STAT_HP) < 1)
			{
				if (!DeathCounted)
				{
					V_GameLost = TRUE;
					V_TimesKilled += 1;

					DeathCounted = TRUE;
				}
			}

			for (LPROOM1 Room = Me->pAct->pRoom1; Room; Room = Room->pRoomNext)
			{
				for (LPUNITANY Unit = Room->pUnitFirst; Unit; Unit = Unit->pListNext)
				{
					if (Unit && Unit->dwType == UNIT_TYPE_NPC)
					{
						if (Unit->dwMode == NPC_MODE_DEATH || Unit->dwMode == NPC_MODE_DEAD)
						{
							if (aSize < MAXIGNORE)
							{
								V_IgnoreTarget = FALSE;

								for (INT i = 0; i < MAXMONSTERS - 1; i++)
								{
									if ((DWORD)i == Unit->dwTxtFileNo)
									{
										for (INT j = 0; j < aSize; j++)
										{
											if (Unit->dwUnitId == V_IgnoreList[j])
											{
												V_IgnoreTarget = TRUE;
											}
										}
										if (!V_IgnoreTarget)
										{
											V_MonsterUnit[D2CLIENT_GetDifficulty()][i] += 1;

											V_IgnoreList[aSize++] = Unit->dwUnitId;

											if(Unit->dwTxtFileNo == 156)
											{
												EventGetTime(0);
											}
											else if (Unit->dwTxtFileNo == 211)
											{
												EventGetTime(1);
											}
											else if (Unit->dwTxtFileNo == 242)
											{
												EventGetTime(2);
											}
											else if (Unit->dwTxtFileNo == 243)
											{
												EventGetTime(3);
											}
											else if (Unit->dwTxtFileNo == 544)
											{
												EventGetTime(4);
											}
											else if (Unit->dwTxtFileNo == 757)
											{
												EventGetTime(5);
											}
											else if (Unit->dwTxtFileNo == 778)
											{
												EventGetTime(6);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		break;

	case COUNTER2:

		MarkedPosition = FALSE;
		MarkedArea = FALSE;

		mPosX = 0;
		mPosY = 0;
		pPosX = 0;
		pPosY = 0;
		rDistX = 0;
		rDistY = 0;

		while (TRUE)
		{
			SleepEx(LOOPDELAY, TRUE);

			if (!ClientReady(FALSE))
				continue;

			//
			//Count Distance
			if (!MarkedArea) //Set area marker
			{
				mArea = (INT)GetUnitLevel(Me)->dwLevelNo;

				MarkedArea = TRUE;
			}

			if (!MarkedPosition) //Set position marker
			{
				mPosX = Me->pPath->xPos;
				mPosY = Me->pPath->yPos;

				MarkedPosition = TRUE;
			}

			pPosX = Me->pPath->xPos;
			pPosY = Me->pPath->yPos;
			pArea = (INT)GetUnitLevel(Me)->dwLevelNo;

			SleepEx(SECONDSDELAY, TRUE);

			if (mArea != pArea)
			{
				if (MarkedArea == TRUE)
				{
					V_ChangedArea++;
				}

				MarkedArea = FALSE;
				MarkedPosition = FALSE;
			}

			if (MarkedPosition == TRUE && (pPosX != mPosX || pPosY != mPosY) && mArea == pArea) //Check for movement
			{
				if (mPosX < pPosX) //Moved East
				{
					rDistX = pPosX - mPosX;

					V_TravelDistanceE = rDistX;
				}
				else if (mPosX > pPosX) //Moved West
				{
					rDistX = mPosX - pPosX;

					V_TravelDistanceW = rDistX;
				}
				if (mPosY < pPosY) //Moved South
				{
					rDistY = pPosY - mPosY;

					V_TravelDistanceS = rDistY;
				}
				else if (mPosY > pPosY) //Moved North
				{
					rDistY = mPosY - pPosY;

					V_TravelDistanceN = rDistY;
				}

				V_DistanceThis = V_TravelDistanceN + V_TravelDistanceS + V_TravelDistanceE + V_TravelDistanceW;

				if(V_DistanceThis > 0)
				{
					V_TravelDistanceYard += V_DistanceThis;

					V_AntiIdle = TRUE;
				}
				if (V_TravelDistanceYard > 1759)
				{
					V_TravelDistanceMile += 1;

					V_TravelDistanceYard -= 1759;
				}
				V_TravelDistanceN = 0;
				V_TravelDistanceS = 0;
				V_TravelDistanceE = 0;
				V_TravelDistanceW = 0;

				V_DistanceThis = 0;

				MarkedPosition = FALSE;
			}
		}

		break;

	case COUNTER3:

		while (TRUE)
		{
			SleepEx(LOOPDELAY, TRUE);

			if (!ClientReady(FALSE))
				continue;

			//
			//Count Potions
			if (!GetUnitState(Me, AFFECT_HEALTHPOT))
				V_UsedHealth = FALSE;

			if (!GetUnitState(Me, AFFECT_MANAPOT))
				V_UsedMana = FALSE;

			if (!V_UsedHealth && GetUnitState(Me, AFFECT_HEALTHPOT))
			{
				V_HealthUsed += 1;

				V_UsedHealth = TRUE;
			}
			if (!V_UsedMana && GetUnitState(Me, AFFECT_MANAPOT))
			{
				V_ManaUsed += 1;

				V_UsedMana = TRUE;
			}

			//
			//Count Shrines
			if (!GetUnitState(Me, AFFECT_SHRINE_ARMOR) && !GetUnitState(Me, AFFECT_SHRINE_COMBAT) && !GetUnitState(Me, AFFECT_SHRINE_RESIST_LIGHTNING) &&
				!GetUnitState(Me, AFFECT_SHRINE_RESIST_FIRE) && !GetUnitState(Me, AFFECT_SHRINE_RESIST_COLD) && !GetUnitState(Me, AFFECT_SHRINE_RESIST_POISON) &&
				!GetUnitState(Me, AFFECT_SHRINE_SKILL) && !GetUnitState(Me, AFFECT_SHRINE_MANA_REGEN) && !GetUnitState(Me, AFFECT_SHRINE_STAMINA) &&
				!GetUnitState(Me, AFFECT_SHRINE_EXPERIENCE))
			{
				V_UsedShrine = FALSE;
			}

			if (!V_UsedShrine && (GetUnitState(Me, AFFECT_SHRINE_ARMOR) || GetUnitState(Me, AFFECT_SHRINE_COMBAT) || GetUnitState(Me, AFFECT_SHRINE_RESIST_LIGHTNING) ||
				GetUnitState(Me, AFFECT_SHRINE_RESIST_FIRE) || GetUnitState(Me, AFFECT_SHRINE_RESIST_COLD) || GetUnitState(Me, AFFECT_SHRINE_RESIST_POISON) ||
				GetUnitState(Me, AFFECT_SHRINE_SKILL) || GetUnitState(Me, AFFECT_SHRINE_MANA_REGEN) || GetUnitState(Me, AFFECT_SHRINE_STAMINA) ||
				GetUnitState(Me, AFFECT_SHRINE_EXPERIENCE)))
			{
				V_ShrineUsed += 1;

				V_UsedShrine = TRUE;
			}

			//
			//Count Times Healed
			DOUBLE LifePercent = CalcPercent((GetUnitStat(Me, STAT_HP) >> 8), (GetUnitStat(Me, STAT_MAXHP) >> 8));
			DOUBLE ManaPercent = CalcPercent((GetUnitStat(Me, STAT_MANA) >> 8), (GetUnitStat(Me, STAT_MAXMANA) >> 8));

			if (GetUnitState(Me, AFFECT_BATTLEORDERS)) //Check to see if Player has battle orders
				V_BoHealth = TRUE;

			if (LifePercent < 96) //Player is less than 95% life, FLAGGED for heal count
				V_MinusHealth = TRUE;

			if (LifePercent > 94 && LifePercent < 100) //Player has regen or is above 95% life, UNFLAGGED for heal count
				V_MinusHealth = FALSE;

			if (LifePercent > 94 && GetUnitState(Me, AFFECT_HEALTHPOT)) //Player is at 95% health while potion is active, UNFLAGGED for heal count
				V_MinusHealth = FALSE;

			if (LifePercent > 94 && GetUnitState(Me, AFFECT_RED)) //Player is at 95% health while leech is active, UNFLAGGED for heal count
				V_MinusHealth = FALSE;

			if (V_BoHealth && !GetUnitState(Me, AFFECT_BATTLEORDERS) && LifePercent > 99) //Player had battle orders and is now at full health, UNFLAGGED for heal count
				V_MinusHealth = FALSE;

			if (V_MinusHealth && LifePercent == 100) //If FLAGGED, count += 1
			{
				V_TimesHealed += 1;

				V_MinusHealth = FALSE;
			}

			//
			//Count Portals
			if (!GetUnitState(Me, AFFECT_JUST_PORTALED))
				V_UsedPortal = FALSE;

			if (!V_UsedPortal && GetUnitState(Me, AFFECT_JUST_PORTALED))
			{
				V_PortalsTaken += 1;

				V_UsedPortal = TRUE;
			}

			//
			//Count Waypoints
			if (!GetUIVar(UI_WPMENU))
				V_UsedWaypoint = FALSE;

			if (!V_UsedWaypoint)
			{
				if (GetUIVar(UI_WPMENU))
				{
					V_WaypointUsed += 1;

					V_UsedWaypoint = TRUE;
				}
			}
		}

		break;

	case COUNTER4:

		while (TRUE)
		{	
			if (!ClientReady(FALSE))
			{
				SleepEx(LOOPDELAY, TRUE);

				continue;
			}

			if (!V_GoldFoundLast)
				V_GoldFoundLast = 0;

			if (V_GoldFoundLast > 1000000000)
			{
				V_GoldFoundLast = 0;
			}

			if (!V_GoldFoundThis)
				V_GoldFoundThis = 0;

			if (V_GoldFoundThis > 1000000000)
			{
				V_GoldFoundThis = 0;
			}

			SleepEx(CALCGOLDDELAY, TRUE);

			TotalGold = GetUnitStat(Me, STAT_GOLD) + GetUnitStat(Me, STAT_GOLDBANK);

			if(!GetUIVar(UI_STASH))
			{
				V_GoldFoundThis = TotalGold - V_GoldFoundLast;

				if(V_GoldFoundThis >= 1000)
				{
					V_GoldThousand += V_GoldFoundThis / 1000;

					V_GoldFoundThis -= (V_GoldFoundThis / 1000) * 1000;
				}
				if(V_GoldFoundThis >= 100)
				{
					V_GoldSilver += V_GoldFoundThis / 100;

					V_GoldFoundThis -= (V_GoldFoundThis / 100) * 100;
				}
				V_GoldCopper += V_GoldFoundThis;

				if(V_GoldCopper >= 100)
				{
					V_GoldSilver += V_GoldCopper / 100;

					V_GoldCopper -= (V_GoldCopper / 100) * 100;
				}
				if(V_GoldSilver >= 10)
				{
					V_GoldThousand += V_GoldSilver / 10;

					V_GoldSilver -= (V_GoldSilver / 10) * 10;
				}
				if(V_GoldThousand >= 1000)
				{
					V_GoldMillion += V_GoldThousand / 1000;

					V_GoldThousand -= (V_GoldThousand / 1000) * 1000;
				}
				if(V_GoldMillion >= 1000)
				{
					V_GoldBillion += V_GoldMillion / 1000;

					V_GoldMillion -= (V_GoldMillion / 1000) * 1000;
				}
				if(V_GoldBillion >= 1000)
				{
					V_GoldTrillion += V_GoldBillion / 1000;

					V_GoldBillion -= (V_GoldBillion / 1000) * 1000;
				}
			}

			V_GoldFoundLast = TotalGold;
		}

		break;

	case AUTOBOT:

		break;
	

	case AUTOSAVE:

		while (TRUE)
		{
			SleepEx(SAVEDELAY, TRUE);

			while (V_BusyUpdData == TRUE)  //Pause if updating ladder
			{
				SleepEx(250, TRUE);
			}

			SavePlayerData();
		}

		break;

	case LADDERSAVE:

		while (TRUE)
		{
			SleepEx(250, TRUE);

			if (V_QueueLadderReset == TRUE)
			{
				Print(1, 9, "Resetting player ladder...");

				LadderResetCMD();

				V_QueueLadderReset = FALSE;
			}
			if (V_QueueLadderSave == TRUE)
			{
				Print(1, 9, "Saving player ladder...");

				LadderSaveCMD();

				V_QueueLadderSave = FALSE;
			}
			if (V_QueueLadderSetNote == TRUE)
			{
				Print(1, 9, "Saving player note...");

				LadderSetNoteCMD();

				V_QueueLadderSetNote = FALSE;
			}
			if (V_QueueLadderDeleteNote == TRUE)
			{
				Print(1, 9, "Deleting player note...");

				LadderDeleteNoteCMD();

				V_QueueLadderDeleteNote = FALSE;
			}
		}

		break;

	case LADDERAUTOSAVE:

		while (TRUE)
		{
			SleepEx(SAVEDELAYLADDER, TRUE); //Save

			if (V_BusyUpdData == FALSE)
			{
				//Print(1, 9, "Updating player ladder.");

				V_BusyUpdData = TRUE;

				LoadLadder();

				RegisterLadder();

				UpdateLadder();
				SortLadder();

				SaveLadder();

				LoadLadder();

				V_BusyUpdData = FALSE;

				//Print(1, 9, "Player ladder updated!");
			}
		}

		break;

	case LADDERWATCH:

		while (TRUE)
		{
			SleepEx(25, TRUE);

			if (!ClientReady(FALSE))
				continue;

			LPUNITANY pMe = Me;

			if ((pMe->dwMode == NPC_MODE_DEATH || pMe->dwMode == NPC_MODE_DEAD) && GetUnitStat(Me, STAT_HP) < 1)
			{
				if (!DeathCountedLadder)
				{
					DeathCountedLadder = TRUE;

					V_LadderDeath = TRUE;

					if (V_BusyUpdData == TRUE)
					{
						while (V_BusyUpdData == TRUE)
						{
							SleepEx(250, TRUE);
						}
					}

					if (V_BusyUpdData == FALSE)
					{
						//Print(1, 9, "Updating player ladder.");

						V_BusyUpdData = TRUE;

						RegisterLadder();

						UpdateLadder();
						SortLadder();

						SaveLadder();

						LoadLadder();

						V_BusyUpdData = FALSE;
					}
				}
			}
			else
			{
				if (V_LadderDeath == TRUE)
				{
					if (V_BusyUpdData == TRUE)
					{
						while (V_BusyUpdData == TRUE)
						{
							SleepEx(250, TRUE);
						}
					}

					V_LadderDeath = FALSE;

					V_BusyUpdData = TRUE;

					RegisterLadder();

					UpdateLadder();
					SortLadder();

					SaveLadder();

					LoadLadder();

					V_BusyUpdData = FALSE;
				}
				else
				{
					V_LadderDeath = FALSE;
				}
			}
		}

		break;

	case TIMECLOCK:

		mMin = 0;
	
		while (TRUE)
		{
			SleepEx(SECONDSDELAY, TRUE);

			V_ClockSeconds += 1;

			if (V_ClockSeconds  >= 59)
			{
				V_ClockSeconds -= 59;

				V_ClockMinutes += 1;

				mMin += 1;
			}
			if (V_ClockMinutes >= 59)
			{
				V_ClockMinutes -= 59;

				V_ClockHours += 1;
			}
			if (mMin >= GAMEDRAWMIN)
			{
				V_GameDraw = TRUE;
			}
			if (mMin >= GAMEWINMIN)
			{
				V_GameWon = TRUE;
			}
		}

		break;

	case AUTOLOGOUT:

		mIdleSec = 0;
		mIdleMin = 0;
	
		while (TRUE)
		{
			SleepEx(LOOPDELAY, TRUE);

			if(!V_AntiIdle)
			{
				SleepEx(SECONDSDELAY, TRUE);

				mIdleSec += 1;

				if (mIdleSec  >= 59)
				{
					mIdleSec -= 59;

					mIdleMin += 1;

					if (mIdleMin == 5)
					{
						Print(0, 9, "You are idle.");
					}
#ifdef EXITWHENIDLE
					if (mIdleMin == MAXIDLETIME - 5)
					{
						Print(0, 9, "Exiting game in 5 minutes...");
					}
					if (mIdleMin == MAXIDLETIME - 4)
					{
						Print(0, 9, "Exiting game in 4 minutes...");
					}
					if (mIdleMin == MAXIDLETIME - 3)
					{
						Print(0, 9, "Exiting game in 3 minutes...");
					}
					if (mIdleMin == MAXIDLETIME - 2)
					{
						Print(0, 9, "Exiting game in 2 minutes...");
					}
					if (mIdleMin == MAXIDLETIME - 1)
					{
						Print(0, 9, "Exiting game in 1 minute...");
					}
					if (mIdleMin >= MAXIDLETIME)
					{
						Print(0, 9, "Exiting game.");

						SleepEx(5000, TRUE);

						D2CLIENT_ExitGame();
					}
#endif
				}
			}
			else if(V_AntiIdle == TRUE)
			{
				if (mIdleMin >= 4)
				{
					Print(0, 9, "You are no longer idle.");
				}

				mIdleSec = 0;
				mIdleMin = 0;

				V_AntiIdle = FALSE;
			}
		}

		break;

	case DESIGN:

		while (TRUE)
		{
			SleepEx(1, TRUE);

			if (!ClientReady(FALSE))
				continue;

			if (V_Screenshot)
				ScreenShot();

		/*	if (V_Design->Hide && !V_HostileImage)
			{
				PatchBytes((DWORD)LoadLibraryA("D2Client.dll") + 0x2864C, 0x46, 1);
				V_HostileImage = TRUE;
			}

			else if (!V_Design->Hide && V_HostileImage)
			{
				if (D2CLIENT_GetDifficulty() > 0)
					PatchBytes((DWORD)LoadLibraryA("D2Client.dll") + 0x2864C, ((strlen(D2CLIENT_GetGameInfo()->szGamePassword) != NULL) ?
					0x46 + 0x5F : 0x46 + 0x55), 1);
				else
					PatchBytes((DWORD)LoadLibraryA("D2Client.dll") + 0x2864C, ((strlen(D2CLIENT_GetGameInfo()->szGamePassword) != NULL) ?
					0x46 + 0x4B : 0x46 + 0x41), 1);

				V_HostileImage = FALSE;
			}*/

			if (!ClientReady(TRUE))
				continue;

			if (V_AutoKB && V_KB)
				if (Knockback()) V_KB = FALSE;

			if (V_AutoBlind && V_Reblind)
				if (Reblind()) V_Reblind = FALSE;
		}

		break;

	case ENCHANT:

		while (TRUE)
		{
			SleepEx(500, TRUE);

			if (!ClientReady(TRUE) || !V_Enchant)
				continue;

			if (V_EnchantNoteIteration && !V_Players.IsEmpty())
			{
				V_EnchantNoteIteration = FALSE;

				if (Say("%s's Enchant Bot is enabled", V_Name))
					SleepEx(500, TRUE);

				if (Say("%s - Enchants you", V_EnchantPlayer))
					SleepEx(500, TRUE);

				if (Say("%s - Enchants your mercenary", V_EnchantMercenary))
					SleepEx(500, TRUE);

				if (Say("%s - Enchants everything", V_EnchantAll))
					SleepEx(500, TRUE);
			}

			if (V_EnchantQueue.IsEmpty() || V_EnchantQueue.IsLocked)
				continue;

			ExecuteEnchantQueue(V_EnchantQueue[0]);
			V_EnchantQueue.RemoveAt(0);
			V_EnchantQueue.FreeExtra();
		}

		break;

	case PACKETS:

		while (TRUE)
		{
			SleepEx(50, TRUE);

			if (!ClientReady(TRUE))
				continue;

			if (GetTickCount() - V_FlashLast >= V_FlashDelay)
			{
				for (INT i = 0; i < V_Players.GetSize(); i++)
				{
					if (V_Players[i]->Flashing)
					{
						if (ResynchPlayer(V_Players[i]->UnitId, UNIT_TYPE_PLAYER))
							SleepEx(50, TRUE);
					}
				}

				V_FlashLast = GetTickCount();
			}

			if (V_GoldDrop && V_GoldAmount > 0)
			{
				if (GetUnitStat(Me, STAT_GOLD) >= 1)
				{
					if (DropGold(Me->dwUnitId, V_GoldAmount))
						SleepEx(50, TRUE);
				}
			}
		}

		break;

	case PARTY:

		while(TRUE)
		{
			SleepEx(500, TRUE);

			if (!ClientReady(TRUE) || !V_AutoParty)
				continue;

			LPROSTERUNIT pMe = FindPartyById(Me->dwUnitId);

			if (!pMe)
				continue;

			for(LPROSTERUNIT pUnit = *p_D2CLIENT_PlayerUnitList; pUnit; pUnit = pUnit->pNext)
			{
				if(pUnit->dwUnitId == pMe->dwUnitId)
					continue;

				DWORD dwFlags = GetPvPFlags(pUnit->dwUnitId);

				if(dwFlags & PVP_ALLIED || dwFlags & PVP_ALLIED_WITH_YOU)
					continue;

				if(dwFlags & PVP_INVITED_BY_YOU)
					continue;

				if(dwFlags & PVP_HOSTILED_YOU || dwFlags & PVP_HOSTILED_BY_YOU)
					continue;

				if(dwFlags & PVP_INVITED_YOU)
				{
					BYTE aPacket[6];
					*(LPWORD)&aPacket[0] = 0x085E;
					*(LPDWORD)&aPacket[2] = pUnit->dwUnitId;
					D2NET_SendPacket(6, 1, aPacket);

					for(INT i = 0; i < 500 + (INT)*p_D2CLIENT_Ping; i++)
					{
						if(pMe->wPartyId != 0xFFFF)
							break;
						else
							SleepEx(1, TRUE);
					}

					continue;
				}

				if(!(dwFlags & PVP_ALLIED || dwFlags & PVP_ALLIED_WITH_YOU ||
					dwFlags & PVP_INVITED_YOU || dwFlags & PVP_INVITED_BY_YOU))
				{
					BYTE aPacket[6];
					*(LPWORD)&aPacket[0] = 0x065E;
					*(LPDWORD)&aPacket[2] = pUnit->dwUnitId;
					D2NET_SendPacket(6, 1, aPacket);

					for(INT i = 0; i < 500 + (INT)*p_D2CLIENT_Ping; i++)
					{
						DWORD dwFlags = GetPvPFlags(pUnit->dwUnitId);
						if(dwFlags & PVP_INVITED_BY_YOU)
							break;
						else
							SleepEx(1, TRUE);
					}

					continue;
				}
			}
		}

		break;

	case GOA5:

	{
		INT DestArea;
		DestArea = 109;

		Print(0, 0, "ÿc4Travel:ÿc0 Going to Act5.");

		V_ActiveWP = GetWaypoint();

		if (!V_ActiveWP)
		{
			Print(0, 1, "ÿc1Waypoint not found, get closer and try again.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		if (!MoveToQueue((WORD)D2CLIENT_GetUnitX(V_ActiveWP), (WORD)D2CLIENT_GetUnitY(V_ActiveWP)))
		{
			Print(0, 1, "ÿc1Failed to reach desination, terminating sequence.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		Interact(V_ActiveWP->dwUnitId, UNIT_TYPE_OBJECT, TRUE);
		SleepEx(250, TRUE);
		D2CLIENT_TakeWaypoint(V_ActiveWP->dwUnitId, DestArea);
		SleepEx(1000, TRUE);
		if (D2CLIENT_GetUiVar_I(0x00))
			D2CLIENT_CloseInteract();

		if (Me->pAct->dwAct != 4)
		{
			Print(0, 1, "ÿc1TakeWaypoint failed.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}
		V_BusyThread = FALSE;
	}

	break;

	case GIVEA5:

	{
		INT DestArea;
		INT SpoofLoc[2];

		DestArea = 109;
		SpoofLoc[0] = 5114;
		SpoofLoc[1] = 5069;

		Print(0, 1, "ÿc4Travel:ÿc0 Giving Stony Field spoof waypoint.");

		V_ActiveWP = GetWaypoint();

		if (!V_ActiveWP)
		{
			Print(0, 1, "ÿc1Waypoint not found, get closer and try again.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		if (!MoveToQueue((WORD)D2CLIENT_GetUnitX(V_ActiveWP), (WORD)D2CLIENT_GetUnitY(V_ActiveWP)))
		{
			Print(0, 1, "ÿc1Failed to reach desination, terminating sequence.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		Interact(V_ActiveWP->dwUnitId, UNIT_TYPE_OBJECT, FALSE);
		SleepEx(250, TRUE);
		D2CLIENT_TakeWaypoint(V_ActiveWP->dwUnitId, 4);
		SleepEx(1000, TRUE);
		if (!D2CLIENT_GetUiVar_I(0x00))
			D2CLIENT_CloseInteract();

		if (InTown(Me))
		{
			Print(0, 1, "ÿc1TakeWaypoint failed.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		if (!MoveToQueue((WORD)SpoofLoc[0], (WORD)SpoofLoc[1]))
		{
			Print(0, 1, "ÿc1Failed to reach desination, terminating sequence.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		if (Portal()) V_TP = TRUE;

		while (!InTown(Me))
		{
			SleepEx(3000, TRUE);
		}

		V_BusyThread = FALSE;
	}

	break;

	case GETA5:

	{
		INT Retries = 15;

		if (InTown(Me))
		{
			Print(0, 1, "ÿc1Wrong Area, take Stony Field portal and try again.");

			V_BusyThread = FALSE;
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		for (INT i = 0; i < Retries; i++)
		{
			MoveToQueue(5116, 5067);

			INT Length = 9;
			LPBYTE Packet = new BYTE[Length];
			Packet[0] = 0x13;
			*(LPDWORD)&Packet[1] = 0x02;
			*(LPDWORD)&Packet[5] = (DWORD)V_A5WaypointID;

			D2NET_SendPacket(Length, 1, Packet);

			delete[] Packet;

			SleepEx(1000, TRUE);

			if (GetUIVar(UI_WPMENU))
			{
				break;
			}
		}
		SleepEx(1000, TRUE);
		if (!D2CLIENT_GetUiVar_I(0x00))
			D2CLIENT_CloseInteract();

		Say("Activated waypoint.");

		V_BusyThread = FALSE;
	}

	break;

	case TELEPORT:

		WORD OldSkill;
		INT OldLevel;

		if (GetSkill(D2S_TELEPORT) == NULL)
		{
			V_TeleportQueue.RemoveAll();
			Print(0, 4, "ÿc4Lazarusÿc0: ÿc1Teleport skill not found");
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		if (V_TeleportQueue.IsEmpty())
		{
			Print(0, 4, "ÿc4Lazarusÿc0: ÿc1There are no nodes to teleport to");
			DestroyThread(GetCurrentThread(), NULL, INFINITE);
			while (TRUE) SleepEx(1, TRUE);
		}

		V_TeleportQueue.Lock();

		OldSkill = GetCurrentSkill(V_LeftAttack);
		OldLevel = GetUnitLevel(Me)->dwLevelNo;

		while (!V_TeleportQueue.IsEmpty())
		{
			BOOL Arrived = FALSE;
			INT Iterations = NULL;

			if (GetCurrentSkill(V_LeftAttack) != D2S_TELEPORT)
				SetSkill(D2S_TELEPORT, V_LeftAttack);

			while (GetCurrentSkill(V_LeftAttack) != D2S_TELEPORT)
				SleepEx(1, TRUE);

			LPBYTE Packet = new BYTE[5];
			Packet[0] = V_LeftAttack ? 0x05 : 0x0C;
			*(LPWORD)&Packet[1] = (WORD)V_TeleportQueue[0].x;
			*(LPWORD)&Packet[3] = (WORD)V_TeleportQueue[0].y;
			D2NET_SendPacket(5, 1, Packet);
			delete [] Packet;

			while (Iterations < 1000)
			{
				if (!ClientReady(TRUE) || InTown(Me) || V_TeleportQueue.IsEmpty())
					break;

				if (CalculateDistance(Me->pPath->xPos, Me->pPath->yPos, V_TeleportQueue[0].x, V_TeleportQueue[0].y) <= 5)
				{
					Arrived = TRUE;
					break;
				}

				Iterations++;
				SleepEx(1, TRUE);
			}

			if (!Arrived)
			{
				V_TeleportQueue.RemoveAll();
				V_TeleportQueue.Unlock();

				//Print(0, 4, "ÿc4Lazarusÿc0: ÿc1Failed to reach target, terminating teleport sequence");

				if (GetCurrentSkill(V_LeftAttack) != OldSkill)
					SetSkill(OldSkill, V_LeftAttack);

				while (GetCurrentSkill(V_LeftAttack) != OldSkill)
					SleepEx(1, TRUE);

				DestroyThread(GetCurrentThread(), NULL, INFINITE);
				return TRUE;
			}

			V_TeleportQueue.RemoveAt(0);
			V_TeleportQueue.FreeExtra();
		}

		if (V_CurrentVector)
		{
			if (GetCurrentSkill(V_LeftAttack) != OldSkill)
				SetSkill(OldSkill, V_LeftAttack);

			while (GetCurrentSkill(V_LeftAttack) != OldSkill)
				SleepEx(1, TRUE);

			for (LPROOM1 Room = Me->pAct->pRoom1; Room; Room = Room->pRoomNext)
			{
				for (LPUNITANY Unit = Room->pUnitFirst; Unit; Unit = Unit->pListNext)
				{
					if (Unit->dwType == UNIT_TYPE_TILE)
					{
						if (V_CurrentVector->TargetType == -1)
						{
							if (V_Reveal->GetTileLevelNo(Room->pRoom2, Unit->dwTxtFileNo) == V_CurrentVector->Target)
							{
								SleepEx(50 + (INT)Ping, TRUE);
								Interact(Unit->dwUnitId, Unit->dwType, TRUE);
								goto End;
							}
						}

						if (V_CurrentVector->Type == 3)
						{
							if (Unit->dwTxtFileNo == V_CurrentVector->Target)
							{
								SleepEx(50 + (INT)Ping, TRUE);
								Interact(Unit->dwUnitId, Unit->dwType, TRUE);
								goto End;
							}
						}
					}

					if (Unit->dwType == UNIT_TYPE_OBJECT)
					{
						if (V_CurrentVector->Type == 4)
						{
							if (Unit->dwTxtFileNo == V_CurrentVector->Target)
							{
								SleepEx(50 + (INT)Ping, TRUE);

								for (INT i = 0; i < 2; i++)
								{
									if (Unit->dwMode < 2)
									{
										Interact(Unit->dwUnitId, Unit->dwType, TRUE);
										SleepEx(500 + (INT)Ping, TRUE);
									}

									else
									{
										Interact(Unit->dwUnitId, Unit->dwType, TRUE);
										break;
									}
								}

								goto End;
							}
						}
					}
				}
			}
End:;
		}

		V_TeleportQueue.Unlock();
		DestroyThread(GetCurrentThread(), NULL, INFINITE);
		break;
	}
	
	return TRUE;
}

HANDLE MakeThread(LPVOID Process, LPVOID Parameter)
{
	HANDLE Thread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Process, Parameter, NULL, NULL);
	if (!Thread) return NULL;
	return Thread;
}

VOID DestroyThread(HANDLE Thread, DWORD Parameter, DWORD MaxWaitTime)
{
	TerminateThread(Thread, Parameter);
	WaitForSingleObject(Thread, MaxWaitTime);
	CloseHandle(Thread);
}

VOID CreateInGameThreads()
{
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DESIGN));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)ENCHANT));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)PACKETS));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)PARTY));

	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)TIMECLOCK));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)AUTOSAVE));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)LADDERSAVE));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)LADDERAUTOSAVE));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)LADDERWATCH));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)COUNTER));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)COUNTER2));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)COUNTER3));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)COUNTER4));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)KEYITEMS));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)AUTOLOGOUT));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)MOVEKEYS));
#ifdef XINPUT
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)VIBRATEPAD));
	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)VIBRATEPAD2));
#endif
}

VOID DestroyInGameThreads()
{
	if (!V_Threads.IsEmpty())
	{
		for (INT i = 0; i < V_Threads.GetSize(); i++)
		{
			if (V_Threads[i])
				DestroyThread(V_Threads[i], i + 1, INFINITE);
		}

		V_Threads.RemoveAll();
	}
}
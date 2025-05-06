#include "Hack.h"

VOID DrawInfoMain()
{
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_InfoListMainStr[0]); //Player
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_InfoListMainStr[1]); //Monsters
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_InfoListMainStr[2]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_InfoListMainStr[3]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_InfoListMainStr[4]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_InfoListMainStr[5]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_InfoListMainStr[6]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_InfoListMainStr[7]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_InfoListMainStr[8]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 1, V_InfoListMainStr[9]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_InfoListMainStr[10]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_InfoListMainStr[11]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_InfoListMainStr[12]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_InfoListMainStr[13]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_InfoListMainStr[14]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_InfoListMainStr[15]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_InfoListMainStr[16]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_InfoListMainStr[17]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_InfoListMainStr[18]);
	DrawGroupListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_InfoListMainStr[19]);
}

VOID DrawInfoList(INT Group)
{
	if (Group == 1)
	{
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_InfoListOneStr[0]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_InfoListOneStr[1]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_InfoListOneStr[2]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_InfoListOneStr[3]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_InfoListOneStr[4]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_InfoListOneStr[5]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_InfoListOneStr[6]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_InfoListOneStr[7]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_InfoListOneStr[8]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_InfoListOneStr[9]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_InfoListOneStr[10]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_InfoListOneStr[11]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_InfoListOneStr[12]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_InfoListOneStr[13]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_InfoListOneStr[14]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_InfoListOneStr[15]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_InfoListOneStr[16]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_InfoListOneStr[17]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_InfoListOneStr[18]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_InfoListOneStr[19]);
	}
	else if (Group == 2)
	{
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_InfoListTwoStr[0]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_InfoListTwoStr[1]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_InfoListTwoStr[2]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_InfoListTwoStr[3]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_InfoListTwoStr[4]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_InfoListTwoStr[5]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_InfoListTwoStr[6]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_InfoListTwoStr[7]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_InfoListTwoStr[8]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_InfoListTwoStr[9]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_InfoListTwoStr[10]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_InfoListTwoStr[11]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_InfoListTwoStr[12]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_InfoListTwoStr[13]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_InfoListTwoStr[14]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_InfoListTwoStr[15]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_InfoListTwoStr[16]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_InfoListTwoStr[17]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_InfoListTwoStr[18]);
		DrawInfoListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_InfoListTwoStr[19]);
	}

	DrawInfoListBack();
	DrawInfoListNext();
}

VOID DrawInfoText()
{
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr1Y, 0, 0, 0, -1, V_PlayerInfoText1);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr2Y, 0, 0, 0, -1, V_PlayerInfoText2);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr3Y, 0, 0, 0, -1, V_PlayerInfoText3);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr4Y, 0, 0, 0, -1, V_PlayerInfoText4);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr5Y, 0, 0, 0, -1, V_PlayerInfoText5);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr6Y, 0, 0, 0, -1, V_PlayerInfoText6);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr7Y, 0, 0, 0, -1, V_PlayerInfoText7);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr8Y, 0, 0, 0, -1, V_PlayerInfoText8);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr9Y, 0, 0, 0, -1, V_PlayerInfoText9);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr10Y, 0, 0, 0, -1, V_PlayerInfoText10);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr11Y, 0, 0, 0, -1, V_PlayerInfoText11);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr12Y, 0, 0, 0, -1, V_PlayerInfoText12);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr13Y, 0, 0, 0, -1, V_PlayerInfoText13);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr14Y, 0, 0, 0, -1, V_PlayerInfoText14);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr15Y, 0, 0, 0, -1, V_PlayerInfoText15);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr16Y, 0, 0, 0, -1, V_PlayerInfoText16);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr17Y, 0, 0, 0, -1, V_PlayerInfoText17);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr18Y, 0, 0, 0, -1, V_PlayerInfoText18);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr19Y, 0, 0, 0, -1, V_PlayerInfoText19);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr20Y, 0, 0, 0, -1, V_PlayerInfoText20);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr21Y, 0, 0, 0, -1, V_PlayerInfoText21);

	DrawInfoTextBack();
	DrawInfoTextNext();
}

VOID DrawGroupListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iGroupId, LPSTR szGroupTitle)
{
	std::string str = szGroupTitle;
	if (str != "")
	{
		if ((*p_D2CLIENT_MouseX >= iMouseOverX1 && *p_D2CLIENT_MouseX <= iMouseOverX2) && (*p_D2CLIENT_MouseY >= iMouseOverY1 && *p_D2CLIENT_MouseY <= iMouseOverY2))
		{
			V_Design->TextHook(iTextX, iTextY, 3, 0, 1, -1, szGroupTitle);

			PlayMenuSound(iGroupId, 0);
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					ResetInfoMenu();

					V_PlayerInfoGroup = iGroupId;
					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			V_Design->TextHook(iTextX, iTextY, 0, 0, 1, -1, szGroupTitle);

			PlayMenuSound(iGroupId, 1);
		}
	}
}

VOID DrawInfoListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iInfoId, LPSTR szInfoTitle)
{
	std::string str = szInfoTitle;
	if (str != "")
	{
		if ((*p_D2CLIENT_MouseX >= iMouseOverX1 && *p_D2CLIENT_MouseX <= iMouseOverX2) && (*p_D2CLIENT_MouseY >= iMouseOverY1 && *p_D2CLIENT_MouseY <= iMouseOverY2))
		{
			V_Design->TextHook(iTextX, iTextY, 3, 0, 1, -1, szInfoTitle);

			PlayMenuSound(iInfoId, 0);
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					ResetInfoMenu();

					V_PlayerInfoSelected = iInfoId;

					SetInfoText(V_PlayerInfoGroup, iInfoId, V_SelectedCounterPageText);

					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			if (V_PlayerInfoSelected == iInfoId)
			{
				V_Design->TextHook(iTextX, iTextY, 3, 0, 1, -1, szInfoTitle);
			}
			else
			{
				V_Design->TextHook(iTextX, iTextY, 0, 0, 1, -1, szInfoTitle);
			}

			PlayMenuSound(iInfoId, 1);
		}
	}
}

VOID DrawInfoListBack()
{
	if ((*p_D2CLIENT_MouseX >= MouseOverX1L && *p_D2CLIENT_MouseX <= MouseOverX2L) && (*p_D2CLIENT_MouseY >= MouseOverY1LBack && *p_D2CLIENT_MouseY <= MouseOverY2LBack))
	{
		V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoBackStrY, 3, 0, 1, -1, V_CounterBackStr);

		if (!V_BackSoundSelectB)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_BackSoundSelectB = TRUE;
		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				ResetInfoMenu();

				V_PlayerInfoBack = TRUE;

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
			}
		}
	}
	else
	{
		V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoBackStrY, 0, 0, 1, -1, V_CounterBackStr);

		V_BackSoundSelectB = FALSE;
	}
}

VOID DrawInfoListNext()
{
	if ((*p_D2CLIENT_MouseX >= MouseOverX1L && *p_D2CLIENT_MouseX <= MouseOverX2L) && (*p_D2CLIENT_MouseY >= MouseOverY1LNext && *p_D2CLIENT_MouseY <= MouseOverY2LNext))
	{
		if (V_SelectedCounterPage == V_PlayerInfoListPages)
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 5, 0, 1, -1, V_CounterNextStr);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 3, 0, 1, -1, V_CounterNextStr);
		}

		if (!V_NextSoundSelectB)
		{
			if (V_SelectedCounterPage < V_PlayerInfoListPages)
			{
				D2CLIENT_PlaySound(STAND_PASS);

				V_NextSoundSelectB = TRUE;
			}
		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				ResetInfoMenu();

				V_PlayerInfoNext = TRUE;

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
			}
		}
	}
	else
	{
		if (V_SelectedCounterPage == V_PlayerInfoListPages)
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 5, 0, 1, -1, V_CounterNextStr);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 0, 0, 1, -1, V_CounterNextStr);
		}

		V_NextSoundSelectB = FALSE;
	}
}

VOID DrawInfoTextBack()
{
	if (V_PlayerInfoTextPages > 1)
	{
		if ((*p_D2CLIENT_MouseX >= MouseOverX1BackText && *p_D2CLIENT_MouseX <= MouseOverX2BackText) && (*p_D2CLIENT_MouseY >= MouseOverY1BackText && *p_D2CLIENT_MouseY <= MouseOverY2BackText))
		{
			if (V_SelectedCounterPageText == 1)
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 5, 0, 1, -1, V_CounterBackStr);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 3, 0, 1, -1, V_CounterBackStr);
			}

			if (!V_BackTextSoundSelectB)
			{
				if (V_SelectedCounterPageText > 1)
				{
					D2CLIENT_PlaySound(STAND_PASS);

					V_BackTextSoundSelectB = TRUE;
				}
			}
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					ResetInfoText();

					V_PlayerInfoBackText = TRUE;

					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			if (V_SelectedCounterPageText == 1)
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 5, 0, 1, -1, V_CounterBackStr);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 0, 0, 1, -1, V_CounterBackStr);
			}

			V_BackTextSoundSelectB = FALSE;
		}
	}
}

VOID DrawInfoTextNext()
{
	if (V_PlayerInfoTextPages > 1)
	{
		if ((*p_D2CLIENT_MouseX >= MouseOverX1NextText && *p_D2CLIENT_MouseX <= MouseOverX2NextText) && (*p_D2CLIENT_MouseY >= MouseOverY1NextText && *p_D2CLIENT_MouseY <= MouseOverY2NextText))
		{
			if (V_SelectedCounterPageText == V_PlayerInfoTextPages)
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 5, 0, 1, -1, V_CounterNextStr);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 3, 0, 1, -1, V_CounterNextStr);
			}

			if (!V_NextTextSoundSelectB)
			{
				if (V_SelectedCounterPageText < V_PlayerInfoTextPages)
				{
					D2CLIENT_PlaySound(STAND_PASS);

					V_NextTextSoundSelectB = TRUE;
				}
			}
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					ResetInfoText();

					V_PlayerInfoNextText = TRUE;

					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			if (V_SelectedCounterPageText == V_PlayerInfoTextPages)
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 5, 0, 1, -1, V_CounterNextStr);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 0, 0, 1, -1, V_CounterNextStr);
			}

			V_NextTextSoundSelectB = FALSE;
		}
	}
}

VOID DrawQuestMain()
{
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 0, V_SideQuestTitleExpansion1);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 1, V_SideQuestTitleExpansion2);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 2, V_SideQuestTitleExpansion3);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 3, V_SideQuestTitleExpansion4);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 4, V_SideQuestTitleExpansion5);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 5, V_SideQuestTitleExpansion6);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 6, V_SideQuestTitleExpansion7);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 7, V_SideQuestTitleExpansion8);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 8, V_SideQuestTitleExpansion9);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 9, V_SideQuestTitleExpansion10);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 10, V_SideQuestTitleExpansion11);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 11, V_SideQuestTitleExpansion12);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 12, V_SideQuestTitleExpansion13);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 13, V_SideQuestTitleExpansion14);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 14, V_SideQuestTitleExpansion15);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 15, V_SideQuestTitleExpansion16);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 16, V_SideQuestTitleExpansion17);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 17, V_SideQuestTitleExpansion18);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 18, V_SideQuestTitleExpansion19);
	DrawExpansionListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 19, V_SideQuestTitleExpansion20);
}

VOID DrawQuestList()
{
	if(V_MenuObject == 4) //Key Items
	{
		if(V_SideQuestTagExpansion == "Classic")
		{
			if(V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp1[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp1[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp1[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp1[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp1[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp1[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp1[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp1[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp1[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp1[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp1[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp1[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp1[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp1[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp1[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp1[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp1[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp1[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp1[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp1[19]);
			}
			if(V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp1[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp1[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp1[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp1[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp1[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp1[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp1[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp1[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp1[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp1[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp1[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp1[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp1[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp1[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp1[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp1[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp1[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp1[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp1[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp1[39]);
			}
		}
		if(V_SideQuestTagExpansion == "Lod")
		{
			if(V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp2[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp2[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp2[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp2[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp2[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp2[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp2[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp2[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp2[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp2[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp2[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp2[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp2[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp2[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp2[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp2[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp2[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp2[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp2[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp2[19]);
			}
			if(V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp2[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp2[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp2[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp2[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp2[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp2[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp2[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp2[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp2[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp2[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp2[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp2[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp2[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp2[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp2[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp2[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp2[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp2[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp2[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp2[39]);
			}
		}
		if(V_SideQuestTagExpansion == "Prd")
		{
			if(V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp3[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp3[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp3[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp3[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp3[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp3[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp3[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp3[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp3[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp3[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp3[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp3[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp3[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp3[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp3[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp3[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp3[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp3[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp3[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp3[19]);
			}
			if(V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp3[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp3[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp3[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp3[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp3[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp3[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp3[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp3[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp3[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp3[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp3[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp3[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp3[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp3[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp3[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp3[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp3[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp3[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp3[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp3[39]);
			}
		}
		if(V_SideQuestTagExpansion == "Wotg")
		{
			if(V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp4[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp4[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp4[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp4[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp4[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp4[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp4[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp4[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp4[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp4[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp4[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp4[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp4[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp4[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp4[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp4[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp4[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp4[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp4[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp4[19]);
			}
			if(V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp4[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp4[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp4[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp4[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp4[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp4[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp4[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp4[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp4[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp4[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp4[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp4[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp4[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp4[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp4[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp4[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp4[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp4[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp4[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp4[39]);
			}
		}
		if(V_SideQuestTagExpansion == "Oos")
		{
			if(V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp5[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp5[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp5[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp5[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp5[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp5[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp5[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp5[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp5[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp5[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp5[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp5[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp5[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp5[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp5[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp5[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp5[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp5[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp5[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp5[19]);
			}
			if(V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp5[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp5[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp5[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp5[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp5[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp5[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp5[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp5[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp5[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp5[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp5[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp5[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp5[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp5[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp5[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp5[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp5[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp5[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp5[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp5[39]);
			}
		}
		if(V_SideQuestTagExpansion == "Fagf")
		{
			if(V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp6[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp6[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp6[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp6[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp6[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp6[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp6[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp6[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp6[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp6[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp6[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp6[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp6[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp6[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp6[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp6[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp6[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp6[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp6[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp6[19]);
			}
			if(V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp6[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp6[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp6[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp6[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp6[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp6[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp6[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp6[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp6[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp6[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp6[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp6[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp6[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp6[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp6[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp6[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp6[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp6[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp6[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp6[39]);
			}
		}
		if (V_SideQuestTagExpansion == "Gp")
		{
			if (V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp7[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp7[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp7[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp7[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp7[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp7[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp7[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp7[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp7[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp7[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp7[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp7[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp7[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp7[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp7[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp7[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp7[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp7[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp7[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp7[19]);
			}
			if (V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp7[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp7[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp7[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp7[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp7[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp7[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp7[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp7[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp7[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp7[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp7[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp7[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp7[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp7[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp7[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp7[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp7[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp7[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp7[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp7[39]);
			}
		}
		if (V_SideQuestTagExpansion == "Anh")
		{
			if (V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp7[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp7[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp7[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp7[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp7[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp7[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp7[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp7[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp7[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp7[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp7[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp7[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp7[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp7[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp7[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp7[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp7[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp7[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp7[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp7[19]);
			}
			if (V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp7[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp7[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp7[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp7[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp7[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp7[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp7[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp7[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp7[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp7[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp7[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp7[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp7[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp7[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp7[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp7[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp7[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp7[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp7[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp7[39]);
			}
		}
		if (V_SideQuestTagExpansion == "Soc")
		{
			if (V_SideQuestTagPage == "1")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp7[0]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp7[1]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp7[2]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp7[3]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp7[4]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp7[5]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp7[6]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp7[7]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp7[8]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp7[9]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp7[10]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp7[11]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp7[12]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp7[13]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp7[14]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp7[15]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp7[16]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp7[17]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp7[18]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp7[19]);
			}
			if (V_SideQuestTagPage == "2")
			{
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, V_HaveKeyItemExp7[20]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, V_HaveKeyItemExp7[21]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, V_HaveKeyItemExp7[22]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, V_HaveKeyItemExp7[23]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, V_HaveKeyItemExp7[24]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, V_HaveKeyItemExp7[25]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, V_HaveKeyItemExp7[26]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, V_HaveKeyItemExp7[27]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, V_HaveKeyItemExp7[28]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, V_HaveKeyItemExp7[29]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, V_HaveKeyItemExp7[30]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, V_HaveKeyItemExp7[31]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, V_HaveKeyItemExp7[32]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, V_HaveKeyItemExp7[33]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, V_HaveKeyItemExp7[34]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, V_HaveKeyItemExp7[35]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, V_HaveKeyItemExp7[36]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, V_HaveKeyItemExp7[37]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, V_HaveKeyItemExp7[38]);
				DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, V_HaveKeyItemExp7[39]);
			}
		}

		DrawQuestListBack();
		DrawQuestListNext();

		return;
	}

	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr1Y, MouseOverX1L, MouseOverY1L1, MouseOverX2L, MouseOverY2L1, 1, V_SideQuestListStrL1, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr2Y, MouseOverX1L, MouseOverY1L2, MouseOverX2L, MouseOverY2L2, 2, V_SideQuestListStrL2, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr3Y, MouseOverX1L, MouseOverY1L3, MouseOverX2L, MouseOverY2L3, 3, V_SideQuestListStrL3, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr4Y, MouseOverX1L, MouseOverY1L4, MouseOverX2L, MouseOverY2L4, 4, V_SideQuestListStrL4, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr5Y, MouseOverX1L, MouseOverY1L5, MouseOverX2L, MouseOverY2L5, 5, V_SideQuestListStrL5, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr6Y, MouseOverX1L, MouseOverY1L6, MouseOverX2L, MouseOverY2L6, 6, V_SideQuestListStrL6, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr7Y, MouseOverX1L, MouseOverY1L7, MouseOverX2L, MouseOverY2L7, 7, V_SideQuestListStrL7, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr8Y, MouseOverX1L, MouseOverY1L8, MouseOverX2L, MouseOverY2L8, 8, V_SideQuestListStrL8, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr9Y, MouseOverX1L, MouseOverY1L9, MouseOverX2L, MouseOverY2L9, 9, V_SideQuestListStrL9, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr10Y, MouseOverX1L, MouseOverY1L10, MouseOverX2L, MouseOverY2L10, 10, V_SideQuestListStrL10, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr11Y, MouseOverX1L, MouseOverY1L11, MouseOverX2L, MouseOverY2L11, 11, V_SideQuestListStrL11, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr12Y, MouseOverX1L, MouseOverY1L12, MouseOverX2L, MouseOverY2L12, 12, V_SideQuestListStrL12, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr13Y, MouseOverX1L, MouseOverY1L13, MouseOverX2L, MouseOverY2L13, 13, V_SideQuestListStrL13, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr14Y, MouseOverX1L, MouseOverY1L14, MouseOverX2L, MouseOverY2L14, 14, V_SideQuestListStrL14, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr15Y, MouseOverX1L, MouseOverY1L15, MouseOverX2L, MouseOverY2L15, 15, V_SideQuestListStrL15, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr16Y, MouseOverX1L, MouseOverY1L16, MouseOverX2L, MouseOverY2L16, 16, V_SideQuestListStrL16, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr17Y, MouseOverX1L, MouseOverY1L17, MouseOverX2L, MouseOverY2L17, 17, V_SideQuestListStrL17, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr18Y, MouseOverX1L, MouseOverY1L18, MouseOverX2L, MouseOverY2L18, 18, V_SideQuestListStrL18, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr19Y, MouseOverX1L, MouseOverY1L19, MouseOverX2L, MouseOverY2L19, 19, V_SideQuestListStrL19, 1);
	DrawQuestListItem(PlayerInfoTextStrLX, PlayerInfoTextStr20Y, MouseOverX1L, MouseOverY1L20, MouseOverX2L, MouseOverY2L20, 20, V_SideQuestListStrL20, 1);

	DrawQuestListBack();
	DrawQuestListNext();
}

VOID DrawQuestText()
{
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr1Y, 0, 0, 0, -1, V_PlayerInfoText1);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr2Y, 0, 0, 0, -1, V_PlayerInfoText2);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr3Y, 0, 0, 0, -1, V_PlayerInfoText3);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr4Y, 0, 0, 0, -1, V_PlayerInfoText4);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr5Y, 0, 0, 0, -1, V_PlayerInfoText5);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr6Y, 0, 0, 0, -1, V_PlayerInfoText6);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr7Y, 0, 0, 0, -1, V_PlayerInfoText7);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr8Y, 0, 0, 0, -1, V_PlayerInfoText8);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr9Y, 0, 0, 0, -1, V_PlayerInfoText9);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr10Y, 0, 0, 0, -1, V_PlayerInfoText10);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr11Y, 0, 0, 0, -1, V_PlayerInfoText11);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr12Y, 0, 0, 0, -1, V_PlayerInfoText12);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr13Y, 0, 0, 0, -1, V_PlayerInfoText13);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr14Y, 0, 0, 0, -1, V_PlayerInfoText14);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr15Y, 0, 0, 0, -1, V_PlayerInfoText15);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr16Y, 0, 0, 0, -1, V_PlayerInfoText16);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr17Y, 0, 0, 0, -1, V_PlayerInfoText17);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr18Y, 0, 0, 0, -1, V_PlayerInfoText18);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr19Y, 0, 0, 0, -1, V_PlayerInfoText19);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr20Y, 0, 0, 0, -1, V_PlayerInfoText20);
	V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoTextStr21Y, 0, 0, 0, -1, V_PlayerInfoText21);

	if(V_MenuObject == 3)
	{
		DrawQuestTextBack();
		DrawQuestTextNext();
	}
	else if(V_MenuObject == 4 && V_SideQuestSelected > 0)
	{
		DrawKeyItemTextOff();
		DrawKeyItemTextOn();
	}
}

VOID DrawExpansionListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iExpansionId, LPSTR szExpansionTitle)
{
	std::string str = szExpansionTitle;
	if (str != "")
	{
		if ((*p_D2CLIENT_MouseX >= iMouseOverX1 && *p_D2CLIENT_MouseX <= iMouseOverX2) && (*p_D2CLIENT_MouseY >= iMouseOverY1 && *p_D2CLIENT_MouseY <= iMouseOverY2))
		{
			V_Design->TextHook(iTextX, iTextY, 3, 0, 1, -1, szExpansionTitle);

			PlayMenuSound(iExpansionId, 0);
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					ResetQuestsMenu();

					V_SideQuestExpansion = iExpansionId;
					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			V_Design->TextHook(iTextX, iTextY, 0, 0, 1, -1, szExpansionTitle);

			PlayMenuSound(iExpansionId, 1);
		}
	}
}

VOID DrawQuestListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iQuestId, LPSTR szQuestTitle, INT iEnabled)
{
	std::string str = szQuestTitle;
	if (str != "")
	{
		if ((GetUnitStat(Me, STAT_LEVEL) < V_SideQuestLevel[iQuestId]) && V_MenuObject != 4)  // Menu object 4 is key items
		{
			V_Design->TextHook(iTextX, iTextY, 5, 0, 1, -1, V_QuestUnavailableStr);

			return;
		}
		if ((*p_D2CLIENT_MouseX >= iMouseOverX1 && *p_D2CLIENT_MouseX <= iMouseOverX2) && (*p_D2CLIENT_MouseY >= iMouseOverY1 && *p_D2CLIENT_MouseY <= iMouseOverY2))
		{
			if(iEnabled < 1)
			{
				V_Design->TextHook(iTextX, iTextY, 5, 0, 1, -1, V_CounterUnknownStr);
			}
			else
			{
				V_Design->TextHook(iTextX, iTextY, 3, 0, 1, -1, szQuestTitle);
			}

			if(iEnabled > 0)
			{
				PlayMenuSound(iQuestId, 0);
			}
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					if(iEnabled > 0)
					{
						ResetQuestsMenu();

						V_SideQuestSelected = iQuestId;

						if (V_MenuObject == 3)
						{
							LoadScriptText(iQuestId, V_SelectedQuestPageText);
						}
						else if (V_MenuObject == 4)
						{
							LoadKeyItemText(iQuestId, V_SelectedQuestPageText);
						}

						D2CLIENT_PlaySound(STAND_PASS);
					}

					V_ClickDelay = TRUE;

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			if (V_SideQuestSelected == iQuestId)
			{
				V_Design->TextHook(iTextX, iTextY, 3, 0, 1, -1, szQuestTitle);
			}
			else
			{
				if(iEnabled < 1)
				{
					V_Design->TextHook(iTextX, iTextY, 5, 0, 1, -1, V_CounterUnknownStr);
				}
				else
				{
					V_Design->TextHook(iTextX, iTextY, 0, 0, 1, -1, szQuestTitle);
				}
			}

			PlayMenuSound(iQuestId, 1);
		}
	}
}

VOID DrawQuestListBack()
{
	if ((*p_D2CLIENT_MouseX >= MouseOverX1L && *p_D2CLIENT_MouseX <= MouseOverX2L) && (*p_D2CLIENT_MouseY >= MouseOverY1LBack && *p_D2CLIENT_MouseY <= MouseOverY2LBack))
	{
		V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoBackStrY, 3, 0, 1, -1, V_SideQuestStrBack);

		if (!V_BackSoundSelectB)
		{
			D2CLIENT_PlaySound(STAND_PASS);

			V_BackSoundSelectB = TRUE;
		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				ResetQuestsMenu();

				V_SideQuestBack = TRUE;

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
			}
		}
	}
	else
	{
		V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoBackStrY, 0, 0, 1, -1, V_SideQuestStrBack);

		V_BackSoundSelectB = FALSE;
	}
}

VOID DrawQuestListNext()
{
	if ((*p_D2CLIENT_MouseX >= MouseOverX1L && *p_D2CLIENT_MouseX <= MouseOverX2L) && (*p_D2CLIENT_MouseY >= MouseOverY1LNext && *p_D2CLIENT_MouseY <= MouseOverY2LNext))
	{
		if (V_SelectedQuestPage == V_SideQuestListPages)
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 5, 0, 1, -1, V_SideQuestStrNext);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 3, 0, 1, -1, V_SideQuestStrNext);
		}

		if (!V_NextSoundSelectB)
		{
			if (V_SelectedQuestPage < V_SideQuestListPages)
			{
				D2CLIENT_PlaySound(STAND_PASS);

				V_NextSoundSelectB = TRUE;
			}
		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				ResetQuestsMenu();

				V_SideQuestNext = TRUE;

				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
			}
		}
	}
	else
	{
		if (V_SelectedQuestPage == V_SideQuestListPages)
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 5, 0, 1, -1, V_SideQuestStrNext);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrLX, PlayerInfoNextStrY, 0, 0, 1, -1, V_SideQuestStrNext);
		}

		V_NextSoundSelectB = FALSE;
	}
}

VOID DrawQuestTextBack()
{
	if (V_SideQuestTextPages > 1)
	{
		if ((*p_D2CLIENT_MouseX >= MouseOverX1BackText && *p_D2CLIENT_MouseX <= MouseOverX2BackText) && (*p_D2CLIENT_MouseY >= MouseOverY1BackText && *p_D2CLIENT_MouseY <= MouseOverY2BackText))
		{
			if (V_SelectedQuestPageText == 1)
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 5, 0, 1, -1, V_SideQuestStrBack);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 3, 0, 1, -1, V_SideQuestStrBack);
			}

			if (!V_BackTextSoundSelectB)
			{
				if (V_SelectedQuestPageText > 1)
				{
					D2CLIENT_PlaySound(STAND_PASS);

					V_BackTextSoundSelectB = TRUE;
				}
			}
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					ResetQuestsText();

					V_SideQuestBackText = TRUE;

					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			if (V_SelectedQuestPageText == 1)
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 5, 0, 1, -1, V_SideQuestStrBack);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 0, 0, 1, -1, V_SideQuestStrBack);
			}

			V_BackTextSoundSelectB = FALSE;
		}
	}
}

VOID DrawQuestTextNext()
{
	if (V_SideQuestTextPages > 1)
	{
		if ((*p_D2CLIENT_MouseX >= MouseOverX1NextText && *p_D2CLIENT_MouseX <= MouseOverX2NextText) && (*p_D2CLIENT_MouseY >= MouseOverY1NextText && *p_D2CLIENT_MouseY <= MouseOverY2NextText))
		{
			if (V_SelectedQuestPageText == V_SideQuestTextPages)
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 5, 0, 1, -1, V_SideQuestStrNext);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 3, 0, 1, -1, V_SideQuestStrNext);
			}

			if (!V_NextTextSoundSelectB)
			{
				if (V_SelectedQuestPageText < V_SideQuestTextPages)
				{
					D2CLIENT_PlaySound(STAND_PASS);

					V_NextTextSoundSelectB = TRUE;
				}
			}
			if (!V_ClickDelay)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					ResetQuestsText();

					V_SideQuestNextText = TRUE;

					V_ClickDelay = TRUE;

					D2CLIENT_PlaySound(STAND_PASS);

					V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
				}
			}
		}
		else
		{
			if (V_SelectedQuestPageText == V_SideQuestTextPages)
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 5, 0, 1, -1, V_SideQuestStrNext);
			}
			else
			{
				V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 0, 0, 1, -1, V_SideQuestStrNext);
			}

			V_NextTextSoundSelectB = FALSE;
		}
	}
}

VOID DrawKeyItemTextOff()
{
	if ((*p_D2CLIENT_MouseX >= MouseOverX1BackText && *p_D2CLIENT_MouseX <= MouseOverX2BackText) && (*p_D2CLIENT_MouseY >= MouseOverY1BackText && *p_D2CLIENT_MouseY <= MouseOverY2BackText))
	{
		if (V_ToggleKeyItem[V_SideQuestSelected - 1][V_SideQuestExpansion] == 0)
		{
			V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 1, 0, 1, -1, V_KeyItemStrOff);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 3, 0, 1, -1, V_KeyItemStrOff); 
		}

		if (!V_BackTextSoundSelectB)
		{
			if (V_SelectedQuestPageText > 1)
			{
				D2CLIENT_PlaySound(STAND_PASS);

				V_BackTextSoundSelectB = TRUE;
			}
		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_ToggleKeyItem[V_SideQuestSelected - 1][V_SideQuestExpansion] = FALSE;

				PreloadSettings();

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
			}
		}
	}
	else
	{
		if (V_ToggleKeyItem[V_SideQuestSelected - 1][V_SideQuestExpansion] == 1)
		{
			V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 5, 0, 1, -1, V_KeyItemStrOff);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrRX, PlayerInfoNextStrY, 1, 0, 1, -1, V_KeyItemStrOff);
		}

		V_BackTextSoundSelectB = FALSE;
	}
}

VOID DrawKeyItemTextOn()
{
	if ((*p_D2CLIENT_MouseX >= MouseOverX1NextText && *p_D2CLIENT_MouseX <= MouseOverX2NextText) && (*p_D2CLIENT_MouseY >= MouseOverY1NextText && *p_D2CLIENT_MouseY <= MouseOverY2NextText))
	{
		if (V_ToggleKeyItem[V_SideQuestSelected - 1][V_SideQuestExpansion] == 1)
		{
			V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 2, 0, 1, -1, V_KeyItemStrOn);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 3, 0, 1, -1, V_KeyItemStrOn);
		}

		if (!V_NextTextSoundSelectB)
		{
			if (V_SelectedQuestPageText < V_SideQuestTextPages)
			{
				D2CLIENT_PlaySound(STAND_PASS);

				V_NextTextSoundSelectB = TRUE;
			}
		}
		if (!V_ClickDelay)
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				V_ClickDelay = TRUE;

				D2CLIENT_PlaySound(STAND_PASS);

				V_ToggleKeyItem[V_SideQuestSelected - 1][V_SideQuestExpansion] = TRUE;

				PreloadSettings();

				V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)DELAYCLICK));
			}
		}
	}
	else
	{
		if (V_ToggleKeyItem[V_SideQuestSelected - 1][V_SideQuestExpansion] == 0)
		{
			V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 5, 0, 1, -1, V_KeyItemStrOn);
		}
		else
		{
			V_Design->TextHook(PlayerInfoTextStrNextX, PlayerInfoNextStrY, 2, 0, 1, -1, V_KeyItemStrOn);
		}

		V_NextTextSoundSelectB = FALSE;
	}
}
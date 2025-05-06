VOID DrawInfoMain();
VOID DrawInfoList(INT Group);
VOID DrawInfoText();

VOID DrawGroupListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iGroupId, LPSTR szGroupTitle);
VOID DrawInfoListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iInfoId, LPSTR szInfoTitle);

VOID DrawInfoListBack();
VOID DrawInfoListNext();
VOID DrawInfoTextBack();
VOID DrawInfoTextNext();

VOID DrawQuestMain();
VOID DrawQuestList();
VOID DrawQuestText();

VOID DrawExpansionListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iExpansionId, LPSTR szExpansionTitle);
VOID DrawQuestListItem(INT iTextX, INT iTextY, INT iMouseOverX1, INT iMouseOverY1, INT iMouseOverX2, INT iMouseOverY2, INT iQuestId, LPSTR szQuestTitle, INT iEnabled);

VOID DrawQuestListBack();
VOID DrawQuestListNext();
VOID DrawQuestTextBack();
VOID DrawQuestTextNext();

VOID DrawKeyItemTextOff();
VOID DrawKeyItemTextOn();
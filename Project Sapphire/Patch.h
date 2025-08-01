#define CopyAndPasteBugFix	INST_JMP
#define FloorsInside		INST_NOP
#define LeftClickAllSkills	0xEB
#define ShiftClickFarcast	0x01
#define ShrineDistance		INST_NOP
#define WallsInside			INST_NOP

PATCH Patches[] =
{
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x727B3),   (DWORD)AddShrineSTUB,               6,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xA302B),   (DWORD)AfterAttackSTUB,               10,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x3CB20),   (DWORD)AttackLoop,                  6,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x70FAA),   (DWORD)AutomapCells,               5,   INGAME}, //updated 1.13d
   {PatchJmp,      DLLOFFSET(D2CLIENT,      0x1D7B5),   (DWORD)DrawSTUB,                  5,   INGAME}, //updated 1.13d
   {PatchJmp,      DLLOFFSET(D2CLIENT,      0x73469),   (DWORD)DrawAutomapSTUB,               5,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x1D4A1),   (DWORD)DrawEnteringLevelTextSTUB,      5,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x6F34E),   (DWORD)DrawManaOrbSTUB,               5,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x45153),   (DWORD)EndSTUB,                     5,   INGAME},
   {PatchFill,      DLLOFFSET(D2CLIENT,      0x731A4),   (DWORD)FloorsInside,               2,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x23397),   (DWORD)FullLightRadiusSTUB,            5,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x48F80),   (DWORD)GameAfterAttack,               5,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x452F2),   (DWORD)GameShake,                  5,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x1BF94),   (DWORD)GetSelectedUnit,               5,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x9EA65),   (DWORD)GetViewingUnit,               5,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xBCBA3),   (DWORD)GetViewingUnit,               5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xBCEA6),   (DWORD)GetViewingUnit,               5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xBD743),   (DWORD)GetViewingUnit,               5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xBB983),   (DWORD)InfraVisionSTUB,               7,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0xB254C),   (DWORD)InputLineSTUB1,               5,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0xB186B),   (DWORD)InputLineSTUB2,               5,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0xB2342),   (DWORD)InputSTUB,                  5,   INGAME}, //updated 1.13d
   {PatchBytes,   DLLOFFSET(D2CLIENT,      0x5BE3F),   (DWORD)INST_NOP,                  2,   INGAME}, //updated 1.13d
   {PatchBytes,   DLLOFFSET(D2CLIENT,      0x29573),   (DWORD)INST_NOP,                  6,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x2DEED),   (DWORD)ItemBasicStatSTUB,            5,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x96736),   (DWORD)ItemNameSTUB,               6,   INGAME}, //updated 1.13d
//{PatchBytes,   DLLOFFSET(D2CLIENT,      0xA74C4),   (DWORD)LeftClickAllSkills,            1,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x61E70),   (DWORD)LoadAutomapLayerFromFileSTUB,   6,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x45280),   (DWORD)LoopSTUB,                  7,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x7D8A8),   (DWORD)MessageLogSTUB1,               5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x7D61F),   (DWORD)MessageLogSTUB2,               5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x20FBE),   (DWORD)MonsterDeathSTUB,            5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x1FE3B),   (DWORD)MonsterDescCommaSTUB1,         5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x1FF25),   (DWORD)MonsterDescCommaSTUB2,         5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xC0C01),   (DWORD)MonsterDescCommaSTUB3,         6,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x3A965),   (DWORD)OnGameKeyDownSTUB,            7,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x83301),   (DWORD)OnGamePacketReceivedSTUB,      5,   INGAME}, //updated 1.13d
   {PatchJmp,      DLLOFFSET(D2CLIENT,      0xD13C),   (DWORD)OnGamePacketSentSTUB,         6,   INGAME}, //updated 1.13d
   //{PatchJmp,      DLLOFFSET(D2CLIENT,      0xD252),   (DWORD)OnGamePacketSentSTUB,         6,   MPGAME}, //test 1.13
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x29560),   (DWORD)OnUseSkillSTUB,               5,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x2B425),   (DWORD)OutTownSelectSTUB1,            6,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x631E1),   (DWORD)OutTownSelectSTUB2,            6,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x6328E),   (DWORD)OutTownSelectSTUB3,            6,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x71ED4),   (DWORD)OverrideShrineSTUB,            7,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xC5A24),   (DWORD)PassingActBugFixSTUB,         9,   INGAME},
   //{PatchJmp,      DLLOFFSET(D2CLIENT,      0xADF37),   (DWORD)PlayerAssignmentSTUB,         5,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x7270D),   (DWORD)PlayerBlobSTUB,               6,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x61140),   (DWORD)SaveAutomapLayerToFileSTUB,      5,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0xB5FA6),   (DWORD)ShakeSTUB,                  6,   INGAME}, //updated 1.13d
   {PatchBytes,   DLLOFFSET(D2CLIENT,      0x2ACA7),   (DWORD)ShiftClickFarcast,            1,   INGAME}, //updated 1.13d
   {PatchFill,      DLLOFFSET(D2CLIENT,      0x72761),   (DWORD)ShrineDistance,               6,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x9D544),   (DWORD)SocketProtectionSTUB1,         6,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x9B4FB),   (DWORD)SocketProtectionSTUB2,         6,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x93450),   (DWORD)SocketViewtableSTUB1,         5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x933E2),   (DWORD)SocketViewtableSTUB2,         5,   INGAME},
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x997B2),   (DWORD)ViewInventorySTUB1,            6,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x98E84),   (DWORD)ViewInventorySTUB2,            6,   INGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2CLIENT,      0x97E3F),   (DWORD)ViewInventorySTUB3,            5,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x99120),   (DWORD)ViewInventorySTUB4,            5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x2FE63),   (DWORD)ViewStatSTUB1,            6,   INGAME},
   //{PatchCall,      DLLOFFSET(D2CLIENT,      0xBC524),   (DWORD)ViewStatSTUB2,            6,   INGAME},
   {PatchFill,      DLLOFFSET(D2CLIENT,      0x731EA),   (DWORD)WallsInside,                  2,   INGAME}, //updated 1.13d

   //{PatchJmp,      DLLOFFSET(D2COMMON,      0x325B1),   (DWORD)FrameRemainSTUB,               5,   INGAME},
   {PatchJmp,      DLLOFFSET(D2COMMON,      0x60D1E),   (DWORD)WeatherSTUB,                  5,   INGAME}, //updated 1.13d

   {PatchCall,      DLLOFFSET(D2MCPCLIENT,   0x6297),   (DWORD)OnMCPPacketReceivedSTUB,         5,   OUTGAME}, //updated 1.13d

   {PatchCall,      DLLOFFSET(D2MULTI,      0xAD8F),   (DWORD)CreateGameBoxSTUB,            5,   OUTGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2MULTI,      0x8413),   (DWORD)DestroyGameList,               5,   OUTGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2MULTI,      0xADAB),   (DWORD)NextGameName,               5,   OUTGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2MULTI,      0xB5E9),   (DWORD)NextGameName,               5,   OUTGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2MULTI,      0xADE6),   (DWORD)NextGamePassword,            5,   OUTGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2MULTI,      0xB6BC),   (DWORD)NextGamePassword,            5,   OUTGAME}, //updated 1.13d
   {PatchCall,      DLLOFFSET(D2MULTI,      0x121EE),   (DWORD)RefreshGameListSTUB,            5,   OUTGAME}, //updated 1.13d

   //{PatchFill,      DLLOFFSET(D2WIN,      0x9E1A),   (DWORD)CopyAndPasteBugFix,            1,   INGAME},
   //{PatchCall,      DLLOFFSET(D2WIN,      0x12C68),   (DWORD)LifeBarSTUB,                  6,   INGAME},
   {PatchCall,      DLLOFFSET(D2WIN,      0x12480),   (DWORD)MonsterLifeBarNameSTUB,         6,   INGAME}, //updated 1.13d
   //{PatchCall,      DLLOFFSET(D2WIN,      0x17740),   (DWORD)WindowProcSTUB,               5,   INGAME},
   //{PatchCall,      DLLOFFSET(D2WIN,      0xEC61),   (DWORD)WinDrawSTUB,                  5,   OUTGAME}, //updted 1.13d

   //{PatchCall,      DLLOFFSET(D2CLIENT,      0x8450E), (DWORD)GameStart, 5, OUTGAME}, // Overrides  call    D2Common_GetActNoByLevelNo_10864
   //{PatchJmp,      DLLOFFSET(D2WIN, -10054), (DWORD)GameEnd, 5, INGAME},

   //{PatchCall,      DLLOFFSET(D2WIN,      0xEC68), (DWORD)GameDrawOOG_Intercept,			5, OUTGAME},
   //{PatchJmp,      DLLOFFSET(D2CLIENT,      0x1D7B4), (DWORD)GameDraw_InterceptSTUB,			6,	INGAME}
};
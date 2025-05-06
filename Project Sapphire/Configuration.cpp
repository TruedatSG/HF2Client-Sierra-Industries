#include "Hack.h"

static BOOL DebugMsg = FALSE;

CONFIGURATION C[] =
{
	{"Registration",	"Key",												NULL,	INTEGER,	&V_Key},
	{"Registration",	"Time of Release",									NULL,	INTEGER,	&V_ToR},

	/*
	{"Aim",				"On",												NULL,	BOOLEAN,	&V_Aim},
	{"Aim",				"Block Fake Attacks/Casts",							NULL,	BOOLEAN,	&V_BlockFakes},
	//{"Aim",				"Hostile Targets Only",								NULL,	BOOLEAN,	&V_HostilesOnly},
	{"Aim",				"Automatic Blind Teleport Max Distance",			NULL,	INTEGER,	&V_AutoBlindDistance},
	{"Aim",				"Automatic Knockback Max Distance",					NULL,	INTEGER,	&V_AutoKBDistance},
	{"Aim",				"Attack Myself With Left Skill Hotkey",				NULL,	INTEGER,	&K_AttackMyselfLeft},
	{"Aim",				"Attack Myself With Right Skill Hotkey",			NULL,	INTEGER,	&K_AttackMyselfRight},
	{"Aim",				"Attack Target With Left Skill Hotkey",				NULL,	INTEGER,	&K_AttackTargetLeft},
	{"Aim",				"Attack Target With Right Skill Hotkey",			NULL,	INTEGER,	&K_AttackTargetRight},
	{"Aim",				"Attack Nearest Target With Left Skill Hotkey",		NULL,	INTEGER,	&K_AttackNearestTargetLeft},
	{"Aim",				"Attack Nearest Target With Right Skill Hotkey",	NULL,	INTEGER,	&K_AttackNearestTargetRight},
	{"Aim",				"Toggle Aim Type Hotkey",							NULL,	INTEGER,	&K_Blind},
	{"Aim",				"Toggle Automatic Blind Teleport Hotkey",			NULL,	INTEGER,	&K_AutoBlind},
	{"Aim",				"Toggle Automatic Knockback Hotkey",				NULL,	INTEGER,	&K_AutoKB},
	{"Aim",				"Next Target Hotkey",								NULL,	INTEGER,	&K_NextTarget},
	{"Aim",				"Previous Target Hotkey",							NULL,	INTEGER,	&K_PreviousTarget},
	{"Aim",				"Set Kick As Left Skill Hotkey",					NULL,	INTEGER,	&K_SetKickLeft},
	{"Aim",				"Set Kick As Right Skill Hotkey",					NULL,	INTEGER,	&K_SetKickRight},

	{"Death Message",	"On",												NULL,	BOOLEAN,	&V_DeathMessage},
	{"Death Message",	"Delay",											NULL,	INTEGER,	&V_DeathMessageDelay},
	{"Death Message",	"Line 1",											NULL,	STRING,		&V_Line1},
	{"Death Message",	"Line 2",											NULL,	STRING,		&V_Line2},
	{"Death Message",	"Line 3",											NULL,	STRING,		&V_Line3},
	{"Death Message",	"Line 4",											NULL,	STRING,		&V_Line4},
	{"Death Message",	"Line 5",											NULL,	STRING,		&V_Line5},
	{"Death Message",	"Line 6",											NULL,	STRING,		&V_Line6},
	{"Death Message",	"Line 7",											NULL,	STRING,		&V_Line7},
	{"Death Message",	"Line 8",											NULL,	STRING,		&V_Line8},
	{"Death Message",	"Line 9",											NULL,	STRING,		&V_Line9},
	{"Death Message",	"Line 10",											NULL,	STRING,		&V_Line10},
	{"Death Message",	"Line 11",											NULL,	STRING,		&V_Line11},
	{"Death Message",	"Line 12",											NULL,	STRING,		&V_Line12},
	{"Death Message",	"Line 13",											NULL,	STRING,		&V_Line13},
	{"Death Message",	"Line 14",											NULL,	STRING,		&V_Line14},
	{"Death Message",	"Line 15",											NULL,	STRING,		&V_Line15},
	{"Death Message",	"Line 16",											NULL,	STRING,		&V_Line16},
	{"Death Message",	"Line 17",											NULL,	STRING,		&V_Line17},
	{"Death Message",	"Line 18",											NULL,	STRING,		&V_Line18},
	{"Death Message",	"Line 19",											NULL,	STRING,		&V_Line19},
	{"Death Message",	"Line 20",											NULL,	STRING,		&V_Line20},

	{"Design",			"Toggle Hotkey",									NULL,	INTEGER,	&K_Clean},
	{"Design",			"Hide On Screenshot",								NULL,	BOOLEAN,	&V_Screenshot},

	{"Design",			"Life/Mana % Orbs",									NULL,	BOOLEAN,	&V_Orbs},
	{"Design",			"Mouse Coordinates",								NULL,	BOOLEAN,	&V_Mouse},
	{"Design",			"Player Life %",									NULL,	BOOLEAN,	&V_PlayerLifePercent},
	{"Design",			"Player Life Bar",									NULL,	BOOLEAN,	&V_PlayerLifeBar},
	{"Design",			"Vectors",											NULL,	BOOLEAN,	&V_Vectors},

	{"Design",			"Hostile Player Color",								NULL,	INTEGER,	&V_HostilePlayerColor},
	{"Design",			"Targetted Player Color",							NULL,	INTEGER,	&V_TargetPlayerColor},

	{"Design",			"Automap Info Game Name Text",						NULL,	STRING,		&V_AutomapInfoGameNameText},
	{"Design",			"Automap Info Game Name Font Color",				NULL,	INTEGER,	&V_AutomapInfoGameNameColor},
	{"Design",			"Automap Info Game Name Font Type",					NULL,	INTEGER,	&V_AutomapInfoGameNameFont},

	{"Design",			"Automap Info Game Password Text",					NULL,	STRING,		&V_AutomapInfoGamePasswordText},
	{"Design",			"Automap Info Game Password Font Color",			NULL,	INTEGER,	&V_AutomapInfoGamePasswordColor},
	{"Design",			"Automap Info Game Password Font Type",				NULL,	INTEGER,	&V_AutomapInfoGamePasswordFont},

	{"Design",			"Automap Info Level Name Text",						NULL,	STRING,		&V_AutomapInfoLevelText},
	{"Design",			"Automap Info Level Name Font Color",				NULL,	INTEGER,	&V_AutomapInfoLevelColor},
	{"Design",			"Automap Info Level Name Font Type",				NULL,	INTEGER,	&V_AutomapInfoLevelFont},

	{"Design",			"Automap Info Difficulty Text",						NULL,	STRING,		&V_AutomapInfoDifficultyText},
	{"Design",			"Automap Info Difficulty Font Color",				NULL,	INTEGER,	&V_AutomapInfoDifficultyColor},
	{"Design",			"Automap Info Difficulty Font Type",				NULL,	INTEGER,	&V_AutomapInfoDifficultyFont},

	{"Design",			"Automap Info IP Text",								NULL,	STRING,		&V_AutomapInfoIPText},
	{"Design",			"Automap Info IP Font Color",						NULL,	INTEGER,	&V_AutomapInfoIPColor},
	{"Design",			"Automap Info IP Font Type",						NULL,	INTEGER,	&V_AutomapInfoIPFont},

	{"Design",			"Automap Info Local Time Text",						NULL,	STRING,		&V_AutomapInfoLocalTimeText},
	{"Design",			"Automap Info Local Time Font Color",				NULL,	INTEGER,	&V_AutomapInfoLocalTimeColor},
	{"Design",			"Automap Info Local Time Font Type",				NULL,	INTEGER,	&V_AutomapInfoLocalTimeFont},

	{"Design",			"Automap Info Time Zone PDT",						NULL,	BOOLEAN,	&V_AutomapInfoTimeZonePDT},
	{"Design",			"Automap Info DST Start Day",						NULL,	INTEGER,	&V_AutomapInfoDSTStart},
	{"Design",			"Automap Info DST End Day",							NULL,	INTEGER,	&V_AutomapInfoDSTEnd},
	{"Design",			"Automap Info Japan Time Text",						NULL,	STRING,		&V_AutomapInfoJapanTimeText},
	{"Design",			"Automap Info Japan Time Font Color",				NULL,	INTEGER,	&V_AutomapInfoJapanTimeColor},
	{"Design",			"Automap Info Japan Time Font Type",				NULL,	INTEGER,	&V_AutomapInfoJapanTimeFont},

	{"Design",			"Automap Info Game Timer Text",						NULL,	STRING,		&V_AutomapInfoGameTimerText},
	{"Design",			"Automap Info Game Timer Font Color",				NULL,	INTEGER,	&V_AutomapInfoGameTimerColor},
	{"Design",			"Automap Info Game Timer Font Type",				NULL,	INTEGER,	&V_AutomapInfoGameTimerFont},

	{"Design",			"Automap Info FPS Text",							NULL,	STRING,		&V_AutomapInfoFPSText},
	{"Design",			"Automap Info FPS Font Color",						NULL,	INTEGER,	&V_AutomapInfoFPSColor},
	{"Design",			"Automap Info FPS Font Type",						NULL,	INTEGER,	&V_AutomapInfoFPSFont},

	{"Design",			"Automap Info Skip Text",							NULL,	STRING,		&V_AutomapInfoSkipText},
	{"Design",			"Automap Info Skip Font Color",						NULL,	INTEGER,	&V_AutomapInfoSkipColor},
	{"Design",			"Automap Info Skip Font Type",						NULL,	INTEGER,	&V_AutomapInfoSkipFont},

	{"Design",			"Automap Info Ping Text",							NULL,	STRING,		&V_AutomapInfoPingText},
	{"Design",			"Automap Info Ping Font Color",						NULL,	INTEGER,	&V_AutomapInfoPingColor},
	{"Design",			"Automap Info Ping Font Type",						NULL,	INTEGER,	&V_AutomapInfoPingFont},

	{"Design",			"Automap Info Day Of Week Text",					NULL,	STRING,		&V_AutomapInfoDayOfWeekText},
	{"Design",			"Automap Info Day Of Week Font Color",				NULL,	INTEGER,	&V_AutomapInfoDayOfWeekColor},
	{"Design",			"Automap Info Day Of Week Font Type",				NULL,	INTEGER,	&V_AutomapInfoDayOfWeekFont},

	{"Design",			"Automap Info Character Name Text",					NULL,	STRING,		&V_AutomapInfoCharacterNameText},
	{"Design",			"Automap Info Character Name Font Color",			NULL,	INTEGER,	&V_AutomapInfoCharacterNameColor},
	{"Design",			"Automap Info Character Name Font Type",			NULL,	INTEGER,	&V_AutomapInfoCharacterNameFont},

	{"Design",			"Escape Info",										NULL,	BOOLEAN,	&V_EscapeInfo},
	{"Design",			"Escape Info X Position",							NULL,	INTEGER,	&V_EscapeInfoX},
	{"Design",			"Escape Info Y Position",							NULL,	INTEGER,	&V_EscapeInfoY},
	{"Design",			"Escape Info Title Color",							NULL,	INTEGER,	&V_EscapeInfoTitleColor},

	{"Escape",			"Town When Curse With Amplify Damage",				NULL,	BOOLEAN,	&V_TownAmplify},
	{"Escape",			"Town When Cursed With Battle Cry",					NULL,	BOOLEAN,	&V_TownBattleCry},
	{"Escape",			"Town When Cursed With Conviction Aura",			NULL,	BOOLEAN,	&V_TownConvicted},
	{"Escape",			"Town When Cursed With Decrepify",					NULL,	BOOLEAN,	&V_TownDecrepify},
	{"Escape",			"Town When Cursed With Iron Maiden",				NULL,	BOOLEAN,	&V_TownIronMaiden},
	{"Escape",			"Town When Cursed With Lower Resist",				NULL,	BOOLEAN,	&V_TownLowerResist},

	{"Design",			"Experience Info",									NULL,	BOOLEAN,	&V_ExpInfo},
	{"Design",			"Experience Info X Position",						NULL,	INTEGER,	&V_ExpInfoX},
	{"Design",			"Experience Info Y Position",						NULL,	INTEGER,	&V_ExpInfoY},
	{"Design",			"Experience Info Title Color",						NULL,	INTEGER,	&V_ExpInfoTitleColor},

	{"Design",			"Life Orb Color",									NULL,	INTEGER,	&V_LifeOrbColor},
	{"Design",			"Life Orb Font",									NULL,	INTEGER,	&V_LifeOrbFont},
	{"Design",			"Mana Orb Color",									NULL,	INTEGER,	&V_ManaOrbColor},
	{"Design",			"Mana Orb Font",									NULL,	INTEGER,	&V_ManaOrbFont},

	{"Design",			"UI Dash",											NULL,	BOOLEAN,	&V_UIDash},
	{"Design",			"UI Clock",											NULL,	BOOLEAN,	&V_UIClock},
	{"Design",			"Experience Meter",									NULL,	BOOLEAN,	&V_ExpMeter},
	{"Design",			"Experience Info Add Comma",						NULL,	BOOLEAN,	&V_ExpAddComma},
	{"Design",			"Gold Meter",										NULL,	BOOLEAN,	&V_GoldMeter},
	{"Design",			"Life Dots",										NULL,	BOOLEAN,	&V_LifeDots},
	{"Design",			"Transparent Nametag",								NULL,	BOOLEAN,	&V_TransparentNametag},

	{"Design",			"Music Player",										NULL,	BOOLEAN,	&V_MusicPlayer},
	{"Design",			"Music Player X Position",							NULL,	INTEGER,	&V_MusicPlayerX},
	{"Design",			"Music Player Y Position",							NULL,	INTEGER,	&V_MusicPlayerY},
	{"Design",			"Music Player Title Color",							NULL,	INTEGER,	&V_MusicPlayerTitleColor},
	{"Design",			"Music Player Max Song Length",						NULL,	INTEGER,	&V_MusicPlayerSongLength},

	{"Design",			"Potion Info",										NULL,	BOOLEAN,	&V_PotionInfo},
	{"Design",			"Potion Info X Position",							NULL,	INTEGER,	&V_PotionInfoX},
	{"Design",			"Potion Info Y Position",							NULL,	INTEGER,	&V_PotionInfoY},
	{"Design",			"Potion Info Title Color",							NULL,	INTEGER,	&V_PotionInfoTitleColor},

	{"Design",			"State List",										NULL,	BOOLEAN,	&V_StateList},
	{"Design",			"State List X Position",							NULL,	INTEGER,	&V_StateListX},
	{"Design",			"State List Y Position",							NULL,	INTEGER,	&V_StateListY},
	{"Design",			"State List Title Color",							NULL,	INTEGER,	&V_StateListTitleColor},

	{"Design",			"Supplies",											NULL,	BOOLEAN,	&V_Supplies},
	{"Design",			"Supplies X Position",								NULL,	INTEGER,	&V_SuppliesX},
	{"Design",			"Supplies Y Position",								NULL,	INTEGER,	&V_SuppliesY},
	{"Design",			"Supplies Title Color",								NULL,	INTEGER,	&V_SuppliesTitleColor},

	{"Design",			"Gold",												NULL,	BOOLEAN,	&V_Gold},
	{"Design",			"Gold X Position",									NULL,	INTEGER,	&V_GoldX},
	{"Design",			"Gold Y Position",									NULL,	INTEGER,	&V_GoldY},
	{"Design",			"Gold Title Color",									NULL,	INTEGER,	&V_GoldTitleColor},

	{"Design",			"Target Clicking Position",							NULL,	BOOLEAN,	&V_TargetClick},
	{"Design",			"Target Clicking Position Color",					NULL,	INTEGER,	&V_TargetClickColor},

	{"Design",			"Target Vector",									NULL,	BOOLEAN,	&V_TargetVector},
	{"Design",			"Target Vector Color",								NULL,	INTEGER,	&V_TargetVectorColor},

	{"Design",			"Target List",										NULL,	BOOLEAN,	&V_TargetList},
	{"Design",			"Target List X Position",							NULL,	INTEGER,	&V_TargetListX},
	{"Design",			"Target List Y Position",							NULL,	INTEGER,	&V_TargetListY},
	{"Design",			"Target List Title Color",							NULL,	INTEGER,	&V_TargetListTitleColor},
	{"Design",			"Target List Targetted Player Color",				NULL,	INTEGER,	&V_TargetListTargettedColor},
	{"Design",			"Target List Non Targetted Player Color",			NULL,	INTEGER,	&V_TargetListNonTargettedColor},

	{"Design",			"Target Info",										NULL,	BOOLEAN,	&V_TargetInfo},
	{"Design",			"Target Info X Position",							NULL,	INTEGER,	&V_TargetInfoX},
	{"Design",			"Target Info Y Position",							NULL,	INTEGER,	&V_TargetInfoY},
	{"Design",			"Target Info Title Color",							NULL,	INTEGER,	&V_TargetInfoTitleColor},
	{"Design",          "Console X Coord",                                  NULL,   INTEGER,    &V_ConsoleX},
	{"Design",          "Console Y Coord",                                  NULL,   INTEGER,    &V_ConsoleY},

	{"Enchant",			"On",												NULL,	BOOLEAN,	&V_Enchant},
	{"Enchant",			"Note",												NULL,	BOOLEAN,	&V_EnchantNote},
	{"Enchant",			"All Phrase",										NULL,	STRING,		&V_EnchantAll},
	{"Enchant",			"Mercenary Phrase",									NULL,	STRING,		&V_EnchantMercenary},
	{"Enchant",			"Player Phrase",									NULL,	STRING,		&V_EnchantPlayer},

	{"Escape",			"Exit Life %",										NULL,	INTEGER,	&V_LifeExitPercent},
	{"Escape",			"Exit Mana %",										NULL,	INTEGER,	&V_ManaExitPercent},
	{"Escape",			"Town Life %",										NULL,	INTEGER,	&V_LifeTownPercent},
	{"Escape",			"Town Mana %",										NULL,	INTEGER,	&V_ManaTownPercent},
	{"Escape",			"Town Interval Time",								NULL,	INTEGER,	&V_TPIntervalTime},
	{"Escape",			"Town When Hostiled",								NULL,	BOOLEAN,	&V_TPWhenHostiled},
	{"Escape",			"Town When Attacked",								NULL,	BOOLEAN,	&V_TPWhenAttacked},
	{"Escape",			"Exit When Hostiled",								NULL,	BOOLEAN,	&V_ExitWhenHostiled},
	{"Escape",			"Block Town Portal",								NULL,	BOOLEAN,	&V_BlockTP},
	{"Escape",			"Fast Town Portal",									NULL,	BOOLEAN,	&V_FastTP},
	{"Escape",			"Remove Town Portal Delay",							NULL,	BOOLEAN,	&V_NoTPDelay},
	{"Escape",			"Fast Exit Hotkey",									NULL,	INTEGER,	&K_Exit},
	{"Escape",			"Fast Town Hotkey",									NULL,	INTEGER,	&K_Town},
	{"Escape",			"Fast Portal Hotkey",								NULL,	INTEGER,	&K_TP},

	{"Flash",			"Anti Flash",										NULL,	BOOLEAN,	&V_AntiFlash},
	{"Flash",			"Flash Target Hotkey",								NULL,	INTEGER,	&K_Flash},
	{"Flash",			"Flash Delay",										NULL,	INTEGER,	&V_FlashDelay},

	{"Game Filter",		"On",												NULL,	BOOLEAN,	&V_GameFilter},

	{"Miscellaneous",	"Anti Item Glitch",									NULL,	BOOLEAN,	&V_AntiItemGlitch},
	{"Miscellaneous",	"Anti Minimize",									NULL,	BOOLEAN,	&V_AntiMinimize},
	{"Miscellaneous",	"Auto Party",										NULL,	BOOLEAN,	&V_AutoParty},
	{"Miscellaneous",	"Anti Quest Box",									NULL,	BOOLEAN,	&V_AntiQuestBox},
	{"Miscellaneous",	"Control Hotkey",									NULL,	INTEGER,	&K_ControlHotkey},
	{"Miscellaneous",	"Copy & Paste",										NULL,	BOOLEAN,	&V_CopyPaste},
	{"Miscellaneous",	"Load Configuration Hotkey",						NULL,	INTEGER,	&K_LoadConfiguration},
	{"Miscellaneous",	"Log In-Game Messages",								NULL,	BOOLEAN,	&V_LogInGameMessages},
	{"Miscellaneous",	"Log Kills",										NULL,	BOOLEAN,	&V_KillLog},
	{"Miscellaneous",	"Modified Join Message",							NULL,	BOOLEAN,	&V_ModifiedJoinMessage},
	//{"Miscellaneous",	"Monster Death Animation",							NULL,	BOOLEAN,	&V_MonsterDeathAnimation},
	{"Miscellaneous",	"Remember Game Name",								NULL,	BOOLEAN,	&V_RememberGameName},
	{"Miscellaneous",	"Remember Game Password",							NULL,	BOOLEAN,	&V_RememberGamePassword},
	{"Miscellaneous",	"Select Non-Hostile Players Out Of Town",			NULL,	BOOLEAN,	&V_OutTownSelect},
	{"Miscellaneous",	"Start Game With Automap",							NULL,	BOOLEAN,	&V_AutomapOnJoin},
    {"Miscellaneous",	"Auto SS Kills",									NULL,	BOOLEAN,		&V_AutoSS},

	{"Notification",	"Life Potions",										NULL,	BOOLEAN,	&V_LifePot},
	{"Notification",	"Life Rejuvenation Potions",						NULL,	BOOLEAN,	&V_LifeJuv},
	{"Notification",	"Mana Potions",										NULL,	BOOLEAN,	&V_ManaPot},
	{"Notification",	"Mana Rejuvenation Potions",						NULL,	BOOLEAN,	&V_ManaJuv},
	{"Notification",	"Potion",											NULL,	BOOLEAN,	&V_Potion},
	{"Notification",	"Quests",											NULL,	BOOLEAN,	&V_Quests},

	{"Options Menu",	"Toggle Hotkey",									NULL,	INTEGER,	&K_Options},
	{"Options Menu",	"Title Color",										NULL,	INTEGER,	&V_OptionTitleColor},
	{"Options Menu",	"Title Font",										NULL,	INTEGER,	&V_OptionTitleFont},
	{"Options Menu",	"Variable Name Color",								NULL,	INTEGER,	&V_OptionVariableColor},
	{"Options Menu",	"Variable Name Font",								NULL,	INTEGER,	&V_OptionVariableFont},
	{"Options Menu",	"Close Button Color",								NULL,	INTEGER,	&V_OptionCloseColor},
	{"Options Menu",	"Close Button Font",								NULL,	INTEGER,	&V_OptionCloseFont},

	{"Potion",			"Life %",											NULL,	INTEGER,	&V_LifePotPercent},
	{"Potion",			"Life Delay",										NULL,	INTEGER,	&V_LifePotDelay},
	{"Potion",			"Life Rejuvenation %",								NULL,	INTEGER,	&V_LifeJuvPercent},
	{"Potion",			"Life Rejuvenation Delay",							NULL,	INTEGER,	&V_LifeJuvDelay},
	{"Potion",			"Mana %",											NULL,	INTEGER,	&V_ManaPotPercent},
	{"Potion",			"Mana Delay",										NULL,	INTEGER,	&V_ManaPotDelay},
	{"Potion",			"Mana Rejuvenation %",								NULL,	INTEGER,	&V_ManaJuvPercent},
	{"Potion",			"Mana Rejuvenation Delay",							NULL,	INTEGER,	&V_ManaJuvDelay},

	{"Reveal",			"Anti Shake",										NULL,	BOOLEAN,	&V_AntiShake},
	{"Reveal",			"Anti Weather",										NULL,	BOOLEAN,	&V_AntiWeather},
	{"Reveal",			"Automatically Reveal Act",							NULL,	BOOLEAN,	&V_AutoRevealAutomap},
	{"Reveal",			"Ethereal Items",									NULL,	BOOLEAN,	&V_Ethereal},
	{"Reveal",			"Full Light Radius",								NULL,	BOOLEAN,	&V_FullLightRadius},
	{"Reveal",			"Item Level",										NULL,	BOOLEAN,	&V_ItemLevel},
	{"Reveal",			"Item Socket Protection",							NULL,	BOOLEAN,	&V_ProtectItemSocket},
	{"Reveal",			"Item Sockets",										NULL,	BOOLEAN,	&V_Sockets},
	{"Reveal",			"Level Names",										NULL,	BOOLEAN,	&V_LevelNames},
	{"Reveal",			"Shrine Images",									NULL,	BOOLEAN,	&V_ShrineImages},
	{"Reveal",			"View Basic Stats Of Items",						NULL,	BOOLEAN,	&V_ViewItemBasicStats},
	{"Reveal",			"View Socketables",									NULL,	BOOLEAN,	&V_ViewSocketable},

	{"Reveal",			"Life Bar Transparency",							NULL,	INTEGER,	&V_LifeBarTransparency},
	{"Reveal",			"Life Bar Color",									NULL,	INTEGER,	&V_LifeBarColor},

	{"Reveal",			"Level Names Font Color",							NULL,	INTEGER,	&V_LevelNamesFontColor},
	{"Reveal",			"Staff Tomb Level Indicator",						NULL,	STRING,		&V_StaffTombIndicator},

	{"Reveal",			"Missiles",											NULL,	BOOLEAN,	&V_Missiles},
	{"Reveal",			"My Missile Color",									NULL,	INTEGER,	&V_MyColor},
	{"Reveal",			"Neutral Missile Color",							NULL,	INTEGER,	&V_NeutralColor},
	{"Reveal",			"Hostile Missile Color",							NULL,	INTEGER,	&V_HostileColor},
	{"Reveal",			"Partied Missile Color",							NULL,	INTEGER,	&V_PartyColor},

	{"Reveal",			"Monsters",											NULL,	BOOLEAN,	&V_Monsters},
	{"Reveal",			"Boss Monster Names",								NULL,	BOOLEAN,	&V_MonsterNames},
	{"Reveal",			"Monster Resistances",								NULL,	BOOLEAN,	&V_MonsterResists},
	{"Reveal",			"Monster Resistances Fire",							NULL,	BOOLEAN,	&V_MonsterResistsFire},
	{"Reveal",			"Monster Resistances Cold",							NULL,	BOOLEAN,	&V_MonsterResistsCold},
	{"Reveal",			"Monster Resistances Lightning",					NULL,	BOOLEAN,	&V_MonsterResistsLightning},
	{"Reveal",			"Monster Resistances Poison",						NULL,	BOOLEAN,	&V_MonsterResistsPoison},
	{"Reveal",			"Monster Resistances Physical",						NULL,	BOOLEAN,	&V_MonsterResistsPhysical},
	{"Reveal",			"Monster Resistances Magic",						NULL,	BOOLEAN,	&V_MonsterResistsMagic},
	{"Reveal",			"Normal Monster Color",								NULL,	INTEGER,	&V_NormalColor},
	{"Reveal",			"Boss Monster Color",								NULL,	INTEGER,	&V_BossColor},
	{"Reveal",			"Boss Monster Name Color",							NULL,	INTEGER,	&V_BossNameColor},
	{"Reveal",			"Champion Monster Color",							NULL,	INTEGER,	&V_ChampionColor},
	{"Reveal",			"Minion Monster Color",								NULL,	INTEGER,	&V_MinionColor},
	{"Reveal",			"Poison Resist Light Green",						NULL,	BOOLEAN,	&V_PoisonResistGreen},

	{"Reveal",			"Boss Monster Enchantments",						NULL,	BOOLEAN,	&V_MonsterEnchantments},
	{"Reveal",			"Boss Monster Enchantments Might",					NULL,	BOOLEAN,	&V_MonsterEnchantmentsMight},
	{"Reveal",			"Boss Monster Enchantments Fanaticism",				NULL,	BOOLEAN,	&V_MonsterEnchantmentsFanaticism},
	{"Reveal",			"Boss Monster Enchantments Conviction",				NULL,	BOOLEAN,	&V_MonsterEnchantmentsConviction},
	{"Reveal",			"Boss Monster Enchantments Blessed Aim",			NULL,	BOOLEAN,	&V_MonsterEnchantmentsBlessedAim},
	{"Reveal",			"Boss Monster Enchantments Holy Fire",				NULL,	BOOLEAN,	&V_MonsterEnchantmentsHolyFire},
	{"Reveal",			"Boss Monster Enchantments Holy Freeze",			NULL,	BOOLEAN,	&V_MonsterEnchantmentsHolyFreeze},
	{"Reveal",			"Boss Monster Enchantments Holy Shock",				NULL,	BOOLEAN,	&V_MonsterEnchantmentsHolyShock},

	{"Reveal",			"Notorious Monster Units",							NULL,	BOOLEAN,	&V_MonsterUnits},
	{"Reveal",			"Notorious Monster Units Devilkin Shamans",			NULL,	BOOLEAN,	&V_MonsterUnitsDevilkinShamans},
	{"Reveal",			"Notorious Monster Units Damned",					NULL,	BOOLEAN,	&V_MonsterUnitsDamned},
	{"Reveal",			"Notorious Monster Units Urdars",					NULL,	BOOLEAN,	&V_MonsterUnitsUrdars},
	{"Reveal",			"Notorious Monster Units Vampires",					NULL,	BOOLEAN,	&V_MonsterUnitsVampires},
	{"Reveal",			"Notorious Monster Units Flayer Shamans",			NULL,	BOOLEAN,	&V_MonsterUnitsFlayerShamans},
	{"Reveal",			"Notorious Monster Units Thorned Hulks",			NULL,	BOOLEAN,	&V_MonsterUnitsThornedHulks},
	{"Reveal",			"Notorious Monster Units Burning Souls",			NULL,	BOOLEAN,	&V_MonsterUnitsSouls},
	{"Reveal",			"Notorious Monster Units Undead Stygian Dolls",		NULL,	BOOLEAN,	&V_MonsterUnitsDolls},
	{"Reveal",			"Notorious Monster Units Pit Lords",				NULL,	BOOLEAN,	&V_MonsterUnitsPitLords},
	{"Reveal",			"Notorious Monster Units Abyss Knights",			NULL,	BOOLEAN,	&V_MonsterUnitsKnights},
	{"Reveal",			"Notorious Monster Units Oblivion Knights",			NULL,	BOOLEAN,	&V_MonsterUnitsOblivions},
	{"Reveal",			"Notorious Monster Units Moon Lords",				NULL,	BOOLEAN,	&V_MonsterUnitsMoonLords},
	{"Reveal",			"Notorious Monster Units Unravelers",				NULL,	BOOLEAN,	&V_MonsterUnitsUnravelers},
	{"Reveal",			"Notorious Monster Units Suicide Minions",			NULL,	BOOLEAN,	&V_MonsterUnitsSuicideMinions},
	{"Reveal",			"Notorious Monster Units Succubus Witches",			NULL,	BOOLEAN,	&V_MonsterUnitsSuccubusWitches},
	{"Reveal",			"Notorious Monster Units Claw Vipers",				NULL,	BOOLEAN,	&V_MonsterUnitsSnakes},
	{"Reveal",			"Notorious Monster Units Rot Walkers",				NULL,	BOOLEAN,	&V_MonsterUnitsUndeadCharger},

	{"Reveal",			"Monster Life Bar Level",							NULL,	BOOLEAN,	&V_MonsterLifeBarLevel},
	{"Reveal",			"Monster Life Bar Resistances",						NULL,	BOOLEAN,	&V_MonsterLifeBarResists},
	{"Reveal",			"Monster Life Bar Treasure Classes",				NULL,	BOOLEAN,	&V_MonsterLifeBarTC},

	//{"Reveal",			"My Summon Color",									NULL,	INTEGER,	&V_MySummonColor},
	//{"Reveal",			"Neutral Summon Color",								NULL,	INTEGER,	&V_NeutralSummonColor},
	//{"Reveal",			"Hostile Summon Color",								NULL,	INTEGER,	&V_HostileSummonColor},
	//{"Reveal",			"Partied Summon Color",								NULL,	INTEGER,	&V_PartiedSummonColor},

	{"Reveal",			"Toggle View Basic Stats Of Items Hotkey",			NULL,	INTEGER,	&K_ViewItemBasicStats},
	{"Reveal",			"Toggle Item Socket Protection Hotkey",				NULL,	INTEGER,	&K_ProtectItemSocket},
	{"Reveal",			"View Character Stats Hotkey",						NULL,	INTEGER,	&K_Stats},
	{"Reveal",			"View Other Player's Inventory Hotkey",				NULL,	INTEGER,	&K_ViewInventory},

	{"Speed",			"Attack Speed",										NULL,	BOOLEAN,	&V_SpeedAttack},
	{"Speed",			"Attack Speed Frames",								NULL,	INTEGER,	&V_AttackFrames},

	{"Speed",			"Cast Rate",										NULL,	BOOLEAN,	&V_SpeedCast},
	{"Speed",			"Cast Rate Frames",									NULL,	INTEGER,	&V_CastFrames},

	{"Speed",			"Increased Attack Speed %",							NULL,	INTEGER,	&V_AttackSpeed},
	{"Speed",			"Increased Block Rate %",							NULL,	INTEGER,	&V_BlockRate},
	{"Speed",			"Increased Cast Rate %",							NULL,	INTEGER,	&V_CastRate},
	{"Speed",			"Increased Hit Recovery Rate %",					NULL,	INTEGER,	&V_HitRecoveryRate},
	{"Speed",			"Increased Run/Walk Speed %",						NULL,	INTEGER,	&V_RunWalkSpeed},
	{"Speed",			"Increased Velocity Speed %",						NULL,	INTEGER,	&V_VelocitySpeed},

	{"Teleport",		"Fast Teleport",									NULL,	BOOLEAN,	&V_FastTeleport},
	{"Teleport",		"Farcast Teleport",									NULL,	BOOLEAN,	&V_FarcastTeleport},

	{"Teleport",		"Hostile & Teleport To Target Hotkey",				NULL,	INTEGER,	&K_TeleHost},
	{"Teleport",		"Teleport To Click Hotkey",							NULL,	INTEGER,	&K_TeleWalk},

	{"Teleport",		"Next Level Vector Hotkey",							NULL,	INTEGER,	&K_NextLevelVector},
	{"Teleport",		"Next Level Vector Color",							NULL,	INTEGER,	&V_NextLevelVectorColor},

	{"Teleport",		"Previous Level Vector Hotkey",						NULL,	INTEGER,	&K_PreviousLevelVector},
	{"Teleport",		"Previous Level Vector Color",						NULL,	INTEGER,	&V_PreviousLevelVectorColor},

	{"Teleport",		"Quest Vector Hotkey",								NULL,	INTEGER,	&K_QuestVector},
	{"Teleport",		"Quest Vector Color",								NULL,	INTEGER,	&V_QuestVectorColor},

	{"Teleport",		"Waypoint Vector Hotkey",							NULL,	INTEGER,	&K_WaypointVector},
	{"Teleport",		"Waypoint Vector Color",							NULL,	INTEGER,	&V_WaypointVectorColor},

	{"Teleport",		"Active Vector Color",								NULL,	INTEGER,	&V_ActiveVectorColor},

	{"Winamp",			"Say Hotkey",										NULL,	INTEGER,	&K_CurrentSong},
	{"Winamp",			"Fast Forward Hotkey",								NULL,	INTEGER,	&K_FastForwardSong},
	{"Winamp",			"Rewind Hotkey",									NULL,	INTEGER,	&K_RewindSong},
	{"Winamp",			"Higher Volume Hotkey",								NULL,	INTEGER,	&K_HigherSongVolume},
	{"Winamp",			"Lower Volume Hotkey",								NULL,	INTEGER,	&K_LowerSongVolume},
	{"Winamp",			"Next Hotkey",										NULL,	INTEGER,	&K_NextSong},
	{"Winamp",			"Previous Hotkey",									NULL,	INTEGER,	&K_PreviousSong},
	{"Winamp",			"Pause Hotkey",										NULL,	INTEGER,	&K_PauseSong},
	{"Winamp",			"Play Hotkey",										NULL,	INTEGER,	&K_PlaySong},
	{"Winamp",			"Stop Hotkey",										NULL,	INTEGER,	&K_StopSong},
	{"Winamp",			"Phrase",											NULL,	STRING,		&V_CurrentSongPhrase}
	*/
};

CONFIGURATION D[] =
{
	{"Default",	"Str1",														NULL,	STRING,		&V_Line1},
	{"Default",	"Str2",														NULL,	STRING,		&V_Line2},
	{"Default",	"Str3",														NULL,	STRING,		&V_Line3},
	{"Default",	"Str4",														NULL,	STRING,		&V_Line4},
	{"Default",	"Str5",														NULL,	STRING,		&V_Line5},
	{"Default",	"Str6",														NULL,	STRING,		&V_Line6},
	{"Default",	"Str7",														NULL,	STRING,		&V_Line7},
	{"Default",	"Str8",														NULL,	STRING,		&V_Line8},
	{"Default",	"Str9",														NULL,	STRING,		&V_Line9},
	{"Default",	"Str10",													NULL,	STRING,		&V_Line10},
	{"Default",	"Str11",													NULL,	STRING,		&V_Line11},
	{"Default",	"Str12",													NULL,	STRING,		&V_Line12},
	{"Default",	"Str13",													NULL,	STRING,		&V_Line13},
	{"Default",	"Str14",													NULL,	STRING,		&V_Line14},
	{"Default",	"Str15",													NULL,	STRING,		&V_Line15},
	{"Default",	"Str16",													NULL,	STRING,		&V_Line16},
	{"Default",	"Str17",													NULL,	STRING,		&V_Line17},
	{"Default",	"Str18",													NULL,	STRING,		&V_Line18},
	{"Default",	"Str19",													NULL,	STRING,		&V_Line19},
	{"Default",	"Str20",													NULL,	STRING,		&V_Line20},
	{"Default",	"Str21",													NULL,	STRING,		&V_AutomapInfoGameNameText},
	{"Default",	"Str22",													NULL,	STRING,		&V_AutomapInfoGamePasswordText},
	{"Default",	"Str23",													NULL,	STRING,		&V_AutomapInfoLevelText},
	{"Default",	"Str24",													NULL,	STRING,		&V_AutomapInfoDifficultyText},
	{"Default",	"Str25",													NULL,	STRING,		&V_AutomapInfoIPText},
	{"Default",	"Str26",													NULL,	STRING,		&V_AutomapInfoLocalTimeText},
	{"Default",	"Str28",													NULL,	STRING,		&V_AutomapInfoGameTimerText},
	{"Default",	"Str29",													NULL,	STRING,		&V_AutomapInfoFPSText},
	{"Default",	"Str30",													NULL,	STRING,		&V_AutomapInfoSkipText},
	{"Default",	"Str31",													NULL,	STRING,		&V_AutomapInfoPingText},
	{"Default",	"Str32",													NULL,	STRING,		&V_AutomapInfoDayOfWeekText},
	{"Default",	"Str38",													NULL,	STRING,		&V_AutomapInfoCharacterNameText},
	{"Default",	"Str33",													NULL,	STRING,		&V_EnchantAll},
	{"Default",	"Str34",													NULL,	STRING,		&V_EnchantMercenary},
	{"Default",	"Str35",													NULL,	STRING,		&V_EnchantPlayer},
	{"Default",	"Str36",													NULL,	STRING,		&V_StaffTombIndicator},
	{"Default",	"Str37",													NULL,	STRING,		&V_CurrentSongPhrase},
	{ "Default", "VerInfoStr1X",											NULL,	INTEGER,	&V_VerInfoStr1X},
	{ "Default", "VerInfoStr1Y",											NULL,	INTEGER,	&V_VerInfoStr1Y},
	{ "Default", "VerInfoStr2X",											NULL,	INTEGER,	&V_VerInfoStr2X},
	{ "Default", "VerInfoStr2Y",											NULL,	INTEGER,	&V_VerInfoStr2Y}
};

CONFIGURATION E[] =
{
	{"STASH",	"ActiveMultiPageStash",										NULL,	INTEGER,	&V_ActiveMultiPageStash },
	{"STASH",	"ActiveSharedStash",										NULL,	INTEGER,	&V_ActiveSharedStash },

	{"EXTRA",	"NBPlayersByDefault",										NULL,	INTEGER,	&V_NBPlayersByDefault},

	{"OTHER",	"MultiPlayerMode",											NULL,	INTEGER,	&V_MultiPlayerMode}
};

BOOL Bool(LPSTR Value)
{
	if (!_stricmp(Value, "1") || !_stricmp(Value, "on") || !_stricmp(Value, "true") || !_stricmp(Value, "y") || !_stricmp(Value, "yes"))
		return TRUE;

	if (!_stricmp(Value, "0") || !_stricmp(Value, "off") || !_stricmp(Value, "false") || !_stricmp(Value, "n") || !_stricmp(Value, "no"))
		return FALSE;

	return FALSE;
}

INT Integer(LPSTR Value)
{
	if (!_stricmp("A", Value)) return 'A';
	if (!_stricmp("B", Value)) return 'B';
	if (!_stricmp("C", Value)) return 'C';
	if (!_stricmp("D", Value)) return 'D';
	if (!_stricmp("E", Value)) return 'E';
	if (!_stricmp("F", Value)) return 'F';
	if (!_stricmp("G", Value)) return 'G';
	if (!_stricmp("H", Value)) return 'H';
	if (!_stricmp("I", Value)) return 'I';
	if (!_stricmp("J", Value)) return 'J';
	if (!_stricmp("K", Value)) return 'K';
	if (!_stricmp("L", Value)) return 'L';
	if (!_stricmp("M", Value)) return 'M';
	if (!_stricmp("N", Value)) return 'N';
	if (!_stricmp("O", Value)) return 'O';
	if (!_stricmp("P", Value)) return 'P';
	if (!_stricmp("Q", Value)) return 'Q';
	if (!_stricmp("R", Value)) return 'R';
	if (!_stricmp("S", Value)) return 'S';
	if (!_stricmp("T", Value)) return 'T';
	if (!_stricmp("U", Value)) return 'U';
	if (!_stricmp("V", Value)) return 'V';
	if (!_stricmp("W", Value)) return 'W';
	if (!_stricmp("X", Value)) return 'X';
	if (!_stricmp("Y", Value)) return 'Y';
	if (!_stricmp("Z", Value)) return 'Z';

	if (!_stricmp("VK_0", Value)) return '0';
	if (!_stricmp("VK_1", Value)) return '1';
	if (!_stricmp("VK_2", Value)) return '2';
	if (!_stricmp("VK_3", Value)) return '3';
	if (!_stricmp("VK_4", Value)) return '4';
	if (!_stricmp("VK_5", Value)) return '5';
	if (!_stricmp("VK_6", Value)) return '6';
	if (!_stricmp("VK_7", Value)) return '7';
	if (!_stricmp("VK_8", Value)) return '8';
	if (!_stricmp("VK_9", Value)) return '9';

	if (!_stricmp("VK_LBUTTON", Value)) return VK_LBUTTON;
	if (!_stricmp("VK_MBUTTON", Value)) return VK_MBUTTON;
	if (!_stricmp("VK_RBUTTON", Value)) return VK_RBUTTON;

	if (!_stricmp("VK_NUMPAD0", Value)) return VK_NUMPAD0;
	if (!_stricmp("VK_NUMPAD1", Value)) return VK_NUMPAD1;
	if (!_stricmp("VK_NUMPAD2", Value)) return VK_NUMPAD2;
	if (!_stricmp("VK_NUMPAD3", Value)) return VK_NUMPAD3;
	if (!_stricmp("VK_NUMPAD4", Value)) return VK_NUMPAD4;
	if (!_stricmp("VK_NUMPAD5", Value)) return VK_NUMPAD5;
	if (!_stricmp("VK_NUMPAD6", Value)) return VK_NUMPAD6;
	if (!_stricmp("VK_NUMPAD7", Value)) return VK_NUMPAD7;
	if (!_stricmp("VK_NUMPAD8", Value)) return VK_NUMPAD8;
	if (!_stricmp("VK_NUMPAD9", Value)) return VK_NUMPAD9;

	if (!_stricmp("F1", Value)) return VK_F1;
	if (!_stricmp("VK_F1", Value)) return VK_F1;

	if (!_stricmp("F2", Value)) return VK_F2;
	if (!_stricmp("VK_F2", Value)) return VK_F2;

	if (!_stricmp("F3", Value)) return VK_F3;
	if (!_stricmp("VK_F3", Value)) return VK_F3;

	if (!_stricmp("F4", Value)) return VK_F4;
	if (!_stricmp("VK_F4", Value)) return VK_F4;

	if (!_stricmp("F5", Value)) return VK_F5;
	if (!_stricmp("VK_F5", Value)) return VK_F5;

	if (!_stricmp("F6", Value)) return VK_F6;
	if (!_stricmp("VK_F6", Value)) return VK_F6;

	if (!_stricmp("F7", Value)) return VK_F7;
	if (!_stricmp("VK_F7", Value)) return VK_F7;

	if (!_stricmp("F8", Value)) return VK_F8;
	if (!_stricmp("VK_F8", Value)) return VK_F8;

	if (!_stricmp("F9", Value)) return VK_F9;
	if (!_stricmp("VK_F9", Value)) return VK_F9;

	if (!_stricmp("F10", Value)) return VK_F10;
	if (!_stricmp("VK_F10", Value)) return VK_F10;

	if (!_stricmp("F11", Value)) return VK_F11;
	if (!_stricmp("VK_F11", Value)) return VK_F11;

	if (!_stricmp("F12", Value)) return VK_F12;
	if (!_stricmp("VK_F12", Value)) return VK_F12;

	if (!_stricmp("F13", Value)) return VK_F13;
	if (!_stricmp("VK_F13", Value)) return VK_F13;

	if (!_stricmp("F14", Value)) return VK_F14;
	if (!_stricmp("VK_F14", Value)) return VK_F14;

	if (!_stricmp("F15", Value)) return VK_F15;
	if (!_stricmp("VK_F15", Value)) return VK_F15;

	if (!_stricmp("F16", Value)) return VK_F16;
	if (!_stricmp("VK_F16", Value)) return VK_F16;

	if (!_stricmp("F17", Value)) return VK_F17;
	if (!_stricmp("VK_F17", Value)) return VK_F17;

	if (!_stricmp("F18", Value)) return VK_F18;
	if (!_stricmp("VK_F18", Value)) return VK_F18;

	if (!_stricmp("F19", Value)) return VK_F19;
	if (!_stricmp("VK_F19", Value)) return VK_F19;

	if (!_stricmp("F20", Value)) return VK_F20;
	if (!_stricmp("VK_F20", Value)) return VK_F20;

	if (!_stricmp("F21", Value)) return VK_F21;
	if (!_stricmp("VK_F21", Value)) return VK_F21;

	if (!_stricmp("F22", Value)) return VK_F22;
	if (!_stricmp("VK_F22", Value)) return VK_F22;

	if (!_stricmp("F23", Value)) return VK_F23;
	if (!_stricmp("VK_F23", Value)) return VK_F23;

	if (!_stricmp("F24", Value)) return VK_F24;
	if (!_stricmp("VK_F24", Value)) return VK_F24;

	if (!_stricmp("HOME", Value)) return VK_HOME;
	if (!_stricmp("VK_HOME", Value)) return VK_HOME;

	if (!_stricmp("DELETE", Value)) return VK_DELETE;
	if (!_stricmp("VK_DELETE", Value)) return VK_DELETE;

	if (!_stricmp("PAGEDOWN", Value)) return VK_NEXT;
	if (!_stricmp("VK_PAGEDOWN", Value)) return VK_NEXT;

	if (!_stricmp("PAGEUP", Value)) return VK_PRIOR;
	if (!_stricmp("VK_PAGEUP", Value)) return VK_PRIOR;

	if (!_stricmp("INSERT", Value)) return VK_INSERT;
	if (!_stricmp("VK_INSERT", Value)) return VK_INSERT;

	if (!_stricmp("END", Value)) return VK_END;
	if (!_stricmp("VK_END", Value)) return VK_END;

	if (!_stricmp("TAB", Value)) return VK_TAB;
	if (!_stricmp("VK_TAB", Value)) return VK_TAB;

	if (!_stricmp("CAPSLOCK", Value)) return VK_CAPITAL;
	if (!_stricmp("VK_CAPSLOCK", Value)) return VK_CAPITAL;

	if (!_stricmp("SHIFT", Value)) return VK_SHIFT;
	if (!_stricmp("VK_SHIFT", Value)) return VK_SHIFT;

	if (!_stricmp("ENTER", Value)) return VK_RETURN;
	if (!_stricmp("VK_ENTER", Value)) return VK_RETURN;
	if (!_stricmp("RETURN", Value)) return VK_RETURN;
	if (!_stricmp("VK_RETURN", Value)) return VK_RETURN;

	if (!_stricmp("VK_CTRL", Value)) return VK_CONTROL;
	if (!_stricmp("CONTROL", Value)) return VK_CONTROL;
	if (!_stricmp("VK_CTRL", Value)) return VK_CONTROL;
	if (!_stricmp("VK_CONTROL", Value)) return VK_CONTROL;

	if (!_stricmp("ESC", Value)) return VK_ESCAPE;
	if (!_stricmp("ESCAPE", Value)) return VK_ESCAPE;
	if (!_stricmp("VK_ESC", Value)) return VK_ESCAPE;
	if (!_stricmp("VK_ESCAPE", Value)) return VK_ESCAPE;

	if (!_stricmp("SPACE", Value)) return VK_SPACE;
	if (!_stricmp("VK_SPACE", Value)) return VK_SPACE;

	if (!_stricmp("LEFT", Value)) return VK_LEFT;
	if (!_stricmp("VK_LEFT", Value)) return VK_LEFT;

	if (!_stricmp("UP", Value)) return VK_UP;
	if (!_stricmp("VK_UP", Value)) return VK_UP;

	if (!_stricmp("RIGHT", Value)) return VK_RIGHT;
	if (!_stricmp("VK_RIGHT", Value)) return VK_RIGHT;

	if (!_stricmp("DOWN", Value)) return VK_DOWN;
	if (!_stricmp("VK_DOWN", Value)) return VK_DOWN;

	if (!_stricmp("VK_NUMPAD*", Value)) return VK_MULTIPLY;
	if (!_stricmp("VK_MULTIPLY", Value)) return VK_MULTIPLY;

	if (!_stricmp("VK_NUMPAD+", Value)) return VK_ADD;
	if (!_stricmp("VK_ADD", Value)) return VK_ADD;

	if (!_stricmp("VK_NUMPAD-", Value)) return VK_SUBTRACT;
	if (!_stricmp("VK_SUBTRACT", Value)) return VK_SUBTRACT;

	if (!_stricmp("VK_NUMPAD.", Value)) return VK_DECIMAL;
	if (!_stricmp("VK_DECIMAL", Value)) return VK_DECIMAL;

	if (!_stricmp("VK_NUMPAD/", Value)) return VK_DIVIDE;
	if (!_stricmp("VK_DIVIDE", Value)) return VK_DIVIDE;

	if (!_stricmp("ALT", Value)) return VK_MENU;
	if (!_stricmp("VK_ALT", Value)) return VK_MENU;

	if (!_stricmp("VK_LMENU", Value)) return VK_LMENU;
	if (!_stricmp("VK_RMENU", Value)) return VK_RMENU;

	if (!_stricmp(",", Value)) return VK_OEM_COMMA;
	if (!_stricmp("VK_,", Value)) return VK_OEM_COMMA;
	if (!_stricmp("VK_COMMA", Value)) return VK_OEM_COMMA;

	if (!_stricmp("+", Value)) return VK_OEM_PLUS;
	if (!_stricmp("=", Value)) return VK_OEM_PLUS;
	if (!_stricmp("VK_+", Value)) return VK_OEM_PLUS;
	if (!_stricmp("VK_=", Value)) return VK_OEM_PLUS;
	if (!_stricmp("VK_PLUS", Value)) return VK_OEM_PLUS;

	if (!_stricmp("_", Value)) return VK_OEM_MINUS;
	if (!_stricmp("-", Value)) return VK_OEM_MINUS;
	if (!_stricmp("VK__", Value)) return VK_OEM_MINUS;
	if (!_stricmp("VK_-", Value)) return VK_OEM_MINUS;
	if (!_stricmp("VK_MINUS", Value)) return VK_OEM_MINUS;

	if (!_stricmp(">", Value)) return VK_OEM_PERIOD;
	if (!_stricmp(".", Value)) return VK_OEM_PERIOD;
	if (!_stricmp("VK_>", Value)) return VK_OEM_PERIOD;
	if (!_stricmp("VK_.", Value)) return VK_OEM_PERIOD;
	if (!_stricmp("VK_PERIOD", Value)) return VK_OEM_PERIOD;

	if (!_stricmp("""", Value)) return VK_OEM_7;
	if (!_stricmp("'", Value)) return VK_OEM_7;
	if (!_stricmp("VK_""", Value)) return VK_OEM_7;
	if (!_stricmp("VK_'", Value)) return VK_OEM_7;
	if (!_stricmp("VK_OEM_7", Value)) return VK_OEM_7;

	if (!_stricmp("}", Value)) return VK_OEM_6;
	if (!_stricmp("]", Value)) return VK_OEM_6;
	if (!_stricmp("VK_}", Value)) return VK_OEM_6;
	if (!_stricmp("VK_]", Value)) return VK_OEM_6;
	if (!_stricmp("VK_OEM_6", Value)) return VK_OEM_6;

	if (!_stricmp("|", Value)) return VK_OEM_5;
	if (!_stricmp("\\", Value)) return VK_OEM_5;
	if (!_stricmp("VK_|", Value)) return VK_OEM_5;
	if (!_stricmp("VK_\\", Value)) return VK_OEM_5;
	if (!_stricmp("VK_OEM_5", Value)) return VK_OEM_5;

	if (!_stricmp("{", Value)) return VK_OEM_4;
	if (!_stricmp("[", Value)) return VK_OEM_4;
	if (!_stricmp("VK_{", Value)) return VK_OEM_4;
	if (!_stricmp("VK_[", Value)) return VK_OEM_4;
	if (!_stricmp("VK_OEM_4", Value)) return VK_OEM_4;

	if (!_stricmp("~", Value)) return VK_OEM_3;
	if (!_stricmp("`", Value)) return VK_OEM_3;
	if (!_stricmp("VK_~", Value)) return VK_OEM_3;
	if (!_stricmp("VK_`", Value)) return VK_OEM_3;
	if (!_stricmp("VK_OEM_3", Value)) return VK_OEM_3;

	if (!_stricmp("?", Value)) return VK_OEM_2;
	if (!_stricmp("/", Value)) return VK_OEM_2;
	if (!_stricmp("VK_?", Value)) return VK_OEM_2;
	if (!_stricmp("VK_/", Value)) return VK_OEM_2;
	if (!_stricmp("VK_OEM_2", Value)) return VK_OEM_2;

	if (!_stricmp(":", Value)) return VK_OEM_1;
	if (!_stricmp(";", Value)) return VK_OEM_1;
	if (!_stricmp("VK_:", Value)) return VK_OEM_1;
	if (!_stricmp("VK_;", Value)) return VK_OEM_1;
	if (!_stricmp("VK_OEM_1", Value)) return VK_OEM_1;

	if (!_stricmp("NUMLOCK", Value)) return VK_NUMLOCK;
	if (!_stricmp("VK_NUMLOCK", Value)) return VK_NUMLOCK;

	if (!_stricmp("PRTSCN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("PRINTSCREEN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("SNAPSHOT", Value)) return VK_SNAPSHOT;
	if (!_stricmp("VK_PRTSCN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("VK_PRINTSCREEN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("VK_SNAPSHOT", Value)) return VK_SNAPSHOT;

	if (!_stricmp("PRINT", Value)) return VK_PRINT;
	if (!_stricmp("PRT", Value)) return VK_PRINT;
	if (!_stricmp("VK_PRINT", Value)) return VK_PRINT;
	if (!_stricmp("VK_PRT", Value)) return VK_PRINT;

	if (!_stricmp("HELP", Value)) return VK_HELP;
	if (!_stricmp("VK_HELP", Value)) return VK_HELP;

	if (!_stricmp("SEPARATOR", Value)) return VK_SEPARATOR;
	if (!_stricmp("VK_SEPARATOR", Value)) return VK_SEPARATOR;

	if (!_stricmp("SCRLK", Value)) return VK_SCROLL;
	if (!_stricmp("SCROLLLOCK", Value)) return VK_SCROLL;
	if (!_stricmp("VK_SCRLK", Value)) return VK_SCROLL;
	if (!_stricmp("VK_SCROLLLOCK", Value)) return VK_SCROLL;

	if (!_stricmp("CANCEL", Value)) return VK_CANCEL;
	if (!_stricmp("CONTROLBREAKPROCESSING", Value)) return VK_CANCEL;
	if (!_stricmp("VK_CANCEL", Value)) return VK_CANCEL;
	if (!_stricmp("VK_CONTROLBREAKPROCESSING", Value)) return VK_CANCEL;

	if (!_stricmp("BACKSPACE", Value)) return VK_BACK;
	if (!_stricmp("BACK", Value)) return VK_BACK;
	if (!_stricmp("VK_BACKSPACE", Value)) return VK_BACK;
	if (!_stricmp("VK_BACK", Value)) return VK_BACK;

	if (!_stricmp("CLEAR", Value)) return VK_CLEAR;
	if (!_stricmp("VK_CLEAR", Value)) return VK_CLEAR;

	if (!_stricmp("PAUSE", Value)) return VK_PAUSE;
	if (!_stricmp("PAUSEBREAK", Value)) return VK_PAUSE;
	if (!_stricmp("VK_PAUSE", Value)) return VK_PAUSE;
	if (!_stricmp("VK_PAUSEBREAK", Value)) return VK_PAUSE;

	if (!_stricmp("LWIN", Value)) return VK_LWIN;
	if (!_stricmp("LEFTWINDOWS", Value)) return VK_LWIN;
	if (!_stricmp("VK_LWIN", Value)) return VK_LWIN;
	if (!_stricmp("VK_LEFTWINDOWS", Value)) return VK_LWIN;

	if (!_stricmp("RWIN", Value)) return VK_RWIN;
	if (!_stricmp("RIGHTWINDOWS", Value)) return VK_RWIN;
	if (!_stricmp("VK_RWIN", Value)) return VK_RWIN;
	if (!_stricmp("VK_RIGHTWINDOWS", Value)) return VK_RWIN;

	if (!_stricmp("APPS", Value)) return VK_APPS;
	if (!_stricmp("APPLICATIONS", Value)) return VK_APPS;
	if (!_stricmp("VK_APPS", Value)) return VK_APPS;
	if (!_stricmp("VK_APPLICATIONS", Value)) return VK_APPS;

	if (!_stricmp("SLEEP", Value)) return VK_SLEEP;
	if (!_stricmp("VK_SLEEP", Value)) return VK_SLEEP;

	if (!_stricmp("LSHIFT", Value)) return VK_LSHIFT;
	if (!_stricmp("VK_LSHIFT", Value)) return VK_LSHIFT;

	if (!_stricmp("RSHIFT", Value)) return VK_RSHIFT;
	if (!_stricmp("VK_RSHIFT", Value)) return VK_RSHIFT;

	if (!_stricmp("LCONTROL", Value)) return VK_LCONTROL;
	if (!_stricmp("VK_LCONTROL", Value)) return VK_LCONTROL;

	if (!_stricmp("RCONTROL", Value)) return VK_RCONTROL;
	if (!_stricmp("VK_RCONTROL", Value)) return VK_RCONTROL;

	if (!_stricmp("LMENU", Value)) return VK_LMENU;
	if (!_stricmp("VK_LMENU", Value)) return VK_LMENU;

	if (!_stricmp("RMENU", Value)) return VK_RMENU;
	if (!_stricmp("VK_RMENU", Value)) return VK_RMENU;

	if (!_stricmp("BRIGHT WHITE", Value)) return -1;
	if (!_stricmp("WHITE", Value)) return 0;
	if (!_stricmp("RED", Value)) return 1;
	if (!_stricmp("GREEN", Value)) return 2;
	if (!_stricmp("BLUE", Value)) return 3;
	if (!_stricmp("GOLD", Value)) return 4;
	if (!_stricmp("GRAY", Value)) return 5;
	if (!_stricmp("BLACK", Value)) return 6;
	if (!_stricmp("GOLD 2", Value)) return 7;
	if (!_stricmp("ORANGE", Value)) return 8;
	if (!_stricmp("YELLOW", Value)) return 9;
	if (!_stricmp("DARK GREEN", Value)) return 10;
	if (!_stricmp("PURPLE", Value)) return 11;
	if (!_stricmp("DARK GREEN 2", Value)) return 12;
	if (!_stricmp("BRIGHT WHITE 2", Value)) return 13;
	if (!_stricmp("BLACK 2", Value)) return 14;
	if (!_stricmp("SILVER", Value)) return 15;
	if (!_stricmp("LIGHT GRAY", Value)) return 16;
	if (!_stricmp("MESSY", Value)) return 17;
	if (!_stricmp("BRIGHT WHITE 3", Value)) return 18;
	if (!_stricmp("RED 2", Value)) return 19;

	if (!_stricmp("INFINITE", Value)) return INFINITE;

	return atoi(Value);
}

INT64 Integer64(LPSTR Value)
{
	if (!_stricmp("A", Value)) return 'A';
	if (!_stricmp("B", Value)) return 'B';
	if (!_stricmp("C", Value)) return 'C';
	if (!_stricmp("D", Value)) return 'D';
	if (!_stricmp("E", Value)) return 'E';
	if (!_stricmp("F", Value)) return 'F';
	if (!_stricmp("G", Value)) return 'G';
	if (!_stricmp("H", Value)) return 'H';
	if (!_stricmp("I", Value)) return 'I';
	if (!_stricmp("J", Value)) return 'J';
	if (!_stricmp("K", Value)) return 'K';
	if (!_stricmp("L", Value)) return 'L';
	if (!_stricmp("M", Value)) return 'M';
	if (!_stricmp("N", Value)) return 'N';
	if (!_stricmp("O", Value)) return 'O';
	if (!_stricmp("P", Value)) return 'P';
	if (!_stricmp("Q", Value)) return 'Q';
	if (!_stricmp("R", Value)) return 'R';
	if (!_stricmp("S", Value)) return 'S';
	if (!_stricmp("T", Value)) return 'T';
	if (!_stricmp("U", Value)) return 'U';
	if (!_stricmp("V", Value)) return 'V';
	if (!_stricmp("W", Value)) return 'W';
	if (!_stricmp("X", Value)) return 'X';
	if (!_stricmp("Y", Value)) return 'Y';
	if (!_stricmp("Z", Value)) return 'Z';

	if (!_stricmp("VK_0", Value)) return '0';
	if (!_stricmp("VK_1", Value)) return '1';
	if (!_stricmp("VK_2", Value)) return '2';
	if (!_stricmp("VK_3", Value)) return '3';
	if (!_stricmp("VK_4", Value)) return '4';
	if (!_stricmp("VK_5", Value)) return '5';
	if (!_stricmp("VK_6", Value)) return '6';
	if (!_stricmp("VK_7", Value)) return '7';
	if (!_stricmp("VK_8", Value)) return '8';
	if (!_stricmp("VK_9", Value)) return '9';

	if (!_stricmp("VK_LBUTTON", Value)) return VK_LBUTTON;
	if (!_stricmp("VK_MBUTTON", Value)) return VK_MBUTTON;
	if (!_stricmp("VK_RBUTTON", Value)) return VK_RBUTTON;

	if (!_stricmp("VK_NUMPAD0", Value)) return VK_NUMPAD0;
	if (!_stricmp("VK_NUMPAD1", Value)) return VK_NUMPAD1;
	if (!_stricmp("VK_NUMPAD2", Value)) return VK_NUMPAD2;
	if (!_stricmp("VK_NUMPAD3", Value)) return VK_NUMPAD3;
	if (!_stricmp("VK_NUMPAD4", Value)) return VK_NUMPAD4;
	if (!_stricmp("VK_NUMPAD5", Value)) return VK_NUMPAD5;
	if (!_stricmp("VK_NUMPAD6", Value)) return VK_NUMPAD6;
	if (!_stricmp("VK_NUMPAD7", Value)) return VK_NUMPAD7;
	if (!_stricmp("VK_NUMPAD8", Value)) return VK_NUMPAD8;
	if (!_stricmp("VK_NUMPAD9", Value)) return VK_NUMPAD9;

	if (!_stricmp("F1", Value)) return VK_F1;
	if (!_stricmp("VK_F1", Value)) return VK_F1;

	if (!_stricmp("F2", Value)) return VK_F2;
	if (!_stricmp("VK_F2", Value)) return VK_F2;

	if (!_stricmp("F3", Value)) return VK_F3;
	if (!_stricmp("VK_F3", Value)) return VK_F3;

	if (!_stricmp("F4", Value)) return VK_F4;
	if (!_stricmp("VK_F4", Value)) return VK_F4;

	if (!_stricmp("F5", Value)) return VK_F5;
	if (!_stricmp("VK_F5", Value)) return VK_F5;

	if (!_stricmp("F6", Value)) return VK_F6;
	if (!_stricmp("VK_F6", Value)) return VK_F6;

	if (!_stricmp("F7", Value)) return VK_F7;
	if (!_stricmp("VK_F7", Value)) return VK_F7;

	if (!_stricmp("F8", Value)) return VK_F8;
	if (!_stricmp("VK_F8", Value)) return VK_F8;

	if (!_stricmp("F9", Value)) return VK_F9;
	if (!_stricmp("VK_F9", Value)) return VK_F9;

	if (!_stricmp("F10", Value)) return VK_F10;
	if (!_stricmp("VK_F10", Value)) return VK_F10;

	if (!_stricmp("F11", Value)) return VK_F11;
	if (!_stricmp("VK_F11", Value)) return VK_F11;

	if (!_stricmp("F12", Value)) return VK_F12;
	if (!_stricmp("VK_F12", Value)) return VK_F12;

	if (!_stricmp("F13", Value)) return VK_F13;
	if (!_stricmp("VK_F13", Value)) return VK_F13;

	if (!_stricmp("F14", Value)) return VK_F14;
	if (!_stricmp("VK_F14", Value)) return VK_F14;

	if (!_stricmp("F15", Value)) return VK_F15;
	if (!_stricmp("VK_F15", Value)) return VK_F15;

	if (!_stricmp("F16", Value)) return VK_F16;
	if (!_stricmp("VK_F16", Value)) return VK_F16;

	if (!_stricmp("F17", Value)) return VK_F17;
	if (!_stricmp("VK_F17", Value)) return VK_F17;

	if (!_stricmp("F18", Value)) return VK_F18;
	if (!_stricmp("VK_F18", Value)) return VK_F18;

	if (!_stricmp("F19", Value)) return VK_F19;
	if (!_stricmp("VK_F19", Value)) return VK_F19;

	if (!_stricmp("F20", Value)) return VK_F20;
	if (!_stricmp("VK_F20", Value)) return VK_F20;

	if (!_stricmp("F21", Value)) return VK_F21;
	if (!_stricmp("VK_F21", Value)) return VK_F21;

	if (!_stricmp("F22", Value)) return VK_F22;
	if (!_stricmp("VK_F22", Value)) return VK_F22;

	if (!_stricmp("F23", Value)) return VK_F23;
	if (!_stricmp("VK_F23", Value)) return VK_F23;

	if (!_stricmp("F24", Value)) return VK_F24;
	if (!_stricmp("VK_F24", Value)) return VK_F24;

	if (!_stricmp("HOME", Value)) return VK_HOME;
	if (!_stricmp("VK_HOME", Value)) return VK_HOME;

	if (!_stricmp("DELETE", Value)) return VK_DELETE;
	if (!_stricmp("VK_DELETE", Value)) return VK_DELETE;

	if (!_stricmp("PAGEDOWN", Value)) return VK_NEXT;
	if (!_stricmp("VK_PAGEDOWN", Value)) return VK_NEXT;

	if (!_stricmp("PAGEUP", Value)) return VK_PRIOR;
	if (!_stricmp("VK_PAGEUP", Value)) return VK_PRIOR;

	if (!_stricmp("INSERT", Value)) return VK_INSERT;
	if (!_stricmp("VK_INSERT", Value)) return VK_INSERT;

	if (!_stricmp("END", Value)) return VK_END;
	if (!_stricmp("VK_END", Value)) return VK_END;

	if (!_stricmp("TAB", Value)) return VK_TAB;
	if (!_stricmp("VK_TAB", Value)) return VK_TAB;

	if (!_stricmp("CAPSLOCK", Value)) return VK_CAPITAL;
	if (!_stricmp("VK_CAPSLOCK", Value)) return VK_CAPITAL;

	if (!_stricmp("SHIFT", Value)) return VK_SHIFT;
	if (!_stricmp("VK_SHIFT", Value)) return VK_SHIFT;

	if (!_stricmp("ENTER", Value)) return VK_RETURN;
	if (!_stricmp("VK_ENTER", Value)) return VK_RETURN;
	if (!_stricmp("RETURN", Value)) return VK_RETURN;
	if (!_stricmp("VK_RETURN", Value)) return VK_RETURN;

	if (!_stricmp("VK_CTRL", Value)) return VK_CONTROL;
	if (!_stricmp("CONTROL", Value)) return VK_CONTROL;
	if (!_stricmp("VK_CTRL", Value)) return VK_CONTROL;
	if (!_stricmp("VK_CONTROL", Value)) return VK_CONTROL;

	if (!_stricmp("ESC", Value)) return VK_ESCAPE;
	if (!_stricmp("ESCAPE", Value)) return VK_ESCAPE;
	if (!_stricmp("VK_ESC", Value)) return VK_ESCAPE;
	if (!_stricmp("VK_ESCAPE", Value)) return VK_ESCAPE;

	if (!_stricmp("SPACE", Value)) return VK_SPACE;
	if (!_stricmp("VK_SPACE", Value)) return VK_SPACE;

	if (!_stricmp("LEFT", Value)) return VK_LEFT;
	if (!_stricmp("VK_LEFT", Value)) return VK_LEFT;

	if (!_stricmp("UP", Value)) return VK_UP;
	if (!_stricmp("VK_UP", Value)) return VK_UP;

	if (!_stricmp("RIGHT", Value)) return VK_RIGHT;
	if (!_stricmp("VK_RIGHT", Value)) return VK_RIGHT;

	if (!_stricmp("DOWN", Value)) return VK_DOWN;
	if (!_stricmp("VK_DOWN", Value)) return VK_DOWN;

	if (!_stricmp("VK_NUMPAD*", Value)) return VK_MULTIPLY;
	if (!_stricmp("VK_MULTIPLY", Value)) return VK_MULTIPLY;

	if (!_stricmp("VK_NUMPAD+", Value)) return VK_ADD;
	if (!_stricmp("VK_ADD", Value)) return VK_ADD;

	if (!_stricmp("VK_NUMPAD-", Value)) return VK_SUBTRACT;
	if (!_stricmp("VK_SUBTRACT", Value)) return VK_SUBTRACT;

	if (!_stricmp("VK_NUMPAD.", Value)) return VK_DECIMAL;
	if (!_stricmp("VK_DECIMAL", Value)) return VK_DECIMAL;

	if (!_stricmp("VK_NUMPAD/", Value)) return VK_DIVIDE;
	if (!_stricmp("VK_DIVIDE", Value)) return VK_DIVIDE;

	if (!_stricmp("ALT", Value)) return VK_MENU;
	if (!_stricmp("VK_ALT", Value)) return VK_MENU;

	if (!_stricmp("VK_LMENU", Value)) return VK_LMENU;
	if (!_stricmp("VK_RMENU", Value)) return VK_RMENU;

	if (!_stricmp(",", Value)) return VK_OEM_COMMA;
	if (!_stricmp("VK_,", Value)) return VK_OEM_COMMA;
	if (!_stricmp("VK_COMMA", Value)) return VK_OEM_COMMA;

	if (!_stricmp("+", Value)) return VK_OEM_PLUS;
	if (!_stricmp("=", Value)) return VK_OEM_PLUS;
	if (!_stricmp("VK_+", Value)) return VK_OEM_PLUS;
	if (!_stricmp("VK_=", Value)) return VK_OEM_PLUS;
	if (!_stricmp("VK_PLUS", Value)) return VK_OEM_PLUS;

	if (!_stricmp("_", Value)) return VK_OEM_MINUS;
	if (!_stricmp("-", Value)) return VK_OEM_MINUS;
	if (!_stricmp("VK__", Value)) return VK_OEM_MINUS;
	if (!_stricmp("VK_-", Value)) return VK_OEM_MINUS;
	if (!_stricmp("VK_MINUS", Value)) return VK_OEM_MINUS;

	if (!_stricmp(">", Value)) return VK_OEM_PERIOD;
	if (!_stricmp(".", Value)) return VK_OEM_PERIOD;
	if (!_stricmp("VK_>", Value)) return VK_OEM_PERIOD;
	if (!_stricmp("VK_.", Value)) return VK_OEM_PERIOD;
	if (!_stricmp("VK_PERIOD", Value)) return VK_OEM_PERIOD;

	if (!_stricmp("""", Value)) return VK_OEM_7;
	if (!_stricmp("'", Value)) return VK_OEM_7;
	if (!_stricmp("VK_""", Value)) return VK_OEM_7;
	if (!_stricmp("VK_'", Value)) return VK_OEM_7;
	if (!_stricmp("VK_OEM_7", Value)) return VK_OEM_7;

	if (!_stricmp("}", Value)) return VK_OEM_6;
	if (!_stricmp("]", Value)) return VK_OEM_6;
	if (!_stricmp("VK_}", Value)) return VK_OEM_6;
	if (!_stricmp("VK_]", Value)) return VK_OEM_6;
	if (!_stricmp("VK_OEM_6", Value)) return VK_OEM_6;

	if (!_stricmp("|", Value)) return VK_OEM_5;
	if (!_stricmp("\\", Value)) return VK_OEM_5;
	if (!_stricmp("VK_|", Value)) return VK_OEM_5;
	if (!_stricmp("VK_\\", Value)) return VK_OEM_5;
	if (!_stricmp("VK_OEM_5", Value)) return VK_OEM_5;

	if (!_stricmp("{", Value)) return VK_OEM_4;
	if (!_stricmp("[", Value)) return VK_OEM_4;
	if (!_stricmp("VK_{", Value)) return VK_OEM_4;
	if (!_stricmp("VK_[", Value)) return VK_OEM_4;
	if (!_stricmp("VK_OEM_4", Value)) return VK_OEM_4;

	if (!_stricmp("~", Value)) return VK_OEM_3;
	if (!_stricmp("`", Value)) return VK_OEM_3;
	if (!_stricmp("VK_~", Value)) return VK_OEM_3;
	if (!_stricmp("VK_`", Value)) return VK_OEM_3;
	if (!_stricmp("VK_OEM_3", Value)) return VK_OEM_3;

	if (!_stricmp("?", Value)) return VK_OEM_2;
	if (!_stricmp("/", Value)) return VK_OEM_2;
	if (!_stricmp("VK_?", Value)) return VK_OEM_2;
	if (!_stricmp("VK_/", Value)) return VK_OEM_2;
	if (!_stricmp("VK_OEM_2", Value)) return VK_OEM_2;

	if (!_stricmp(":", Value)) return VK_OEM_1;
	if (!_stricmp(";", Value)) return VK_OEM_1;
	if (!_stricmp("VK_:", Value)) return VK_OEM_1;
	if (!_stricmp("VK_;", Value)) return VK_OEM_1;
	if (!_stricmp("VK_OEM_1", Value)) return VK_OEM_1;

	if (!_stricmp("NUMLOCK", Value)) return VK_NUMLOCK;
	if (!_stricmp("VK_NUMLOCK", Value)) return VK_NUMLOCK;

	if (!_stricmp("PRTSCN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("PRINTSCREEN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("SNAPSHOT", Value)) return VK_SNAPSHOT;
	if (!_stricmp("VK_PRTSCN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("VK_PRINTSCREEN", Value)) return VK_SNAPSHOT;
	if (!_stricmp("VK_SNAPSHOT", Value)) return VK_SNAPSHOT;

	if (!_stricmp("PRINT", Value)) return VK_PRINT;
	if (!_stricmp("PRT", Value)) return VK_PRINT;
	if (!_stricmp("VK_PRINT", Value)) return VK_PRINT;
	if (!_stricmp("VK_PRT", Value)) return VK_PRINT;

	if (!_stricmp("HELP", Value)) return VK_HELP;
	if (!_stricmp("VK_HELP", Value)) return VK_HELP;

	if (!_stricmp("SEPARATOR", Value)) return VK_SEPARATOR;
	if (!_stricmp("VK_SEPARATOR", Value)) return VK_SEPARATOR;

	if (!_stricmp("SCRLK", Value)) return VK_SCROLL;
	if (!_stricmp("SCROLLLOCK", Value)) return VK_SCROLL;
	if (!_stricmp("VK_SCRLK", Value)) return VK_SCROLL;
	if (!_stricmp("VK_SCROLLLOCK", Value)) return VK_SCROLL;

	if (!_stricmp("CANCEL", Value)) return VK_CANCEL;
	if (!_stricmp("CONTROLBREAKPROCESSING", Value)) return VK_CANCEL;
	if (!_stricmp("VK_CANCEL", Value)) return VK_CANCEL;
	if (!_stricmp("VK_CONTROLBREAKPROCESSING", Value)) return VK_CANCEL;

	if (!_stricmp("BACKSPACE", Value)) return VK_BACK;
	if (!_stricmp("BACK", Value)) return VK_BACK;
	if (!_stricmp("VK_BACKSPACE", Value)) return VK_BACK;
	if (!_stricmp("VK_BACK", Value)) return VK_BACK;

	if (!_stricmp("CLEAR", Value)) return VK_CLEAR;
	if (!_stricmp("VK_CLEAR", Value)) return VK_CLEAR;

	if (!_stricmp("PAUSE", Value)) return VK_PAUSE;
	if (!_stricmp("PAUSEBREAK", Value)) return VK_PAUSE;
	if (!_stricmp("VK_PAUSE", Value)) return VK_PAUSE;
	if (!_stricmp("VK_PAUSEBREAK", Value)) return VK_PAUSE;

	if (!_stricmp("LWIN", Value)) return VK_LWIN;
	if (!_stricmp("LEFTWINDOWS", Value)) return VK_LWIN;
	if (!_stricmp("VK_LWIN", Value)) return VK_LWIN;
	if (!_stricmp("VK_LEFTWINDOWS", Value)) return VK_LWIN;

	if (!_stricmp("RWIN", Value)) return VK_RWIN;
	if (!_stricmp("RIGHTWINDOWS", Value)) return VK_RWIN;
	if (!_stricmp("VK_RWIN", Value)) return VK_RWIN;
	if (!_stricmp("VK_RIGHTWINDOWS", Value)) return VK_RWIN;

	if (!_stricmp("APPS", Value)) return VK_APPS;
	if (!_stricmp("APPLICATIONS", Value)) return VK_APPS;
	if (!_stricmp("VK_APPS", Value)) return VK_APPS;
	if (!_stricmp("VK_APPLICATIONS", Value)) return VK_APPS;

	if (!_stricmp("SLEEP", Value)) return VK_SLEEP;
	if (!_stricmp("VK_SLEEP", Value)) return VK_SLEEP;

	if (!_stricmp("LSHIFT", Value)) return VK_LSHIFT;
	if (!_stricmp("VK_LSHIFT", Value)) return VK_LSHIFT;

	if (!_stricmp("RSHIFT", Value)) return VK_RSHIFT;
	if (!_stricmp("VK_RSHIFT", Value)) return VK_RSHIFT;

	if (!_stricmp("LCONTROL", Value)) return VK_LCONTROL;
	if (!_stricmp("VK_LCONTROL", Value)) return VK_LCONTROL;

	if (!_stricmp("RCONTROL", Value)) return VK_RCONTROL;
	if (!_stricmp("VK_RCONTROL", Value)) return VK_RCONTROL;

	if (!_stricmp("LMENU", Value)) return VK_LMENU;
	if (!_stricmp("VK_LMENU", Value)) return VK_LMENU;

	if (!_stricmp("RMENU", Value)) return VK_RMENU;
	if (!_stricmp("VK_RMENU", Value)) return VK_RMENU;

	if (!_stricmp("BRIGHT WHITE", Value)) return -1;
	if (!_stricmp("WHITE", Value)) return 0;
	if (!_stricmp("RED", Value)) return 1;
	if (!_stricmp("GREEN", Value)) return 2;
	if (!_stricmp("BLUE", Value)) return 3;
	if (!_stricmp("GOLD", Value)) return 4;
	if (!_stricmp("GRAY", Value)) return 5;
	if (!_stricmp("BLACK", Value)) return 6;
	if (!_stricmp("GOLD 2", Value)) return 7;
	if (!_stricmp("ORANGE", Value)) return 8;
	if (!_stricmp("YELLOW", Value)) return 9;
	if (!_stricmp("DARK GREEN", Value)) return 10;
	if (!_stricmp("PURPLE", Value)) return 11;
	if (!_stricmp("DARK GREEN 2", Value)) return 12;
	if (!_stricmp("BRIGHT WHITE 2", Value)) return 13;
	if (!_stricmp("BLACK 2", Value)) return 14;
	if (!_stricmp("SILVER", Value)) return 15;
	if (!_stricmp("LIGHT GRAY", Value)) return 16;
	if (!_stricmp("MESSY", Value)) return 17;
	if (!_stricmp("BRIGHT WHITE 3", Value)) return 18;
	if (!_stricmp("RED 2", Value)) return 19;

	if (!_stricmp("INFINITE", Value)) return INFINITE;

	return _atoi64(Value);
}

BOOL Load()
{
	CHAR File[MAX_PATH], Returned[100000];
	GetModuleDirectory();

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, "\\Interface\\Torch.ini");

	for (INT i = 0; i < ArraySize(C); i++)
	{
		GetPrivateProfileStringA(C[i].Section, C[i].Name, C[i].Default, Returned, sizeof(Returned), File);

		if (C[i].Type == BOOLEAN)
			*(LPBOOL)C[i].Variable = Bool(Returned);

		else if (C[i].Type == INTEGER)
			*(LPINT)C[i].Variable = Integer(Returned);

		else if (C[i].Type == STRING)
			strncpy_s((LPSTR)C[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	if (ClientReady(FALSE))
		IncreaseSpeedStats();

	return TRUE;
}

BOOL Save()
{
	CHAR File[MAX_PATH];
	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, "\\Interface\\Torch.ini");

	for (INT i = 0; i < ArraySize(C); i++)
	{
		if (C[i].Type == BOOLEAN)
			WritePrivateProfileIntA(C[i].Section, C[i].Name, *(LPBOOL)C[i].Variable, File);

		else if (C[i].Type == INTEGER)
			WritePrivateProfileIntA(C[i].Section, C[i].Name, *(LPINT)C[i].Variable, File);
	}

	return TRUE;
}

BOOL LoadStr()
{
	CHAR File[MAX_PATH], Returned[100000];
	GetModuleDirectory();

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, "\\Interface\\LocalStr.ini");

	for (INT i = 0; i < ArraySize(D); i++)
	{
		GetPrivateProfileStringA(D[i].Section, D[i].Name, D[i].Default, Returned, sizeof(Returned), File);

		if (D[i].Type == BOOLEAN)
			*(LPBOOL)D[i].Variable = Bool(Returned);

		else if (D[i].Type == INTEGER)
			*(LPINT)D[i].Variable = Integer(Returned);

		else if (D[i].Type == STRING)
			strncpy_s((LPSTR)D[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL LoadPlugY()
{
	CHAR File[MAX_PATH], Returned[100000];
	GetModuleDirectory();

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, "\\Interface\\PlugY.ini");

	for (INT i = 0; i < ArraySize(E); i++)
	{
		GetPrivateProfileStringA(E[i].Section, E[i].Name, E[i].Default, Returned, sizeof(Returned), File);

		if (E[i].Type == BOOLEAN)
			*(LPBOOL)E[i].Variable = Bool(Returned);

		else if (E[i].Type == INTEGER)
			*(LPINT)E[i].Variable = Integer(Returned);

		else if (E[i].Type == STRING)
			strncpy_s((LPSTR)E[i].Variable, sizeof(Returned), Returned, sizeof(Returned));
	}

	return TRUE;
}

BOOL SavePlugY()
{
	CHAR File[MAX_PATH];
	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));
	strcat_s(File, "\\Interface\\PlugY.ini");

	for (INT i = 0; i < ArraySize(E); i++)
	{
		if (E[i].Type == BOOLEAN)
			WritePrivateProfileIntA(E[i].Section, E[i].Name, *(LPBOOL)E[i].Variable, File);

		else if (E[i].Type == INTEGER)
			WritePrivateProfileIntA(E[i].Section, E[i].Name, *(LPINT)E[i].Variable, File);
	}

	return TRUE;
}

VOID GetModuleDirectory()
{
	GetModuleFileNameA(V_DLL, V_FileNamePath, MAX_PATH);
	PathRemoveFileSpecA(V_FileNamePath);
	strcat_s(V_FileNamePath, sizeof(V_FileNamePath), "\\");
}

VOID WritePrivateProfileIntA(LPCSTR Section, LPCSTR Entry, INT Value, LPCSTR Filename)
{
	CHAR Convert[32]; // Up from 10.  Crash Fix
	_itoa_s(Value, Convert, 32, 10);
	WritePrivateProfileStringA(Section, Entry, Convert, Filename);
}

VOID WritePrivateProfileInt64A(LPCSTR Section, LPCSTR Entry, INT64 Value, LPCSTR Filename)
{
	CHAR Convert[32]; // Up from 10.  Crash Fix
	_i64toa_s(Value, Convert, 32, 10);
	WritePrivateProfileStringA(Section, Entry, Convert, Filename);
}

BOOL PreloadSettings()
{
#ifdef DEBUGKEYITEMS
	V_HaveKeyItemExp1[0] = 5148;
	V_HaveKeyItemExp1[1] = 239;
	V_HaveKeyItemExp1[2] = 591;
	V_HaveKeyItemExp1[3] = 248;
	V_HaveKeyItemExp1[4] = 227;
	V_HaveKeyItemExp1[5] = 398;
	V_HaveKeyItemExp2[0] = 2219;
	V_HaveKeyItemExp2[1] = 987;
	V_HaveKeyItemExp2[2] = 4702;
	V_HaveKeyItemExp2[3] = 2387;
	V_HaveKeyItemExp3[0] = 5008;
	V_HaveKeyItemExp3[1] = 3784;
	V_HaveKeyItemExp3[2] = 6742;
	V_HaveKeyItemExp3[3] = 1637;
	V_HaveKeyItemExp3[4] = 5564;
	V_HaveKeyItemExp3[5] = 4551;
	V_HaveKeyItemExp4[0] = 2335;
	V_HaveKeyItemExp4[1] = 4871;
	V_HaveKeyItemExp4[2] = 4441;
	V_HaveKeyItemExp4[3] = 2123;
	V_HaveKeyItemExp4[4] = 7763;
	V_HaveKeyItemExp4[5] = 6222;
	V_HaveKeyItemExp5[0] = 9095;
	V_HaveKeyItemExp5[1] = 5478;
	V_HaveKeyItemExp5[2] = 3449;
	V_HaveKeyItemExp5[3] = 4319;
	V_HaveKeyItemExp5[4] = 2984;
	V_HaveKeyItemExp6[0] = 4641;
	V_HaveKeyItemExp6[1] = 7329;
	V_HaveKeyItemExp6[2] = 6691;
	V_HaveKeyItemExp6[3] = 7943;
	V_HaveKeyItemExp6[4] = 2113;
#endif

	//Aim
	V_Aim = 0;
	V_BlockFakes = 0;
	//V_HostilesOnly = 0;
	V_AutoBlindDistance = 0;
	V_AutoKBDistance = 0;
	K_AttackMyselfLeft = 0;
	K_AttackMyselfRight = 0;
	K_AttackTargetLeft = 0;
	K_AttackTargetRight = 0;
	K_AttackNearestTargetLeft = 0;
	K_AttackNearestTargetRight = 0;
	K_Blind = 0;
	K_AutoBlind = 0;
	K_AutoKB = 0;
	K_NextTarget = 0;
	K_PreviousTarget = 0;
	K_SetKickLeft = 0;
	K_SetKickRight = 0;

	//Death Message
	V_DeathMessage = 0;
	V_DeathMessageDelay = 0;
	//V_Line1 = "";
	//V_Line2 = "";
	//V_Line3 = "";
	//V_Line4  = "";
	//V_Line5  = "";
	//V_Line6  = "";
	//V_Line7  = "";
	//V_Line8  = "";
	//V_Line9  = "";
	//V_Line10  = "";
	//V_Line11  = "";
	//V_Line12  = "";
	//V_Line13  = "";
	//V_Line14  = "";
	//V_Line15  = "";
	//V_Line16  = "";
	//V_Line17  = "";
	//V_Line18  = "";
	//V_Line19  = "";
	//V_Line20  = "";

	//Design
	K_Clean = 0;
	V_Screenshot = 0;
	V_Orbs = 0; //New key item?
	V_Mouse = 0;
	V_PlayerLifePercent = 1; 
	V_PlayerLifeBar = 1;
	V_Vectors = 1;
	V_HostilePlayerColor = 98;
	V_TargetPlayerColor = 96;
	V_AutomapInfoGameNameColor = 4;
	V_AutomapInfoGameNameFont = 1;
	V_AutomapInfoGamePasswordColor = 4;
	V_AutomapInfoGamePasswordFont = 1;
	V_AutomapInfoLevelColor = 4; // 1 - Red
	V_AutomapInfoLevelFont = 1; // 7 - Large
	V_AutomapInfoDifficultyColor = 4;
	V_AutomapInfoDifficultyFont = 1;
	V_AutomapInfoIPColor = 4;
	V_AutomapInfoIPFont = 1;
	V_AutomapInfoLocalTimeColor = 4;
	V_AutomapInfoLocalTimeFont = 1;
	V_AutomapInfoJapanTimeColor = 4;
	V_AutomapInfoJapanTimeFont = 1;
	V_AutomapInfoGameTimerColor = 4;
	V_AutomapInfoGameTimerFont = 1;
	V_AutomapInfoFPSColor = 4;
	V_AutomapInfoFPSFont = 1;
	V_AutomapInfoSkipColor = 4;
	V_AutomapInfoSkipFont = 1;
	V_AutomapInfoPingColor = 4;
	V_AutomapInfoPingFont = 1;
	V_AutomapInfoDayOfWeekColor = 4;
	V_AutomapInfoDayOfWeekFont = 1;
	V_AutomapInfoCharacterNameColor = 4;
	V_AutomapInfoCharacterNameFont = 0;
	V_EscapeInfo = 0;
	V_EscapeInfoX = 0;
	V_EscapeInfoY = 0;
	V_EscapeInfoTitleColor = 0;
	//V_ExpInfo = 0;
	V_ExpInfoX = 20;
	V_ExpInfoY = 285;
	V_ExpInfoTitleColor = 0;
	V_LifeOrbColor = 1;
	V_LifeOrbFont = 0;
	V_ManaOrbColor = 3;
	V_ManaOrbFont = 0;
	if(V_HaveKeyItemExp1[3] == 248)
	{
		V_UIDash = V_ToggleKeyItem[3][0];
	}
	else
	{
		V_UIDash = 0;
	}
	if(V_HaveKeyItemExp1[5] == 398)
	{
		V_UIClock = V_ToggleKeyItem[5][0];
	}
	else
	{
		V_UIClock = 0;
	}
	if(V_HaveKeyItemExp1[4] == 227)
	{
		V_ExpMeter = V_ToggleKeyItem[4][0];
	}
	else
	{
		V_ExpMeter = 0;
	}
	V_ExpAddComma = 1;
	if (V_HaveKeyItemExp1[4] == 227)
	{
		V_GoldMeter = V_ToggleKeyItem[4][0]; //New key item?
	}
	else
	{
		V_GoldMeter = 0;
	}
	if(V_HaveKeyItemExp5[4] == 2984)
	{
		V_LifeDots = V_ToggleKeyItem[4][4];
	}
	else
	{
		V_LifeDots = 0;
	}
	V_TransparentNametag = 1;
	V_MusicPlayer = 0;
	V_MusicPlayerX = 0;
	V_MusicPlayerY = 0;
	V_MusicPlayerTitleColor = 0;
	V_MusicPlayerSongLength = 0;
	V_PotionInfo = 0;
	V_PotionInfoX = 0;
	V_PotionInfoY = 0;
	V_PotionInfoTitleColor = 0;
	//V_StateList = 0;
	V_StateListX = 150;
	V_StateListY = 365;
	V_StateListTitleColor = 0;
	//V_Supplies = 0;
	V_SuppliesX = 20;
	V_SuppliesY = 365;
	V_SuppliesTitleColor = 0;
	//V_Gold = 0;
	V_GoldX = 150;
	V_GoldY = 285;
	V_GoldTitleColor = 0;
	V_TargetClick = 0;
	V_TargetClickColor = 0;
	V_TargetVector = 0;
	V_TargetVectorColor = 0;
	V_TargetList = 0;
	V_TargetListX = 0;
	V_TargetListY = 0;
	V_TargetListTitleColor = 0;
	V_TargetListTargettedColor = 0;
	V_TargetListNonTargettedColor = 0;
	V_TargetInfo = 0;
	V_TargetInfoX = 0;
	V_TargetInfoY = 0;
	V_TargetInfoTitleColor = 0;
	V_ConsoleX = 0;
	V_ConsoleY = 0;

	//Enchant
	V_Enchant = 0;
	V_EnchantNote = 0;

	//Escape
	V_TownAmplify = 0;
	V_TownBattleCry = 0;
	V_TownConvicted = 0;
	V_TownDecrepify = 0;
	V_TownIronMaiden = 0;
	V_TownLowerResist = 0;
	V_LifeExitPercent = 0;
	V_ManaExitPercent = 0;
	V_LifeTownPercent = 0;
	V_ManaTownPercent = 0;
	V_TPIntervalTime = 1000;
	V_TPWhenHostiled = 0;
	V_TPWhenAttacked = 0;
	V_ExitWhenHostiled = 0;
	V_BlockTP = 0;
	V_FastTP = 0;
	V_NoTPDelay = 0;
	K_Exit = 0;
	K_Town = 0;
	K_TP = 0;

	//Flash
	V_AntiFlash = 0;
	//V_EnableFlash = 0;
	K_Flash = 0;
	V_FlashDelay = 0;

	//Game Filter
	V_GameFilter = 0;

	//Miscellaneous
	V_AntiItemGlitch = 1;
	V_AntiMinimize = 1;
	V_AutoParty = 0;
#ifdef ANTIQUESTBOX
	V_AntiQuestBox = 1;
#else
	V_AntiQuestBox = 0;
#endif
	K_ControlHotkey = 0;
	V_CopyPaste = 1;
	K_LoadConfiguration = 0;
	V_LogInGameMessages = 0;
	V_KillLog = 0;
	V_ModifiedJoinMessage = 1;
	V_MonsterDeathAnimation = 0;
	V_RememberGameName = 1;
	V_RememberGamePassword = 1;
	V_OutTownSelect = 0;
	if(V_HaveKeyItemExp1[2] == 591)
	{
		V_AutomapOnJoin = V_ToggleKeyItem[2][0];
	}
	else
	{
		V_AutomapOnJoin = 0;
	}
	//V_MaxGameTime = 300;

	//Notification
	V_LifePot = 0;
	V_LifeJuv = 0;
	V_ManaPot = 0;
	V_ManaJuv = 0;
	V_Potion = 0;
	V_Quests = 0;

	//Options Menu
	K_Options = 0;
	V_OptionTitleColor = 0;
	V_OptionTitleFont = 0;
	V_OptionVariableColor = 0;
	V_OptionVariableFont = 0;
	V_OptionCloseColor = 0;
	V_OptionCloseFont = 0;

	//Potion
	V_LifePotPercent = 0; //New key item?
	V_LifePotDelay = 2000;
	V_LifeJuvPercent = 0; //New key item?
	V_LifeJuvDelay = 500;
	V_ManaPotPercent = 0; //New key item?
	V_ManaPotDelay = 2000;
	V_ManaJuvPercent = 0; //New key item?
	V_ManaJuvDelay = 500;
	V_TownDrinker = 1;

	//Reveal
	if(V_HaveKeyItemExp5[2] == 3449)
	{
		V_AntiShake = V_ToggleKeyItem[2][4];
	}
	else
	{
		V_AntiShake = 0;
	}
	V_AntiWeather = 0;
	if(V_HaveKeyItemExp5[1] == 5478)
	{
		V_AutoRevealAutomap = V_ToggleKeyItem[1][4];
	}
	else
	{
		V_AutoRevealAutomap = 0;
	}
#ifndef LAZARUSMOD
	if(V_HaveKeyItemExp6[2] == 6691)
	{
		V_Ethereal = V_ToggleKeyItem[2][5];
	}
	else
	{
		V_Ethereal = 0;
	}
#else
	V_Ethereal = 1;
#endif
	if(V_HaveKeyItemExp6[1] == 7329)
	{
		V_FullLightRadius = V_ToggleKeyItem[1][5];
	}
	else
	{
		V_FullLightRadius = 0;
	}
#ifndef LAZARUSMOD
	if(V_HaveKeyItemExp6[3] == 7943)
	{
		V_ItemLevel = V_ToggleKeyItem[3][5];
	}
	else
	{
		V_ItemLevel = 0;
	}
#else
	V_ItemLevel = 1;
#endif
	if(V_HaveKeyItemExp5[3] == 4319)
	{
		V_ProtectItemSocket = V_ToggleKeyItem[3][4];
	}
	else
	{
		V_ProtectItemSocket = 0;
	}
#ifndef LAZARUSMOD
	if(V_HaveKeyItemExp6[4] == 2113)
	{
		V_Sockets = V_ToggleKeyItem[4][5];
	}
	else
	{
		V_Sockets = 0;
	}
#else
	V_Sockets = 1;
#endif
	V_LevelNames = 1;
	V_ShrineImages = 1;
	V_ViewItemBasicStats = 0;
	V_ViewSocketable = 0;
	V_LifeBarTransparency = 0;
	V_LifeBarColor = 1;
	V_LevelNamesFontColor = 0;
	V_Missiles = 0; //New key item?
	V_MyColor = 151;
	V_NeutralColor = 32;
	V_HostileColor = 98;
	V_PartyColor = 155;
	V_Monsters = 1; //New key item?
	V_MonsterNames = 0;
	V_MonsterResists = 0; //New key item?
	V_MonsterResistsFire = 1;
	V_MonsterResistsCold = 1;
	V_MonsterResistsLightning = 1;
	V_MonsterResistsPoison = 1;
	V_MonsterResistsPhysical = 1;
	V_MonsterResistsMagic = 1;
	V_NormalColor = 98;
	V_BossColor = 155;
	V_BossNameColor = 0;
	V_ChampionColor = 151;
	V_MinionColor = 91;
	V_MonsterEnchantments = 0; //New key item?
	V_MonsterEnchantmentsMight = 1;
	V_MonsterEnchantmentsFanaticism = 1;
	V_MonsterEnchantmentsConviction = 1;
	V_MonsterEnchantmentsBlessedAim = 1;
	V_MonsterEnchantmentsHolyFire = 1;
	V_MonsterEnchantmentsHolyFreeze = 1;
	V_MonsterEnchantmentsHolyShock = 1;
	V_MonsterUnits = 0; //New key item?
	V_MonsterUnitsDevilkinShamans = 1;
	V_MonsterUnitsDamned = 1;
	V_MonsterUnitsUrdars = 1;
	V_MonsterUnitsVampires = 1;
	V_MonsterUnitsFlayerShamans = 1;
	V_MonsterUnitsThornedHulks = 1;
	V_MonsterUnitsSouls = 1;
	V_MonsterUnitsDolls = 1;
	V_MonsterUnitsPitLords = 1;
	V_MonsterUnitsKnights = 1;
	V_MonsterUnitsOblivions = 1;
	V_MonsterUnitsMoonLords = 1;
	V_MonsterUnitsUnravelers = 1;
	V_MonsterUnitsSuicideMinions = 1;
	V_MonsterUnitsSuccubusWitches = 1;
	V_MonsterUnitsSnakes = 1;
	V_MonsterUnitsUndeadCharger = 1;
	V_MonsterLifeBarLevel = 1;
	V_MonsterLifeBarResists = 1;
	V_MonsterLifeBarTC = 1;
	K_ViewItemBasicStats = 0;
	K_ProtectItemSocket = 0;
	K_Stats = 0;
	K_ViewInventory = 0;

	//Speed
	V_SpeedAttack = 0;
	V_AttackFrames = 0;
	V_SpeedCast = 0;
	V_CastFrames = 0;

	if(V_HaveKeyItemExp3[5] == 4551)
	{
		if(V_ToggleKeyItem[5][2])
		{
			V_AttackSpeed = 125;
		}
		else
		{
			V_AttackSpeed = 0;
		}
	}
	else
	{
		V_AttackSpeed = 0;
	}
	if(V_HaveKeyItemExp3[3] == 1637)
	{
		if(V_ToggleKeyItem[3][2])
		{
			V_BlockRate = 125;
		}
		else
		{
			V_BlockRate = 0;
		}
	}
	else
	{
		V_BlockRate = 0;
	}

	if(V_HaveKeyItemExp3[1] == 3784)
	{
		if(V_ToggleKeyItem[1][2])
		{
			V_CastRate = 125;
		}
		else
		{
			V_CastRate = 0;
		}
	}
	else
	{
		V_CastRate = 0;
	}

	if(V_HaveKeyItemExp3[2] == 6742)
	{
		if(V_ToggleKeyItem[2][2])
		{
			V_HitRecoveryRate = 125;
		}
		else
		{
			V_HitRecoveryRate = 0;
		}
	}
	else
	{
		V_HitRecoveryRate = 0;
	}

	V_RunWalkSpeed = 0;
	if(V_HaveKeyItemExp3[4] == 5564)
	{
		if(V_ToggleKeyItem[4][2])
		{
			V_VelocitySpeed = 50;
		}
		else
		{
			V_VelocitySpeed = 0;
		}
	}
	else
	{
		V_VelocitySpeed = 0;
	}

	//Teleport
	V_FastTeleport = 0; //New key item?
	V_FarcastTeleport = 0; //New key item?
	K_TeleHost = 0;
	K_TeleWalk = 0;
	K_NextLevelVector = 0; //New key item?
	V_NextLevelVectorColor = 151;
	K_PreviousLevelVector = 0; //New key item?
	V_PreviousLevelVectorColor = 168;
	K_QuestVector = 0; //New key item?
	V_QuestVectorColor = 155;
	K_WaypointVector = 0; //New key item?
	V_WaypointVectorColor = 132;
	V_SealVectorColor = 13;
	V_ActiveVectorColor = 98;

	//Winamp
	K_CurrentSong = 0;
	K_FastForwardSong = 0;
	K_RewindSong = 0;
	K_HigherSongVolume = 0;
	K_LowerSongVolume = 0;
	K_NextSong = 0;
	K_PreviousSong = 0;
	K_PauseSong = 0;
	K_PlaySong = 0;
	K_StopSong = 0;

	//Menu
	K_CloseBackspace = 8;
	K_CloseEscape = 27;

	return TRUE;
}

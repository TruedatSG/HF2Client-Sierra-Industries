#ifdef VARS

#define ARRAY(Type, Name)		CArrayEx<Type, Type> V_##Name;
#define KEY(Name)				INT K_##Name;
#define TOGGLE(Name)			BOOL V_##Name; INT K_##Name;
#define VAR(Type, Name)			Type V##_##Name;

#else

#define ARRAY(Type, Name)		extern CArrayEx<Type, Type> V_##Name;
#define KEY(Name)				extern INT K_##Name;
#define TOGGLE(Name)			extern BOOL V_##Name; extern INT K_##Name;
#define VAR(Type, Name)			extern Type V_##Name;

#endif

VAR(HINSTANCE, DLL)
VAR(BOOL, Game)
VAR(INT, PatchInGame)
VAR(BOOL, PatchOutGame)
VAR(DWORD, GameTimer)

VAR(LPSTR, Name)
VAR(FLOAT, Version)

VAR(CHAR, FileNamePath[1000])
VAR(WNDPROC, OldWndProc)

VAR(BOOL, AntiMinimize)
VAR(BOOL, CubeOrStashOpened)
VAR(BOOL, HideCommands)
VAR(BOOL, HostileImage)

KEY(ControlHotkey)
KEY(LoadConfiguration)

//Aim
ARRAY(PTARGETINFO, Players)

KEY(AttackMyselfLeft)
KEY(AttackMyselfRight)
KEY(AttackNearestTargetLeft)
KEY(AttackNearestTargetRight)
KEY(AttackTargetLeft)
KEY(AttackTargetRight)
KEY(Blind)
KEY(NextTarget)
KEY(PreviousTarget)
KEY(SetKickLeft)
KEY(SetKickRight)

TOGGLE(AutoBlind)
TOGGLE(AutoKB)

VAR(BOOL, Aim)
VAR(BOOL, BlockFakes)
VAR(BOOL, HostilesOnly)
VAR(BOOL, KB)
VAR(BOOL, Kick)
VAR(BOOL, LeftAttack)
VAR(BOOL, Reblind)

VAR(INT, Target)
VAR(INT, Blind)

VAR(DWORD, AutoBlindDistance)
VAR(DWORD, AutoKBDistance)

//Auto Party
VAR(BOOL, AutoParty)

//Copy & Paste
VAR(BOOL, CopyPaste)
VAR(LPCONTROL, EditBox)

//Death Message
VAR(BOOL, DeathMessage)
VAR(BOOL, DeathMessageIteration)

VAR(CHAR, LocalTime[50])
VAR(CHAR, LocalDate[50])

VAR(CHAR, InjectKills[1000])
VAR(CHAR, InGameKills[1000])
VAR(CHAR, InjectDeaths[1000])
VAR(CHAR, InGameDeaths[1000])

VAR(INT, InjectKillCount)
VAR(INT, InGameKillCount)
VAR(INT, InjectDeathCount)
VAR(INT, InGameDeathCount)

VAR(DWORD, DeathMessageDelay)

VAR(CHAR, Line1[1000])
VAR(CHAR, Line2[1000])
VAR(CHAR, Line3[1000])
VAR(CHAR, Line4[1000])
VAR(CHAR, Line5[1000])
VAR(CHAR, Line6[1000])
VAR(CHAR, Line7[1000])
VAR(CHAR, Line8[1000])
VAR(CHAR, Line9[1000])
VAR(CHAR, Line10[1000])
VAR(CHAR, Line11[1000])
VAR(CHAR, Line12[1000])
VAR(CHAR, Line13[1000])
VAR(CHAR, Line14[1000])
VAR(CHAR, Line15[1000])
VAR(CHAR, Line16[1000])
VAR(CHAR, Line17[1000])
VAR(CHAR, Line18[1000])
VAR(CHAR, Line19[1000])
VAR(CHAR, Line20[1000])

VAR(CHAR, SlainName[30])

//Design
KEY(Clean)
KEY(Options)
KEY(Stats)

VAR(BOOL, Hide)

VAR(Design *, Design)

VAR(BOOL, Mouse)
VAR(BOOL, Orbs)
VAR(BOOL, PlayerLifePercent)
VAR(BOOL, PlayerLifeBar)
VAR(BOOL, Screenshot)
VAR(BOOL, Vectors)

VAR(INT, HostilePlayerColor)
VAR(INT, TargetPlayerColor)

VAR(BOOL, TargetVector)
VAR(INT, TargetVectorColor)

VAR(BOOL, TargetClick)
VAR(INT, TargetClickColor)

VAR(CHAR, AutomapInfoGameNameText[0x100])
VAR(CHAR, AutomapInfoGamePasswordText[0x100])
VAR(CHAR, AutomapInfoLevelText[0x100])
VAR(CHAR, AutomapInfoDifficultyText[0x100])
VAR(CHAR, AutomapInfoIPText[0x100])
VAR(CHAR, AutomapInfoLocalTimeText[0x100])
VAR(CHAR, AutomapInfoJapanTimeText[0x100])
VAR(CHAR, AutomapInfoGameTimerText[0x100])
VAR(CHAR, AutomapInfoFPSText[0x100])
VAR(CHAR, AutomapInfoSkipText[0x100])
VAR(CHAR, AutomapInfoPingText[0x100])
VAR(CHAR, AutomapInfoDayOfWeekText[0x100])
VAR(CHAR, AutomapInfoCharacterNameText[0x100])

VAR(INT, AutomapInfoGameNameColor)
VAR(INT, AutomapInfoGamePasswordColor)
VAR(INT, AutomapInfoLevelColor)
VAR(INT, AutomapInfoDifficultyColor)
VAR(INT, AutomapInfoIPColor)
VAR(INT, AutomapInfoLocalTimeColor)
VAR(INT, AutomapInfoJapanTimeColor)
VAR(INT, AutomapInfoGameTimerColor)
VAR(INT, AutomapInfoFPSColor)
VAR(INT, AutomapInfoSkipColor)
VAR(INT, AutomapInfoPingColor)
VAR(INT, AutomapInfoDayOfWeekColor)
VAR(INT, AutomapInfoCharacterNameColor)

VAR(INT, AutomapInfoGameNameFont)
VAR(INT, AutomapInfoGamePasswordFont)
VAR(INT, AutomapInfoLevelFont)
VAR(INT, AutomapInfoDifficultyFont)
VAR(INT, AutomapInfoIPFont)
VAR(INT, AutomapInfoLocalTimeFont)
VAR(INT, AutomapInfoJapanTimeFont)
VAR(INT, AutomapInfoGameTimerFont)
VAR(INT, AutomapInfoFPSFont)
VAR(INT, AutomapInfoSkipFont)
VAR(INT, AutomapInfoPingFont)
VAR(INT, AutomapInfoDayOfWeekFont)
VAR(INT, AutomapInfoCharacterNameFont)

VAR(BOOL, AutomapInfoTimeZonePDT)
VAR(INT, AutomapInfoDSTStart)
VAR(INT, AutomapInfoDSTEnd)

VAR(BOOL, EscapeInfo)
VAR(INT, EscapeInfoX)
VAR(INT, EscapeInfoY)
VAR(INT, EscapeInfoTitleColor)

VAR(BOOL, ExpInfo)
VAR(INT, ExpInfoX)
VAR(INT, ExpInfoY)
VAR(INT, ExpInfoTitleColor)

VAR(INT, LifeOrbColor)
VAR(INT, LifeOrbFont)
VAR(INT, ManaOrbColor)
VAR(INT, ManaOrbFont)

VAR(BOOL, Options)
VAR(INT, OptionTitleColor)
VAR(INT, OptionTitleFont)
VAR(INT, OptionVariableColor)
VAR(INT, OptionVariableFont)
VAR(INT, OptionCloseColor)
VAR(INT, OptionCloseFont)

VAR(BOOL, UIDash)
VAR(BOOL, UIClock)
VAR(BOOL, ExpMeter)
VAR(BOOL, ExpAddComma)
VAR(BOOL, GoldMeter)
VAR(BOOL, LifeDots)
VAR(BOOL, TransparentNametag)

VAR(BOOL, PotionInfo)
VAR(INT, PotionInfoX)
VAR(INT, PotionInfoY)
VAR(INT, PotionInfoTitleColor)

VAR(BOOL, StateList)
VAR(INT, StateListX)
VAR(INT, StateListY)
VAR(INT, StateListTitleColor)

VAR(BOOL, Supplies)
VAR(INT, SuppliesX)
VAR(INT, SuppliesY)
VAR(INT, SuppliesTitleColor)

VAR(BOOL, Gold)
VAR(INT, GoldX)
VAR(INT, GoldY)
VAR(INT, GoldTitleColor)

VAR(BOOL, TargetInfo)
VAR(INT, TargetInfoX)
VAR(INT, TargetInfoY)
VAR(INT, TargetInfoTitleColor)

VAR(BOOL, TargetList)
VAR(INT, TargetListNonTargettedColor)
VAR(INT, TargetListTitleColor)
VAR(INT, TargetListTargettedColor)
VAR(INT, TargetListX)
VAR(INT, TargetListY)

VAR(BOOL, MusicPlayer)
VAR(INT, MusicPlayerX)
VAR(INT, MusicPlayerY)
VAR(INT, MusicPlayerTitleColor)
VAR(INT, MusicPlayerSongLength)

//Drop Gold
VAR(BOOL, GoldDrop)
VAR(DWORD, GoldAmount)
VAR(BOOL, AutoSS)

//Enchant
ARRAY(LPENCHANTINFO, EnchantQueue)

VAR(BOOL, Enchant)
VAR(BOOL, EnchantNote)
VAR(BOOL, EnchantNoteIteration)
VAR(BOOL, EnchantWhisper)

VAR(CHAR, EnchantPlayer[1000])
VAR(CHAR, EnchantMercenary[1000])
VAR(CHAR, EnchantAll[1000])

//Escape
KEY(Exit)
KEY(Town)
KEY(TP)

VAR(BOOL, BlockTP)
VAR(BOOL, FastTP)
VAR(BOOL, NoTPDelay)
VAR(BOOL, TP)
VAR(BOOL, TPWhenHostiled)
VAR(BOOL, TPWhenAttacked)
VAR(BOOL, ExitWhenHostiled)

VAR(DWORD, TPIntervalTime)
VAR(DWORD, TPInteractLast)
VAR(DWORD, TPLast)

VAR(DWORD, LifeExitPercent)
VAR(DWORD, ManaExitPercent)

VAR(DWORD, LifeTownPercent)
VAR(DWORD, ManaTownPercent)

VAR(BOOL, TownAmplify)
VAR(BOOL, TownBattleCry)
VAR(BOOL, TownConvicted)
VAR(BOOL, TownDecrepify)
VAR(BOOL, TownIronMaiden)
VAR(BOOL, TownLowerResist)

//Experience
VAR(DWORD, StartingExperience)

//Gold
VAR(DWORD, StartingGold)
VAR(INT, GainedGold)

//Flash
VAR(BOOL, AntiFlash)

VAR(DWORD, FlashDelay)
VAR(DWORD, FlashLast)

TOGGLE(Flash)

//Game Filter
VAR(LPCONTROL, FilterBox)
VAR(list<LPGAMELISTENTRY>, GameList)
VAR(BOOL, GameFilter)

//Miscellaneous
VAR(BOOL, AntiItemGlitch)
VAR(BOOL, AntiQuestBox)
VAR(BOOL, AutomapOnJoin)
VAR(BOOL, MonsterDeathAnimation)
VAR(INT, MaxGameTime)

VAR(BOOL, KillLog)
VAR(BOOL, LogInGameMessages)
VAR(BOOL, ModifiedJoinMessage)

VAR(BOOL, OutTownSelect)
VAR(BOOL, PlayerInTown)

VAR(BOOL, RememberGameName)
VAR(BOOL, RememberGamePassword)

VAR(WCHAR, GameName[50])
VAR(WCHAR, GamePassword[50])

VAR(INT, ConsoleDelay)
VAR(INT, ConsoleX)
VAR(INT, ConsoleY)

VAR(BOOL, Hardcore)
VAR(BOOL, Expansion)

//Notification
VAR(BOOL, Potion)
VAR(BOOL, Quests)

VAR(BOOL, LifePot)
VAR(BOOL, ManaPot)
VAR(BOOL, LifeJuv)
VAR(BOOL, ManaJuv)

//Potion
VAR(DWORD, LifePotDelay)
VAR(DWORD, LifePotLast)
VAR(DWORD, LifePotPercent)

VAR(DWORD, LifeJuvDelay)
VAR(DWORD, LifeJuvLast)
VAR(DWORD, LifeJuvPercent)

VAR(DWORD, ManaPotDelay)
VAR(DWORD, ManaPotLast)
VAR(DWORD, ManaPotPercent)

VAR(DWORD, ManaJuvDelay)
VAR(DWORD, ManaJuvLast)
VAR(DWORD, ManaJuvPercent)

VAR(DWORD, MercJuvDelay)
VAR(DWORD, MercJuvLast)
VAR(DWORD, MercJuvPercent)

VAR(DWORD, MercPotDelay)
VAR(DWORD, MercPotLast)
VAR(DWORD, MercPotPercent)

VAR(BOOL, TownDrinker)

//Reveal
TOGGLE(ProtectItemSocket)
TOGGLE(ViewItemBasicStats)
TOGGLE(ViewSocketables)

//Console
TOGGLE(ConsoleLogs)

VAR(BOOL, AntiShake)
VAR(BOOL, AntiWeather)
VAR(BOOL, AutoRevealAutomap)
VAR(BOOL, Ethereal)
VAR(BOOL, FullLightRadius)
VAR(BOOL, ItemLevel)
VAR(BOOL, LevelNames)
VAR(BOOL, MiniShrine)
VAR(BOOL, Missiles)
VAR(BOOL, Monsters)
VAR(BOOL, MonsterLifeBarResists)
VAR(BOOL, MonsterLifeBarLevel)
VAR(BOOL, MonsterLifeBarTC)
VAR(BOOL, MonsterResists)
VAR(BOOL, MonsterResistsFire)
VAR(BOOL, MonsterResistsCold)
VAR(BOOL, MonsterResistsLightning)
VAR(BOOL, MonsterResistsPoison)
VAR(BOOL, MonsterResistsPhysical)
VAR(BOOL, MonsterResistsMagic)
VAR(BOOL, MonsterNames)
VAR(BOOL, MonsterUnits)
VAR(BOOL, MonsterUnitsDevilkinShamans)
VAR(BOOL, MonsterUnitsDamned)
VAR(BOOL, MonsterUnitsUrdars)
VAR(BOOL, MonsterUnitsVampires)
VAR(BOOL, MonsterUnitsFlayerShamans)
VAR(BOOL, MonsterUnitsThornedHulks)
VAR(BOOL, MonsterUnitsSouls)
VAR(BOOL, MonsterUnitsDolls)
VAR(BOOL, MonsterUnitsPitLords)
VAR(BOOL, MonsterUnitsKnights)
VAR(BOOL, MonsterUnitsOblivions)
VAR(BOOL, MonsterUnitsMoonLords)
VAR(BOOL, MonsterUnitsUnravelers)
VAR(BOOL, MonsterUnitsSuicideMinions)
VAR(BOOL, MonsterUnitsSuccubusWitches)
VAR(BOOL, MonsterUnitsSnakes)
VAR(BOOL, MonsterUnitsUndeadCharger)
VAR(BOOL, MonsterEnchantments)
VAR(BOOL, MonsterEnchantmentsMight)
VAR(BOOL, MonsterEnchantmentsFanaticism)
VAR(BOOL, MonsterEnchantmentsConviction)
VAR(BOOL, MonsterEnchantmentsBlessedAim)
VAR(BOOL, MonsterEnchantmentsHolyFire)
VAR(BOOL, MonsterEnchantmentsHolyFreeze)
VAR(BOOL, MonsterEnchantmentsHolyShock)
VAR(BOOL, ShrineImages)
VAR(BOOL, Sockets)
VAR(BOOL, ViewSocketable)
VAR(BOOL, PoisonResistGreen)

VAR(BOOL, MonsterLifeBarNameOn)
VAR(BOOL, ViewSocketableMonsterLifeBarFlag)

VAR(BYTE, MonsterTCs[1000])
VAR(BYTE, SuperUniqueTCs[100])

VAR(WCHAR, MonsterLifeBarName[0x400])
VAR(WCHAR, MonsterDesc[0x800])

VAR(LPCELLFILE, MyShrineCells[2][TOTALSHRINES])
VAR(LPCELLFILE, WaypointCell)
VAR(LPCELLFILE, MinimapObjectCell)

VAR(MYAUTOMAPLAYERMAN, MyAutoMapLayer[100])

VAR(INT, LevelNamesFontColor)
VAR(CHAR, StaffTombIndicator[0x40])

VAR(BYTE, LifeBarTransparency)
VAR(BYTE, LifeBarColor)

VAR(INT, HostileSummonColor)
VAR(INT, PartiedSummonColor)
VAR(INT, NeutralSummonColor)
VAR(INT, MySummonColor)

VAR(INT, HostileColor)
VAR(INT, MyColor)
VAR(INT, NeutralColor)
VAR(INT, PartyColor)

VAR(INT, BossColor)
VAR(INT, BossNameColor)
VAR(INT, ChampionColor)
VAR(INT, MinionColor)
VAR(INT, NormalColor)

VAR(Reveal *, Reveal)

VAR(WCHAR *, MonsterDescComma)

VAR(LPUNITANY, ViewingUnit)
KEY(ViewInventory)

VAR(BOOL, CharacterStats)

//Speed
VAR(BOOL, SpeedAttack)
VAR(BOOL, SpeedCast)

VAR(INT, AttackFrames)
VAR(INT, CastFrames)

VAR(INT, AttackSpeed)
VAR(INT, BlockRate)
VAR(INT, CastRate)
VAR(INT, HitRecoveryRate)
VAR(INT, RunWalkSpeed)
VAR(INT, VelocitySpeed)

//States
VAR(BOOL, DelayedChicken)

VAR(DWORD, AmplifyDamageTimer)
VAR(DWORD, BattleCommandTimer)
VAR(DWORD, BattleCryTimer)
VAR(DWORD, BattleOrdersTimer)
VAR(DWORD, BoneArmorTimer)
VAR(DWORD, BurstOfSpeedTimer)
VAR(DWORD, ChillingArmorTimer)
VAR(DWORD, ColdTimer)
VAR(DWORD, ConvictedTimer)
VAR(DWORD, CycloneArmorTimer)
VAR(DWORD, DecrepifyTimer)
VAR(DWORD, EnchantTimer)
VAR(DWORD, EnergyShieldTimer)
VAR(DWORD, FadeTimer)
VAR(DWORD, FrozenTimer)
VAR(DWORD, FrozenArmorTimer)
VAR(DWORD, HolyFrozenTimer)
VAR(DWORD, HolyShieldTimer)
VAR(DWORD, InnerSightTimer)
VAR(DWORD, IronMaidenTimer)
VAR(DWORD, LifeTapTimer)
VAR(DWORD, LowerResistTimer)
VAR(DWORD, OakSageTimer)
VAR(DWORD, OpenWoundsTimer)
VAR(DWORD, PoisonedTimer)
VAR(DWORD, ShiverArmorTimer)
VAR(DWORD, ShoutTimer)
VAR(DWORD, SlowedTimer)
VAR(DWORD, TerrorTimer)
VAR(DWORD, ThunderStormTimer)
VAR(DWORD, VenomTimer)

//Teleport
ARRAY(POINT, TeleportQueue)

KEY(TeleHost)
TOGGLE(TeleWalk)

VAR(BOOL, FastTeleport)
VAR(BOOL, FarcastTeleport)

//Threads
VAR(THREAD, PrimaryThread)
ARRAY(HANDLE, Threads)
ARRAY(HANDLE, ThreadsAux)

//Vectors
ARRAY(LPVECTOR, CurrentVectors)

//Console
//ARRAY(CONSOLEMESSAGE, List)

KEY(NextLevelVector)
KEY(PreviousLevelVector)
KEY(QuestVector)
KEY(WaypointVector)

VAR(INT, ActiveVectorColor)
VAR(INT, NextLevelVectorColor)
VAR(INT, PreviousLevelVectorColor)
VAR(INT, QuestVectorColor)
VAR(INT, WaypointVectorColor)
VAR(INT, SealVectorColor)

VAR(DWORD, LastLevel)
VAR(LPVECTOR, CurrentVector)

//Winamp
KEY(CurrentSong)
KEY(NextSong)
KEY(PreviousSong)
KEY(PlaySong)
KEY(PauseSong)
KEY(StopSong)
KEY(FastForwardSong)
KEY(RewindSong)
KEY(HigherSongVolume)
KEY(LowerSongVolume)

VAR(CHAR, CurrentSongPhrase[1000])

//Click
VAR(DWORD, SelectedUnitId)
VAR(DWORD, SelectedUnitType)

VAR(BOOL, ClickAction)

VAR(BOOL, ClickDelay)
VAR(BOOL, ClickIgnore)
VAR(BOOL, ClickIgnoreMenu)
VAR(BOOL, ClickIgnoreStat)
VAR(BOOL, ClickIgnoreInfo)
VAR(BOOL, ClickIgnoreMission)
VAR(BOOL, ClickIgnoreAbility)
VAR(BOOL, ClickIgnoreGuide)
VAR(BOOL, ClickIgnoreCalc)
VAR(BOOL, ClickIgnoreSetting)

VAR(BOOL, ClickIgnoreInfo2)
VAR(BOOL, ClickIgnoreMission2)
VAR(BOOL, ClickIgnoreAbility2)
VAR(BOOL, ClickIgnoreStat2)
VAR(BOOL, ClickIgnoreGuide2)
VAR(BOOL, ClickIgnoreGuide3)
VAR(BOOL, ClickIgnoreGuide4)

VAR(BOOL, InGame)
VAR(BOOL, UnhookClick)
VAR(HHOOK, MiHook)

ARRAY(HANDLE, ThreadsMain)

//Menu
KEY(CloseBackspace)
KEY(CloseEscape)

VAR(BOOL, ToggleMenu)

VAR(BOOL, ToggleStatMenu)
VAR(BOOL, ToggleInfoMenu)
VAR(BOOL, ToggleMissionMenu)
VAR(BOOL, ToggleAbilityMenu)
VAR(BOOL, ToggleGuideMenu)
VAR(BOOL, ToggleCalcMenu)
VAR(BOOL, ToggleSettingMenu)

VAR(BOOL, ToggleInfoMenu2)
VAR(BOOL, ToggleMissionMenu2)

VAR(INT, BoxColorMenu)
VAR(INT, BoxColorStatMenu)
VAR(INT, BoxColorInfoMenu)
VAR(INT, BoxColorMissionMenu)
VAR(INT, BoxColorAbilityMenu)
VAR(INT, BoxColorGuideMenu)
VAR(INT, BoxColorCalcMenu)
VAR(INT, BoxColorSettingMenu)

VAR(INT, MenuObject)

//List filters
VAR(INT, SelectedQuestPage)
VAR(INT, SelectedCounterPage)

//Text filters
VAR(INT, SelectedQuestPageText)
VAR(INT, SelectedCounterPageText)

//Sound filters
VAR(BOOL, SoundMenu)
VAR(BOOL, SoundStatMenu)
VAR(BOOL, SoundInfoMenu)
VAR(BOOL, SoundMissionMenu)
VAR(BOOL, SoundAbilityMenu)
VAR(BOOL, SoundGuideMenu)
VAR(BOOL, SoundCalcMenu)
VAR(BOOL, SoundSettingMenu)
VAR(BOOL, SoundCloseB)
VAR(BOOL, SoundMinus)
VAR(BOOL, SoundPlus)
VAR(BOOL, SoundSelectB[21])
VAR(BOOL, BackSoundSelectB)
VAR(BOOL, NextSoundSelectB)
VAR(BOOL, BackTextSoundSelectB)
VAR(BOOL, NextTextSoundSelectB)
VAR(BOOL, PlayedSecret1)

//Info list
VAR(CHAR, PlayerInfoListStrL1[64])
VAR(CHAR, PlayerInfoListStrL2[64])
VAR(CHAR, PlayerInfoListStrL3[64])
VAR(CHAR, PlayerInfoListStrL4[64])
VAR(CHAR, PlayerInfoListStrL5[64])
VAR(CHAR, PlayerInfoListStrL6[64])
VAR(CHAR, PlayerInfoListStrL7[64])
VAR(CHAR, PlayerInfoListStrL8[64])
VAR(CHAR, PlayerInfoListStrL9[64])
VAR(CHAR, PlayerInfoListStrL10[64])
VAR(CHAR, PlayerInfoListStrL11[64])
VAR(CHAR, PlayerInfoListStrL12[64])
VAR(CHAR, PlayerInfoListStrL13[64])
VAR(CHAR, PlayerInfoListStrL14[64])
VAR(CHAR, PlayerInfoListStrL15[64])
VAR(CHAR, PlayerInfoListStrL16[64])
VAR(CHAR, PlayerInfoListStrL17[64])
VAR(CHAR, PlayerInfoListStrL18[64])
VAR(CHAR, PlayerInfoListStrL19[64])
VAR(CHAR, PlayerInfoListStrL20[64])

//Info list expanded
VAR(CHAR, InfoListMainStr[20][64])
VAR(CHAR, InfoListOneStr[20][64])
VAR(CHAR, InfoListTwoStr[20][64])
VAR(CHAR, InfoListThreeStr[20][64])
VAR(CHAR, InfoListFourStr[20][64])
VAR(CHAR, InfoListFiveStr[20][64])
VAR(CHAR, InfoListSixStr[20][64])
VAR(CHAR, InfoListSevenStr[20][64])
VAR(CHAR, InfoListEightStr[20][64])
VAR(CHAR, InfoListNineStr[20][64])
VAR(CHAR, InfoListTenStr[20][64])
VAR(CHAR, InfoListElevenStr[20][64])
VAR(CHAR, InfoListTwelveStr[20][64])
VAR(CHAR, InfoListThirteenStr[20][64])
VAR(CHAR, InfoListFourteenStr[20][64])
VAR(CHAR, InfoListFifteenStr[20][64])
VAR(CHAR, InfoListSixteenStr[20][64])
VAR(CHAR, InfoListSeventeenStr[20][64])
VAR(CHAR, InfoListEighteenStr[20][64])
VAR(CHAR, InfoListNineteenStr[20][64])
VAR(CHAR, InfoListTwentyStr[20][64])

//Info text
VAR(CHAR, PlayerInfoText1[1000])
VAR(CHAR, PlayerInfoText2[1000])
VAR(CHAR, PlayerInfoText3[1000])
VAR(CHAR, PlayerInfoText4[1000])
VAR(CHAR, PlayerInfoText5[1000])
VAR(CHAR, PlayerInfoText6[1000])
VAR(CHAR, PlayerInfoText7[1000])
VAR(CHAR, PlayerInfoText8[1000])
VAR(CHAR, PlayerInfoText9[1000])
VAR(CHAR, PlayerInfoText10[1000])
VAR(CHAR, PlayerInfoText11[1000])
VAR(CHAR, PlayerInfoText12[1000])
VAR(CHAR, PlayerInfoText13[1000])
VAR(CHAR, PlayerInfoText14[1000])
VAR(CHAR, PlayerInfoText15[1000])
VAR(CHAR, PlayerInfoText16[1000])
VAR(CHAR, PlayerInfoText17[1000])
VAR(CHAR, PlayerInfoText18[1000])
VAR(CHAR, PlayerInfoText19[1000])
VAR(CHAR, PlayerInfoText20[1000])
VAR(CHAR, PlayerInfoText21[1000])

//Info misc
VAR(CHAR, CounterMainStr[64])
VAR(CHAR, CounterCloseStr[64])
VAR(CHAR, CounterBackStr[64])
VAR(CHAR, CounterNextStr[64])
VAR(CHAR, CounterKilledStr[64])
VAR(CHAR, CounterUnknownStr[64])
VAR(CHAR, CounterBarKilledStr[64])

//Menu misc
VAR(CHAR, MenuStr[64])
VAR(INT, MenuStrContextX)
VAR(INT, MenuStrContextY)
VAR(INT, MenuStrRectX)
VAR(INT, MenuStrRectY)
VAR(INT, MenuStrRectWidth)
VAR(INT, MenuStrRectHeight)

VAR(CHAR, MenuStrStat[64])
VAR(CHAR, MenuStrInfo[64])
VAR(CHAR, MenuStrMission[64])
VAR(CHAR, MenuStrAbility[64])
VAR(CHAR, MenuStrGuide[64])
VAR(CHAR, MenuStrCalc[64])
VAR(CHAR, MenuStrSetting[64])

VAR(CHAR, MenuStrSpace[64])

//Stats text
VAR(CHAR, ModStatAttackSpeed[64])
VAR(CHAR, ModStatBlockRate[64])
VAR(CHAR, ModStatCastRate[64])
VAR(CHAR, ModStatHitRecovery[64])
VAR(CHAR, ModStatRunWalkSpeed[64])
VAR(CHAR, ModStatVelocity[64])
VAR(CHAR, ModStatReplenishLife[64])
VAR(CHAR, ModStatRegenerateMana[64])
VAR(CHAR, ModStatDamageTakenGoesToMana[64])
VAR(CHAR, ModStatCurrencyFind[64])
VAR(CHAR, ModStatMagicFind[64])
VAR(CHAR, ModStatFireResist[64])
VAR(CHAR, ModStatColdResist[64])
VAR(CHAR, ModStatLightningResist[64])
VAR(CHAR, ModStatPoisonResist[64])
VAR(CHAR, ModStatPhysicalResist[64])
VAR(CHAR, ModStatMagicResist[64])
VAR(CHAR, ModStatMaximumFireResist[64])
VAR(CHAR, ModStatMaximumColdResist[64])
VAR(CHAR, ModStatMaximumLightningResist[64])
VAR(CHAR, ModStatMaximumPoisonResist[64])
VAR(CHAR, ModStatDamageReduction[64])
VAR(CHAR, ModStatMagicDamageReduction[64])
VAR(CHAR, ModStatFireAbsorb[64])
VAR(CHAR, ModStatColdAbsorb[64])
VAR(CHAR, ModStatLightningAbsorb[64])
VAR(CHAR, ModStatMagicAbsorb[64])
VAR(CHAR, ModStatCrushingBlow[64])
VAR(CHAR, ModStatDeadlyStrike[64])
VAR(CHAR, ModStatOpenWounds[64])
VAR(CHAR, ModStatLifeStolenPerHit[64])
VAR(CHAR, ModStatManaStolenPerHit[64])
VAR(CHAR, ModStatReduceVendorPrice[64])

//Side Quest list
VAR(CHAR, SideQuestListStrL1[64])
VAR(CHAR, SideQuestListStrL2[64])
VAR(CHAR, SideQuestListStrL3[64])
VAR(CHAR, SideQuestListStrL4[64])
VAR(CHAR, SideQuestListStrL5[64])
VAR(CHAR, SideQuestListStrL6[64])
VAR(CHAR, SideQuestListStrL7[64])
VAR(CHAR, SideQuestListStrL8[64])
VAR(CHAR, SideQuestListStrL9[64])
VAR(CHAR, SideQuestListStrL10[64])
VAR(CHAR, SideQuestListStrL11[64])
VAR(CHAR, SideQuestListStrL12[64])
VAR(CHAR, SideQuestListStrL13[64])
VAR(CHAR, SideQuestListStrL14[64])
VAR(CHAR, SideQuestListStrL15[64])
VAR(CHAR, SideQuestListStrL16[64])
VAR(CHAR, SideQuestListStrL17[64])
VAR(CHAR, SideQuestListStrL18[64])
VAR(CHAR, SideQuestListStrL19[64])
VAR(CHAR, SideQuestListStrL20[64])

VAR(INT, SideQuestLevel[21])

VAR(CHAR, QuestUnavailableStr[64])

//Side Quest tag
VAR(CHAR, SideQuestTagExpansion1[64])
VAR(CHAR, SideQuestTagExpansion2[64])
VAR(CHAR, SideQuestTagExpansion3[64])
VAR(CHAR, SideQuestTagExpansion4[64])
VAR(CHAR, SideQuestTagExpansion5[64])
VAR(CHAR, SideQuestTagExpansion6[64])
VAR(CHAR, SideQuestTagExpansion7[64])
VAR(CHAR, SideQuestTagExpansion8[64])
VAR(CHAR, SideQuestTagExpansion9[64])
VAR(CHAR, SideQuestTagExpansion10[64])
VAR(CHAR, SideQuestTagExpansion11[64])
VAR(CHAR, SideQuestTagExpansion12[64])
VAR(CHAR, SideQuestTagExpansion13[64])
VAR(CHAR, SideQuestTagExpansion14[64])
VAR(CHAR, SideQuestTagExpansion15[64])
VAR(CHAR, SideQuestTagExpansion16[64])
VAR(CHAR, SideQuestTagExpansion17[64])
VAR(CHAR, SideQuestTagExpansion18[64])
VAR(CHAR, SideQuestTagExpansion19[64])
VAR(CHAR, SideQuestTagExpansion20[64])

//Side Quest title
VAR(CHAR, SideQuestTitleExpansion1[64])
VAR(CHAR, SideQuestTitleExpansion2[64])
VAR(CHAR, SideQuestTitleExpansion3[64])
VAR(CHAR, SideQuestTitleExpansion4[64])
VAR(CHAR, SideQuestTitleExpansion5[64])
VAR(CHAR, SideQuestTitleExpansion6[64])
VAR(CHAR, SideQuestTitleExpansion7[64])
VAR(CHAR, SideQuestTitleExpansion8[64])
VAR(CHAR, SideQuestTitleExpansion9[64])
VAR(CHAR, SideQuestTitleExpansion10[64])
VAR(CHAR, SideQuestTitleExpansion11[64])
VAR(CHAR, SideQuestTitleExpansion12[64])
VAR(CHAR, SideQuestTitleExpansion13[64])
VAR(CHAR, SideQuestTitleExpansion14[64])
VAR(CHAR, SideQuestTitleExpansion15[64])
VAR(CHAR, SideQuestTitleExpansion16[64])
VAR(CHAR, SideQuestTitleExpansion17[64])
VAR(CHAR, SideQuestTitleExpansion18[64])
VAR(CHAR, SideQuestTitleExpansion19[64])
VAR(CHAR, SideQuestTitleExpansion20[64])

//Side Quest misc
VAR(CHAR, SideQuestStrMain[64])
VAR(CHAR, SideQuestStrBack[64])
VAR(CHAR, SideQuestStrNext[64])
VAR(CHAR, SideQuestStrClose[64])

//Key items
VAR(CHAR, KeyItemStrMain[64])
VAR(CHAR, KeyItemStrBack[64])
VAR(CHAR, KeyItemStrNext[64])
VAR(CHAR, KeyItemStrClose[64])
VAR(CHAR, KeyItemStrOn[64])
VAR(CHAR, KeyItemStrOff[64])

VAR(CHAR, KeyItemStrExp1[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp2[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp3[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp4[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp5[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp6[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp7[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp8[MAXKEYITEMS][64])
VAR(CHAR, KeyItemStrExp9[MAXKEYITEMS][64])

VAR(INT, HaveKeyItemExp1[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp2[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp3[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp4[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp5[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp6[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp7[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp8[MAXKEYITEMS])
VAR(INT, HaveKeyItemExp9[MAXKEYITEMS])

VAR(BOOL, ToggleKeyItem[MAXKEYITEMS][9])

//Ladder
VAR(CHAR, LadderName[MAXLADDER][16])
VAR(INT, LadderID[MAXLADDER])
VAR(INT, LadderLevel[MAXLADDER])
VAR(INT, LadderRank[MAXLADDER])
VAR(INT, LadderClass[MAXLADDER])
VAR(INT64, LadderExp[MAXLADDER])
VAR(CHAR, LadderNote[MAXLADDER][64])

VAR(CHAR, UpdLadderName[MAXLADDER][16])
VAR(INT, UpdLadderID[MAXLADDER])
VAR(INT, UpdLadderLevel[MAXLADDER])
VAR(INT, UpdLadderRank[MAXLADDER])
VAR(INT, UpdLadderClass[MAXLADDER])
VAR(INT64, UpdLadderExp[MAXLADDER])
VAR(CHAR, UpdLadderNote[MAXLADDER][64])

VAR(INT64, TempLadderExp[MAXLADDER])
VAR(CHAR, TempLadderNote[64])

VAR(INT, LastLadderID)

VAR(CHAR, MyLadderName[16])
VAR(INT, MyLadderID)
VAR(INT, MyLadderLevel)
VAR(INT, MyLadderRank)
VAR(INT, MyLadderClass)
VAR(INT64, MyLadderExp)
VAR(INT, MyLadderStatus)
VAR(CHAR, MyLadderNote[64])

VAR(CHAR, LadderClassAbrv[MAXCLASSES + 8][16])

VAR(INT, ShowLadderPage)

VAR(BOOL, BusyUpdData)

VAR(BOOL, LadderDeath)

VAR(DWORD, FLAG) //Class flag for ladder
VAR(DWORD, ClassFlag)

VAR(BOOL, ResetLadderNote)

VAR(BOOL, QueueLadderReset)
VAR(BOOL, QueueLadderSave)
VAR(BOOL, QueueLadderSetNote)
VAR(BOOL, QueueLadderDeleteNote)

VAR(CHAR, LadderNameStart[MAXLADDER][16])
VAR(INT, LadderIDStart[MAXLADDER])
VAR(INT, LadderLevelStart[MAXLADDER])
VAR(INT, LadderRankStart[MAXLADDER])
VAR(INT, LadderClassStart[MAXLADDER])
VAR(INT64, LadderExpStart[MAXLADDER])
VAR(CHAR, LadderNoteStart[MAXLADDER][64])

//Loading
VAR(BOOL, LoadingNotice)
VAR(BOOL, DisableInput)

//Version
VAR(BOOL, VersionNotice)

VAR(INT, VerInfoStr1X)
VAR(INT, VerInfoStr1Y)
VAR(INT, VerInfoStr2X)
VAR(INT, VerInfoStr2Y)

//Side Quests vars
VAR(BOOL, SideQuestMenu)
VAR(INT, SideQuestTextPages)
VAR(INT, SideQuestListPages)
VAR(INT, SideQuestExpansion)
VAR(INT, SideQuestSelected)
VAR(BOOL, SideQuestBack)
VAR(BOOL, SideQuestNext)
VAR(BOOL, SideQuestBackText)
VAR(BOOL, SideQuestNextText)
VAR(INT, QuestStrContextX)
VAR(INT, QuestStrContextY)
VAR(INT, QuestStrRectX)
VAR(INT, QuestStrRectY)
VAR(INT, QuestStrRectWidth)
VAR(INT, QuestStrRectHeight)
VAR(INT, QuestStrMouseOverX1)
VAR(INT, QuestStrMouseOverY1)
VAR(INT, QuestButtonWidth)
VAR(INT, QuestButtonHeight)

VAR(BOOL, KeyItemMenu)
VAR(INT, KeyItemTextPages)
VAR(INT, KeyItemListPages)
VAR(INT, KeyItemExpansion)
VAR(INT, KeyItemSelected)
VAR(BOOL, KeyItemOffText)
VAR(BOOL, KeyItemOnText)
VAR(BOOL, KeyItemBack)
VAR(BOOL, KeyItemNext)
VAR(BOOL, KeyItemOn)
VAR(BOOL, KeyItemOff)

//Counter vars
VAR(BOOL, PlayerInfoMenu)
VAR(BOOL, PlayerInfoBack)
VAR(BOOL, PlayerInfoNext)
VAR(BOOL, PlayerInfoBackText)
VAR(BOOL, PlayerInfoNextText)
VAR(INT, PlayerInfoGroup)
VAR(INT, PlayerInfoListPages)
VAR(INT, PlayerInfoSelected)
VAR(INT, PlayerInfoTextPages)
VAR(INT, MainStrContextX)
VAR(INT, MainStrContextY)
VAR(INT, MainStrRectX)
VAR(INT, MainStrRectY)
VAR(INT, MainStrRectWidth)
VAR(INT, MainStrRectHeight)
VAR(INT, MainStrMouseOverX1)
VAR(INT, MainStrMouseOverY1)
VAR(INT, MainButtonWidth)
VAR(INT, MainButtonHeight)
VAR(INT, CounterPosition)

VAR(CHAR, CharacterName[16])

VAR(CHAR, GameNormStr[64])
VAR(CHAR, GameNmStr[64])
VAR(CHAR, GameHellStr[64])

VAR(INT, Difficulty)
VAR(INT, Rank)
VAR(INT, Games0)
VAR(INT, Games1)
VAR(INT, Games2)
VAR(BOOL, GameWon)
VAR(BOOL, GameDraw)
VAR(BOOL, GameLost)
VAR(INT, GamesWon)
VAR(INT, GamesDraw)
VAR(INT, GamesLost)
VAR(CHAR, RankStr[64])
VAR(CHAR, GameWonStr[64])
VAR(CHAR, GameDrawStr[64])
VAR(CHAR, GameLostStr[64])

VAR(INT, TimesKilled)
VAR(CHAR, TimesKilledStr[64])

VAR(INT, HealthUsed)
VAR(INT, ManaUsed)
VAR(INT, PortalsTaken)

VAR(INT, TimesHealed)
VAR(BOOL, MinusHealth)
VAR(BOOL, BoHealth)

VAR(INT, WaypointUsed)
VAR(INT, ChangedArea)
VAR(INT, ShrineUsed)
VAR(BOOL, UsedWaypoint)
VAR(BOOL, UsedHealth)
VAR(BOOL, UsedMana)
VAR(BOOL, UsedPortal)
VAR(BOOL, UsedShrine)

VAR(INT, DistanceThis)
VAR(INT, TravelDistanceN)
VAR(INT, TravelDistanceS)
VAR(INT, TravelDistanceE)
VAR(INT, TravelDistanceW)
VAR(INT, TravelDistanceMile)
VAR(INT, TravelDistanceYard)
VAR(CHAR, TravelDistanceStr[64])
VAR(CHAR, TravelYardStr[64])
VAR(CHAR, TravelMileStr[64])
VAR(BOOL, AntiIdle)

VAR(INT, GoldFoundLast)
VAR(INT, GoldFoundThis)
VAR(CHAR, TotalGoldStr[64])
VAR(CHAR, GoldThousandStr[64])
VAR(CHAR, GoldMillionStr[64])
VAR(CHAR, GoldBillionStr[64])
VAR(CHAR, GoldTrillionStr[64])
VAR(INT, GoldCopper)
VAR(INT, GoldSilver)
VAR(INT, GoldThousand)
VAR(INT, GoldMillion)
VAR(INT, GoldBillion)
VAR(INT, GoldTrillion)

VAR(INT, EquipHead)
VAR(INT, EquipAmulet)
VAR(INT, EquipBody)
VAR(INT, EquipRightW)
VAR(INT, EquipLeftW)
VAR(INT, EquipRightR)
VAR(INT, EquipLeftR)
VAR(INT, EquipBelt)
VAR(INT, EquipFeet)
VAR(INT, EquipGloves)
VAR(INT, EquipRight2W)
VAR(INT, EquipLeft2W)
VAR(CHAR, EquipWeaponStr[64])
VAR(CHAR, EquipArmorStr[64])
VAR(CHAR, EquipMiscStr[64])

VAR(BOOL, NewCharacter)

VAR(CHAR, HealthUsedStr[64])
VAR(CHAR, ManaUsedStr[64])
VAR(CHAR, PortalsTakenStr[64])
VAR(CHAR, WaypointUsedStr[64])
VAR(CHAR, ChangedAreaStr[64])
VAR(CHAR, ShrineUsedStr[64])
VAR(CHAR, TimesHealedStr[64])

VAR(INT, MonsterUnit[3][MAXMONSTERS])
VAR(CHAR, MonsterStr[MAXMONSTERS][64])
VAR(DWORD, IgnoreList[MAXIGNORE])
VAR(BOOL, IgnoreTarget)

VAR(BOOL, COUNTED)

VAR(INT, MonsterUnitStart[3][MAXMONSTERS])

//Timeclock
VAR(CHAR, ClockStr[64])
VAR(CHAR, DobStr[64])
VAR(CHAR, LastStr[64])
VAR(CHAR, ClockMillisecondsStr[64])
VAR(CHAR, ClockSecondsStr[64])
VAR(CHAR, ClockMinutesStr[64])
VAR(CHAR, ClockHoursStr[64])

VAR(CHAR, BestAndyStr[64])
VAR(CHAR, BestDurielStr[64])
VAR(CHAR, BestMephStr[64])
VAR(CHAR, BestDiabloStr[64])
VAR(CHAR, BestBaalStr[64])

VAR(CHAR, BestAndyNMStr[64])
VAR(CHAR, BestDurielNMStr[64])
VAR(CHAR, BestMephNMStr[64])
VAR(CHAR, BestDiabloNMStr[64])
VAR(CHAR, BestBaalNMStr[64])

VAR(CHAR, BestAndyHellStr[64])
VAR(CHAR, BestDurielHellStr[64])
VAR(CHAR, BestMephHellStr[64])
VAR(CHAR, BestDiabloHellStr[64])
VAR(CHAR, BestBaalHellStr[64])

VAR(CHAR, LadderRankStr[64])
VAR(CHAR, LadderClassStr[64])
VAR(CHAR, LadderNameStr[64])
VAR(CHAR, LadderExpStr[64])
VAR(CHAR, LadderLevelStr[64])
VAR(CHAR, LadderSoftStr[64])
VAR(CHAR, LadderHardStr[64])
VAR(CHAR, LadderLodStr[64])
VAR(CHAR, LadderNoteStr[64])

VAR(INT, ClockMilliseconds)
VAR(INT, ClockSeconds)
VAR(INT, ClockMinutes)
VAR(INT, ClockHours)

VAR(INT, ClockDoBYear)
VAR(INT, ClockDoBMonth)
VAR(INT, ClockDoBDay)
VAR(INT, ClockDoBHour)
VAR(INT, ClockDoBMinute)
VAR(INT, ClockDoBSecond)

VAR(INT, ClockLastYear)
VAR(INT, ClockLastMonth)
VAR(INT, ClockLastDay)
VAR(INT, ClockLastHour)
VAR(INT, ClockLastMinute)
VAR(INT, ClockLastSecond)

VAR(INT, BestAndyHour)
VAR(INT, BestAndyMin)
VAR(INT, BestAndySec)
VAR(INT, BestDurielHour)
VAR(INT, BestDurielMin)
VAR(INT, BestDurielSec)
VAR(INT, BestMephHour)
VAR(INT, BestMephMin)
VAR(INT, BestMephSec)
VAR(INT, BestDiabloHour)
VAR(INT, BestDiabloMin)
VAR(INT, BestDiabloSec)
VAR(INT, BestBaalHour)
VAR(INT, BestBaalMin)
VAR(INT, BestBaalSec)

VAR(INT, BestAndyNMHour)
VAR(INT, BestAndyNMMin)
VAR(INT, BestAndyNMSec)
VAR(INT, BestDurielNMHour)
VAR(INT, BestDurielNMMin)
VAR(INT, BestDurielNMSec)
VAR(INT, BestMephNMHour)
VAR(INT, BestMephNMMin)
VAR(INT, BestMephNMSec)
VAR(INT, BestDiabloNMHour)
VAR(INT, BestDiabloNMMin)
VAR(INT, BestDiabloNMSec)
VAR(INT, BestBaalNMHour)
VAR(INT, BestBaalNMMin)
VAR(INT, BestBaalNMSec)

VAR(INT, BestAndyHellHour)
VAR(INT, BestAndyHellMin)
VAR(INT, BestAndyHellSec)
VAR(INT, BestDurielHellHour)
VAR(INT, BestDurielHellMin)
VAR(INT, BestDurielHellSec)
VAR(INT, BestMephHellHour)
VAR(INT, BestMephHellMin)
VAR(INT, BestMephHellSec)
VAR(INT, BestDiabloHellHour)
VAR(INT, BestDiabloHellMin)
VAR(INT, BestDiabloHellSec)
VAR(INT, BestBaalHellHour)
VAR(INT, BestBaalHellMin)
VAR(INT, BestBaalHellSec)

VAR(BOOL, NormalWon)
VAR(BOOL, NMWon)
VAR(BOOL, HellWon)

//DPMS
VAR(DWORD, DamageUnitId[1000])
VAR(INT, DamageUnitLife[1000])
VAR(INT, DamageUnitLife2[1000])
VAR(INT, DamageUnitLife3[1000])
VAR(INT, DamageUnitLife4[1000])
VAR(INT, DamageUnitLife5[1000])
VAR(INT, DamageUnitLife6[1000])
VAR(INT, DamageUnitLife7[1000])
VAR(INT, DamageUnitLife8[1000])

VAR(DWORD, DisplayDamageAmount[1000])
VAR(DWORD, DisplayDamageTimer[1000])
VAR(DWORD, DisplayDamagePosX[1000])
VAR(DWORD, DisplayDamagePosY[1000])
VAR(DWORD, DisplayDamageConf[1000])

VAR(INT, MonsterHPMinNorm[1000])
VAR(INT, MonsterHPMaxNorm[1000])
VAR(INT, MonsterHPMinNm[1000])
VAR(INT, MonsterHPMaxNm[1000])
VAR(INT, MonsterHPMinHell[1000])
VAR(INT, MonsterHPMaxHell[1000])

//Classes
VAR(INT, Class[MAXCLASSES])
VAR(CHAR, ClassStr[MAXCLASSES + 8][64])

//Data
VAR(INT, LoadTest)
VAR(INT, LoadUpdate)

VAR(INT, TestUpdate4)

//Side Quests/Mission
VAR(string, FilePath)
VAR(string, FilePathB)
VAR(string, FilePathC)

VAR(string, SideQuestTagExpansion)
VAR(string, SideQuestTagPage)
VAR(string, SideQuestTagQuest)

VAR(string, KeyItemTagExpansion)
VAR(string, KeyItemTagPage)
VAR(string, KeyItemTagItem)

//Player Info
VAR(string, DoBTimeOfDay)
VAR(string, LastTimeOfDay)

VAR(string, PlayerInfoTextStrR1)
VAR(string, PlayerInfoTextStrR2)
VAR(string, PlayerInfoTextStrR3)
VAR(string, PlayerInfoTextStrR4)
VAR(string, PlayerInfoTextStrR5)
VAR(string, PlayerInfoTextStrR6)
VAR(string, PlayerInfoTextStrR7)
VAR(string, PlayerInfoTextStrR8)
VAR(string, PlayerInfoTextStrR9)
VAR(string, PlayerInfoTextStrR10)
VAR(string, PlayerInfoTextStrR11)
VAR(string, PlayerInfoTextStrR12)
VAR(string, PlayerInfoTextStrR13)
VAR(string, PlayerInfoTextStrR14)
VAR(string, PlayerInfoTextStrR15)
VAR(string, PlayerInfoTextStrR16)
VAR(string, PlayerInfoTextStrR17)
VAR(string, PlayerInfoTextStrR18)
VAR(string, PlayerInfoTextStrR19)
VAR(string, PlayerInfoTextStrR20)
VAR(string, PlayerInfoTextStrR21)

//AIBot
//Dupe
VAR(LPUNITANY, A5Gate)

VAR(BYTE, OpenGate[17])

VAR(BOOL, Block0x30)
VAR(BOOL, DupeComplete)

//Travel
VAR(LPUNITANY, ActiveWP)
VAR(DWORD, ActiveArea)
VAR(INT, A5WaypointID)

VAR(BOOL, TP2)
VAR(DWORD, LevelX)
VAR(DWORD, LevelY)
VAR(BOOL, BusyThread)
VAR(BOOL, WalkingActive)
VAR(BOOL, FarcastTeleportMemory)
VAR(WORD, Portalspot[2])

VAR(INT, Direction)

VAR(BOOL, EnableTeleport)

//Monsterlifebar
VAR(INT, MLBPosX)
VAR(INT, MLBPosY)
VAR(INT, MLBDifficulty)
VAR(INT, MLBMonsterID)

//Godmode
VAR(BYTE, Heal[13])
VAR(BYTE, BuyHeal[5])

VAR(BOOL, CSet)
VAR(BOOL, PCopied)
VAR(BOOL, ICopied)
VAR(BOOL, GMStart)
VAR(BOOL, NPCCopied)
VAR(BOOL, GMOn)

//Mpq
VAR(void*, MPQHandleData)
VAR(void*, MPQHandleMusic)

//PlugY
VAR(INT, ActiveMultiPageStash)
VAR(INT, ActiveSharedStash)

VAR(INT, NBPlayersByDefault)

VAR(INT, MultiPlayerMode)

//Xinput
VAR(BOOL, QueueVibrate)
VAR(BOOL, QueueVibrateSoft)

//Registration
VAR(INT, CDKey[NUMOFKEYS])

VAR(INT, Key)
VAR(INT, ToR)
VAR(INT, IDEntry)
VAR(INT, KeyReturn)
VAR(INT, KeyEntry)
VAR(BOOL, Validated)
VAR(BOOL, Registered)

VAR(INT, RegistryNotice)

VAR(CHAR, ClientVersion[16])

//Administrator
VAR(BOOL, LegitMode)
VAR(BOOL, GMMode)
VAR(CHAR, GMName[16])
VAR(BOOL, MonstersMap)
VAR(BOOL, VectorsMap)
VAR(BOOL, MonstersMapExt)

VAR(BOOL, InTownTemp)

VAR(BOOL, MenuNotice)

#undef VARS

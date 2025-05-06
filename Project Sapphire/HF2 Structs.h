#ifndef D2STRUCTS_H__
#define D2STRUCTS_H__

#include "HF2 Data Tables.h"
struct exUnitAny;
struct exClientInfo;
struct exPlayerData;
struct exItemData;
struct exMonsterData;
struct exObjectData;
struct exAct;
struct exAutoMapLayer;
struct exActMisc;
struct exPath;
struct exStatList;
struct exInventory;
struct exLight;
struct exInfo;
struct exSkill;
struct exDamage;
struct exGame;
struct exClientData;
struct exWaypoint;
struct exQuestInfo;
struct exRoom1;
struct exRoom2;
struct exRoomTile;
struct exLevel;
struct exPresetUnit;
struct exObjectTxt;
struct exControl;
struct exEditBox;
struct exImage;
struct exAnimImage;
struct exTextBox;
struct exScrollBar;
struct exButton;
struct exList;
struct exArena;
struct expMsg;
struct exQuestFlags;
struct exCollMap;
struct exCellContext;

struct exD2Seed;
struct exCellFile;
struct exGfxCell;

struct exD2Seed
{
	DWORD nLowSeed;
	DWORD nHiSeed;
};

struct exCellFile // *.dc6
{
	DWORD dwVersion;				//0x00
	struct {
		WORD dwFlags; // 0x4 = CELFILE_24BIT
		BYTE mylastcol;
		BYTE mytabno : 1;
	};								//0x04
	DWORD eFormat;					//0x08
	DWORD termination;				//0x0C
	DWORD numdirs;					//0x10
	DWORD numcells;					//0x14
	exGfxCell *cells[255];			//0x18
};

struct exHoverText	//size 0x110
{
	DWORD dwDisplayTime;	//0x00	8 * strlen + 125
	DWORD dwExpireTime;		//0x04	DisplayTime+CurrentTick;
	DWORD dwLangId;			//0x08
	DWORD _1;				//0x0C	Unused?
	char szMsg[255];		//0x10
};

struct exChatMsg		//size 0x2C
{
	wchar_t* wMsg;			//0x00
	void* _1;				//0x04
	//...
};

struct exInventory
{
	DWORD dwSignature;				//0x00
	BYTE* pMemPool;					//0x04
	exUnitAny* pOwner;				//0x08
	exUnitAny* pFirstItem;			//0x0C
	exUnitAny* pLastItem;				//0x10
	DWORD _1[2];					//0x14
	DWORD dwLeftItemUid;			//0x1C
	exUnitAny* pCursorItem;			//0x20
	DWORD dwOwnerId;				//0x24
	DWORD dwItemCount;				//0x28
	DWORD _2[4];					//0x2C
	DWORD CorpseNumber;				//0x3C
};

struct exItemData {
	DWORD QualityNo;		//0x00
	DWORD LowSeed;			//0x04
	DWORD HighSeed;			//0x08
	DWORD OwnerID;			//0x0C
	DWORD InitSeed;			//0x10
	DWORD CommandFlags;		//0x14
	DWORD ItemFlags;		//0x18
	DWORD _1[2];			//0x1C
	DWORD ActionStamp;		//0x24
	DWORD FileIndex;		//0x28
	DWORD ItemLevel;		//0x2C
	WORD ItemFormat;		//0x30
	WORD RarePrefix;		//0x32
	WORD RareSutfix;		//0x34
	WORD AutoPrefix;		//0x36
	WORD MagicPrefix[3];	//0x38
	WORD MagicSutfix[3];	//0x3E
	BYTE BodyLoc;		    //0x44					// location on body = xpos of item (only if on body) (spread)
	BYTE InvPage;			//0x45					// 0 = inventory,  3= cube, 4=stash (spread)
	BYTE _2[2];				//0x46
	BYTE EarLvl;			//0x48
	BYTE InvGfxIdx;			//0x49
	char szPlayerName[16];	//0x4A
	BYTE _3[2];				//0x5A
	exInventory *pNodeInv;	//0x5C
	DWORD _4;				//0x60
	exUnitAny* pNextItem;		//0x64
	BYTE NodePos;			//0x68
	BYTE NodePosOther;		//0x69
};

struct exActEnvironment // sizeof(0x38)
{
	DWORD _1;						//0x00  2
	DWORD _2;						//0x04  0
	DWORD _3;						//0x08  0 * 128
	DWORD _4;						//0x0C  32
	DWORD dwCreatedTick;			//0x10
	DWORD _6;						//0x14
	DWORD _7;						//0x18  Some angle (sin( (_3 / _11)  * (1/180) * PI)
	DWORD _8;						//0x1C  Some angle (-cos( (_3 / _11) * (1/180) * PI)
	DWORD _9;						//0x20
	DWORD _10;						//0x24
	DWORD _11;						//0x28  128
	DWORD _12;						//0x2C
	DWORD _13;						//0x30
	DWORD _14;						//0x34
};

//sizeof = 0x60
struct exAct
{
	DWORD _1a;						//0x00
	exActEnvironment* pEnviroment;	//0x04
	DWORD dwTownLvl;				//0x08
	DWORD dwMapSeed;				//0x0C
	exRoom1* pRoom1;					//0x10
	DWORD dwAct;					//0x14
	DWORD hTile[12];				//0x18 not sure, some inline struct of 0x30 size seems fit
	exActMisc* pMisc;					//0x48
	DWORD _4;						//0x4C
	DWORD _5;						//0x50
	DWORD _6;						//0x54
	DWORD _7;						//0x58
	void* pMemPool;					//0x5C
};


// sizeof 0x48
struct exDrlgVis
{
	DWORD nLevelDef;		//0x00 -> record number of LevelDefs.bin
	DWORD dwVis[8];			//0x04
	DWORD dwWarp[8];		//0x24
	exDrlgVis* pNext;			//0x44
};

struct exActMisc // sizeof(0x48C) aka Drlg
{
	exD2Seed hSeed;			//0x00
	DWORD _1;				//0x08
	DWORD* pTile;			//0x0C
	DWORD _1g[15];			//0x10
	DWORD pfnCallBack;		//0x4c
	DWORD _1a[16];			//0x50
	exDrlgVis * pVis;			//0x90
	DWORD dwStaffTombLevel; //0x94
	DWORD _2a;				//0x98
	exGame* pGame;			//0x9C
	DWORD _2[236];			//0xA0
	DWORD nDiffLvl;			//0x450
	DWORD* fnCallback;		//0x454
	DWORD InitSeed;			//0x458
	DWORD _2d[4];			//0x45C
	exAct* pAct;				//0x46C
	DWORD _3[2];			//0x470
	void *pMemPool;			//0x478 D2PoolManager*
	exLevel* pLevelFirst;		//0x47C
	DWORD nAct;				//0x480
	DWORD _5;				//0x484 Tomb Levels Related 66 + rand(7)
	DWORD* fnCallback2;		//0x488
};

struct exAutoMapCell
{
	DWORD fSaved;					//0x00
	WORD nCellNo;					//0x04
	WORD xPixel;					//0x06
	WORD yPixel;					//0x08
	WORD wWeight;					//0x0A
	exAutoMapCell* pLess;				//0x0C
	exAutoMapCell* pMore;				//0x10
};

struct exAutoMapLayer //sizeof = 0x1C
{
	DWORD nLayerNo;					//0x00
	DWORD fSaved;					//0x04
	exAutoMapCell* pFloors;			//0x08
	exAutoMapCell* pWalls;			//0x0C
	exAutoMapCell* pObjects;			//0x10
	exAutoMapCell* pExtras;			//0x14
	exAutoMapLayer* pNextLayer;		//0x18
};

struct exAutoMapLayer2
{
	DWORD _1[2];					//0x00
	DWORD nLayerNo;					//0x08
};

struct exPresetUnit {
	DWORD _1;						//0x00
	DWORD dwClassId;				//0x04
	DWORD dwPosX;					//0x08
	exPresetUnit* pPresetNext;		//0x0C
	DWORD _3;						//0x10
	DWORD dwType;					//0x14
	DWORD dwPosY;					//0x18
};


struct exRoomCoords // sizeof(0x20) 32 bytes of exRoom1+4C
{
	DWORD dwXStart;					//0x00
	DWORD dwYStart;					//0x04
	DWORD dwXSize;					//0x08
	DWORD dwYSize;					//0x0C
	WORD wTileX;					//0x10
	WORD _1b;						//0x12
	WORD wTileY;					//0x14
	WORD _2b;						//0x16
	DWORD _3;						//0x18
	DWORD _4;						//0x1C
};


struct exRoom1 {
	exRoom1** pRoomsNear; 	//0x00 pptVisibleRooms
	DWORD _1;				//0x04
	void *_1s;				//0x08
	DWORD _1b;				//0x0C
	exRoom2* pRoom2;			//0x10
	DWORD _2[2];			//0x14
	exUnitAny **pUnitChanged; //0x1C
	exCollMap* Coll;			//0x20
	DWORD dwRoomsNear;		//0x24 dwVisibleRooms
	DWORD nPlayerUnits;		//0x28
	exAct *pAct;				//0x2C
	DWORD _4;				//0x30
	DWORD nUnknown;			//0x34
	DWORD _5[4];			//0x38
	exClientData **pClients;  //0x48
	exRoomCoords hCoords;		//0x4C
	exD2Seed hSeed;			//0x6C
	exUnitAny *pUnitFirst;	//0x74
	DWORD nNumClients;		//0x78
	exRoom1 *pRoomNext;		//0x7C
};

struct exRoom2 {
	DWORD _1[2];			//0x00
	exRoom2** pRoom2Near;		//0x08
	DWORD _2[2];			//0x0C
	exD2Seed hSeed;			//0x14
	DWORD _2b;				//0x1C
	struct {
		DWORD dwRoomNumber; //0x00
		DWORD* _1;			//0x04
		DWORD* pdwSubNumber;//0x08
	} *pType2Info;			//0x20 <- points to 0x70 struct if dwPresetType == 1, 0xF8 struct if == 2
	exRoom2* pRoom2Next;		//0x24
	DWORD dwRoomFlags;		//0x28
	DWORD dwRoomsNear;		//0x2C
	exRoom1* pRoom1;			//0x30
	DWORD dwPosX;			//0x34
	DWORD dwPosY;			//0x38
	DWORD dwSizeX;			//0x3C
	DWORD dwSizeY;			//0x40
	DWORD _3;				//0x44
	DWORD dwPresetType;		//0x48
	exRoomTile* pRoomTiles;	//0x4C
	DWORD _4[2];			//0x50
	exLevel* pLevel;			//0x58
	exPresetUnit* pPreset;	//0x5C
};

struct exRoomTile {
	exRoom2* pRoom2;				//0x00
	exRoomTile* pNext; 			//0x04
	DWORD _2[2];				//0x08
	DWORD *nNum; 				//0x10
};


//sizeof = 0x8
struct exPresetData
{
	DWORD _1;					//0x00
	DWORD dwPreset;				//0x04 -> randomly selected from Files columun in LvlPrest.txt
};

//sizeof = 0x10
struct exLevelPreset
{
	DWORD dwDef;				//0x00
	DWORD dwFiles;				//0x04 number of presets
	DWORD dwPreset;				//0x08 randomly selected from Files columun in LvlPrest.txt
	exLevelPreset* pNext;			//0x0C
};


// sizeof = 0x38
struct exWildernessUnk
{
	exLevel* pLevel;					//0x00
	DWORD _2;						//0x04
	DWORD dwRooms;					//0x08
	DWORD _4;						//0x0C
	DWORD _5;						//0x10
	DWORD _6;						//0x14
	DWORD dwType;					//0x18 pLvlSub.txt type
	DWORD fnCallback[7];			//0x1C
};


struct exDrlgGrid // size 0x14
{
	DWORD *gridX;			//0x00
	DWORD *gridY;			//0x04 points to memory of (4 * ySize * (xSize + 1)) 
	DWORD dwXSize;			//0x08
	DWORD dwYSize;			//0x0C
	DWORD _5;				//0x10
};

//sizeof = 0x268
struct exWildernessData
{
	DWORD dwFlags;				//0x00
	exDrlgGrid hGrid[4];			//0x08
	DWORD  _12[2];				//0x0C
	DWORD dwSizeX;				// LevelSizeX / 8
	DWORD dwSizeY;				// LevelSizeY / 8
	DWORD  _13[7];				//0x0C
	DWORD _UnkArr[4][30];		//0x80
	DWORD _14;					//0x260
	DWORD _15;					//0x264
};

// sizeof = 0x230
struct exLevel {
	DWORD dwDrlgType;			//0x00 1 - maze, 2 - preset, 3 - wilderness
	DWORD dwLevelFlags;			//0x04
	DWORD _1[2];				//0x08
	exRoom2* pRoom2First;			//0x10
	union {
		exLvlMazeTxt* pMazeTxt;    		//     for dwDrlgType == 1 (RANDOM MAZE)
		exPresetData* pPreset;			//     for dwDrlgType == 2 (PRESET MAP)
		exWildernessData* pWilderness;	//     for dwDrlgType == 3 (RANDOM AREA WITH PRESET SIZE)
	}; // 0x14
	DWORD _2;					//0x18
	DWORD dwPosX;				//0x1C
	DWORD dwPosY;				//0x20
	DWORD dwSizeX;				//0x24
	DWORD dwSizeY;				//0x28
	DWORD _3[96];				//0x2C
	exLevel* pNextLevel;			//0x1AC
	DWORD _4;					//0x1B0
	exActMisc* pMisc;				//0x1B4
	DWORD _5[2];				//0x1B8
	DWORD dwLevelType;			//0x1C0
	exD2Seed hSeed;				//0x1C4
	exLevelPreset* pLevelPresets;	//0x1CC
	DWORD dwLevelNo;			//0x1D0
	DWORD _6[3];				//0x1D4
	union {
		DWORD RoomCenterX[9];
		DWORD WarpX[9];
	};							//0x1E0
	union {
		DWORD RoomCenterY[9];
		DWORD WarpY[9];
	};							//0x204
	DWORD dwRoomEntries;		//0x228
	DWORD _7;					//0x22C
};

struct exPath	//sizeof 0x200
{
	short xOffset;					//0x00
	short xPos;						//0x02
	short yOffset;					//0x04
	short yPos;						//0x06
	DWORD xUnknown;					//0x08  16 * (wInitX - wInitY) <- Mby AutomapX
	DWORD yUnknown;					//0x0C  8 * (wInitX + wInitY + 1) <- Mby AutoampY
	short xTarget;					//0x10
	short yTarget;					//0x12
	DWORD _2[2];					//0x14
	exRoom1 *pRoom1;					//0x1C
	exRoom1 *pRoomUnk;				//0x20
	DWORD _3[3];					//0x24
	exUnitAny *pUnit;					//0x30
	DWORD dwFlags;					//0x34 0x40000 -> PATH_MISSILE_MASK
	DWORD _4;						//0x38
	DWORD dwPathType;				//0x3C
	DWORD dwPrevPathType;			//0x40
	DWORD dwUnitSize;				//0x44
	DWORD _5[2];					//0x48
	DWORD dwCollisionFlag;			//0x50  0x1804 <- bFlying, 0x3401 <- bOpenDoors, 0x3C01 <- Cannot Open Doors, 0x804 <- Ghost, 0x1C09 <- Player
	DWORD _5d;						//0x54
	exUnitAny *pTargetUnit;			//0x58
	DWORD dwTargetType;				//0x5C
	DWORD dwTargetId;				//0x60
	BYTE bDirection;				//0x64
};

struct exStaticPath // size 0x20
{
	exRoom1 *pRoom1;		//0x00
	DWORD xOffset;		//0x04
	DWORD yOffset;		//0x08
	DWORD xPos;			//0x0C
	DWORD yPos;			//0x10
	DWORD _1[2];			//0x14
	DWORD dwFlags;		//0x1C
};


struct exPlayerData { //size 0x16C , copied from serverside, dunno if everything is the same on client
	char szName[16];				//0x00
	exQuestFlags *QuestsFlags[3];		//0x10
	exWaypoint *pNormalWaypoint[3];	//0x1C
	void* ptAiGeneral;				//0x28
	DWORD _1[2];					//0x2C
	WORD* KillCounter;				//0x34 Monster
	DWORD _1b;						//0x38
	DWORD _2[4];					//0x3C 2[2] is merc related
	DWORD dwTradeTick;				//0x4C mby InactivityTime
	DWORD nTradeState;				//0x50
	DWORD _3;						//0x54
	DWORD dwAcceptTradeTick;		//0x58
	void* pTrade;					//0x5C
	DWORD _4[3];					//0x60
	DWORD dwBoughtItemId;			//0x6C
	DWORD dwRightSkill;				//0x70
	DWORD dwLeftSkill;				//0x74
	DWORD dwRightSkillFlags;		//0x78
	DWORD dwLeftSkillFlags;			//0x7C
	DWORD dwSwitchRightSkill;		//0x80
	DWORD dwSwitchLeftSkill;		//0x84
	DWORD dwSwitchRightSkillFlags;	//0x88
	DWORD dwSwitchLeftSkillFlags;	//0x8C
	DWORD _5[3];					//0x90
	exClientData* pClientData;		//0x9C
	DWORD _6[50];					//0x100
	DWORD GameFrame;				//0x168
};

struct exObjectData
{
	exObjectTxt* pObjectTxt;				//0x00
	BYTE InteractType;				//0x04
	BYTE _1[3];						//0x05
	DWORD _2[8];					//0x08
	char szOwner[16];				//0x28
};

struct exAiGeneral
{
	DWORD SpecialState;										  //0x00 - stuff like terror, confusion goes here
	void* (__fastcall * fpAiFunction)(exGame*, exUnitAny*, DWORD*);  //0x04 - the primary ai function to call
	DWORD AiFlags;											  //0x08
	DWORD OwnerGUID;											  //0x0C- the global unique identifier of the boss or minion owner
	DWORD eOwnerType;											  //0x10 - the unit type of the boss or minion owner
	DWORD dwArgs[3];											  //0x14 - three dwords holding custom data used by ai func to store counters (etc)
	DWORD* pCmdCurrent;										  //0x20
	DWORD *pCmdLast;											  //0x24
	exGame* pGame;												  //0x28
	DWORD OwnerGuideq;										  //0x2C - the same as +008
	DWORD eOwnerTypeEq;										  //0x30 - the same as +00C
	DWORD* pMinionList;										  //0x34 - list of all minions, for boss units (SetBoss in MonStats, Unique, SuperUnique etc)
	DWORD _1;													  //0x38
	DWORD eTrapNo;											  //0x3C - used by shadows for summoning traps (so they stick to one type usually)
};

struct exMonsterData {
	exMonStatsTxt* pMonStatsTxt;				//0x00
	BYTE Components[16];					//0x04
	WORD NameSeed;							//0x14
	struct
	{
		BYTE fOther : 1;
		BYTE fSuperUniq : 1;
		BYTE fChampion : 1;
		BYTE fUnique : 1;
		BYTE fMinion : 1;
		BYTE fPossesed : 1;
		BYTE fGhostly : 1;
		BYTE fMultishot : 1;
	};				//0x16
	BYTE dwLastMode;				//0x17
	DWORD dwDuriel;					//0x18
	BYTE anEnchants[9];				//0x1C
	BYTE _1;						//0x25
	WORD wUniqueNo;					//0x26
	exAiGeneral* pAiGeneral;			//0x28
	wchar_t* wName[28];				//0x2C
};


struct exStat // size 0x8
{
	WORD wSubIndex;					//0x00
	WORD wStatIndex;				//0x02
	DWORD dwStatValue;				//0x04
};

struct exStatEx	//size 0x8
{
	exStat* pStat;					//0x00 An Array[wStatCount]
	WORD wStatCount;				//0x04
	WORD wnBitSize;					//0x06
};

struct exStatListEx  //size 0x64
{
	DWORD pMemPool;					//0x00
	DWORD _1;						//0x04
	DWORD dwOwnerType;				//0x08
	DWORD dwOwnerId;				//0x0C
	DWORD dwListFlags;				//0x10
	DWORD _2[4];					//0x14
	exStatEx BaseStats;				//0x24
	exStatList* pLastList;			//0x2C - pointer to the last pStatList of the exStatListEx owner (aka item owner in case list ex belongs to item)
	DWORD _3;						//0x30
	exStatListEx* pListEx;			//0x34 - pStatListEx - pointer to owner exStatListEx (if this one is owned by a item, this points to the item owners list)
	exStatListEx* pNextListEx;		//0x38
	exStatList *pMyLastList;			//0x3C
	exStatList *pMyStats;				//0x40
	exUnitAny* pOwner;				//0x44
	exStatEx FullStats;				//0x48
	exStatEx ModStats;				//0x50
	BYTE* StatFlags;				//0x58 pt to an  array
	void *fpCallBack;				//0x5C
	exGame* ptGame;					//0x60
};

struct exStatList { //size 0x40
	void* pMemPool;					//0x00
	exUnitAny* pUnit;					//0x04
	DWORD dwOwnerType;				//0x08
	DWORD dwOwnerId;				//0x0C
	DWORD dwFlags;					//0x10
	DWORD dwStateNo;				//0x14
	DWORD ExpireFrame;				//0x18
	DWORD SkillNo;					//0x1C
	DWORD sLvl;						//0x20
	exStatEx Stats;					//0x24
	exStatList *pPrevLink;			//0x2C
	exStatList *pNextLink;			//0x30
	exStatList *pPrev;				//0x34
	void *fpStatRemove;				//0x38
	exStatList *pNext;				//0x3C
};

struct exGfxDrawOffset
{
	DWORD DrawFlags;				//0x00
	DWORD xPos;						//0x04
	DWORD yPos;						//0x08
	DWORD zPos;						//0x0C
	struct
	{
		DWORD xOffset;				//0x00
		DWORD yOffset;				//0x04
		DWORD zOffset;				//0x08
	} Offsets[3];					//0x10
};

struct exGfxInfo
{
	DWORD _1;						//0x00
	DWORD _2;						//0x04
	DWORD _3;						//0x08
	DWORD _4;						//0x0C
	DWORD _5;						//0x10
	DWORD _6;						//0x14
	DWORD _7;						//0x18
	DWORD _8;						//0x1C
	DWORD _9;						//0x20
	DWORD _10;						//0x24
	DWORD _11;						//0x28
	DWORD _12;						//0x2C
	exGfxDrawOffset*  pGfxDrawOffsets;//0x30
	DWORD _13;						//0x34
	DWORD nPalShiftIdx;				//0x38
};

struct exUnitAny  // CLIENT SIDE
{
	DWORD dwType;					//0x00
	DWORD dwClassId;				//0x04
	void* pMemPool;					//0x08
	DWORD dwUnitId;					//0x0C
	DWORD dwMode;					//0x10
	union
	{
		exPlayerData*  pPlayerData;
		exItemData*    pItemData;
		exMonsterData* pMonsterData;
		exObjectData*  pObjectData;
	};								//0x14
	DWORD dwAct;					//0x18
	exAct * pAct;						//0x1C
	DWORD dwSeed[2];				//0x20
	DWORD dwInitSeed;				//0x28
	union
	{
		exPath*       pPath;
		exStaticPath*   pStaticPath;
	};								//0x2C
	DWORD _3[5];					//0x30
	DWORD dwGfxFrame;				//0x44
	DWORD dwFrameRemain;			//0x48
	WORD wFrameRate;				//0x4C
	WORD _4;						//0x4E
	DWORD* pAnimData;				//0x50
	exGfxInfo* pGfxInfo;				//0x54
	exGfxInfo* pGfxInfo2;				//0x58
	exStatListEx*  pStatsEx;			//0x5C
	exInventory* pInventory;			//0x60
	exLight * pLight;					//0x64
	DWORD  dwLightRadious;			//0x68
	WORD   nPalShiftIdx;			//0x6C
	WORD UpdateType;				//0x6E
	exUnitAny *pUpdateUnit;			//0x70
	DWORD *pQuestRecord;			//0x74
	BYTE bSparkyChest;				//0x78
	BYTE _6a[3];					//0x79
	DWORD pTimerArgs;				//0x7C
	DWORD dwSoundSync;				//0x80
	DWORD _7[2];					//0x84
	WORD wX;						//0x8C
	WORD wY;						//0x8E
	DWORD pEvent;					//0x90
	DWORD dwOwnerType;				//0x94
	DWORD dwOwnerId;				//0x98
	DWORD _8[2];					//0x9C
	exHoverText* pHoverText;			//0xA4
	exInfo* pInfo;					//0xA8
	void* ptCombat;					//0xAC
	DWORD dwLastHitClass;			//0xB0
	DWORD _9[4];					//0xB4
	DWORD dwFlags;					//0xC4
	DWORD dwFlags2;					//0xC8
	DWORD _10[5];					//0xCC
	exUnitAny* pChangedNext;			//0xE0
	exUnitAny*  pRoomNext;			//0xE4 // changed 14.12.11
	exUnitAny*  pListNext;			//0xE8
	expMsg* pMsgFirst;				//0xEC
	expMsg* pMsgLast;					//0xF0
};

struct exSkill
{
	exSkillsTxt* pSkillsTxt;			//0x00
	exSkill* pNextSkill;				//0x04
	DWORD SkillMode;				//0x08
	DWORD _1[7];					//0x0C
	DWORD dwSkillLevel;				//0x28
	DWORD _2[2];					//0x2C
	DWORD dwFlags;					//0x30
};

struct exInfo
{
	DWORD* pMemPool;			//0x00
	exSkill* pFirstSkill;			//0x04
	exSkill* pLeftSkill;			//0x08
	exSkill* pRightSkill;			//0x0C
};

#pragma pack(push, 1)
struct exBnetData // sizeof 0x3C8 name of this structure is a big mistake, but I won't change it at this stage...it's more like clientside version of exClientData
{
	DWORD bExpansion;				//0x00
	BYTE bWindowMode;				//0x04
	BYTE bFixAspectRatio;			//0x05
	BYTE b3DFXMode;					//0x06
	BYTE bOpenGLMode;				//0x07
	BYTE bRaveMode;					//0x08
	BYTE bDirect3DMode;				//0x09
	BYTE bUsePerspective;			//0x0A
	BYTE bLowQuality;				//0x0B 
	DWORD dwGamma;					//0x0C
	BYTE bVSync;					//0x10
	DWORD dwFrameRate;				//0x11
	DWORD dwGameType;				//0x15 Values 1, 2 , 3 , 6 , 7
	WORD wJoinId;					//0x19 Overflows on GameName (parameter is an int)
	char szGameName[24];			//0x1B Overflows on GameIP (every string here should've 27 length)
	char szGameIP[24];				//0x33 Overflows -||-
	char szBattleNetIp[24];			//0x4B -||-
	char szMCPIp[24];				//0x63 
	BYTE _8a[4];					//0x7B
	BYTE bNoPK;						//0x7F
	BYTE bOpenC;					//0x80 -openc
	BYTE bAmazon;					//0x81 default is true
	BYTE bPaladin;					//0x82
	BYTE bSorceress;				//0x83
	BYTE bNecormancer;				//0x84
	BYTE bBarbarian;				//0x85
	BYTE _8b;						//0x86
	BYTE _8c;						//0x87
	BYTE bInvincible;				//0x88
	char szAccountName[48];			//0x89
	char szPlayerName[24];			//0xB9
	char szRealmName[27];			//0xD1
	DWORD _11;						//0xEC  <- splited out these bytes to figure out rest of stuff
	DWORD _12;						//0xF0
	DWORD _13;						//0xF4
	DWORD _14;						//0xF8
	DWORD _15;						//0xFC
	DWORD _16;						//0x100
	DWORD _17;						//0x104
	DWORD _18;						//0x108
	DWORD _19;						//0x10C
	DWORD _20;						//0x110
	DWORD _21;						//0x114
	DWORD _22;						//0x118
	DWORD _23;						//0x11C
	DWORD _24;						//0x120
	DWORD _25;						//0x124
	DWORD _26;						//0x128
	DWORD _27;						//0x12C
	DWORD _28;						//0x130
	DWORD _29;						//0x134
	DWORD _30;						//0x138
	DWORD _31;						//0x13C
	DWORD _32;						//0x140
	DWORD _33;						//0x144
	DWORD _34;						//0x148
	DWORD _35;						//0x14C
	DWORD _36;						//0x150
	DWORD _37;						//0x154
	DWORD _38;						//0x158
	DWORD _39;						//0x15C
	DWORD _40;						//0x160
	DWORD _41;						//0x164
	DWORD _42;						//0x168
	DWORD _43;						//0x16C
	DWORD _44;						//0x170
	DWORD _45;						//0x174
	DWORD _46;						//0x178
	DWORD _47;						//0x17C
	DWORD _48;						//0x180
	DWORD _49;						//0x184
	DWORD _50;						//0x188
	DWORD _51;						//0x18C
	DWORD _52;						//0x190
	DWORD _53;						//0x194
	DWORD _54;						//0x198
	DWORD _55;						//0x19C
	DWORD _56;						//0x1A0
	DWORD _57;						//0x1A4
	DWORD _58;						//0x1A8
	DWORD _59;						//0x1AC
	DWORD _60;						//0x1B0
	DWORD _61;						//0x1B4
	DWORD _62;						//0x1B8
	DWORD _63;						//0x1BC
	DWORD _64;						//0x1C0
	DWORD _65;						//0x1C4
	DWORD _66;						//0x1C8
	DWORD _67;						//0x1CC
	DWORD _68;						//0x1D0
	DWORD _69;						//0x1D4
	DWORD _70;						//0x1D8
	DWORD _71;						//0x1DC
	DWORD _72;						//0x1E0
	DWORD _73;						//0x1E4
	BYTE _74;						//0x1E8
	WORD wCTemp;					//0x1E9	
	WORD CharFlags;					//0x1EB
	BYTE bNoMonsters;				//0x1ED
	DWORD dwMonsterClass;			//0x1EE
	BYTE bMonsterInfo;				//0x1F2
	DWORD dwMonsterDebug;			//0x1F3
	BYTE bItemRare;					//0x1F7
	BYTE bItemUnique;				//0x1F8
	BYTE _76[2];					//0x1F9
	DWORD dwAct;					//0x1FB -act default = 1
	BYTE bNoPreload;				//0x1FF -npl
	BYTE bDirect;					//0x200 -direct
	BYTE bLowEnd;					//0x201 -lem
	BYTE bNoGFXCompression;			//0x202 -nocompress
	DWORD dwArena;					//0x203 -> points to exArena* ?
	BYTE _76c[6];					//0x207
	BOOL(__stdcall *pfn77)();		//0x20D Called when MPQs are loaded	(Win.10172), pointed func always returns 1, mby used in older version
	BYTE bTxt;						//0x211 -txt
	BYTE bLog;						//0x212
	BYTE bMsgLog;					//0x213
	BYTE bSafeMode;					//0x214
	BYTE bNoSave;					//0x215
	DWORD dwSeed;					//0x216
	BYTE bCheats;					//0x21A
	BYTE bTeen;						//0x21B
	BYTE bNoSound;					//0x21C -ns
	BYTE bQuests;					//0x21D -questall
	BYTE _80;						//0x21E
	BYTE bBuild;					//0x21F -build
	BYTE bSoundBackground;			//0x220 -sndbkg
	DWORD *pfnBnetCallbacks;		//0x221 -comint
	BYTE _81[28];					//0x225
	char szGamePass[24];			//0x241
	DWORD _83[64];					//0x259
	BYTE bSkipToBnet;				//0x359 -skiptobnet
	DWORD _84[27];					//0x35A
	BYTE _85[2];					//0x3C6
};
#pragma pack(pop)

struct exGfxCell  // Size is 0x2C <- to be verified
{
	DWORD flags;					//0x00
	DWORD width;					//0x04
	DWORD height;					//0x08
	int xoffs;						//0x0C
	int yoffs;						//0x10
	DWORD _2;						//0x14
	DWORD lpParent;					//0x18
	DWORD length;					//0x1C
	BYTE cols;						//0x20
};


/* To Find
	BYTE nComponents;				//0x1D
	struct
	{
	DWORD dwUnitToken;			//0x30
	DWORD dwCompToken;			//0x34
	DWORD dwSomeToken;			//0x38
	DWORD _3;					//0x3C
	DWORD dwWClassToken;		//0x40
	} tUnitInfo;
	*/
struct exCellContext		//size 0x48
{
	DWORD nCellNo;					//0x00
	DWORD _0a;						//0x04
	DWORD dwUnit;					//0x08
	DWORD dwClass;					//0x0C
	DWORD dwMode;					//0x10
	DWORD _3;						//0x14
	DWORD _4;						//0x18
	BYTE _5;						//0x1C
	BYTE _5a;						//0x1D
	WORD _6;						//0x1E
	DWORD _7;						//0x20
	DWORD _8;						//0x24
	DWORD _9;						//0x28
	char* szName;					//0x2C
	DWORD _11;						//0x30
	CellFile* pCellFile;			//0x34 also pCellInit
	DWORD _12;						//0x38
	exGfxCell* pGfxCells;				//0x3C
	DWORD direction;				//0x40
	DWORD _14;						//0x44
};


struct exRosterInfo
{
	DWORD dwUnitId;
	DWORD dwPartyFlags;  //0x02 - ignore, 0x04 - squelch, 0x08 hostile
	exRosterInfo *ptNext;
};

struct exRosterPet //size 0x34
{
	DWORD dwMonStatsIdx;//0x00
	DWORD dwPetTypeIdx;	//0x04
	DWORD dwUnitId;		//0x08
	DWORD dwOwnerId;	//0x0C
	DWORD _4;			//0x10
	DWORD _5;			//0x14
	DWORD _6;			//0x18
	DWORD LifePercent;	//0x1C
	DWORD bDrawIcon;	//0x20
	void* _8;			//0x24
	DWORD _9;			//0x28
	DWORD _10;			//0x2C
	exRosterPet* ptNext;	//0x30
};

struct exRosterBody
{
	DWORD CorpseId;
	exRosterBody *ptPrevCorpse;
};

struct exRosterUnit {
	char szName[16];				//0x00
	DWORD dwUnitId;					//0x10
	DWORD dwPartyLife;				//0x14
	DWORD KillCount;				//0x18
	DWORD dwClassId;                //0x1C
	WORD wLevel;					//0x20
	WORD wPartyId;  				//0x22
	DWORD dwLevelId;                //0x24
	DWORD Xpos;						//0x28
	DWORD Ypos;						//0x2C
	DWORD dwPartyFlags;				//0x30
	exRosterInfo** ptInfo;			//0x34
	exRosterBody* ptBody;				//0x38
	DWORD _6[10];					//0x3C
	WORD _7;						//0x64
	char szName2[16];				//0x66
	WORD _8;						//0x76
	DWORD _9[2];					//0x78
	exRosterUnit * pNext;				//0x80
};


#endif
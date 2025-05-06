#ifndef _D2STRUCTS_H
#define _D2STRUCTS_H

#pragma once
#include <string>
using namespace std;

struct CBPlayerData;
struct CBItemData;

struct AttackStruct;
struct AutomapCell;
struct AutomapLayer;
struct AutomapLayer2;
struct CollMap;
struct UnitAny;
struct Room1;
struct Room2;
struct Level;
struct LevelTxt;
struct Act;
struct ActMisc;
struct RosterUnit;
struct PresetUnit;
struct OverheadMsg;
struct ObjectData;
struct ObjectTxt;
struct RoomTile;
struct ItemTxt;
struct Inventory;
struct InventoryInfo;
struct Room1;
struct Skill;
struct GameListEntry;
struct GameStructInfo;
struct CellFile;
struct Control;
struct ControlPreferences;
struct ControlText;
struct LevelNameInfo;
struct CellContext;
struct Path;
struct MonsterTxt;
struct SuperUniqueTxt;
struct TreasureClassItem;
struct TreasureClass;

struct SkillsBIN;
struct SkillData;
struct Skills;
struct Room;
struct ActMap;
struct CGame;
struct D2Stat;
struct Stats;
struct Unit;

struct NetClient;

struct jspControlText;
struct jspControl;
struct jspCellContext;
struct jspCellFile;
struct jspUnitAny;

typedef AttackStruct *LPATTACKSTRUCT;
typedef AutomapLayer *LPAUTOMAPLAYER;
typedef AutomapLayer2 *LPAUTOMAPLAYER2;
typedef AutomapCell *LPAUTOMAPCELL;
typedef Act *LPACT;
typedef CellFile *LPCELLFILE;
typedef CellContext *LPCELLCONTEXT;
typedef Control *LPCONTROL;
typedef ControlPreferences *LPCONTROLPREFERENCES;
typedef ControlText *LPCONTROLTEXT;
typedef PresetUnit *LPPRESETUNIT;
typedef GameListEntry *LPGAMELISTENTRY;
typedef GameStructInfo *LPGAMESTRUCTINFO;
typedef CollMap *LPCOLLMAP;
typedef ActMisc *LPACTMISC;
typedef UnitAny *LPUNITANY;
typedef ObjectData *LPOBJECTDATA;
typedef ObjectTxt *LPOBJECTTXT;
typedef ItemTxt *LPITEMTXT;
typedef Level *LPLEVEL;
typedef LevelTxt *LPLEVELTXT;
typedef LevelNameInfo *LPLEVELNAMEINFO;
typedef Inventory *LPINVENTORY;
typedef InventoryInfo *LPINVENTORYINFO;
typedef Path *LPPATH;
typedef Room1 *LPROOM1;
typedef Room2 *LPROOM2;
typedef RoomTile *LPROOMTILE;
typedef RosterUnit *LPROSTERUNIT;
typedef Skill *LPSKILL;
typedef MonsterTxt *LPMONSTERTXT;
typedef SuperUniqueTxt *LPSUPERUNIQUETXT;
typedef TreasureClassItem *LPTREASURECLASSITEM;
typedef TreasureClass *LPTREASURECLASS;

typedef NetClient *LPNETCLIENT;

typedef jspControl *LPCONTROLII;
typedef jspCellFile *LPCELLFILEII;
typedef jspUnitAny *LPUNITANYII;

struct LevelNameInfo
{
	int nX;
	int nY;
	int nLevelId;
	int nAct;
};

struct InventoryInfo 
{
	int nLocation;
	int nMaxXCells;
	int nMaxYCells;
};

struct GameStructInfo
{
	BYTE _1[0x1B];					//0x00
	char szGameName[0x18];			//0x1B
	char szGameServerIp[0x56];		//0x33
	char szAccountName[0x30];		//0x89
	char szCharName[0x18];			//0xB9
	char szRealmName[0x18];			//0xD1
	BYTE _2[0x158];					//0xE8
	char szGamePassword[0x18];		//0x23F
};

struct AutomapCell
{
	DWORD fSaved;					//0x00
	WORD nCellNo;					//0x04
	WORD xPixel;					//0x06
	WORD yPixel;					//0x08
	WORD wWeight;					//0x0A
	AutomapCell *pLess;				//0x0C
	AutomapCell *pMore;				//0x10
};

struct GfxCell
{
	DWORD flags;					//0x00
	DWORD width;					//0x04
	DWORD height;					//0x08
	DWORD xoffs;					//0x0C
	DWORD yoffs;					//0x10
	DWORD _2;						//0x14
	DWORD lpParent;					//0x18
	DWORD length;					//0x1C
	BYTE cols;						//0x20
};


struct InteractStruct
{
	DWORD dwMoveType;			//0x00
	UnitAny* lpPlayerUnit;		//0x04
	UnitAny* lpTargetUnit;		//0x08
	DWORD dwTargetX;			//0x0C
	DWORD dwTargetY;			//0x10
	DWORD _1;					//0x14
	DWORD _2;					//0x18
};

struct CellFile
{
	DWORD dwVersion;				//0x00
	struct {
		WORD dwFlags;
		BYTE mylastcol;
		BYTE mytabno:1;
	};								//0x04
	DWORD eFormat;					//0x08
	DWORD termination;				//0x0C
	DWORD numdirs;					//0x10
	DWORD numcells;					//0x14
	GfxCell *cells[255];			//0x18
};

struct jspCellFile {
	DWORD dwVersion;				//0x00
	struct {
		WORD dwFlags;
		BYTE mylastcol;
		BYTE mytabno : 1;
	};								//0x04
	DWORD eFormat;					//0x08
	DWORD termination;				//0x0C
	DWORD numdirs;					//0x10
	DWORD numcells;					//0x14
	GfxCell *cells[255];			//0x18
};

struct ControlPreferences
{
	DWORD dwType;//0x00
};

struct CellContext
{
	DWORD nCellNo;
	DWORD _1[12];			//0x00
	LPCELLFILE pCellFile;	//0x34
	DWORD _2[4];			//0x38
};

struct jspCellContext {
	DWORD _1[13];					//0x00
	LPCELLFILEII pCellFile;			//0x34
	DWORD _2[4];					//0x38
};

struct TreasureClassItem
{
	DWORD _1[2];
	DWORD thingno; //+08
	struct
	{
		DWORD _3:2;
		DWORD tcflag:1;
	}; //+0c
	DWORD _2[3];
};

struct TreasureClass
{
	DWORD _1a;
	DWORD numitems; //+04
	DWORD _1[8];
	LPTREASURECLASSITEM items; //+28
};

struct AutomapLayer
{
	DWORD nLayerNo;					//0x00
	DWORD fSaved;					//0x04
	AutomapCell *pFloors;			//0x08
	AutomapCell *pWalls;			//0x0C
	AutomapCell *pObjects;			//0x10
	AutomapCell *pExtras;			//0x14
	AutomapLayer *pNextLayer;		//0x18
};

struct AutomapLayer2
{
	DWORD _1[2];					//0x00
	DWORD nLayerNo;					//0x08
};

struct LevelTxt
{
	DWORD dwLevelNo;				//0x00
	DWORD _1[60];					//0x04
	BYTE _2;						//0xF4
	char szName[40];				//0xF5
	char szEntranceText[40];		//0x11D
	char szLevelDesc[41];			//0x145
	wchar_t wName[40];				//0x16E
	wchar_t wEntranceText[40];		//0x1BE
	BYTE nObjGroup[8];				//0x196
	BYTE nObjPrb[8];				//0x19E
};

struct ControlText
{
	wchar_t* wText; //0x00
	wchar_t* wText2;//0x04
	DWORD _1[3];	//0x08
	DWORD dwColor;	//0x14
	DWORD _2;		//0x18
	ControlText* pNext;//0x1C
};

struct Control {
   DWORD dwType;					//0x00
   CellFile *pCellFile;				//0x04
   DWORD dwDisabled;				//0x08
   DWORD dwPosX;					//0x0C
   DWORD dwPosY;					//0x10
   DWORD dwSizeX;					//0x14
   DWORD dwSizeY;					//0x18
   VOID (FASTCALL * Initialize)(LPCONTROL pControl);//0x1c
   DWORD _3;						//0x20
   DWORD *_4;						//0x24
   DWORD *_5;						//0x28
   DWORD _6;						//0x2C
   DWORD *_7;						//0x30
   DWORD *_8;						//0x34
   DWORD _9;						//0x38
   Control* pNext;					//0x3C
   DWORD _10;						//0x40
   DWORD dwMaxLength;				//0x44
   union {
	   ControlText* pFirstText;		//0x48
	   DWORD dwScrollEntries;		//0x48
   };
   union {
       ControlText* pLastText;		//0x4C
	   DWORD dwScrollPosition;		//0x4C
   };
   ControlText* pSelectedText;		//0x50
   DWORD dwSelectEnd;				//0x54
   DWORD dwSelectStart;				//0x58
   wchar_t wText[0x1A];				//0x5C
   Control* pChildControl;			//0x90
};

struct jspControlText // size = 0x20
{
	wchar_t* wText[5]; //0x00 for each field
	DWORD dwColor;	//0x14
	DWORD dwAlign;	//0x18
	jspControlText* pNext;	//0x1C
};

struct jspControl {
	DWORD dwType;					//0x00
	DWORD *_1;						//0x04 // unsure? definitely a ptr but not obvious, usually points to 6 when dwType is 6 I think
	DWORD dwDisabled;				//0x08
	DWORD dwPosX;					//0x0C
	DWORD dwPosY;					//0x10
	DWORD dwSizeX;					//0x14
	DWORD dwSizeY;					//0x18
	// I think _2 thru _9 are a handler table of some sort
	DWORD *_2;						//0x1C // some sort of function (maybe click?)
	DWORD _3;						//0x20
	DWORD *_4;						//0x24 // some sort of function
	DWORD *_5;						//0x28
	DWORD _6;						//0x2C
	DWORD *_7;						//0x30 // ptr to something...
	DWORD *_8;						//0x34 // another random ptr... mostly dead ends when I examined them
	DWORD _9;						//0x38
	jspControl* pNext;					//0x3C
	DWORD _10;						//0x40
	DWORD unkState; 					//0x44 _11 0 when button avail to be clicked 1 when greyed - still need to look at this more
	jspControlText* pFirstText;			//0x48
	jspControlText* pLastText;			//0x4C
	jspControlText* pSelectedText;		//0x50
	DWORD dwSelectEnd;				//0x54
	DWORD dwSelectStart;				//0x58
	union {
		struct { //Textboxes
			wchar_t wText[256];		//0x5C
			DWORD dwCursorPos;
			DWORD dwIsCloaked;
		};
		struct { //Buttons
			DWORD _12[2];			//0x5C
			wchar_t wText2[256];	//0x6C
		};
	};
};

struct GameListEntry
{
	WORD wRequestId;
	DWORD dwIndex;
	BYTE bPlayers;
	DWORD dwStatus;
	string sGameName;
	string sGameDesc;
};

struct RoomTile
{
	Room2* pRoom2;            //0x00
	RoomTile* pNext;          //0x04
	DWORD _2[2];            //0x08
	DWORD *nNum;             //0x10 
};

struct RosterUnit
{
	char szName[16];				//0x00
	DWORD dwUnitId;					//0x10
	DWORD dwPartyLife;				//0x14
	DWORD _1;						//0x18
	DWORD dwClassId;                //0x1C
	WORD wLevel;					//0x20
	WORD wPartyId;  				//0x22
	DWORD dwLevelId;                //0x24
	DWORD Xpos;						//0x28
	DWORD Ypos;						//0x2C
	DWORD dwPartyFlags;				//0x30
	BYTE * _5;						//0x34
	DWORD _6[11];					//0x38
	WORD _7;						//0x64
	char szName2[16];				//0x66
	WORD _8;						//0x76
	DWORD _9[2];					//0x78
	RosterUnit * pNext;				//0x80
};

struct QuestInfo
{
	void *pBuffer;					//0x00
	DWORD _1;						//0x04
};

struct Waypoint
{
	BYTE flags;						//0x00
};

struct PlayerData
{
	char szName[0x10];				//0x00
	QuestInfo *pNormalQuest;		//0x10
	QuestInfo *pNightmareQuest;		//0x14
	QuestInfo *pHellQuest;			//0x18
	Waypoint *pNormalWaypoint;		//0x1c
	Waypoint *pNightmareWaypoint;	//0x20
	Waypoint *pHellWaypoint;		//0x24
};

struct CollMap
{
	DWORD dwPosGameX;				//0x00
	DWORD dwPosGameY;				//0x04
	DWORD dwSizeGameX;				//0x08
	DWORD dwSizeGameY;				//0x0C
	DWORD dwPosRoomX;				//0x10
	DWORD dwPosRoomY;				//0x14
	DWORD dwSizeRoomX;				//0x18
	DWORD dwSizeRoomY;				//0x1C
	WORD *pMapStart;				//0x20
	WORD *pMapEnd;					//0x22
};


struct PresetUnit
{
	DWORD _1;					//0x00
	DWORD dwTxtFileNo;			//0x04
	DWORD dwPosX;				//0x08
	LPPRESETUNIT pPresetNext;	//0x0C
	DWORD _2;					//0x10
	DWORD dwType;				//0x14
	DWORD dwPosY;				//0x18
};

struct Level
{
	DWORD _1[4];					//0x00
	Room2 *pRoom2First;				//0x10
	DWORD _2[2];					//0x14
	DWORD dwPosX;					//0x1C
	DWORD dwPosY;					//0x20
	DWORD dwSizeX;					//0x24
	DWORD dwSizeY;					//0x28
	BYTE _3[0x180];					//0x3C
	Level *pNextLevel;				//0x1AC
	DWORD _4;						//0x1B0
	ActMisc *pMisc;					//0x1B4
	DWORD _5[3];					//0x1B8
	DWORD dwSeed[2];				//0x1C4
	DWORD _6;						//0x1C8
	DWORD dwLevelNo;				//0x1D0
};

struct Room1
{
	Room1** pRoomsNear; 	//0x00
	DWORD _1[3];			//0x04
	Room2* pRoom2;			//0x10
	DWORD _2[3];			//0x14
	CollMap* Coll;			//0x20
	DWORD dwRoomsNear;		//0x24
	DWORD _3[9];			//0x28
	DWORD dwXStart;			//0x4C
	DWORD dwYStart;			//0x50
	DWORD dwXSize;			//0x54
	DWORD dwYSize;			//0x58
	DWORD _4[6];			//0x5C
	UnitAny* pUnitFirst;	//0x74
	DWORD _5;				//0x78
	Room1* pRoomNext;		//0x7C
};

struct Room2
{
	DWORD _1[2];			//0x00
	LPROOM2 * pRoom2Near;	//0x08
	DWORD _2[5];			//0x0C
	LPDWORD pType2Info;		//0x20
	LPROOM2 pRoom2Next;		//0x24
	DWORD dwRoomFlags;		//0x28
	DWORD dwRoomsNear;		//0x2C
	LPROOM1 pRoom1;			//0x30
	DWORD dwPosX;			//0x34
	DWORD dwPosY;			//0x38
	DWORD dwSizeX;			//0x3C
	DWORD dwSizeY;			//0x40
	DWORD _3;				//0x44
	DWORD dwPresetType;		//0x48
	LPROOMTILE pRoomTiles;	//0x4C
	DWORD _4[2];			//0x50
	LPLEVEL pLevel;			//0x58
	LPPRESETUNIT pPreset;	//0x5C
};

struct ActMisc
{
	BYTE _1[0x94];
	DWORD dwStaffTombLevel;
	BYTE _2[0x3D4];
	Act *pAct;
	DWORD _3[3];
	Level *pLevelFirst;
};

struct Act
{
	DWORD _1[3];         //0x00
	DWORD dwMapSeed;      //0x0C
	Room1* pRoom1;         //0x10
	DWORD dwAct;         //0x14
	DWORD _2[12];         //0x18
	ActMisc* pMisc;         //0x48 
};

struct Path
{
	WORD xOffset;					//0x00
	WORD xPos;						//0x02
	WORD yOffset;					//0x04
	WORD yPos;						//0x06
	DWORD _1[2];					//0x08
	WORD xTarget;					//0x10
	WORD yTarget;					//0x12
	DWORD _2[2];					//0x14
	Room1 *pRoom1;					//0x1C
	Room1 *pRoomUnk;				//0x20
	DWORD _3[3];					//0x24
	UnitAny *pUnit;					//0x30
	DWORD dwFlags;					//0x34
	DWORD _4;						//0x38
	DWORD dwPathType;				//0x3C
	DWORD dwPrevPathType;			//0x40
	DWORD dwUnitSize;				//0x44
	DWORD _5[4];					//0x48
	UnitAny *pTargetUnit;			//0x58
	DWORD dwTargetType;				//0x5C
	DWORD dwTargetId;				//0x60
	BYTE bDirection;				//0x64
};

struct Pseudo 
{ 
   CHAR Game[16];        //0x00
   CHAR Password[16];    //0x10
   BYTE _1[0x26];        //0x20
   BYTE MaxPlayers;      //0x46
};

struct ItemPath
{
	DWORD _1[3];					//0x00
	DWORD dwPosX;					//0x0C
	DWORD dwPosY;					//0x10
	//Use Path for the rest
};

struct Stat
{
	WORD wSubIndex;					//0x00
	WORD wStatIndex;				//0x02
	DWORD dwStatValue;				//0x04
};

struct StatList
{
	DWORD _1[9];					//0x00
	Stat *pStat;					//0x24
	WORD wStatCount1;				//0x28
	WORD wStatCount2;				//0x2A
	DWORD _2[2];					//0x2C
	BYTE *_3;						//0x34
	DWORD _4;						//0x38
	StatList *pNext;				//0x3C
};

struct Inventory
{
	DWORD dwSignature;				//0x00
	BYTE *bGame1C;					//0x04
	UnitAny *pOwner;				//0x08
	UnitAny *pFirstItem;			//0x0C
	UnitAny *pLastItem;				//0x10
	DWORD _1[2];					//0x14
	DWORD dwLeftItemUid;			//0x1C
	UnitAny *pCursorItem;			//0x20
	DWORD dwOwnerId;				//0x24
	DWORD dwItemCount;				//0x28
};

struct Light
{
	DWORD _1[3];					//0x00
	DWORD dwType;					//0x0C
	DWORD _2[7];					//0x10
	DWORD dwStaticValid;			//0x2C
	int *pnStaticMap;				//0x30
};

struct SkillInfo
{
	WORD wSkillId;					//0x00
};

struct Skill
{
	SkillInfo *pSkillInfo;			//0x00
	Skill *pNextSkill;				//0x04
	DWORD _1[8];					//0x08
	DWORD dwSkillLevel;				//0x28
	DWORD _2[2];					//0x2C
	DWORD dwFlags;					//0x30
};

struct Info
{
	BYTE *pGame1C;					//0x00
	
	union
	{
		Skill *pFirstSkill;				//0x04
		Skill *pStartSkill;				//0x04
	};

	Skill *pLeftSkill;				//0x08
	Skill *pRightSkill;				//0x0C
	Skill *pCurrentSkill;			//0x10
	DWORD dwUnk;					//0x14
};

struct ItemData
{
	DWORD dwQuality;				//0x00
	DWORD _1[2];					//0x04
	DWORD dwItemFlags;				//0x0C 1 = Owned by player, 0xFFFFFFFF = Not owned
	DWORD _2[2];					//0x10
	DWORD dwFlags;					//0x18
	DWORD _3[3];					//0x1C
	DWORD dwQuality2;				//0x28
	DWORD dwItemLevel;				//0x2C
	WORD _4;						//0x30
	WORD wRarePrefix;				//0x32
	WORD wRareSuffix;				//0x34
	WORD _14;
	WORD wPrefix;					//0x38
	WORD _5[2];						//0x3A
	WORD wSuffix;					//0x3E
	DWORD _6;						//0x40
	BYTE BodyLocation;				//0x44
	BYTE ItemLocation;				//0x45 Non-body/belt location (Body/Belt == 0xFF)
	BYTE _7;						//0x46
	WORD _8;						//0x47
	DWORD _9[4];					//0x48
	Inventory *pOwnerInventory;		//0x5C
	DWORD _10;						//0x60
	UnitAny *pNextInvItem;			//0x64
	BYTE _11;						//0x68
	BYTE NodePage;					//0x69 Actual location, this is the most reliable by far
	WORD _12;						//0x6A
	DWORD _13[6];					//0x6C
	UnitAny *pOwner;				//0x84
};

struct ItemTxt
{
	wchar_t szName2[0x40];			//0x00
	union
	{
		DWORD dwCode;
		char szCode[4];
	};								//0x40
	BYTE _2[0x70];					//0x84
	WORD nLocaleTxtNo;				//0xF4
	BYTE _2a[0x19];					//0xF7
	BYTE xSize;						//0xFC
	BYTE ySize;						//0xFD
	BYTE _2b[13];					//0xFE
	BYTE nType;						//0x11E
	BYTE _3[0x0d];					//0x11F
	BYTE fQuest;					//0x12A
};

struct MonsterTxt
{
	BYTE _1[0x6];					//0x00
	WORD nLocaleTxtNo;				//0x06
	WORD flag;						//0x08
	WORD _1a;						//0x0A
	union
	{
		DWORD flag1;				//0x0C
		struct
		{
			BYTE flag1a;			//0x0C
			BYTE flag1b;			//0x0D
			BYTE flag1c[2];			//0x0E
		};
	};
	BYTE _2[0x22];					//0x10
	WORD velocity;					//0x32
	BYTE _2a[0x52];					//0x34
	WORD tcs[3][4];					//0x86
	BYTE _2b[0x52];					//0x9E
	wchar_t szDescriptor[0x3c];		//0xF0
	BYTE _3[0x1a0];					//0x12C
};

struct SuperUniqueTxt
{
	WORD nIndex;
	WORD nLocaleTxtNo;
	DWORD _1[9];
	BYTE _1a[4];
	WORD tcs[4];
};

struct MonsterData
{
	BYTE _1[22];					//0x00
	struct
	{
		BYTE fUnk:1;
		BYTE fNormal:1;
		BYTE fChamp:1;
		BYTE fBoss:1;
		BYTE fMinion:1;
	};								//0x16
	WORD _2;						//0x17
	DWORD _3;						//0x18
	BYTE anEnchants[9];				//0x1C
	BYTE _4;						//0x25
	WORD wUniqueNo;					//0x26
	DWORD _5;						//0x28
	struct
	{
		wchar_t wName[28];
	};								//0x2C
};

struct ObjectTxt
{
	char szName[0x40];				//0x00
	wchar_t wszName[0x40];			//0x40
	BYTE _1[4];						//0xC0
	BYTE nSelectable0;				//0xC4
	BYTE _2[0x87];					//0xC5
	BYTE nOrientation;				//0x14C
	BYTE _2b[0x19];					//0x14D
	BYTE nSubClass;					//0x166
	BYTE _3[0x11];					//0x167
	BYTE nParm0;					//0x178
	BYTE _4[0x39];					//0x179
	BYTE nPopulateFn;				//0x1B2
	BYTE nOperateFn;				//0x1B3
	BYTE _5[8];						//0x1B4
	DWORD nAutoMap;					//0x1BB
};

struct ObjectData
{
	ObjectTxt *pTxt;				//0x00
	union
	{
		BYTE Type;					//0x04 (0x0F would be a Exp Shrine)
		struct
		{
			BYTE _1:7;
			BYTE ChestLocked:1;
		};
	};
	DWORD _2[8];					//0x08
	char szOwner[0x10];				//0x28

};

struct ObjectPath
{
	Room1 *pRoom1;					//0x00
	DWORD _1[2];					//0x04
	DWORD dwPosX;					//0x0C
	DWORD dwPosY;					//0x10
	//Leaving rest undefined, use Path
};

struct UnitAny
{
	DWORD dwType;					//0x00
	DWORD dwTxtFileNo;				//0x04
	DWORD _1;						//0x08
	DWORD dwUnitId;					//0x0C
	DWORD dwMode;					//0x10
	union
	{
		PlayerData *pPlayerData;
		ItemData *pItemData;
		MonsterData *pMonsterData;
		ObjectData *pObjectData;
		//TileData *pTileData doesn't appear to exist anymore
	};								//0x14
	DWORD dwAct;					//0x18
	Act *pAct;						//0x1C
	DWORD dwSeed[2];				//0x20
	DWORD _2;						//0x28
	union
	{
		Path *pPath;
		ItemPath *pItemPath;
		ObjectPath *pObjectPath;
	};								//0x2C
	DWORD _3[5];					//0x30
	DWORD dwGfxFrame;				//0x44
	DWORD dwFrameRemain;			//0x48
	WORD wFrameRate;				//0x4C
	WORD _4;						//0x4E
	BYTE *pGfxUnk;					//0x50
	DWORD *pGfxInfo;				//0x54
	DWORD _5;						//0x58
	StatList *pStats;				//0x5C
	Inventory *pInventory;			//0x60
	Light *ptLight;					//0x64
	DWORD _6[9];					//0x68
	WORD wX;						//0x8C
	WORD wY;						//0x8E
	DWORD _7;						//0x90
	DWORD dwOwnerType;				//0x94
	DWORD dwOwnerId;				//0x98
	DWORD _8[2];					//0x9C
	OverheadMsg* pOMsg;				//0xA4
	Info *pInfo;					//0xA8
	DWORD _9[6];					//0xAC
	DWORD dwFlags;					//0xC4
	DWORD dwFlags2;					//0xC8
	DWORD _10[5];					//0xCC
	LPUNITANY pChangedNext;			//0xE0
	LPUNITANY pRoomNext;			//0xE4
	LPUNITANY pListNext;			//0xE8 -> 0xD8
	CHAR szNameCopy[0x10];			//+0x66
};

struct jspUnitAny {
	DWORD dwType;					//0x00
	DWORD dwTxtFileNo;				//0x04
	DWORD _1;						//0x08
	DWORD dwUnitId;					//0x0C
	DWORD dwMode;					//0x10
	union
	{
		PlayerData *pPlayerData;
		ItemData *pItemData;
		MonsterData *pMonsterData;
		ObjectData *pObjectData;
		//TileData *pTileData doesn't appear to exist anymore
	};								//0x14
	DWORD dwAct;					//0x18
	Act *pAct;						//0x1C
	DWORD dwSeed[2];				//0x20
	DWORD _2;						//0x28
	union
	{
		Path *pPath;
		ItemPath *pItemPath;
		ObjectPath *pObjectPath;
	};								//0x2C
	DWORD _3[5];					//0x30
	DWORD dwGfxFrame;				//0x44
	DWORD dwFrameRemain;			//0x48
	WORD wFrameRate;				//0x4C
	WORD _4;						//0x4E
	BYTE *pGfxUnk;					//0x50
	DWORD *pGfxInfo;				//0x54
	DWORD _5;						//0x58
	StatList *pStats;				//0x5C
	Inventory *pInventory;			//0x60
	Light *ptLight;					//0x64
	DWORD dwStartLightRadius;               //0x68
	WORD nPl2ShiftIdx;                              //0x6C
	WORD nUpdateType;                               //0x6E
	jspUnitAny* pUpdateUnit;                           //0x70 - Used when updating unit.
	DWORD* pQuestRecord;                    //0x74
	DWORD bSparklyChest;                    //0x78 bool
	DWORD* pTimerArgs;                              //0x7C
	DWORD dwSoundSync;                              //0x80
	DWORD _6[2];                                    //0x84
	WORD wX;						//0x8C
	WORD wY;						//0x8E
	DWORD _7;						//0x90
	DWORD dwOwnerType;				//0x94
	DWORD dwOwnerId;				//0x98
	DWORD _8[2];					//0x9C
	OverheadMsg* pOMsg;				//0xA4
	Info *pInfo;					//0xA8
	DWORD _9[6];					//0xAC
	DWORD dwFlags;					//0xC4
	DWORD dwFlags2;					//0xC8
	DWORD _10[5];					//0xCC
	jspUnitAny *pChangedNext;			//0xE0
	jspUnitAny *pListNext;				//0xE4 -> 0xD8
	jspUnitAny *pRoomNext;				//0xE8
};

struct BnetData
{
	DWORD dwId;					//0x00
	DWORD dwId2;				//0x04
	DWORD _1[3];				//0x08
	DWORD dwId3;				//0x14
	WORD Unk3;					//0x18
	char szGameName[22];		//0x1A
	char szGameIP[16];			//0x30
	DWORD _2[16];				//0x40
	DWORD dwId4;				//0x80
	DWORD _3;					//0x84
	char szAccountName[48];		//0x88
	char szPlayerName[24];		//0xB8
	char szRealmName[8];		//0xD0
	BYTE _4[273];				//0xD8
	BYTE nCharClass;			//0x1E9
	BYTE nCharFlags;			//0x1EA
	BYTE nMaxDiff;				//0x1EB
	BYTE _5[31];				//0x1EC
	BYTE nDifficulty;			//0x20B
	void *_6;					//0x20C
	DWORD _7[5];				//0x210
	WORD _8;					//0x224
	BYTE _9;					//0x226
	char szRealmName2[24];		//0x227
	char szGamePass[24];		//0x23F
	char szGameDesc[256];		//0x257
	WORD _10;					//0x348
	BYTE _11;					//0x34B
};


struct WardenClientRegion_t
{
	DWORD cbAllocSize; //+00
	DWORD offsetFunc1; //+04
	DWORD offsetRelocAddressTable; //+08
	DWORD nRelocCount; //+0c
	DWORD offsetWardenSetup; //+10
	DWORD _2[2];
	DWORD offsetImportAddressTable; //+1c
	DWORD nImportDllCount; //+20
	DWORD nSectionCount; //+24
};

struct SMemBlock_t
{
	DWORD _1[6];
	DWORD cbSize; //+18
	DWORD _2[31];
	BYTE data[1]; //+98
};

struct WardenClient_t
{
	WardenClientRegion_t* pWardenRegion; //+00
	DWORD cbSize; //+04
	DWORD nModuleCount; //+08
	DWORD param; //+0c
	DWORD fnSetupWarden; //+10
};

struct WardenIATInfo_t
{
	DWORD offsetModuleName;
	DWORD offsetImportTable;
};

struct AttackStruct
{
	DWORD dwAttackType;			//0x00
	UnitAny* lpPlayerUnit;		//0x04
	UnitAny* lpTargetUnit;		//0x08
	DWORD dwTargetX;			//0x0C
	DWORD dwTargetY;			//0x10
	DWORD _1;					//0x14
	DWORD _2;					//0x18
};

struct Skill_t
{
	CHAR			name[64];
	WORD			skillID;
};

struct SkillsBIN //size=0x23C (572)
{
	WORD	skillID;		//+00
	BYTE	uk1[0x0A];		//+02
	BYTE	charclass;		//+0C
	BYTE	uk2[0x08];		//+10
	WORD	itypea1;		//+18
	WORD	itypea2;		//+1A
	WORD	itypea3;		//+1C
	WORD	itypeb1;		//+1E
	WORD	itypeb2;		//+20
	WORD	itypeb3;		//+22
	WORD	etypea1;		//+24
	WORD	etypea2;		//+26
	WORD	etypeb1;		//+28
	WORD	etypeb2;		//+2A
	BYTE	uk3[0x100];		//+2C
	WORD	maxlvl;			//+12C
	BYTE	uk4[0x42];		//+12E
	int		skpoints;		//+170
	WORD	reqlevel;		//+174
	BYTE	uk5[0x1E];		//+176
	DWORD	skilldesc;		//+194 (DWORD ?)
	BYTE	uk6[0xA4];		//+198
};

struct SkillData
{								//Offset from Code. (size = 0x3C or 0x40)
	SkillsBIN*	ptSkillBin;		//+00
	SkillData*	ptNextSkill;	//+04
	DWORD	mode;           //+08
	DWORD	uk1[3];         //+0C
	DWORD	targetInfo;     //+18
	DWORD	targetType;     //+1c
	DWORD	targetUNID;     //+20
	DWORD	uk2;            //+24
	DWORD	slvl;           //+28
	DWORD	slvlBonus;      //+2c
	DWORD	uk3;            //+30
	int		state;          //+34 (-1 if index exist)
	DWORD	param1;			//+38 (nb current charge)
	DWORD	param2;			//+3C
};

struct Skills
{								//Offset from Code.
	DWORD		gameRelated;	//+00
	SkillData*	ptFirstSkill;	//+04
	SkillData*	ptLeftSkill;	//+08
	SkillData*	ptRightSkill;	//+0c
	SkillData*	ptCurrentSkill;	//+10
};

struct Room//size=0x80
{
	//ptRoom +48 0 = spawn new units (monster, objects e.tc), 1 = don't spawn any new units
	DWORD	seed1;						//+00
	DWORD	seed2;						//+04
	BYTE	uk8[0x1C];					//+08
	Room*	ptNearRooms;				//+24
	DWORD	nbNearRooms;				//+28
	Unit*	unit;						//+2C
	BYTE	uk5[0x44];					//+30
	Room*	ptNextRoom;					//+74
	union
	{
		BYTE	flags;					//+78
		struct
		{
			BYTE isGenerated : 1;
			BYTE isGenerated2 : 1;//???
		};
	};
};

struct ActMap//ptGame+BC size=0x60
{
	DWORD	isNotManaged;
	DWORD	uk4;
	DWORD	uk8;//size = 0x488
	Room*	ptFirstRoom;
};

struct Game
{                              			//Offset from Code.
	BYTE	uk1[0x18];					//+00
	DWORD	_ptLock;					//+18 Unknown  
	DWORD	memoryPool;					//+1C Memory Pool (??)  
	BYTE	uk2[0x4D];					//+20
	BYTE	difficultyLevel;			//+6D (Difficulty 0,1 or 2)
	WORD	unknown1;					//+6E Cube puts 4 here
	DWORD	V_Expansion;					//+70 (D2=0 LOD =1) (DWORD ?)
	BYTE	uk3[0x04];					//+71
	WORD	unknown2;					//+78
	BYTE	uk4[0x0E];					//+7A
	NetClient*	ptClient;				//+88
	BYTE	uk8C[0x30];					//+8C
	ActMap*	mapAct[5];					//+BC
	BYTE	ukD0[0x1024];				//+D0
	DWORD*	game10F4;					//+10F4
	BYTE	uk6[0x28];					//+10F8
	Unit*	units[0xA00];				//+1120
	Unit*	roomtitles[0x200];			//+1B20
};

struct D2Stat
{
	WORD	index;
	WORD	id;
	int		value;
};

struct Stats				//sizeof(Stats)=0x64
{
	DWORD	nUnitId;				//+00
	Unit*	ptUnit;					//+04
	DWORD	nUnitType;				//+08
	DWORD	nItemNum;				//+0C
	union
	{
		DWORD	flags;				//+10
		struct
		{
			DWORD fuk1 : 13;			//0x00001FFF
			DWORD isDisabled : 1;		//0x00002000
			DWORD fuk2 : 17;			//0x7FFFC000
			DWORD dontUseBaseValue : 1;//0x80000000
		};
	};
	DWORD	id;						//+14
	DWORD	uk18;					//+18
	BYTE	uk2[0x08];				//+1C
	D2Stat*	ptBaseStatsTable;		//+24
	WORD	nbBaseStats;			//+28
	WORD	sizeOfBaseStatsTable;	//+2A ??
	Stats*	ptStats;				//+2C
	BYTE	uk3[0x04];				//+30
	Stats*	ptItemStats;			//+34
	BYTE	uk4[0x04];				//+38
	Stats*	ptAffixStats;			//+3C
	Stats*	ptNextStats2;			//+40
	union
	{
		Unit*	ptChar;				//+44
		Unit*	ptItem;
	};
	D2Stat*	ptStatsTable;			//+48
	WORD	nbStats;				//+4C
	WORD	sizeOfStatsTable;		//+4E ??
	BYTE	uk5[0x8];				//+50
	BYTE*	unknow0;				//+58 (sizeof(*unknow0)=0x30 (calculated)
	DWORD	unknow1;				//+5C (=0)
	DWORD	unknow2;				//+60 (=0)
};

struct Unit
{										//Offset from Code.		Size: 0xF4+4
	DWORD		nUnitType;				//+00
	union{
		DWORD			nPlayerClass;
		DWORD			nTxtFileNo;
	};									//+04
	DWORD		nUnitId;				//+08
	DWORD		nItemNum;				//+0C
	DWORD		CurrentAnim;			//+10
	union{
		MonsterData*	ptMonsterData;
		ObjectData*		ptObjectData;
		ItemData*		ptItemData;
		PlayerData*		ptPlayerData;
	};									//+14
	BYTE		act;					//+18
	BYTE		uk12[3];				//+19
	void*		ptAct;					//+1C
	DWORD		SeedLow;				//+20
	DWORD		SeedHi;					//+24
	DWORD		SeedStarting;			//+28
	Path*		path;					//+2C
	BYTE		uk1[0x08];				//+30
	Path*		ptPos;					//+38
	DWORD		animSpeed;				//+3C
	BYTE		uk2[0x04];				//+40
	DWORD		curFrame;				//+44
	DWORD		remainingFrame;			//+48
	WORD		animSpeedW;				//+4C
	BYTE		actionFlag;				//+4E
	BYTE		uk3[0x1];				//+4F
	void*		ptAnimData;				//+50
	BYTE		uk4[0x08];				//+54
	Stats*		ptStats;				//+5C
	Inventory*	ptInventory;		    //+60
	BYTE		uk5[0x1C];				//+64
	CGame*		ptGame;					//+80
	BYTE		uk6[0x24];				//+84
	Skills*		ptSkills;				//+A8
	void*		ptCombatData;			//+AC
	BYTE		uk7[0x08];				//+B0
	DWORD		itemCode;				//+B8 for an item being dropped by this unit
	BYTE		uk8[0x08];				//+BC
	DWORD		flags1;					//+C4
	union{
		DWORD		flags2;				//+C8	//flags
		struct{
			DWORD	ukf1 : 25;
			DWORD	isLod : 1;
		};
	};
	BYTE		uk9[0x04];				//+CC
	DWORD		clientId;				//+D0
	BYTE		uk10[0x0C];				//+D4
	Unit*		ptFirstMonster;			//+E0
	Unit*		Unit1;					//+E4
	Unit*		Unit2;					//+E8
	BYTE		uk11[0x08];				//+EC
	union{
		CBPlayerData*	ptCBPlayerData;
		CBItemData*		ptCBItemData;
		void*			ptCBData;
	};									//+F4
};

struct NetClient
{
	DWORD	clientID;					//+00
	BYTE	uk1[0x06];					//+04
	union {								//+0A
		WORD	flag;
		struct {
			WORD f1 : 1;
			WORD f2 : 1;
			WORD isHardCoreGame : 1;
		};
	};
	BYTE	uk2;						//+0C
	char	name[0x10];					//+0D
	BYTE	uk3[0x15F];					//+1D
	BYTE*	savefile;					//+17C
	DWORD	finalSize;					//+180
	DWORD	counter;					//+184
	DWORD	currentSize;				//+188
	BYTE	uk4[0x1C];					//+18C
	CGame*	ptGame;						//+1A8
	//+1A8 is ptGame
	//+4A8 ptNextClient
	/*
	Kingpin: ptPclient
	+16C is either act or unit type
	+170 Active UniqueID for player
	+174 Active ptPlayer on Client
	+1a8 ptGame
	+1b4 Current or next ptRoom
	*/
};


/*
Akara NPCEntry

0   94 00 00 00 03 00 00 00  î.......
8   35 0D 44 0D 00 00 00 00  5.D.....
10  00 00 B0 AA B0 6F 90 BD  ..∞™∞oêΩ
18  B0 6F 00 00 00 00 00 00  ∞o......
20  00 00 00 00 00 00 01     .......
*/
#pragma pack(push)
#pragma pack(1)

typedef struct
{
	DWORD dwNPCClassId;
	DWORD dwEntryAmount;
	WORD wEntryId1;
	WORD wEntryId2;
	WORD wEntryId3;
	WORD wEntryId4;	
	WORD _1;
	DWORD dwEntryFunc1;
	DWORD dwEntryFunc2; 
	DWORD dwEntryFunc3; 
	DWORD dwEntryFunc4;
	BYTE _2[5];
} NPCMenu;

struct OverheadMsg
{
	DWORD _1;
	DWORD dwTrigger;
	DWORD _2[2];
	CHAR Msg[232];
};

struct RareItemTable
{
	DWORD _1[3];		 //0x00
	WORD wLocaleStringId;//0x0C
	DWORD _2[6];		 //0x0E
	CHAR szFixName[20];	 //0x26
};

#pragma pack(pop)

struct D2MSG
{
	HWND myHWND;
	char lpBuf[256];
};


struct InventoryLayout
{
	BYTE SlotWidth;
	BYTE SlotHeight;
	BYTE unk1;
	BYTE unk2;
	DWORD Left;
	DWORD Right;
	DWORD Top;
	DWORD Bottom;
	BYTE SlotPixelWidth;
	BYTE SlotPixelHeight;
};

struct LevelsTxt
{
	WORD wLevelNo;
	BYTE nPal;
	BYTE nAct;
	BYTE nTeleport;
	BYTE nRain;
	BYTE nMud;
	BYTE nNoPer;
	BYTE nIsInside;
	BYTE nDrawEdges;
	WORD unk0x0A;
	DWORD dwWarpDist;
	WORD wMonLvl1;
	WORD wMonLvl2;
	WORD wMonLvl3;
	WORD wMonLvl1Ex;
	WORD wMonLvl2Ex;
	WORD wMonLvl3Ex;
	DWORD dwMonDen[3];
	BYTE nMonUMin[3];
	BYTE nMonUMax[3];
	BYTE nMonWndr;
	BYTE nMonSpcWalk;
	BYTE nQuest;
	BYTE nRangedSpawn;
	DWORD dwNumMon;
	WORD wMon[25];
	WORD wNMon[25];
	WORD wUMon[25];
	WORD wCMon[4];
	WORD wCPct[4];
	WORD wCAmt[4];
	BYTE nWaypoint;
	BYTE nObjGroup[8];
	BYTE nObjPrb[8];
	char szLevelName[40];
	char szLevelWarp[40];
	char szEntryFile[41];
	wchar_t wszLevelName[40];
	wchar_t wszLevelWarp[41];
	DWORD dwThemes;
	DWORD dwFloorFilter;
	DWORD dwBlankScreen;
	DWORD dwSoundEnv;
};


#endif
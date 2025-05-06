#define D2FONT_SMALL				6
#define D2FONT_THIN					4
#define D2FONT_NORMAL				0
#define D2FONT_SMOOTH				13
#define D2FONT_BIGSMOOTH			5
#define D2FONT_CAPS					1
#define D2FONT_ROUGH				7
#define D2FONT_BIGROUGH				2
#define D2FONT_BIGBIGROUGH			3
#define D2FONT_SMOKE				11

#define STAND_PASS					1
#define STAND_SELECT				2
#define STAND_CLICK					4
#define STAND_WINOPEN				5
#define STAND_LEVLEUP				7
#define STAND_PICKUP				235
#define STAND_ARCANEPORTAL			2556
#define D2NON_SECRET1				4702

struct AUTOMAP
{
	LPSTR Message;
	LPSTR Data;
	INT FontColor;
	INT FontType;
};

struct STATE
{
	LPSTR Text;
	DWORD State;
	DWORD Timer;
};

class Design
{
public:
	Design();
	virtual ~Design();

	BOOL GameFilter();
	BOOL Mouse();
	BOOL Options();
	BOOL Supplies();
	BOOL Gold();

	VOID GameDraw();
	VOID GameDraw2();
	VOID GameDraw3();
	VOID GameDraw4();
	VOID GameDrawAutomap();
	VOID WinDraw();

	INT GetScreenSizeX();
	INT GetScreenSizeX2();
	INT GetScreenSizeY();
	INT GetScreenSizeY2();

	VOID DrawOut(INT X, INT Y, INT Color, INT Size, LPSTR Format, ...);
	BOOL DrawOutCenter(INT xPos, INT yPos, DWORD dwColor, DWORD dwSize, DWORD dwDiv, LPSTR lpFormat, ...);
	VOID TextHook(INT X, INT Y, DWORD Color, BOOL Automap, INT Font, INT Center, LPSTR Text, ...);

	BOOL ClearScreen(INT Screen);
	VOID ScreenToAutoMap(LPPOINT Point);
	VOID ScreenToAutomap(LPPOINT Position, INT X, INT Y);

	BOOL CharacterStats;
	BOOL Hide;

protected:

	BOOL UIDash();
	BOOL GoldMeter();
	BOOL ExpMeter();
	BOOL LifeDots();

	BOOL AutomapInfo();
	BOOL EscapeInfo();
	BOOL ExperienceInfo();
	BOOL PotionInfo();

	BOOL Missiles();
	BOOL Monsters();

	BOOL MusicPlayer();

	BOOL Orbs();
	BOOL PlayerLifePercent();
	BOOL States();

	BOOL Stats();
	BOOL Ability();
	BOOL Guide();
	BOOL Settings();

	BOOL Targets();
	BOOL Vectors();

	VOID BoxHook(INT X, INT Y, INT XSize, INT YSize, DWORD Color, DWORD Transparency, BOOL Automap);
	VOID DrawBox(INT X1, INT Y1, INT X2, INT Y2, INT LineColor, INT BackGroundColor, INT Transparency);

	VOID DrawCross(INT X, INT Y, DWORD Color, BOOL Automap);
	VOID DrawDot(INT X, INT Y, INT DotColor, INT Type);

	BOOL DrawGMTag();
	BOOL DrawGMTag2();
	BOOL DrawGMTag2Lazarus();

	VOID GetPlayerPosition(LPPOINT Player);
	VOID MapToScreenCoords(LPPOINT Position);

	VOID Rectangle(INT X, INT Y, INT X2, INT Y2, INT Color, INT Transparency);
	VOID Frame(INT X, INT Y, INT X2, INT Y2);

	VOID ScreenToAutomapRelative(LPPOINT ptPos, INT x, INT y);

	BOOL MenuButton();

	BOOL MenuStatButton();
	BOOL MenuInfoButton();
	BOOL MenuMissionButton();
	BOOL MenuAbilityButton();
	BOOL MenuGuideButton();
	BOOL MenuCalcButton();
	BOOL MenuSettingButton();

	BOOL MenuMiniPanel();

	VOID DrawMenuFrame(INT X, INT Y, INT SizeX, INT SizeY, INT FrameColor);
	VOID DrawClassBlock(INT X, INT Y);

	VOID AdvanceClasses();
	VOID AdvanceClassesLazarus();

	BOOL PlayerInfoMenu();
	BOOL SideQuestsMenu();
};
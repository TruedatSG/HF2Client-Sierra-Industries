#define	PRIMARY			1
#define	SECONDARY		2
#define DELAYCLICK		3
#define IGNORECLICK		4
#define CLOSEMENU		5
#define GETKEY			6
#define CHECKKEY		7
#define COUNTER			8
#define COUNTER2		9
#define COUNTER3		10
#define COUNTER4		11
#define AUTOBOT			12
#define AUTOSAVE		13
#define LADDERSAVE		15
#define LADDERAUTOSAVE	14
#define LADDERWATCH		16
#define TIMECLOCK		17
#define	DESIGN			18
#define	ENCHANT			19
#define	PACKETS			20
#define PARTY			21
#define TELEPORT		22
#define LOBBYDELAY		23
#define MOVEKEYS		24
#define MOVEPAD			26
#define VIBRATEPAD		27
#define VIBRATEPAD2		28
#define KEYITEMS		29
#define AUTOLOGOUT		30
#define GOA5			31
#define GIVEA5			32
#define GETA5			33

#define REGISTRY		0

typedef struct Thread_t
{
	HANDLE Handle;
	DWORD ID;
} THREAD, *LPTHREAD;

BOOL STDCALL Threads(LPVOID Parameter);
HANDLE MakeThread(LPVOID Process, LPVOID Parameter);
VOID DestroyThread(HANDLE Thread, DWORD Parameter, DWORD MaxWaitTime);

VOID CreateInGameThreads();
VOID DestroyInGameThreads();
#define BOOLEAN		1
#define INTEGER		2
#define STRING		3

struct CONFIGURATION
{
	LPCSTR Section;
	LPCSTR Name;
	LPCSTR Default;
	INT Type;
	LPVOID Variable;
};

BOOL Bool(LPSTR Value);
INT Integer(LPSTR Value);
INT64 Integer64(LPSTR Value);
BOOL Load();
BOOL Save();
VOID GetModuleDirectory();
VOID WritePrivateProfileIntA(LPCSTR Section, LPCSTR Entry, INT Value, LPCSTR Filename);
VOID WritePrivateProfileInt64A(LPCSTR Section, LPCSTR Entry, INT64 Value, LPCSTR Filename);

BOOL PreloadSettings();
BOOL LoadStr();

BOOL LoadPlugY();
BOOL SavePlugY();
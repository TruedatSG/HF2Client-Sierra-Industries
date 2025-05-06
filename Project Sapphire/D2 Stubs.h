DWORD FASTCALL DrawRectangleFrameSTUB(RECT * Rectangle);
DWORD FASTCALL GetInventoryIDSTUB(LPUNITANY Unit, DWORD ID, DWORD Unknown);
DWORD FASTCALL GetUIVarSTUB(DWORD UI);
DWORD FASTCALL GetUnitNameSTUB(DWORD Unit);
DWORD FASTCALL GetUnitSTUB(DWORD dwUnitId, DWORD dwUnitType);
DWORD FASTCALL InitAutomapLayerSTUB(DWORD dwLayer);
DWORD FASTCALL LoadUIImage(LPSTR szPath);
DWORD FASTCALL TestPvPFlagSTUB(DWORD Argument1, DWORD Argument2, DWORD Flag);

//void* __stdcall D2WIN_LoadMpq(DWORD OrderFlag, const char* szDllFile, const char* szMpqFile, const char* szName, DWORD _1, BOOL(__stdcall *fnMPQMissing)());
void __fastcall D2CLIENT_PlaySound(int SoundNo);

void __stdcall D2CLIENT_TakeWaypoint(DWORD dwWaypointId, DWORD dwArea);
#ifndef __EXEXTLVLS_H__
#define __EXEXTLVLS_H__

namespace ExExtendedLevels
{
	DWORD __stdcall GetActByLevelNo(DWORD nLevel);
	BYTE __fastcall GetActByLevelNo_STUB1(DWORD nLevel);
	BYTE __fastcall GetActByLevelNo_STUB2(DWORD nLevel);
	BYTE __fastcall GetActByLevel(Level* pLevel);
	BYTE __fastcall GetActByRoom2(int _1, Room2* pRoom2);	
}
VOID ExtLevelsPatch();

#endif

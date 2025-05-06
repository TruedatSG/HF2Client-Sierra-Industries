#include "Hack.h"

///////////////////////////
// Hashing Formula:
//
// Pick a number inbetween LOSTKEYS through NUMOFKEYS
// Multiply by KEYNUM
// Add LOCKNUM
// Add THOBNUM
//
// Credits to Ruby.
////////////
BOOL EnterCDKey(INT Entry)
{
	for (INT Key = 0; Key < NUMOFKEYS; Key++)
	{
		if(Key >= (NUMOFKEYS - LOSTKEYS))
			break;

		if(Entry == V_CDKey[Key])
		{
			V_Registered = TRUE;

			break;
		}
	}

	return TRUE;
}

BOOL CheckCDKey()
{
	for (INT Key = 0; Key < NUMOFKEYS; Key++)
	{
		if(Key >= NUMOFKEYS)
			break;

		if(V_Key == V_CDKey[Key])
		{
			V_Registered = TRUE;

			break;
		}
	}

	return TRUE;
}

BOOL LoadCDKeys()
{
	for (INT Key = LOSTKEYS; Key < NUMOFKEYS; Key++)
	{
		if(Key >= NUMOFKEYS)
			break;

		INT KEYROOT = KEYNUM * Key; 
		INT KEYHASH = (KEYROOT + LOCKNUM) + THOBNUM;
		if(MAKEIDS == 1)
		{
			KEYHASH = KEYROOT;
		}

		INT j = Key - LOSTKEYS;
		V_CDKey[j] = KEYHASH;
	}

	return TRUE;
}

VOID MakeKeys()
{
	CHAR File[MAX_PATH], Log[200];

	strncpy_s(File, sizeof(File), V_FileNamePath, sizeof(File));

	if(MAKEIDS == 1)
	{
		strcat_s(File, "\\ID List.txt");
	}
	else
	{
		strcat_s(File, "\\CDKey List.txt");
	}

	for (INT Key = LOSTKEYS; Key < NUMOFKEYS; Key++)
	{
		if(Key >= NUMOFKEYS)
			break;

		INT KEYROOT = KEYNUM * Key; 

		INT KEYHASH = (KEYROOT + LOCKNUM) + THOBNUM;

		if(MAKEIDS)
		{
			KEYHASH = KEYROOT;
		}

		INT KEY = (Key - LOSTKEYS) + 1;

		sprintf_s(Log, "[%d]%d ", KEY, KEYHASH);

		FILE * ListKeys;
		ListKeys = fopen(File, "a");

		if (ListKeys)
		{
			fputs(Log, ListKeys);
			fclose(ListKeys);

			Log[0] = NULL;
		}
	}
}
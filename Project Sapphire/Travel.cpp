#include "Hack.h"
#include "Vars.h"

BOOL TravelGoA5()
{	
	if(V_BusyThread)
	{
		Print(0, 4, "ÿc0Busy performing task.");

		return FALSE;
	}
	V_BusyThread = TRUE;

	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)GOA5));

	return TRUE;
}

BOOL TravelGiveA5()
{
	if(V_BusyThread)
	{
		Print(0, 4, "ÿc0Busy performing task.");

		return FALSE;
	}
	V_BusyThread = TRUE;

	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)GIVEA5));





	return TRUE;
}

BOOL TravelGetA5()
{
	if(V_BusyThread)
	{
		Print(0, 4, "ÿc0Busy performing task.");

		return FALSE;
	}
	V_BusyThread = TRUE;

	V_Threads.Add(MakeThread((LPVOID)Threads, (LPVOID)GETA5));

	return TRUE;
}
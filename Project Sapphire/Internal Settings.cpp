#include "Hack.h"

VOID SetInternals() {
	////////////////////////////////////////////////////
	//
	//
	//		Ruby Internal Settings
	//
	//
	////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////
	//	Hellfire Expansion Settings
	//
	//		Expansion Packs:
	//			Type 0 (Expansion I)
	//				0A - Lord of Destruction
	//				0B - Ruby Dreams
	//				0C - Wings of the Goddess
	//				0D - Origins of Silence
	/////////////////////////////////////////////////////////
	V_CEXPANSION = 0;

	////////////
	//	Options
	////////////////////////////
	V_CINTERNALSETTINGS = TRUE; //View packet information in some modules
	V_CHIDEHACKMENU = TRUE; //Hide hack information from help menu
	V_CENABLEDOTHACK = TRUE; //Enable use of .hack commands
	V_CDIRECT3D = FALSE; //Make design adjustments for Direct3D
}
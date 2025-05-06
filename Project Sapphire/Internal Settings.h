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
//				0.0 - Lord of Destruction
//				0.1 - Ruby Dreams
//				0.2 - Wings of the Goddess
//				0.3 - Origins of Silence
/////////////////////////////////////////////////////////
#define EXPANSIONTYPE					0		//Expansion set Type
#define EXPANSIONPACK					3		//Number of the expansion pack

////////////
//	Options
////////////////////////////
#define DIRECT3DSUPPORT					1		//Make design adjustments for Direct3D, set to 1 to turn DIRECT3D support ON

///////
//Save
/////////////////
#define SAVEPATHLOD						"\\Save\\HF2Lod Beta\\"		//Save path for character save files for different expansions
#define SAVEPATHPRD						"\\Save\\HF2Prd Beta\\"
#define SAVEPATHWOTG					"\\Save\\HF2Wotg Beta\\"
#define SAVEPATHOOS						"\\Save\\HF2Oos Beta\\"

////////
//Client
///
//Main
#define HACKRUBY						"Project Sapphire for Hellfire II|"		//Load .hack core library under this name
#define BUILDNO							2331				//This expanded .hack library's build number to display												
#define CLIENTVERSION					"v2.9.3 Beta"		//Client/Scripts version to display on the main menu
															//Decimals - Expansion.Release.Update															

#define DATAUPDATE						8					//Update tag variables to auto-update data structure in expandedsave files 
															//See interface\\data\\default.ini

//Exit
#define KILLPROCESS						0					//Kill process after each game? (0 - No, 1 - Yes)
//Delays
#define DELAYLOAD						500					//Load delay in milliseconds to patch when entering a new game
#define DELAYADD						5000				//Delay in milliseconds to switch the unregistered customer service advertisement

////////
//Design
///
//Colors
#define GOLDMETERCOLOR					13			//Change Currency Color.  COLORS: 7 - Brown, 10 - Red, 13 - Gold, 86 - Orange, 111 - Yellow, 132 - Green
#define	UILARGEEXPBOX					1			//Set to 1 to remove the Rejuv. box and create a larger Exp. box on the UI Dash making room for large integers
#define ADVANCECLASSES					1			//Set to 1 to display Advance Classes in the Character UI
#define RESETEXPCALC					1			//Set to 1 to reset experience calculator each game
#define RESETGOLDCALC					1			//Set to 1 to reset gold calculator each game

//Menu
#define TitleTextX						398			//Do NOT edit.
#define TitleTextY						51			//X, Y Cords for Scripts and Game data menu features 

#define TextBX							393
#define TextBY							486
#define MouseOverX1						369
#define MouseOverY1						474
#define MouseOverX2						415
#define MouseOverY2						486

#define PlayerInfoTextStrLX				15
#define PlayerInfoTextStrRX				405

#define PlayerInfoTextStrNextX			732

#define PlayerInfoTextStr1Y				85
#define PlayerInfoTextStr2Y				102
#define PlayerInfoTextStr3Y				119
#define PlayerInfoTextStr4Y				136
#define PlayerInfoTextStr5Y				153
#define PlayerInfoTextStr6Y				170
#define PlayerInfoTextStr7Y				187
#define PlayerInfoTextStr8Y				204
#define PlayerInfoTextStr9Y				221
#define PlayerInfoTextStr10Y			238
#define PlayerInfoTextStr11Y			255
#define PlayerInfoTextStr12Y			272
#define PlayerInfoTextStr13Y			289
#define PlayerInfoTextStr14Y			306
#define PlayerInfoTextStr15Y			323
#define PlayerInfoTextStr16Y			340
#define PlayerInfoTextStr17Y			357
#define PlayerInfoTextStr18Y			374
#define PlayerInfoTextStr19Y			391
#define PlayerInfoTextStr20Y			408
#define PlayerInfoTextStr21Y			425
#define PlayerInfoTextStr22Y			442
#define PlayerInfoTextStr23Y			459

#define PlayerInfoBackStrY 				442
#define PlayerInfoNextStrY				459

#define MouseOverX1L					15
#define MouseOverX2L					395

#define MouseOverY1L1					73
#define MouseOverY1L2					90
#define MouseOverY1L3					107
#define MouseOverY1L4					124
#define MouseOverY1L5					141
#define MouseOverY1L6					158
#define MouseOverY1L7					175
#define MouseOverY1L8					192
#define MouseOverY1L9					209
#define MouseOverY1L10					226
#define MouseOverY1L11					243
#define MouseOverY1L12					260
#define MouseOverY1L13					277
#define MouseOverY1L14					294
#define MouseOverY1L15					311
#define MouseOverY1L16					328
#define MouseOverY1L17					345
#define MouseOverY1L18					362
#define MouseOverY1L19					379
#define MouseOverY1L20					396

#define MouseOverY2L1					85
#define MouseOverY2L2					102
#define MouseOverY2L3					119
#define MouseOverY2L4					136
#define MouseOverY2L5					153
#define MouseOverY2L6					170
#define MouseOverY2L7					187
#define MouseOverY2L8					204
#define MouseOverY2L9					221
#define MouseOverY2L10					238
#define MouseOverY2L11					255
#define MouseOverY2L12					272
#define MouseOverY2L13					289
#define MouseOverY2L14					306
#define MouseOverY2L15					323
#define MouseOverY2L16					340
#define MouseOverY2L17					357
#define MouseOverY2L18					374
#define MouseOverY2L19					391
#define MouseOverY2L20					408

#define MouseOverY1LBack				430
#define MouseOverY2LBack				442

#define MouseOverY1LNext				447
#define MouseOverY2LNext				459

#define MouseOverX1BackText				405
#define MouseOverY1BackText				447
#define MouseOverX2BackText				455
#define MouseOverY2BackText				459

#define MouseOverX1NextText				732
#define MouseOverY1NextText				447
#define MouseOverX2NextText				782
#define MouseOverY2NextText				459

/////////
//Counter
////
#define MAXMONSTERS						1000			//Number of monsters to register from the monstats.txt file
#define MAXCLASSES						20				//Number of extra character classes in the D2Non expansions
#define MAXIGNORE						17476			//Maximum amount of units to ignore

///////////
//Key Items
/////
#define KEYITEMS						27			//Number of Key Items

/////////
//Threads
////
//Delays
#define LOOPDELAY						1			//Loop delay
#define CLICKDELAY						250			//Click delay
#define MENUCLOSEDELAY					350			//Close Menu delay
#define SECONDSDELAY					999			//One Second delay
#define CALCDELAY						1000		//Calculate distance delay
#define CALCGOLDDELAY					3000		//Calculate distance delay
#define SAVEDELAY						360000		//Auto save delay
#define MESSAGEDELAY					10000		//Message fade delay

//////////////
//Registration
//////
//CDKeys
#define NUMOFKEYS						32768		//Number of keys to create
#define LOSTKEYS						1357		//Number to keys to subtract from the total number of keys, a higher number will make the key value higher
#define KEYNUM							937			//Key base multiplier
#define LOCKNUM							10569483	//Integer added to the user ID to create a new key
#define THOBNUM							13			//Additional added to the user ID to create a unique key

//////////
//GM Stuff
/////
//Main
#define LEGITMAP						0			// Do not use reveal features.  Yes or no?  1 - Yes, 0 - No
#define LEGITSPEED						0			// Do not use speedhack, Yes or no?  1 - Yes, 0 - No.
//Design
#define GMNAME							"Thunderer"		//Name of the GM
#define	GMNAMEOFFSETX					12			//Move your name to the side to make room for the GM flag
//Keymaker
#define KEYMAKER						0			//Set to 1 to turn ON the keymaker
#define MAKEIDS							0			//Set to 1 to print list IDs
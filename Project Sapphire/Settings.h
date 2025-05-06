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
//				0.4 - From a Grace Fallen
//				0.5 - Guild Pact
//				0.6 - A New Hope
//				0.7 - Sands of Calypso
/////////////////////////////////////////////////////////
#define EXPANSIONTYPE					0		//Expansion set Type
#define EXPANSIONPACK					7		//Number of the expansion pack

//#define LAZARUSMOD								//Modify input for Lazarus

//#define DEBUGKEYITEMS							//Enable all key items for all expansions
//#define FFXIVMOD								//Modify input for Final Fantasy XIV
#define MODWINDOW								//Change the window settings for FFXIV, removes boarder and character creation


#define LANMPMODE								//Rigs things to work on LAN when packets won't work

#define MODMAXLEVEL						99		//Maximum level that can be attained

//#define EXTLEVELS								//NOT TESTED Extend maximum number of areas to 255
//#define NOWILDERNESSMENU						//Can't use menu outside of town

//#define COLOREXPNAMETAG							//Color the nametag of expansion characters

#define ANTIQUESTBOX							//Hide the quest box

////////////
//	Options
////////////////////////////
#define DIRECT3DSUPPORT					1		//Make design adjustments for Direct3D, set to 1 to turn DIRECT3D support ON

////////
//Client
///
//Main
#define	SAVEPATH						"Save\\Beta2\\"
#define DATAUPDATE						15					//Update tag variables to auto-update data structure in expandedsave files 
															//See interface\\data\\default.ini

//#define DIRECTIONALINPUT								//Use keys to move character
#define XINPUT										//Use XBOX 360 controller to move
#define POINTERSPEED						15			//Speed of mouse pointer reiteration. Do not edit
#define POINTERDIST							3			//Distance moved by mouse pointer
#define POINTERDISTADD						15			//Increase distance moved of mouse pointer by how much

//Exit
#define EXITWHENIDLE									//Exit game when idle for too long
#define MAXIDLETIME						60				//Exit game after how long

#define KILLPROCESS						1					//Kill process after each game? (0 - No, 1 - Yes)

//Delays
#define DELAYLOAD						1000				//Load delay in milliseconds to patch when entering a new game
#define DELAYAD							5000				//Delay in milliseconds to switch the unregistered customer service advertisement

#define DELAYLOBBY						0				//Amount of time to pause in the lobby

//Ratings
#define LOSERANK										//Players will lose ranks depending on win/loss rating
#define GAMEDRAWMIN						30				//Game Draw after how long
#define GAMEWINMIN						120				//Game Win after how long

#define GAMESWONFACTOR					3				//Multiply win rating by. Default 3
#define GAMESLOSTFACTOR					10				//Multiply loss rating by.  Default 5
#define GAMESDRAWFACTOR					1				//Multiply draw rating by.  Default 1

/////////
//Counter
////
#define MAXMONSTERS						1000			//Number of monsters to register from the monstats.txt file
#define MAXCLASSES						23				//Number of extra character classes in the D2Non expansions
#define MAXIGNORE						17476			//Maximum amount of units to ignore

#define MAXLADDER						1000			//Maximum players on the ladder.  Do not edit

///////////
//Key Items
/////
#define MAXKEYITEMS						40			//Number of Key Items per list

													//Time in minutes to interact with NPC
#define KEYITEMSWARRIVMIN				15			
#define KEYITEMSGEGLASHMIN				120
#define KEYITEMSHALBUMIN				30
#define KEYITEMSAKARAMIN				60
#define KEYITEMSJAMELLAMIN				45

/////////
//Threads
////
//Delays
#define LOOPDELAY						1			//Loop delay
#define CLICKDELAY						250			//Click map delay before clicking again
#define MENUCLICKDELAY					1000		//Click menu delay
#define MENUCLOSEDELAY					350			//Close Menu delay
#define SECONDSDELAY					999			//One Second delay
#define CALCDELAY						1000		//Calculate distance delay
#define CALCGOLDDELAY					550			//Calculate gold delay
#define SAVEDELAY						300000		//Auto save delay
#define SAVEDELAYLADDER					600000		//Auto save delay ladder
#define EXITDELAYLADDER					3000		//Delay intervals exiting game if ladder is busy
#define MESSAGEDELAY					10000		//Message fade delay
#define BUTTONDELAY						200			//Gamepad button delay

#define REITERATEDELAY					25			//How many times to delay exiting game.  Max 25			

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
#define	GMTAGX							527		//Location of the GM tag. Default 527 for Thunderer, 535 for Shikari
#define	GMTAGX2							121			//Location of the GM tag. Default 121 for Thunderer, 135 for Shikari
#define	GMNAMEOFFSETX					12			//Move your name to the side to make room for the GM flag. Default 12 for Thunderer, 0 for Shikari
//Keymaker
#define KEYMAKER						0			//Set to 1 to turn ON the keymaker
#define MAKEIDS							0			//Set to 1 to print list IDs

////////
//UI Design
///
//Colors
#define GOLDMETERCOLOR					13			//Change Gold Color.  COLORS: 7 - Brown, 10 - Red, 13 - Gold, 86 - Orange, 111 - Yellow, 132 - Green
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

#define TextBX2							215
#define TextBY2							92
#define MouseOverX1X1					216
#define MouseOverY1X1					81
#define MouseOverX2X1					223
#define MouseOverY2X1					97

#define TextBX3							785
#define TextBY3							72
#define MouseOverX1X2					786
#define MouseOverY1X2					61
#define MouseOverX2X2					793
#define MouseOverY2X2					77

#define TextBX4							18
#define TextBY4							57
#define MouseOverX1X3					19
#define MouseOverY1X3					46
#define MouseOverX2X3					26
#define MouseOverY2X3					62

#define TextBX5							86
#define TextBY5							57
#define MouseOverX1X4					87
#define MouseOverY1X4					46
#define MouseOverX2X4					93
#define MouseOverY2X4					62

#define TextBX6							53
#define TextBY6							57

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
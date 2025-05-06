#ifndef _XBOX_CONTROLLER_H_
#define _XBOX_CONTROLLER_H_

/*
typedef struct _XINPUT_GAMEPAD {
	WORD wButtons;
	BYTE bLeftTrigger;
	BYTE bRightTrigger;
	SHORT sThumbLX;
	SHORT sThumbLY;
	SHORT sThumbRX;
	SHORT sThumbRY;
} XINPUT_GAMEPAD, *PXINPUT_GAMEPAD;
*/

class CXBOXController
{
private:
	XINPUT_STATE _controllerState;
	int _controllerNum;
public:
	CXBOXController(int playerNumber);
	XINPUT_STATE GetState();
	bool IsConnected();

	void Vibrate(float leftmotor = 0.0f, float rightmotor = 0.0f);
};

#endif
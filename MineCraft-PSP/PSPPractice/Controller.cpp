// Author: Mouhamad Abdallah	(Slightly modified by David Kilford)
// Date: 29 December 2010		(Modified 7th February 2011)
// Modifications: All modifications are documented via Repository on google-code page

#include "Controller.h" // Header File of 'Controller' Class
#include <pspctrl.h> // Header File of PSP controls Library

int count=0;

Controller::Controller()
{
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);	//Enable joystick updates
}

bool Controller::isKeyDown(unsigned int key) // Method which returns true or false after giving it a key to check for (e.g. PSP_CTRL_LEFT)
{
	if(pad.Buttons & key)
		return true;
	else return false;
}

void Controller::updateController() // Method which is required to update the psp to read the current keys state
{
	sceCtrlReadBufferPositive(&pad, 1);
}
int  Controller::getJoystickX()
{
	return pad.Lx;
}
int  Controller::getJoystickY()
{
	return pad.Ly;
}
#include "Controller.h" // Header File of 'Controller' Class
#include <pspctrl.h> // Header File of PSP controls Library

Controller::Controller() // Empty Constructor
{

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
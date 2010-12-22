#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <pspctrl.h> // Header File of PSP controls Library
#include <stdbool.h> // Header File for Standard library to include booleans

class Controller
{
	private:
		SceCtrlData pad; // Object which contains the variables associated with the control pads data including their key state

	public:
		Controller(); // Empty constructor

		void updateController(); // Method to update state of key pad
		bool isKeyDown(unsigned int key); //Method to check for a certain key press
};

#endif
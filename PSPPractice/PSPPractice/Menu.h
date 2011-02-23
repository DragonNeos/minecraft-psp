//Author:		David Kilford
//Date:			25th January 2011
//Description:	Header file for the menu loop

#include <stdlib.h>		// needed in order to have "exit" function @@@
#include "GLLib.h"		//Header file for OpenGL library
#include "Display.h"	// Header File for Display class which encapsulates OpenGL

class Menu
{
public:

	Menu(int state);					//Takes in a state so it knows what to display
	void displayMenu();					//Holds main display loop for the menu
	int getButton();					//returns where the button is
	int getMenuState();					//Returns the curren menu state
	void setButton(int button);			//Changes the button to a certain point
	void selectButton(int button);		//Selects the button and follows an action depending on which button it was
};
//Author:		David Kilford
//Date:			25th January 2011
//Description:	Class for the menu

#include <stdlib.h>		// Needed in order to have "exit" function @@@
#include "GLLib.h"		// Header file for OpenGL library
#include "Display.h"	// Header File for Display class which encapsulates OpenGL
#include "Menu.h"		// Header file for the menu class
#include "Texture.h"	// Header file for the texture class
#include "Display.h"	// Header file for the display class
#include "Controller.h"

	int currentButton=1;	
	bool upPushed = false;
	bool downPushed = false;


	Menu::Menu(int state)
	{
		int menuState = state;
	}

	void Menu::displayMenu()
	{
		//Loading the menu texture
		printf("Display menu start\n");
		Texture *menuTexture = new Texture();
		menuTexture->loadTexture("Data/menu.png");
		printf("Display menu textures loaded\n");

		Display display; //= new Display();			//Instantiate the graphics class via dynamic memory allocation
		printf("Display menu display loaded\n");
		Controller controller;// = new Controller();  //Instantiate the controls class via dynamic memory allocation

		while(1)
		{
			controller.updateController();			//Update the keystates of the control pad
			display.clearBuffers();					//Clear screen and depth buffer
			display.resetOrigin();					//Reset the co-ordinate origin

			if(controller.isKeyDown(PSP_CTRL_DOWN)) //Check for down to move the current button down, checks in place so it only moves 1 space per press
			{
				if(upPushed==false)
				{
					upPushed==true;
					if(currentButton==1)
					{
						currentButton=4;
					}
					else
					{
						currentButton--;
					}
				}
			}
			else
			{
				upPushed=false;
			}

			if(controller.isKeyDown(PSP_CTRL_UP))	//Check for down to move the current button up, checks in place so it only moves 1 space per press
			{
				if(downPushed==false)
				{
					downPushed==true;
					if(currentButton==4)
					{
						currentButton=1;
					}
					else
					{
						currentButton++;
					}
				}

			}
			else
			{
				downPushed=false;
			}

			glBegin(GL_QUADS);

			glColor3f(1, 1, 1);

			//Background
			glTexCoord2f(0.9375,		0);							glVertex3f( 1,   1, -0.12); //Top-Right Corner
			glTexCoord2f(0,				0);							glVertex3f(-1,   1, -0.12); //Top-Left Corner
			glTexCoord2f(0,		  0.53125);							glVertex3f(-1,  -1, -0.12); //Bottom-Left Corner
			glTexCoord2f(0.9375,  0.53125);							glVertex3f( 1,  -1, -0.12); //Bottom-Right Corner

			glEnd();

			display.update(); //Update the display buffer(i.e. swap the buffer)
		}
	}
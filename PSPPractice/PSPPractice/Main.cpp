// Author:			Mouhamad Abdallah & David Kilford
// Date:			29 December 2010
// Modifications:	All modifications are documented via Repository on google-code page
//
// -- THIS IS STILL PRACTICE CODE USED TO PRACTICE THE IMPLEMENTATION OF FEATURES FOR MINECRAFT-PSP --
// 

#include <stdlib.h>			// Header file for standard library
#include <stdio.h>			// Header file for file IO
#include <pspctrl.h>		// Header file for the PSP's control library
#include <string.h>			// Header file for c string methods
#include <math.h>			// Header file for trig methods
#include "GLLib.h"			// Header file carrying all OpenGL32 and GLUT headers
#include "Display.h"		// Header file For the 'Display' class
#include "World.h"			// Header file for the 'Cube' class
#include "Controller.h"		// Header file for the 'Controller' class
#include "Texture.h"		// Header file for the 'Texture' class
#include "WorldManager.h"	// Header file for the 'WorldManager" class
#include "Inventory.h"		// Header file for the 'Inventory' class
//#include "Menu.h"			// Header file for the 'Menu' class


int worldSize, blockSize, blockNumber;
World *world;
Texture *worldTexture;
Inventory *inventory;
#define PI 3.14159265

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // The only method call that as of yet needs the command line arguments to initialise GLUT

	float x = 0,y = 0, z = 0, rotation = 0, worldR = 0; //Position variables of the cube
	float yRotation = 0, xRotation = 0, zRotation = 0;	//Rotation amounts for each axis
	float xRotationAmount = 1, zRotationAmount = 0;		//Vars to remove axis rotation problems

	worldSize = 6; //Size of the WorldArray in terms of amount of blocks per Dimension
	blockSize = 4; //Size of blocks dimension(x,y,z)
	blockNumber = 0;
	WorldManager worldManager;

	int selectedItem=1;
	bool displayInventory = false;	//Bool that holds whether to display the inventory or not.
	bool trianglePreviouslyPressed = false; //Bool so it doesn't keep on flicking the inventory up and down.
	bool rPreviouslyPressed = false;
	bool lPreviouslyPressed = false;

	Display *display = new Display();			//Instantiate the graphics class via dynamic memory allocation
	Controller *controller = new Controller();  //Instantiate the controls class via dynamic memory allocation
	world = new World();						//Instantiate the World class via dynamic memory allocation

	display->initialise();	 //Initialises all OpenGL requirements and creates a viewport
	display->enableTextures(); //Enable Texturing
	display->enableTransparency(); //Enable basic transperancy
	//display->enableCulling();
	//display->cullBack();
	
	worldTexture = new Texture(); //Instantiate Textures of the world
	
	worldTexture->loadTexture("Data/texture.png"); //load the texture image used in the world
	
	printf("Loading World\n");
	worldManager.loadWorld("Saves/world.txt", worldSize);
	printf("World Loaded\n");

	printf("Initialising Inventory\n");
	int *itemIDArray;
	itemIDArray = new int[9];

	for (int i = 0; i<9; i++)		//Filling array with junk data for testing
	{
		itemIDArray[i] = i;
	}

	inventory = new Inventory(itemIDArray);		//Passing the reference to the array over to inventory
	printf("Inventory Initialised\n");

	world->initialiseWorld(worldSize, blockSize, worldManager.blockID); // Startup and populate the world with reference to the saveFiles 'blockID' Array

	worldTexture->bindTexture(); //Bind all the world's textures to every object after this line (Binding is no longer repeated and no overhead occurs)

	while(1)
	{
		controller->updateController(); //Update the keystates of the control pad

		display->clearBuffers(); //Clear screen and depth buffer
		display->resetOrigin(); //Reset the co-ordinate origin

		inventory -> displayInventory();

		display->translate(0, 0, -80); //Push the scene inside of the viewport frustum

		//Rotate the world according to the joystick
		//display->translate(x,y,z);//Move the 'world' around in the view

		//Names may be confusing, to generate a change on the 'y' axis you rotation around x, vise versa
		display->rotate(yRotation, 0, 1, 0);	
		//Changes the axis of rotation depending on how much the y-axis is rotated so it always rotates up or down from the frustum's point of view
		//Because cos and sin constantly move between 0 and 1 every 180 degrees you can work out how much the world should be rotating around x and z
		display->rotate(xRotation, cos(yRotation*PI/180), 0, sin(yRotation*PI/180));

		if(controller->isKeyDown(PSP_CTRL_LEFT)) //Check for left press to move the world
		{
			//x -= 4;
			//if(x < 0)
			//	x = worldSize;
		}
		if(controller->isKeyDown(PSP_CTRL_RIGHT)) //Check for right press to move the world
		{
			x += 1;
			if(x > worldSize-1)
				x = 0;
		}
		if(controller->isKeyDown(PSP_CTRL_DOWN)) //Check for down press to move the world
		{
			//y -= 4;
			//if(y < 0)
			//	y = worldSize;
		}
		if(controller->isKeyDown(PSP_CTRL_UP)) //Check for up press to move the world
		{
			y += 1;
			if(y > worldSize-1)
				y = 0;
		}

		//Joystick controls
		if(controller->getJoystickX()>143)
		{
			if(yRotation>=360) yRotation-=360;		//Check so that rotation doesn't get too low
			yRotation+=(controller->getJoystickX()-143)/25;
			printf("Right Joystick: %d\n", controller->getJoystickX());
		}

		if(controller->getJoystickX()<111)
		{
			if(yRotation<=-360) yRotation+=360;		//Check so that rotation doesn't get too low
			yRotation+=(controller->getJoystickX()-111)/25;
			printf("Left Joystick: %d\n", controller->getJoystickX());
		}

		if(controller->getJoystickY()>143)
		{
			xRotation+=(controller->getJoystickY()-143)/25;
			printf("Down Joystick: %d\n", controller->getJoystickY());
		}

		if(controller->getJoystickY()<111)
		{
			xRotation+=(controller->getJoystickY()-111)/25;
			printf("Up Joystick: %d\n", controller->getJoystickY());
		}

		if(controller->isKeyDown(PSP_CTRL_LTRIGGER)) //Check for LTrigger press to control the zoom of the world
		{
			if (displayInventory==false)
			{
				//z -= 4;
			}
			else if (lPreviouslyPressed==false)
			{
				lPreviouslyPressed=true;
				if (selectedItem==1)
				{
					selectedItem=9;
					inventory ->setInventoryNumber(9);
				}
				else
				{
				selectedItem--;
				inventory ->setInventoryNumber(selectedItem);
				}
			}
			else
			{
				lPreviouslyPressed=false;
			}
		}
		if(controller->isKeyDown(PSP_CTRL_RTRIGGER)) //Check for RTrigger press to control the zoom of the world
		{
			if (displayInventory==false)
			{
				//z += 4;
			}
			else if (rPreviouslyPressed==false)
			{
				rPreviouslyPressed=true;
				if (selectedItem==9)
				{
					selectedItem=1;
					inventory ->setInventoryNumber(1);
				}
				else
				{
				selectedItem++;
				inventory ->setInventoryNumber(selectedItem);
				}
			}
			else
			{
				rPreviouslyPressed=false;
			}
		}

		if(controller->isKeyDown(PSP_CTRL_CROSS)) //Check for 'x' press to rotate the individual blocks
		{
			printf("'X' pressed\n");
			world->changeBlock((int)x, (int)y, (int)z, 0);
		}
		if(controller->isKeyDown(PSP_CTRL_CIRCLE)) //Check for circle press to rotate world
		{
			printf("'O' pressed\n");
			world->changeBlock((int)x, (int)y, (int)z, inventory->getInventory());
		}

		if(controller->isKeyDown(PSP_CTRL_SQUARE)) //Check for circle press to rotate world
		{
			printf("'[]' pressed\n");
			z+=1;
			if(z > worldSize - 1)
				z = 0;
			/*yRotation = 0;
			xRotation = 0;
			zRotation = 0;*/
		}

		if(controller->isKeyDown(PSP_CTRL_TRIANGLE)) //Check for triangle to display inventory
		{
			printf("'/\' pressed\n");
			if (trianglePreviouslyPressed==false)
			{
				trianglePreviouslyPressed=true;

				//printf("Triangle Pressed\n");

				if (displayInventory==false)
				{
					printf("Displaying inventory\n");
					displayInventory=true;
				}
				else
				{
					printf("No longer displaying inventory\n");
					displayInventory=false;
				}
			}
		}
		else
		{
			trianglePreviouslyPressed=false;
		}

		
		display->rotate(worldR,0,1,0);//rotate the world around to see around it

		world->draw(); //Draw the world

		display->update(); //Update the display buffer(i.e. swap the buffer)
	}

	return 0;
}
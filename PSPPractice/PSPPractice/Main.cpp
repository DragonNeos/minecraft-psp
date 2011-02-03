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
#include "GLLib.h"			// Header file carrying all OpenGL32 and GLUT headers
#include "Display.h"		// Header file For the 'Display' class
#include "Triangle.h"		// Header file for the 'Triangle' class
#include "Cube.h"			// Header file for the 'Cube' class
#include "Controller.h"		// Header file for the 'Controller' class
#include "Texture.h"		// Header file for the 'Texture' class
#include "WorldManager.h"	// Header file for the 'WorldManager" class
#include "Inventory.h"		// Header file for the 'Inventory' class
//#include "Menu.h"			// Header file for the 'Menu' class


int worldSize, blockSize, blockNumber;
Cube ***world;
Texture *worldTexture;
Inventory *inventory;

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // The only method call that as of yet needs the command line arguments to initialise GLUT

	float x = 0,y = 0, z = 0, rotation = 0, worldR = 0; //Position variables of the cube
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
	
	display->initialise();	 //Initialises all OpenGL requirements and creates a viewport
	glEnable(GL_TEXTURE_2D); //Enable Texturing
	
	worldTexture = new Texture(); //Instantiate Textures of the world
	
	worldTexture->loadTexture("Data/texture.png"); ////load the texture image used in the world
	
	printf("Loading World\n");
	worldManager.loadWorld("Saves/world.txt", worldSize);
	//strcpy(buffer, saveGame.loadSaveGame("Saves/savegame.txt"));
	printf("World Loaded\n");
	//printf(buffer);

	printf("Initialising Inventory\n");
	int *itemIDArray;
	itemIDArray = new int[9];

	for (int i = 0; i<9; i++)		//Filling array with junk data for testing
	{
		itemIDArray[i] = i;
	}

	inventory = new Inventory(itemIDArray);		//Passing the reference to the array over to inventory
	printf("Inventory Initialised\n");


	//initialising a multi-dimensional array via dynamic memory allocation using pointers(Not used currently)
	//world = new Cube***[1]; //Initialise a dummy dimension which will simply act as a pointer to the 3D array(Not used currently)

	world = new Cube**[worldSize]; //Initialise the 1st Dimension
	for(int j = 0; j < worldSize; j++)
	{
		world[j] = new Cube*[worldSize]; //Initialise the 2nd Dimension
		for(int k = 0; k < worldSize; k ++)
		{
			world[j][k] = new Cube[worldSize]; //Initialise the 3rd Dimension
		}
	}

	for(int i = 0, y = 0; i < worldSize; i++, y += blockSize) //Initialise and dynamically allocate a 3D PointerArray new cube objects
	{
		for(int j = 0, z = 0; j < worldSize; j++, z+= blockSize)
		{
			for(int k = 0, x = 0; k < worldSize; k ++, x+=blockSize, blockNumber++)
			{
				world[i][j][k].createBlock(worldManager.blockID[blockNumber]); //Create the block based off it's type ID	
				world[i][j][k].initialise(blockSize, blockSize, blockSize); //Instantiate a new object and assign it via dynamic memory allocation
				world[i][j][k].position->set(x, y, z); //Position the cubes apart from each other in order of theyre relative co-ordinates in the array
			}
		}
	}

	worldTexture->bindTexture(); //Bind all the world's textures to every object after this line (Binding is no longer repeated and no overhead occurs)

	while(1)
	{
		controller->updateController(); //Update the keystates of the control pad

		display->clearBuffers(); //Clear screen and depth buffer
		display->resetOrigin(); //Reset the co-ordinate origin

		inventory -> displayInventory();

		display->translate(0,0,-50); //Push the scene inside of the viewport frustum

		if(controller->isKeyDown(PSP_CTRL_LEFT)) //Check for left press to move the world
		{
			x -= 4;
		}
		if(controller->isKeyDown(PSP_CTRL_RIGHT)) //Check for right press to move the world
		{
			x += 4;
		}
		if(controller->isKeyDown(PSP_CTRL_DOWN)) //Check for down press to move the world
		{
			y -= 4;
		}
		if(controller->isKeyDown(PSP_CTRL_UP)) //Check for up press to move the world
		{
			y += 4;
		}

		if(controller->isKeyDown(PSP_CTRL_LTRIGGER)) //Check for LTrigger press to control the zoom of the world
		{
			if (displayInventory==false)
			{
				z -= 2;
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
				z += 2;
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
			//printf("'X' pressed\n");
			rotation += 4;
		}
		if(controller->isKeyDown(PSP_CTRL_CIRCLE)) //Check for circle press to rotate world
		{
			worldR += 4;
		}

				if(controller->isKeyDown(PSP_CTRL_TRIANGLE)) //Check for triangle to display inventory
		{

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

		display->translate(x,y,z);//Move the 'world' around in the view
		display->rotate(worldR,0,1,0);//rotate the world around to see around it
		
		for(int i = 0; i < worldSize; i++)
		{
			for(int j = 0; j < worldSize; j++)
			{
				for(int k = 0; k < worldSize; k ++)
				{
					world[i][j][k].draw(rotation, 0, 1, 0);// Draw the 'World' array of cubes with rotation applied
				}
			}
		}

		display->update(); //Update the display buffer(i.e. swap the buffer)
	}

	return 0;
}
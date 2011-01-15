// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page
//
// -- THIS IS STILL PRACTICE CODE USED TO PRACTICE THE IMPLEMENTATION OF FEATURES FOR MINECRAFT-PSP --
// 

#include <stdlib.h>		// Header file for standard library
#include <stdio.h>		// Header file for file IO
#include <pspctrl.h>	// Header file for the PSP's control library
#include "GLLib.h"		// Header file carrying all OpenGL32 and GLUT headers
#include "Display.h"	// Header file For the 'Display' class
#include "Triangle.h"	// Header file for the 'Triangle' class
#include "Cube.h"		// Header file for the 'Cube' class
#include "Controller.h" // Header file for the 'Controller' class
#include "Texture.h"	// Header file for the 'Texture' class
#include "SaveGameIO.h" // Header file for the 'SaveGameIO" class
#include <string.h>

int worldSize, blockSize, blockNumber;
Cube ***world;
Texture *worldTexture;

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // The only method call that as of yet needs the command line arguments to initialise GLUT

	float x = 0,y = 0, z = 0, rotation = 0, worldR = 0; //Position variables of the cube
	worldSize = 6; //Size of the WorldArray in terms of amount of blocks per Dimension
	blockSize = 4; //Size of blocks dimension(x,y,z)
	blockNumber=0;
	
	Display *display = new Display();			//Instantiate the graphics class via dynamic memory allocation
	Controller *controller = new Controller();  //Instantiate the controls class via dynamic memory allocation
	//SaveGameIO *saveGameIO = new SaveGameIO();
	SaveGameIO saveGame;
	//char* testBuffer[];

	display->initialise(); //Initialises all OpenGL requirements and creates a viewport
	glEnable(GL_TEXTURE_2D); //Enable Texturing
	printf("Texture has been created\n");
	worldTexture = new Texture(); //Instantiate Textures of the world
	printf("Texture has been instantiated\n");
	worldTexture->loadTexture("Data/texture.png"); ////load the texture image used in the world
	printf("Texture has been loaded\n");

	char buffer[80];
	printf("Loading savegame and inserting it into buffer\n");
	strcpy(buffer, saveGame.loadSaveGame("Saves/savegame.txt"));
	printf("Savegame Loaded\n");
	//printf(buffer);


	//char &bufferContents = buffer[];
	//printf("Savegame =");
	//printf("\n");
	//printf(buffer);
	//printf("\n");

	//printf("\n");
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

	for(int i = 0, x = 0; i < worldSize; i++, x += blockSize) //Initialise and dynamically allocate a 3D PointerArray new cube objects
	{
		for(int j = 0, y = 0; j < worldSize; j++, y+= blockSize)
		{
			for(int k = 0, z = 0; k < worldSize; k ++, z+=blockSize, blockNumber++)
			{
				short tempShort = static_cast<short>(buffer[blockNumber]); //Converting the individual char to a short (it will be in the form of an ascii code
				if (tempShort==10)
				{
					printf("break\n");
					blockNumber++;
					tempShort = static_cast<short>(buffer[blockNumber]);
				}
				else if (tempShort==0)
				{
					printf("null block\n");
				}
				tempShort-=48;	//Subtracting 48 from the ASCII code to get a number (0-9), it is a bit of a shit way but it works for now
				world[i][j][k].createBlock(tempShort); //Create the block based off it's type ID	
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
			z -= 2;
		}
		if(controller->isKeyDown(PSP_CTRL_RTRIGGER)) //Check for RTrigger press to control the zoom of the world
		{
			z += 2;
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
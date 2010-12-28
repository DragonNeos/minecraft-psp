// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page
//
// -- THIS IS STILL PRACTICE CODE USED TO PRACTICE THE IMPLEMENTATION OF FEATURES FOR MINECRAFT-PSP --
// 

#include <stdlib.h> // Header file for standard library
#include <pspctrl.h> // Header file for the PSP's control library
#include "GLLib.h" // Header File carrying all OpenGL32 and GLUT headers
#include "Display.h" // Header File For the 'Display' class
#include "Triangle.h" // Header file for the 'Triangle' class
#include "Cube.h" // Header file for the 'Cube' class
#include "Controller.h" // Header file for the 'Controller' class
#include "Texture.h"

int worldSize, blockSize;
Cube ***world;
Texture *worldTexture;

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // The only method call that as of yet needs the command line arguments to initialise GLUT

	float x = 0,y = 0, z = 0, rotation = 0, worldR = 0; //Position variables of the cube
	worldSize = 6; //Size of the WorldArray in terms of amount of blocks per Dimension
	blockSize = 4; //Size of blocks dimension(x,y,z)
	
	Display *display = new Display(); //Instantiate the graphics class via dynamic memory allocation
	Controller *controller = new Controller(); //Instantiate the controls class via dynamic memory allocation

	display->initialise(); //Initialises all OpenGL requirements and creates a viewport
	glEnable(GL_TEXTURE_2D); //Enable Texturing
	worldTexture = new Texture(); //Instantiate Textures of the world
	worldTexture->loadTexture("Data/texture.bmp"); ////load the texture image used in the world
	
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
			for(int k = 0, z = 0; k < worldSize; k ++, z+=blockSize)
			{
				world[i][j][k].createBlock(i); //Create the block based off it's type ID
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
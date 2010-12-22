#include <stdlib.h> // Header file for standard library
#include <pspctrl.h> // Header file for the PSP's control library
#include "GLLib.h" // Header File carrying all OpenGL32 and GLUT headers
#include "Display.h" // Header File For the 'Display' class
#include "Triangle.h" // Header file for the 'Triangle' class
#include "Cube.h" // Header file for the 'Cube' class
#include "Controller.h" // Header file for the 'Controller' class

int worldSize;
Cube ****world;

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // The only method call that as of yet needs the command line arguments to initialise GLUT

	float x = 0,y = 0, rotation = 0, worldR = 0;
	worldSize = 4; //Position variables of the cube
	
	Display *display = new Display(); //Instantiate the graphics class via dynamic memory allocation
	Triangle *tri = new Triangle(64,64); //Instantiate the 'Triangle' class via dynamic memory allocation
	Cube *cube = new Cube(32,32,32); //Instantiate the 'Cube' class via dynamic memory allocation
	Controller *controller = new Controller(); //Instantiate the controls class via dynamic memory allocation

	display->initialise(); //Initialises all OpenGL requirements and creates a viewport
	tri->initialise(1.0f,0,1.0f); //Initialises the triangles color property(R,G,B)

	//initialising a multi-dimensional array via dynamic memory allocation using pointers
	world = new Cube***[1]; //Initialise a dummy dimension which will simply act as a pointer to the 3D array
	for(int i = 0; i < worldSize; i++)
	{
		world[i] = new Cube**[worldSize]; //Initialise the 1st Dimension
		for(int j = 0; j < worldSize; j++)
		{
			world[i][j] = new Cube*[worldSize]; //Initialise the 2nd Dimension
			for(int k = 0; k < worldSize; k ++)
			{
				world[i][j][k] = new Cube[worldSize]; //Initialise the 3rd Dimension
			}
		}
	}

	for(int i = 0; i < worldSize; i++) //Initialise and dynamically allocate a 3D PointerArray new cube objects
	{
		for(int j = 0; j < worldSize; j++)
		{
			for(int k = 0; k < worldSize; k ++)
			{
				world[i][j][k] = new Cube(8*(i+1),8*(i+1),8*(i+1)); //Instantiate a new object and assign it via dynamic memory allocation
				world[i][j][k]->position->set(32*(i+1), 32*(j+1), 32*(k+1)); //Position the cubes apart from each other in order of theyre relative co-ordinates in the array
			}
		}
	}

	while(1)
	{
		controller->updateController(); //Update the keystates of the control pad

		display->clearBuffers(); //Clear screen and depth buffer
		display->resetOrigin(); //Reset the co-ordinate origin

		display->translate(0,0,-150); //Push the scene inside of the viewport frustum

		cube->position->x = x; //Set 'x' position of the cube
		cube->position->y = y; //Set 'y' position of the cube

		if(controller->isKeyDown(PSP_CTRL_LEFT)) //Check for left press
		{
			x -= 4;
		}
		if(controller->isKeyDown(PSP_CTRL_RIGHT)) //Check for right press
		{
			x += 4;
		}
		if(controller->isKeyDown(PSP_CTRL_DOWN)) //Check for down press
		{
			y -= 4;
		}
		if(controller->isKeyDown(PSP_CTRL_UP)) //Check for up press
		{
			y += 4;
		}
		if(controller->isKeyDown(PSP_CTRL_CROSS)) //Check for 'x' press
		{
			rotation += 4;
		}
		if(controller->isKeyDown(PSP_CTRL_CIRCLE)) //Check for circle press to rotate world
		{
			worldR += 4;
		}

		display->translate(0,0,0); //Move the cube over to the left side
		cube->draw(rotation, 0, 1, 0); //Draw the cube

		display->translate(-40,-60,-30);//Move the 'world' into better view
		display->rotate(worldR,0,1,0);//rotate the world around to see around it
		for(int i = 0; i < worldSize; i++)
		{
			for(int j = 0; j < worldSize; j++)
			{
				for(int k = 0; k < worldSize; k ++)
				{
					world[i][j][k]->draw();// Draw the 'World' pointers array of cubes
				}
			}
		}

		//display->translate(100,0,0); //Move the triangle over to the right
		//tri->draw(); //Draw the triangle

		display->update(); //Update the display buffer(i.e. swap the buffer)
	}

	return 0;
}
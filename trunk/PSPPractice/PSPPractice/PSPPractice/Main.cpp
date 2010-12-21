//This code is just a skeleton for your own programs

// This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe 
// (email Richard Campbell at ulmont@bellsouth.net)
//

// this was modified to work on PSP by Edorul (edorul@free.fr)
// Many Thanks to  jared bruni (jared@lostsidedead.com) for is
// MasterPiece3D port to PSP : it gave me a good sample and not
// the least a working makefile !

// important notes :  - all modified portion of code from cygwin version
//                                  of Nehe tutorial are marked with @@@

// Used keys :
// START = exit 

#include <stdlib.h> // needed in order to have "exit" function @@@
#include <pspctrl.h>
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include "Display.h" // Header File For the 'Display' class
#include "Triangle.h"
#include "Cube.h"
#include "Controller.h"

/* The number of our GLUT window */
int window; 
float x,y;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				// Reset The Projection Matrix

	gluPerspective(45.0f,(float)Width/(float)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
	if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
		Height=1;

	glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(float)Width/(float)Height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
void DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
	glLoadIdentity();				// Reset The View

	glTranslatef(0,0,-10);

	glBegin(GL_TRIANGLES);

	glVertex3f(0,0,0);
	glVertex3f(0,1,0);
	glVertex3f(1,0,0);

	glEnd();

	// swap buffers to display, since we're double buffered.
	glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int &x, int &y) 
{
	switch (key) {
	case 'd':	y++;		/* delta, triangle */
		break;
	case 'o':	x++;		/* round */
		break;
	case 'q':	x--;		/* square*/
		break;
	case 'x':	y--;		/* cross */
		break;
	case 'n':			/* key with the music note */
		break;
	case 's':			/* select */
		break;
	case 'a':			/* startbutton */  /* If START is pressed, kill everything. */
		/* exit the program...normal termination. */
		exit(0);                   
	default:
		;
	}
}

/* The function called whenever a key is released. */
void keyReleased(unsigned char key, int x, int y) 
{
	switch (key) {
	case 'd':			/* delta, triangle */
		break;
	case 'o':			/* round */
		break;
	case 'q':			/* square*/
		break;
	case 'x':			/* cross */
		break;
	case 'n':			/* key with the music note */
		break;
	case 's':			/* select */
		break;
	case 'a':			/* startbutton */
		break;
	default:
		;
	}
}

/* The function called whenever a special key is pressed. */
void specialKeyPressed(int key, int x, int y) 
{
	switch (key) {    
	case GLUT_KEY_UP: // pad arrow up
		break;

	case GLUT_KEY_DOWN: //  pad arrow down
		break;

	case GLUT_KEY_LEFT: //  pad arrow left
		break;

	case GLUT_KEY_RIGHT: //  pad arrow right
		break;

	case GLUT_KEY_HOME: // home
		break;

	default:
		break;
	}	
}

/* The function called whenever a special key is released. */
void specialKeyReleased(int key, int x, int y) 
{
	switch (key) {    
	case GLUT_KEY_UP: // pad arrow up
		break;

	case GLUT_KEY_DOWN: //  pad arrow down
		break;

	case GLUT_KEY_LEFT: //  pad arrow left
		break;

	case GLUT_KEY_RIGHT: //  pad arrow right
		break;

	case GLUT_KEY_HOME: // home
		break;

	default:
		break;
	}	
}

/* The function called whenever the joystick is moved. */
void joystickMoved (unsigned int buttonMask, int x, int y, int z)
{
	if (abs(x) > 150) // dead zone
	{	
		// use x value
	}

	if (abs(y) > 150) // dead zone
	{	
		// use y value
	}
}

/* The function called whenever the triggers are pressed. */
void triggerHandle (int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {  // left trigger...
		if (state == GLUT_DOWN) {  // ...is pressed
		}
		if (state == GLUT_UP) {  // ...is released
		}
	}

	if (button == GLUT_RIGHT_BUTTON) {  // right trigger...
		if (state == GLUT_DOWN) {  // ...is pressed
		}
		if (state == GLUT_DOWN) {  // ...is released
		}
	}
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	Display *display = new Display();
	Triangle *tri = new Triangle();
	Cube *cube = new Cube();
	Controller *controller = new Controller();

	display->initialise();
	tri->initialise(0.5f,0,1.0f);

	while(1)
	{
		controller->updateController();

		display->clearBuffers();
		display->resetOrigin();

		display->translate(0,0,-10);

		cube->x = x;
		cube->y = y;

		if(controller->isKeyDown(PSP_CTRL_LEFT))
		{
			x -= 0.01;
		}
		if(controller->isKeyDown(PSP_CTRL_RIGHT))
		{
			x += 0.01;
		}
		if(controller->isKeyDown(PSP_CTRL_DOWN))
		{
			y -= 0.01;
		}
		if(controller->isKeyDown(PSP_CTRL_UP))
		{
			y += 0.01;
		}

		display->translate(-5,0,0);
		cube->draw();

		display->translate(10,0,0);
		tri->draw();

		display->update();
	}

	return 0;
}
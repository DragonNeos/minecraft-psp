#include <stdlib.h> // needed in order to have "exit" function @@@

#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include "Display.h" // Header File for Display class which encapsulates OpenGL
#include <string>

Display::Display()
{
	width = 0, height = 0;

	/* Select type of Display mode:   
	Double buffer 
	RGBA color
	Alpha components supported 
	Depth buffer */  
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	/* get a 640 x 480 window */
	glutInitWindowSize(480, 272); 

	/* the window starts at the upper left corner of the screen */
	glutInitWindowPosition(0, 0);

	/* Open a window */  
	window = glutCreateWindow("PSPGL Window");
}

//Display::Display(string title)
//{	
//	width = 0, height = 0;
//	this->title = title;
//
//	/* Select type of Display mode:   
//	Double buffer 
//	RGBA color
//	Alpha components supported 
//	Depth buffer */  
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
//		
//	/* get a 640 x 480 window */
//	glutInitWindowSize(480, 272); 
//
//	/* the window starts at the upper left corner of the screen */
//	glutInitWindowPosition(0, 0);
//
//		/* Open a window */  
//	window = glutCreateWindow(title);
//}

void Display::initialise()
{
	width = 480;
	height = 272;

	glClearColor(0,0,0,0);
	glClearDepth(1.0f);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	//viewport usage has not been working but program runs already with a default viewport
	//glViewPort(0, 0, static_cast<int>(width), static_cast<int>(height));

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f,(float)width/(float)height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
}

void Display::initialise(float width, float height)
{
	this->width = width;
	this->height = height;

	glClearColor(0,0,0,0);
	glClearDepth(1.0f);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	//glViewPort(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(float)width/(float)height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
}

void Display::smoothShading()
{
	//Change shading of surfaces to smooth
	glShadeModel(GL_SMOOTH);
}

void Display::flatShading()
{
	//Change shading of surfaces to flat
	glShadeModel(GL_FLAT);
}

void Display::clearBuffers()
{
	//Clear screen and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::pushMatrix()
{
	//Push the stack matrix
	glPushMatrix();
}

void Display::popMatrix()
{
	//Pop the stack Matrix
	glPopMatrix();
}

void Display::resetOrigin()
{
	//reset co-ordinates to origin
	glLoadIdentity();
}

void Display::translate(float x, float y, float z)
{
	//translate to the given values
	glTranslatef(x,y,z);
}

void Display::update()
{
	// swap buffers to display, since we're double buffered.
	glutSwapBuffers();
}
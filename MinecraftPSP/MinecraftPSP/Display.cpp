// Author: Mouhamad Abdallah
// Date: 29 December 2010 (Modified by Mouhamad Abdallah Tuesday 8th February 2011)
// Modifications: All modifications are documented via Repository on google-code page

#include <stdlib.h> // needed in order to have "exit" function @@@
#include "GLLib.h" //Header file for OpenGL library
#include "Display.h" // Header File for Display class which encapsulates OpenGL

Display::Display() //Default Constructor
{
	width = 0, height = 0;

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH); /* Select type of Display mode: RGBA Color | DoubleBuffer | Alpha Enabled | Depth Buffer */

	//glutInitWindowSize(480, 272); /* get a 640 x 480 window */
	
	//glutInitWindowPosition(0, 0); /* the window starts at the upper left corner of the screen */
	
	window = glutCreateWindow("PSPGL Window"); /* Open a window */  
}

void Display::initialise() // Initialisation method which creates the frustum(However gluPerspective is unfimiliar)
{
	width = 480;
	height = 272;

	glClearColor(0,0,0,0);
	glClearDepth(1.0f);

	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);
	

	//viewport usage has not been working but program runs already with a default viewport
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	//glFrustum(-width/2.0f, width/2.0f, -width/2.0f, width/2.0f, 5.0f, 100.0f);
	gluPerspective(45, (float)width/(float)height, 0.1f, width);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
}

void Display::initialise(float width, float height) // Initialisation method that can have the width and height adjusted in which creates the frustum(However gluPerspective is unfimiliar)
{
	this->width = width;
	this->height = height;

	glClearColor(0,0,0,0);
	glClearDepth(1.0f);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-width/2.0f, width/2.0f, -height/2.0f, height/2.0f, 5.0f, width);
	//gluPerspective(45.0f,(float)width/(float)height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

	glMatrixMode(GL_MODELVIEW);
}

void Display::enableTextures()
{
	glEnable(GL_TEXTURE_2D);	
}

void Display::disableTextures()
{
	glDisable(GL_TEXTURE_2D);
}

void Display::enableTransparency()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Display::disableTransparency()
{
	glDisable(GL_BLEND);
}

void Display::enableCulling()
{
	glEnable(GL_CULL_FACE);
}

void Display::disableCulling()
{
	glDisable(GL_CULL_FACE);
}

void Display::smoothShading() // Places OpenGL in a smooth shading state
{
	glShadeModel(GL_SMOOTH);
}

void Display::flatShading() // Places OpenGL in a flat shading state
{
	glShadeModel(GL_FLAT);
}

void Display::cullFront()
{
	glCullFace(GL_FRONT);
}

void Display::cullBack()
{
	glCullFace(GL_BACK);
}

void Display::clearBuffers() // Clears the screen display buffer and depth buffer
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::pushMatrix() //Push the stack matrix
{
	glPushMatrix();
}

void Display::popMatrix() //Pop the stack Matrix
{
	glPopMatrix();
}

void Display::resetOrigin() //reset co-ordinates to origin
{
	glLoadIdentity();
}

void Display::translate(float x, float y, float z) //translate to the given values
{
	glTranslatef(x,y,z);
}

void Display::rotate(float rotationAngle, float x, float y, float z)
{
	glRotatef(rotationAngle, x, y, z);
}

void Display::update() //swap buffers to display, since we're double buffered 
{
	glutSwapBuffers();
}
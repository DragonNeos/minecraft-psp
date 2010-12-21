#include <stdlib.h>
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include "Triangle.h"

Triangle::Triangle()
{
	r = 1, g = 1, b = 1;
}

void Triangle::initialise(float r, float g, float b)
{
	this->r = r;
	this->b = b;
	this->g = g;
}

void Triangle::draw()
{
	glBegin(GL_TRIANGLES);

	glColor3f(r,g,b);

	glVertex3f(0,0,0);
	glVertex3f(1,0,0);
	glVertex3f(0,1,0);

	glEnd();
}
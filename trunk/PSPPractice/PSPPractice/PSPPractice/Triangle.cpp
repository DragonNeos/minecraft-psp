#include <stdlib.h> // Header File for the standard library
#include "GLLib.h" //Header file for OpenGL library 
#include "Triangle.h" //Header File for the 'Triangle' class

Triangle::Triangle() //Default Constructor
{
	r = 1, g = 1, b = 1;
}

void Triangle::initialise(float r, float g, float b) //Initialise the color of the shape
{
	this->r = r;
	this->b = b;
	this->g = g;
}

void Triangle::draw() //draw the shape
{
	glBegin(GL_TRIANGLES);

	glColor3f(r,g,b);

	glVertex3f(0,0,0);
	glVertex3f(1,0,0);
	glVertex3f(0,1,0);

	glEnd();
}
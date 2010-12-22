#include <stdlib.h> // Header File for the standard library
#include "GLLib.h" //Header file for OpenGL library 
#include "Triangle.h" //Header File for the 'Triangle' class
#include "Vector.h" //Header file for Vector math class

Triangle::Triangle() //Default Constructor
{
	r = 1, g = 1, b = 1;
	this->position = new Vector();
	this->size = new Vector();
}

Triangle::Triangle(float width, float height)
{
	r = 1, g = 1, b = 1;
	this->position = new Vector();
	this->size = new Vector(width, height);
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
	glVertex3f(size->x,0,0);
	glVertex3f(0,size->y,0);

	glEnd();
}

Triangle::~Triangle()
{
	size = 0;
	position = 0;
	delete size;
	delete position;
}
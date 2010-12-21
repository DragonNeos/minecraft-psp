#include <stdlib.h> //Header file for standard library
#include "GLLib.h" //Header file for OpenGL library
#include "Cube.h" //Header file for 'Cube' class

Cube::Cube() //Default constructor
{
	r = 1, b = 1, g = 1;
	x = 0, y = 0, z = 0;
}

void Cube::render() //Renders the shape
{
	//Front Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glVertex3f(0,0,0);
	glVertex3f(1,0,0);
	glVertex3f(1,1,0);
	glVertex3f(0,1,0);

	glEnd();

	//Left Face
	glBegin(GL_QUADS);

	glColor3f(r,0,b);

	glVertex3f(0,0,0);
	glVertex3f(0,0,-1);
	glVertex3f(0,1,-1);
	glVertex3f(0,1,0);

	glEnd();

	//Top Face
	glBegin(GL_QUADS);

	glColor3f(0,g,0);

	glVertex3f(0,1,0);
	glVertex3f(1,1,0);
	glVertex3f(1,1,-1);
	glVertex3f(0,1,-1);

	glEnd();

	//Right Face
	glBegin(GL_QUADS);

	glColor3f(0,g,b);

	glVertex3f(1,0,0);
	glVertex3f(1,0,-1);
	glVertex3f(1,1,-1);
	glVertex3f(1,1,0);

	glEnd();

	//Back Face
	glBegin(GL_QUADS);

	glColor3f(r,0,0);

	glVertex3f(0,0,-1);
	glVertex3f(1,0,-1);
	glVertex3f(1,1,-1);
	glVertex3f(0,1,-1);

	glEnd();

	//Bottom Face
	glBegin(GL_QUADS);

	glColor3f(0.5f,0.5f,0);

	glVertex3f(0,0,0);
	glVertex3f(0,0,-1);
	glVertex3f(1,0,-1);
	glVertex3f(0,1,0);

	glEnd();
}

void Cube::draw() //Draws the shape with translations
{
	glPushMatrix();
	glTranslatef(x,y,z);

	render();

	glPopMatrix();
}
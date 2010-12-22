#include <stdlib.h> //Header file for standard library
#include "GLLib.h" //Header file for OpenGL library
#include "Cube.h" //Header file for 'Cube' class
#include "Vector.h" //Header file for Vector math class

Cube::Cube() //Default constructor
{
	r = 1, b = 1, g = 1;
	this->position = new Vector();
	this->size = new Vector(8,8,8);
}

Cube::Cube(float width, float height, float depth) //Default constructor
{
	r = 1, b = 1, g = 1;
	this->position = new Vector();
	this->size = new Vector(width, height, depth);
}

void Cube::render() //Renders the shape
{
	//Front Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glVertex3f(size->x/2, size->y/2, size->z/2);
	glVertex3f(-size->x/2, size->y/2, size->z/2);
	glVertex3f(-size->x/2, -size->y/2, size->z/2);
	glVertex3f(size->x/2, -size->y/2, size->z/2);

	glEnd();

	//Left Face
	glBegin(GL_QUADS);

	glColor3f(r,0,b);

	glVertex3f(-size->x/2, size->y/2, size->z/2);
	glVertex3f(-size->x/2, size->y/2, -size->z/2);
	glVertex3f(-size->x/2, -size->y/2, -size->z/2);
	glVertex3f(-size->x/2, -size->y/2, size->z/2);

	glEnd();

	//Top Face
	glBegin(GL_QUADS);

	glColor3f(0,g,0);

	glVertex3f(size->x/2, size->y/2, -size->z/2);
	glVertex3f(-size->x/2, size->y/2, -size->z/2);
	glVertex3f(-size->x/2, size->y/2, size->z/2);
	glVertex3f(size->x/2, size->y/2, size->z/2);

	glEnd();

	//Right Face
	glBegin(GL_QUADS);

	glColor3f(0,g,b);

	glVertex3f(size->x/2, size->y/2, -size->z/2);
	glVertex3f(size->x/2, size->y/2, size->z/2);
	glVertex3f(size->x/2, -size->y/2, size->z/2);
	glVertex3f(size->x/2, -size->y/2, -size->z/2);

	glEnd();

	//Back Face
	glBegin(GL_QUADS);

	glColor3f(r,0,0);

	glVertex3f(size->x/2, size->y/2, -size->z/2);
	glVertex3f(-size->x/2, size->y/2, -size->z/2);
	glVertex3f(-size->x/2, -size->y/2, -size->z/2);
	glVertex3f(size->x/2, -size->y/2, -size->z/2);

	glEnd();

	//Bottom Face
	glBegin(GL_QUADS);

	glColor3f(0.5f,0.5f,0);

	glVertex3f(size->x/2, -size->y/2, -size->z/2);
	glVertex3f(-size->x/2, -size->y/2, -size->z/2);
	glVertex3f(-size->x/2, -size->y/2, size->z/2);
	glVertex3f(size->x/2, -size->y/2, size->z/2);

	glEnd();
}

void Cube::draw() //Draws the shape with translations
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);

	render();

	glPopMatrix();
}

void Cube::draw(float rotation, float x, float y, float z) //Draws the shape with translations and rotations
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRotatef(rotation, x, y, z);
	render();

	glPopMatrix();
}

Cube::~Cube()
{
	position = 0;
	size = 0;

	delete position;
	delete size;
}
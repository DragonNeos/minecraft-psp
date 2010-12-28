#include <stdlib.h> //Header file for standard library
#include "GLLib.h" //Header file for OpenGL library
#include "Cube.h" //Header file for 'Cube' class
#include "Vector.h" //Header file for Vector math class
#include "Texture.h"

Cube::Cube() //Default/Empty constructor
{
}

void Cube::initialise()
{
	r = 1, b = 1, g = 1;
	this->position = new Vector();
	this->size = new Vector(8,8,8);
}

void Cube::initialise(float width, float height, float depth)
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

	glTexCoord2f(0.03125f, 0.03125f);			glVertex3f(size->x/2, size->y/2, size->z/2); //Top-Right Corner
	glTexCoord2f(0, 0.03125f);					glVertex3f(-size->x/2, size->y/2, size->z/2); //Top-Left Corner
	glTexCoord2f(0, 0.03125f*2.0f);			glVertex3f(-size->x/2, -size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(0.03125f, 0.03125f*2.0f);		glVertex3f(size->x/2, -size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();

	//Left Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(0.03125f, 0.03125f);			glVertex3f(-size->x/2, size->y/2, size->z/2); //Top-Right Corner
	glTexCoord2f(0, 0.03125f);					glVertex3f(-size->x/2, size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(0, 0.03125f*2.0f);			glVertex3f(-size->x/2, -size->y/2, -size->z/2); //Bottom-Left Corner
	glTexCoord2f(0.03125f, 0.03125f*2.0f);		glVertex3f(-size->x/2, -size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();

	//Top Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(0.03125f, 0);			glVertex3f(size->x/2, size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(0, 0);					glVertex3f(-size->x/2, size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(0, 0.03125f);			glVertex3f(-size->x/2, size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(0.03125f, 0.03125f);		glVertex3f(size->x/2, size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();

	//Right Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(0.03125f, 0.03125f);			glVertex3f(size->x/2, size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(0, 0.03125f);					glVertex3f(size->x/2, size->y/2, size->z/2); //Top-Left Corner
	glTexCoord2f(0, 0.03125f*2.0f);			glVertex3f(size->x/2, -size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(0.03125f, 0.03125f*2.0f);		glVertex3f(size->x/2, -size->y/2, -size->z/2); //Bottom-Right Corner

	glEnd();

	//Back Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(0.03125f, 0.03125f);			glVertex3f(size->x/2, size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(0, 0.03125f);					glVertex3f(-size->x/2, size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(0, 0.03125f*2.0f);			glVertex3f(-size->x/2, -size->y/2, -size->z/2); //Bottom-Left Corner
	glTexCoord2f(0.03125f, 0.03125f*2.0f);		glVertex3f(size->x/2, -size->y/2, -size->z/2); //Bottom-Right Corner

	glEnd();

	//Bottom Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(0.03125f, 0.03125f*2.0f);			glVertex3f(size->x/2, -size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(0, 0.03125f*2.0f);					glVertex3f(-size->x/2, -size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(0, 0.03125f*3.0f);			glVertex3f(-size->x/2, -size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(0.03125f, 0.03125f*3.0f);		glVertex3f(size->x/2, -size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();
}

void Cube::draw() //Draws the shape with translations
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	//texture->bindTexture();
	render();

	glPopMatrix();
}

void Cube::draw(float rotation, float x, float y, float z) //Draws the shape with translations and rotations
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glRotatef(rotation, x, y, z);
	//texture->bindTexture();
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
// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page

#include <stdlib.h> //Header file for standard library
#include <stdio.h>			// Header file for file IO
#include "GLLib.h" //Header file for OpenGL library
#include "Cube.h" //Header file for 'Cube' class
#include "Vector.h" //Header file for Vector math class

Cube::Cube() //Default/Empty constructor
{	
}

void Cube::initialise()
{
	r = 1, b = 1, g = 1;
	this->position = new Vector();
	this->size = new Vector(8,8,8);
	tex = new GLfloat[48];
}

void Cube::initialise(float width, float height, float depth)
{
	r = 1, b = 1, g = 1;
	this->position = new Vector();
	this->size = new Vector(width, height, depth);
	tex = new GLfloat[48];
}

short Cube::returnBlockType()
{
	return blockType;
}

void Cube::createBlock(short block)
{
	switch(block)
	{
		case DIRT:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = 0;
			topFace.lowerY = TEXTURE_INTERVAL*2.0f;
			topFace.upperX = TEXTURE_INTERVAL;
			topFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = 0;
			sideFace.lowerY = TEXTURE_INTERVAL*2.0f;
			sideFace.upperX = TEXTURE_INTERVAL;
			sideFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = 0;
			bottomFace.lowerY = TEXTURE_INTERVAL*2.0f;
			bottomFace.upperX = TEXTURE_INTERVAL;
			bottomFace.upperY = TEXTURE_INTERVAL*3.0f;
			break;
		case GRASS:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = 0;
			topFace.lowerY = 0;
			topFace.upperX = TEXTURE_INTERVAL;
			topFace.upperY = TEXTURE_INTERVAL;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = 0;
			sideFace.lowerY = TEXTURE_INTERVAL;
			sideFace.upperX = TEXTURE_INTERVAL;
			sideFace.upperY = TEXTURE_INTERVAL*2.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = 0;
			bottomFace.lowerY = TEXTURE_INTERVAL*2.0f;
			bottomFace.upperX = TEXTURE_INTERVAL;
			bottomFace.upperY = TEXTURE_INTERVAL*3.0f;
			break;
		case SAND:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = 0;
			topFace.lowerY = TEXTURE_INTERVAL*7.0f;
			topFace.upperX = TEXTURE_INTERVAL;
			topFace.upperY = TEXTURE_INTERVAL*8.0f;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = 0;
			sideFace.lowerY = TEXTURE_INTERVAL*7.0f;
			sideFace.upperX = TEXTURE_INTERVAL;
			sideFace.upperY = TEXTURE_INTERVAL*8.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = 0;
			bottomFace.lowerY = TEXTURE_INTERVAL*7.0f;
			bottomFace.upperX = TEXTURE_INTERVAL;
			bottomFace.upperY = TEXTURE_INTERVAL*8.0f;
			break;
		case STONE:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL*2.0f;
			topFace.lowerY = 0;
			topFace.upperX = TEXTURE_INTERVAL*3.0f;
			topFace.upperY = TEXTURE_INTERVAL;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL*2.0f;
			sideFace.lowerY = 0;
			sideFace.upperX = TEXTURE_INTERVAL*3.0f;
			sideFace.upperY = TEXTURE_INTERVAL;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL*2.0f;
			bottomFace.lowerY = 0;
			bottomFace.upperX = TEXTURE_INTERVAL*3.0f;
			bottomFace.upperY = TEXTURE_INTERVAL;
			break;
		case COBBLESTONE:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL*2.0f;
			topFace.lowerY = TEXTURE_INTERVAL*2.0f;
			topFace.upperX = TEXTURE_INTERVAL*3.0f;
			topFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL*2.0f;
			sideFace.lowerY = TEXTURE_INTERVAL*2.0f;
			sideFace.upperX = TEXTURE_INTERVAL*3.0f;
			sideFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL*2.0f;
			bottomFace.lowerY = TEXTURE_INTERVAL*2.0f;
			bottomFace.upperX = TEXTURE_INTERVAL*3.0f;
			bottomFace.upperY = TEXTURE_INTERVAL*3.0f;
			break;
		case WOOD:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL;
			topFace.lowerY = 0;
			topFace.upperX = TEXTURE_INTERVAL*2.0f;
			topFace.upperY = TEXTURE_INTERVAL;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL;
			sideFace.lowerY = TEXTURE_INTERVAL;
			sideFace.upperX = TEXTURE_INTERVAL*2.0f;
			sideFace.upperY = TEXTURE_INTERVAL*2.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL;
			bottomFace.lowerY = 0;
			bottomFace.upperX = TEXTURE_INTERVAL*2.0f;
			bottomFace.upperY = TEXTURE_INTERVAL;
			break;

		case WOODENPLANK:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL;
			topFace.lowerY = TEXTURE_INTERVAL*2.0f;
			topFace.upperX = TEXTURE_INTERVAL*2;
			topFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL;
			sideFace.lowerY = TEXTURE_INTERVAL*2.0f;
			sideFace.upperX = TEXTURE_INTERVAL*2;
			sideFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL;
			bottomFace.lowerY = TEXTURE_INTERVAL*2.0f;
			bottomFace.upperX = TEXTURE_INTERVAL*2;
			bottomFace.upperY = TEXTURE_INTERVAL*3.0f;
			break;
		case BEDROCK:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL*2;
			topFace.lowerY = TEXTURE_INTERVAL*8;
			topFace.upperX = TEXTURE_INTERVAL*3;
			topFace.upperY = TEXTURE_INTERVAL*9;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL*2;
			sideFace.lowerY = TEXTURE_INTERVAL*8;
			sideFace.upperX = TEXTURE_INTERVAL*3;
			sideFace.upperY = TEXTURE_INTERVAL*9;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL*2;
			bottomFace.lowerY = TEXTURE_INTERVAL*8;
			bottomFace.upperX = TEXTURE_INTERVAL*3;
			bottomFace.upperY = TEXTURE_INTERVAL*9;
			break;
		case GRAVEL:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = 0;
			topFace.lowerY = TEXTURE_INTERVAL*8.0f;
			topFace.upperX = TEXTURE_INTERVAL;
			topFace.upperY = TEXTURE_INTERVAL*9.0f;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = 0;
			sideFace.lowerY = TEXTURE_INTERVAL*8.0f;
			sideFace.upperX = TEXTURE_INTERVAL;
			sideFace.upperY = TEXTURE_INTERVAL*9.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = 0;
			bottomFace.lowerY = TEXTURE_INTERVAL*8.0f;
			bottomFace.upperX = TEXTURE_INTERVAL;
			bottomFace.upperY = TEXTURE_INTERVAL*9.0f;
			break;

		case GOLDORE:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL*2;
			topFace.lowerY = TEXTURE_INTERVAL*5;
			topFace.upperX = TEXTURE_INTERVAL*3;
			topFace.upperY = TEXTURE_INTERVAL*6;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL*2;
			sideFace.lowerY = TEXTURE_INTERVAL*5;
			sideFace.upperX = TEXTURE_INTERVAL*3;
			sideFace.upperY = TEXTURE_INTERVAL*6;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL*2;
			bottomFace.lowerY = TEXTURE_INTERVAL*5;
			bottomFace.upperX = TEXTURE_INTERVAL*3;
			bottomFace.upperY = TEXTURE_INTERVAL*6;
			break;

		case COALORE:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL*2;
			topFace.lowerY = TEXTURE_INTERVAL*1;
			topFace.upperX = TEXTURE_INTERVAL*3;
			topFace.upperY = TEXTURE_INTERVAL*2;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL*2;
			sideFace.lowerY = TEXTURE_INTERVAL*1;
			sideFace.upperX = TEXTURE_INTERVAL*3;
			sideFace.upperY = TEXTURE_INTERVAL*2;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL*2;
			bottomFace.lowerY = TEXTURE_INTERVAL*1;
			bottomFace.upperX = TEXTURE_INTERVAL*3;
			bottomFace.upperY = TEXTURE_INTERVAL*2;
			break;

		case IRONORE:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = TEXTURE_INTERVAL*2;
			topFace.lowerY = TEXTURE_INTERVAL*4;
			topFace.upperX = TEXTURE_INTERVAL*3;
			topFace.upperY = TEXTURE_INTERVAL*5;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = TEXTURE_INTERVAL*2;
			sideFace.lowerY = TEXTURE_INTERVAL*4;
			sideFace.upperX = TEXTURE_INTERVAL*3;
			sideFace.upperY = TEXTURE_INTERVAL*5;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = TEXTURE_INTERVAL*2;
			bottomFace.lowerY = TEXTURE_INTERVAL*4;
			bottomFace.upperX = TEXTURE_INTERVAL*3;
			bottomFace.upperY = TEXTURE_INTERVAL*5;
			break;
		case AIR:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = 0;
			topFace.lowerY = TEXTURE_INTERVAL*10.0f;
			topFace.upperX = TEXTURE_INTERVAL;
			topFace.upperY = TEXTURE_INTERVAL*11.0f;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = 0;
			sideFace.lowerY = TEXTURE_INTERVAL*10.0f;
			sideFace.upperX = TEXTURE_INTERVAL;
			sideFace.upperY = TEXTURE_INTERVAL*11.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = 0;
			bottomFace.lowerY = TEXTURE_INTERVAL*10.0f;
			bottomFace.upperX = TEXTURE_INTERVAL;
			bottomFace.upperY = TEXTURE_INTERVAL*11.0f;
			break;

		default:
			//Top Face Texture Mapping Co-ordinates set
			topFace.lowerX = 0;
			topFace.lowerY = TEXTURE_INTERVAL*2.0f;
			topFace.upperX = TEXTURE_INTERVAL;
			topFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Side Face Texture Mapping Co-ordinates set
			sideFace.lowerX = 0;
			sideFace.lowerY = TEXTURE_INTERVAL*2.0f;
			sideFace.upperX = TEXTURE_INTERVAL;
			sideFace.upperY = TEXTURE_INTERVAL*3.0f;

			//Bottom Face Texture Mapping Co-ordinates set
			bottomFace.lowerX = 0;
			bottomFace.lowerY = TEXTURE_INTERVAL*2.0f;
			bottomFace.upperX = TEXTURE_INTERVAL;
			bottomFace.upperY = TEXTURE_INTERVAL*3.0f;
			break;
	}
	printf("Starting Texture mapping\n");
	for(int i = 0, k = 0; i < 48; i++, k++)
	{
		printf("inside for loop\n");
		if(k > 7)
		{
			k = 0;
		}
		printf("current tex axis checked\n");
		if(i < 32)
		{
			printf("inside side faces\n");
			switch(k)
			{
				case 0: tex[i] = sideFace.upperX; break;
				case 1: tex[i] = sideFace.lowerY; break;
				case 2: tex[i] = sideFace.lowerX; break;
				case 3: tex[i] = sideFace.lowerY; break;
				case 4: tex[i] = sideFace.lowerX; break;
				case 5: tex[i] = sideFace.upperY; break;
				case 6: tex[i] = sideFace.upperX; break;
				case 7: tex[i] = sideFace.upperY; break;
			}
			printf("exiting side faces\n");
		}
		if(i > 31 && i < 40)
		{
			printf("inside top faces\n");
			switch(k)
			{
				case 0: tex[i] = topFace.upperX; break;
				case 1: tex[i] = topFace.lowerY; break;
				case 2: tex[i] = topFace.lowerX; break;
				case 3: tex[i] = topFace.lowerY; break;
				case 4: tex[i] = topFace.lowerX; break;
				case 5: tex[i] = topFace.upperY; break;
				case 6: tex[i] = topFace.upperX; break;
				case 7: tex[i] = topFace.upperY; break;
			}
			printf("exiting top faces\n");
		}
		if(i > 40)
		{
			printf("inside bottom faces\n");
			switch(k)
			{
				case 0: tex[i] = bottomFace.upperX; break;
				case 1: tex[i] = bottomFace.lowerY; break;
				case 2: tex[i] = bottomFace.lowerX; break;
				case 3: tex[i] = bottomFace.lowerY; break;
				case 4: tex[i] = bottomFace.lowerX; break;
				case 5: tex[i] = bottomFace.upperY; break;
				case 6: tex[i] = bottomFace.upperX; break;
				case 7: tex[i] = bottomFace.upperY; break;
			}
			printf("exiting bottom faces\n");
		}
	}
}


void Cube::render() //Renders the shape
{
	//Front Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(sideFace.upperX, sideFace.lowerY);			glVertex3f(size->x/2, size->y/2, size->z/2); //Top-Right Corner
	glTexCoord2f(sideFace.lowerX, sideFace.lowerY);			glVertex3f(-size->x/2, size->y/2, size->z/2); //Top-Left Corner
	glTexCoord2f(sideFace.lowerX, sideFace.upperY);			glVertex3f(-size->x/2, -size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(sideFace.upperX, sideFace.upperY);			glVertex3f(size->x/2, -size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();

	//Left Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(sideFace.upperX, sideFace.lowerY);			glVertex3f(-size->x/2, size->y/2, size->z/2); //Top-Right Corner
	glTexCoord2f(sideFace.lowerX, sideFace.lowerY);			glVertex3f(-size->x/2, size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(sideFace.lowerX, sideFace.upperY);			glVertex3f(-size->x/2, -size->y/2, -size->z/2); //Bottom-Left Corner
	glTexCoord2f(sideFace.upperX, sideFace.upperY);			glVertex3f(-size->x/2, -size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();

	//Top Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(topFace.upperX, topFace.lowerY);			glVertex3f(size->x/2, size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(topFace.lowerX, topFace.lowerY);			glVertex3f(-size->x/2, size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(topFace.lowerX, topFace.upperY);			glVertex3f(-size->x/2, size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(topFace.upperX, topFace.upperY);			glVertex3f(size->x/2, size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();

	//Right Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(sideFace.upperX, sideFace.lowerY);			glVertex3f(size->x/2, size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(sideFace.lowerX, sideFace.lowerY);			glVertex3f(size->x/2, size->y/2, size->z/2); //Top-Left Corner
	glTexCoord2f(sideFace.lowerX, sideFace.upperY);			glVertex3f(size->x/2, -size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(sideFace.upperX, sideFace.upperY);			glVertex3f(size->x/2, -size->y/2, -size->z/2); //Bottom-Right Corner

	glEnd();

	//Back Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(sideFace.upperX, sideFace.lowerY);			glVertex3f(size->x/2, size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(sideFace.lowerX, sideFace.lowerY);			glVertex3f(-size->x/2, size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(sideFace.lowerX, sideFace.upperY);			glVertex3f(-size->x/2, -size->y/2, -size->z/2); //Bottom-Left Corner
	glTexCoord2f(sideFace.upperX, sideFace.upperY);			glVertex3f(size->x/2, -size->y/2, -size->z/2); //Bottom-Right Corner

	glEnd();

	//Bottom Face
	glBegin(GL_QUADS);

	glColor3f(r,g,b);

	glTexCoord2f(bottomFace.upperX, bottomFace.lowerY);			glVertex3f(size->x/2, -size->y/2, -size->z/2); //Top-Right Corner
	glTexCoord2f(bottomFace.lowerX, bottomFace.lowerY);			glVertex3f(-size->x/2, -size->y/2, -size->z/2); //Top-Left Corner
	glTexCoord2f(bottomFace.lowerX, bottomFace.upperY);			glVertex3f(-size->x/2, -size->y/2, size->z/2); //Bottom-Left Corner
	glTexCoord2f(bottomFace.upperX, bottomFace.upperY);			glVertex3f(size->x/2, -size->y/2, size->z/2); //Bottom-Right Corner

	glEnd();
}

void Cube::draw(GLbyte*& indices) //Draws the shape with translations
{
	glPushMatrix();
	glTranslatef(position->x, position->y, position->z);
	glTexCoordPointer(2 ,GL_FLOAT, 0, tex);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
	//texture->bindTexture();
	//render();

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
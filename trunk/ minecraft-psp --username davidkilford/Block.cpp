//Author:		David Kilford
//Date:			15th December 2010
//Description:	Entity class for blocks

#include <GL/glut.h>		//Header File For The GLUT Library 
#include <GL/gl.h>			//Header File For The OpenGL32 Library
#include <GL/glu.h>			//Header File For The GLu32 Library
#include <stdio.h>			//Header file for standard file i/o.
#include <stdlib.h>			//Header file for malloc/free.
#include <stdbool.h>		//Header file for booleans

/** Block is an entity class used as the basis of every block.
	Inside are the basic attributes that every block should have.
	Currently it has one non-get method: a destroy method.
*/

class Block
{
	float x, y, z;			//Position in array. May be changed as the position is redundent because the position is held in the array.
	float hardness;			//The block's maximum 'health'.
	float durability;		//The block's current 'health.
	float blockID;			//ID of the block so it can be quickly referenced.
	float dropItemID;		//ID of the item it drops, probably to be changed.
	bool walkThroughAble;	//Boolean of whether you can walk through it, may be changed as lava and water act differently to other blocks.
	bool seeThrough;		//Whether the block effects light.

	Block(float posx, float posy, float posz) //Takes in and sets the position, may be redundent because the position is held in the array it is stored in.
	{
		x = posx;
		y = posy;
		z = posz;
	}

	/* This method is to be run to destroy the block object correctly.
	   Currently it isn't implemented yet. */
		
	void destroyBlock()
	{
		//TO BE IMPLEMENTED
	}

	//Get methods

	float getDurability()
	{
		return durability;
	}

	float getHardness()
	{
		return hardness;
	}

	float getDropItemID()
	{
		return dropItemID;
	}

	bool getWalkThroughAble()
	{
		return walkThroughAble;
	}

	bool getSeeThrough()
	{
		return seeThrough;
	}

}
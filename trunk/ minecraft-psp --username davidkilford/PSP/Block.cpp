//Author:		David Kilford
//Date:			15th December 2010
//Description:	Source class for blocks

#include <stdio.h>			//Header file for standard file i/o.
#include <stdlib.h>			//Header file for malloc/free.
#include <stdbool.h>		//Header file for booleans

/** Block is an abstract class used as the basis of every block.
	Inside are the basic attributes that every block should have.
	Currently it has one non-get method: a destroy method.
*/

class Block
{
public:
	float x, y, z;			//Position in array. May be changed as the position is redundent because the position is held in the array.
	float hardness;			//The block's maximum 'health'.
	float durability;		//The block's current 'health.
	float blockID;			//ID of the block so it can be quickly referenced.
	float dropItemID;		//ID of the item it drops, probably to be changed.
	bool walkThroughAble;	//Boolean of whether you can walk through it, may be changed as lava and water act differently to other blocks.
	bool seeThrough;		//Whether the block effects light.

	public:Block(float posx, float posy, float posz) //Takes in and sets the position, may be redundent because the position is held in the array it is stored in.
	{
		x = posx;
		y = posy;
		z = posz;
	}

	public:Block()
	{
		durability=1;
		hardness=1;
		walkThroughAble=false;
		seeThrough=false;
		dropItemID=0;
	}

	/* This method is to be run to destroy the block object correctly.
	   Currently it isn't implemented yet. */
		
	public:void destroyBlock()
	{
		//Probably getting shfited to world class
	}

	//Get methods

	public:float getDurability()
	{
		return durability;
	}

	public:float getHardness()
	{
		return hardness;
	}

	public:float getDropItemID()
	{
		return dropItemID;
	}

	public:bool getWalkThroughAble()
	{
		return walkThroughAble;
	}

	public:bool getSeeThrough()
	{
		return seeThrough;
	}

	public:void setBlockID(float ID)
	{
			   blockID=ID;
	}
}
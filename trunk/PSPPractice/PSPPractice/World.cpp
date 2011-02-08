//Author:			Mouhamad Abdallah
//Date:				Tuesday 8th February 2011
//Description:		Loads and manages an entire world - The blocks of the world are created here

#include <stdlib.h> //Header File for standard library
#include "World.h"  //Header File for 'World' class

World::World() //Default/Empty Constructor
{

}

void World::initialiseWorld(int worldLimit, int blockSide, short *&blockID) //Initialises the world creating and populating the 3D Array
{
	this->worldSize = worldLimit;
	this->blockSize = blockSide;

	world = new Cube**[worldSize]; //Initialise the 1st Dimension
	for(int j = 0; j < worldSize; j++)
	{
		world[j] = new Cube*[worldSize]; //Initialise the 2nd Dimension
		for(int k = 0; k < worldSize; k ++)
		{
			world[j][k] = new Cube[worldSize]; //Initialise the 3rd Dimension
		}
	}

	for(int i = 0, y = 0, blockNumber = 0; i < worldSize; i++, y += blockSize) //Initialise and dynamically allocate a 3D PointerArray of new cube objects
	{
		for(int j = 0, z = 0; j < worldSize; j++, z+= blockSize)
		{
			for(int k = 0, x = 0; k < worldSize; k ++, x+=blockSize, blockNumber++)
			{
				world[i][j][k].createBlock(blockID[blockNumber]); //Create the block based off it's type ID	
				world[i][j][k].initialise(blockSize, blockSize, blockSize); //Instantiate a new object and assign it via dynamic memory allocation
				world[i][j][k].position->set(x, y, z); //Position the cubes apart from each other in order of theyre relative co-ordinates in the array
			}
		}
	}
}

void World::draw(float rotation, float xR, float yR, float zR) //Draw function of the entire world with rotation matrix included
{
		for(int x = 0; x < worldSize; x++)
		{
			for(int y = 0; y < worldSize; y++)
			{
				for(int z = 0; z < worldSize; z ++)
				{
					world[x][y][z].draw(rotation, xR, yR, zR);// Draw the 'World' array of cubes with rotation applied
				}
			}
		}
}

void World::draw() //Draw function of the entire world
{
		for(int x = 0; x < worldSize; x++)
		{
			for(int y = 0; y < worldSize; y++)
			{
				for(int z = 0; z < worldSize; z ++)
				{
					world[x][y][z].draw();// Draw the 'World' array of cubes
				}
			}
		}
}
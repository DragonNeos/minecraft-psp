//Author:			Mouhamad Abdallah
//Date:				Tuesday 8th February 2011
//Description:		Header file for the actual 'World'

#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h> //Header File for standard library
#include "Cube.h"   //Header File for the 'Cube' class

class World
{
	public:
		int worldSize, blockSize; //World information for later use
		Cube ***world; //3D Array of blocks/cubes

		World(); //Default Constructor
		void initialiseWorld(int worldLimit, int blockSide, short *&blockID); //Initialise the world with various limits and reference to block information
		short returnBlock(int x, int y, int z); //Returns the block type at the indicated position(For collision detection purposes)
		void changeBlock(int x, int y, int z, short blockType); //Used to change the blocks selected(Either for destruction of/creation of blocks)
		void draw(GLbyte* indices); //Draw the world without any rotations on the individual blocks
		void draw(float rotation, float xR, float yR, float zR); //Draw the world with individual rotations on blocks
};

#endif
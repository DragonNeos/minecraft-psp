// Author:			Mouhamad Abdallah
// Date:			29 December 2010
// Modifications:	All modifications are documented via Repository on google-code page

#ifndef CUBE_H
#define CUBE_H

#include <stdlib.h> // Header file for standard library
#include "Vector.h" //Header file for Vector class
#define TEXTURE_INTERVAL 0.03125f

enum Block
{
	AIR,
	STONE,
	GRASS,
	DIRT,
	COBBLESTONE,
	WOODENPLANK,
	SAPLING,
	BEDROCK,
	WATER,
	STATIONARYWATER,
	LAVA,
	STATIONARYLAVA,
	SAND,
	GRAVEL,
	GOLDORE,
	IRONORE,
	COALORE,
	WOOD
};

struct MappingInfo
{
	float lowerX, lowerY, upperX, upperY;
};

class Cube
{
	public:
		float r,g,b; //Variables for holding values of color
		Vector *position, *size; //Vectors for position and dimensions
		MappingInfo topFace, sideFace, bottomFace;
		//Texture *texture;
		Cube(); //Default Constructor
		void initialise(); //Better method to initialise the block instead of re-instantiation
		void initialise(float width, float height, float depth); //Method allowing dimension changes
		void createBlock(short block); //Initialise the block type and set the tex-coord's for the texture
		void draw(); //draw shape with translations
		void draw(float rotation, float x, float y, float z); //draw shape with rotations applied

		~Cube(); //default destructor
	
	private:
		void render(); //render the actual shape
};

#endif
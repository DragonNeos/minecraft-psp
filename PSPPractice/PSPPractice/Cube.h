#ifndef CUBE_H
#define CUBE_H

#include <stdlib.h> // Header file for standard library
#include "Vector.h" //Header file for Vector class
//#include "Texture.h"

class Cube
{
	public:
		float r,g,b; //Variables for holding values of color
		Vector *position, *size; //Vectors for position and dimensions
		//Texture *texture;
		Cube(); //Default Constructor
		void initialise(); //Better method to initialise the block instead of re-instantiation
		void initialise(float width, float height, float depth); //Method allowing dimension changes
		void draw(); //draw shape with translations
		void draw(float rotation, float x, float y, float z); //draw shape with rotations applied

		~Cube(); //default destructor
	
	private:
		void render(); //render the actual shape
};

#endif
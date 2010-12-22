#ifndef CUBE_H
#define CUBE_H

#include <stdlib.h> // Header file for standard library
#include "Vector.h" //Header file for Vector class

class Cube
{
	public:
		float r,g,b; //Variables for holding values of color
		Vector *position, *size; //Vectors for position and dimensions
		Cube(); //Default Constructor
		Cube(float width, float height, float depth); //Constructor allowing for dimension changes

		void draw(); //draw shape with translations
		void draw(float rotation, float x, float y, float z); //draw shape with rotations applied

		~Cube(); //default destructor
	
	private:
		void render(); //render the actual shape
};

#endif
#ifndef CUBE_H
#define CUBE_H

#include <stdlib.h> // Header file for standard library

class Cube
{
	public:
		float r,g,b; //Variables for holding values of color
		float x,y,z; //Variables for holding position
		Cube(); //Default Constructor

		void draw(); //draw shape with translations
	
	private:
		void render(); //render the actual shape
};

#endif
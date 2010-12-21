#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdlib.h> // Header File for standard library

class Triangle
{
	public:
		float r,g,b; //Variables for holding color values

		Triangle(); //Default Constructor

		void initialise(float r, float g, float b); //Initialises color of shape

		void draw(); //Draw shape
};

#endif
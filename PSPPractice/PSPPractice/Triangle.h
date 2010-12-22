#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdlib.h> // Header File for standard library
#include "Vector.h" //Header file for Vector class

class Triangle
{
	public:
		float r,g,b; //Variables for holding color values
		Vector *position, *size; //Vectors for position and dimensions
		Triangle(); //Default Constructor
		Triangle(float width, float height); //Constructor allowing for size change

		void initialise(float r, float g, float b); //Initialises color of shape

		void draw(); //Draw shape

		~Triangle();
};

#endif
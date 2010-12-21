#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdlib.h>

class Triangle
{
	public:
		float r,g,b;

		Triangle();

		void initialise(float r, float g, float b);

		void draw();
};

#endif
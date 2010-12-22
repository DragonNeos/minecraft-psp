#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdlib.h>

class Display
{
	public:
		int window;
		float width, height;
	Display();

	void initialise();
	void initialise(float width, float height);

	void smoothShading();
	void flatShading();

	void resetOrigin();
	void translate(float x, float y, float z);
	void rotate(float rotationAngle, float x, float y, float z);

	void pushMatrix();
	void popMatrix();

	void update();
	void clearBuffers();
};

#endif
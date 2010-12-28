// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page

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
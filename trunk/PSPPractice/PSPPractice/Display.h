// Author: Mouhamad Abdallah
// Date: 29 December 2010 (Modified by Mouhamad Abdallah Tuesday 8th February 2011)
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

	void enableTextures();
	void disableTextures();
	void enableTransparency();
	void disableTransparency();

	void enableCulling();
	void disableCulling();

	void initialise();
	void initialise(float width, float height);

	void smoothShading();
	void flatShading();

	void cullFront();
	void cullBack();
	void cullBoth();

	void resetOrigin();
	void translate(float x, float y, float z);
	void rotate(float rotationAngle, float x, float y, float z);

	void pushMatrix();
	void popMatrix();

	void update();
	void clearBuffers();
};

#endif
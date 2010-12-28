#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include "GLLib.h"

/* Image type - contains height, width, and data */
struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};
typedef struct Image Image;

class Texture
{
	public:
		//Image *image;
		Texture();
		void loadTexture(char *fileName);
		void bindTexture();

	private:
		GLuint id;
		int loadImage(char *fileName, Image *image);
		void initialiseTexture(Image *image);
};

#endif
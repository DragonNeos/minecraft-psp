// Author: Mouhamad Abdallah & David Kilford
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page

#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include "GLLib.h"
//#include "Graphics.h"

#include <psptypes.h>

#define	PSP_LINE_SIZE 512
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

typedef u32 Color;
#define A(color) ((u8)(color >> 24 & 0xFF))
#define B(color) ((u8)(color >> 16 & 0xFF))
#define G(color) ((u8)(color >> 8 & 0xFF))
#define R(color) ((u8)(color & 0xFF))

typedef struct
{
	int textureWidth;  // the real width of data, 2^n with n>=0
	int textureHeight;  // the real height of data, 2^n with n>=0
	int imageWidth;  // the image width
	int imageHeight;
	Color* data;
} Image;

class Texture
{
	public:
          char buffer[200];
          Image* ourImage;
		Texture();
		void loadTexture(char *filename);
		void bindTexture();

	private:
		/**
		 * Load a PNG image.
		 *
		 * @pre filename != NULL
		 * @param filename - filename of the PNG image to load
		 * @return pointer to a new allocated Image struct, or NULL on failure
		 */
		Image* loadImage(char* filename);
		void initialiseTexture();
		GLuint id;
};

#endif
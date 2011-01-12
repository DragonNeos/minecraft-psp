// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page

#include "Texture.h"
#include "CTexture.h"
#include "GLLib.h"
#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.

Texture::Texture()
{
	texture = new CTexture();
	id = 0;
}

void Texture::loadTexture(char *filename)
{
	printf("File will now load\n");
	texture->LoadTexture(filename);
	printf("File has had load Attempt\n");
	if(texture != NULL)
	{
		printf("File has been loaded\n");
		id = texture->texID;
		initialiseTexture();
	}
}

void Texture::initialiseTexture()
{
	// Create Texture	
	printf("Texture Binding Started\n");
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);   // 2d texture (x and y size)

	printf("Texture Parameter Started\n");
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
	
    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image, 
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
	switch(texture->textureType)
	{
		case BMP: //Not Working
		printf("Texture Image Rasterising\n");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);
			break;
		case PCX: //Not working
		printf("Texture Image Rasterising\n");	
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
			break;
		case TGA: //Working However TGA files are too large
			printf("Texture Image Rasterising\n");
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);
			break;
	}
	
}

void Texture::bindTexture()
{
	printf("Texture Binding\n");
	glBindTexture(GL_TEXTURE_2D, id);   // 2d texture (x and y size)
}

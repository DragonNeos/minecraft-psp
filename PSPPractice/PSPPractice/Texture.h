// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page

#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>      // Header file for standard file i/o.
#include <stdlib.h>     // Header file for malloc/free.
#include "GLLib.h"
#include "CTexture.h"

class Texture
{
	public:
		CTexture *texture;
		Texture();
		void loadTexture(char *filename);
		void bindTexture();

	private:
		void initialiseTexture();
		GLuint id;
};

#endif
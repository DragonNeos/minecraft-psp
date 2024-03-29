// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page

#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
	public:
		float x,y,z;

		Vector();
		Vector(float x);
		Vector(float x, float y);
		Vector(float x, float y, float z);

		void set(float x, float y, float z);
};

#endif
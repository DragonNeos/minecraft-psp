// Author: Mouhamad Abdallah
// Date: 29 December 2010
// Modifications: All modifications are documented via Repository on google-code page

#include <stdlib.h>
#include "Vector.h"

Vector::Vector()
{
	x = 0, y = 0, z = 0;
}

Vector::Vector(float x)
{
	this->x = x, y = 0, z = 0;
}

Vector::Vector(float x, float y)
{
	this->x = x, this->y = y, z = 0;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x, this->y = y, this->z = z;
}

void Vector::set(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
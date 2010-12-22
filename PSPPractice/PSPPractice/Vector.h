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
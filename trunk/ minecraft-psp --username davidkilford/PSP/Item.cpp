//Author:		David Kilford
//Date:			15th December 2010
//Description:	Entity class for items.  TODO: Add a model for the item while it is held, implement methods.

#include <GL/glut.h>				// Header File For The GLUT Library 
#include <GL/gl.h>					// Header File For The OpenGL32 Library
#include <GL/glu.h>					// Header File For The GLu32 Library
#include <stdio.h>					// Header file for standard file i/o.
#include <stdlib.h>					// Header file for malloc/free.
#include <stdbool.h>				// Header file for booleans.
#include <Item.h>					// Header file for items

class Item
{
	float x, y, z;					//Positions, self explanitory
	float inventoryID;				//Which inventory the item is placed in
	float amount;					//Amount of items in the stack
	float durability;				//How much durability the item has left
	float strength;					//How well it can break something down
	bool stackable;					//Whether you can stack the item or not
	float texturex, texturey;		//The x and y coordinates for texturing.
	

	Item(float posx, float posy, float posz, int invID, float dura, float size)
	{
		x = posx;
		y = posy;
		z = posz;
		inventoryID = invID;
		durability = dura;
		amount = size;

	}
	Item()							//Empty Constructor for testing
	{
	}

	void dropItem()					//Method to be run when you convert the item into a dropped item
	{
		//Make a dropped item. TO BE IMPLEMENTED
	}


	void setTest(int setAmount)
		{
			amount=setAmount;
		}

	int pickUpItem()				//Convert a dropped item into an item
	{
		return durability, amount;
	}

	//Get methods

	int getInventoryID()
	{
		return inventoryID;
	}

	float getAmount()
	{
		return amount;
	}

	bool getStackable()
	{
		return stackable;
	}

	float getDurability()
	{
		return durability;
	}

	float getTextureCoords()
	{
		return texturex, texturey;
	} 

}
//Author:		David Kilford
//Date:			Monday 17th January 2011
//Description:	Header for all inventory related needs!

#ifndef INVENTORY_H
#define INVENTORY_H

#include "GLLib.h"
#include "Texture.h"

//enum Item
//{
//	DIRT,
//	GRASS,
//	SAND,
//	STONE,
//	COBBLESTONE,
//	WOOD
//};

class Inventory
{
public:
	Inventory(int itemIDArray[]);
	void displayInventory();
	void drawIcon(int position, int itemID);
	int getInventory();
	void setInventoryNumber(int inventoryPosition);
	int getInventoryNumber();

};

#endif

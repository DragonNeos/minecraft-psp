//Author:		David Kilford
//Date:			Monday 17th January 2011
//Description:	Header for all inventory related needs!

#ifndef INVENTORY_H
#define INVENTORY_H

#include "GLLib.h"
#include "Texture.h"

class Inventory
{
public:
	Inventory(float itemIDArray[45]);
	void drawInventory(bool displayInventory);
	void drawInventoryBarIcon(int position, int itemID, float textureCoordx, float textureCoordy);
	void drawInventoryIcon(int positionx, int positiony, int ItemID, float textureCoordx, float textureCoordy);
	void drawSelectedIcon(int positionx, int positiony);
	int getInventory();
	void setInventoryNumber(int inventoryPosition);
	int getInventoryNumber();

};

#endif

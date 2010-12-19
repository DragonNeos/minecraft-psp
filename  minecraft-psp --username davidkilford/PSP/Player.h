//Author:			David Kilford
//Date:				Sunday 19th December 2010
//Description:		Header file for the player

#include <Item.h>
#include <Inventory.h>
#include <stdbool.h>

class Player
{
	float x, y, z;					//Positions
	float health;					//Player health
	float armour;					//Player armour
	float texCoordx, texCoordy;		//Player's texture coords
	float velocityx, velocityy;		//Player's velocity
	bool canJump;
	Inventory playerInventory;		//The player's inventory
	Item currentItem;				//The player's current item

	Player()
	{
		x=1;
		y=1;
		z=1;
	}

	//construct player, will be from save game
	Player(float tempx, float tempy, float tempz, float temphealth, float temparmour, float temptexCoordx, float temptexCoordy, 
		Inventory tempplayerInventory, Item tempcurrentItem)
	{
		x=tempx;
		y=tempy;
		z=tempz;
		health=temphealth;
		armour=temparmour;
		texCoordx=temptexCoordx;
		texCoordy=temptexCoordy;
		playerInventory=tempplayerInventory;
		currentItem=tempcurrentItem;
	}

	//get methods

	float getPosition()
	{
		return x, y, z;
	}

	float getHealth()
	{
		return health;
	}

	float getArmour()
	{
		return armour;
	}

	float getTexCoords()
	{
		return texCoordx, texCoordy;
	}

	bool getCanJump()
	{
		return canJump;
	}

	Inventory getPlayerInventory()
	{
		return playerInventory;
	}

	Item getCurrentItem()
	{
		return currentItem;
	}

	//set methods

	void setPosition(float setx, float sety, float setz)
	{
		x=setx;
		y=sety;
		z=setz;
	}

	void setHealth(float sHealth)
	{
		health=sHealth;
	}

	void setArmour(float sArmour)
	{
		armour=sArmour;
	}

	void setTexCoords(float setx, float sety)
	{
		texCoordx=setx;
		texCoordy=sety;
	}

	void setCanJump(bool jumpState)
	{
		canJump=jumpState;
	}

	void changeInventory(int position, Item setItem)
	{
		playerInventory.inventoryArray[position]=setItem;
	}

	void setCurrentItem(Item item)
	{
		currentItem=item;
	}

}
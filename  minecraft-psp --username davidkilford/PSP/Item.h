//Author:		David Kilford
//Date:			15th December 2010
//Description:	Header file for items.  TODO: Add a model for the item while it is held, implement methods.


class Item
{
	float x, y, z;					//Positions, self explanitory
	float inventoryID;				//Which inventory the item is placed in
	float amount;					//Amount of items in the stack
	float durability;				//How much durability the item has left
	float strength;					//How well it can break something down
	bool stackable;					//Whether you can stack the item or not
	float texturex, texturey;		//The x and y coordinates for texturing.
	

	public:Item(float posx, float posy, float posz, int invID, float dura, float size)
	{
	}

	public:Item()
	{
	}

	public:~Item()
	{
	}

	public:void dropItem()					//Method to be run when you convert the item into a dropped item
	{
		//Make a dropped item. TO BE IMPLEMENTED
	}


	public:int pickUpItem()				//Convert a dropped item into an item
	{
		return durability, amount;
	}

	//Get methods

	public:int getInventoryID()
	{
		return inventoryID;
	}

	public:float getAmount()
	{
		return amount;
	}

	public:bool getStackable()
	{
		return stackable;
	}

	public:float getDurability()
	{
		return durability;
	}

	public:float getTextureCoords()
	{
		return texturex, texturey;
	} 

}
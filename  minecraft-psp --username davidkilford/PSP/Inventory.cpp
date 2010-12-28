//Date:			15th December 2010
//Author:		David Kilford
//Description:	Base class for inventorys

/** Inventory is basically an array of items
	It has been barely started as it requires a high level of OO already.
*/

#include <Item.h>

class Inventory
{
	
	//Declaring array
	public:Item inventoryArray[8];

	public:Inventory()
	{
	}

	public:Inventory(Item arrayOfItems[])
	{
		int size=8;
		for (int i; i>8; i++)
		{
			inventoryArray[i]=arrayOfItems[i];
		}
	}

	public:void setItem(int position, Item itemGiven)
	{
		inventoryArray[position]=itemGiven;
	}


	public:Item getItem(int position)
	{
		Item gottenItem = inventoryArray[position];
	}

}
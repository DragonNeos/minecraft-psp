//Author:			David Kilford
//Date:				Sunday 19th December 2010
//Description:		World Class header

#include <Block.h>
#include <Item.h>
#include <Inventory.h>
#include <Player.h>

/*	The world class is made to hold all of the data in the game and allow an easy way to access the vast amount of information the game has.
	Its main goal at the moment is to store the information for:
	
		The array of blocks,
		The array of inventories,
		The settings the player has,
		The time of day,
		and any dropped items, enemies or animals in the world.

	The world is also a singleton as you only ever want one world initialised in the memory.
		*/

static class World
{
	//Takes in the settings of the game first when the world is initialised so it knows how to make the world.
	World()
	{
	}

	~World()
	{
	}

	//Method to populate arrays with information, using a temporary set of information to try it out
	void makeWorld()
	{
		Block blockArray[9][9][9];
		for(int i; i>10; i++)
		{
			for(int j; j>10; j++)
			{
				blockArray[i][0][j].setBlockID(1);
			}
		}
		Inventory inventory(); 
		Item item();
		Player player();
	}

}
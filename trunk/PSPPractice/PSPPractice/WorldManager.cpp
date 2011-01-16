//Author:			Mouhamad Abdallah
//Date:				Monday 17th January 2010
//Description:		Loads the world into an array of block ID's

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorldManager.h"
#include "FileManager.h"

WorldManager::WorldManager()
{
	blockNumber = 0;
}

void WorldManager::saveWorld(char *filepath, char *bufferData)
{
	file.saveFile(filepath, bufferData); //Save file with the according filepath and data given
}

void WorldManager::loadWorld(char *filepath, int &worldSize)
{
	char *buffer;
	int temp = worldSize*worldSize*worldSize; //Setting size of 3D world into a temporary variable
	printf("dumping data\n");
	buffer = file.loadFile(filepath); //Dumping data from the loaded file into a buffer
	printf("initialising blockID's\n");
	blockID = new short[temp]; //Setting amount of array in accordance to the size of the world

	printf("Converting World Data\n");
	for(int i = 0; i < temp; i++, blockNumber++)
	{
		short tempShort = static_cast<short>(buffer[blockNumber]); //Converting the individual char to a short (it will be in the form of an ascii code
		if (tempShort==13)
		{				
			blockNumber+=2;
			tempShort = (short) buffer[blockNumber];
			printf("Break (%c)\n", buffer[blockNumber]);
		}
		if (tempShort==0)
		{
			printf("block %d", blockNumber);
			printf(" (null)\n");
		}

		tempShort-=48;	//Subtracting 48 from the ASCII code to get a number (0-9)
		if (tempShort<=0)
		{
			printf("Warning num is %d at block %d\n", tempShort, blockNumber);
			printf("Char is(%c)\n", buffer[blockNumber]);
		}
		blockID[i] = tempShort;
	}
}
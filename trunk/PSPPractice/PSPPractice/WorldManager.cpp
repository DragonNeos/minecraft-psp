//Author:			David Kilford (Cleaned up by Mouhamad Abdallah, Monday 17th January 2010)
//Date:				Wednesday 12th January 2011
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
	printf("Dumping data\n");
	buffer = file.loadFile(filepath); //Dumping data from the loaded file into a buffer
	printf("Initialising blockIDs\n");
	blockID = new short[temp]; //Setting amount of array in accordance to the size of the world

	printf("Converting World Data\n");
	for(int i = 0; i < temp; i++, blockNumber+=2)
	{
		if (buffer[blockNumber]==13) //Check for line breaks
		{				
			blockNumber+=2;
			printf("Break (%c%c)\n", buffer[blockNumber+1], buffer[blockNumber+2]);
		}
		short tempShort = (static_cast<short>(buffer[blockNumber])-48)*10 + (static_cast<short>(buffer[blockNumber+1])-48); //Converting the individual char to a short (it will be in the form of an ascii code)
		//printf("tempshort = %d\n", tempShort);
		blockID[i] = tempShort;
	}
}
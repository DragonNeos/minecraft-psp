//Author:			Mouhamad Abdallah
//Date:				Monday 17th January 2010
//Description:		Loads the world into an array of block ID's

#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include "FileManager.h"

class WorldManager
{
	public:
		short *blockID;
		short blockNumber;
		FileManager file;
		WorldManager();
		void initialise();
		void saveWorld(char *filepath, char *bufferData);
		void loadWorld(char *filepath, int &worldSize);
};

#endif
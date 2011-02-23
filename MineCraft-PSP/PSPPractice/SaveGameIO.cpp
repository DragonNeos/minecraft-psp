//Author:			David Kilford
//Date:				Wedsday 12th January 2011
//Description:		Class for text IO (mainly for savegames but could be used for configuration files)

#include <stdio.h>
#include <stdlib.h>
#include "SaveGameIO.h"

	SaveGameIO::SaveGameIO()
	{
	}

	void SaveGameIO::saveGame(char* saveGamePath)		//Going to be modified later to insert relevant information into the save file based on the world
	{
		FILE * pFile;
		char buffer[] = "3 3\n\n00000\n00000\n11111\n11111\n11111";
		pFile = fopen (saveGamePath , "w");
		fwrite (buffer , 1 , 29 , pFile);
		fclose (pFile);
	}

	char* SaveGameIO::loadSaveGame(char* saveGamePath)	//Loads the game from a path
	{
		FILE * pFile;
		long lSize;
		char * buffer;
		pFile = fopen ( saveGamePath, "rb" );
		if (pFile==NULL) exit (1);
		fseek (pFile , 0 , SEEK_END);
		lSize = ftell (pFile);
		rewind (pFile);
		buffer = (char*) malloc (lSize);
		if (buffer == NULL) exit (2);
		fread (buffer,1,lSize,pFile);
		fclose (pFile);
		//free (buffer);
		return buffer;

		//float x, y, z, u, v;
		//int vert;
		//int numtriangles;
		//FILE *filein;        // file to load the world from
		//char buffer[255];

		//filein = fopen("Data/world.txt", "rt");

		//readstr(filein, buffer);
		//sscanf(oneline, "NUMPOLLIES %d\n", &numtriangles);

		//fclose(filein);
		//return buffer;
	}

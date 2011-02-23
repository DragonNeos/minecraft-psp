//Author:			David Kilford & Mouhamad Abdallah
//Date:				Wedsday 12th January 2011
//Description:		Class for text IO (mainly for savegames but could be used for configuration files)
//Modification:		Renaming and organising class to perform a better use

//Author:			David Kilford & Mouhamad Abdallah
//Date:				Wednesday 12th January 2011
//Description:		Loads and saves files
//Modification:		Renaming and organising class to perform a better use - Monday 17th January 2010

#include <stdio.h>
#include <stdlib.h>
#include "FileManager.h"

FileManager::FileManager()
{
}

void FileManager::saveFile(char* filepath, char *bufferData)		//Saves the buffer information into the given file path
{
	FILE * pFile;
	pFile = fopen (filepath , "w");
	
	fwrite (bufferData , 1 , 29 , pFile);
	fclose (pFile);
}

char* FileManager::loadFile(char* filepath)	//Loads the file from a path and returns a buffer of data
{
	FILE * pFile;
	long lSize;
	char * buffer;
	
	pFile = fopen ( filepath, "rb" );
	
	if (pFile==NULL) exit (1);
	
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	
	rewind (pFile);
	buffer = (char*) malloc (lSize);
	
	if (buffer == NULL) exit (2);
	
	fread (buffer,1,lSize,pFile);
	fclose (pFile);
	
	return buffer;
}

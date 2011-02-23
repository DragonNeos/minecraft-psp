//Author:			David Kilford & Mouhamad Abdallah
//Date:				Wednesday 12th January 2011
//Description:		Header file for file functions
//Modification:		Renaming and organising class to perform a better use - Monday 17th January 2010

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <stdio.h>
#include <stdlib.h>

class FileManager
{
	public:
	FileManager();

	void saveFile(char* filepath, char *bufferData);
	char* loadFile(char* filepath);

};

#endif
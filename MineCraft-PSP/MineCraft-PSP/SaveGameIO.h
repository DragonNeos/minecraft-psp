//Author:			David Kilford
//Date:				Wedsday 12th January 2011
//Description:		Header file for savegame functions

#include <stdio.h>
#include <stdlib.h>

class SaveGameIO
{
	public:
	SaveGameIO();

	void saveGame(char* saveGamePath);
	char* loadSaveGame(char* saveGamePath);

};
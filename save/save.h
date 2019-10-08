#include <stdio.h>

#include "../structs.h"

#ifndef _SAVE_
	#define _SAVE_

	PlInf readPlayerInf (FILE* saveFile);
	void WritePlayerInf (FILE* saveFile, PlInf *player);
	Bool seekPlayer (char* playerPseudonym, FILE* saveFile);
	void profileInit (PlInf *player, char* saveFileName);
#endif
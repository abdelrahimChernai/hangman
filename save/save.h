#include <stdio.h>

#include "../structs.h"

#ifndef _SAVE_
	#define _SAVE_

	void profileInit (PlInf *player, char* saveFileName);
	void readPlayerInf (FILE saveFile);
	void WritePlayerInf (FILE saveFile, PlInf *player);
#endif
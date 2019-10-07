#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../structs.h"

void profileInit (PlInf *player, char* saveFileName) {				//creats a player profile or giting access to it

	FILE* saveFile = NULL;		//the pointer that contains the saving file

	saveFile = fopen (saveFileName, "r+");		//assining the saving file

	if (saveFile != NULL) {		// checking if the file is opened 
		do {					//checing the length of the string
			printf("\n\t\t\tEnter your pseudonym has to have 25 or less characters\n");     //geting the player pseudonym
			printf("\t\t\t\t    ");scanf("%s", &player->pseudonym);printf("\n");
		} while (strlen(player->pseudonym) > 25);
	} else {
		printf("couldn't open the file %s\n", saveFileName);
	}
}

void readPlayerInf (FILE saveFile) {

}

void WritePlayerInf (FILE saveFile, PlInf *player) {

}
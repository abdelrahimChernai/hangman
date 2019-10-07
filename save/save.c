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
		fclose(saveFile);
	} else {
		printf("couldn't open the file %s\n", saveFileName);
	}
}

PlInf readPlayerInf (FILE* saveFile) {
	PlInf playerData;

	rewind(saveFile);							//going back to the bigginig of the file
	playerData.letter = fgetc(saveFile);		//we are using the letter in the struct as a buffer for the character we are geting
	playerData.passCode = 0;					//we are using the pass code as an index

	while ((playerData.letter != EOF) && (playerData.letter != ',')) {
		playerData.pseudonym[playerData.passCode] = playerData.letter;
		playerData.passCode++;
		playerData.letter = fgetc(saveFile);
	}

	playerData.pseudonym[playerData.passCode] = '\0';  //ending the string
}

void WritePlayerInf (FILE* saveFile, PlInf *player) {

}
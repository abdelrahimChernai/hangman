#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../structs.h"

PlInf readPlayerInf (FILE* saveFile) {
	PlInf playerData = {"", ' ', 0000, 0, 0, 1, 0, 0, 0, 0};		//if the file is empty the pseudoname will be : ""

	playerData.letter = fgetc(saveFile);		//we are using the letter in the struct as a buffer for the character we are geting
	playerData.passCode = 0;					//we are using the pass code as an index

	while ((playerData.letter != EOF) && (playerData.letter != ',')) {
		playerData.pseudonym[playerData.passCode] = playerData.letter;
		playerData.passCode++;
		playerData.letter = fgetc(saveFile);
	}

	if (playerData.letter != EOF) {
		playerData.pseudonym[playerData.passCode] = '\0';  //ending the string
		fscanf(saveFile, "%d,%d,%d,%d", &playerData.passCode, &playerData.brstScoreSolo, &playerData.bestScoreMult, &playerData.bestScorePVP);
	}

	return playerData;
}

void WritePlayerInf (FILE* saveFile, PlInf *player) {
	//fprintf(saveFile, "%s,%d,%d,%d,%d\n", );
}

Bool seekPlayer (char* playerPseudonym, FILE* saveFile) {
	PlInf playerData;
	Bool find = False;

	playerData = readPlayerInf(saveFile);		//reading the first player in the file

	while ((strcmp(playerData.pseudonym, "") != 0 /*checking if it the end of the file*/) && (!find)) {
		if (strcmp(playerData.pseudonym, playerPseudonym) == 0) {
			find = True;
		}

		fgetc(saveFile);						//escaping the \n at the end of the line
		playerData = readPlayerInf(saveFile);
	}

	return find;
}

void profileInit (PlInf *player, char* saveFileName) {				//creats a player profile or giting access to it

	FILE* saveFile = NULL;		//the pointer that contains the saving file

	saveFile = fopen (saveFileName, "r+");		//assining the saving file

	if (saveFile != NULL) {		// checking if the file is opened 
		do {					//checing the length of the string
			printf("\n\t\t\tEnter your pseudonym has to have 25 or less characters\n");     //geting the player pseudonym
			printf("\t\t\t\t    ");scanf("%s", &player->pseudonym);printf("\n");
		} while (strlen(player->pseudonym) > 25);

		rewind(saveFile);		//going to the start of the file

		if (seekPlayer("Himou", saveFile)) {
			printf("Gocha !!!\n");
		}

		fclose(saveFile);
	} else {
		printf("couldn't open the file %s\n", saveFileName);
	}
}
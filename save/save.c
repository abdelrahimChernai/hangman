#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../structs.h"
#include "../functions.h"		//we need the cleanBuffer function

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

PlInf seekPlayer (char* playerPseudonym, FILE* saveFile) {
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

	return playerData;
}

void profileInit (PlInf *player, char* saveFileName) {				//creats a player profile or giting access to it

	FILE* saveFile = NULL;		//the pointer that contains the saving file
	Bool logedIn = False;
	PlInf playerFromFile;

	saveFile = fopen (saveFileName, "r+");		//assining the saving file

	if (saveFile != NULL) {		// checking if the file is opened 
		do {
			do {					//checing the length of the string
				cleanBuffer();
				printf("\n\t\tEnter your pseudonym has to have 25 or less characters\n");     //geting the player pseudonym
				printf("\t\t\t\t    ");scanf("%s", &player->pseudonym);printf("\n");
			} while (strlen(player->pseudonym) > 25);

			rewind(saveFile);		//going to the start of the file
			playerFromFile = seekPlayer(player->pseudonym, saveFile);

			if (strcmp(playerFromFile.pseudonym, player->pseudonym) == 0) {

				cleanBuffer();
				printf("\t\tIt seems that this pseudonym is already tooken\n");
				printf("\t\tif it's you enter -- y -- if not enter -- n --\n");
				printf("\t\t\t\t\t ");scanf("%c", &player->letter);printf("\n");		//using player->letter as a buffer

				if (player->letter == 'y') {
					//do{
						cleanBuffer();
						printf("\t\t\tPleas enter your Pass Code\n");
						printf("\t\t\t\t    ");scanf("%d", &player->plNbr/*using plNbr as a buffer*/);printf("\n");
					//} while (player->passCode != playerFromFile.passCode);
					if (player->passCode != playerFromFile.passCode) {		
						logedIn = True;
						printf("\t\t\tHi %s here is your scors\n", player->pseudonym);
						printf("solo mode :%d multiplayer mode : %d player vd player mode\n", player->brstScoreSolo, player->bestScoreMult, player->bestScorePVP);
					}else {
						printf("`\t\t\tThe pass code is wrong\n");
					}
				}
			} else {
				printf("\t\tHi %s it seems that this is the first time you play\n", player->pseudonym);
				printf("pleas enter a Pass code of 4 numbers so we can safely keep your scors\n");
			}
		} while (!logedIn);

		fclose(saveFile);
	} else {
		printf("couldn't open the file %s\n", saveFileName);
	}
}
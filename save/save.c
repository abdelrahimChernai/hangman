#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../structs.h"

void profileInit(PlInf *player) {
	
	do {					//checing the length of the string
		printf("\n\t\t\tEnter your pseudonym has to have 25 or less characters\n");     //geting the player pseudonym
		printf("\t\t\t\t    ");scanf("%s", &player->pseudonym);printf("\n");
	} while (strlen(player->pseudonym) > 25);
	
}
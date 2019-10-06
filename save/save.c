#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structs.h"

void profileInit(PlInf *player) {
	
	do {					//checing the length of the string
		printf("\n\t\t\t\tEnter your pseudonym\n");     //geting the player pseudonym
		printf("\t\t\t\t    ");scanf("%s", &player->pseudonym);printf("\n");
	} while ((strlen(player->pseudonym) <= 0) || (strlen(player->pseudonym) > 25));
	
}
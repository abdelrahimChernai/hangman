#include "../structs.h"
#include "../scoreManip/scoreAtrib.h"

void letterInclud(const char *source, char *target, PlInf *playerInf)
{
    int i, booleen = 0, repeat = 0, exist = 0;
    /* the boolean is to know if the player has fond a word or no, the repeat is to know how many times the letter repeats in the cpu word
    and the exist is to check if the player didn't try this letter before*/

    for(i = 0; i < strlen(source); i++)     //for each letter of the cpu word
    {
        if(toupper(playerInf->letter) == source[i])     //we use only caps so the letter must be in the toupper func
        {
            if(toupper(playerInf->letter)  == target[i])        //we check if the letter doesn't exist in the player word
            {
                exist = 1;      //if it exists we set exist to 1 (it will be usful to punich the player)
            }
            else        //if the letter doesn't exixst in the player word
            {
                repeat++;       //we compt the repetitions of the letter in the cpuword
                booleen = 1;        //we set booleean to 1 because the letter does exist in the cpu word
                target[i] = source[i];      //then we put the letter in the player's word
            }
        }
    }

    if(exist)       //if letter has been repeated
    {
        printf("\t\tyou have already tried this letter you louse 10 pts\n");

        if(playerInf->score >= 10)      //if the player score is biggr then 10 pts we take over 10 pts
        {
            playerInf->score += -10;
        }
        else
        {
            playerInf->score = 0;       //if the players's score is smaler then 10 we set it to 0
        }
    }
    else
    {
        if(booleen)
        {
            printf("\t\tyou fond a letter, it's repeated %d times\n", repeat);      //just some info to the player
        }
        else
        {
            printf("\t\tthe letter is not in the computer word\n");
        }
    }

    scoreAtribSolo(playerInf, repeat, booleen);     //this function sets the scores
}

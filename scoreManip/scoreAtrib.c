#include "../structs.h"

#define LETTER_FIND 10
#define LETTER_REPEAT 5
#define WORD_FIND 25
#define ERROR 5

void scoreAtribSolo(PlInf *playerInf, int repeat, const int booleen)
{
    if(booleen)
    {
        playerInf->score += LETTER_FIND + LETTER_REPEAT * (repeat - 1);
    }
    else
    {
        if(playerInf->score >= ERROR)        //if the player score is bigger then th ERROR we take over the ERROR value  (check the preprocssor part)
        {
            playerInf->score -= ERROR;
        }
        else        //if the player score is smaler the ERROR we set it at 0
        {
            playerInf->score = 0;
        }
    }
}

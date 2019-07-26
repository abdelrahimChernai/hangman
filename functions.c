#include "structs.h"

void playersPositioner(PlInf *tabel, const int tabSize)
{
    int i, j, superiorsNbr;

    for(i = 0; i < tabSize; i++)
    {
        superiorsNbr = 0;       //how many players has a superior score then player "i"

        for (j = 0; j < tabSize; j++)
        {
            if(tabel[i].score < tabel[j].score)     //if a player has a superior score then the "i"
            {
                superiorsNbr ++;
            }
        }

        tabel[i].position = superiorsNbr + 1;  //we put the number o superior players + 1 in the position of the player
    }
}

void playersClasser(PlInf *tabel, const int tabSize)
{
    int i, j;
    PlInf temp;

    playersPositioner(tabel, tabSize);

    for(i = 0; i < tabSize; i++)
    {
        tabel[i].position--;
    }

    for(i = 0; i < tabSize; i++)
    {
        if(i != tabel[i].position)      //checking if the player isn't in the right box
        {
            if(tabel[i].score == tabel[tabel[i].position].score)        //checking if the players have not the same score
            {
                tabel[i].position++;        //if the player have the same score we put the player "i" in the next box
                i = 0;      //going back at the biginig to check that all the players are in the right box
            }

            temp = tabel[tabel[i].position];
            tabel[tabel[i].position] = tabel[i];
            tabel[i] = temp;
            i = 0;      //going back at the biginig to check that all the players are in the right box
        }
    }

    playersPositioner(tabel, tabSize);      //giving back all the players their right position
}

void cleanBuffer()
{
    char c;

    do
    {
        c = getchar();
    }while(c != '\n'); //we can also do while(c != '\n' && c != EOF)
}

void stringAffectCap(const char *valuToAffect, char *target)
{
    int i;

    for(i = 0; i < strlen(valuToAffect); i++)
    {
        target[i] = toupper(valuToAffect[i]);
    }

    target[i] = '\0';
}

void stringAffect(const char *valuToAffect, char *target)
{
    int i;

    for(i = 0; i < strlen(valuToAffect); i++)
    {
        target[i] = valuToAffect[i];
    }

    target[i] = '\0';
}

PlInf playerSelect(const int theActuPlPosition, const int thePlayrsNbr, PlInf *thePlayersList)
{
    const int i = theActuPlPosition - 1;
    PlInf theActuPl;

    stringAffect(thePlayersList[i].pseudonym, theActuPl.pseudonym);
    theActuPl.score = thePlayersList[i].score;
    theActuPl.win = thePlayersList[i].win;
    theActuPl.position = thePlayersList[i].position;
    theActuPl.plNbr = thePlayersList[i].plNbr;

    return theActuPl;
}

PlInf playerSelectP_V_P(const int theActuPlNbr, const int thePlayersNbr, PlInf *thePlayersList)
{
    int i;
    PlInf thePlayer;

    for(i = 0; i < thePlayersNbr; i++)
    {
        if(theActuPlNbr == thePlayersList[i].plNbr)
        {
            stringAffect(thePlayersList[i].pseudonym, thePlayer.pseudonym);
            thePlayer.score = thePlayersList[i].score;
            thePlayer.win = thePlayersList[i].win;
            thePlayer.position = thePlayersList[i].position;
            thePlayer.plNbr = thePlayersList[i].plNbr;
        }
    }

    return thePlayer;
}

int atempsInit(const char *TheWord)
{
    int atempsNbr = 0;

    switch(strlen(TheWord))
    {
        case 1 ... 4:
            atempsNbr = 7;
        break;

        case 5 ... 6:
            atempsNbr = 11;
        break;

        case 7 ... 12:
            atempsNbr = 15;
        break;

        case 13 ... 16:
            atempsNbr = 19;
        break;

        default:
            atempsNbr = 23;
        break;
    }

    return atempsNbr;
}

void nbrToAarry(int theNbr, char *target)
{
    int i, temp;

    temp = theNbr;
    i = 0;

    while(temp / 10 != 0)
    {
        i++;
        temp /= 10;
    }

    target[i + 1] = '\0';

    for(i; 0 <= i; i--)
    {
        target[i] = (theNbr % 10) + 48;
        theNbr /= 10;
    }
}

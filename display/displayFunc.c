#include <stdio.h>
#include "..\structs.h"

#define MAX_SIZE 100000

void dispalyFunc(const char *fileName, int linesNbr)
{
    char string[MAX_SIZE];
    FILE *file = NULL;

    file = fopen(fileName, "r");
        if(file != NULL)
        {
            for(linesNbr; linesNbr > 0; linesNbr--)
            {
                fgets(string, MAX_SIZE, file);
                printf("%s", string);
            }
            fclose(file);
        }
        else
        {
            printf("file opening failed");
        }
}

void ScoreFileileFormating(const char *fileName, const int playersNbr, PlInf *thePlayersList)
{
    void spacManag(const char *theString, FILE *theFile)
    {
        char result[18];
        int length = strlen(theString), i, befor =(19 - strlen(theString)) / 2, after = 19 - strlen(theString) - befor;

        for(i = 0; i < befor; i++)
        {
            result[i] = ' ';
        }

        for(i ; i < befor + strlen(theString); i++)
        {
            result[i] = theString[i - befor];
        }

        for(i ; i < 18; i++)
        {
            result[i] = ' ';
        }

        result[i] = '\0';
        fprintf(theFile, "%s", result);
    }

    char nbr[MAX_SIZE];
    int i;
    FILE *theFile = NULL;

    theFile = fopen(fileName, "w");
        if(theFile != NULL)
        {
                fprintf(theFile, "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= score tabel =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
                fprintf(theFile, "+     position     =     pseudonym     =       score       =        win        =\n");
                fprintf(theFile, "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");

                for(i = 0; i < playersNbr; i++)
                {
                    fputc('+', theFile);
                    nbrToAarry(thePlayersList[i].position, nbr);
                    spacManag(nbr, theFile);
                    fputs("=", theFile);
                    spacManag(thePlayersList[i].pseudonym, theFile);
                    fputs(" =", theFile);
                    nbrToAarry(thePlayersList[i].score, nbr);
                    spacManag(nbr, theFile);
                    fputs(" =", theFile);
                    nbrToAarry(thePlayersList[i].win, nbr);
                    spacManag(nbr, theFile);
                    fputs(" =\n", theFile);
                    fprintf(theFile, "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
                }
                fclose(theFile);
        }
        else
        {
            printf("file opening failed");
        }
}

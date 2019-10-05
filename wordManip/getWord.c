#include <stdio.h>
#define MAX_SIZE 100


int linesConter(const char *fileName)
{
    int linesNbr = 0;
    char c;
    FILE *theFile = NULL;

    theFile = fopen(fileName, "r");
        if(theFile != NULL)
        {
            c = fgetc(theFile);

            while(c != EOF)
            {
                if(c == '\n')
                {
                    linesNbr++;
                }

                c = fgetc(theFile);
            }
        }
        else
        {
            printf("the file couldn't be opend\n");
        }

        return linesNbr;
}

void goToLine (int theLine, FILE *theFile)
{
    int i;
    char c, string[100];

    for(i = 0; i <= theLine; i++)
    {
        c = fgetc(theFile);

        while(c != '\n')
        {
            c = fgetc(theFile);
        }

    }
}

void getWord(const char *fileName, char *target)
{
    int linesNbr, theWordLine;
    FILE *theFile = NULL;

    linesNbr = linesConter(fileName);
    theFile = fopen(fileName, "r");
        if(theFile != NULL)
        {
            srand(time(NULL));
            theWordLine = rand() % linesNbr;
            goToLine(theWordLine, theFile);
            fscanf(theFile, "%s", target);
        }
        else
        {
            printf("the file couldn't be opend\n");
        }
}

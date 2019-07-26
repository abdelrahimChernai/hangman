#include <stdio.h>

#include "..\structs.h"

#ifndef _GET_WORD_
    #define _GET_WORD_
    int linesConter(const char *fileName);
    void goToLine (int theLine, FILE *theFile);
    void getWord(const char *fileNamen, char *target);
#endif

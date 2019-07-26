#include "structs.h"

#ifndef _FUNC_
    #define _FUNC_

    void playersPositioner(PlInf *tabel, const int tabSize);        //to give each player his position proportionally whith his score
    void playersClasser(PlInf *tabel, const int tabSize);       //to put each player at his box in the players array propotionally whith his score
    void cleanBuffer();     //it's necessary to scan a char
    void stringAffectCap(const char *valuToAffect, char *target);       //afects a string to a char pointer in capitals letters
    void stringAffect(const char *valuToAffect, char *target);      //afects a string to a char pointer
    PlInf playerSelect(const int theActuPlPosition, const int thePlayrsNbr, PlInf *thePlayersList);     //returns the actual players informaions accordig to the position
    PlInf playerSelectP_V_P(const int theActuPlNbr, const int thePlayersNbr, PlInf *thePlayersList);        //returns the player who choses the word information
    int atempsInit(const char *TheWord);        //sets the atemps number acordig to the word length
    void nbrToAarry(int theNbr, char *target);       //convert a nuber to a string
#endif

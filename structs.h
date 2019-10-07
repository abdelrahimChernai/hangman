#ifndef _STUCT_
    #define _STUCT_
    typedef struct {            //to save players data
        char pseudonym[25];     //to store the player pseudonym
        char letter;            //to stor the player letter
        int passCode;           //to access the saveed profile
        int score;              //to store the player score (we will need it to class the players)
        int win;                //to store the win number of the player
        int position;           //the rank of the player
        int plNbr;              //the nomber of the layer (player 1, player 2 ...)
        int brstScoreSolo;      //player's best score in solo mode
        int bestScoreMult;      //player's best score in multiplayer mode
        int bestScorePVP;       //player's best score in player vs player mode
    } PlInf;

    typedef enum {
        false = 0,
        true
    } Bool;

#endif

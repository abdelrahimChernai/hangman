void plWordInit(const char *pathernWord, char *targetWord)
{
    int i;

    for(i = 0; i < strlen(pathernWord); i++)
    {
        targetWord[i] = '*';        //for each leter in the cpuWord we put a "*" in the player word at the same position
    }

    targetWord[i] = '\0';       //the string must end by '\0' to avoid buggs
}

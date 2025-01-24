#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdbool.h>

struct words{
    char *word;
    float score;
    float SD;
    int SIS_array[10];
};

void getWord(struct words* word_list, char* word, float score, float SD, int SIS_array[10]);

void printWords(struct words* word_list, int size, char **sentence_list, int size2);

bool isNegationWord(char *word);

void freeAll(struct words* word_list, int size, char **sentence_list, int size2);

#endif /* FUNCTIONS_H */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct words{
    char *word;
    float score;
    float SD;
    int SIS_array[10];
};

// used to store words as a structure, in the element of the list that passed into the function
void getWord(struct words* word_list, char* word, float score, float SD, int SIS_array[]){
    word_list -> word = strdup(word);
    word_list -> score = score;
    word_list -> SD = SD;
    for (int i = 0; i < 10; i++) {
        word_list -> SIS_array[i] = SIS_array[i];
    }
}

// check if a word is a negation word
bool isNegationWord(char *word){
    char *negation_words[] = {"not", "no", "nor", "neither", "can't", "cannot", "never"};

    // if the word that passed into the function is a negation word, then return true, else false
    for (int i = 0; i < 7; i++){
        if (strcmp(word, negation_words[i]) == 0){
            return true;
        }
    }
    return false;
}

// execute and print data as formatted
void printWords(struct words* word_list, int size, char **sentence_list, int size2){
    printf("            String Sample                                                                                      Score\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size2; i++) {
        float sum = 0;
        int word_count = 0;
        int negationCount = 0;

        // get the sentence that is going to seperate into words
        char *sentence_copy = strdup(sentence_list[i]);
        char *word = strtok(sentence_copy, " ,.;!?"); // get the first word

        // count number of negation words, because there might be something like not not not
        if (word != NULL && isNegationWord(word)){
            negationCount += 1;
        }

        //printf("Word %d: %s \n", word_count, word);
        while (word != NULL) {
            // check if each words are in the word_list
            for (int j = 0; j < size; j++) {
                if (strcasecmp(word_list[j].word, word) == 0){
                    
                    if(negationCount % 2 == 1){
                        sum += (-word_list[j].score);
                    }
                    
                    else{
                        sum += word_list[j].score;
                    }
                    negationCount = 0;
                    //printf("Score of %s : %f\n", word_list[j].word, word_list[j].score);
                    break; // break after find a word that matches
                }
            }
            word_count++;
            word = strtok(NULL, " ,.;!?"); // continue seperation
            if (word != NULL && isNegationWord(word)){
                negationCount += 1;
            }
            //printf("Word %d: %s \n", word_count, word);
        }
        free(sentence_copy); // freeeeeeeeeeeeeeeeeeee

        float average = word_count > 0 ? sum / word_count : 0;
        printf("%-110s %.4f\n", sentence_list[i], average); // print everything with format
    }
}

// free all pointers
void freeAll(struct words* word_list, int size, char **sentence_list, int size2){
    for (int i = 0; i < size2; i++) {
        free(sentence_list[i]); // free all
    }
    free(sentence_list);
    
    for (int k = 0; k < size; k++){
        free(word_list[k].word); // freeeeee bird
    }
    free(word_list);
}
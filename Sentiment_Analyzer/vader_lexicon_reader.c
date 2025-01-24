#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    // check if input meet the requirements
    if (argc < 2 || argc > 3) {
        printf("Usage: %s <path_to_lexicon>\n", argv[0]);
        return 1;
    }
    
    // "vader_lexicon.txt"
    // open and check the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file 1.\n");
        return 1;
    }

    struct words *word_list = NULL;

    // setup 
    char text[1024];
    int word_count = 0;

    while(fgets(text, sizeof(text), file)){

        struct words *temp = (struct words *)realloc(word_list, (word_count + 1) * sizeof(struct words));
        
        // if failed to realloc, end the program and close the file, free the word_list
        if (!temp) {
            free(word_list);
                fclose(file);
                return 1;
            }
        
        // assign address with new memory to the word_list
        word_list = temp;
        
        // seperate the line ... with tokens
        // hope there will be no more bugs
        float value2 = 0.0, value3 = 0.0; // deault as 0
        int SIS[10] = {0};
        int SIS_count = 0;

        char *token1 = strtok(text, "\t");
        if (token1 == NULL) {
            token1 = ""; // set default as an empty string
        }

        char *token2 = strtok(NULL, "\t");
        if (token2 != NULL) {
            value2 = atof(token2); // if nothing went wrong, transfer value in token2 to value2
        }
        
        char *token3 = strtok(NULL, "\t");
        if (token3 != NULL) {
            value3 = atof(token3); // if nothing went wrong, transfer value in token3 to value3
        }

        char *token4 = strtok(NULL, "\t");
        // assign token4 to SIS, if token4 is not empty
        if (token4 != NULL){      
            while(*token4 != '\0' && SIS_count < 10 && token4 != NULL){
                if (isdigit((unsigned char)*token4)){
                    SIS[SIS_count] = *token4;
                    SIS_count++;
                }
                token4++;
            };
        }

        // store these data into word_list
        getWord(&word_list[word_count], token1, value2, value3, SIS);

        word_count++;
    }

    fclose(file);

    // "validation.txt"
    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        perror("Error opening file 2.\n");
        return 1;
    }
    
    // setup
    char **sentence_list = NULL;
    char text2[1024];
    int sentence_count = 0; 

    while (fgets(text2, sizeof(text2), file)) {
        text2[strcspn(text2, "\r\n")] = 0;

        // reallocate memory for new sentences
        char **temp = realloc(sentence_list, (sentence_count + 1) * sizeof(char *));
        if (!temp) {
            freeAll(word_list, word_count, sentence_list, sentence_count); // free!!!!!
            fclose(file2);
            return 1;
        }
        sentence_list = temp;
        // copy the new sentence to its new home!!!!!!!!
        sentence_list[sentence_count] = strdup(text2);
        if (!sentence_list[sentence_count]) {
            // exit if strdup failed
            freeAll(word_list, word_count, sentence_list, sentence_count); // freeeeeeeeee (bird)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            fclose(file2);
            return 1;
        }

        sentence_count++;
    }
    
    // close file 2
    fclose(file2);

    // print all and free all
    printWords(word_list, word_count, sentence_list, sentence_count);
    freeAll(word_list, word_count, sentence_list, sentence_count);
    return 0;
}
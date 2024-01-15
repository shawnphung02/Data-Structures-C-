/**
--------------------------------------------------
Project: cp264-a3q2
File:    myword.c
Author:  Shawn Phung
Version: 2023-02-03
--------------------------------------------------
*/
 
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"


int process_word(char *filename, WORD *words, WORDSTATS *wordstats) {
    const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
    char line[MAX_LINE_LEN];
    char *word_token = NULL; int j;
    FILE *fp = fopen(filename, "r");    // open file
    int found = 0;

    while(fgets(line, MAX_LINE_LEN, fp) != NULL){
        wordstats->line_count++;
        lower_case(line);   // change to lowercase
        str_trim(line);    // trim uneccessary whitespaces
        word_token = (char *)strtok(line, delimiters);  // get first word token

        while(word_token != NULL){  // token is not null
            wordstats->total_word_count++;  // update count
            found = 0;  // boolean to check for existing word in array
            for(j = 0; j < wordstats->distinct_word_count; j++){
                if(strcmp(word_token, words[j].word) == 0){ // compare token to array indexes
                    words[j].frequency++;   // increment frequency
                    found = 1;  // found existing word
                    break;  // break and move on
                }
            }
            if(!found){ // word not found
                strcpy(words[wordstats->distinct_word_count].word, word_token); // copy token into array
                words[wordstats->distinct_word_count].frequency = 1;    // update frequency to 1
                wordstats->distinct_word_count++;   // update total word count
            }

            word_token = (char*)strtok(NULL, delimiters); //next word
        }
    }   
    fclose(fp);
    return 0;
}

int save_file(char *filename, WORD *words, WORDSTATS *wordstats) {
    FILE *fp = fopen(filename, "w");  // open file to write
    
    // output stats
    fprintf(fp, "word stats:value\n");
    fprintf(fp, "line count:%d\n", wordstats->line_count);
    fprintf(fp, "total word count:%d\n", wordstats->total_word_count);
    fprintf(fp, "distinct word count:%d\n\n", wordstats->distinct_word_count);
    fprintf(fp, "distinct words:frequency\n");

    // output word frequency
    for (int i = 0; i < wordstats->distinct_word_count; i++) {
        fprintf(fp, "%s:%d\n", words[i].word, words[i].frequency);
    }

    fclose(fp);
    return 0;
}
/*
--------------------------------------------------
Project: CP264-a4q2
File:    myrecord.c
Author:  Shawn Phung
Version: 2023-02-01
--------------------------------------------------
*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mysort.h"
#include "myrecord.h"

#define MAX_LINE 100


char letter_grade(float s){
    char grade;

    if(s >= 90 && s <= 100){
        grade = 'S';
    }else if(s >= 80 && s < 90){
        grade = 'A';
    }else if(s >= 70 && s < 80){
        grade = 'B';
    }else if(s >= 60 && s < 70){
        grade = 'C';
    }else if(s >= 50 && s < 60){
        grade = 'D';
    }else if(s >= 0 && s < 50){
        grade = 'F';
    }

    return grade;
}

STATS process_data(RECORD *dataset, int n) {    
    STATS stats = {};
    stats.count = n;
    int i;
    float total = 0;
    
    // Calculate mean
    for(i = 0; i < n; i++) total += dataset[i].score;     // Get total score
    stats.mean = total / (float)n;                         // Get mean score

    // Calculate standard deviation
    for(i = 0; i < n; i++) stats.stddev += (dataset[i].score - stats.mean)*(dataset[i].score - stats.mean);
    stats.stddev = sqrt(stats.stddev/n);


    // Calculate median
    float scores[n];
    for(i = 0; i < n; i++){
        scores[i] = dataset[i].score;       // Create float array to store all score values
    }
    quick_sort(scores, 0, n-1);             // Sort scores
    
    if(n % 2 == 1){
        stats.median = scores[n/2];                             // n is odd
    }else{
        stats.median = (scores[n/2 - 1] + scores[n/2]) / 2;     // n is even
    }

    return stats;
}

int import_data(char *infilename, RECORD *records) {

    FILE *file = fopen(infilename, "r");              // Open file
    int i = 0;                                        // Record counter
    char line[100];
    char delimiters[] = ",\n\r";
    char *token = NULL;       

    if(file == NULL){
        printf("There are no text files to read.");
    }else{
        while(fgets(line, sizeof(line), file) != NULL){   // While read line is not NULL
            token = (char *)strtok(line, delimiters);      // Split line using delimiters
            strcpy(records[i].name, token);               // Record first token as student name
            token = (char *)strtok(NULL, delimiters);      // Next token
            records[i].score = atof(token);               // Convert token to float and then assign to student score
            i++;
        }   
    }

    fclose(file);
    return i;
}


int report_data(char *outfilename, RECORD *records, STATS stats) {
   
    FILE *fp;
    fp = fopen(outfilename, "w"); 
    int i;
    
    fprintf(fp, "stats:value\n");
    fprintf(fp, "count:%i\n", stats.count);
    fprintf(fp, "mean:%4.1f\n", stats.mean);
    fprintf(fp, "stddev:%4.1f\n", stats.stddev);
    fprintf(fp, "median:%4.1f\n", stats.median);

    fprintf(fp, "\nname,score,grade");

    for(i = 0; i < stats.count; i++){
        fprintf(fp, "\n%s,%.1f,%c", records[i].name, records[i].score, letter_grade(records[i].score));
    }
    
    fclose(fp);
    
}
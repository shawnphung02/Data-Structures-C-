/*
--------------------------------------------------
Project: CP264-a4q2
File:    myrecord.h
Author:  HBF
Version: 2023-02-01
--------------------------------------------------
*/
 
#ifndef MYRECORD_H
#define MYRECORD_H 

typedef struct {
  char name[40];
  float score;
} RECORD;

typedef struct {
  int count;
  float mean;
  float stddev;
  float median;
} STATS;

char letter_grade(float score);
int import_data(char *infilename, RECORD *records); 
STATS process_data(RECORD *records, int count);   
int report_data(char *outfilename,  RECORD *records, STATS stats);
 
#endif
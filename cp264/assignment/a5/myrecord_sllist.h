/*
--------------------------------------------------
Project: CP264-a5q1
File:    myrecord_sllist.h
Author:  Shawn Phung
Version: 2023-02-07
--------------------------------------------------
*/
#ifndef SLLIST_H
#define SLLIST_H

typedef struct {
  char name[40];
  float score;
} RECORD;

typedef struct node {
    RECORD data;
    struct node *next;
} NODE;

typedef struct sllist {
    int length;
    NODE *start;
} SLLIST;

NODE *search(SLLIST *sllistp, char *name);
void insert(SLLIST *sllistp, char *name, float score);
int delete(SLLIST *sllistp,  char *name);
void clean(SLLIST *sllistp);

#endif
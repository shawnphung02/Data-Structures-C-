/*--------------------------------------------------
Project: CP264-a7q3
File:    myrecord_bst.h
Author:  Shawn Phung
Version: 2023-03-02
--------------------------------------------------
*/
#ifndef MYRECORD_BST_H
#define MYRECORD_BST_H

typedef struct {
  TNODE *root;
} BST;

typedef struct {
  int count;
  float mean;
  float stddev;
  float median;
} STATS;

void add_data(BST *bst, STATS *stats, char *name, float score);
void remove_data(BST *bst, STATS *stats, char *name);
#endif
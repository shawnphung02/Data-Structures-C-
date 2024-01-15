/*--------------------------------------------------
Project: cp264-a7q3
File:    myrecord_avl.c
Author:  Shawn Phung
Version: 2023-03-02
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "avl.h"
#include "myrecord_avl.h"

void merge_tree(TNODE **rootp1, TNODE **rootp2) {  
  // use recursive or iterative algorithm to traverse tree rootp2, 
  // get record data of each node and insert into rootp1
  TNODE *temp = *rootp2;

  if(temp != NULL){
    merge_tree(rootp1, &temp->left);
    insert_avl(rootp1, temp->data.name, temp->data.score);
    merge_tree(rootp1, &temp->right);
  }
}

void merge_data(AVL *t1, AVL *t2) {
  merge_tree(&t1->root, &t2->root);
  // aggregate existing t1->stats and  t2->stats, and then update t1->stats 
  int count1 = t1->stats.count;
  float mean1 = t1->stats.mean;
  float stddev1 = t1->stats.stddev;

  int count2 = t2->stats.count;
  float mean2 = t2->stats.mean;
  float stddev2 = t2->stats.stddev;

  int count = count1 + count2;
  float mean = (mean1 * count1 + mean2 * count2) / count;
  float stddev = sqrtf((stddev1*stddev1*count1 + mean1*mean1*count1 + stddev2*stddev2*count2 + mean2*mean2*count2)/count - mean*mean);

  t1->stats.count = count;
  t1->stats.mean = mean;
  t1->stats.stddev = stddev;
}

void clear_avl(AVL *avl) {
  TNODE *root = avl->root;
  clear_tree(&root);
  avl->root = NULL;
  avl->stats.count = 0;
  avl->stats.mean = 0;
  avl->stats.stddev = 0;
  avl->stats.median = 0;
}
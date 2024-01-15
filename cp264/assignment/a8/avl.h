/*
 * your program signature
 */ 
 
#ifndef AVL_H
#define AVL_H
#include "stdlib.h"

typedef struct record {
  char name[40];
  float score;
} RECORD;

typedef struct tnode {
    RECORD data;
    int height;
    struct tnode *left;
    struct tnode *right;
} TNODE;


/* This returns the balance factor at the given root */
int balance_factor(TNODE *root);

/* This checks if the tree is AVL tree, returns 1 if true, 0 otherwise */
int is_avl(TNODE *root);

/* This does the left rotation at the root */
TNODE *rotate_left(TNODE *root);  

/* This does the right rotation at the root */
TNODE *rotate_right(TNODE *root);

/* This inserts record (name, score) into the AVL tree using name as key */
void insert_avl(TNODE **rootp, char *name, float score);

/* This deletes node of data.name from the AVL tree */ 
void delete_avl(TNODE **rootp, char *name);  

/* This searches node by data.name from the AVL tree */ 
TNODE *search_avl(TNODE *root, char *name);

/* This clean the tree and free dynamically allocated node space*/
void clear_tree(TNODE **rootp); 

#endif
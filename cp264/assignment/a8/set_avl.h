/*
 * your program signature
 */ 
 
#ifndef SET_AVL_H
#define SET_AVL_H

typedef struct {
  TNODE *root;
  int size;
} SET;

int size(SET *s);
int contains_element(SET *s, char *e); 
void add_element(SET *s, char *e);
void remove_element(SET *s, char *e);
void clear_set(SET *s);

#endif 
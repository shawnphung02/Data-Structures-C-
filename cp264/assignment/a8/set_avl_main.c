/*
--------------------------------------------------
Project: cp264-a8q3
File:    set_avl_main.c
Description: public test driver program
Author:  HBF  
Version: 2023-03-09
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "avl.h"
#include "set_avl.h"

void display_inorder(TNODE *root);
void display_set_info(SET *set, char *prefix);

int main(int argc, char* args[]) {
  SET set={0};
  display_set_info(&set, "after declare set");
  
  add_element(&set, "a");
  add_element(&set, "b");
  add_element(&set, "c");
  add_element(&set, "c");
  display_set_info(&set, "after add_element");
  
  char *str="a";
  printf("contains(set,%s):%d\n", str, contains_element(&set, str));
  str="d";
  printf("contains(set,%s):%d\n", str, contains_element(&set, str));
  
  remove_element(&set, "c");
  display_set_info(&set, "after remove_element");
  
  clear_set(&set);
  display_set_info(&set, "after clear_set");

  return 0;
}

void display_inorder(TNODE *root) {
  if (root) {
    if (root->left) display_inorder(root->left);
    printf("%s ", root->data.name);
    if (root->right) display_inorder(root->right);
  }
}

void display_set_info(SET *s, char *prefix) {
  printf("%s size(set):%d\n", prefix, size(s));
  if (size(s) == 0)
    printf("%s elements:%s", prefix, "empty");
  else {
    printf("%s elements:", prefix); 
    display_inorder(s->root); 
  }
  printf("\n"); 
  
}

/*--------------------------------------------------
Project: cp264-a5q2
File:    dllist_main.c  public test driver
Author:  HBF
Version: 2023-02-10
--------------------------------------------------
*/ 

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

void display_forward(DLLIST *dllistp);
void display_backward(DLLIST *dllistp);

int main(int argc, char* args[]) {
  DLLIST dllist = {0};
  int i=0;
  for (i = 0; i<10; i++) {
    insert_start(&dllist, new_node('0'+i));
  }
  printf("display_forward:");
  display_forward(&dllist);
  printf("\n"); 
  printf("display_backward:");
  display_backward(&dllist);
  printf("\nlength:%d\n",dllist.length);
  
  delete_start(&dllist);
  delete_end(&dllist);
  printf("display_forward2:");
  display_forward(&dllist);
  printf("\nlength2:%d\n",dllist.length); 
  clean(&dllist); 
  
  for (i = 0; i<10; i++) {
    insert_end(&dllist, new_node('a'+i));
  }
  printf("display_forward3:");
  display_forward(&dllist);
  printf("\nlength3:%d\n",dllist.length);   
  clean(&dllist); 
  printf("length4:%d\n",dllist.length);   
  return 0;
}

void display_forward(DLLIST *dllistp) {
  NODE *np = dllistp->start;
  while ( np != NULL) {
    printf("%c", np->data);
    np = np->next;
  }
}

void display_backward(DLLIST *dllistp) {
  NODE *np = dllistp->end;
  while ( np != NULL) {
    printf("%c", np->data);
    np = np->prev;
  }
}
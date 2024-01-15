/*--------------------------------------------------
Project: cp264-a9q1
File:    hash_main.c 
Description: public test driver
Author:  HBF
Version: 2023-03-15
--------------------------------------------------
*/   

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "hash.h"

int htsize = 5;

void display_search_result(char *key, HASHNODE *p);
void display_hashtable(HASHTABLE *ht, int option);

int main(int argc, char *argv[]) {
  int n = 20;	
  if (argc > 1) sscanf(argv[1],"%d",&htsize); //  htsize = atoi(argv[1]);
  if (argc > 2) sscanf(argv[2],"%d",&n);      //  n = atoi(argv[2]);
  
  HASHTABLE *ht = new_hashtable(htsize);
  
  int i=0;
  char name[20];
  for (i=0; i<n; i++) {
	name[0] = i+'a';
  	name[1] = '\0';
	insert(ht, new_hashnode(name, i));
  }
  printf("\nhash table after insertions:\n");
  display_hashtable(ht, 0);
  char *key = "a";
  HASHNODE *hn = search(ht, key);
  display_search_result(key, hn);
  
  for (i=0; i<n/2; i++) {
	name[0] = i+'a';
  	name[1] = '\0';
	delete(ht, name);
  }
  printf("hash table after deletions:\n");
  display_hashtable(ht, 0);  
  key = "b";
  hn = search(ht, key);
  display_search_result(key, hn);
 
  clean_hash(&ht);
  
  return 0;
}


void display_search_result(char *key, HASHNODE *p){
  if (p) 
    printf("search(%s):(%s,%d)\n", key, p->name, p->value);
  else
    printf("search(%s):NULL\n", key);	
}

void display_hashtable(HASHTABLE *ht, int option) {
  int i = 0;
  HASHNODE *p;
  if (option == 0) {
    printf("size:%d\n", ht->size);
    printf("count:%d\n", ht->count);
    printf("index:list of (key,value) pairs of the same hash index");
    for (i = 0; i < ht->size; i++) {
      p = *(ht->hna + i);
	  if (!p) printf("\n%d:NULL", i);
      else { printf("\n%d:", i); 
	    while (p) {
          printf("(%s,%d) ", p->name, p->value);
          p = p->next;
        }
	  }
    }
    printf("\n");
  } else { 
    for (i = 0; i < ht->size; i++) {
      p = *(ht->hna + i);
      while (p) {
        printf("%s:%d\n", p->name, p->value);
        p = p->next;
      }
    }  
  }
}




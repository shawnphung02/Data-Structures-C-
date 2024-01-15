/*
--------------------------------------------------
Project: cp264-a9q1
File:    hash.c
Author:  Shawn Phung  
Version: 2023-03-15
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "hash.h"

extern int htsize;

int hash(char *name) {
  unsigned int value = 0, i;
  char *p = name;
  while (*p) {
    value = 31 * value + *p;
    p++;
  }
  return value % htsize;
}

HASHNODE *new_hashnode(char *name, int value) {
    // Allocate space for node
    HASHNODE *node = (HASHNODE*)malloc(sizeof(HASHNODE));
    
    // Node is null
    if(node == NULL) return NULL;

    strncpy(node->name, name, sizeof(node->name));
    node->name[sizeof(node->name) - 1] = '\0';
    node->value = value;
    node->next = NULL;

    return node;
}

HASHTABLE *new_hashtable(int size) {
    HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
    ht->hna = (HASHNODE**) malloc(sizeof(HASHNODE**)*size);
    int i;
    for (i=0; i<size; i++) *(ht->hna+i) = NULL; // initialize to NULL
    ht->size = size;
    ht->count = 0;
    return ht;
}

HASHNODE *search(HASHTABLE *ht, char *name) { 
    int i = hash(name); // compute the hash index of name
    HASHNODE *p = ht->hna[i]; // get the linked list of the hash value
    // search the linked list, if name is matched, return the node
    while(p != NULL){
        // Traverse through linked list
        if(strcmp(p->name, name) == 0){
            // Name found, return node
            return p;
        }
        // Else iterate
        p = p->next;
    }
    // End of list reached, return NULL
    return NULL;
}

int insert(HASHTABLE *ht, HASHNODE *np) {
    int i = hash(np->name);
    HASHNODE *p = ht->hna[i], *prev = NULL;
    if (p == NULL) ht->hna[i] = np;
    else {
        while (p && strcmp(np->name, p->name ) > 0) { // find insert positionprev = p; p = p->next;
            prev = p;
            p = p->next;
        }
        if (p && strcmp(np->name, p->name) == 0) { // when matched, update value// update the p node value by np->value, free np, return 0
            p->value = np->value;
            free(np);
            return 0;
        }
        // insert np into the linked list before node p
        if (prev == NULL) ht->hna[i] = np;
        else prev->next = np;
        np->next = p;
    }
    ht->count++;
    return 1;
}

int delete(HASHTABLE *ht, char *name) {
    int i = hash(name);
    HASHNODE *p = ht->hna[i], *prev = NULL;
    while (p != NULL && strcmp(p->name, name) != 0) {
        // Iterate through linked list for name
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        // Node not found
        return 0;   
    }else if(prev == NULL){
        // Node is at the head of the list, move head to next node
        ht->hna[i] = p->next;
    }else{
        // Node found somehwere in the middle
        prev->next = p->next;
    }

    // Free memory
    free(p->name);
    free(p);
    // Update hash table count
    ht->count--;

    return 1;
}


void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HASHNODE *sp = ht->hna[0], *p, *temp;
  int i;
  for (i = 0; i < ht->size; i++) {
    p = ht->hna[i];
    while (p) {
      temp = p;  
      p = p->next;
      free(temp);
    }
    ht->hna[i] = NULL;
  }
  free(ht->hna);
  ht->hna = NULL;
  *htp = NULL;
}
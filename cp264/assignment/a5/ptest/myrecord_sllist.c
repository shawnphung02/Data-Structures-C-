/*
--------------------------------------------------
Project: CP264-a5q1
File:    myrecord_sllist.c
Author:  Shawn Phung
Version: 2023-02-07
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "myrecord_sllist.h"

NODE *search(SLLIST *sllistp, char *name) {
    NODE *p = sllistp->start;                 // Create pointer
    while(p != NULL){                         // Traverse through list
        if(strcmp(p->data.name, name) == 0){
            return p;
        }
        p = p->next;                          // Next node
    }
    return NULL;                              // name not found, return NULL
}

void insert(SLLIST *sllistp, char *name, float score) {
    NODE* np = (NODE *) malloc(sizeof(NODE)); // Create new node
    strcpy(np->data.name, name);              // Copy name to node
    np->data.score = score;                   // Copy score to node
    np->next = NULL;
    NODE *prev = NULL, *p = sllistp->start;   // Create pointer node and prev node 

    while(p!=NULL && strcmp(p->data.name, name) < 0){   // Traverse through list
        prev = p;                             // Set p to prev
        p = p->next;
    }

    if(prev == NULL){                     // Empty linked list or found at start
        sllistp->start = np;              // Insert at beginning   
    }else{
        prev->next = np;                  // insert between prev and p
    }
   
    np->next = p;                         // Set next to p
    sllistp->length++;                    // Update length
    
}

int delete(SLLIST *sllistp, char *name) {
    NODE *prev = NULL, *p = sllistp->start;   // Create prev and pointer node
    
    while(p != NULL){                         // Traverse through list
        if(strcmp(p->data.name, name) == 0){       // Name matches
            if(prev == NULL){                     // First node is matched, first node will be deleted
                sllistp->start = p->next;         
            }else{
                prev->next = p->next;             // Name not matched, next node
            }        
            free(p);                              // Free memory from p
            sllistp->length--;                    // Update length
            return 1;          
        }
        prev = p;                                 // Save p to prev
        p = p->next;                              // Next node
    }
    return 0;
}

void clean(SLLIST *sllistp) {
    NODE *temp, *p = sllistp->start;          // Create pointer node and temp node

    while(p != NULL){                         // Traverse list
        temp = p;                             // Save p to temp
        p = p->next;                          // Next node
        free(temp);
    }

    sllistp->start = NULL;                    // Set list start to NULL
    sllistp->length = 0;                      // Set list length to 0
}
 

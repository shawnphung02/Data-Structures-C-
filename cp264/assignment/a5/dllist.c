/*
--------------------------------------------------
Project: CP264-a5q2
File:    dllist.c
Author:  Shawn Phung
Version: 2023-02-07
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE *new_node(char data) {
  
    NODE* np = (NODE*) malloc(sizeof(NODE));      // Allocate memory for new node

    np->data = data;                              // Update data
    np->prev = NULL;                              // Update prev
    np->next = NULL;                              // Update next

    return np;                                    // Return pointer of node
}

void clean(DLLIST *dllistp) {
    NODE *np = dllistp->start;      // Node pointer at start of list

    while (np) {                    // Traverse list
        NODE *next = np->next;      // Get next node
        free(np);                   // Free memory from np
        np = next;                  // Update node
    }

    dllistp->start = NULL;          // Update start of list
    dllistp->end = NULL;            // Update end of list
    dllistp->length = 0;            // Update list length
}

void insert_start(DLLIST *dllistp, NODE *np) {
    if(dllistp->start == NULL){     // Double linked list empty
        np->prev = NULL;            // Update prev
        np->next = NULL;            // Update next
        dllistp->start = np;        // Update start
        dllistp->end = np;         // Update end
    }else{                         // List not empty
        np->prev = NULL;           // Update prev
        np->next = dllistp->start;  // Insert in start of list
        dllistp->start->prev = np;  // Link node to list
        dllistp->start = np;        // Update front
    }
    dllistp->length++;             // Update length
}

void insert_end(DLLIST *dllistp, NODE *np) {
    if(dllistp->start == NULL){       // Double linked list empty
        np->prev = NULL;           // Update prev
        np->next = NULL;           // Update next
        dllistp->start = np;       // Update start
        dllistp->end = np;         // Update end
    }else{                         // List not empty
        np->next = NULL;           // Update next
        np->prev = dllistp->end;   // Insert node to end of list
        dllistp->end->next = np;   // Link node to end of list
        dllistp->end = np;         // Update end of list
    }
        dllistp->length++;
}

void delete_start(DLLIST *dllistp) {
    NODE* np = dllistp->start;                  // Create node pointer at start
   
    if(dllistp->length == 0){                   // List empty, return
        return;
    }else if(dllistp->length == 1){             // List has one node
        dllistp->start = NULL;                  // Update start
        dllistp->end = NULL;                    // Update end
    }else{
        dllistp->start = np->next;              // Move start to next node
        dllistp->start->prev = NULL;            // Update prev
    }
    free(np);                                   // Free memory from np
    dllistp->length--;                          // Update length
}

void delete_end(DLLIST *dllistp) {
    NODE* np = dllistp->end;                  // Create node pointer at start
   
    if(dllistp->length == 0){                 // List empty, return
        return;
    }else if(dllistp->length == 1){           // List has one node
        dllistp->start = NULL;                // Update start
        dllistp->end = NULL;                  // Update end
    }else{
        dllistp->end = np->prev;              // Move end to previous node
        dllistp->end->next = NULL;            // Update next
    }
    free(np);                                 // Free memory from np
    dllistp->length--;                        // Update length
}
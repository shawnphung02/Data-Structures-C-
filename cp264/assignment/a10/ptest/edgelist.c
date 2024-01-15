/*
 * your program signature
 */ 

#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h"

EDGELIST *new_edgelist() {
    EDGELIST *p = malloc(sizeof(EDGELIST)); // Allocate memory for new edgelist
    p->start = NULL;
    p->end = NULL;
    p->size = 0;
    
    return p;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
    // Make a new edge
    EDGE *p = (EDGE*)malloc(sizeof(EDGE));
    p->from = from;
    p->to = to;
    p->weight = weight;
    p->next = NULL;

    // Empty list
    if(g->size == 0){
        g->start = p;
        g->end = p;
    }else{
    // Non-empty list
        g->end->next = p;       // Insert new edge
        g->end = p;             // Updte end
    }
    // Update list size
    g->size++;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
    // Make a new edge
    EDGE *p = (EDGE*)malloc(sizeof(EDGE));
    p->from = from;
    p->to = to;
    p->weight = weight;
    p->next = NULL;

    // Empty list
    if(g->size == 0){
        g->start = p;
        g->end = p;
    }else{
    // Non-empty list
        EDGELIST *temp = new_edgelist();    // Make copy of list
        temp = g;

        g->start = p;                       // Insert new edge
        g->start->next = temp->start;              // Merge with old list
    }
    // Update list size
    g->size++;
}

int weight_edgelist(EDGELIST *g) {
    // Make an edge pointer to traverse through edge list
    EDGE *p = (EDGE*)malloc(sizeof(EDGE));
    int weight = 0;
    p = g->start;                   // Move pointer to list start

    // Traverse list
    while(p != NULL){
        weight += p->weight;        // Increment weight by edge weight
        p = p->next;                // Next edge
    }

    return weight;
}

void clean_edgelist(EDGELIST **gp) {    
    EDGE *p = (*gp)->start;        // Pointer to traverse through list 
    EDGE *next;                    // Pointer for following list element
    while (p != NULL) {
        next = p->next;
        free(p);
        p = next;
    }
    free(*gp);
    *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
  if (g == NULL) return;
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;
  while (p) {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}
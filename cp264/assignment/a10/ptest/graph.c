/*
 * your program signature
 */ 

#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h" 
#include "graph.h"

GRAPH *new_graph(int order) {
    GRAPH *p = malloc(sizeof(GRAPH));       // Allocate memory for new graph
    p->nodes = NULL;
    p->order = 0;
    p->size = 0;

    // Set nodes
    p->nodes = malloc(order * sizeof(GNODE*));      // Create array of GNODE pointers

    for(int i = 0; i < order; i++){
        p->nodes[i] = malloc(sizeof(GNODE));        // Create GNODE object
        p->nodes[i]->nid = i;                       // Set node id to i
        p->nodes[i]->neighbor = NULL;               // Initialize neighbor linked list
    }

    return p;
}

void add_edge(GRAPH *g, int from, int to, int weight) {
    ADJNODE *new_node = (ADJNODE*)malloc(sizeof(ADJNODE));      // Allocate memory for new ADJNODE
    new_node->nid = to;    
    new_node->weight = weight;  
    new_node->next = NULL;

    // Create GNODE to traverse through graph, to find from node
    GNODE *p = NULL;
    for(int i = 0; i < g->order; i++){
        if(g->nodes[i]->nid == from){
            // From node found, stop
            p = g->nodes[i];
            break;
        }
    }

    // From node not found
    if(p == NULL){
        p = (GNODE*)malloc(sizeof(GNODE));
        p->nid = from;
        p->neighbor = NULL;

        // Add p vertex to graph
        g->nodes[g->order++] = p;
    }

    // Add adjacency node to 'from' vertex
    if(p->neighbor == NULL){
        // No existing neighnor, insert 
        p->neighbor = new_node;
    }else{
        // Neighbor exists, traverse through all of neighbors
        ADJNODE *current = p->neighbor;
        while(current->next != NULL){
            current = current->next;        
        }
        // End of neighbors reached, insert
        current->next = new_node;
    }

    // Update size
    g->size++;
}

int get_weight(GRAPH *g, int from, int to) {
    // Invalid from or to 
    if(from >= g->order || to >= g->order){
        return INFINITY;
    }

    ADJNODE *p = g->nodes[from]->neighbor;      // Create adjancency list to traverse through
    while(p != NULL){                   // Traverse through list
        if(p->nid == to){
            // to node found, return weight
            return p->weight;
        }
        // Not found, keep going
        p = p->next;
    }

    // to node not found in list
    return INFINITY;
}

void clean_graph(GRAPH **gp) {
    if(*gp == NULL) return;     // Empty graph

    for(int i = 0; i < (*gp)->order; i++){
        ADJNODE *anp = (*gp)->nodes[i]->neighbor;       // Get list of neighbors

        // Traverse through neighbors
        while(anp){
            ADJNODE *temp = anp;
            anp = anp->next;
            // Free node by node
            free(temp);
        }
        free((*gp)->nodes[i]);
    }

    free((*gp)->nodes);     // Free memory from nodes list
    free(*gp);              // Free memory from graph
    *gp = NULL;             // Set graph to NULL
}

void display_bforder(GRAPH *g, int start) {
    if(g == NULL) return;

    int n = g->order, visited[n], i;
    for(i = 0; i < n; i++) {visited[i] = 0;}

    // Bread-first traversal
    QUEUE q = {0};
    GNODE *gnp = NULL;
    ADJNODE *anp = NULL;

    enqueue(&q, g->nodes[start]);
    visited[start] = 1;

    while(q.front){
        gnp = (GNODE*)dequeue(&q);
        printf("%d ", gnp->nid);

        anp = gnp->neighbor;        // Get neighbor list
        while(anp){    
            if(!visited[anp->nid]){
                visited[anp->nid] = i;
                enqueue(&q, g->nodes[anp->nid]); 
            }  
            anp = anp->next;
        }     
    }
    clean_queue(&q);  
}

void display_dforder(GRAPH *g, int start) {
     if(g == NULL) return;

    int n = g->order, visited[n], i;
    for(i = 0; i < n; i++) {visited[i] = 0;}

    // Bread-first traversal
    STACK s = {0};
    GNODE *gnp = NULL;
    ADJNODE *anp = NULL;

    push(&s, g->nodes[start]);
    visited[start] = 1;

    while(s.top){
        gnp = (GNODE*)pop(&s);
        printf("%d ", gnp->nid);

        anp = gnp->neighbor;        // Get neighbor list
        while(anp){    
            if(!visited[anp->nid]){
                visited[anp->nid] = i;
                push(&s, g->nodes[anp->nid]); 
            }  
            anp = anp->next;
        }     
    }
    clean_stack(&s);  
}


void display_graph(GRAPH *g) {
  if (g == NULL) return;
  printf("order:%d\n", g->order);
  printf("size:%d\n", g->size);
  printf("from:(to weight)");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d) ", ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
}
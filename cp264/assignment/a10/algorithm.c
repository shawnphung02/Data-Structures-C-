/*
--------------------------------------------------
Project: cp264-a6q3
File:    algorithm.c
Author:  Shawn Phung
ID:      200814180  
Version: 2023-03-15
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h> 
#include "heap.h"
#include "algorithm.h"

EDGELIST *mst_prim(GRAPH *g, int start) {
    if(g == NULL) return NULL;

    int i, heapindex, u, n = g->order, T[n], parent[n];     // Support data structures
    for(i = 0; i < n; i++){
        T[i] = 0;          //Intialize to 0, T[i] == 1 means i is in the tree
        parent[i] = -1;     // Initialize to -1, meaning no parent is defined
    }                      
    
    HEAPNODE hn;            // Temp heap node variable
    HEAP *h = new_heap(4);  // Heap for finding minimum weight edge

    // Set first node from start
    T[start] = 1;
    
    // Add heap node for each corresponding neighbor into heap
    ADJNODE *temp = g->nodes[start]->neighbor;
    while(temp){
        hn.key = temp->weight;
        hn.data = temp->nid;
        insert(h, hn);
        parent[temp->nid] = start;
        temp = temp->next;
    }

    // Create EDGELIST object to hold MST
    EDGELIST *mst = new_edgelist();

    // Main loop of Prim's algorithm
    while(h->size > 0){
        hn = extract_min(h);                        // Get min node
        i = hn.data;
        
        if(T[i] == 0){
            T[i] = 1;
            add_edge_end(mst, parent[i], i, hn.key);    // Add to MST
            // Update keys of neighbors of the newly added node
            temp = g->nodes[i]->neighbor;
                while(temp){
                    heapindex = find_data_index(h, temp->nid);
                    if(heapindex >= 0){
                        if(T[temp->nid] == 0 && temp->weight < h->hna[heapindex].key){
                            change_key(h, heapindex, temp->weight);
                            parent[temp->nid] = i;
                        }
                    }else{
                        if(T[temp->nid] == 0){
                            hn.key = temp->weight;
                            hn.data = temp->nid;
                            insert(h, hn);   
                            parent[temp->nid] = i;
                        }                   
                    }
                    temp = temp->next;     
                }
        }
    }
    clean_heap(&h);
    return mst;
}

EDGELIST *spt_dijkstra(GRAPH *g, int start) {
    if (!g) return NULL;
    EDGELIST *spt = new_edgelist();
    int i, heapindex, u, n = g->order;
    int T[n], parent[n], label[n];
    HEAPNODE hn;
    HEAP *h = new_heap(4);

    for(i = 0; i < n; i++){
        T[i] = 0;
        label[i] == 9999;
    }

    ADJNODE *temp = g->nodes[start]->neighbor;
    label[start] = 0;
    T[start] = 1;

    while(temp){
        hn.key = temp->weight + label[start];
        hn.data = temp->nid;
        insert(h, hn);
        parent[temp->nid] = start;
        temp = temp->next;
    }

    while(h->size > 0){
        hn = extract_min(h);
        u = hn.data;
        T[u] = 1;
        label[u] = hn.key;
        add_edge_end(spt, parent[u], u, label[u] - label[parent[u]]);
        temp = g->nodes[u]->neighbor;
        while (temp) {
            if (T[temp->nid] == 0) {
                heapindex = find_data_index(h, temp->nid);
                if (heapindex >= 0) {
                    if (label[u] + temp->weight < h->hna[heapindex].key) {
                        change_key(h, heapindex, label[u] + temp->weight);
                        parent[temp->nid] = u;
                    }
                } else {
                    hn.key = label[u] + temp->weight;
                    hn.data = temp->nid;
                    insert(h, hn);
                    parent[temp->nid] = u;
                }
            }
            temp = temp->next;
        }
    }
    return spt;
}

EDGELIST *sp_dijkstra(GRAPH *g, int start, int end) {
    if (!g) return NULL;
    EDGELIST *spt = new_edgelist();
    EDGELIST *sp = new_edgelist();
    int i, heapindex, u, n = g->order;
    int T[n], parent[n], label[n], p[n];
    HEAPNODE hn;
    HEAP *h = new_heap(4);

    for(i = 0; i < n; i++){
        T[i] = 0;
        label[i] = 9999; // fixed typo: should be '=' instead of '=='
        p[i] = -1; // initialize all nodes to unvisited
    }

    ADJNODE *temp = g->nodes[start]->neighbor;
    label[start] = 0;
    T[start] = 1;

    while(temp){
        hn.key = temp->weight + label[start];
        hn.data = temp->nid;
        insert(h, hn);
        parent[temp->nid] = start;
        temp = temp->next;
    }

    while(h->size > 0){
        hn = extract_min(h);
        u = hn.data;
        T[u] = 1;
        label[u] = hn.key;
        add_edge_end(spt, parent[u], u, label[u] - label[parent[u]]);
        temp = g->nodes[u]->neighbor;

        while (temp) {
            if (T[temp->nid] == 0) {
                heapindex = find_data_index(h, temp->nid);
                if (heapindex >= 0) {
                    if (label[u] + temp->weight < h->hna[heapindex].key) {
                        change_key(h, heapindex, label[u] + temp->weight);
                        parent[temp->nid] = u;
                        p[temp->nid] = u; // update shortest path
                    }
                } else {
                    hn.key = label[u] + temp->weight;
                    hn.data = temp->nid;
                    insert(h, hn);
                    parent[temp->nid] = u;
                    p[temp->nid] = u; // update shortest path
                }
            }
            temp = temp->next;
        }

        // Stop growing tree if end node is reached
        if (u == end) break;
    }

    // Backtracking to find the shortest path
    i = end;
    while (1) {
        if (i == start) break;
        add_edge_start(sp, p[i], i, label[i]-label[p[i]]);
        i = p[i];
    }
    return sp;
}
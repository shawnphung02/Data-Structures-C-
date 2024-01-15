/*--------------------------------------------------
Project: CP264-a7q3
File:    myrecord_bst.c
Author:  Shawn Phung
Version: 2023-03-02
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_data(BST *bst, STATS *stats, char *name, float score) {
    // check if the node already exists in the tree
    TNODE *existing_node = search(bst->root, name);
    if (existing_node == NULL) {
        // Insert the new node
        insert(&(bst->root), name, score);

        // Create copy of stats 
        float count = (float)stats->count;
        float mean = stats->mean;
        float stddev = stats->stddev;
        // Update stats
        stats->count = count + 1;
        stats->mean = ((count * mean) + score) / (count + (float)1);
        stats->stddev = sqrtf(((count * (stddev * stddev + mean * mean)) + (score * score))/((float)1)/(stats->count) - (stats->mean * stats->mean));
    }
}

void remove_data(BST *bst, STATS *stats, char *name) {
    // Search for the node with the given name
    TNODE *p = search(bst->root, name);
    if (p != NULL) {
        // Get the score of the node to be deleted
        int score = p->data.score;
        // Delete the node
        delete(&(bst->root), name);
        // Create copy of stats
        int count = stats->count;
        float mean = stats->mean;
        float stddev = stats->stddev;
        // Update stats
        stats->count = count - 1;
        stats->mean = ((count * mean) + score) / (count - 1);
        stats->stddev = sqrtf(((count * (stddev * stddev + mean * mean)) + (score * score))/((float)1)/(stats->count) - (stats->mean * stats->mean));
    }
}
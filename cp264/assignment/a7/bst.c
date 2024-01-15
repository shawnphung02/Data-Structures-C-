/*--------------------------------------------------
Project: CP264-a7q2
File:    bst.c
Author:  Shawn Phung
Version: 2023-03-02
--------------------------------------------------
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// you can add auxiliary function for the insert and delete operations

TNODE *new_node(char *name, float score) {
    TNODE *np = malloc(sizeof(TNODE));      // Initialize and allocate memory for np    
    np->left = NULL;            // Update np left
    np->right = NULL;           // Update np right
    strcpy(np->data.name, name);
    np->data.score = score;
   
    return np;
}

void clean_tree(TNODE **rootp) {
    if(*rootp){         // rootp is not empty
        clean_tree(&(*rootp)->left);        // Recursively clean left sub-tree
        clean_tree(&(*rootp)->right);       // Recursively clean right sub-tree
        free((*rootp)->data.name);
        free(*rootp);                       // Free memory from root
        *rootp = NULL;                      // Reset rootp pointer
    }   
}

TNODE *search(TNODE *root, char *name) {
    if(root == NULL) return NULL;

    int cmp = strcmp(name, root->data.name);
    if(cmp == 0) return root;
    else if(cmp < 0) return search(root->left, name);
    else return search(root->right, name);
    
}

void insert(TNODE **rootp, char *name, float score) {
    TNODE *newnp = new_node(name, score);

    if(*rootp){
        int comp = strcmp(name, (*rootp)->data.name);

        if(comp < 0){
            insert(&((*rootp)->left), name, score);
        }else if(comp > 0){
            insert(&((*rootp)->right), name, score);
        }else{
            // Dupe name, free memory and move on
            free(newnp);
        }
    }else{
        *rootp = newnp;
    }
}

void delete(TNODE **rootp, char *name) {
    if(*rootp){
        int cmp = strcmp(name, (*rootp)->data.name);

        if(cmp < 0) delete(&((*rootp)->left), name);
        else if(cmp >0) delete(&((*rootp)->right), name);
        else{
            TNODE *temp;

            if((*rootp)->left == NULL){
                temp = *rootp;
                *rootp = (*rootp)->right;
                free(temp);
            }else if((*rootp)->right == NULL){
                temp = *rootp;
                *rootp = (*rootp)->left;
                free(temp);
            }else{
                temp = (*rootp)->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                (*rootp)->data = temp->data;
                delete(&((*rootp)->right), temp->data.name);
            }
        }
    }
}
/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TNODE *new_node(int value) {
    TNODE *np = malloc(sizeof(TNODE));             // Initialize node and allocate memory
    np->data = value;       // Assign value to node data
    // Update node left and right
    np->left = NULL;
    np->right = NULL;

    return np;
}

TPROPS get_props(TNODE *root) {
    TPROPS r = {0};
    if(root){
        TPROPS lp = get_props(root->left);        // Get props of left sub-tree (recursivve)
        TPROPS rp = get_props(root->right);       // Get props of right sub-tree (recursive)
        r.count = 1 + lp.count + rp.count;        // Calculate total number of nodes (root + left sub-tree + right sub-tree)
        r.height = 1 + __max(lp.height, rp.height);
    }
    return r;
}


void display_preorder(TNODE *root) {
    if(root){
        printf("%c ", root->data);           // Print root 
        display_preorder(root->left);        // Call function recursively for left sub-tree
        display_preorder(root->right);       // Call function recursively for right sub-tre
    }
}

void display_inorder(TNODE *root) {
    if(root){
        display_inorder(root->left);        // Call function recursively for left sub-tree
        printf("%c ", root->data);           // Print root 
        display_inorder(root->right);       // Call function recursively for right sub-tree
    }
}

void display_postorder(TNODE *root) {
    if(root){
        display_postorder(root->left);      // Call function recursively for left sub-tree
        display_postorder(root->right);     // Call function recursively for right sub-tree
        printf("%c ", root->data);           // Print root 
    }
}

/* use auxiliary queue data structure for the algorithm  */
void display_bforder(TNODE *root) {
    if (root){
      QUEUE queue = {0};
      enqueue(&queue, root);            // Enqueue the root

      while(queue.front){               // While queue is not empty
        TNODE *np = dequeue(&queue);    // Assign first queue element to np
        printf("%c ", np->data);         // Print value of np
        if(np->left) enqueue(&queue, np->left);     // Call function recursively for left sub-tree
        if(np->right) enqueue(&queue, np->right);   // Call function rectusively for right sub-tree
      }  
    }
}

/* use auxiliary queue data structure for the algorithm  */
TNODE *iterative_bfs(TNODE *root, int val) {
    QUEUE queue = {0};
    TNODE *r = NULL, *p = NULL;
    
    if(root){               // Tree is not empty
        enqueue(&queue, root);      // Enqueue the root
        while(queue.front){         // While queue is not empty
            p = dequeue(&queue);           // Assign first queue element to p
            if(p->data == val){            // p matches the key, break
                r = p;
                break;
            }
            if(p->left) enqueue(&queue, p->left);       // Queue up node in left sub-tree if possible
            if(p->right) enqueue(&queue, p->right);     // Queue up node in right sub-tree if possible
        }
    }
    clean_queue(&queue);        // End of queue  reached, clean queue
    return r;
}

TNODE *iterative_dfs(TNODE *root, int val) {
    STACK stack = {0};
    TNODE *r = NULL, *p = NULL;

    if(root){               // Tree is not empty
        push(&stack, root);         // Push root to top of stack
        while(stack.top){           // While stack is not empty
            p = (TNODE *)(stack.top)->data;         // Parse the top element of the stack to a TNODE, then assign it to p
            if(p->data == val){                     // p matches the key, break
                r = p;
                break;                                    
            }
            pop(&stack);            // Pop top element of the stack
            if(p->right) push(&stack, p->right);
            if(p->left) push(&stack, p->left);
        }

    }
    clean_stack(&stack);        // Clean stack
    return r;
}

void clean_tree(TNODE **rootp) {
    if(*rootp){         // rootp is not empty
        clean_tree(&(*rootp)->left);        // Recursively clean left sub-tree
        clean_tree(&(*rootp)->right);       // Recursively clean right sub-tree
        free(*rootp);                       // Free memory from root
        *rootp = NULL;                      // Reset rootp pointer
    }
}

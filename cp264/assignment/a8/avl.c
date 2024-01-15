/*
 * your program signature
 */ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl.h"
 
 
TNODE *extract_smallest_node(TNODE **rootp) {
  TNODE *p = *rootp, *parent = NULL;
  if (p) {
    while (p->left) {
      parent = p;
      p = p->left;
    }
    if (parent == NULL)
      *rootp = p->right;
    else
      parent->left = p->right;
    
    p->left = NULL;
    p->right = NULL;
  }
  return p;
}


int max(int a, int b) 
{
  return (a > b)? a : b;
}

int height(TNODE *np)
{
  if (np == NULL) return 0;
  return np->height;
}


int balance_factor(TNODE* np) {
    if(np == NULL) return 0;
    return height(np->left) - height(np->right);
}

int is_avl(TNODE *root) {
    if(root == NULL){
        return 1;
    }else{
        int bf = balance_factor(root);
        if(bf > 1 || bf < -1){
            return 0;
        }
        else if(is_avl(root->left) == 0){
            return 0;
        }
        else if(is_avl(root->right) == 0){
            return 0;
        }
        else return 1;
    }
}

TNODE *rotate_right(TNODE *y)
{   
    TNODE *x = y->left;
    TNODE *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

TNODE *rotate_left(TNODE *x)
{
    TNODE *y = x->right;
    TNODE *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


void insert_avl(TNODE **rootp, char *name, float score)
{
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np == NULL) return;
  strcpy(np->data.name, name);
  np->data.score = score;
  np->height = 1;
  np->left = NULL;
  np->right = NULL;
  
  // 1. Perform the normal BST insertion
  if (*rootp == NULL) {
    *rootp = np;
    return;
  }
  
  TNODE *root = *rootp;
  if (strcmp(name, root->data.name) < 0 )
    insert_avl(&root->left, name, score);
  else if (strcmp(name, root->data.name) > 0 )
    insert_avl(&root->right, name, score);
  else return;

  // 2. update height of this root node
    root->height = 1 + max(height(root->left), height(root->right));
 
  // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int bf = balance_factor(root);
  // 4. re-balance if not balanced
  if(bf > 1){
    if(balance_factor(root->left) >= 0){
        *rootp = rotate_right(root);
    }else{
        root->left = rotate_left(root->left);
        *rootp = rotate_right(root);
    }
  }else if(bf < -1){
    if(balance_factor(root->right) <= 0){
        *rootp = rotate_left(root);
    }else{
        root->right = rotate_right(root->right);
        *rootp = rotate_left(root);
    }
  }
}

void delete_avl(TNODE **rootp, char *name)
{
  TNODE *root = *rootp;
  TNODE* np;

  if (root == NULL) return;

  if (strcmp(name, root->data.name) == 0) {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      *rootp = NULL;
    } else if (root->left != NULL && root->right == NULL) {
      np = root->left;
      free(root);
      *rootp = np;
    } else if (root->left == NULL && root->right != NULL) {
      np = root->right;
      free(root);
      *rootp = np;
    } else if (root->left != NULL && root->right != NULL) {
      np = extract_smallest_node(&root->right);
      np->left = root->left;
      np->right = root->right;
      free(root);
      *rootp = np;
    }
  } else {
    if (strcmp(name, root->data.name) < 0) {
      delete_avl(&root->left, name);
    } else {
      delete_avl(&root->right, name);
    }
  }

    // If the tree had only one node then return
    if (*rootp == NULL) return;

    root = *rootp;
  
    // 2. update height of this root node
    root->height = 1 + max(height(root->left), height(root->right));
 
    // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int bf = balance_factor(root);
    // 4. re-balance if not balanced
    if(bf > 1){
        if(balance_factor(root->left) >= 0){
            *rootp = rotate_right(root);
        }else{
            root->left = rotate_left(root->left);
            *rootp = rotate_right(root);
        }
    }else if(bf < -1){
        if(balance_factor(root->right) <= 0){
            *rootp = rotate_left(root);
        }else{
            root->right = rotate_right(root->right);
            *rootp = rotate_left(root);
        }
    }
}



TNODE *search_avl(TNODE *root, char *name) {
  TNODE *r = NULL, *p=root; 
  while (p) {
    if (strcmp(name, p->data.name) == 0) {
       r=p;
       break;
    } else if (strcmp(name, root->data.name) < 0) 
      p = p->left;
    else { 
       p = p->right;
    }  
  }    
  return r;
}

void clear_tree(TNODE **rootp) {
  TNODE *p = *rootp;
  if (p) {
    if (p->left)
      clear_tree(&p->left);
    if (p->right)
      clear_tree(&p->right);
    free(p);
  }
  *rootp = NULL;
}
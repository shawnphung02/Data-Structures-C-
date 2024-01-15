/*--------------------------------------------------
Project: cp264-a6q1
File:    stack.c
Description: Holds functions involving stacks
Author:  Shawn Phung        200814180
Version: 2023-02-16
--------------------------------------------------
*/
#include <stdio.h>
#include "stack.h"
#include <stddef.h>

void push(STACK *sp, NODE *np) {
    np->next = sp->top;
    sp->top = np;
    sp->height++;
}

NODE *pop(STACK *sp) {
    NODE *np;
    if(!sp->top){
        // Stack empty
        np = NULL;
    }else{
        // Get top node
        np = sp->top;
        // Remove top node
        sp->top = sp->top->next;
        // Update height and node
        sp->height--;
        np->next = NULL;
    }

    return np;
}

void clean_stack(STACK *sp) {
    if(sp->top){
        // Clean
        clean(&sp->top);
    }
    // Update top
    sp->top = NULL;
    // Update height
    sp->height = 0;
}

/*--------------------------------------------------
Project: cp264-a6q3
File:    expression.c
Description: Holds primary and auxillary functions for operations
Author:  Shawn Phung    200814180 
Version: 2023-03-03
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function 
*/
int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}

/*
 * auxiliary function 
*/
int type(char c) {
  if (c >= '0' &&  c <= '9' )
     return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if ( c == ')')
    return 3;  
  else 
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
    char *p = infixstr;
    QUEUE queue = {0}; // for returning postfix expression queue
    STACK stack = {0}; // working stack as an intermediate DS
    int sign = 1, num = 0; // for number string conversion
    while (*p) { // expression str traversal
    if ( *p == '-' && (p == infixstr || *(p-1) == '(') ) {// get the sign of an operand
        sign = -1;
    }
    else if (*p >= '0' && *p <= '9') { // case of number
        num = *p-'0';
        while ((*(p+1) >= '0' && *(p+1) <= '9')) { num = num*10 + *(p+1)-'0'; p++; }
        enqueue(&queue, new_node(sign*num, 0));
        sign = 1;
    } else if (*p == '(') { // case of (
        // Push to top of stack
        push(&stack, new_node(*p, 2));
    } else if (*p == ')') { // case of )
        // Add top stack element to queue
        enqueue(&queue, pop(&stack));
        // Remove top ( element
        pop(&stack);
    }
    else if (type(*p) == 1) { // case of operator
        push(&stack, new_node(*p, 1));
    }
    p++; // move to next character
    }

    // End of infixstr reached, start moving stack elements to queue
    while(stack.top){
      enqueue(&queue, pop(&stack));
    }

    return queue;
}

int evaluate_postfix(QUEUE queue) {
  NODE *p = queue.front;
  STACK stack = {0}; // stack for postfix evaluation
  int type = 0;
  while (p) { // traversal the queue linked list
    type = p->type;
    if (type == 0) { // operant
      push(&stack, new_node(p->data, 0));
    } else if (type==1){ // operator
      int equals;
      // Get operands
      int num1 = pop(&stack)->data;
      int num2 = pop(&stack)->data;
      // Get operator value
      if(p->data == '+'){
        // Addition
        equals = num2 + num1;
      }else if(p->data == '-'){
        // Subtraction
        equals = num2 - num1;
      }else if(p->data == '*'){
        // Multiplication
        equals = num2 * num1;
      }else if(p->data == '/'){
        // Division
        equals = num2 / num1;
      }else if(p->data == '%'){
        // Modulus
        equals = num2 % num1;
      }
      // Push the result to top of stack
      push(&stack, new_node(equals, 0));
    }
      p = p->next;
    }

  int result = stack.top->data;
  clean_stack(&stack); 
  return result;
  }


int evaluate_infix(char *infixstr) {
  // Convert infix to postfix
  QUEUE in_to_post = infix_to_postfix(infixstr);
  // Evaluate postfix
  int result = evaluate_postfix(in_to_post);

  return result;
}
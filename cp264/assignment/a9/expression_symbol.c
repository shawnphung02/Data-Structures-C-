/*
--------------------------------------------------
Project: cp264-a9q2
File:    expression.c
Author:  Shawn Phung  
Version: 2023-03-15
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression_symbol.h"

int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}


QUEUE infix_to_postfix_symbol(char *infixstr,  HASHTABLE *ht) {
// your implementation
}


int evaluate_infix_symbol(char *infixstr,  HASHTABLE *ht) {
// your implementation
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

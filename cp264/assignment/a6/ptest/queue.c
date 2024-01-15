/*--------------------------------------------------
Project: cp264-a6q1
File:    queue.c
Description: Holds functions involving queues
Author:  Shawn Phung        200814180
Version: 2023-02-16
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
    // Queue empty, insert in front
    if(qp->length == 0){
        // Insert and point rear to front
        qp->front = np;
        qp->rear = qp->front;
        // Update front and rear
        qp->front->next = NULL;
        qp->rear->next = NULL;
    }else{
        // Queue not empty
        // Insert to end of queue
        qp->rear->next = np;
        qp->rear = np;
        // Update rear
        qp->rear->next = NULL;
    }
    // Update count
    qp->length++;
}  

NODE *dequeue(QUEUE *qp) {
    // Get front value
    NODE *np = qp->front;
    // Queue not empty and has 2 or more nodes
    if(qp->front->next){
        // Dequeue front node
        qp->front = qp->front->next;
        // Update length
        qp->length--;
    }else if(qp->length == 1){
        // Queue only has 1 node
        // Update front and rear
        qp->front = NULL;
        qp->rear = NULL;
        // Update length
        qp->length--;
    }else{
        printf("Empty queue");
    }
    return np;
}

void clean_queue(QUEUE *qp) {
// your implementation
// call clean() function in common.h 
// set qp's front, rare to NULL and length to 0
    if(qp->front){
        clean(&qp->front);
    }
    // Update front and rear
    qp->front = NULL;
    qp->rear = NULL;
    // Update length
    qp->length = 0;
}                     
/*
--------------------------------------------------
Project: cp264-a9q3
File:    heap.h
Description: header of heap ds
Author:  HBF  
Version: 2023-03-16
--------------------------------------------------
*/

#ifndef HEAP_H
#define HEAP_H
 
#define MIN_CAPACITY 4

typedef int KEYTYPE;  // key type
typedef int DATA;     // data type 

typedef struct heap_node { // data element ds for binary heap
  KEYTYPE key;
  DATA data;
} HEAPNODE;

typedef struct heap {  
  unsigned int capacity; // the MAX length of array
  unsigned int size;     // the current heap size, i.e., heap node count
  HEAPNODE *hna;  // pointer pointing the heap node array
} HEAP;

/* create and return a heap data structure 
to instantiate and return the pointer of the above heap structure,  size=0, capacity=4, allocate memory space to hold array of 
elements of the capacity and store pointer in data
*/
HEAP *new_heap(int capacity);

void clean_heap(HEAP **hpp);

/* this inserts the given node data a into the heap; When the heap size is equal to the capacity, the inserting process needs first to expand data array by doubling its amount. This may need to copy the data of old array to new array, secondly insert the new data element into the end of the array and update size.*/
void insert(HEAP *heap, HEAPNODE a);

/* this gets the data element of minimum key and delete the element from the binary heap. When the heap size  is no more than a quarter of the capacity, it needs to shrink the data array by half to free the unused memory space. */
HEAPNODE extract_min(HEAP *heap);

/* this changes the key of given element at given index position to new_key, and return the index of updated key node */
int change_key(HEAP *heap, int index, KEYTYPE new_key);

/* this finds and returns the first index of the heap node matching given data */
int find_data_index(HEAP *heap, DATA data);

/* this compare two key values a and b, return -1 if a<b, 0 if a=b, 1 if a>b  */ 
int cmp(KEYTYPE a, KEYTYPE b); 


#endif 
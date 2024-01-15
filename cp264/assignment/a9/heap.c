/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"


HEAP *new_heap(int capacity)
{
  HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
  hp->capacity = capacity;
  hp->size = 0;
  hp->hna = (HEAPNODE *) malloc(sizeof(HEAPNODE) * capacity);
  return hp;
}

void insert(HEAP *heap, HEAPNODE new_node)
{
// your implementation
}

HEAPNODE extract_min(HEAP *heap)
{
// your implementation
}

int change_key(HEAP *heap, int index, KEYTYPE new_key)
{
// your implementation
}

int find_data_index(HEAP *heap, DATA data) {
// your implementation
}

void heap_sort(HEAPNODE *hna, int n) {
// your implementation 
}

int cmp(KEYTYPE a, KEYTYPE b) {
  int r = 0;
  if (a < b) r = -1;
  else if (a > b) r = 1;
  return r;
}
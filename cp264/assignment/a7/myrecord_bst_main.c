/*--------------------------------------------------
Project: cp264-a7q3
File:    myrecord_bst_main.c
Description: public test driver
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

void display_search_info(char *sf, char *key, TNODE *tnp);
void display_inorder(TNODE *root);
void file_inorder(TNODE *root, FILE *fp);

char letter_grade(float s);
int import_data(char *filename, BST *bst, STATS *stats);
STATS process_data(BST *bst, int n);
int report_data(char *outfilename, BST *bst, STATS *stats);

int main(int argc, char* args[]) {
  char infilename[40] = "marks.txt";
  char outfilename[40] = "record_report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  
  
  printf("\n---test import_data---\n");
  BST bst = {0}; 
  STATS stats = {0};
  
  int n = import_data(infilename, &bst, &stats);  
  display_inorder(bst.root);
  printf("\ncount:%d\n", stats.count);
  printf("mean:%.1f\n", stats.mean);
  printf("stddev:%.1f\n", stats.stddev);
  printf("median:%.1f\n\n", stats.median);

  printf("\n---test process_data---\n");
  stats = process_data(&bst, n);
  printf("count:%d\n", stats.count);
  printf("mean:%.1f\n", stats.mean);
  printf("stddev:%.1f\n", stats.stddev);
  printf("median:%.1f\n", stats.median); 
  
  printf("\n---test search---\n");
  char *key = "Wang";
  TNODE *tp = search(bst.root, key);
  display_search_info("search", key, tp);

  printf("\n---test add_data---\n");
  key = "Moore";
  float score = 92;
  add_data(&bst, &stats, "Moore", score);
  tp = search(bst.root, key);
  display_search_info("search", key, tp);

  printf("\n---test remove_data---\n");
  key = "Wang";
  remove_data(&bst, &stats, key);  
  tp = search(bst.root, key);
  display_search_info("search", key, tp);
  
  printf("\n---test report_data---\n");
  stats = process_data(&bst, stats.count);
  printf("count:%d\n", stats.count);
  printf("mean:%.1f\n", stats.mean);
  printf("stddev:%.1f\n", stats.stddev);
  printf("median:%.1f\n", stats.median); 
  report_data(outfilename, &bst, &stats);
 
  clean_tree(&(bst.root));  
  return 0;
}

void display_search_info(char *sf, char *key, TNODE *tnp){
  if (tnp) 
    printf("%s(%s):%s,%.0f\n", sf, key, tnp->data.name, tnp->data.score);
  else
    printf("%s(%s):NULL\n", sf, key);	
}

void display_inorder(TNODE *root) {
	if (root) {
		if (root->left) display_inorder(root->left);
		printf("%s,%3.1f\n", root->data.name, root->data.score);
		if (root->right) display_inorder(root->right);
	}
}

void file_inorder(TNODE *root, FILE *fp) {
  if (root){
    if (root->left) file_inorder(root->left, fp);
    fprintf(fp, "%s,%.1f,%c\n", root->data.name, root->data.score, letter_grade(root->data.score));
    if (root->right) file_inorder(root->right, fp);
  }
}

char letter_grade(float s) {
  char r = 'F';
  if (s >= 90) r = 'S';
  else if (s >= 80) r = 'A';
  else if (s >= 70) r = 'B';
  else if (s >= 60) r = 'C';
  else if (s >= 50) r = 'D';  
  else r = 'F';
  return r;
}

void select_sort(float a[], int left, int right) 
{
  int i, j, k;
  float temp;
  for (i = left; i <= right; ++i) {
	k = i;
    for(j = i+1; j <= right; ++j) {	
	  if (a[j] < a[k]) {
		k = j;
	  }
	}
    if (i != k) {
	  temp = a[k];
	  a[k] = a[i];
      a[i] = temp;     
    }
  }	
}

int import_data(char *filename, BST *bst, STATS *stats) {
  char line[40], name[20];
  FILE *fp = fopen(filename, "r");
  char *result = NULL;
  float score = 0;
  char delimiters[] = ",\n";
  if (fp == NULL) {
    perror("Error while opening the file.\n");
    return -1;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    result = strtok(line, delimiters);
    if (result){
      strcpy(name, result);
      result = strtok(NULL, delimiters);
      score = atof(result);
	  add_data(bst, stats, name, score); 
    }
  }
  fclose(fp);
  return stats->count;
}

STATS process_data(BST *bst, int n) { 
  int count = 0;
  float mean = 0;
  float stddev = 0;  
  float a[n]; // array store score values for sorting, fill a[] by bf traversing the bst 
  TNODE *p = bst->root;
  QUEUE queue = {0};
  enqueue(&queue, p);
  int i=0;
  while (queue.front) {
    p = dequeue(&queue);
	a[i++] = p->data.score;
	count += 1;
	mean += p->data.score;
	stddev += p->data.score*p->data.score;
	
    if (p->left) enqueue(&queue, p->left);
    if (p->right) enqueue(&queue, p->right);
  }
  
  // compute mean and stddev
  mean /= count;
  stddev = sqrt(stddev/count - mean*mean);
  STATS stats = {};
  stats.count = count;
  stats.mean = mean;
  stats.stddev = stddev; 
  // compute median
  select_sort(a, 0, count-1); 
  stats.median = (count % 2 == 1)? a[count/2] : (a[count/2-1] + a[count/2])/2;
  return stats;	
}

int report_data(char *outfilename, BST *bst, STATS *stats) {
  if (stats == NULL || stats == NULL) return 1;
  FILE *fp = fopen(outfilename, "w");
    if (fp == NULL) { 
     perror("error, cannot open file");
     return 1;
  } 
  fprintf(fp, "%s:%s\n", "stats", "value");
  fprintf(fp, "%s:%d\n", "count", stats->count);
  fprintf(fp, "%s:%.1f\n", "mean", stats->mean);
  fprintf(fp, "%s:%.1f\n", "stddev", stats->stddev);
  fprintf(fp, "%s:%.1f\n", "median", stats->median);
  fprintf(fp, "\n%s,%s,%s\n", "name", "score", "grade");
  file_inorder(bst->root, fp);
  return 0;
}

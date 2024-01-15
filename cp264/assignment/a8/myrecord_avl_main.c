/*
--------------------------------------------------
Project: cp264-a8q2
File:    myrecord_avl_main.c
Description: public test driver program
Author:  HBF  
Version: 2023-03-09
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "avl.h"
#include "myrecord_avl.h"

void display_search_info(char *sf, char *key, TNODE *tnp);
void display_inorder(TNODE *root);
void file_inorder(TNODE *root, FILE *fp);
char letter_grade(float s);
void import_data(char *filename, AVL *avl);
void process_data(AVL *avl);
int report_data(char *outfilename, AVL *avl);
void add_data(AVL *avl, char *name, float score);
void remove_data(AVL *avl, char *name);

int main(int argc, char* args[]) {
  char infilename1[40] = "marks1.txt";
  char infilename2[40] = "marks2.txt";
  char outfilename[40] = "record_report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename1, args[1]);
    if (argc >= 3) strcpy(infilename2, args[2]);
    if (argc >= 4) strcpy(outfilename, args[3]);
  }  
  
  printf("\nInport data from %s to t1:\n", infilename1);
  AVL t1 = {0};
  import_data(infilename1, &t1);
  display_inorder(t1.root);
  printf("\ncount:%d\n", t1.stats.count);
  printf("mean:%.1f\n", t1.stats.mean);
  printf("stddev:%.1f\n", t1.stats.stddev);
  printf("median:%.1f\n", t1.stats.median);

  printf("\nInport data from %s to t2:\n", infilename2);
  AVL t2 = {0};
  import_data(infilename2, &t2); 
  display_inorder(t2.root);
  printf("\ncount:%d\n", t2.stats.count);
  printf("mean:%.1f\n", t2.stats.mean);
  printf("stddev:%.1f\n", t2.stats.stddev);
  printf("median:%.1f\n", t2.stats.median);
  
  printf("\nMerge t2 into t1:\n");
  merge_data(&t1, &t2);
  display_inorder(t1.root);  
  printf("\ncount:%d\n", t1.stats.count);
  printf("mean:%.1f\n", t1.stats.mean);
  printf("stddev:%.1f\n", t1.stats.stddev);
  printf("median:%.1f\n", t1.stats.median);
  
  printf("\nRemove data from t2:\n");
  while (t2.root) {
    remove_data(&t2, t2.root->data.name);
  }
  printf("count:%d\n", t2.stats.count);

  process_data(&t1); 
  printf("\ncount:%d\n", t1.stats.count);
  printf("mean:%.1f\n", t1.stats.mean);
  printf("stddev:%.1f\n", t1.stats.stddev);
  printf("median:%.1f\n", t1.stats.median);
  
  printf("\nWrite report to file %s:\n", outfilename);  
  report_data(outfilename, &t1);  

  printf("\nClean t1:\n");    
  clear_avl(&t1);

  return 0;
}

void display_inorder(TNODE *root) {
  if (root) {
    if (root->left) display_inorder(root->left);
    printf("%s,%.1f\n", root->data.name, root->data.score);
    if (root->right) display_inorder(root->right);
  }
}

void display_search_info(char *sf, char *key, TNODE *tnp){
  if (tnp) 
    printf("%s(%s):%s,%.0f\n", sf, key, tnp->data.name, tnp->data.score);
  else
    printf("%s(%s):NULL\n", sf, key);	
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

void import_data(char *filename, AVL *avl) 
{
  char line[40], name[20];
  FILE *fp = fopen(filename, "r");
  char *result = NULL;
  float score = 0;
  char delimiters[] = ",\n";
  if (fp == NULL) {
    perror("Error while opening the file.\n");
  }
  while (fgets(line, sizeof(line), fp) != NULL) {
    result = strtok(line, delimiters);
    if (result){
      strcpy(name, result);
      result = strtok(NULL, delimiters);
      score = atof(result);
	  add_data(avl, name, score); 
    }
  }
  fclose(fp);
}

void add_data(AVL *avl, char *name, float score) {
  if (search_avl(avl->root, name) == NULL) {
	insert_avl(&(avl->root), name, score);
    int count = avl->stats.count;
    float mean = avl->stats.mean;
    float stddev = avl->stats.stddev;
    avl->stats.count = count + 1;
    avl->stats.mean =  (mean*count + score) / (count+1);
    avl->stats.stddev = sqrt(score*score/(count+1.0) + (stddev * stddev + mean * mean) * (count/(count+1.0)) - avl->stats.mean * avl->stats.mean ); 
  } else {
    printf("record exits");
  }
}

void remove_data(AVL *avl, char *name) {
  TNODE *np = NULL;
  if ( (np = search_avl(avl->root, name)) != NULL) {
    float score = np->data.score;
    delete_avl(&(avl->root), name);
    int count = avl->stats.count;
    float mean = avl->stats.mean;
    float stddev = avl->stats.stddev;
    avl->stats.count = count - 1;
    avl->stats.mean =  (mean*count - score) / (count-1.0);
    avl->stats.stddev = sqrt( (stddev * stddev + mean * mean) * (count/(count-1.0)) - score*score/(count-1.0) - avl->stats.mean * avl->stats.mean );
  } else {
    printf("record does not exit");   
  } 	
}

void process_data(AVL *avl) { 
  float a[avl->stats.count]; 
  TNODE *p = avl->root;
  QUEUE queue = {0};
  enqueue(&queue, p);
  // re-calculate count, mean and stddev.
  int count = 0;
  float mean = 0;
  float stddev = 0;    
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
  mean /= count;
  stddev = sqrt(stddev/count - mean*mean);
  // update avl->stats, and median
  avl->stats.count = count;
  avl->stats.mean = mean;
  avl->stats.stddev = stddev; 
  select_sort(a, 0, count-1); 
  avl->stats.median = (count % 2 == 1)? a[count/2] : (a[count/2-1] + a[count/2])/2;
}

int report_data(char *outfilename, AVL *avl) {
  if (avl == NULL) return 1;
  FILE *fp = fopen(outfilename, "w");
    if (fp == NULL) { 
     perror("error, cannot open file");
     return 1;
  } 
  fprintf(fp, "%s:%s\n", "stats", "value");
  fprintf(fp, "%s:%d\n", "count", avl->stats.count);
  fprintf(fp, "%s:%.1f\n", "mean", avl->stats.mean);
  fprintf(fp, "%s:%.1f\n", "stddev", avl->stats.stddev);
  fprintf(fp, "%s:%.1f\n", "median", avl->stats.median);
  fprintf(fp, "\n%s,%s,%s\n", "name", "score", "grade");
  file_inorder(avl->root, fp);
  return 0;
}


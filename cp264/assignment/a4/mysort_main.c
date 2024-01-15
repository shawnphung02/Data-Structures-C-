/*
--------------------------------------------------
Project: cp264-a4q1 
File:    mysort_main.c, a public test driver  
Author:  HBF
Version: 2023-02-01
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>  
#include <time.h> 
#include "mysort.h"

// uncomment following line to do runtime testing.
#define TEST
   
void display_array(float *a, int n);
// copy array from a to b
void copy_array(float *a, float *b, int n); 

int main(int argc, char *args[])
{
  int i, n;
  
  if (argc == 1) {    // for correctness verification
  
  float a[] = {3, 1, 4, 5, 2, 7, 6, 9, 8};    // input array for correctness testing
  n = sizeof(a)/sizeof(float);                // array length
  
  float b[n];                                 // array to sort
  printf("Algorithm correctness testing:\n");  
  printf("a[]:");  
  display_array(a, n);
  printf("\n"); 
  printf("is_sorted(a):%d\n", is_sorted(a, 0, n-1));  
  
  printf("selection sort:");
  copy_array(a, b, n);
  select_sort(b, 0, n-1);
  display_array(b, n);
  printf("\nis_sorted(b):%d\n", is_sorted(b, 0, n-1));  

  printf("quick sort:");
  copy_array(a, b, n);
  quick_sort(b, 0, n-1); 
  display_array(b, n);
  printf("\nis_sorted(b):%d\n", is_sorted(b, 0, n-1));  
  
  } else {   // for runtime comparison  

// conditional compiling for runtime testine. 
#ifdef TEST
  printf("Algorithm runtime testing:\n");  
  //run time measurement
  clock_t t1, t2;    
  int len = 10000;
  float a1[len];
  float b1[len];
  //generate randomly an array of len elements more modular len
  
  srand(time(NULL)); 
  for (i=0;i<len;i++) {
    a1[i] = rand()% len;
  }

  // measuring the test overhead time span  
  t1=clock();
  for (i=0; i<1000; i++) {
    copy_array(a1, b1, len);
    is_sorted(b1, 0, len-1); 
  }
  t2=clock();
  double time_span0 = (double) (t2-t1)/1000;  
  //printf("time_span0:%f\n", time_span0);  
  
  //run time measuring for selection_sort
  int m1 = 10;
  t1=clock();
  for (i=0; i< m1; i++) {
    copy_array(a1, b1, len);
    select_sort(b1, 0, len-1); 
    if (is_sorted(b1, 0, len-1) == false) printf("not sorted:\n");  
  }
  t2=clock();
  double time_span1 = (double) t2-t1;
  time_span1 -= time_span0*m1;  // remove the overhead time
  printf("time_span(selection_sort(%d numbers) for %d times)(ms):%0.1f\n", len, m1, time_span1);
  
  //run time measuring for quick_sort
  int m2 = 1000;
  t1=clock();
  for (i=0; i< m2; i++) {
    copy_array(a1, b1, len);
    quick_sort(b1, 0, len-1); 
    if (is_sorted(b1, 0, len-1)== false) printf("not sorted:\n");  
  }
  t2=clock();
  double time_span2 = (double) t2-t1;
  time_span2 -= time_span0*m2;  // remove the overhead time
  printf("time_span(quick_sort(%d numbers) for %d times)(ms):%0.1f\n", len, m2, time_span2);
  printf("time_span(selection_sort(%d numbers))/time_span(quick_sort(%d numbers)):%0.1f\n", len, len, (time_span1/m1)/(time_span2/m2));
#endif
}
  
  return 0;
} 


void display_array(float *a, int n)
{
  int i; 
  if (n>0) printf("%.1f", *(a+0));
  for (i=1; i<n; i++) {
    printf(", %.1f", *(a+i));
  }
}

void copy_array(float *a, float *b, int n)
{
  int i;
  for (i = 0; i < n; i++)
    *(b+i) = *(a+i); 
}
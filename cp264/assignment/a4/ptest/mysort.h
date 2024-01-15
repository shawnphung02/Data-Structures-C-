#ifndef MYSORT_H
#define MYSORT_H 

typedef enum {
    false = 0,
    true = 1
} BOOLEAN;
BOOLEAN is_sorted(float *a, int left, int right);
void select_sort(float *a, int left, int right);
void quick_sort(float *a, int left, int right);

#endif
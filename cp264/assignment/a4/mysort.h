/*
--------------------------------------------------
Project: CP264-a4q2
File:    mysort.h
Author:  HBF
Version: 2023-02-01
--------------------------------------------------
*/

#ifndef MYSORT_H
#define MYSORT_H 

typedef enum {false, true} BOOLEAN;
BOOLEAN is_sorted(float *a, int left, int right);
void select_sort(float *a, int left, int right);
void quick_sort(float *a, int left, int right);

#endif
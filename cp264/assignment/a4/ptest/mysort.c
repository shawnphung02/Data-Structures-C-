/*
--------------------------------------------------
Project: cp264-a4q1
File:    mysort.c
Author:  Aaron Langevin
Version: 2023-02-10
--------------------------------------------------
*/
#include "mysort.h"

BOOLEAN is_sorted(float *a, int left, int right)
{
    int i;
    for (i = left; i < right; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;

}

void select_sort(float *a, int left, int right)
{

    int i, j, min_idx;
    float temp;
    for (i = left; i < right; i++) {
        min_idx = i;
        for (j = i + 1; j <= right; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }
}

void quick_sort(float *a, int left, int right)
{ 
    int i, j;
    float pivot, temp;
    if (left < right) {
        pivot = a[left];
        i = left;
        j = right + 1;
        while (1) {
            do ++i; while (a[i] <= pivot && i <= right);
            do --j; while (a[j] > pivot);
            if (i >= j) break;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        temp = a[left];
        a[left] = a[j];
        a[j] = temp;
        quick_sort(a, left, j - 1);
        quick_sort(a, j + 1, right);
    }
}

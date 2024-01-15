/**
--------------------------------------------------
Project: cp264-a2q3
File:    matrix.c
Author:  Shawn Phung
Version: 2023-01-27
--------------------------------------------------
*/
#include<stdio.h>
#include "matrix.h"


float vsum(float *v, int n) {

    int sum = 0;
    int i = 0;
    while (i < n) {
        sum += v[i];
        i++;
    }
    return sum;
}

float msum(float *m, int n) {

    int sum = 0;
    int i = 0;
    while (i < n*n) {
        sum += *(m + i);
        i++;
    }
    return sum;

}

void multiply_vector(float *m, float *vin, float *vout, int n) {

    int i, k, sum;
    i = 0;
    while (i < n) {
        sum = 0;
        k = 0;
        while (k < n) {
            sum += *(m + i*n + k) * *(vin + k);
            k++;
        }
        *(vout + i) = sum;
        i++;
}
}

void transpose_matrix(float *m1, float *m2, int n) {

    int i,j;
    i=0;
    while (i<n) {
        j=0;
        while (j<n) {
            *(m2 + j*n + i) = *(m1 + i*n + j);
            j++;
        }
        i++;
        }
    }

void multiply_matrix(float *m1, float *m2, float *m3, int n) {

    int i, j, k, sum;
    i = 0;
    while (i < n) {
        j = 0;
        while (j < n) {
            sum = 0;
            k = 0;
            while (k < n) {
                sum += *(m1 + i*n + k) * *(m2 + k*n + j);
                k++;
            }
            *(m3 + i*n + j) = sum;
            j++;
        }
        i++;
    }
} 
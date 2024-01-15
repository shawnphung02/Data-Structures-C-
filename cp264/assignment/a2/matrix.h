/**
--------------------------------------------------
Project: cp264-a2q3
File:    matrix.h
Author: Shawn Phung
Version: 2023-01-27
--------------------------------------------------
*/
#ifndef MATRIX_H
#define MATRIX_H
 
float vsum(float *v, int n);
float msum(float *m, int n);
void multiply_vector(float *m, float *v1, float *v2, int n);
void transpose_matrix(float *m1, float *m2, int n);
void multiply_matrix(float *m1, float *m2, float *m3, int n);

#endif
/**
--------------------------------------------------
Project: cp264-a2q2
File:    polynomial.h
Author: Shawn Phung
Version: 2023-01-27
--------------------------------------------------
*/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
 
#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6

float horner(float p[], int n, float x)
{
    // Set result to first index
    float result = p[0];

	for (int i = 1; i < n; i++) {
		result = result * x + p[i];
	}
	
	// Prevent rounding to 0.00
	if (result < 5 * EPSILON && result > 5 * -EPSILON) {
		result = 0.00;
	}
	return result;

}

void derivative(float p[], int n, float d[])
{
    for (int i = 0; i < n-1; i++)
    {
        d[i] = (n-1-i) * p[i];
    }
}

float newton(float p[], int n, float x0)
{
    float x = x0;
    float f = horner(p,n,x);
    float df = horner(p,n-1,x);
    while(fabs(f) > EPSILON)
    {
        x = x - f/df;
        f = horner(p,n,x);
        df = horner(p,n-1,x);
    }
    return x;
}

#endif
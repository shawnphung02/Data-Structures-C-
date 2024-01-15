/**
--------------------------------------------------
Project: cp264-a1q3
File:    quadratic.c
Author: Shawn Phung
Version: 2023-01-20
--------------------------------------------------
*/
#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6 // or #define EPSILON 0.000001

int main(int argc, char* argv[])
{
    float a, b, c, d, x1, x2, real;
    
    if (argc < 2) {  
       printf("argument input:missing\n");     
    } else {
        int n = sscanf(argv[1], "%f,%f,%f", &a, &b, &c); 
        if (n != 3) { 
            printf("input:invalid\n");  
        } else {

            printf("(%f)x^2+(%f)x+(%f)=0 ", a, b, c);
     
            if (fabs(a) < EPSILON) {
                printf("is not a quadratic equation\n");
            } else {
                // your solution logic code for cases 2-4
                // Calculate discriminant
                d = (b*b)-(4*a*c);
                real = (-b)/(2*a);

                x1 = sqrt(d)/(2*a);
                x2 = -x1;
                // No roots
                if(d < 0){
                    x1 = sqrt(-d)/(2*a);
                    x2 = -x1;
                    printf("has two complex roots: %f+%fi, %f%fi\n", real, x1, real, x2);
                }else if(d == 0){
                    // 1  root
                    printf("has two equal real roots: %f\n", real+x1);
                }else{
                    // 2 roots
                    printf("has two distinct real roots: %f, %f\n", real+x1, real+x2);
                }
            }
        }
    }
    return 0;
}
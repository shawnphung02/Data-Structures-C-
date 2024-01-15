/*
--------------------------------------------------
Project: CP264-a4q1
File:    mysort.c
Author:  Shawn Phung
Version: 2023-02-01
--------------------------------------------------
*/

#include "mysort.h"

BOOLEAN is_sorted(float *a, int left, int right)
{
    int i;
    for(i = 0; i < right; i++){
        // 
        if(*(a+i) >= *(a+i+1)){
            return 0;
            break;
        }
    }
    if(i == right){
        return 1;
    }
}

void select_sort(float *a, int left, int right)
{
    int i, j, k;

    // Iterate through array
    for(i = left; i < right; ++i){
        k = i;
        // Iterate through all indexes after i
        for(j = i; j <= right; ++j){
            if(*(a + j) < *(a + k)){
                k = j;
            }
        }
        
        if(i != k){
            // Swap the values at a+k and a+i
            float temp;
            temp = *(a+k);
            *(a+k) = *(a+i);
            *(a+i) = temp;
        }
    }
    
    return;
}

void quick_sort(float *a, int left, int right)
{ 
    int i, j, k;
    float key, temp;

    if(left < right){
        k = left;
        key = *(a + k);
       
        if(k != left){
            temp = left;
            *(a + k) = left;
            left = temp;
        } 

        i = left + 1;
        j = right;

        while(i <= j){
            while(*(a + i) <= key && i <= right) i++;
            while(*(a + j) > key && j >= left) j--;

            if(i < j){
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    
        temp = *(a + left);
        *(a + left) = *(a + j);
        *(a + j) = temp;

        quick_sort(a, left, j - 1);
        quick_sort(a, j + 1, right);
    
    }


}   
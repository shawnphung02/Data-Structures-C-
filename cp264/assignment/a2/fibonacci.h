/**
--------------------------------------------------
Project: cp264-a2q1
File:    fibonacci.h
Author: Shawn Phung
Version: 2023-01-27
--------------------------------------------------
*/
#ifndef FIBONACCI_H
#define FIBONACCI_H

extern int *la;  // global pointer variable to hold lowest variable address

int recursive_fibonacci(int n) {
  if (&n < la)
		la = &n;
	// n <= 0
  if(n <= 0){
		return 0;
	}
  // n = 1 or 2
	else if (n == 1 || n == 2) {
		return 1;
	} else {
    // Otherwise keep recursing
		return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
	}
}

int iterative_fibonacci(int n)
{
  if (&n < la) la = &n;   

  // your implementation of the iterative algorithm
  int prev1 = 0, prev2 = 1;
  int fib = 0;
  if (n == 0){
    return prev1;
  }
  else if (n == 1){
    return prev2;
  }
  else{
    for (int i = 2; i <= n; i++) {
      fib = prev1 + prev2;
      prev1 = prev2;
      prev2 = fib;
    } 
  }
  return fib;
}

#endif
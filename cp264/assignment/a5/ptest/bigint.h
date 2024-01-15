/*
--------------------------------------------------
Project: CP264-a5q3
File:    bigint.h
Author:  Shawn Phung
Version: 2023-02-07
--------------------------------------------------
*/
#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef DLLIST BIGINT;
BIGINT bigint(char *digitstr);
BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

#endif
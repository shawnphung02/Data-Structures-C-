/*
-------------------------------------
File:    My_Definitions.h
Project: CP264
file description
-------------------------------------
Author:  Heider Ali/Rick Magnotta
ID:      xxxxxxxxx
Email:   heali@wlu.ca/rmagnotta@wlu.ca
Version  2020-11-29
Last Modified: 2023-03-30
-------------------------------------
 */
#ifndef MY_DEFINITIONS_H_
#define MY_DEFINITIONS_H_

#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

typedef unsigned int bool;

#define SUCCESS TRUE
#define FAILURE FALSE

//#define DEBUG_LEVEL_01
//#define DEBUG_LEVEL_02

#endif /* MY_DEFINITIONS_H_ */

/*
-------------------------------------------------
File:    name_list.h
Project: 202301_CP264_Lab06_Queues_Stacks
file description: Header file
-------------------------------------------------
Author:  Heider Ali/Rick Magnotta
ID:      xxxxxxxxx
Email:   heali@wlu.ca/rmagnotta@wlu.ca
Version  2020-02-06
Last Modified: 2023-02-22
-------------------------------------------------
 */

#include "rm_library.h"
#include "utility_library.h"

#ifndef NAME_LIST_H_
#define NAME_LIST_H_

bool g_SIMULATE_FATAL_ERROR;                   // Global flag used to simulate a Fatal Error condition when set to TRUE.
                                               // Set to FALSE, otherwise.

#define MAX_FIRST_NAME_LNG  41                           // Max. size of First Name field +end byte.
#define MAX_LAST_NAME_LNG     MAX_FIRST_NAME_LNG         // Max. size of Last  Name field +end byte.

typedef struct {                               // Name Structure storing the First, and Last name of a person's name.
	char first_name[MAX_FIRST_NAME_LNG];       //   Stores the person's first name.
	char last_name [MAX_LAST_NAME_LNG ];       //   Stores the person's last  name.
} sNAME;                                       // sNAME is the name given to the person's name structure


typedef struct node{                           // List node structure.
	sNAME        name;                         // Compound field storing the person's name.
    struct node *next;                         // Pointer to an sNODE node.
} sNODE;                                       // sNODE is the name given to the node structure.


typedef struct {
	sNODE *front;                              // Pointer to the FIRST node/name of the sNAME_LIST.
	sNODE *rear;                               // Pointer to the LAST  node/name of the sNAME_LIST.
	int    count;                              // Count of number of nodes/names are present in the sNAME_LIST.
} sNAME_LIST;


//===== SUBPROGRAM PROTOTYPES ===========================================================================================
                                                 // Subprogram to initialize the "name_list".
void initialize_name_list(sNAME_LIST *name_list);
                                                 // Subprogram to insert a name in the list, but only if the name is NOT
                                                 // already in the list.
void insert_name_list(sNAME_LIST *name_list,
                      sNODE      *node     );
                                                 // Subprogram to free (i.e. Clean) all the nodes in the "name_list".
int  free_name_list(sNAME_LIST *name_list);
                                                 // Subprogram to print the Data content of the "name_list".
int  output_name_list(const sNAME_LIST *name_list);


#endif // NAME_LIST_H_

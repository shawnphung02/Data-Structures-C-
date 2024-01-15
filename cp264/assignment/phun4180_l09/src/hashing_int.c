/*
 -------------------------------------
 File:    hashing_int.c
 Project: CP264_Lab10_Hashing
 Hashing Source Code
 -------------------------------------
 St Name:	Shawn Phung
 St ID:     200814180
 Email:   	phun4180@mylaurier.ca
 Date:		03/22/2023
  ------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "hashing_int.h"


void initialize_hash_table(int hash_table[],                      // The integer 1D array implementing the Hash Table.
                           int MAX_HASH_TABLE_SIZE)               // Max. number of slots defined for the Hash Table.
//=================================================
// Fill the hash table array with NULLS casted to "int"!
{
	for (int i=0; i<MAX_HASH_TABLE_SIZE; i++) {
	    hash_table[i] = (int)NULL;
	}
	return;
}

bool insert_hash_table(int hash_table[],                          // The integer 1D array implementing the Hash Table.
                       int MAX_HASH_TABLE_SIZE)                   // Max. number of slots defined for the Hash Table.
//=============================================
// "hash_table" is a 1D-array of size "HASH_TABLE_SIZE"
//
// Algorithm to insert a value in linear probing:
// =============================================
// Step 1: Read the key/value to be inserted.
// Step 2: Let i = 0
// Step 3: Compute the index at which the key/value has to be inserted in hash table, as follows:
//                 index = ((key% HASH_TABLE_SIZE) + i) % HASH_TABLE_SIZE
// Step 4: If there is no element at that index, then insert the key/value at index and STOP!
// Step 5: If there is already an element at that index, then:
//         5.1 repeat Step-3 with (i+1), that is, re-hash (i.e. re-calculate index) with "i+1"
// step 6: Repeat Step-3, 4, and 5 for:
//           - as long as (i < HASH_TABLE_SIZE), and
//           - have not yet found an empty slot.
{
	bool INSERTED;                      // TRUE if key/value is inserted, FALSE otherwise.
	int  key;                           // The input Key/Value to insert/store into the Hash Table/Array.


	printf("Enter an integer key/value to insert into Hash table: \n");
	scanf("%d", &key);
	while ( getchar() != '\n' );

	printf("\n");
	printf("Slot  Collision?  Value Inserted\n");
	printf("====  ==========  ==============\n");

	INSERTED = FALSE;

	//****************************************************************************************
	// NOTE: Move the following two print lines to the appropriate location in your code
	//       in order to print the contents of the "Slot  Collision?  Value Inserted" table.
	//                                             "====  ==========  =============="
	//
	//printf("%4d      no      %14d\n", index, key);
   	//printf("%4d      Yes\n", index);
	//
	//****************************************************************************************
	int index;
	int i = 0;
	// Iterate through hash table
    while(i < MAX_HASH_TABLE_SIZE && !INSERTED){
		index =  ((key% MAX_HASH_TABLE_SIZE) + i) % MAX_HASH_TABLE_SIZE;
		if(hash_table[index] == (int)NULL){										// Hash is empty, insert
			hash_table[index] = key;											// Set index to key
			INSERTED = TRUE;													// Set INSERTED to TRUE
			printf("%4d      no      %14d\n", index, key);						// Print if no collisions found
		}
		else{
			printf("%4d      Yes\n", index);									// Print if collision found
			i++;																// Incrememnt i
		}
	}

	if (!INSERTED) printf("Element [%d] cannot be inserted.\n", key);			// End reached, print this

	return ( INSERTED );
}

bool search_hash_table(int hash_table[],                          // The integer 1D array implementing the Hash Table.
                       int MAX_HASH_TABLE_SIZE)                   // Max. number of slots defined for the Hash Table.
//=============================================
// Ask user to input the "key" value of interest, and use it's hash value
// to search for its presence/absence from the "hash_table".
// Prints appropriate search-result message, and
// returns TRUE if key is found in hash_table, FALSE otherwise.
{
	bool FOUND;                           // TRUE if input key is found in hash_table, false otherwise.
	int key;                              // Input key value to search!

	printf("\n");
	printf("Enter integer key/value to search:\n");
	scanf("%d", &key);
	while ( getchar() != '\n' );

	//****************************************************************************************
	// NOTE: Move the following print line to the appropriate location in your code
	//
	// printf("Key/Value [%d] is found at index/slot [%d]\n", key, index);
	//
	//****************************************************************************************

    // <<<< Your Code >>>> DO NOT USE a LINEAR SEARCH Algorithm to find the location
	//                >>>>            of the Key in the Hash Table.
	//                >>>>            Use the same HASHING Algorithm used in the
	//                >>>>            "insert_hash_table()" function.
	int i = 0;
	int  index =  ((key% MAX_HASH_TABLE_SIZE) + i) % MAX_HASH_TABLE_SIZE;
	// Iterate through table for as long as the key is not found
	while(hash_table[index] != (int)NULL && i < MAX_HASH_TABLE_SIZE && !FOUND){
		// Key found
		if(hash_table[index] == key){
			FOUND = TRUE;
		}else{
			// Key not found, incremement i and recalculate index
			i++;
			index =  ((key% MAX_HASH_TABLE_SIZE) + i) % MAX_HASH_TABLE_SIZE;
		}
	}
	// Output depending on if the key was found
	if ( !FOUND ) printf("Key/Value [%d] is not found!\n", key);
	else printf("Key/Value [%d] is found at index/slot [%d]\n", key, index);

	return ( FOUND );
}

void display_hash_table(int hash_table[],                         // The integer 1D array implementing the Hash Table.
                        int MAX_HASH_TABLE_SIZE)                  // Max. number of slots defined for the Hash Table.
//==============================================
// Print the contents of the "hash_table".
{
	printf("\n");
	printf("Contents of Hash Table:\n");
    printf("====================== \n");
    printf("Index/Slot   Key/Value \n");
    printf("==========   ========= \n");

	for (int i=0; i< MAX_HASH_TABLE_SIZE; i++) {
       if ( hash_table[i] == (int)NULL )
          printf("%10d   %9s\n", i, "empty");
       else
          printf("%10d   %9d\n", i, hash_table[i]);
	}
	printf("\n");
	return;
}

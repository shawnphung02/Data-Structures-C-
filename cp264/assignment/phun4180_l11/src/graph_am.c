/*
 -------------------------------------
 File:     graph_am.c
 Project:  phun4180_l11
 -------------------------------------
 Author:  Shawn Phung
 ID:      200814180
 Email:   phun4180@mylaurier.ca
 Version  2019-02-25
 Version  2020-03-25 Rick Magnotta
 Version  2020-11-29 Heider Ali
 -------------------------------------
 */

#include "My_Definitions.h"
#include "graph_am.h"

void randomGraph(int adj[][MAX])
//==============================
{
	int i, j, v;

	srand(time(NULL));

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (j == i)
				adj[i][j] = 0;
			else {
				v = rand() % 2;
				adj[i][j] = v;
				adj[j][i] = v;
			}
		}
	}
}

void displayAdjacentMatrix(int adj[][MAX])
//========================================
{
	int i, j;

	printf("    ");
	for (i = 0; i < MAX; i++) printf("%d ", i);
	printf("  <=== Node Number\n\n");

	for (i = 0; i < MAX; i++) {
		printf("%d  ", i);

		for (j = 0; j < MAX; j++) printf(" %d", adj[i][j]);

		printf("\n");
	}
    printf("^\n");
    printf("|__ Node Number\n");
    printf("\n");
}

void connected(int adj[][MAX],     // Adjacency Matrix
		       int node      )     // Node in Graph.
//============================
// Given the Graph "adj", and a node "node" present in the graph,
// this routine prints the "node-number" of all the nodes that are
// connected to the node "node".
{
	int i = node;

	printf("Nodes connected to node %d: [", i);
	int has_connection = 0;

	for(int j = 0; j < MAX; j++){
	    if(adj[i][j] == 1){
	        printf("%s%d", has_connection ? ", " : " ", j);		// List off connections
	        has_connection = 1;									// Set has_connection to TRUE
	    }
	}
	printf(" ]\n");			// Close off output
}

void node_counts(int adj[][MAX],   // Adjacency Matrix
		         int count     )   // Target count.
//==============================
// Given the Graph "adj", and the target count "count",
// this routine prints the "node-number" of all the nodes that are
// connected to "count" other nodes.
{

	int num_conns = count;
	printf("Nodes connected to %d other nodes: [", num_conns);
	int has_node = 0;

	for(int i = 0; i < MAX; i++){
	    int adj_count = 0;
		
	    for(int j = 0; j < MAX; j++){
	        if(adj[i][j] == 1){
				// Increment number of adjecent nodes
	            adj_count++;
	        }
	        if(adj_count > num_conns){
				// Stop if number of adjacents exceed the number of connections
	            break;
	        }
	    }
		// Number of adjancents is equal to number of connections
	    if(adj_count == num_conns){
	        printf("%s%d", has_node ? ", " : " ", i);
	        has_node = 1;			// Set has_node to TRUE
	    }
	}
	printf(" ]\n");		// Close off output
}

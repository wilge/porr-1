// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>

// init path to unknown
void init_path(int *path) {
	int i;
	
	for (i = 0; i < GRAPHSIZE; i++) {
		path[i] = INFINITY;
	}
}

// print all path fields, imitting unknown ones
void print_path(int *path) {
	int i;
	
	printf("\n::path:: ");
	for (i = 0; i < GRAPHSIZE; i++) {
		if (path[i] != INFINITY)
			printf("%i ", path[i]);
	}
	printf("\n");
}

int main() {
	int graph[GRAPHSIZE][GRAPHSIZE] =
	{	{INFINITY,2,4,7,INFINITY,5,INFINITY},
		{2,INFINITY,INFINITY,6,3,INFINITY,8},
		{4,INFINITY,INFINITY,INFINITY,INFINITY,6,INFINITY},
		{7,6,INFINITY,INFINITY,INFINITY,1,6},
		{INFINITY,3,INFINITY,INFINITY,INFINITY,INFINITY,7},
		{5,INFINITY,6,1,INFINITY,INFINITY,6},
		{INFINITY,8,INFINITY,6,7,6,INFINITY}	};
	
	int target = 4;					// set target node
	int path[GRAPHSIZE];				// result variable
	
	init_path(path);				// init path to unknown
	dijkstra_algorithm(graph, target, path);	// execute algorithm
	print_path(path);				// print result
	
	init_path(path);				// init path to unknown
	auction_algorithm(graph, target, path);		// execute algorithm
	print_path(path);				// print result

	printf("\n");	
	return 0;
}


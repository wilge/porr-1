// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>
#include <time.h>

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

// convert to milliseconds and print time
void print_exec_time(int tic_d, int toc_d, int tic_a, int toc_a) {
	printf("\n::dijkstra:: %.2f ms\n",
		(double)(toc_d- tic_d) / CLOCKS_PER_SEC * 1000);
	printf("::auction:: %.2f ms\n",
		(double)(toc_a - tic_a) / CLOCKS_PER_SEC * 1000);
}

int main() {
	clock_t tic_d, toc_d, tic_a, toc_a;			// execution time utils
	
	int graph[GRAPHSIZE][GRAPHSIZE] =
	{	{INFINITY,2,4,7,INFINITY,5,INFINITY},
		{2,INFINITY,INFINITY,6,3,INFINITY,8},
		{4,INFINITY,INFINITY,INFINITY,INFINITY,6,INFINITY},
		{7,6,INFINITY,INFINITY,INFINITY,1,6},
		{INFINITY,3,INFINITY,INFINITY,INFINITY,INFINITY,7},
		{5,INFINITY,6,1,INFINITY,INFINITY,6},
		{INFINITY,8,INFINITY,6,7,6,INFINITY}	};
	
	int target = 4;								// set target node
	int path_d[GRAPHSIZE], path_a[GRAPHSIZE];	// result variables
	init_path(path_d);							// init to unknown
	init_path(path_a);							// init to unknown
	
	tic_d = clock();							// start timer
	dijkstra_algorithm(graph, target, path_d);	// execute algorithm
	toc_d = clock();							// stop timer
	print_path(path_d);							// print result
	
	tic_a = clock();							// start timer
	auction_algorithm(graph, target, path_a);	// execute algorithm
	toc_a = clock();							// stop timer
	print_path(path_a);							// print result

	print_exec_time(tic_d, toc_d, tic_a, toc_a);
	
	return 0;
}


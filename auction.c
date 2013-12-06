// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

// #include "porr.h"
#include <stdio.h>

#define GRAPHSIZE  7
#define INFINITY  99

// for printing path/prices arrays
void print_result(int *path) {
	int i;

	for(i = 0; i < GRAPHSIZE; i++)
		printf("%d ", path[i]);
	printf("\n");
}

// calculate minimum as outlined in algorithm description
void min_a_plus_p(int graph[][GRAPHSIZE], int *prices, 
			int terminal_node, int *arg_min, int *min) {
	int j, j_dist;				// iteration utilities
	
	*min = INFINITY;			// init to unknown
	*arg_min    = 0;			// init to the first

	for (j = 0; j < GRAPHSIZE; j++) {
		j_dist = graph[terminal_node][j] + prices[j];
		if (j_dist < *min) {
			*min      = j_dist;
			*arg_min	  = j;
		}
	}
}

void auction_algorithm(int graph[][GRAPHSIZE], int target, int *path) {
	int prices[GRAPHSIZE] = {0};		// to reach each node - unknown
	int terminal,				// points to current end of path
	    arg_min,				// arg min from algorithm description
	    min;				// min from algorithm descripton
	
	path[0]  = 0;				// start off with the source node
	terminal = 0;
	
	while (path[terminal] != target) {
		min_a_plus_p(graph, prices, path[terminal], 
			     &arg_min, &min);
		
		printf("\n::auction:: i=%i, j=%i, p(i)=%i, min=%i\n", 
				path[terminal], arg_min, 
				prices[path[terminal]], min);
		
		if (prices[path[terminal]] < min) {			// choose step

			printf("::auction:: => contract P\n");		// step 1
			prices[path[terminal]] = min;			// set p := min
			if (terminal != 0)				// contract P
				path[terminal--] = INFINITY;
		} else {
			printf("::auction:: => extend P\n");		// step 2
			path[++terminal] = arg_min;			// extend P
		}
		
		printf("::auction:: path:   ");
		print_result(path);
		printf("::auction:: prices: ");
		print_result(prices);
	}
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

	int i, path[GRAPHSIZE];
	for (i = 0; i < GRAPHSIZE; i++)
		path[i] = INFINITY;

	auction_algorithm(graph, 4, path);

	
	printf("\n::auction:: path: ");
	print_result(path);
	return 0;
}

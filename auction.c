// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

// #include "porr.h"
#include <stdio.h>

#define GRAPHSIZE  7
#define INFINITY  99

void auction_algorithm(int graph[][GRAPHSIZE], int target, int *path) {
	int prices[GRAPHSIZE] = {0};

	int v, nearest_dist, last_ind,			// utilities
	    nearest_neighbour, neighbour_dist;
	
	path[0]  = 0;					// add source to path
	int last = 0;					// remember what was added
	last_ind = 0;
	
	// TODO: last not needed, just path[last]
	while (last != target) {
		nearest_dist      = INFINITY;		// find nearest neighbour
		nearest_neighbour = 0;			// of last node in path
		for (v = 0; v < GRAPHSIZE; v++) {
			neighbour_dist = graph[last][v] + prices[v];
			if (neighbour_dist < nearest_dist) {
				nearest_dist      = neighbour_dist;
				nearest_neighbour = v;
			}
		}
		
		printf("::auction:: nearest to %i is %i\n", 
				last, nearest_neighbour);
		
		if (prices[last] < nearest_dist) {
			prices[last] = nearest_dist;
			if (last != 0)
				path[last_ind--] = INFINITY;
		} else {
			path[++last_ind] = nearest_neighbour;
			last             = nearest_neighbour;
		}
	}
}

void print_result(int *path) {
	int i;

	printf("\n::auction:: path: ");
	for(i = 0; i < GRAPHSIZE; i++)
		printf("%d ", path[i]);
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

	int i, path[GRAPHSIZE];
	for (i = 0; i < GRAPHSIZE; i++)
		path[i] = INFINITY;

	auction_algorithm(graph, 5, path);
	print_result(path);
	return 0;
}

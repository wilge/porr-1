// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>

void print_result(int *dist) {
	int i;

	printf("\n::dijkstra:: distances: ");
	for(i = 0; i < GRAPHSIZE; i++)
		printf("%d ",dist[i]);
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

	int i, dist[GRAPHSIZE];
	for (i = 0; i < GRAPHSIZE; i++)
		dist[i] = INFINITY;

	dijkstra_algorithm(graph, 5, dist);
	print_result(dist);
	return 0;
}

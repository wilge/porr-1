// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>

int not_empty(int *Q) {
	int i;
	for (i = 0; i < GRAPHSIZE; i++)
		if (Q[i] == 1)
			return 1;
	return 0;
}

int find_u(int *Q, int *dist, int *visited) {
	int i, u, smallest_dist;
	
	smallest_dist = INFINITY;
	for (i = 0; i < GRAPHSIZE; i++) {
		if (Q[i] == 1 && dist[i] < smallest_dist) {
			smallest_dist = dist[i];
			u = i;
		}
	}

	return u;
}

void dijkstra_algorithm(int graph[][GRAPHSIZE], int target, int *dist) {
	int i, u, v, alt;			// utility variables
	int Q[GRAPHSIZE] = {0};			// empty Q

	int visited [GRAPHSIZE] = {0};		// mark all nodes as unvisited
	int previous[GRAPHSIZE] = {0};		// previous node in optimal path from source

	dist[0] = 0;				// distance from source to itself is zero
	Q   [0] = 1;				// start off with the source node

	while (not_empty(Q)) {
		u = find_u(Q, dist, visited);
		

		printf("\n::dijkstra:: u = %i\n", u);
		Q[u]       = 0;			// remove this node from Q
		visited[u] = 1;			// mark it as visited

		for (v = 0; v < GRAPHSIZE; v++) {
			// neighbours only
			if (!graph[u][v] == INFINITY)
				continue;
			// accumulate shortest distance from source
			alt = dist[u] + graph[u][v];
			printf("::dijkstra:: v=%i, alt=%i, dist[v]=%i\n", v, alt, dist[i]);
			if (alt < dist[v]) {
				printf("::dijkstra:: => alt<dist[%i]\n", v);
				// keep the shortest distance from source to v
				dist[v] = alt;
				previous[v]  = u;
				// add unvisited v into the Q to be processed
				if (!visited[v])
					Q[v] = 1;
			}
		}
	}
}

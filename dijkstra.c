// WEiTI PORR 13Z
// JAKUB JARZYNSKI & LUKASZ RUTA

#include "porr.h"
#include <stdio.h>

// if any element in Q is set to 1, Q is not empty
int not_empty(int *Q) {
	int i;
	for (i = 0; i < GRAPHSIZE; i++)
		if (Q[i] == 1)
			return 1;
	return 0;
}

// find vertex in Q with smallest distance in dist[] and has not been visited
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

// read path from previous[], put it at the end of path[]
int* read_path(int *previous, int target, int *path) {
	int i, u;
		
	i = GRAPHSIZE - 1;
	u = target;
	path[i] = u;
	while (u != 0) {
		i--;
		u = previous[u];
		path[i] = u;
	}
	
	return previous;
}

void dijkstra_algorithm(int graph[][GRAPHSIZE], int target, int *path) {
	int i, u, v, alt;			// utility variables
	int Q[GRAPHSIZE] = {0};			// empty Q

	int dist[GRAPHSIZE];
	for (i = 0; i < GRAPHSIZE; i++)
		dist[i] = INFINITY;
	
	int visited [GRAPHSIZE] = {0};		// mark all nodes as unvisited
	int previous[GRAPHSIZE] = {0};		// previous node in optimal path from source

	dist[0] = 0;				// distance from source to itself is zero
	Q   [0] = 1;				// start off with the source node

	while (not_empty(Q)) {
		u = find_u(Q, dist, visited);	// see function desc
		if (u == target)		// terminate once target is reached
			break;
		
		printf("\n::dijkstra:: u=%i\n", u);

		Q[u]       = 0;			// remove this node from Q
		visited[u] = 1;			// mark it as visited

		for (v = 0; v < GRAPHSIZE; v++) {
			// neighbours only
			if (!graph[u][v] == INFINITY)
				continue;
			// accumulate shortest distance from source
			alt = dist[u] + graph[u][v];
			printf("::dijkstra:: v=%i, alt=%i, dist[v]=%i\n", v, alt, dist[v]);
			if (alt < dist[v]) {
				printf("::dijkstra:: => alt < dist[%i]\n", v);
				// keep the shortest distance from source to v
				dist[v] = alt;
				previous[v]  = u;
				// add unvisited v into the Q to be processed
				if (!visited[v])
					Q[v] = 1;
			}
		}
	}
	
	read_path(previous, target, path);
}

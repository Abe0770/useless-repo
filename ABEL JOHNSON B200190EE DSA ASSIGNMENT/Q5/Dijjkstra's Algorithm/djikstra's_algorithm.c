/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

/*
NODES TAKEN AS 0 TO 4 (ZERO INDEXEXD)
OUUTPUT PATH WILL DISPLAY FORMAT "CURRENT NODE" "CURRENT NODE TO NEXT NODE" ... "THEN TO DESTINATION NODE"
*/

#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int sptSet[]) {
    	int min = INT_MAX, min_index;
    	for (int v = 0; v < V; v++)
        	if (sptSet[v] == 0 && dist[v] <= min)
        		min = dist[v], min_index = v;
    	return min_index;
}

void printPath(int parent[], int j) {
    	if (parent[j] == -1) {
        	printf("%d ", j);
        	return;
    	}
    	printPath(parent, parent[j]);
    	printf("%d ", j);
}

void printSolution(int dist[], int parent[], int src, int dest) {
	printf("Shortest path from node %d to node %d:\n", src, dest);
	printf("Node\tDistance\tPath\n");
	for (int i = 0; i < V; i++) {
		if (i == dest) {
			printf("%d\t%d\t\t%d ", i, dist[i], src);
			printPath(parent, i);
			printf("\n");
		}
	}
}

void dijkstra(int graph[V][V], int src, int dest) {
	int dist[V];
	int sptSet[V];
	int parent[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = 0, parent[src] = -1;
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = 1;
		for (int v = 0; v < V; v++) {
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, parent, src, dest);
}

int main() {
	int graph[V][V];
	FILE *f;
	f = fopen("matrix.txt", "r");
	if (f == NULL) {
		printf("Error: File not found.\n");
		return 0;
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			fscanf(f, "%d", &graph[i][j]);
		}
	}
	int src, dest;
	printf("Enter the starting node: ");
	scanf("%d", &src);
	printf("Enter the ending node: ");
	scanf("%d", &dest);
	dijkstra(graph, src, dest);
	return 0;
}


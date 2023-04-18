/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define MAXCOST 999999

int cost[N][N];
int visited[N] = {0};
int current_path[N];
int min_path[N+1];
int min_cost = MAXCOST;

void tsp(int current_city, int level) {
    visited[current_city] = 1;
    current_path[level] = current_city;
    
    if (level == N-1) {
        int cost_path = 0;
        for (int i = 0; i < N-1; i++) {
            cost_path += cost[current_path[i]][current_path[i+1]];
        }
        cost_path += cost[current_path[N-1]][current_path[0]];
        
        if (cost_path < min_cost) {
            min_cost = cost_path;
            for (int i = 0; i < N; i++) {
                min_path[i] = current_path[i];
            }
            min_path[N] = current_path[0];
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (visited[i] == 0 && cost[current_city][i] != 0) {
                tsp(i, level+1);
            }
        }
    }
    visited[current_city] = 0;
}

int main() {
    FILE *fp;
    fp = fopen("matrix.txt", "r");
    
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    // read cost matrix from file
    int f = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d", &cost[i][j]);
        }
        if(cost[0][N-1] == 0) {
        	printf("Cannot execute as a tsp rule is violated! \n");
        	exit(0);
        }
    }
    fclose(fp);
    
    // find the minimum cost path
    tsp(0, 0);
    
    // print the minimum cost and path
    printf("Minimum cost: %d\nPath: ", min_cost);
    for (int i = 0; i < N+1; i++) {
        printf("%d ", min_path[i]+1);
    }
    printf("\n");
    
    return 0;
}


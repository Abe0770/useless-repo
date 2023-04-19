/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100
#define MAXCOST 999999

int cost[N][N];
int visited[N] = {0};
int current_path[N];
int min_path[N+1];
int min_cost = MAXCOST;

void tsp(int current_city, int level, int lin) {
    visited[current_city] = 1;
    current_path[level] = current_city;

    if (level == lin-1) {
        int cost_path = 0;
        for (int i = 0; i < lin-1; i++) {
            cost_path += cost[current_path[i]][current_path[i+1]];
        }
        cost_path += cost[current_path[lin-1]][current_path[0]];

        if (cost_path < min_cost) {
            min_cost = cost_path;
            for (int i = 0; i < lin; i++) {
                min_path[i] = current_path[i];
            }
            min_path[lin] = current_path[0];
        }
    }
    else {
        for (int i = 0; i < lin; i++) {
            if (visited[i] == 0 && cost[current_city][i] != 0) {
                tsp(i, level+1, lin);
            }
        }
    }
    visited[current_city] = 0;
}

bool adj(int lin) {
	for(int i = 0; i < lin; i++) {
		for(int j = 0; j < lin ; j++) {
			if(cost[i][j] != cost[j][i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
    FILE *fp;
    fp = fopen("matrix.txt", "r");
    
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char c;
    int lin = 0;
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            lin = lin + 1;
    fclose(fp);
    fp = fopen("matrix.txt", "r");
    int f = 0;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < lin; j++) {
            fscanf(fp, "%d", &cost[i][j]);
            printf("%d ", cost[i][j]);
        }
    }
    fclose(fp);
    tsp(0, 0, lin);
    
    
    printf("Minimum cost: %d\nPaths available: ", min_cost);
    for (int i = 0; i < lin+1; i++) {
    	if(i == lin) {
    		printf("%d", min_path[i]+1);
    		continue;
        }
        printf("%d -> ", min_path[i]+1);
    }
    printf("\n");
    
    
    if(adj(lin)) {
	    for (int i = lin; i >= 0; i--) {
	    	if(i == 0) {
	    		printf("%d", min_path[i]+1);
	    		continue;
		}
		printf("%d -> " , min_path[i]+1);
	    }
    }
    
    return 0;
}


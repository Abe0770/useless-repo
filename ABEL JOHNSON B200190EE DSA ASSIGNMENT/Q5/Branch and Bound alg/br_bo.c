/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>

#define N 4
#define INF 9999

int adj[N][N] = {
    { 0, 10, 15, 20 },
    { 5,  0,  9, 10 },
    { 6, 13,  0, 12 },
    { 8,  8,  9,  0 }
};

int min(int a, int b) {
    return a < b ? a : b;
}

int calcLB(int currPath[], int lvl) {
    int cost = 0;
    int used[N] = { 0 };
    
    for (int i = 0; i < lvl; i++) {
        used[currPath[i]] = 1;
        cost += adj[currPath[i]][currPath[i+1]];
    }
    
    int lb = cost;
    for (int i = 0; i < N; i++) {
        if (used[i] == 0) {
            int minDist = INF;
            for (int j = 0; j < N; j++) {
                if (used[j] == 1) {
                    minDist = min(minDist, adj[j][i]);
                }
            }
            lb += minDist;
        }
    }
    
    return lb;
}

void BnB(int currPath[], int lvl, int currCost, int* minCost) {
    if (lvl == N) {
        *minCost = min(*minCost, currCost + adj[currPath[N-1]][currPath[0]]);
        return;
    }
    
    int lb = calcLB(currPath, lvl);
    if (lb + currCost >= *minCost) {
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (adj[currPath[lvl-1]][i] != 0) {
            int isVisited = 0;
            for (int j = 0; j < lvl; j++) {
                if (currPath[j] == i) {
                    isVisited = 1;
                    break;
                }
            }
            if (isVisited == 0) {
                currPath[lvl] = i;
                BnB(currPath, lvl+1, currCost+adj[currPath[lvl-1]][i], minCost);
                currPath[lvl] = -1;
            }
        }
    }
}

int main() {
    int currPath[N+1] = { 0 };
    int minCost = INF;
    currPath[0] = 0;
    BnB(currPath, 1, 0, &minCost);
    printf("Minimum Cost: %d\n", minCost);
    return 0;
}


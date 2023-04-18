#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define V 4

typedef struct node {
	int data, num;
	struct node *next;
}list;

list *head = NULL;
list *tail = NULL;
int count = 0 ;

void insert(int i) {
	list *new = (list*)malloc(sizeof(list));
	new -> data = i;
	new -> next = NULL;
	if(head == NULL) {
		head = new;
		tail = new;
		new -> num = count++;
	}
	else {
		tail -> next = new;
		tail = new;
		new -> num = count++;
	}
}

void nextPerm(int *p, int len) {
  int found = 0;
  int i = len - 2;
  while (i >= 0) {
    if (p[i] < p[i + 1]) {
      found = 1;
      break;
    }
    i--;
  }
  if (!found) {
    printf("\nLast permutation reached.\nE.g. (4,3,2,1,0) from (0,1,2,3,4).\n\n");
    return; 
  }
  int tempLen = len - i;
  int tempNums[tempLen];
  int tempInt;
  for (int j = 0; j < tempLen; j++) {
    tempNums[j] = p[i + j];
  }
  for (int j = 0; j < tempLen; j++) {
    for (int k = j + 1; k < tempLen; k++) {
      if (tempNums[j] > tempNums[k]) {
        tempInt = tempNums[j];
        tempNums[j] = tempNums[k];
        tempNums[k] = tempInt;
      }
    }
  }
  int closestFound = 0;
  for (int l = 0; l < tempLen; l++) {
    if (!closestFound && tempNums[l] > p[i]) {
      p[i] = tempNums[l];
      closestFound = 1;
    } else {
      p[i + l + 1 - closestFound] = tempNums[l];
    }
  }
}
bool stringsRearrangement(arr_string inputArray) {
  int permArray[inputArray.size];
  int poss = 1;
  for (int i = 0; i < inputArray.size; i++) {
    permArray[i] = i;
    poss *= i + 1;
  }
  printf("Possibilities: %i\n", poss);
  for (int j = 0; j < poss; j++) {
    int diff;
    for (int k = 0; k < inputArray.size; k++) {
      diff = 0;
      if (k != inputArray.size - 1) {
        for (int l = 0; l < strlen(inputArray.arr[0]); l++) {
          int permA = permArray[k];
          int permB = permArray[k + 1];
          diff += (inputArray.arr[permA][l] != inputArray.arr[permB][l]);
        }
      } else {
        printf("Match found!\n\n");
        return 1;
      }
      if (diff != 1) {
        break;
      }
    }
    nextPerm(permArray, inputArray.size);
  }
  return 0;
}

int travllingSalesmanProblem(int graph[][V], int s)
{
	for (int i = 0; i < V; i++)
		if (i != s)
			insert(i);

	int min_path = INT_MAX;
	do {
		int current_pathweight = 0;

		int k = s;
		for (list *i = head; i != NULL; i = i -> next) {
			current_pathweight += graph[k][i -> num];
			k = vertex[i -> num];
		}
		current_pathweight += graph[k][s];

		min_path = min(min_path, current_pathweight);

	} while (
		nextPerm(head -> num, tail -> num));

	return min_path;
}


int main()
{
	int graph[][V] = { { 0, 10, 15, 20 },
					{ 10, 0, 35, 25 },
					{ 15, 35, 0, 30 },
					{ 20, 25, 30, 0 } };
	int s = 0;
	printf("%d \n", travllingSalesmanProblem(graph, s));

	return 0;
}


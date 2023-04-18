/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

/*
USING CALL BY REFERENCE FOR MORE EFFICIENCY, OTHER METHODS CAN BE RETURNING, WRITING IN MAIN FUNCTION, USE OF GLOBAL VARIABLES ETC

---------------------------------------------------------------------------------------------
IF THE DUPLICATES ARE SUPPOSED TO BE REMOVED, REPLACE THE SORT FUNCTION WITH THE BELOW SNIPPET
---------------------------------------------------------------------------------------------

void bubble_sort(int *a, int *y){
	for(int i = 0; i < *y; i++)
		for(int j = i+1; j < *y; j++) {
			if(a[j] < a[i]) {
				a[i] ^= a[j];
		       		a[j] ^= a[i];
		       		a[i] ^= a[j];
			}
			else if(a[i] == a[j]) {
				a[j] = a[*y-1];
				(*y)--;
				j--;
			}
		}
}

*/

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int *y){
	for(int i = 0; i < *y; i++)
		for(int j = i+1; j < *y; j++) {
			if(a[j] < a[i]) {
				a[i] ^= a[j];
		       		a[j] ^= a[i];
		       		a[i] ^= a[j];
			}
		}
}


void display(int a[10000], int y) {
	printf("The sorted array : ");
	for(int i = 1 ; i < y ; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	FILE *f = fopen("input.txt", "r");
	!f ? printf("ERROR : Cannot open file!"), exit(0) : 0;
	int a[10000], i = 0;
	while(fscanf(f, "%d", &a[i++]) != EOF){}	
	bubble_sort(a, &i);
	display(a, i);
	
	return 0;
}

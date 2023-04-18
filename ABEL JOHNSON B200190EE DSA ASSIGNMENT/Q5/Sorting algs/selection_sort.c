/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/


/*
USING GLOBAL VARIABLES, OTHER METHODS CAN BE RETURNING, WRITING IN MAIN FUNCTION, USE OF CALL BY REFERENCE ETC

-------------------------------------------------------------------
IF THE DUPLICATES ARE SUPPOSED TO BE REMOVED, USE THE BELOW SNIPPET
-------------------------------------------------------------------

void remove_duplicates() {
	for(int i = 0 ; i < n-1; i++)
		for(int j = i+1 ; j < n ; j++){
		        if (a[i] == a[j]){
			            a[j] = a[n-1];
			            n--;
			            j--;
		        }
	        }
}

int main() {
	FILE *f = fopen("input.txt", "r");
	!f ? printf("ERROR : Cannot open file!"), exit(0) : 0;
	while(fscanf(f, "%d", &a[n++]) != EOF){}
	remove_duplicates();
	selection_sort();
	display();
	return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

int a[10000], n = 0;

void selection_sort() {
	int curr_ptr, curr_min;
	for (int i = 0; i < n; i++) {
        	curr_min = i;
        	for (int j = i+1; j < n; j++)
          		if (a[j] < a[curr_min])
            			curr_min = j;
           	if(curr_min != i) {
           		a[i] ^= a[curr_min];
               		a[curr_min] ^= a[i];
               		a[i] ^= a[curr_min];
               	}
    }
}

void display() {
	printf("The sorted array : ");
	for(int i = 1 ; i < n ; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	FILE *f = fopen("input.txt", "r");
	!f ? printf("ERROR : Cannot open file!"), exit(0) : 0;
	while(fscanf(f, "%d", &a[n++]) != EOF){}	
	selection_sort();
	display();
	
	return 0;
}

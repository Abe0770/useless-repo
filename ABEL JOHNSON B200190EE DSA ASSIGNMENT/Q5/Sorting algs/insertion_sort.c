/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

/*
USING CALL BY REFERENCE FOR MORE EFFICIENCY, OTHER METHODS CAN BE RETURNING, WRITING IN MAIN FUNCTION, USE OF GLOBAL VARIABLES ETC

---------------------------------------------------------------------------------------------
IF THE DUPLICATES ARE SUPPOSED TO BE REMOVED, REPLACE THE SORT FUNCTION WITH THE BELOW SNIPPET
---------------------------------------------------------------------------------------------

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
	insertion_sort();
	display();
	return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

int a[10000], n = 0;


void insertion_sort() {
	for (int i = 1; i < n; i++) {
		int pt = a[i];
		int pre = i - 1;

		while (pt < a[pre] && pre >= 0) {
			a[pre + 1] = a[pre];
			pre--;
		}
		a[pre + 1] = pt;
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
	insertion_sort();
	display();
	
	return 0;
}

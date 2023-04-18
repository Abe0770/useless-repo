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
	quick_sort(a, 0, (n-2));
	display();
	return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

int a[10000], n = 0;

void quick_sort(int a[10000], int beg, int end) {
	if(beg < end) {
		int pivot = beg, i = beg, j = end, t;
		while(i < j) {
			while(a[i] <= a[pivot] && i < end)
				i++;
			while(a[j] > a[pivot])
				j--;
			if(i < j) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			t = a[pivot];
			a[pivot] = a[j];
			a[j] = t;
			quick_sort(a, 0, j-1);
			quick_sort(a, j+1, end);
		}
	}
}

void display() {
	printf("The sorted array : ");
	for(int i = 0 ; i < n-1 ; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	FILE *f = fopen("input.txt", "r");
	!f ? printf("ERROR : Cannot open file!"), exit(0) : 0;
	while(fscanf(f, "%d", &a[n++]) != EOF){}	
	quick_sort(a, 0, (n-2));
	display();
	
	return 0;
}

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
	merge_sort(a, 0, (n-2));
	display();
	return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

int a[10000], b[10000], n = 0;

void merge(int a[10000], int beg, int mid, int end) {
	int temp = n;
	int i = beg, k = beg, j = mid+1;
	while(i <= mid && j <= end) {
		if(a[i] > a[j])
			b[k++] = a[j++];
		else 
			b[k++] = a[i++];
	}
	while(i <= mid)
		b[k++] = a[i++];
	while(j <= end)
		b[k++] = a[j++];
	for(int l = beg; l <= end; l++)
		a[l] = b[l];
}

void merge_sort(int a[10000], int beg, int end) {
	if(beg < end) {
		int mid = (beg + end) / 2;
		merge_sort(a, beg, mid);
		merge_sort(a, mid+1, end);
		merge(a, beg, mid, end);
	}
}

void display() {
	printf("The sorted array : ");
	for(int i = 0 ; i < n-1 ; i++)
		printf("%d ", b[i]);
	printf("\n");
}

int main() {
	FILE *f = fopen("input.txt", "r");
	!f ? printf("ERROR : Cannot open file!"), exit(0) : 0;
	while(fscanf(f, "%d", &a[n++]) != EOF){}	
	merge_sort(a, 0, (n-2));
	display();
	
	return 0;
}

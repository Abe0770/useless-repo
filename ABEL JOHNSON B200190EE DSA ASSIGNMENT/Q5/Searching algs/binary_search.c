/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/


#include <stdio.h>
#include <stdlib.h>

int a[10000], n=0;

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

int binary_search(int num) {
	int beg = 0, end = n-1;
	while(beg <= end){ 
		int mid = (beg + end) / 2;
		
		if(num == a[mid])
			return mid;
		
		else if(num < a[mid]) 
			end = mid-1;
		
		else if(num > a[mid]) 
			beg = mid+1;
			
	}
	return -1;
}

int main() {
	FILE *f = fopen("input.txt", "r");
	!f ? printf("ERROR : Cannot open file!"), exit(0) : 0;
	char ch;
	while(fscanf(f, "%d", &a[n++]) != EOF){}
	selection_sort();
	int num;
	START: 
	printf("Enter the number to find : ");
	scanf("%d", &num);
	int aa = binary_search(num);
	if (aa == -1)
		printf("\033[0;31mNumber %d was not found!\033[0m", num);
	else 
		printf("\033[0;32mNumber %d was found at index %d of the sorted array\033[0m\n", num, aa);
				
	printf("\nsearch again? [y/n] : ");
	scanf("%s", &ch);
	if(ch == 'y' || ch == 'Y')
		goto START;
	return 0;
}

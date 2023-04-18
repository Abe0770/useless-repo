/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f = fopen("input.txt", "r");
	!f ? printf("ERROR : Cannot open file!"), exit(0) : 0;
	int a[10000], num, n=0;
	char ch;
	while(fscanf(f, "%d", &a[n++]) != EOF){}
	START: 
	int flag = 0;
	printf("Enter the number to find : ");
	scanf("%d", &num);
	for(int i = 0 ; i < n ; i++){
		if(num == a[i]) {
			printf("\033[0;32mNumber %d was found at index %d\n\033[0m", num, i+1);
			flag++;
		}
	}		
	if(flag == 0)
		printf("\033[0;31mNumber %d was not found!\033[0m", num);
	printf("\nsearch again? [y/n] : ");
	scanf("%s", &ch);
	if(ch == 'y' || ch == 'Y')
		goto START;
	return 0;
}

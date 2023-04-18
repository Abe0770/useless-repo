/*
ABEL JOHNSON B200190EE
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/


/*
Assuming every student with total percentage greater than 40% pass the semester even if they fail in any one subject.

if failure in one subject makes them fail the semester the program can be modified as shown 

while (fgets(line, 100, f) != NULL) {
	    int sum = 0;
	    unsigned int mark = 0;
		sscanf(line, "%s %d %d %d %d", string, &arr[0], &arr[1], &arr[2], &arr[3]);
		printf("%-16s", string);
		int fa = 0;
		for( int i = 0 ; i < 4 ; i++ ) {
		    mark = arr[i] < 40 ? 0 : (arr[i] > 80 ? 5 : (arr[i]/10)-3);
		    grade[mark] == 'F' ? printf("\033[0;31m") : (grade[mark] == 'A' ? printf("\033[0;32m") : 0);
		    printf("%10d-%c", arr[i], grade[mark]);
		    	printf("\033[0m");
		    sum = sum + arr[i];
		    if(arr[i] < 40)
		    	fa = 1; 
		}
		printf("%10d\t", sum);
		sum = sum < 160 ? 0 : (sum > 320 ? 5 : (sum/40)-3);
		if(fa > 0)
			sum = 0;
		grade[sum] == 'F' ? printf("\033[0;31m") : (grade[sum] == 'A' ? printf("\033[0;32m") : 0);
		printf("%6c\n", grade[sum]);
		printf("\033[0m");
	}

*/


/*
EXECUTE IN FULL SCREEN MODE FOR BETTER RESULT
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *f = fopen("marks.txt", "r");
	!f ? printf("Error : File not found!"), exit(0) : 0;
	char line[100];
	char string[100];
	int arr[4];
	char grade[10] = {'F', 'E', 'D', 'C', 'B', 'A'};
	printf("\e[1mRESULT\n");
	printf("NAME\t\t       PHYSICS\t    MATHS     CHEMISTRY    BIOLOG     TOTAL\tFINAL GRADE\n\033[0m");
	while (fgets(line, 100, f) != NULL) {
	    int sum = 0;
	    unsigned int mark = 0;
		sscanf(line, "%s %d %d %d %d", string, &arr[0], &arr[1], &arr[2], &arr[3]);
		printf("%-16s", string);
		
		for( int i = 0 ; i < 4 ; i++ ) {
		    mark = arr[i] < 40 ? 0 : (arr[i] > 80 ? 5 : (arr[i]/10)-3);
		    grade[mark] == 'F' ? printf("\033[0;31m") : (grade[mark] == 'A' ? printf("\033[0;32m") : 0);
		    printf("%10d-%c", arr[i], grade[mark]);
		    	printf("\033[0m");
		    sum = sum + arr[i];
		}
		printf("%10d\t", sum);
		sum = sum < 160 ? 0 : (sum > 320 ? 5 : (sum/40)-3);
		grade[sum] == 'F' ? printf("\033[0;31m") : (grade[sum] == 'A' ? printf("\033[0;32m") : 0);
		printf("%6c\n", grade[sum]);
		printf("\033[0m");
	}
	return 0;
}

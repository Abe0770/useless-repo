/*
ABEL JOHNSON B200190EE
IMPLEMENTATION OF STACK USING LINKED LIST
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>

int a[3][3][3] = {2,1,3,2,4,2,6,2,4,6,1,4,7,3,7,2,5,7,3,4,3,2,4,5,9,6,3}, b[3][3][3] = {3,6,9,3,5,4,8,5,6,2,7,9,5,3,8,6,9,4,7,6,8,4,6,5,0,4,2}, c[3][3][3];

void multiplication(){
	
}

void display(){

	printf("MATRIX A \n");
	for(int k=0; k<3; k++){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("%d ", a[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("MATRIX B \n");
	for(int k=0; k<3; k++){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("%d ", b[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("RESULTANT MATRX C \n");
	for(int k=0; k<3; k++){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				printf("%d ", c[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void defau_val()
{
	int f = 0;
	for(int k=0; k<3; k++){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				c[k][i][j] = a[k][i][f]*b[k][f][j] + a[k][i][f+1]*b[k][f+1][j] + a[k][i][f+2]*b[k][f+2][j];
			}
		}
	}
	display();
}

void insert(){
	printf("\nCustom Matrix Values\n\nEnter 27 values for matrix A :\n");
	for(int k=0; k<3; k++){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				scanf("%d", &a[k][i][j]);
			}
		}
	}
	printf("\nCustom Matrix Values\n\nEnter 27 values for matrix B :\n");
	for(int k=0; k<3; k++){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				scanf("%d", &b[k][i][j]);
			}
		}
	}
	defau_val();
}

int main()
{
	int op;
	printf("\n\nMATRIX MULTIPLICATION\n\nSelect your choice\n[1] Insert custom values\n[2] Run with default values\n\nEnter your choice : ");
	scanf("%d", &op);
	if(op == 2)
		defau_val();	
	else if(op == 1)
		insert();
	return 0;
}

/*
ABEL JOHNSON B200190EE
ARRAY AND ITS FUNCTIONS
COMPILER VERSION - gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[1000000], n=0;

void insert()
{	
	int num;
	printf("\nEnter the number : ");
	scanf("%d", &num);
	n++;
	int flag = 0;
	for(int i = 0; i<n; i++)
	{
		if(arr[i] == num)
		{
			flag++;
			break;
		}
	}
	if(flag == 0)
	{
		arr[n-1] = num;	
	}
	else
	n--;
}

void delete()
{
	// Swapping last element and the element to be deleted to decrease time complexity to O(n) [searching] other than pushing elements one index left
	if(n==0)
	{
		printf("\n---------------");
		printf("\nARRAY IS EMPTY!");
		printf("\n---------------");
	}
	else
	{
		int num, flag = 0;
		printf("\nEnter the element to delete : ");
		scanf("%d", &num);
		for(int i=0; i<n; i++)
		{
			if(arr[i] == num)
			{
				printf("\n-----------------------------");
				printf("\nThe element %d was deleted!", num);
				printf("\n-----------------------------");
				arr[i] = arr[n-1];
				arr[n-1] = arr[n-1] - num - 11111111;
				n = n - 1;
				flag++;
			}
		}
		if(flag == 0)
		{
			printf("\n----------------------------");
			printf("\nElement %d was not found!", num);
			printf("\n----------------------------");
		}
		flag = 0;
	}
}

void search()
{
	int num, flag = 0;
	printf("\nEnter a number to search : ");
	scanf("%d", &num);
	for(int i=0; i<n; i++)
	{
		if(arr[i] == num)
		{
			printf("\n------------------------------------------");
			printf("\nThe element %d was found at the index %d!", num, i);
			printf("\n------------------------------------------");
			flag++;
		}
	}
	if(flag == 0)
	{
		printf("\n----------------------------");
		printf("\nElement %d was not found!", num);
		printf("\n----------------------------");
	}
	flag = 0;
}

void display()
{
	if(n==0)
	{
		printf("\n--------------------------------");
		printf("\nArray is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		printf("\n--------------------------------");
		printf("\nArray elements : \n");
		for(int i = 0; i<n; i++)
		{
			printf("%d\n", arr[i]);
		}
		printf("\n--------------------------------");
	}
}

void sort()
{
	if(n==0)
	{
		printf("\n--------------------------------");
		printf("\nArray is empty!");
		printf("\n--------------------------------");
	}
	else
	{
		for(int i=0; i<n-1; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(arr[i] > arr[j])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}	
			}
		}
		display();
	}
}

int main()
{
	int op;
	
	while(1)
	{
		printf("\n\nSelect your choice\n[1] Insert\n[2] Delete \n[3] Search\n[4] Sort \n[5] Display\n[6] Exit\nEnter your choice : ");
		scanf(" %d", &op);
		scanf( "%*[^\n]" );
		if(op == 1)
			insert();
		else if(op == 2)
			delete();
		else if(op == 3)
			search();
		else if(op == 4)
			sort();
		else if(op == 5)
			display();
		else if(op == 6)
			exit(0);
		else 
		printf("\nInvalid option! Try again...");
	}
	return 0;
}

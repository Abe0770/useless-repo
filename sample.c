#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ABC {
                      char name [100];
                      struct ABC *next;
}SR;

typedef struct ABC1 {
                      int rollno;
                      SR *datap;
                      struct ABC1 *next;
}node;
//Insert at head
node *insert1 (node *p, int, SR *datap);
//Insert at tail 
node *insert2 (node *p, int, SR *datap);

node *insert1 (node *p, int rollno, SR *datap)
{
   node *newnode, *temp, *head;

   temp = p;

   newnode = (node *)malloc(sizeof(node));
   newnode->rollno = rollno;
   newnode->datap = datap;
   newnode->next = NULL;

   if (temp == NULL)
   {
     temp = newnode;
     head = temp;
     printf ("\n First Record in the list");
   }
   else
   {
      newnode->next = temp;
      temp = newnode;
      head = temp;
   }
return head;
}
node *insert2 (node *p, int rollno, SR *datap)
{
   node *newnode, *temp, *head, *temp1;
   node *prev = NULL;
   temp = p;

   newnode = (node *)malloc(sizeof(node));
   newnode->rollno = rollno;
   newnode->datap = datap;
   newnode->next = NULL;

   if (temp == NULL)
   {
     temp = newnode;
     head = temp;
     printf ("\n First Record in the list");
   }
   else
   {
       temp1 = temp; 
      while (temp1 != NULL)
      {
        prev = temp1;
        temp1 = temp1->next;
      }
      prev->next = newnode;
      head = temp;
   }
return head;
}

SR *insertname (SR *q, char* name)
{
   SR *newnode, *temp, *head;

   temp = q;

   newnode = (SR *)malloc(sizeof(SR));
   strcpy(newnode->name, name); 
   newnode->next = NULL;

   if (temp == NULL)
   {
     temp = newnode;
     head = temp;
     printf ("\n First Record in the list");
   }
   else
   {
      newnode->next = temp;
      temp = newnode;
      head = temp;
   }
return head;
}

void display(node *p) {
   if( p == NULL)
   	printf("\nThe list is empty!");
   while (p)
   {
     printf ("\n the record list is rollno %d Name : %s", p->rollno, p->datap->name);
     //printf ("\n the  name list is Name : %s", datap->name);
     p = p->next;
   }
}

node *reverse(node *p) {
	node *a = p, *b = p-> next, *temp = p;
	if(p == NULL || p -> next == NULL) {
	return temp;
	}
	else {
		while(b != NULL){
			a = b;
			b = b -> next;
			a -> next = temp;
			temp = a;
		}
		p -> next = NULL;
	}
	return a;
}

node *sort(node *p) {
	char t[100];
	if(p == NULL) 
		return NULL;
	else {
		for(node *i = p; i -> next != NULL; i = i -> next) {
			for (node *j = i -> next; j != NULL; j = j -> next) {
				if(j -> rollno < i -> rollno) {
					i -> rollno = i-> rollno + j -> rollno;
					j -> rollno = i -> rollno - j -> rollno;
					i -> rollno = i -> rollno - j -> rollno;
					strcpy(t, i -> datap-> name);
					strcpy(i -> datap -> name, j -> datap -> name);
					strcpy(j -> datap -> name, t);
				}
			}
		}
	}
}

node *delete(node *p) {
	printf("\nEnter a rollno to delete : ");
	int a, f=0;
	scanf("%d", &a);
	if(p == NULL) {
		printf("\nThe list is empty!");
	}
	else if(p -> rollno == a && p -> next == NULL)
	{
		p = p -> next;
		return p;
	}
	else if(p -> next == NULL) {
		printf("\nRecord not found");
	}
	else {
		node *ptr = p -> next, *temp = p;
		while(ptr != NULL) {
			if (ptr -> rollno == a) {
				temp -> next = ptr -> next;
				f++;
				break;
			}
			temp = temp -> next;
			ptr = ptr -> next;
		}
		if(f == 0)
		printf("\nRecord not found!");
	}
	return p;
}

int roll = 1;
node *readfile(node** p, SR** datap) {
	FILE *tfile;
	char line[100];
	tfile = fopen("list.txt", "r");
	if(tfile == NULL)
		printf("\nCannot open file!");
	while(fgets(line, 100, tfile)) {
		*datap = insertname (*datap, line);
   	    	*p = insert2 (*p, roll, *datap);
   	    	roll++;
	}
}

int main()
{
   int num;
   char name[100];
   node *p = NULL;
   SR *datap = NULL;
   int op;
    while(1) {
        printf("\n\nSelect an option\n[1] Insert at the end\n[2] Insert at the beginning\n[3] display\n[4] Reverse\n[5] Sort according to roll number in ascending order\n[6] Sort in descending order\n[7] Delete\n[8] Read from a file called list\n[9] Exit\nEnter your option : ");
        scanf("%d", &op);
        scanf("%*[^\n]");
        if(op == 1) {
            printf("\nEnter the name of the student : ");
            scanf("%s", name);
            printf("\nEnter the roll number of %s : ", name);
            scanf("%d", &num);
            datap = insertname (datap, name);
   	    p = insert2 (p, num, datap);
        }
        if(op == 2){
            printf("\nEnter the name of the student : ");
            scanf("%s", name);
            printf("\nEnter the roll number of %s : ", name);
            scanf("%d", &num);
            datap = insertname (datap, name);
   	    p = insert1 (p, num, datap);
        }
        else if(op == 3) {
        	display(p);
        }
        else if(op == 4) {
        	p = reverse(p);
        	display(p);
        }
        else if(op == 5) {
        	sort(p);
        	display(p);
        }
        else if (op == 6) { 
        	sort(p);
        	p = reverse(p);
        	display(p);
        }
        else if(op == 7) {
        	p = delete(p);
        }
        else if(op == 8) {
        	readfile(&p, &datap);
        }
        else if(op == 9)
            exit(0);
    }
   return 0;
}

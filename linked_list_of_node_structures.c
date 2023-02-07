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
   while (p)
   {
     printf ("\n the record list is rollno %d Name : %s", p->rollno, p->datap->name);
     //printf ("\n the  name list is Name : %s", datap->name);
     p = p->next;
   }
}

void reverse() {
	int a;
}

void delete(node *p, int rollno, SR *datap) {
   node *temp = p, *prev = NULL;
   SR *temp1 = datap, *prev1 = NULL;
   while (temp != NULL && temp->rollno != rollno) {
      prev = temp;
      temp = temp->next;
   }
   while (temp1 != NULL && strcmp(temp1->name, datap->name) != 0) {
      prev1 = temp1;
      temp1 = temp1->next;
   }
   if (temp == NULL) {
      printf("Node with roll number %d not found\n", rollno);
      return;
   }
   if (temp1 == NULL) {
      printf("Node with name %s not found\n", datap->name);
      return;
   }
   if (prev != NULL) {
      prev->next = temp->next;
   }
   if (prev1 != NULL) {
      prev1->next = temp1->next;
   }
   free(temp);
   free(temp1);
   printf("Node with roll number %d and name %s deleted successfully\n", rollno, datap->name);
}


int main()
{
   node *p = NULL;
   SR *datap = NULL;
   char name[100];
   int op, rolll;
    while(1) {
        printf("\nSelect an option\n[1] Insert at head\n[2] Insert at tail\n[3] Delete\n[4] Display\n[5] Exit\nEnter your option : ");
        scanf("%d", &op);
        if(op == 1)
        {
            printf("\nEnter name : ");
            scanf("%s", name);
            printf("\nEnter Roll Number : ");
            scanf("%d", &rolll);
            datap = insertname (datap, name);
   	    p = insert1 (p, rolll, datap);
        }
        if(op == 2)
        {
            printf("\nEnter name : ");
            scanf("%s", name);
            printf("\nEnter Roll Number : ");
            scanf("%d", &rolll);
            datap = insertname (datap, name);
   	    p = insert2 (p, rolll, datap);
        }
        if(op == 3)
        {
        	printf("Enter a rolll number to delete : ");
        	scanf("%d", &rolll);
        	delete(p, rolll, datap);
        }
        if(op == 4)
            display(p);
        else if(op == 7)
            exit(0);
   }   
   return 0;
}


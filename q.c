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

int main()
{
   node *p = NULL;
   SR *datap = NULL;
   datap = insertname (datap, "Mukti");
   p = insert2 (p, 1, datap);
   datap = insertname (datap, "Jayanta");
   p = insert2 (p, 2, datap);
   datap = insertname (datap, "Mouma");
   p = insert2 (p, 3, datap);
   datap = insertname (datap, "Anusmita");
   p = insert2 (p, 4, datap);
   datap = insertname (datap, "Dui");
   p = insert2 (p, 5, datap);
 
   while (p)
   {
     printf ("\n the record list is rollno %d Name : %s", p->rollno, p->datap->name);
     //printf ("\n the  name list is Name : %s", datap->name);
     p = p->next;
   }
   return 0;
}


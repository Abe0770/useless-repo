#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *link; // self referencing 
} *head = NULL;

struct node * check(int che)
{
    struct node *p = head;
    while(p != NULL) {
        if(che == p -> data)
        return NULL;
        if(p -> link == NULL)
        break;
        p = p-> link;
    }
    return p;
}


void insert() {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    cout << "\nEnter your data : ";
    int dat;
    cin >> dat;
    newnode -> data = dat;
    newnode -> link = NULL;
    struct node *p=head;
    if(head == NULL)
        head = newnode;
    else {
        struct node *temp = check(dat);
        if(temp != NULL) {
            temp -> link = newnode;
        }
    }
}

void display() {
    struct node *temp = head;
    if(temp == NULL)
        cout << "The linked list is empty";
    else {
        cout << "The elements of the linked list are : \n";
        while(temp != NULL) {
            cout << temp -> data << "\n";
            temp = temp -> link;
        }
    }
}

void reverse()
{
    if(head -> link == NULL || head == NULL)
        display();
    else {
        struct node *a=head, *b=head -> link, *temp = head;
        if(head -> link -> link == NULL) {
            head -> link -> link = head;
            head = head -> link;
            head -> link -> link = NULL;
        }
        else {
            while(b != NULL) {
                a = b;
                b = a -> link;
                a -> link = temp;
                temp = a;
            }
            head -> link = NULL;
            head = a;
        }
    }
    display();
}

void binsert() {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    cout << "\nEnter your data : ";
    int dat;
    cin >> dat;
    newnode -> data = dat;
    if(head == NULL) {
        newnode -> link = NULL;
        head = newnode;
    }
    else if(check(dat) != NULL) {
        newnode -> link = head;
        head = newnode;
    }
}

int main() {
    int op;
    while(1) {
        cout << "\nSelect an option\n[1] Insert at the end\n[2] Insert at the beginning\n[3] display\n[4] Reverse\n[7] Exit\nEnter your option : ";
        cin >> op;
        if(op == 1)
            insert();
        if(op == 2)
            binsert();
        if(op == 3)
            display();
        if(op == 4)
            reverse();
        else if(op == 7)
            exit(0);
    }
}

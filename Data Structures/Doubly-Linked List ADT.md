#  **Doubly-Linked List ADT**
### What is Doubly Linked-List
Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous and the next node in the sequence. Therefore, in a doubly-linked list, a node consists of three parts:
* node data
* a pointer to the next node in sequence (next pointer)
* a pointer to the previous node (previous pointer)

A sample node in a doubly-linked list is shown in the figure.

![](https://i.imgur.com/zVbEtkK.png)

This is how a linked-list looks like:

![](https://i.imgur.com/BblFhKN.png)

![](https://i.imgur.com/N8xv8Q7.png)


* **Inserting a node in a linked list**

![](https://i.imgur.com/usZgAK1.png)

* **Deleting a node in a linked list**

![](https://i.imgur.com/L1bMuzP.png)

```c
#include<stdio.h>
#include<stdlib.h>

 struct Node
 {
    int val;
    struct Node* prev;
    struct Node* next;
    
 };

 struct ListRecord
 {
    struct Node* head;
    struct Node* tail;
    int length;
 };
 
 typedef struct ListRecord *List;

// Function to make empty Doubly Linked List
void Makeemptylist(List l)
{
    l->head = (struct Node*)malloc(sizeof(struct Node));
    if(l==NULL) // Checking l is NULL or not
    {
        printf("\nOut of memory !");
        exit(0);
    }
    else
    {
        l->head->prev = NULL;
        l->head->next = NULL;
        l->tail = l->head;
        l->length = 0;
    }
}

 // Function to create Doubly Linked List 
 List createlist(int size)
 {
    List L;
    L = (struct ListRecord*)malloc(sizeof(struct ListRecord));
    if(L==NULL) // Checking L is NULL or not
    {
        printf("\nOut of memory !");
        return NULL;
    }
    else
    {
        Makeemptylist(L);
        return L;
    }
 }


// Function to insert from the beginning
void insert_beg(List L,int x)
{
    struct Node *newnode; // creating newnode
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL) // Checking newnode is NULL or not
    {
        printf("\nOut of memory !");
        exit(1);
    }
    else
    {
        
        newnode->val=x;
        newnode->next=NULL;
        newnode->prev = NULL;

        // adding part
        // because tail is moving ^-^
        L->tail->next=newnode;
        newnode->prev = L->tail;
        L->tail=newnode;
        L->length++;
        // inserting the elements beginning of the list
    }
}

// Function to insert a Node at given position in Doubly Linked List 
void insert(List l,int pos, int val)
{
    struct Node *newnode; // creating newnode
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL) // Checking newnode is NULL or not
    {
        printf("\nOut of memory !");
        exit(1);
    }
    else
    {
        newnode->val = val;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(pos > l->length + 1 ) // adjusting position
            pos = l->length + 1;
        if(pos == l->length + 1) // inserting at the end (tail)
        {
            l->tail->next = newnode;
            newnode->prev = l->tail;
            l->tail = newnode;
        } 
        else // inserting between two nodes
        {
            int i;
            struct Node *dummy;
            dummy = l->head;
            // finding proper position to add
            for (i = 0; i < pos ; i++)
            {
                dummy = dummy->next;
            }
            newnode->prev = dummy;
            dummy->next = newnode;
            newnode->next = dummy->next;
            dummy->next->prev = dummy;
            dummy = newnode;
        }
    }
}

// function to print Doubly Linked List
void Normal_print(List l)
{
    struct Node* current;
    current = l->head->next;
    while(current != NULL)
    {
        printf(" %d <-->",current->val);
        current = current->next;
    }
    printf("\n");
}

// function to print Doubly Linked List
void Reverse_print(List l)
{
    struct Node* current;
    current = l->tail;
    while(current->prev != NULL)
    {
        printf(" %d <-->",current->val);
        current = current->prev;
    }
    printf("\n");
}

int main()
{
    List l;
    l = createlist(4);
    insert_beg(l,1);
    insert_beg(l,2);
    insert_beg(l,5);
    Reverse_print(l);
    Normal_print(l);
}
```




# **Fundamentals of Linked Lists**
**(Pointers and Dynamic Memory Allocation)**

**Purpose:**
This writeup contains.
1. Static vs. dynamic memory allocation
2. Traversal of linked lists
3. Simple algorithms and pointer manipulation for linked lists

A linked list is recursively defined as
*  an empty list, or
*  a node followed by a list
This recursive definition gives rise to the following declaration for linked lists:
```c
struct Node
{
int val;
struct Node *next;
};
```
![](https://i.imgur.com/Wi4UIVz.png)


---



### Example Code

a) Node declaration of a Linked List with prices of a BMW cars.

b) A function InsertCars() that creates a linked list of the cars and fills it with the prices taken from the user.

c) A function ApplySale()that takes the linked list of the cars as an input, and then creates a linked list of a carsSale and fills it with the updated prices (%20 discount for car prices less than 20000 and %40 discount for car prices greater than or equal to 20000) and then returns.

d) A function PrintPrices() that takes the linked list of cars or carsSale as an input, traverses and prints the list.

If the input prices are as 10000, 12000 and 80000 (please note that you cannot make any assumptions regarding to the size of the list (number of car prices)), then list formed by InsertCars() should be as follows;

![](https://i.imgur.com/BziNIjM.png)

Then the returned list from ApplySale()should be as follows; 

![](https://i.imgur.com/6yHnwNs.png)

```c
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct node *next;
};

void printprices(struct Node *list)
{
    while(list!=NULL)
    {
        printf("%d  ",list->data);
        list=list->next;
    }
}
/*InsertCars function creates a linked list of the cars and fills it with the prices taken from
the user.*/
struct Node* InsertCars()
{

    struct Node *temp,*head=NULL;
    int i,count,result;
    printf("How many cars?");
	scanf("%d",&count);

	for  (i = 0; i < count; i++)
	{
		printf("Enter prices for the product:");
        scanf("%d",&result);
        if(head==NULL)
        {
            temp=(struct Node*) malloc(sizeof(struct Node));
            head=temp;
            temp->data=result;
            temp->next=NULL;
        }
        else
        {
            temp->next=(struct Node*) malloc(sizeof(struct Node));
            temp=temp->next;
            temp->data=result;
            temp->next=NULL;
        }
	}
    printf("Prices for the cars are created successfully!");

    return head;
}

struct Node* ApplySale(struct Node* head)
{
    
    struct Node* new_list=NULL;
    
    for(head;head!=NULL;head=head->next)
    {
        
        if(new_list==NULL)
        {
            new_list = (struct Node*) malloc(sizeof(struct Node));
            new_list=head;
            if(head->data>20000)
            {
                
                new_list->data = ((head->data)*80/100);
            }
            else
            {
                new_list->data = ((head->data)*80/100);
            }
            new_list->next=NULL;
            
        }
        else
        {
            new_list = (struct Node*) malloc(sizeof(struct Node));
            new_list=new_list->next;
            
            if(head->data>20000)
            {
                
                new_list->data = ((head->data)*80/100);
            }
            else
            {
                new_list->data = ((head->data)*80/100);
            }
            
            new_list->next=NULL;
        }
        
    }
     printf("Prices for the sale cars are created successfully!");

    return new_list;
}




int main()
{
	struct Node *head;
    int choice=0;
	int n;
    while(choice!=5)
    {
        printf("\n****************************************************\n");
        printf("1) Create prices for the cars\n");
        printf("2) Display prices for the cars\n");
        printf("3) Create sale prices for the cars\n");
        printf("4) Display prices for the sale cars\n");
        printf("5) Exit\n");
        printf("What would you like to do? ");
        scanf("%d",&choice);
        printf("****************************************************\n");

        if(choice==1) /*Creating prices*/
        {
			head=InsertCars(head,n);

        }
        else if(choice==2)/*Display prices*/
        {
            printf("Prices for the cars are as follows:\n");
            printprices(head);

        }
        else if(choice==3)/*Creating sale*/
        {
            ApplySale(head);
        }
        else if(choice==4)/*Displaying prices for sale*/
        {
            printf("Prices for the sale cars are as follows:\n");
            printprices(head);
        }

    }

	free(head);
}
```

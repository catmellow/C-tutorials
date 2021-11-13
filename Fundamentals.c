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

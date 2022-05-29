#include<stdio.h>
#include<stdlib.h>
#include<mem.h>

struct Node
{
    int pen;
    int width;
    int height;
    float x;
    float y;
    float pressure;
    struct Node* next;
};

struct ListRecord
{
    struct Node *head;
    struct Node *tail;
    int size;
};

struct user
{
	char username[10];
	struct user* next;
	struct ListRecord* info;
};

typedef struct ListRecord* List;
typedef struct user* User;

List CreateList(void);
void MakeEmptyList(List);
int ListSize(List);
float HeadOfList(List);
float TailOfList(List);
int IsEmptyList(List);
float average_pressure(List);
int count_signatures(List);
void show_user_statistics(User);
void remove_signature(User);
void Display(User);
struct user* load_data(char*);
struct Node* InsertList(List L, int pen, int width, int height, float x, float y, float pressure);

int main()
{
    User U;
    char filename[20];
    int choice;
	printf("Sign: Analysing Signature Data\n");
	printf("Enter file name: ");
	scanf("%s",&filename);

    U = load_data(filename);
	//Display(U);
	while(choice != 3)
	{
		// menu
		printf("\n\n------------------------------------------------\n");
		printf("Sign Menu\n");
		printf("-----------------------\n");
		printf("1. Remove Signatures\n");
		printf("2. Show User Statistics\n");
		printf("3. Exit from Sign\n");
		printf("------------------------------------------------\n");
		printf("Enter your option: ");
		scanf("%d",&choice);

		if(choice == 1) // Remove Signatures
		{
			remove_signature(U);
		}
		else if(choice == 2) // show_user_statistics
		{
		  	show_user_statistics(U);
		}
		else if(choice == 3) // exit
		{
			printf("\n\n Goodbye !");
		}
		//Display(U);
	}

}


List CreateList()
{
	List l;

	l = (struct ListRecord *) malloc(sizeof(struct ListRecord));
	if (l == NULL)
		printf("Out of memory!\n");
    else
	    MakeEmptyList(l);

	return l;
}


void MakeEmptyList(List l)
{
	l->head = (struct Node *) malloc(sizeof(struct Node));
	if (l->head == NULL)
		printf("Out of memory!\n");

	l->head->next = NULL;
	l->tail = l->head;
	l->size = 0;
}

int IsEmptyList(List l)
{
	return (l->size == 0);
}

int ListSize(List l)
{
	return (l->size);
}

float HeadOfList(List l)
{
	if (!IsEmptyList(l))
		return l->head->next->pressure;
	else
	{
		printf("The linked list is empty\n");
		return -1;
	}
}

float TailOfList(List l)
{
	if (!IsEmptyList(l))
		return l->tail->pressure;
	else
	{
		printf("The linked list is empty\n");
		return -1;
	}
}

void Display(User l)
{
	struct user *p;
	struct Node* node;

	printf("\n\nList content:\n");
    p = l;
	while (p != NULL)
	{
		printf("[%s]\n\n",p->username);
		node = p->info->head->next;
		while(node != NULL)
        {
            printf("%d %d %d %f %f %f \n",node->pen,node->width,node->height,node->x,node->y,node->pressure);
            node = node->next;
        }
		p = p->next;
	}
}



void show_user_statistics(User l) // show_user_statistics
{
	struct user *p;
	struct Node* node;
	char name[20];
	printf("\nEnter a user name:");
	scanf("%s",&name);

    p = l;
	while (strcmpi(name, p->username) != 0) // findinf proper position of user node p that user searchs for
	{
		//printf("[%s]\n\n",p->username);
		p = p->next;  // p->next = the node that we look for
	}

	printf("\nThe number of signatures: %d",count_signatures(p->info));
	printf("\nThe total pen pressure: %f", average_pressure(p->info)*count_signatures(p->info));

}



int count_signatures(List L) // function to count signature nodes inside the user -> info list
{
	struct Node* node;
	int count = 0;

	node = L->head->next;
	while(node != NULL)
    {
        count ++;
        //printf("%d %d %d %f %f %f \n",node->pen,node->width,node->height,node->x,node->y,node->pressure);
        node = node->next;
    }
    return count;

}



float average_pressure(List L) // function to calculate average pressure
{
	struct Node* node;
	float avg = 0;
	int x = count_signatures(L);
	node = L->head->next;
	while(node != NULL)
    {
        //printf("\n!! -> %d %d %d %f %f %f \n",node->pen,node->width,node->height,node->x,node->y,node->pressure);
        //printf("avg -> %d\n",avg);
        avg  = node->pressure + avg;
        node = node->next;
    }
    avg = avg / x;
    return avg;
}


struct Node* InsertList(List L, int pen, int width, int height, float x, float y, float pressure)
{

	struct Node* newnode;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->pressure = pressure;
	newnode->pen = pen;
	newnode->width = width;
	newnode->height = height;
	newnode->x = x;
	newnode->y = y;
    newnode->next = NULL;

        L->tail->next = newnode;
		L->tail = newnode;

	L->size ++;

}




void remove_signature(User l)
{
	struct user *p;
	struct Node* node;
	int countmemory = 0; // this variable tracks/holds number of how many nodes changed/removed in total
	float pressure;
	printf("\nEnter a threshold value: "); // asking the user to enter a thresold/bound value
	scanf("%f",&pressure);
    p = l;
	while (p != NULL)
	{
		node = p->info->head;
		int before = count_signatures(p->info);  // number of nodes before the delete operation

				while(node->next != NULL)
				{
					if(node->next->pressure < pressure)
					{
						// node -> the node before the removal
						struct Node* removal; // the node that we want to remove            node --> removal
						removal = node->next;
						node->next = node->next->next;
						free(removal);
					}
					else
						node = node->next;
				}
		int after = count_signatures(p->info); // number of nodes after the delete operation


		//before - after  = how many nodes removed/changed by using remove operation
		int change = before - after;
		// keep the value in a variable so that we can see how many nodes are changed/removed in total
		countmemory = change + countmemory;

		p = p->next;
	}
	printf("\nThe number of fixations removed: %d",countmemory);
}

float GetPositionOfElement(List L, int pos)
{
    if(pos >= L->size)
    {
        printf("\nError");
    }
    else
    {
        int i;
        struct Node* p;
        p = L->head;
        for(i = 0; i < pos; i++)
        {
            p = p->next;
        }
        return p->pressure;
    }
}

float GetElementAtPosition(List L, int pos )
{
    if(pos > L->size)
    {
        printf("\nError\n");
        exit(-1);
    }
    else
    {
        int i;
        struct Node* p;
        p = L->head;
        for(i = 0; i < pos; i++)
        {
            p = p->next;
        }
        return p->pressure;
    }
}


struct user* load_data(char filename[])
{
    char username[50];
    int pen;
    int width;
    int height;
    float x;
    float y;
    float pressure;


    User head;
    head = NULL;
    char ch;
    int i,j;
    int line = 0;
    FILE *filep;
    filep = fopen(filename,"r");
    if(filep==NULL)
	{
		    printf("Failed to open the file!\n");
            exit(1);
    }
	else
            printf("The signature features is successfully loaded.\n");

    // Find number of lines in the file
	while((ch= fgetc(filep)) !=EOF)
    {
        if(ch=='\n')
        {
            line++;
        }
    }


    // Taking the cursor to the beginning of file
    // rewind(filep);
    fseek(filep,0L,SEEK_SET);

	while(fscanf(filep,"%[^,],%d,%d,%d,%f,%f,%f \n",username,&pen,&width,&height,&x,&y,&pressure)!=EOF)
    {
        User temp;
        User p;
        p = (struct user*)malloc(sizeof(struct user));
        p->next = NULL;
        strcpy(p->username,username);

        p->info = CreateList();  // creating the sign linkedlist for the user node

        if(head == NULL) // if the userlist is NULL or empty
        {
            head = p;
        }
        else
        {

            temp = head;
            while(temp->next != NULL ) // finding the proper position for the user node
            {
                temp = temp->next;
            }
            if( strcmp ( temp->username, p->username) != 0) /* if usernode p has the username with the previous user node, */
            {												/*	then p will not be added the list so that it could not dublicated.*/
                temp->next = p;
            }
            else
            {
                InsertList(temp->info, pen, width, height, x, y, pressure);
            }
        }
        InsertList(p->info, pen, width, height, x, y, pressure);

   	}
    fclose(filep);
    return head;
}

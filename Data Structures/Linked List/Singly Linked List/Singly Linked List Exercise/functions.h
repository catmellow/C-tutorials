#include"Linked.h"

List CreateList(void);
void MakeEmptyList(List);
int ListSize(List);
int HeadOfList(List);
int TailOfList(List);
int IsEmptyList(List);
struct Node *findCode(List,int);
void DisplayList(List);
void InsertList(List,int,int);
void DeleteList(List, int);
void givenpos(List,int);


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

int HeadOfList(List l)
{
	if (!IsEmptyList(l))
		return l->head->next->code;
	else
	{
		printf("The linked list is empty\n");
		return -1;
	}
}

int TailOfList(List l)
{
	if (!IsEmptyList(l))
		return l->tail->code;
	else
	{
		printf("The linked list is empty\n");
		return -1;
	}
}

void DisplayList(List l)
{
	struct Node *p;

	p = l->head->next;
	printf("\n=======\nList content:\n=======\n");

	while (p != NULL)
	{
		printf("%s  %d  %s  %s  %s\n",p->place,p->code, p->country,p->state,p->city);
		p = p->next;
	}
	printf("\n");
}

void InsertList(List L ,int pos,int code)
{
    int i;
    struct Node *insert,*temp;
    insert = (struct Node*)malloc(sizeof(struct Node));
    insert->code = code;
    insert->next = NULL;

    if(pos > (L->size)+1 )
    {
        pos = L->size+1;
    }
    if(pos == (L->size)+1 )
    {
        L->tail->next= insert;
        L->tail = insert;
    }
    else
    {
        temp = L->head;

        for(i = 1; i < pos ; i++ )
        {
            temp = temp->next;
        }

        insert->next = temp->next;
        temp->next = insert;

    }

    L->size++;
}

void DeleteList(List L, int code)
{
    struct Node *dummy;
    dummy = L->head->next;
    if(L->head->next->code == code)
    {
        L->head->next = L->head->next->next;
    }
    else
    {
        while(dummy->next->code != code)
        {
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;
    }

}

struct Node *findCode(List L,int code)
{
    struct Node *dummy;
    dummy = L->head->next;
    while(dummy->code != code)
    {
        dummy = dummy->next;
    }
    return dummy;
}

void givenpos(List L,int pos)
{
    int i;
    struct Node *p;
    p = L->head->next;

    if(pos> L->size)
        pos = L->size;
    else if(pos<L->size)
    {
        for(i = 0; i < pos-1; i++)
        {
            p = p->next;
        }
    }
    else
        pos = 0;

    printf("\n[Information at position %d]\nPlace: %s\nCode: %d\nCountry: %s\nState: %s\nCity: %s\n",pos,p->place,p->code,p->country,p->state,p->city);
}


void Add(List L,char place[], int code, char country[],char state[],char city[])
{
    int count = 1;
    struct Node* p,*t;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("memory couldn't allocated !");
        exit(1);
    }
    newnode->next = NULL;
    strcpy(newnode->place,place);
    newnode->code = code;
    strcpy(newnode->country,country);
    strcpy(newnode->state,state);
    strcpy(newnode->city,city);
    // if the list is empty ^^
    if(L->head->next == NULL)
    {
        L->head->next = newnode;
        L->tail = newnode;

    }
    else
    {
        p = L->head;
        t = L->head->next;

        while(t != NULL)
        {

                if(strcmp(t->place,newnode->place) > 0)
                {

                    newnode->next =  p->next;
                    p->next = newnode;

                    count = 0;
                    break;
                }

            p = p->next;
            t = t->next;
        }

        if(count)
        {
            newnode->next = p->next;
            p->next = newnode;
        }

    }
    L->size++;
}

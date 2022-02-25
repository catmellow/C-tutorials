#include<stdio.h>
#include<stdlib.h>
#include<mem.h>
#include<string.h>


struct Node
{
    char place[40];
    int code;
    char country[40];
    char state[40];
    char city[40];
    struct Node *next;
};

struct ListRecord
{
    struct Node *head;
    struct Node *tail;
    int size;
};
typedef struct ListRecord* List;

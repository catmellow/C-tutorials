#ifndef QUEUE_H
#define QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include "avltree.h"

typedef struct queue *Queue;
struct Node
{
    AVLTree data;
    struct Node *next;
};
struct queue
{
    struct Node *front;
    struct Node *rear;
    int size;
};

Queue CreateQueue();
void MakeEmptyQueue(Queue q);
AVLTree dequeue(Queue q);
void enqueu(Queue q,AVLTree t);

Queue CreateQueue()
{
	Queue q;
	q = (Queue)malloc(sizeof(struct queue));
	if (q == NULL)
    {
        printf("Out of memmory!\n");
    }
    else
    {
        MakeEmptyQueue(q);
    }

    return q;
}

void MakeEmptyQueue(Queue q)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));

	q->front = new_node;
	if (q->front == NULL)
    {
        printf("Out of memory!\n");
    }
    else{
        q->front->next = NULL;
        q->rear = q->front;
        q->size = 0;
    }
}

AVLTree dequeue(Queue q)
{
	if (q->size == 0)
    {

    }
    else
    {
        struct Node *deleted_node;
        deleted_node = q->front;

        AVLTree val = deleted_node->data;

        q->front = deleted_node->next;

        free(deleted_node);
        q->size--;

        if(q->size == 0)
        {
            q->rear = q->front;
        }
        return val;
    }
}

void enqueue(Queue q,AVLTree t)
{
	struct Node* new_node;
	new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = t;
    new_node->next = NULL;
	if(q->size == 0)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }

	q->size++;
}

#endif


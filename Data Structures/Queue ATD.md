# Queue ATD
### What is Queue?
A Queue is a linear structure that follows a particular order in which the operations are performed. The order is First In First Out (FIFO). An excellent example of a queue is any queue of consumers for a resource where the first consumer is served first. The difference between stacks and queues is in removing. In a stack, we remove the item the most recently added; in a queue, we remove the item the least recently added.

#### **Operations on Queue:**

Mainly the following four basic operations are performed on queue:

* **Enqueue**: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition. 
* **Dequeue:** Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition. 
* **Front**: Get the front item from queue. 
* **Rear**: Get the last item from queue. 

*As an example, we can think like a supermarket queue, a person who came early leaves early.*

![](https://i.imgur.com/c4DWRBk.png)

## **Array Implementation**

For implementing Queue, we need to keep track of two indices, front, and rear. We enqueue an item at the rear and dequeue an item from the front. If we simply increment front and rear indices, there may be problems. The front may reach the end of the array. The solution to this problem is to increase the front and rear circularly.

![](https://i.imgur.com/VluM2n1.png)

![](https://i.imgur.com/gEKnrYr.png)



* **Cons of Array Implementation:**

1. Static Data Structure, fixed size.
2. If the queue has a large number of enqueue and dequeue operations, at some point (in case of linear increment of front and rear indexes) we may not be able to insert elements in the queue even if the queue is empty (this problem is avoided by using circular queue).

**Example Code**

```c
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Queue
{
    int front;
    int rear;
    int size; // number of elements
    int *array;
    int capacity; // size of the array
};

// function to create a queue of given capacity
struct Queue *create(int cap)
{
    struct Queue *queue;
    queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->capacity = cap;
    queue->front=queue->size = 0;
    queue->rear = cap-1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
}

// queue is full when size(number of elements) = capacity
int isfull(struct Queue* qp)
{
    return (qp->size == qp->capacity);
}

// Queue is empty when the number of elements in the array = 0
int isempty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Function to add item to the queue from the "front" / "head"
// it changes read and size
void Enqueue(struct Queue *queue, int item)
{
    if(isfull(queue))
        exit(0);
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
// Function  to remove an item from the queue 
// it changes front & size
int Dequeue(struct Queue *queue)
{
    if(isempty)
        return NULL;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Funtion that prints the values inside of the queue
void PrintQueue(struct Queue *queue)
{
    struct Queue *p;
    p = queue;
    int i;
    for ( i = 0; i < p->size; i++)
    {
        printf("\n%d",p->array[i]);
    }
    
}

// Funtion to get rear of the queue
int rear(struct Queue* queue)
{
    if(isempty(queue))
        return NULL;
    return queue->array[queue->rear];
}

// Funtion to get "front" of the queue
int front(struct Queue* queue)
{
    if(isempty(queue))
        return NULL;
    return queue->array[queue->front];
}

int main()
{    

struct Queue *queue;
queue = create(5);
Enqueue(queue,1);
Enqueue(queue,2);
Enqueue(queue,3);
Enqueue(queue,4);
PrintQueue(queue);

}
    
```

**Output**
```
1
2
3
4
```

## Linked List Implementation

In a linked queue, each node of the queue consists of two parts, i.e., the data part and the linked part. Each queue element points to its immediate next element in the memory.

There are two pointers in the linked queue in the memory, i.e., front pointer and rear pointer. The front pointer contains the address of the starting element of the queue, while the rear pointer contains the address of the last element of the queue.

**Time Complexity:** The time complexity of both operations enqueue() and dequeue() is O(1) as we only change a few pointers in both operations. There is no loop in any of the functions.
    
![](https://i.imgur.com/CaT71ZJ.png)

**Example Code**
```c
// A C program to demonstrate linked list based implementation of queue
#include <stdio.h>
#include <stdlib.h>

// A linked list (LL) node to store a queue entry
struct QNode {
	int key;
	struct QNode* next;
};

// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue {
	struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

// The function to add a key k to q
void enQueue(struct Queue* q, int k)
{
	// Create a new LL node
	struct QNode* temp = newNode(k);

	// If queue is empty, then new node is front and rear both
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// Add the new node at the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp;
}

// Function to remove a key from given queue q
void deQueue(struct Queue* q)
{
	// If queue is empty, return NULL.
	if (q->front == NULL)
		return;

	// Store previous front and move front one node ahead
	struct QNode* temp = q->front;

	q->front = q->front->next;

	// If front becomes NULL, then change rear also as NULL
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}

// Driver Program to test anove functions
int main()
{
	struct Queue* q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	deQueue(q);
	deQueue(q);
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	deQueue(q);
	printf("Queue Front : %d \n", q->front->key);
	printf("Queue Rear : %d", q->rear->key);
	return 0;
}
```

**Output**
```
Queue Front : 40
Queue Rear : 50
```



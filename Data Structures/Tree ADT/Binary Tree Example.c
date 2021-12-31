#include<stdio.h>
#include<stdlib.h>

/* A binary tree tNode has data, pointer to left child
and a pointer to right child */
struct tNode
{
    int data;
    struct tNode* left;
    struct tNode* right;
};

/* Structure of a stack node. Linked List implementation is used for
stack. A stack node contains a pointer to tree node and a pointer to
next stack node */
struct sNode
{
    struct tNode *t;
    struct sNode *next;
};

typedef struct tNode *Tree;

/* Stack related functions */
void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
int isEmpty(struct sNode *top);


	/* Function to push an item to sNode*/
void push(struct sNode** top_ref, struct tNode *t)
{
		/* allocate tNode */
		struct sNode* new_tNode = (struct sNode*) malloc(sizeof(struct sNode));

		if(new_tNode == NULL)
		{
			printf("Stack Overflow \n");
			getchar();
			exit(0);
		}

		/* put in the data */
		new_tNode->t = t;

		/* link the old list off the new tNode */
		new_tNode->next = (*top_ref);

		/* move the head to point to the new tNode */
		(*top_ref) = new_tNode;
}

/* The function returns true if stack is empty, otherwise false */
int isEmpty(struct sNode *top)
{
	return (top == NULL)? 1 : 0;
}

/* Function to pop an item from stack*/
struct tNode *pop(struct sNode** top_ref)
{
	struct tNode *res;
	struct sNode *top;

	/*If sNode is empty then error */
	if(isEmpty(*top_ref))
	{
		getchar();
		exit(0);
	}
	else
	{
		top = *top_ref;
		res = top->t;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

Tree RecursiveInsertBinarySearchTree(int x, Tree t)
{
	if (t == NULL)
	{
		/* Create and return a one-node tree */
		t = (Tree) malloc(sizeof(struct tNode));
		
		if (t == NULL)
			printf("Out of space!!!");
		else
		{
			t->data = x;
			t->left = t->right = NULL;
		}
	}	
	else if (x < t->data)
		t->left = RecursiveInsertBinarySearchTree(x, t->left);
	else if (x > t->data)
		t->right = RecursiveInsertBinarySearchTree(x, t->right);
	/* else x is in the tree already. We'll do nothing */
	return t; /* Don't forget this line!! */
}

Tree InsertElement(int x, Tree t)
{
   if (t == NULL)
	{
		/* Create and return a one-node tree */
		t = (Tree) malloc(sizeof(Tree));
			t->data = x;
			t->left = t->right = NULL;

    }
	else if (x < t->data)
	t->left = RecursiveInsertBinarySearchTree(x, t->left);
	else if (x > t->data)
	t->right = RecursiveInsertBinarySearchTree(x, t->right);
	/* else x is in the tree already. We'll do nothing */
	return t; /* Don't forget this line!! */
}


Tree CreateTree()
{
    return NULL;
}

Tree MakeEmptyTree(Tree t)
{
     if (t != NULL)
     {
         MakeEmptyTree(t->left);
         MakeEmptyTree(t->right);
         free(t);
     }
     return NULL;
}

/* Iterative function for inorder tree traversal */
void inOrder(struct tNode *root)
{
	/* set current to root of binary tree */
	struct tNode *current = root;
	struct sNode *s = NULL; /* Initialize stack s */
	

	while (1)
	{
		/* Reach the left most tNode of the current tNode */
		if(current != NULL)
		{
		
		push(&s, current);
		current = current->left;
		}

		
		else
		{
			if (!isEmpty(s))
			{
				current = pop(&s);
				printf("%d ", current->data);
				current = current->right;
			}
			else
				break;
		}
	} 
}

/* Driver program to test above functions*/
int main()
{

	int i,val;
	struct tNode *root;
	root = CreateTree();
	root = MakeEmptyTree(root);
	for (i = 0; i < 6; i++)
	{
		printf("enter value[%d] :",i+1);
		scanf("%d",&val);
		root = InsertElement(val,root);
	}

	inOrder(root);

}

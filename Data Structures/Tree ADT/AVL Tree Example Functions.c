#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct Node *AVLTree;
struct Node
{
	int val;
	AVLTree left;
	AVLTree right;
	int height;
};

AVLTree CreateTree(void);
AVLTree MakeEmptyTree(AVLTree);
AVLTree InsertElement(int, AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
void DisplayTree(AVLTree);
int countNodes(AVLTree);
void DisplayTreeStructure(AVLTree, int);
int AVLTreeHeight(AVLTree);
int Max(int, int);

int main()
{
	AVLTree myTree, pos;
	int exit, val, height;
	char command;
	myTree = CreateTree();

	exit = FALSE;
	while (!exit)
	{
		fflush(stdin);
		printf("\nEnter command \ni)nitialize \nn)ew element \nd)elete element \nl)eave count \nc)ount nodes \nf)ind element \nh)eight of tree \np)rint tree structure \ne)xit: ");
		scanf("%c", &command);
		fflush(stdin);

		switch (command)
		{
		case 'i':
			myTree = MakeEmptyTree(myTree);
			break;
		case 'n':
			printf("enter value: ");
			scanf("%d", &val);
			myTree = InsertElement(val, myTree);
			DisplayTree(myTree);
			break;
		case 'p':
			DisplayTreeStructure(myTree, 0);
			break;
        case 'c':
            printf(" \nCount -> %d\n",countNodes(myTree));
			break;
        case 'h':
			printf(" \nHeight -> %d\n",AVLTreeHeight(myTree));
			break;
		case 'e':
			exit = TRUE;
			break;
		default:
			printf("command not recognized\n");
			break;
		}
	}
	printf("\n\n\n");
	system("PAUSE");
	return 0;
}

AVLTree CreateTree(void)
{
	return NULL;
}

AVLTree MakeEmptyTree(AVLTree t)
{
	if (t != NULL)
	{
		MakeEmptyTree(t->left);
		MakeEmptyTree(t->right);
		free(t);
	}
	return NULL;
}

AVLTree InsertElement(int val, AVLTree t)
{
	if (t == NULL)
	{
		/*Create and return a one-node tree */
		t = malloc(sizeof(struct Node));
		if (t == NULL)
			printf("Out of memory space!!!\n");
		else
		{
			t->val = val; t->height = 0;
			t->left = t->right = NULL;
		}
	}
	else if (val<t->val)
	{
		t->left = InsertElement(val, t->left);

		if (AVLTreeHeight(t->left) - AVLTreeHeight(t->right) == 2)
		if (val < t->left->val)
			t = SingleRotateWithLeft(t);
		else
			t = DoubleRotateWithLeft(t);
	}
	else if (val > t->val)
	{
		t->right = InsertElement(val, t->right);
		if (AVLTreeHeight(t->right) - AVLTreeHeight(t->left) == 2)
		if (val > t->right->val)
			t = SingleRotateWithRight(t);
		else
			t = DoubleRotateWithRight(t);
	}
	/* else val is in the tree already ... do nothing */
	t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;

	return t;
}

void DisplayTree(AVLTree t)
{
	if (t != NULL)
	{
		DisplayTree(t->left);
		printf("%d\n", t->val);
		DisplayTree(t->right);
	}
}

void DisplayTreeStructure(AVLTree t, int depth)
{
	int i;

	if (t != NULL)
	{
		DisplayTreeStructure(t->right, depth + 1);

		for (i = 0; i < depth; i++)
			printf("     ");
		printf("%d\n", t->val);

		DisplayTreeStructure(t->left, depth + 1);
	}
}

int AVLTreeHeight(AVLTree t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}

AVLTree SingleRotateWithLeft(AVLTree k2)
{
    // rotate right
	struct Node* temp = NULL;
	temp = k2->left;
	k2->left = temp->right;
	temp->right = k2;
	k2->height = AVLTreeHeight(k2);
	temp->height = AVLTreeHeight(temp);
	return temp;
}

AVLTree SingleRotateWithRight(AVLTree k1)
{
    // rotate left
	struct Node* temp = NULL;
    temp = k1->right;
    k1->right = temp->left;
    temp->left = k1;
    k1->height = AVLTreeHeight(k1);
    temp->height=AVLTreeHeight(temp);
    return temp;

}

AVLTree DoubleRotateWithLeft(AVLTree k3)
{
	// left right rotation
    // Rotate between k1 and k2
    k3->left = SingleRotateWithRight(k3->left);

    // Rotate between K3 and k2
    return SingleRotateWithLeft(k3);
}

AVLTree DoubleRotateWithRight(AVLTree k3)
{
	// right left rotation
    // rotate between K3 and k2
    k3->right = SingleRotateWithLeft(k3->right);

    // rotate between k1 and k2
    return SingleRotateWithRight(k3);
}

int Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}

int countNodes(AVLTree t)
{
	if (t==NULL)
	      return 0;
	else return ( countNodes(t->left) + countNodes(t->right) + 1);
}


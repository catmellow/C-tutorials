#ifndef AVLTREE_H
#define AVLTREE_H
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree *AVLTree;
struct Tree
{
  char Song_Name[30];
	char Song_Genre[20];
	char Album_Name[30];
	char Artist_Name[30];
	int Year;
	char Date[30];
	char time[30];
    struct Tree *next;
    struct Tree *left;
    struct Tree *right;
    int height;
};

AVLTree CreateTree();
AVLTree MakeEmptyTree(AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
int AVLTreeHeight(AVLTree);
int Max(int, int);

AVLTree CreateTree()
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


int AVLTreeHeight(AVLTree t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}

AVLTree SingleRotateWithLeft(AVLTree k2)
{
    AVLTree tempTree;
    tempTree = k2->left;
    k2->left = tempTree->right;
    tempTree->right = k2;

    k2->height = Max(AVLTreeHeight(k2->left),AVLTreeHeight(k2->right)) + 1;
    tempTree->height = Max(AVLTreeHeight(tempTree->left),AVLTreeHeight(tempTree->right))+ 1;

    return tempTree;
}

AVLTree SingleRotateWithRight(AVLTree k1)
{
    AVLTree tempTree;

    tempTree = k1->right;
    k1->right = tempTree->left;
    tempTree->left = k1;

    k1->height = Max(AVLTreeHeight(k1->left),AVLTreeHeight(k1->right)) + 1;
    tempTree->height = Max(AVLTreeHeight(tempTree->left),AVLTreeHeight(tempTree->right))+ 1;

    return tempTree;
}

AVLTree DoubleRotateWithLeft(AVLTree k3)
{
    k3->left = SingleRotateWithRight(k3->left);
    return SingleRotateWithLeft(k3);
}

AVLTree DoubleRotateWithRight(AVLTree k3)
{
    k3->right = SingleRotateWithLeft(k3->right);
    return SingleRotateWithRight(k3);
}

int Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}


#endif


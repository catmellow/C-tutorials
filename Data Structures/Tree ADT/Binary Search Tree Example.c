#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 16
#define FALSE 0
#define TRUE 1

/*A tree Node declaration*/
struct Node
{
  int val;
  struct Node* left;
  struct Node* right;
};

typedef struct Node *Tree;

/*Function signatures*/

Tree CreateTree(void);
Tree MakeEmptyTree(Tree);
Tree RecursiveInsertBinarySearchTree(int,Tree);
Tree InsertElement(int, Tree);
void DisplayTree(Tree);


int main()
{
    Tree myTree, pos;
    int exit, val, height;
    char command;
        
        
        myTree = CreateTree();        
        exit = FALSE;

        while (!exit)
        {
               fflush(stdin);
               printf("\n****************************	Menu	********************************");
               printf("\n i)nitialize\n n)ew element \n e)xit\nEnter command: ");
               scanf("%c", &command);  
               fflush(stdin);
               
                  switch(command) 
                  {       
                         case 'i':
                                myTree = MakeEmptyTree(myTree);
                                break;
                         case 'n':
                                printf("enter value: ");
                                scanf("	%d", &val);
								printf("\n");  
                                myTree = InsertElement(val, myTree);
                                DisplayTree(myTree);
                                break;                                    
                         case 'e':
                                exit = TRUE;
                                break;       
                         default:
                                 printf("command not recognized\n");
                                 break;
                  }
                
                  
                  
        }
        
    printf("\n\n");              
    system("PAUSE");	
    return 0;
}

/*Function that mainly creates a tree which is initially NULL*/
Tree CreateTree(void)
{
    return NULL;
}

/*Function that takes a tree and makes it an empty tree by removing all the nodes from that tree*/
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

Tree RecursiveInsertBinarySearchTree(int x, Tree t)
{
	if (t == NULL)
	{
		/* Create and return a one-node tree */
		t = (Tree) malloc(sizeof(struct Node));
		
		if (t == NULL)
			printf("Out of space!!!");
		else
		{
			t->val = x;
			t->left = t->right = NULL;
		}
	}	
	else if (x < t->val)
		t->left = RecursiveInsertBinarySearchTree(x, t->left);
	else if (x > t->val)
		t->right = RecursiveInsertBinarySearchTree(x, t->right);
	/* else x is in the tree already. We'll do nothing */
	return t; /* Don't forget this line!! */
}


/*This function takes an integer value and a tree,
  and inserts that value to the tree*/
Tree InsertElement(int x, Tree t)
{
   if (t == NULL)
	{
		/* Create and return a one-node tree */
		t = (Tree) malloc(sizeof(Tree));
			t->val = x;
			t->left = t->right = NULL;
 
    }
	else if (x < t->val)
	t->left = RecursiveInsertBinarySearchTree(x, t->left);
	else if (x > t->val)
	t->right = RecursiveInsertBinarySearchTree(x, t->right);
	/* else x is in the tree already. We'll do nothing */
	return t; /* Don't forget this line!! */
}

/*This function takes a tree and displays its content on the screen*/
void DisplayTree(Tree t)
{
   if (t !=NULL) 
   {
		DisplayTree(t->left);
		printf("%d\n", t->val);
		DisplayTree(t->right);
   }
}

/* �2021 verdosa. all rights reserved. */

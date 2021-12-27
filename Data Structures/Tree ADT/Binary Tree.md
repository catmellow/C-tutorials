# Binary Tree

A binary tree is a structure comprising nodes, where each node has the following three components:

* **Data element:** Stores any data in the node
* **Left pointer:** Points to the tree on the left side of the node
* **Right pointer:** Points to the tree on the right side of the node

As the name suggests, the data element stores any data in the node.

The left and right pointers point to binary trees on the left and right sides of the node, respectively.

If a tree is empty, it is represented by a null pointe

![](https://i.imgur.com/zBjm3Ya.png)

```c
    struct node
    {
         int data;    //Data element
         struct node * left;    //Pointer to left node
         struct node * right;    //Pointer to right node
    };
```

**Creating nodes**

Simple node

```c
    struct node root;
```
**Pointer to a node**
```
    struct node * root;
    root=(node * )malloc(sizeof(node));
```
In this case, you must explicitly allocate the memory of the node type to the pointer (preferred method).

**Utility function returning node**

```c
    struct node * newnode(int element)
    {
        struct node * temp=(node * )malloc(sizeof(node));
        temp->data=element;
        temp->left=temp->right=NULL;
        return temp;
    }
```

**Maximum depth/height of a tree**

The idea is to do a post-order traversal and maintain two variables to store the left depth and right depth and return max of both the depths.

```c
    int maxDepth(struct node* node) 
    {
        if (node==NULL) 
            return 0;
        else
        {
             /* compute the depth of each subtree */
              int lDepth = maxDepth(node->left);
              int rDepth = maxDepth(node->right);

              /* use the larger one */
              if (lDepth > rDepth) 
                    return(lDepth+1);
              else 
                   return(rDepth+1);
       }
    }
```
Time complexity: **O(*n*)** 

**Application of trees**

1. a Manipulate hierarchical data
2. Make information easy to search (see tree traversal)
3. Manipulate sorted lists of data
4. Use as a workflow for compositing digital images for visual effects
5. Use in router algorithms

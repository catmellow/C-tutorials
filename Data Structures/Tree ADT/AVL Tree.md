# AVL Tree

AVL Tree is invented by GM Adelson - Velsky and EM Landis in 1962. The tree is named AVL in honor of its inventors.

AVL Tree can be defined as a height-balanced binary search tree in which each node is associated with a balance factor calculated by subtracting the height of its right sub-tree from that of its left sub-tree.

The tree is said to be balanced if the balance factor of each node is between -1 to 1. Otherwise, the tree will be unbalanced and need to be balanced.

> Height difference between nodes can be maximum is 1 or -1.

![](https://i.imgur.com/oGnGNAz.png)



**Balance Factor (k) = height (left(k)) - height (right(k))**


* An AVL tree is given in the following figure. We can see that the balance factor associated with each node is between -1 and +1.

* If the balance factor of any node is 0, the left sub-tree and right sub-tree contain equal height.

* If the balance factor of any node is -1, the left sub-tree is one level lower than the right sub-tree.

#### **Why AVL Trees ?**

Most of the BST operations (e.g., search, max, min, insert, delete.. etc.) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that the tree's height remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound of O(Logn) for all these operations. The height of an AVL tree is always O(Logn), where n is the number of nodes in the tree.

## **Operations on AVL tree**



| Operation | Description | 
| -------- | -------- | 
| Insertion     | Insertion in the AVL tree is performed in the same way as in a binary search tree. However, it may lead to the violation in the AVL tree property, and therefore the tree may need balancing. The tree can be offset by applying rotations.     | 
| Deletion | Deletion can also be performed in the same way as portrayed in a binary search tree. Deletion may also disturb the balance of the tree; therefore, various types of rotations are used to rebalance the tree.     |

## **AVL Rotations**

We perform rotation in AVL tree only in case if **Balance Factor** is other than -1, 0, and 1. There are basically four types of rotations which are as follows:

1. L L rotation: Inserted node is in the left subtree of left subtree of A
1. R R rotation : Inserted node is in the right subtree of right subtree of A
1. L R rotation : Inserted node is in the right subtree of left subtree of A
1. R L rotation : Inserted node is in the left subtree of right subtree of A
1. Where node A is the node whose balance Factor is other than -1, 0, 1.

The first two rotations LL and RR are single rotations and the next two rotations LR and RL are double rotations. For a tree to be unbalanced, minimum height must be at least 2, Let us understand each rotation

### **1. RR Rotation**

If the node is inserted into the right of the right sub-tree of node A and the tree becomes unbalanced, then RR rotation will be performed as shown in the following diagram.

While the rotation, node B becomes the root node of the tree. The critical node A will be moved to its left and becomes the left child of B.



![](https://i.imgur.com/DdgTx78.png)


When BST becomes unbalanced, due to a node is inserted into the right subtree of the right subtree of A, then we perform RR rotation, RR rotation is an anticlockwise rotation, which is applied on the edge below a node having balance factor -2

![](https://i.imgur.com/OaeP9G2.jpg)


**Example**

Insert 90 into the AVL Tree shown in the figure.

![](https://i.imgur.com/e1osX7s.png)

**Solution :**

*90 is inserted into the right of the right sub-tree. In this case, critical node A will be 85, the closest ancestor to the new node, whose balance factor is disturbed. Therefore, we need to rebalance the tree by applying RR rotation.*

*Node B will be node 90, which will become the root node of this sub-tree. The critical node 85 will become its left child to produce the rebalanced tree, which is now an AVL tree.*

![](https://i.imgur.com/aqnViUs.png)


### **2. LL Rotation**


The tree shown in the following figure is an AVL Tree. However, we need to insert an element into the left of the left sub-tree of A. The tree can become unbalanced with the critical node A.

The node whose balance factor doesn't lie between -1 and 1 is called a critical node.

Node B becomes the root, with A and T3 as its left and right child. T1 and T2 become the left and right sub-trees of A.

![](https://i.imgur.com/fvkrUgN.png)



When BST becomes unbalanced, a node is inserted into the left subtree of C. We perform LL rotation; LL rotation is clockwise rotation, which is applied on edge below a node having balance factor 2.


![](https://i.imgur.com/UiuarTl.jpg)



### **3. LR Rotation**


Double rotations are a bit tougher than single rotation, which has already been explained above. **LR rotation = RR rotation + LL rotation**, i.e., first RR rotation is performed on subtree, and then LL rotation is performed on the entire tree. By the complete tree, we mean the first node from the path of the inserted node whose balance factor is -1, 0, or 1.

LR rotation is to be performed if the new node is inserted into the right of the left sub-tree of node A.

In LR rotation, node C (as shown in the figure) becomes the tree's root node, while nodes B and A become its left and right child, respectively.

T1 and T2 become the left and right sub-tree of Node B, respectively whereas, T3 and T4 become the left and right sub-tree of Node A.

![](https://i.imgur.com/0LKKoqV.png)



| Scheme | Action | 
| -------- | -------- | 
| ![](https://i.imgur.com/zmDMfa9.jpg)| A node B has been inserted into the right subtree of A the left subtree of C, because of which C has become an unbalanced node having balance factor 2. This case is L R rotation where: Inserted node is in the right subtree of left subtree of C | 
| ![](https://i.imgur.com/z2SYjy8.jpg)| As **LR rotation = RR + LL rotation**, hence RR (anticlockwise) on subtree rooted at A is performed first. By doing RR rotation, node A, has become the left subtree of B.  | 
| ![](https://i.imgur.com/7x0VaSF.jpg)| After performing RR rotation, node C is still unbalanced, i.e., having balance factor 2, as inserted node A is in the left of left of C  | 
| ![](https://i.imgur.com/AVvPmv8.jpg)| Now we perform LL clockwise rotation on full tree, i.e. on node C. node C has now become the right subtree of node B, A is left subtree of B     | 
| ![](https://i.imgur.com/95g2xn2.jpg)| **Balance factor** of each node is now either -1, 0, or 1, i.e. BST is balanced now.     | 

**Example**

Insert the node with value 70 into the tree shown in the following data structure.

![](https://i.imgur.com/FTyuEub.png)


**Solution**

*According to the property of the binary search tree, the node with value 70 is inserted into the right of the left sub-tree of the tree's root.*

*As shown in the figure, the balance factor of the root node is disturbed upon inserting 70, and this becomes critical node A.*

*To rebalance the tree, LR rotation is to be performed. Node C, i.e., 75, will become the new root node of the tree with B and A as its left and right child, respectively.*

*Sub-trees T1, T2 become the left and right sub-tree of B, while sub-trees T3, T4 become the left and right sub-tree of A.*

![](https://i.imgur.com/Lok7mLb.png)


### **4. RL Rotation**

RL rotations are to be performed if the new node is inserted into the left of the right sub-tree of the critical node A. Let us consider. Node B is the root of the right sub-tree of the critical node. Node C is the sub-tree's root in which the new node is inserted.

Let T1 be the left sub-tree of the critical node A, T2 and T3 be the left and right sub-tree of Node C, respectively, sub-tree T4 be the right sub-tree of Node B.

Since RL rotation is the mirror image of LR rotation, in this rotation, node C becomes the root node of the tree with A and B as its left and right children, respectively. Sub-trees T1 and T2 become the left and right sub-trees, whereas T3 and T4 become B's left and right sub-trees.

![](https://i.imgur.com/ZrwteGR.png)


**Example**
Insert node with the value 92 into the tree shown in the following figure.

![](https://i.imgur.com/fogVOZc.png)

**Solution**

![](https://i.imgur.com/u4GFWcv.png)



| Scheme | Definition | 
| -------- | -------- | 
| ![](https://i.imgur.com/tUpqYwN.jpg)| A node B has been inserted into the left subtree of C the right subtree of A. Because of which A has become an unbalanced node having a balance factor - 2. This case is RL rotation where: Inserted node is in the left subtree of right subtree of A     |
| ![](https://i.imgur.com/wxkvvxN.jpg)| As **RL rotation = LL rotation + RR rotation**, LL (clockwise) on subtree rooted at C is performed first. By doing RR rotation, node C has become the right subtree of B.     |
| ![](https://i.imgur.com/RB4WQkc.jpg)| After performing LL rotation, node A is still unbalanced, i.e., having balance factor -2, because of the right-subtree of the right-subtree node A.     |
| ![](https://i.imgur.com/7fUWjju.jpg)| Now we perform RR rotation (anticlockwise rotation) on the whole tree, i.e., on node A. node C has now become the right subtree of node B, and node A has become the left subtree of B.     |
| ![](https://i.imgur.com/RHck7vS.jpg)| The **balance factor** of each node is now either -1, 0, or 1, i.e., BST is balanced now.     |

#### **Q: Construct an AVL tree having the following elements**

`H, I, J, B, A, E, C, F, D, G, K, L`

### **1. Insert H, I, J**

![](https://i.imgur.com/UBXX89H.png)

**The resultant balance tree is:**


![](https://i.imgur.com/SO0nwsl.png)


### **2. Insert B, A**

![](https://i.imgur.com/dkJmhGZ.png)

**The resultant balance tree is:**

![](https://i.imgur.com/HDpGYAP.png)

### **3. Insert E**

![](https://i.imgur.com/eY8XH9C.png)


* **3 *a)*** We first perform RR rotation on node B
    ![](https://i.imgur.com/2yfKXqv.png)
    

* **3 *b)*** We first perform LL rotation on the node I
    ![](https://i.imgur.com/qW3nt0P.png)


### **4. Insert C, F, D**

![](https://i.imgur.com/l6e0SuU.png)

* **4 *a)*** We first perform LL rotation on node E
    ![](https://i.imgur.com/mreiflQ.png)

* **4 *b)*** We then perform RR rotation on node B
    ![](https://i.imgur.com/nAly3y5.png)

### **5. Insert G**

![](https://i.imgur.com/jLg5GyA.png)

* **5 *a)*** We first perform RR rotation on node C
 
![](https://i.imgur.com/JcqhKzs.png)

* **5 *b)***  We then perform LL rotation on node H
![](https://i.imgur.com/79FmXH3.png)


### **6. Insert K**

![](https://i.imgur.com/LGQcYWm.png)

**The resultant balanced tree after RR rotation is:**

![](https://i.imgur.com/ODk2ZeP.png)


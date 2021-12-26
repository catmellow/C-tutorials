# Graph Representation

Graphs are mathematical structures that represent pairwise relationships between objects. A graph is a flow structure that describes the relationship between various objects. It can be visualized by using the following two basic components.
1. **Nodes:** These are essential components in any graph. Nodes are entities whose relationships are expressed using edges. If a graph comprises two nodes, A and B, and an undirected edge between them, it represents a bi-directional relationship between the nodes and edge.
2. **Edges:** Edges are the components used to represent the relationships between various nodes in a graph. An edge between two nodes expresses a one-way or two-way relationship between the nodes.

**Types of nodes**

* **Root node:** The root node is the ancestor of all other nodes in a graph. It does not have any ancestors. Each graph consists of precisely one root node. Generally, you must start traversing a graph from the root node.

* **Leaf nodes:** In a graph, leaf nodes represent the nodes that do not have any successors. These nodes only have ancestor nodes. They can have any incoming edges, but they will not have any outgoing edges.

**Types of graphs**

* **Undirected:** An undirected graph in which all the edges are bi-directional, i.e., the edges do not point in any specific direction.

![](https://i.imgur.com/HqPDnTX.jpg)


* **Directed:** A directed graph where all the edges are uni-directional, i.e., the edges point in a single direction.

![](https://i.imgur.com/9z94wX0.jpg)

* **Weighted:** Each edge is assigned a weight or cost in a weighted graph. Consider a graph of 4 nodes as in the diagram below. As you can see, each edge has a weight/cost assigned to it. If you want to go from vertex 1 to vertex 3, you can take one of the following three paths:
1 -> 2 -> 3
1 -> 3
1 -> 4 -> 3
Therefore the total cost of each path will be as follows: - The total cost of 1 -> 2 -> 3 will be (1 + 2) i.e. 3 units - The total cost of 1 -> 3 will be 1 unit - The total cost of 1 -> 4 -> 3 will be (3 + 2) i.e. 5 units

![](https://i.imgur.com/nhADd2s.jpg)



* **Cyclic:** A graph is cyclic if the graph comprises a path that starts from a vertex and ends at the same vertex. That path is called a cycle. An acyclic graph is a graph that has no cycle.
A **tree** is an undirected graph in which any two vertices are connected by only one path. A tree is an acyclic graph with N - 1 edge, where N is the number of vertices. Each node in a graph may have one or multiple parent nodes. However, each node (except the root node) comprises precisely one parent node in a tree.
**Note:** A root node has no parent.
A tree cannot contain any cycles or self-loops. However, the same does not apply to graphs.

![](https://i.imgur.com/1zNABDh.jpg)


### **Graph representation**

There are many ways to represent graphs, but the most commons ones are ;

* **Adjacency matrix**
* **Adjacency list**

#### **Adjacency matrix**

An adjacency matrix is a VxV binary matrix A. Element Ai,j is 1 if there is an edge from vertex i to vertex j else Ai,j is 0.

> **Note:** A binary matrix is a matrix in which the cells can have only one of two possible values - either a 0 or 1.

The adjacency matrix can also be modified for the weighted graph in which instead of storing 0 or 1 in Ai,j, the weight or cost of the edge will be held.

In an undirected graph, if Ai,j = 1, then Aj,i = 1. In a directed graph, if Ai,j = 1, then Aj,i may or may not be 1.

The adjacency matrix provides constant-time access (O(1) ) to determine an edge between two nodes. The space complexity of the adjacency matrix is O(V2).

The adjacency matrix of the following graph is:
i/j : 1 2 3 4
1 : 0 1 0 1
2 : 1 0 1 0
3 : 0 1 0 1
4 : 1 0 1 0

![](https://i.imgur.com/MVYID1t.jpg)


The adjacency matrix of the following graph is:

i/j: 1 2 3 4
1 : 0 1 0 0
2 : 0 0 0 1
3 : 1 0 0 1
4 : 0 1 0 0

![](https://i.imgur.com/pni8FUO.jpg)


#### **Adjacency list**

The other way to represent a graph is by using an adjacency list. An adjacency list is an array A of separate lists. Each element of the array Ai is a list containing all the vertices adjacent to vertex i. 

The space complexity of the adjacency list is O(V + E) because, in an adjacency list, information is stored only for those edges that exist in the graph.

> **Note:** A sparse matrix is a matrix in which most elements are zero, whereas a dense matrix is a matrix in which most elements are non-zero.

![](https://i.imgur.com/Gspo9sn.jpg)

Consider the same undirected graph from an adjacency matrix. The adjacency list of the graph is as follows:

A1 → 2 → 4
A2 → 1 → 3
A3 → 2 → 4
A4 → 1 → 3

![](https://i.imgur.com/b2JJmqy.jpg)

Consider the same directed graph from an adjacency matrix. The adjacency list of the graph is as follows:

A1 → 2
A2 → 4
A3 → 1 → 4
A4 → 2

### **Graph Terminology**



| Term | Definition | 
| -------- | -------- | 
| Path     | the sequence of nodes that are followed in order to reach some terminal node V from the initial node U.| 
| Closed Path     | A path will be called as closed path if the initial node is same as terminal node. A path will be closed path if V0=VN     | 
| Simple Path     | If all the nodes of the graph are distinct with an exception V0=VN, then such path P is called as closed simple path.     | 
| Cycle     | The path which has no repeated edges or vertices except the first and last vertices.     | 
| Connected Graph     | A connected graph is the one in which some path exists between every two vertices (u, v) in V. There are no isolated nodes in connected graph.     | 
| Complete Graph     | A complete graph is the one in which every node is connected with all other nodes. A complete graph contain n(n-1)/2 edges.     | 
| Weighted Graph     | In a weighted graph, each edge is assigned with some data such as length or weight. The weight of an edge e can be given as w(e) which must be a positive (+) value indicating the cost of traversing the edge.     | 
| Digraph     | A digraph is a directed graph in which each edge of the graph is associated with some direction and the traversing can be done only in the specified direction.     | 
| Loop     | An edge that is associated with the similar end points can be called as Loop.     | 
| Adjacent Nodes     | If two nodes u and v are connected via an edge e, then the nodes u and v are called as neighbours or adjacent nodes.     | 
| Degree of the Node     | A degree of a node is the number of edges that are connected with that node. A node with degree 0 is called as isolated node.     | 



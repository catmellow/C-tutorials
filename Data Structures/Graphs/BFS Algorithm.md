# Graph Traversal Algorithms

Graph traversal means visiting every vertex and edge exactly once in a well-defined order. While using specific graph algorithms, you must ensure that each vertex is visited exactly once. The order in which visiting the vertices is essential and may depend upon the algorithm or question you are solving.

There are 2 types Traversal Algorithms in common.

*  **Breadth First Search**
*  **Depth First Search**

## Breadth First Search (BFS)

There are many ways to traverse graphs. BFS is the most commonly used approach.BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise, thus exploring the neighbor nodes (nodes directly connected to the source node). It would help if you then moved towards the next-level neighbor nodes. As the name BFS suggests, you are required to traverse the graph breadthwise as follows in order:
1. Move horizontally and visit all the nodes of the current layer
1. Move to the next layer

![](https://i.imgur.com/ncuS9YP.jpg)


Consider the diagram above. The distance between the nodes in layer 1 is comparatively lesser than the distance between the nodes in layer 2. Therefore, in BFS, you must traverse all the nodes in layer 1 before moving to the nodes in layer 2.



**Traversing child nodes**

A graph can contain cycles, which may bring you to the same node again while traversing the graph. To avoid processing the same node again, use a boolean array that marks the node after it is processed. While visiting the nodes in the layer of a graph, store them so that you can traverse the corresponding child nodes in a similar order.

In the diagram above, start traversing from 0 and visit its child nodes 1, 2, and 3. Store them in the order in which they are seen. This will allow you to visit the child nodes of 1 first (i.e., 4 and 5), then of 2 (i.e., 6 and 7), and then of 3 (i.e., 7), etc.

To make this process easy, use a queue to store the node and mark it as 'visited' until all its neighbors (vertices that are directly connected to it) are marked. The queue follows the First In First Out (FIFO) queuing method, and therefore, the neighbors of the node will be visited in the order in which they were inserted in the node, i.e., the node that was inserted first will be visited first, and so on.

**Pseudocode**

```c
BFS (G, s)              //Where G is the graph and s is the source node
      let Q be queue.
      Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

      mark s as visited.
      while ( Q is not empty)
           //Removing that vertex from queue,whose neighbour will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of v  
          for all neighbours w of v in Graph G
               if w is not visited 
                        Q.enqueue( w )             //Stores w in Q to further visit its neighbour
                        mark w as visited.
```


**Traversing Progress**

![](https://i.imgur.com/pu8UzT2.jpg)

The traversing will start from the source node and push s in the queue. S will be marked as 'visited.'

*First iteration*
* s will be popped from the queue
* Neighbors of s, i.e., 1 and 2 will be traversed
* 1 and 2, which have not been crossed earlier, are traversed. They will be:
* Pushed in the queue
* 1 and 2 will be marked as visited

*Second iteration*
* 1 is popped from the queue
* Neighbors of 1, i.e., s and 3 are traversed
* s is ignored because it is marked as 'visited.'
* 3, which has not been crossed earlier, is traversed. It is:
* Pushed in the queue
* Marked as visited

*Third iteration*
* 2 is popped from the queue
* Neighbors of 2, i.e., s, 3, and 4 are traversed
* 3 and s are ignored because they are marked as 'visited.'
* 4, which has not been traversed earlier, is traversed. It is:
* Pushed in the queue
* Marked as visited

*Fourth iteration*
* 3 is popped from the queue
* Neighbors of 3 i.e., 1, 2, and 5 are traversed
* 1 and 2 are ignored because they are marked as 'visited.'
* 5, which has not been traversed earlier, is traversed. It is:
* Pushed in the queue
* Marked as visited

*Fifth iteration*
* 4 will be popped from the queue
* Neighbors of 4, i.e., 2 are traversed
* 2 is ignored because it is already marked as 'visited.'

*Sixth iteration*
* 5 is popped from the queue
* Neighbors of 5, i.e., 3 are traversed
* 3 is ignored because it is already marked as 'visited.'


**Complexity**

The time complexity of BFS is O(V + E), where V is the number of nodes and E is the number of edges.

**Applications**

1. **How to determine the level of each node in the given tree?**

```c
vector <int> v[10] ;   //Vector for maintaining adjacency list explained above
    int level[10]; //To determine the level of each node
    bool vis[10]; //Mark the node if visited 
    void bfs(int s) {
        queue <int> q;
        q.push(s);
        level[ s ] = 0 ;  //Setting the level of the source node as 0
        vis[ s ] = true;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(int i = 0;i < v[ p ].size() ; i++)
            {
                if(vis[ v[ p ][ i ] ] == false)
                {
            //Setting the level of each node with an increment in the level of parent node
                    level[ v[ p ][ i ] ] = level[ p ]+1;                 
                     q.push(v[ p ][ i ]);
                     vis[ v[ p ][ i ] ] = true;
      }
            }
        }
    }
```
![](https://i.imgur.com/Ou5B3cg.jpg)

```
            node                         level [node]   

              s (source node)              0  
              1                            1  
              2                            1  
              3                            2  
              4                            2  
              5                            2  
              6                            2  
              7                            3
```

2. **0-1 BFS**

This type of BFS is used to find the shortest distance between two nodes in a graph, provided that the edges in the chart have the weights 0 or 1. Applying the BFS explained earlier in this article will get an incorrect result for the optimal distance between 2 nodes.

In this approach, a boolean array is not used to mark the node because the condition of the optimal distance will be checked when you visit each node. A double-ended queue is used to store the node. In 0-1 BFS, if the weight of the edge = 0, then the node is pushed to the front of the dequeue. If the weight of the edge = 1, then the node is pushed to the back of the dequeue.

```c=
void bfs (int start)
{
            deque <int > Q;     //Double-ended queue
            Q.push_back( start); 
            distance[ start ] = 0;       
            while( !Q.empty ())
            {
                int v = Q.front( );
                Q.pop_front(); 
                for( int i = 0 ; i < edges[v].size(); i++)
               {


/* if distance of neighbour of v from start node is greater than sum of distance of v from start node and edge weight between v and its neighbour (distance between v and its neighbour of v) ,then change it */  


                    if(distance[ edges[ v ][ i ].first ] > distance[ v ] + edges[ v ][ i ].second ) 
                {

                    distance[ edges[ v ][ i ].first ] = distance[ v ] + edges[ v ][ i ].second;

                /*if edge weight between v and its neighbour is 0 then push it to front of
        double ended queue else push it to back*/

                    if(edges[ v ][ i ].second == 0)
                    {
                        Q.push_front( edges[ v ][ i ].first);
                    }
                    else
                    {
                            Q.push_back( edges[ v ][ i ].first);

                    }
                }
              }
           }
    }
```

![](https://i.imgur.com/VXv9w8d.jpg)

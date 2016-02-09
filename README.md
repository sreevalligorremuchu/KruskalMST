# KruskalMST
Kruskal's solution to find a minimum spanning tree using disjoint sets and adjacency lists as input and output. 
The disjoint set and adjacency list are also implemented.

This code is compiled and tested in XCode. Might need minor modifications for other compilers.

The solution contains:

In main.cpp : <br> 
      Create and AdjacencyList for input <br>
      Print the input<br>
      Convert it into a Disjoint Set<br>
      Create an MST object with Input AdjacencyList and DisjointSet<br>
      Build MST<br>
      Print the output graph<br>
  <br><br>
  Classes include<br>
    DisjointSet - to implement FindSet and MakeUnion<br>
    node - Base datastructure for both AdjacencyList, Disjoint Set and Edge<br>
    AdjacencyList - Graph representation for both input and output<br>
    MST - Kruskal's algorithm<br>
    Edge - To sort based on the weight of the edge<br>
      


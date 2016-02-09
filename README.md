# KruskalMST
Kruskal's solution to find a minimum spanning tree using disjoint sets and adjacency lists as input and output. 
The disjoint set and adjacency list are also implemented.

This code is compiled and tested in XCode. Might need minor modifications for other compilers.

The solution contains:

In main.cpp : 
      Create and AdjacencyList for input
      Print the input
      Convert it into a Disjoint Set
      Create an MST object with Input AdjacencyList and DisjointSet
      Build MST
      Print the output graph
  
  Classes include
    DisjointSet - to implement FindSet and MakeUnion
    node - Base datastructure for both AdjacencyList, Disjoint Set and Edge
    AdjacencyList - Graph representation for both input and output
    MST - Kruskal's algorithm
    Edge - To sort based on the weight of the edge
      


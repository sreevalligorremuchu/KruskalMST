#ifndef MST_H
#include "MST.h"
#define MST_H
#endif

#ifndef ADJACENCYLIST_H
#include "AdjacencyList.h"
#define ADJACENCYLIST_H
#endif

#ifndef DISJOINTSET_H
#include "DisjointSet.h"
#define DISJOINTSET_H
#endif

AdjacencyList& buildAdjacencyList() {

	AdjacencyList* adjList = new AdjacencyList();
	adjList->addEdge(new node(0, NULL, NULL, "a"), new node(4, NULL, NULL, "b"));
	adjList->addEdge(new node(0, NULL, NULL, "a"), new node(8, NULL, NULL, "h"));
	adjList->addEdge(new node(0, NULL, NULL, "b"), new node(11, NULL, NULL, "h"));
	adjList->addEdge(new node(0, NULL, NULL, "b"), new node(8, NULL, NULL, "c"));
	adjList->addEdge(new node(0, NULL, NULL, "h"), new node(7, NULL, NULL, "i"));
	adjList->addEdge(new node(0, NULL, NULL, "h"), new node(1, NULL, NULL, "g"));
	adjList->addEdge(new node(0, NULL, NULL, "i"), new node(2, NULL, NULL, "c"));
	adjList->addEdge(new node(0, NULL, NULL, "i"), new node(6, NULL, NULL, "g"));
	adjList->addEdge(new node(0, NULL, NULL, "c"), new node(7, NULL, NULL, "d"));
	adjList->addEdge(new node(0, NULL, NULL, "c"), new node(4, NULL, NULL, "f"));
	adjList->addEdge(new node(0, NULL, NULL, "g"), new node(2, NULL, NULL, "f"));
	adjList->addEdge(new node(0, NULL, NULL, "d"), new node(9, NULL, NULL, "e"));
	adjList->addEdge(new node(0, NULL, NULL, "d"), new node(14, NULL, NULL, "f"));
	adjList->addEdge(new node(0, NULL, NULL, "f"), new node(10, NULL, NULL, "e"));
	return *adjList;
}

int main() {

	// Input
	AdjacencyList& adjInput = buildAdjacencyList();
	adjInput.printGraph();

	DisjointSet& djSet = *(new DisjointSet(adjInput));

	// Output
	MST& mst = *(new MST(djSet, adjInput));
	AdjacencyList& adjOutput = mst.buildMST();
	adjOutput.printGraph();


	for (int i=0; i<adjInput.size(); i++) {
		node* temp = adjInput[i];
		while (temp != NULL) {
			node* temp2 = temp;
			temp = temp->next();
			delete temp2;
		}
	}
	return 0;
}

#ifndef DISJOINTSET_H
#include "DisjointSet.h"
#define DISJOINTSET_H
#endif

#ifndef ADJACENCYLIST_H
#include "AdjacencyList.h"
#define ADJACENCYLIST_H
#endif



#ifndef VECTOR
#include <vector>
#define VECTOR
#endif

DisjointSet::DisjointSet(AdjacencyList& adjList){
	representatives = new std::vector<node*>();
	for (int i=0; i<adjList.size(); i++) {
		if (findSet(adjList[i]) == NULL) {
			adjList[i]->rep() = adjList[i];
			adjList[i]->setNext() = NULL;
			representatives->push_back(adjList[i]);
		}
		
		node* temp = adjList[i]->next();
		while (temp != NULL) {
			if (findSet(temp) == NULL) {
				temp->rep() = temp;
				temp->setNext() = NULL;
				representatives->push_back(temp);
			}

			temp= temp->next();
		}
		
	}
}


void DisjointSet::makeSet(node* n) {
// Add node as a new representative
representatives->push_back(n);
}


node* DisjointSet::findSet(node* n) {
	return n->rep();
}


void DisjointSet::makeUnion(node* u, node* v) {

	// Merge the first list with the second

	node* temp = u;
	while (temp->setNext() != NULL) {
		temp = temp->setNext();
	}
	
	temp->setNext() = v->rep();
	temp= v->rep();
        while (temp != NULL) {
		temp->rep() = u->rep();
		temp= temp->setNext();
	}
}


DisjointSet::~DisjointSet() {
	delete representatives;
}

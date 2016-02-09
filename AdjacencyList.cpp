#include <iostream>
#include "AdjacencyList.h"

#ifndef DISJOINTSET_H
#include "DisjointSet.h"
#define DISJOINTSET_H
#endif


#ifndef VECTOR
#include <vector>
#define VECTOR
#endif

AdjacencyList::AdjacencyList() {
	nodes = new std::vector<node*>();
}

void AdjacencyList::addEdge(node* source, node* dest){
	int i;
	for(i=0; i<nodes->size(); i++) {
		if ((*nodes)[i] == source) {
			node* temp = (*nodes)[i];
			while (temp->next() != NULL) {
				temp = temp->next();
			}
			temp->next() = dest;
                        break;
		}
	}

	if (i== nodes->size()) {
		nodes->push_back(source);
		(*nodes)[i]->next() = dest;
	}

}

void AdjacencyList::deleteEdge(node* source, node* dest) {
}

void AdjacencyList::printGraph() const{

	for (int i=0; i<nodes->size(); i++) {
		std::cout << "Source:" << (*nodes)[i]->getLabel();
		std::cout << std::endl;
		std::cout <<  "\t------";
		node* temp = (*nodes)[i];
		while (temp!= NULL) {
			std::cout << "Destination : "<< temp->getLabel();
				std::cout <<  "\t------";
		temp = temp->next();
		}
		 std::cout << std::endl;
	}

}

node* AdjacencyList::operator[] (const int index) const{
	return (*nodes)[index];
}


AdjacencyList::~AdjacencyList() {
/*	for (int i=0; i<nodes->size(); i++) {
		delete *nodes[i];
	}*/

	delete nodes;
}

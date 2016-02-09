#ifndef MST_H
#include "MST.h"
#define MST_H
#endif

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

#include <algorithm>

MST::MST(DisjointSet& djset, AdjacencyList& aInput): djSet(djset), adjInput(aInput) {
	edges = new std::vector<Edge*>();
	// Populate vector edges from adjInput

	for (int i=0; i<adjInput.size(); i++) {
		node* source = adjInput[i];
		node* temp = source->next();
		while (temp != NULL) {
			edges->push_back(new Edge(source, temp, temp->getWeight()));
			temp = temp->next();
		}
	}

	// Construct Output Adjacency List
	adjOutput = new AdjacencyList();

}

bool compareEdge(Edge* e1, Edge* e2) {
	return (e1->weight < e2->weight);
};

AdjacencyList& MST::buildMST() {

	std::sort(edges->begin(), edges->end(), compareEdge); 
	for (int i=0; i<edges->size(); i++) {
		if (djSet.findSet((*edges)[i]->source) != djSet.findSet((*edges)[i]->destination)) {
			node* source = (*edges)[i]->source;
			node* destination = (*edges)[i]->destination;
			// Add Edge to the output adjacency List
			adjOutput->addEdge(source, destination);

			// Union the nodes in the djSet
			djSet.makeUnion(source, destination);
		}
	}

return *adjOutput;

}

MST::~MST() {
	delete edges;
}

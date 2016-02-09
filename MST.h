#include <vector>
class AdjacencyList;
class DisjointSet;
class node;

struct Edge {
public:	
	Edge(node* src, node* dest, int w): source(src), destination(dest), weight(w){}
	node* source;
	node* destination;
	int weight;
};

class MST {
public : 
	MST(DisjointSet& djSet, AdjacencyList& aInput);
	AdjacencyList& buildMST();
	~MST();
private :
	AdjacencyList* adjOutput;
	DisjointSet& djSet;
	std::vector<Edge*>* edges;
	AdjacencyList& adjInput;

};





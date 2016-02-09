#include <string>
#include <vector>
class AdjacencyList;
class node {
	private:
		node* nextNode;
		node* sNext;
		int weight;
		node* representative;
		std::string label;
	public :
		node(int w, node* n, node* rep, std::string l, node* setNext = NULL): nextNode(n), weight(w), representative(rep), label(l), sNext(setNext) {}
		node*& rep() { return representative;}
		int getWeight() const {return weight;} 
		node*& next() {return nextNode;} 
		node*& setNext() { return sNext;}
		std::string getLabel() const {return label;}
};

class DisjointSet {
public : 
	DisjointSet(AdjacencyList& adjList);
 	void makeSet(node*);
        node* findSet(node*);
        void makeUnion(node*, node*);
	~DisjointSet();
private:
	std::vector<node*>* representatives;

};

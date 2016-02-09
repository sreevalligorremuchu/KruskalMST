#include <vector>

class node;

class AdjacencyList {
	public :
		AdjacencyList();
		void addEdge(node* source, node* dest);
		void deleteEdge(node* source, node* dest);
		void printGraph() const;
		int size() const {return nodes->size();}
		node* operator[] (const int index) const;
		~AdjacencyList();

	private :
		std::vector<node*>* nodes;
};



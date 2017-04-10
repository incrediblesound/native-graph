#ifndef GRAPH_H_
#define GRAPH_H_

#include "node.h"
#include "edge.h"
#include <vector>

class Graph {
private:
	Node * nodes;
	Edge * edges;
	uint32_t num_nodes;
public:
	Graph();
	void insert_node(std::string);
	void insert_edge(uint32_t, uint32_t);
	Node * node_at(uint32_t);
	bool has_edge(uint32_t, uint32_t);
	std::vector<uint32_t> * topological_sort(uint32_t, std::vector<uint32_t> *);
	void depth_first(uint32_t, std::vector<uint32_t> *);
};

#endif

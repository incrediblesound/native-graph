#include "graph.h"
#include "node.h"
#include "edge.h"

#include <string>

uint32_t MAX_NODES = 100000;

Graph::Graph(){
	this->nodes = new Node[MAX_NODES];
	this->edges = new Edge[MAX_NODES];
	this->num_nodes = 1;
}

void Graph::insert_node(std::string name){
	Node * n = new Node(name, this->num_nodes);
	this->nodes[this->num_nodes] = *n;
	this->num_nodes++;
}

void Graph::insert_edge(uint32_t source, uint32_t target){
	Edge * e = new Edge(target);
	if(this->edges[source].target == 0){
		this->edges[source] = *e;
	} else {
		Edge * ptr = &this->edges[source];
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = e;
	}
};

Node * Graph::node_at(uint32_t idx){
	return &this->nodes[idx];
}

bool Graph::has_edge(uint32_t source, uint32_t target){
	Edge * ptr = &this->edges[source];
	while(ptr->target != 0) {
		if(ptr->target == target){
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

void Graph::depth_first(uint32_t index, std::vector<uint32_t> *result){
	Edge * child = &this->edges[index];
	while(child != NULL && child->target != 0){
		this->topological_sort(child->target, result);
		child = child->next;
	}
	result->push_back(index);
};

std::vector<uint32_t> * Graph::topological_sort(uint32_t index, std::vector<uint32_t> *result){
	this->depth_first(index, result);
	return result;
}

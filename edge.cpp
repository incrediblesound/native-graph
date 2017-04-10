#include "edge.h"

Edge::Edge(uint32_t target){
	this->target = target;
	this->next = NULL;
};

Edge::Edge(){
	this->target = 0;
	this->next = NULL;
};

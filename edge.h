#ifndef EDGE_H_
#define EDGE_H_

#include <cstdint>
#include <string>

class Edge {
public:
	Edge();
	Edge(uint32_t);
	uint32_t target;
	Edge * next;
};

#endif

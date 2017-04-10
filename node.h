#ifndef NODE_H_
#define NODE_H_

#include <cstdint>
#include <string>

class Node {
public:
	Node(){};
	Node(std::string, uint32_t);
	std::string name;
	uint32_t id;
};

#endif

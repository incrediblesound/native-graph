#include <cstdint>
#include <string>
#include <node.h>

#include "graph.h"

Graph * g = new Graph();

void insertNode(const v8::FunctionCallbackInfo<v8::Value>& args){
	v8::String::Utf8Value name(args[0]);
	std::string node_name(*name);
	g->insert_node(node_name);
};

void insertEdge(const v8::FunctionCallbackInfo<v8::Value>& args){
	uint32_t source = static_cast<uint32_t>(args[0]->NumberValue());
	uint32_t target = static_cast<uint32_t>(args[1]->NumberValue());
	g->insert_edge(source, target);
};

void getById(const v8::FunctionCallbackInfo<v8::Value>& args){
	v8::Isolate* isolate = args.GetIsolate();
	uint32_t id = static_cast<uint32_t>(args[0]->NumberValue());
	Node * n = g->node_at(id);

	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, n->name.c_str()));
}

void hasEdge(const v8::FunctionCallbackInfo<v8::Value>& args){
	v8::Isolate* isolate = args.GetIsolate();
	uint32_t source = static_cast<uint32_t>(args[0]->NumberValue());
	uint32_t target = static_cast<uint32_t>(args[1]->NumberValue());
	bool hasEdge = g->has_edge(source, target);
	args.GetReturnValue().Set(v8::Boolean::New(isolate, hasEdge));
}

void topologicalSort(const v8::FunctionCallbackInfo<v8::Value>& args){
	v8::Isolate* isolate = args.GetIsolate();
	uint32_t start = static_cast<uint32_t>(args[0]->NumberValue());

	std::vector<uint32_t> v;
	g->topological_sort(start, &v);
	v8::Handle<v8::Array> array = v8::Array::New(isolate, v.size());
	for(uint32_t i = 0; i < v.size(); i++){
		array->Set(i, v8::Number::New(isolate, v.at(i)));
	}
	args.GetReturnValue().Set(array);
}

void Initialize(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "insertNode", insertNode);
	NODE_SET_METHOD(exports, "insertEdge", insertEdge);
	NODE_SET_METHOD(exports, "getById", getById);
	NODE_SET_METHOD(exports, "hasEdge", hasEdge);
	NODE_SET_METHOD(exports, "topologicalSort", topologicalSort);
}

NODE_MODULE(graph, Initialize)

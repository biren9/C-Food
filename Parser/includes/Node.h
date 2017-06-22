
#ifndef PARSER_INCLUDES_NODES_NODE_H_
#define PARSER_INCLUDES_NODES_NODE_H_

#include "Visitor.h"


enum NodeType {
	arrayType,
	noType,
	errorType,
	opDivision,
	opLess,
	opGreater,
	opEqual,
	opUnEqual,
	opAnd,
	intType,
	intArrayType,
	opPlus,
	opMinus,
	opMultiplication
};

class Node {
private:
	NodeType type;
public:
	Node();
	virtual ~Node();
	virtual void setNodeType(NodeType type);
	virtual NodeType getType();
	virtual void accept(Visitor* visitor) = 0;

};

#endif

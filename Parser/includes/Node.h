
#ifndef PARSER_INCLUDES_NODES_NODE_H_
#define PARSER_INCLUDES_NODES_NODE_H_

#include "ParseTreeVisitor.h"


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
	Node::NodeType type;
public:
	Node();
	virtual ~Node();
	virtual void setNodeType(Node::NodeType type);
	virtual Node::NodeType getType();
	virtual void accept(ParseTreeVisitor* visitor) = 0;

};

#endif

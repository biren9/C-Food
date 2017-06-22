

#ifndef PARSER_NODEOPEXP_H_
#define PARSER_NODEOPEXP_H_

#include "NodeOp.h"
#include "NodeExp.h"

class NodeExp;

class NodeOpExp: public Node {
private:
	NodeOp* op;
	NodeExp* exp;

public:
	~NodeOpExp() {
		delete this->op;
		delete this->exp;
	}

	void addNode(NodeOp* op) {
		this->op = op;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}

	void accept(Visitor* visitor) {
		visitor->visitNode(this);
	}

	NodeOp* getOp() {
		return this->op;
	}

	NodeExp* getExp() {
		return this->exp;
	}
};

#endif

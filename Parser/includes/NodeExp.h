
#ifndef PARSER_NODEEXP_H_
#define PARSER_NODEEXP_H_

#include "NodeExp2.h"
#include "NodeOpExp.h"

class NodeExp: public Node {
private:
	NodeExp2* exp2;
	NodeOpExp* opExp;

public:

	~NodeExp() {
		delete exp2;
		delete opExp;
	}

	void addNode(NodeExp2* exp2) {
		this->exp2 = exp2;
	}

	void addNode(NodeOpExp* opExp) {
		this->opExp = opExp;
	}

	void accept(Visitor* visitor) {
		visitor->visitNode(this);
	}

	NodeExp2* getExp2() {
		return this->exp2;
	}

	NodeOpExp* getOpExp() {
		return this->opExp;
	}
};

#endif

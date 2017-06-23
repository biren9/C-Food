

#ifndef PARSER_NODEEXP2MINUS_H_
#define PARSER_NODEEXP2MINUS_H_

class NodeExp2Minus: public NodeExp2 {
private:
	NodeExp2* exp2;

public:
	~NodeExp2Minus() {
		delete this->exp2;
	}

	void addNode(NodeExp2* exp2) {
		this->exp2 = exp2;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	NodeExp2* getExp2() {
		return this->exp2;
	}
};

#endif

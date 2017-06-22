

#ifndef PARSER_NODEEXP2BRACKET_H_
#define PARSER_NODEEXP2BRACKET_H_

class NodeExp2Bracket: public NodeExp2 {
private:
	NodeExp* exp;

public:
	~NodeExp2Bracket() {
		delete this->exp;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	NodeExp* getExp() {
		return this->exp;
	}
};

#endif

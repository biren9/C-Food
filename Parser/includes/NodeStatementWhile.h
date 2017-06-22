

#ifndef PARSER_NODESTATEMENTWHILE_H_
#define PARSER__NODESTATEMENTWHILE_H_

class NodeStatementWhile: public NodeStatement {
private:
	NodeExp* exp;
	NodeStatement* statement;

public:
	~NodeStatementWhile() {
		delete this->exp;
		delete this->statement;
	}

	void addNode(NodeExp* exp) {
		this->exp = exp;
	}

	void addNode(NodeStatement* statement) {
		this->statement = statement;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	NodeExp* getExp() {
		return this->exp;
	}

	NodeStatement* getStatement() {
		return this->statement;
	}
};


#endif

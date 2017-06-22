

#ifndef PARSER_NODESTATEMENTS_H_
#define PARSER_NODESTATEMENTS_H_

#include "NodeStatement.h"

class NodeStatements: public Node {
private:
	NodeStatement* statement;
	NodeStatements* statements;

public:

	~NodeStatements() {
		delete this->statement;
		delete this->statements;
	}

	void addNode(NodeStatement* statement) {
		this->statement = statement;
	}

	void addNode(NodeStatements* statements) {
			this->statements = statements;
	}

	void accept(Visitor* visitor) {
		visitor->visitNode(this);
	}

	NodeStatement* getStatement() {
		return this->statement;
	}

	NodeStatements* getStatements() {
		return this->statements;
	}
};

#endif

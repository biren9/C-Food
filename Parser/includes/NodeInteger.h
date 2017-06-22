

#ifndef PARSER_NODEINTEGER_H_
#define PARSER_NODEINTEGER_H_

#include "../../../Scanner/includes/Token.h"

class NodeInteger: public Node {
private:
	unsigned long value;
	Token* token;

public:
	NodeInteger(unsigned long value, Token* token) {
		this->value = value;
	}

	~NodeInteger() {}

	void addInteger(long int value) {
		this->value = value;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	unsigned long getValue() {
		return this->value;
	}

	unsigned int getLine() {
		return this->token->getLine();
	}

	unsigned int getColumn() {
		return this->token->getColumn();
	}
};


#endif

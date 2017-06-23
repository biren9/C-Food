
#ifndef PARSER_NODEINTEGER_H_
#define PARSER_NODEINTEGER_H_

#include "../../../Scanner/includes/Token.h"

class NodeInteger: public Node {
private:
    Token* token;

public:
    NodeInteger(Token* token) {
        this->token = token;
    }

    ~NodeInteger() {}

    /*void addInteger(long int value) {
        this->value = value;
    }*/

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    unsigned long getValue() {
        return this->token->getValue();
    }

    unsigned int getLine() {
        return this->token->getLine();
    }

    unsigned int getColumn() {
        return this->token->getColumn();
    }
};

#endif

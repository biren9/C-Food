
#ifndef PARSER_NODEIDENTIFIER_H_
#define PARSER_NODEIDENTIFIER_H_

#include "../../../Symboltable/includes/InfoNode.h"
#include "../../../Scanner/includes/Token.h"
#include "../../../Symboltable/includes/StringTabelle.h"

class NodeIdentifier: public Node {
private:
    Token* token;

public:
    NodeIdentifier(Token* token) {
        this->token = token;
    }

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    char* getInformation() {
        return this->token->getKey()->strTabelle->stringArr+(this->information->Index);
    }

    unsigned int getLine() {
        return this->token->getLine();
    }

    unsigned int getColumn() {
        return this->token->getColumn();
    }
};

#endif

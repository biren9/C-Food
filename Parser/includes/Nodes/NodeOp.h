

#ifndef PARSER_NODEOP_H_
#define PARSER_NODEOP_H_

#include "../../../Scanner/includes/Token.h"

class NodeOp: public Node {
private:
    Token* token;
public:
    NodeOp (Token* token) {
        this->token = token;
    }

    ~NodeOp() {}

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    Token* getToken() {
        return this->token;
    }
};

#endif
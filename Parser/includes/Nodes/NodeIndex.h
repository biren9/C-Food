

#ifndef PARSER_NODEINDEX_H_
#define PARSER_NODEINDEX_H_

#include "NodeExp.h"

class NodeIndex: public Node {
private:
    NodeExp* exp;

public:

    ~NodeIndex() {
        delete exp;
    }

    void addNode(NodeExp* exp) {
        this->exp = exp;
    }

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    NodeExp* getExp() {
        return this->exp;
    }
};

#endif


#ifndef PARSER_NODESTATEMENTASSIGN_H_
#define PARSER_NODESTATEMENTASSIGN_H_

#include "NodeIndex.h"
#include "NodeExp.h"

class NodeStatementAssign: public NodeStatement {
private:
    NodeIdentifier* identifier;
    NodeIndex* index;
    NodeExp* exp;

public:
    ~NodeStatementAssign() {
        delete this->identifier;
        delete this->index;
        delete this->exp;
    }

    void addNode(NodeIdentifier* identifier) {
        this->identifier = identifier;
    }

    void addNode(NodeIndex* index) {
        this->index = index;
    }

    void addNode(NodeExp* exp) {
        this->exp = exp;
    }

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    NodeIdentifier* getIdentifier() {
        return this->identifier;
    }

    NodeIndex* getIndex() {
        return this->index;
    }

    NodeExp* getExp() {
        return this->exp;
    }
};

#endif

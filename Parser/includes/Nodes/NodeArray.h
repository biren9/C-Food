
#ifndef PARSER_NODEARRAY_H_
#define PARSER_NODEARRAY_H_

#include "NodeInteger.h"

class NodeArray: public Node {
private:
    NodeInteger* integer;

public:
    ~NodeArray() {
        delete this->integer;
    }

    void addInteger(NodeInteger* integer) {
        this->integer = integer;
    }

    NodeInteger* getInteger() {
        return this->integer;
    }

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }
};

#endif
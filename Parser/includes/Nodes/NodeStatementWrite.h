
#ifndef PARSER_NODESTATEMENTWRITE_H_
#define PARSER_NODESTATEMENTWRITE_H_

class NodeStatementWrite: public NodeStatement {
private:
    NodeExp* exp;

public:
    ~NodeStatementWrite() {
        delete this->exp;
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

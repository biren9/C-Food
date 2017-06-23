
#ifndef PARSER_NODEPROG_H_
#define PARSER_NODEPROG_H_

#include "NodeDecls.h"
#include "NodeStatements.h"
#include "../Visitor.h"

class NodeProg: public Node {
private:
    NodeDecls* decls;
    NodeStatements* statements;

public:
    ~NodeProg() {
        delete this->decls;
        delete this->statements;
    }

    void addNode(NodeDecls* decls) {
        this->decls = decls;
    }

    void addNode(NodeStatements* statements) {
        this->statements = statements;
    }

    NodeDecls* getDecls() {
        return this->decls;
    }

    NodeStatements* getStatements() {
        return this->statements;
    }

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

};

#endif

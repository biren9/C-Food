

#ifndef PARSER_NODEDECLS_H_
#define PARSER_NODEDECLS_H_

#include "NodeDecl.h"
#include "../Node.h"

class NodeDecls: public Node {
private:
    NodeDecl* decl;
    NodeDecls* decls;

public:
    ~NodeDecls() {
        delete this->decl;
        delete this->decls;
    }

    void addNode(NodeDecl* decl) {
        this->decl = decl;
    }

    void addNode(NodeDecls* decls) {
        this->decls = decls;
    }

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    NodeDecl* getDecl() {
        return this->decl;
    }

    NodeDecls* getDecls() {
        return this->decls;
    }
};

#endif

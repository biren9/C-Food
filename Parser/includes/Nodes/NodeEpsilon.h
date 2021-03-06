

#ifndef PARSER_NODEEPSILON_H_
#define PARSER_NODEEPSILON_H_

enum EpsilonType {
    epsDecls,
    epsArray,
    epsStatements,
    epsIndex,
    epsOpExp
};

class NodeEpsilon: public NodeDecls, public NodeArray, public NodeStatements, public NodeIndex, public NodeOpExp {
public:

    NodeEpsilon(EpsilonType epsType) {
        this->epsType = epsType;
    }

    virtual ~NodeEpsilon () {}

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    void setEpsilonType(NodeType type) {
        this->type = type;
    }

    NodeType getType() {
        return this->type;
    }

    EpsilonType getEpsilonNodeType() {
        return this->epsType;
    }

private:
    NodeType type;
    EpsilonType epsType;
};

#endif

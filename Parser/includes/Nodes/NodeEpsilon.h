

#ifndef PARSER_NODEEPSILON_H_
#define PARSER_NODEEPSILON_H_

class NodeEpsilon: public NodeDecls, public NodeArray, public NodeStatements, public NodeIndex, public NodeOpExp {
public:
    enum EpsilonType {
        epsDecls,
        epsArray,
        epsStatements,
        epsIndex,
        epsOpExp
    };

    NodeEpsilon(NodeEpsilon::EpsilonType epsType) {
        this->epsType = epsType;
    }

    virtual ~NodeEpsilon () {}

    void accept(Visitor* visitor) {
        visitor->visitNode(this);
    }

    void setEpsilonType(NodeType type) {
        this->type = type;
    }

    NodeType getEpsilonType() {
        return this->type;
    }

    NodeEpsilon::EpsilonType getEpsilonNodeType() {
        return this->epsType;
    }

private:
    NodeType type;
    NodeEpsilon::EpsilonType epsType;
};

#endif

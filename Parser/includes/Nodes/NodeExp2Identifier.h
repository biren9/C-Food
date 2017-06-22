
#ifndef PARSER_NODEEXP2IDENTIFIER_H_
#define PARSER_NODEEXP2IDENTIFIER_H_

class NodeExp2Identifier: public NodeExp2 {
private:
    NodeIdentifier* identifier;
    NodeIndex* index;

public:
    ~NodeExp2Identifier() {
        delete this->identifier;
        delete this->index;
    }

    void addNode(NodeIdentifier* identifier) {
        this->identifier = identifier;
    }

    void addNode(NodeIndex* index) {
        this->index = index;
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
};

#endif

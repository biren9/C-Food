#include "../includes/Node.h"

Node::Node() {}

Node::~Node() {}

void Node::accept(Visitor *visitor) {
    visitor->visitNode(this);
}

void Node::setNodeType(NodeType type) {
    this->type = type;
}

NodeType Node::getType() {
    return this->type;
}

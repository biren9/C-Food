#include "../includes/Node.h"

Node::Node() {
    this->type = Node::noType;
}

Node::~Node() {}

void Node::accept(ParseTreeVisitor* visitor) {
    visitor->visitNode(this);
}

void Node::setType(Node::NodeType type) {
    this->type = type;
}

Node::NodeType Node::getType() {
    return this->type;
}

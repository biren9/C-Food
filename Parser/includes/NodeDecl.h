
#ifndef PARSER_NODEDECL_H_
#define PARSER_NODEDECL_H_

#include "Node.h"
#include "NodeArray.h"
#include "NodeIdentifier.h"

class NodeDecl: public Node {
private:
	NodeArray* array;
	NodeIdentifier* identifier;

public:
	~NodeDecl() {
		delete this->array;
		delete this->identifier;
	}

	void addNode(NodeArray* array) {
		this->array = array;
	}

	void addNode(NodeIdentifier* identifier) {
		this->identifier = identifier;
	}

	void accept(Visitor* visitor) {
		visitor->visitNode(this);
	}

	NodeArray* getArray() {
		return this->array;
	}

	NodeIdentifier* getIdentifier() {
		return this->identifier;
	}
};


#endif


#ifndef PARSER_NODESTATEMENTREAD_H_
#define PARSER_NODESTATEMENTREAD_H_

class NodeStatementRead: public NodeStatement {
private:
	NodeIdentifier* identifier;
	NodeIndex* index;

public:
	~NodeStatementRead() {
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



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

private:
	Node::NodeType type;
	NodeEpsilon::EpsilonType epsType;


public:

	NodeEpsilon(NodeEpsilon::EpsilonType epsType) {
		this->epsType = epsType;
	}

	virtual ~NodeEpsilon () {}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	void setEpsilonType(NodeType type) {
		this->type = type;
	}

	Node::NodeType getEpsilonType() {
		return this->type;
	}

	NodeEpsilon::EpsilonType getEpsilonNodeType() {
		return this->epsType;
	}
};


#endif

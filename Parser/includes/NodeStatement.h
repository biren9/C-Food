

#ifndef PARSER_NODESTATEMENT_H_
#define PARSER_NODESTATEMENT_H_

class NodeStatement: public Node {
public:
	~NodeStatement() {

	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

};


#endif


#ifndef PARSER_NODEEXP2_H_
#define PARSER_NODEEXP2_H_


class NodeExp2: public Node {
public:
	~NodeExp2() {

	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}
};


#endif

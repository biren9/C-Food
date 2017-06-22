
#ifndef PARSER_NODEEXP2EXCLAMATION_H_
#define PARSER_NODEEXP2EXCLAMATION_H_

class NodeExp2Exclamation: public NodeExp2 {
private:
	NodeExp2* exp2;

public:
	~NodeExp2Exclamation() {
		delete this->exp2;
	}

	void addNode(NodeExp2* exp2) {
		this->exp2 = exp2;
	}

	void accept(Visitor* visitor) {
		visitor->visitNode(this);
	}

	NodeExp2* getExp2() {
		return this->exp2;
	}
};

#endif

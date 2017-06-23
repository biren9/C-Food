//
// Created by ninja on 17.04.2017.
//

#ifndef TESTPROJECT_INFONODE_H
#define TESTPROJECT_INFONODE_H

#include "../../Parser/includes/Node.h"
class StringTabelle;
class InfoNode {
public:
	InfoNode(StringTabelle* strTabelle, unsigned int Index, InfoNode *prev, InfoNode *next) {
		this->strTabelle = strTabelle;
		this->Index = Index;
		this->prev = prev;
		this->next = next;
	}
	StringTabelle* strTabelle;
	unsigned int Index;
	InfoNode *prev;
    InfoNode *next;
	NodeType getType() { return type;};
	void storeType(NodeType type) {this->type = type;}

private:
	NodeType type;
};
#endif //TESTPROJECT_INFONODE_H

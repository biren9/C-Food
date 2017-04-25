//
// Created by ninja on 09.04.2017.
//
#include "../includes/Liste.h"

Liste::Liste() {
    

}

Liste::~Liste() {
    //geht durch die liste durch und deleted alle Knoten
    for (InfoNode *node = first; node != 0; node = (*node).next) {
        if (node -> prev != nullptr) {
            delete (node -> prev);
        }
    }
}

InfoNode* Liste::addEnd(const char* lexem, StringTabelle* strTab) {
	if (!size) {
		InfoNode *insertedNode = new InfoNode{ strTab,strTab->insert(lexem),last, nullptr };
		first = insertedNode;
		last = insertedNode;
        ++size;
		return insertedNode;
	}
	else {
        //if lexem already added return InfoNode pointer
		for (InfoNode *node = first; node != 0; node = (*node).next) {
			std::cout << !(strcmp(&(node->strTabelle->stringArr[node->Index]),lexem));
			if (!(strcmp(&(node->strTabelle->stringArr[node->Index]),lexem))) {
				return node;
			}
		}
        //if lexem not added, Create new InfoNode and return its pointer;
		InfoNode *insertedNode = new InfoNode{ strTab,strTab->insert(lexem),last, nullptr };
		last->next = insertedNode;
		last = insertedNode;
		return insertedNode;
	}

}

void Liste::printList() {
    
}

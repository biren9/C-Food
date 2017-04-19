//
// Created by ninja on 09.04.2017.
//
#include "Liste.h"

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

InfoNode* Liste::addEnd(char* lexem, StringTabelle* strTab) {
	if (first == nullptr) {
		InfoNode *insertedNode = new InfoNode{ strTab,strTab->insert(lexem),last, nullptr };
		first = insertedNode;
		last = insertedNode;
		return insertedNode;
	}
	else {
		InfoNode *insertedNode = new InfoNode{ strTab,strTab->insert(lexem),last, nullptr };
		last->next = insertedNode;
		last = insertedNode;
		return insertedNode;
	}
}

void Liste::printList() {
    
}

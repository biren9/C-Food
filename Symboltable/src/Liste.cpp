//
// Created by ninja on 09.04.2017.
//
#include "Liste.h"

Liste::Liste() {
    first = new InfoNode{"test", nullptr, nullptr};
    last = new InfoNode{"test2", first, nullptr};
    first->next = last;

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
    InfoNode *insertedNode = new InfoNode{strTab->insert(lexem),last, nullptr};
    last->next = insertedNode;
    last = insertedNode;
    return insertedNode;
}

void Liste::printList() {
    for (InfoNode *current = first; current != 0; current = current->next)
        std::cout<<(*current).stringTablePointer << std::endl;
}

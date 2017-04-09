//
// Created by ninja on 09.04.2017.
//
#include "../includes/Liste.h"
#include <iostream>
Liste::Liste() {
    first = new InfoNode{"test", nullptr, nullptr};
    last = new InfoNode{"test2", first, nullptr};
    first->next = last;

}

bool Liste::addEnd(char* value) {
    InfoNode *insertedNode = new InfoNode{"addedNode",last, nullptr};
    last->next = insertedNode;
    last = insertedNode;
}

void Liste::printList() {
    for (InfoNode *current = first; current != 0; current = current->next)
        std::cout<<(*current).stringTablePointer << std::endl;
}

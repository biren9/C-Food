//
// Created by ninja on 09.04.2017.
//
#include "InfoNode.h"
#include <iostream>
#include "StringTabelle.h"

#ifndef HASHTABELLE_LISTE_H
#define HASHTABELLE_LISTE_H

class Liste {
public:
    Liste();
    ~Liste();
    InfoNode* addEnd(char* lexem, StringTabelle* strTab);
    void printList();
private:
    InfoNode *first;
	InfoNode *last;

};
#endif //HASHTABELLE_LISTE_H

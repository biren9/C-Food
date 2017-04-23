//
// Created by ninja on 09.04.2017.
//

#ifndef HASHTABELLE_LISTE_H
#define HASHTABELLE_LISTE_H

#include "InfoNode.h"
#include <iostream>
#include "../includes/StringTabelle.h"


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

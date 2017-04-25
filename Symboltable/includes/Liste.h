//
// Created by ninja on 09.04.2017.
//

#ifndef HASHTABELLE_LISTE_H
#define HASHTABELLE_LISTE_H

#include "InfoNode.h"
#include <iostream>
#include <cstring>
#include "../includes/StringTabelle.h"


class Liste {
public:
    Liste();
    ~Liste();
    InfoNode* addEnd(const char* lexem, StringTabelle* strTab);
private:
    InfoNode *first;
	InfoNode *last;
	unsigned int size = 0;

};
#endif //HASHTABELLE_LISTE_H

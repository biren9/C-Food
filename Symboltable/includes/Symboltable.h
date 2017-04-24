//
// Created by ninja on 16.04.2017.
//

#ifndef TESTPROJECT_SYMBOLTABLE_H
#define TESTPROJECT_SYMBOLTABLE_H
constexpr unsigned int SYMBOL_TABLE_SIZE = 1021;

#include "InfoNode.h"
#include "../includes/StringTabelle.h"
#include "../includes/Liste.h"
#include <iostream>
class Symboltable {

public:
    Symboltable();
    ~Symboltable();
	InfoNode* insert(const char *lexem);
	StringTabelle *stringTabelle;
private:
    Liste* hashTabelle[SYMBOL_TABLE_SIZE];
    unsigned int hash(const char *lexem);
    
};


#endif //TESTPROJECT_SYMBOLTABLE_H

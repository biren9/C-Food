//
// Created by ninja on 16.04.2017.
//
#include "InfoNode.h"
#include "StringTabelle.h"
#include "Liste.h"
#include <iostream>
#ifndef TESTPROJECT_SYMBOLTABLE_H
#define TESTPROJECT_SYMBOLTABLE_H
constexpr unsigned int SYMBOL_TABLE_SIZE = 1021;

class Symboltable {

public:
    Symboltable();
    ~Symboltable();
	InfoNode* insert(char *lexem);
	StringTabelle *stringTabelle;
private:
    Liste* hashTabelle[SYMBOL_TABLE_SIZE];
    unsigned int hash(char *lexem);
    
};


#endif //TESTPROJECT_SYMBOLTABLE_H

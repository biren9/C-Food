//
// Created by ninja on 16.04.2017.
//

#include "Symboltable.h"
Symboltable::Symboltable() {
    for  (unsigned int i = 0; i < SYMBOL_TABLE_SIZE; ++i) {
        hashTabelle[i] = new Liste();
		stringTabelle = new StringTabelle();
    }
}

Symboltable::~Symboltable() {
	delete stringTabelle;
	for  (unsigned int i = 0; i < SYMBOL_TABLE_SIZE; ++i) {
        delete hashTabelle[i];
    }
}

InfoNode* Symboltable::insert(char *lexem) {
    return hashTabelle[hash(lexem)]->addEnd(lexem, stringTabelle);
}

unsigned int Symboltable::hash(char *lexem) {
    unsigned int hash = 5381;
    for (int i = 0 ; lexem[i] != '\0'; ++i) {
        hash = ((hash << 5)) + lexem[i];
    }
    return (hash % (SYMBOL_TABLE_SIZE-1));
}
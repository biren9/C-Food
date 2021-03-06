//
// Created by ninja on 16.04.2017.
//

#include "../includes/Symboltable.h"
//create Linked List on heap for each field of the Symboltable array. Create a unique Stringtable.
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
//insert lexem into the Hashtable.
InfoNode* Symboltable::insert(const char *lexem) {
    return hashTabelle[hash(lexem)]->addEnd(lexem, stringTabelle);
}

unsigned int Symboltable::hash(const char *lexem) {
    unsigned int hash = 5381;
    for (int i = 0 ; lexem[i] != '\0'; ++i) {
        hash = ((hash << 5)) + lexem[i];
    }
    return (hash % (SYMBOL_TABLE_SIZE-1));
}
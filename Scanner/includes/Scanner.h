/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "../includes/Token.h"
#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include "../../Symboltable/includes/Symboltable.h"
#include <string>
#include <iostream>

class Scanner {
private:
	Buffer *buffer;
	Automat *automat;
    Symboltable *symbolTable;
public:
	Token* nextToken();
	Scanner(const char* file,Symboltable *symboltable);
	~Scanner();
};

#endif /* SCANNER_H_ */

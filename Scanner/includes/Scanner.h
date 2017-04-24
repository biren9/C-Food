/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_
#include "../../lib/Token.h"
#include "../includes/Scanner.h"
#include "../../Automat/includes/Automat.h"
#include <string>
#include <iostream>

class Scanner {
private:
	Buffer *buffer;
	Automat *automat;
public:
	Token* nextToken();
	Scanner(const char* file);
	~Scanner();
};

#endif /* SCANNER_H_ */

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
#include <thread>
#include <mutex>
#include <deque>

class Scanner {
private:
	Buffer *buffer;
	 Automat *automat;
     Symboltable *symbolTable;
	 std::deque<Token*> tokenList;
	std::thread buildTokensThread;
    void buildTokenList();
    void addToken(Token *token);
    Token* nextT();
    void threadTest() {
        std::cout << "ThreadTest" << std::endl;
    }
    void startTh();
	Token* getToken();
public:
	Token* nextToken();
	Scanner(const char* file,Symboltable *symboltable);
	void startThread()  {
        std::cout << "Vor Thread" << std::endl;
        // do what you want
        this->buildTokensThread = std::thread(&Scanner::buildTokenList,this);
    };
	~Scanner();
};

#endif /* SCANNER_H_ */

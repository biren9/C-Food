/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"
#include <string>
#include <cerrno>
#include <cstdlib>


Scanner::Scanner(const char* file,Symboltable* symboltable) {
    this->buffer = new Buffer(file);
    this->automat = new Automat(buffer);
    this->symbolTable = new Symboltable();

}

Token* Scanner::nextToken() {
    this->automat->nextToken();
    std::string tokenLiteral = this->automat->getTokenLiteral();
    TokenType tokenType = this->automat->getCurrentTokenType();
    int startLine = this->automat->getStartLine();
    int startColumn = this->automat->getStartColumn();

    Token *token = new Token(tokenType,startColumn,startLine,tokenLiteral);

    InfoNode *key = nullptr;
    if(tokenType == Identifier) {
        key  = this->symbolTable->insert(tokenLiteral.c_str());
        token->setKey(key);
    } else if(tokenType == Integer) {
        char *p;
        int value1 = strtol(tokenLiteral.c_str(),&p,10);

        if(errno == ERANGE) {
            errno = 0;
            std::cout << "Error: " << "Value is out of range" << std::endl;
        } else {
            token->setValue(value1);
        }
    }
    return token;

}

Scanner::~Scanner() {
    delete this->buffer;
    delete this->automat;
    delete this->symbolTable;
}
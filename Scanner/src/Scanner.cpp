/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"


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

    if(tokenType == EOL) {
        Token *token = new Token(tokenType,startColumn,startLine, nullptr,tokenLiteral);
        return token;
    } else {
        InfoNode *key = nullptr;
        if(tokenType == Identifier) {
            key  = this->symbolTable->insert(tokenLiteral.c_str());
        }
        Token *token = new Token(tokenType,startColumn,startLine,key,tokenLiteral);
        return token;
    }
}

Scanner::~Scanner() {
    delete buffer;
    delete automat;
    delete symbolTable;
}
/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Scanner.h"


Scanner::Scanner(const char* file) {
    this->buffer = new Buffer(file);
    this->automat = new Automat(buffer);

}

Token* Scanner::nextToken() {
    this->automat->nextToken();
    String tokenLiteral = this->automat->getTokenLiteral();
    TokenType tokenType = this->automat->getCurrentTokenType();
    int startLine = this->automat->getStartColumn();
    int startColumn = this->automat->getStartColumn();

    if(tokenType == EOL) {
        return nullptr;
    } else {
        Token *token = new Token(tokenType,startColumn,startLine);
        return token;
    }
}

Scanner::~Scanner() {}
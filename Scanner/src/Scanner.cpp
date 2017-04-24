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
    std::string tokenLiteral = this->automat->getTokenLiteral();
    TokenType tokenType = this->automat->getCurrentTokenType();
    int startLine = this->automat->getStartLine();
    int startColumn = this->automat->getStartColumn();

    if(tokenType == EOL) {
        Token *token = new Token(tokenType,startColumn,startLine, nullptr,tokenLiteral);
        return token;
    } else {
        Token *token = new Token(tokenType,startColumn,startLine, nullptr,tokenLiteral);
        return token;
    }
}

Scanner::~Scanner() {}
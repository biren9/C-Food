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

Token Scanner::nextToken() {
    this->automat->nextToken();
    std::string tokenLiteral = this->automat->getTokenLiteral();
    TokenType tokenType = this->automat->getCurrentTokenType();
    int startLine = this->automat->getStartLine();
    int startColumn = this->automat->getStartColumn();

    if(tokenType == EOL) {
        std::cout << "EOL" << std::endl;
        Token token = Token(tokenType,startColumn,startLine);
        return token;
    } else {
        Token token = Token(tokenType,startColumn,startLine);
        return token;
    }
}

Scanner::~Scanner() {

}
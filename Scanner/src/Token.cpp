//
// Created by josef on 4/23/17.
//

#include "../../lib/Token.h"

Token::Token(TokenType tokenType,int column, int line,InfoNode *node,std::string tokenLiteral1) {
    this->type = tokenType;
    this->column = column;
    this->line = line;
    this->key = node;
    this->tokenLiteral = tokenLiteral1;
}

int Token::getColumn() {
    return this->column;
}

int Token::getLine() {
    return this->line;
}

TokenType Token::getType() {
    return this->type;
}

InfoNode* Token::getKey() {
    return this->key;
}

std::string Token::getTokenLiteral() {
    return this->tokenLiteral;
}





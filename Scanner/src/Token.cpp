//
// Created by josef on 4/23/17.
//

#include "../../lib/Token.h"

Token::Token(TokenType tokenType,int column, int line) {
    this->type = tokenType;
    this->column = column;
    this->line = line;
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






//
// Created by josef on 4/23/17.
//

#include "../includes/Token.h"

Token::Token(TokenType tokenType,int column, int line,std::string tokenLiteral1) {
    this->type = tokenType;
    this->column = column;
    this->line = line;
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

int Token::getValue() {
    return this->value;
}
void Token::setValue(int i) {
    this->value = i;
}

void Token::setKey(InfoNode *key) {
    this->key = key;
}

void Token::setType(TokenType type) {
    this->type = type;
}

Token::~Token() {

}









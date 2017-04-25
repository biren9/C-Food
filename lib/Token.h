//
// Created by josef on 4/9/17.
//

#ifndef C_FOOD_TOKEN_H
#define C_FOOD_TOKEN_H

#include "../Symboltable/includes/InfoNode.h"
#include "String.h"
enum TokenType
{
    Identifier,
    Assign,
    Plus,
    Integer,
    Semicolon,
    Undefined,
    Minus,
    Colon,
    Equal,
    EqualAssign,
    Comment,
    Multiply,
    Bang,
    ExclamationMark,
    AndOP,
    Greater,
    Smaller,
    OpenParenthesis,
    CloseParenthesis,
    OpenBracket,
    CloseBracket,
    OpenBrace,
    CloseBrace,
    WhileToken,
    IfToken,
    EOL
};

class Token {
private:
    TokenType type;
    int column;
    int line;
    InfoNode *key = nullptr;
    std::string tokenLiteral;
    int value;
public:
    Token(TokenType tokenType,int column, int line,std::string tokenLiteral);
    ~Token();
    TokenType getType();
    void setValue(int i);
    void setKey(InfoNode *key);
    InfoNode* getKey();
    int getValue();
    int getColumn();
    int getLine();
    std::string getTokenLiteral();
};


#endif //C_FOOD_TOKEN_H

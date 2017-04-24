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
public:
    Token(TokenType tokenType,int column, int line,InfoNode *key,std::string tokenLiteral);
    TokenType getType();
    int getColumn();
    int getLine();
    InfoNode* getKey();
    std::string getTokenLiteral();
};


#endif //C_FOOD_TOKEN_H

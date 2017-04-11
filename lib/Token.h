//
// Created by josef on 4/9/17.
//

#ifndef C_FOOD_TOKEN_H
#define C_FOOD_TOKEN_H
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
    Comment,
    Multiply,
    Bang,
    ExclamationMark,
    AndOP
};

class Token {
private:

    TokenType type;
    int column;
    int line;
public:
    Token(TokenType tokenType,int column, int line);
    TokenType getType();
    int getColumn();
    int getRow();
};


#endif //C_FOOD_TOKEN_H

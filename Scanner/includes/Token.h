//
// Created by josef on 4/9/17.
//

#ifndef C_FOOD_TOKEN_H
#define C_FOOD_TOKEN_H


class Token {
private:

    enum Type
    {
        Identifier,
        Assign,
        Plus,
        Integer,
        Semicolon,
        Unknow,
        Minus,
        Colon,
        Equal,
        Comment,
        Multiply,
        Bang,
        ExclamationMark,
        AndOP
    };

    Type tokenType;
    int column;
    int line;
public:
    Token(Type tokenType,int column, int line);
    Type getType();
    int getColumn();
    int getRow();
};


#endif //C_FOOD_TOKEN_H

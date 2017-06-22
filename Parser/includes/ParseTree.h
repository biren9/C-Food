//
// Created by josef on 6/22/17.
//

#ifndef C_FOOD_PARSETREE_H
#define C_FOOD_PARSETREE_H

class ParseTree {
public:
    NodeProg* parse();

private:
    Token* currentToken;
    Scanner* scanner;
    void nextToken();
};

#endif //C_FOOD_PARSETREE_H

//
// Created by josef on 6/22/17.
//

#ifndef C_FOOD_PARSETREE_H
#define C_FOOD_PARSETREE_H

#include "Node.h"
#include "../includes/NodeProg.h"
#include "../includes/NodeDecls.h"
#include "../includes/NodeDecl.h"
#include "../includes/NodeArray.h"
#include "../includes/NodeStatements.h"
#include "../includes/NodeIdentifier.h"
#include "../includes/NodeStatement.h"
#include "../includes/NodeStatementAssign.h"
#include "../includes/NodeStatementBlock.h"
#include "../includes/NodeStatementIf.h"
#include "../includes/NodeStatementRead.h"
#include "../includes/NodeStatementWhile.h"
#include "../includes/NodeStatementWrite.h"
#include "../includes/NodeIndex.h"
#include "../includes/NodeExp.h"
#include "../includes/NodeOpExp.h"
#include "../includes/NodeExp2.h"
#include "../includes/NodeExp2Bracket.h"
#include "../includes/NodeExp2Exclamation.h"
#include "../includes/NodeExp2Identifier.h"
#include "../includes/NodeExp2Integer.h"
#include "../includes/NodeExp2Minus.h"
#include "../includes/NodeInteger.h"
#include "../includes/NodeOp.h"
#include "../includes/NodeEpsilon.h"
#include "../includes/NodeExp2Parenthesis.h"
#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"

class ParseTree {
public:
    NodeProg* parse();
    ParseTree(Scanner *scanner);
private:
    NodeProg* progTree;
    Token* currentToken;
    Scanner* scanner;
    void nextToken();
    NodeProg* prog();
    NodeDecls* decls();
    NodeDecl* decl();
    NodeArray* array();
    NodeStatements* statements();
    NodeStatementAssign* statementAssign();
    NodeStatementWhile* statementWhile();
    NodeStatementIf* statementIf();
    NodeStatementBlock* statementBlock();
    NodeStatementRead* statementRead();
    NodeStatementWrite* statementWrite();
    NodeOpExp* opExp();
    NodeExp* exp();
    NodeExp2* exp2();
    
};

#endif //C_FOOD_PARSETREE_H

//
// Created by josef on 6/22/17.
//

#ifndef C_FOOD_PARSETREE_H
#define C_FOOD_PARSETREE_H

#include "Node.h"
#include "Nodes/NodeProg.h"
#include "Nodes/NodeDecls.h"
#include "Nodes/NodeDecl.h"
#include "Nodes/NodeArray.h"
#include "Nodes/NodeStatements.h"
#include "Nodes/NodeIdentifier.h"
#include "Nodes/NodeStatement.h"
#include "Nodes/NodeStatementAssign.h"
#include "Nodes/NodeStatementBlock.h"
#include "Nodes/NodeStatementIf.h"
#include "Nodes/NodeStatementRead.h"
#include "Nodes/NodeStatementWhile.h"
#include "Nodes/NodeStatementWrite.h"
#include "Nodes/NodeIndex.h"
#include "Nodes/NodeExp.h"
#include "Nodes/NodeOpExp.h"
#include "Nodes/NodeExp2.h"
#include "Nodes/NodeExp2Exclamation.h"
#include "Nodes/NodeExp2Identifier.h"
#include "Nodes/NodeExp2Integer.h"
#include "Nodes/NodeExp2Minus.h"
#include "Nodes/NodeInteger.h"
#include "Nodes/NodeOp.h"
#include "Nodes/NodeEpsilon.h"
#include "Nodes/NodeExp2Parenthesis.h"
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
    NodeStatement* statement();
    NodeStatementAssign* statementAssign();
    NodeStatementWhile* statementWhile();
    NodeStatementIf* statementIf();
    NodeStatementBlock* statementBlock();
    NodeStatementRead* statementRead();
    NodeStatementWrite* statementWrite();
    NodeOpExp* opExp();
    NodeExp* exp();
    void error(std::string parseTreeError);
    std::string getName(TokenType type);
    NodeExp2* exp2();

    NodeIndex *index();
    
};

#endif //C_FOOD_PARSETREE_H

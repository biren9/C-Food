#ifndef PARSER_INCLUDES_VISITORTYPECHECK_H_
#define PARSER_INCLUDES_VISITORTYPECHECK_H_

#include <fstream>
#include <iostream>

#include "Visitor.h"

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
#include "Nodes/NodeExp2Bracket.h"
#include "Nodes/NodeExp2Exclamation.h"
#include "Nodes/NodeExp2Identifier.h"
#include "Nodes/NodeExp2Integer.h"
#include "Nodes/NodeExp2Minus.h"
#include "Nodes/NodeInteger.h"
#include "Nodes/NodeOp.h"
#include "Nodes/NodeEpsilon.h"

using namespace std;

class VisitorTypeCheck: public Visitor {
public:
    VisitorTypeCheck();
    ~VisitorTypeCheck();
    void typeCheck(ParseTree* tree);
    void error(char* errorMessage, unsigned int line, unsigned int column);
    void visitNode(Node* node);
    void visitNode(NodeProg* node);
    void visitNode(NodeArray* node);
    void visitNode(NodeDecl* node);
    void visitNode(NodeDecls* node);
    void visitNode(NodeEpsilon* node);
    void visitNode(NodeExp* node);
    void visitNode(NodeExp2* node);
    void visitNode(NodeExp2Bracket* node);
    void visitNode(NodeExp2Exclamation* node);
    void visitNode(NodeExp2Identifier* node);
    void visitNode(NodeExp2Integer* node);
    void visitNode(NodeExp2Minus* node);
    void visitNode(NodeIdentifier* node);
    void visitNode(NodeIndex* node);
    void visitNode(NodeInteger* node);
    void visitNode(NodeOp* node);
    void visitNode(NodeOpExp* node);
    void visitNode(NodeStatement* node);
    void visitNode(NodeStatementAssign* node);
    void visitNode(NodeStatementBlock* node);
    void visitNode(NodeStatementIf* node);
    void visitNode(NodeStatementRead* node);
    void visitNode(NodeStatementWhile* node);
    void visitNode(NodeStatementWrite* node);
    void visitNode(NodeStatements* node);
private:
    ofstream err;
    unsigned long labelNumber;
};


#endif
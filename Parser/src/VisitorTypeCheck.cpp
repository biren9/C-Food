#include "../includes/VisitorTypeCheck.h"

VisitorTypeCheck::VisitorTypeCheck() {
    //
}

VisitorTypeCheck::~VisitorTypeCheck() {
    //
}

void VisitorTypeCheck::typeCheck(ParseTree* tree) {
    //
}

void VisitorTypeCheck::error(char* errorMessage, unsigned int line, unsigned int column) {
    cerr << "ERROR @ Line: " << line << " Column: " << column << "  " << errorMessage << endl;
    exit(1);
}

void VisitorTypeCheck::visitNode(Node* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeProg* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeArray* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeDecl* node) {
    //
}

//PROG ::= DECLS STATEMENTS
void VisitorTypeCheck::visitNode(NodeDecls* node) {
    ///////
}

void VisitorTypeCheck::visitNode(NodeEpsilon* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeExp* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeExp2* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeExp2Bracket* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeExp2Exclamation* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeExp2Identifier* node) {
    //
}
void VisitorTypeCheck::visitNode(NodeExp2Integer* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeExp2Minus* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeIdentifier* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeIndex* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeInteger* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeOp* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeOpExp* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatement* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatementAssign* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatementBlock* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatementIf* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatementRead* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatementWhile* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatementWrite* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeStatements* node) {
    //
}
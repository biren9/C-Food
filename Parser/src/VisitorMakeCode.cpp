#include "../includes/VisitorMakeCode.h"

VisitorMakeCode::VisitorMakeCode() {
    this->labelNumber = 1;

}

void VisitorMakeCode::makeCode(NodeProg *prog, char *filename) {
this->labelNumber = 1;
    code.open(filename);
    prog->accept(this);
    code.close();

}

VisitorMakeCode::~VisitorMakeCode() {
}

unsigned long VisitorMakeCode::getLabelNumber() {
    return 0;
}

void VisitorMakeCode::visitNode(Node *node) {

}

void VisitorMakeCode::visitNode(NodeProg *node) {

}

void VisitorMakeCode::visitNode(NodeArray *node) {

}

void VisitorMakeCode::visitNode(NodeDecl *node) {

}

void VisitorMakeCode::visitNode(NodeDecls *node) {

}

void VisitorMakeCode::visitNode(NodeEpsilon *node) {

}

void VisitorMakeCode::visitNode(NodeExp *node) {

}

void VisitorMakeCode::visitNode(NodeExp2 *node) {

}

void VisitorMakeCode::visitNode(NodeExp2Bracket *node) {

}

void VisitorMakeCode::visitNode(NodeExp2Exclamation *node) {

}

void VisitorMakeCode::visitNode(NodeExp2Identifier *node) {

}

void VisitorMakeCode::visitNode(NodeExp2Integer *node) {

}

void VisitorMakeCode::visitNode(NodeExp2Minus *node) {

}

void VisitorMakeCode::visitNode(NodeIdentifier *node) {

}

void VisitorMakeCode::visitNode(NodeIndex *node) {

}

void VisitorMakeCode::visitNode(NodeInteger *node) {

}

void VisitorMakeCode::visitNode(NodeOp *node) {

}

void VisitorMakeCode::visitNode(NodeOpExp *node) {

}

void VisitorMakeCode::visitNode(NodeStatement *node) {

}

void VisitorMakeCode::visitNode(NodeStatementAssign *node) {

}

void VisitorMakeCode::visitNode(NodeStatementBlock *node) {

}

void VisitorMakeCode::visitNode(NodeStatementIf *node) {

}

void VisitorMakeCode::visitNode(NodeStatementRead *node) {

}

void VisitorMakeCode::visitNode(NodeStatementWhile *node) {

}

void VisitorMakeCode::visitNode(NodeStatementWrite *node) {

}

void VisitorMakeCode::visitNode(NodeStatements *node) {

}


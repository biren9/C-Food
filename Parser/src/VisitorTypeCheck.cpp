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
//PROG	::=	DECLS STATEMENTS
void VisitorTypeCheck::visitNode(NodeProg* node) {
    node->getDecls()->accept(this);
    node->getStatements()->accept(this);
    node->setNodeType(NodeType::noType);
}
//ARRAY::=[integer])
void VisitorTypeCheck::visitNode(NodeArray* node) {
    if (node != 0) {
        if (node->getInteger()->getValue() > 0) {
            node->setNodeType(NodeType::arrayType);
        } else {
            error("no valid dimension", node->getInteger()->getLine(), node->getInteger()->getColumn());
        }
    }
}
//DECL::=	int ARRAY identifier
//TODO store typinformation
void VisitorTypeCheck::visitNode(NodeDecl* node) {
    if (node->getIdentifier()->getType() != NodeType::noType) {
        error("identifier already defined",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
    }
    else if (node->getArray()->getType() == NodeType::errorType) {
        node->setNodeType(NodeType::errorType);
    }
    else {
        node->setNodeType(NodeType::noType);
        if (node->getArray()->getType() == NodeType::arrayType){

        }
    }
    //node->getIdentifier()->
}

//DECLS	::=	DECL; DECLS
void VisitorTypeCheck::visitNode(NodeDecls* node) {
    node->getDecl()->accept(this);
    if (node != 0) {
        node->getDecls()->accept(this);
    }
    node->setNodeType(NodeType::noType);
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

void VisitorTypeCheck::visitNode(NodeExp2Parenthesis* node) {
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

//STATEMENT ::= identifier INDEX := EXP
void VisitorTypeCheck::visitNode(NodeStatement* node) {
    //if (node->)
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

//STATEMENTS ::=	STATEMENT ; STATEMENTS
void VisitorTypeCheck::visitNode(NodeStatements* node) {
    node->getStatement()->accept(this);
    if (node->getStatements() != 0) {
        node->getStatements()->accept(this);
    }
    node->setNodeType(NodeType::noType);
}
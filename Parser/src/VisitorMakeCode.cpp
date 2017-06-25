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
    return this->labelNumber++;
}

void VisitorMakeCode::visitNode(Node *node) {

}

//PROG	::=	DECLS	STATEMENTS
void VisitorMakeCode::visitNode(NodeProg *node) {
    node->getDecls()->accept(this);
    node->getStatements()->accept(this);
    code << "STP ";
}

//ARRAY	::=	[ integer ] )
void VisitorMakeCode::visitNode(NodeArray *node) {
    code << node->getInteger()->getValue() << endl;
}

//
void VisitorMakeCode::visitNode(NodeDecl *node) {
    code << "DS " << "$" << node->getIdentifier()->getInformation() << " ";
    node->getArray()->accept(this);
}
//DECLS	::=	DECL	; DECLS
void VisitorMakeCode::visitNode(NodeDecls *node) {
    node->getDecl()->accept(this);
    node->getDecls()->accept(this);

}

void VisitorMakeCode::visitNode(NodeEpsilon *node) {
    switch(node->getEpsilonNodeType()) {
        case EpsilonType::epsOpExp:
        case EpsilonType::epsIndex:
        case EpsilonType::epsDecls:
            break;
        case EpsilonType::epsStatements:
            code << "NOP " << endl;
            break;
        case EpsilonType::epsArray:
            code << 1 << endl;
            break;
    }
}

void VisitorMakeCode::visitNode(NodeExp *node) {
    if (node->getOpExp()->getType() == NodeType::noType) {
        node->getExp2()->accept(this);
    }
    else if (node->getOpExp()->getOp()->getType() == NodeType::opGreater) {
        node->getOpExp()->accept(this);
        node->getExp2()->accept(this);
        code << "LES" << endl;
    }
    else if (node->getOpExp()->getOp()->getType() == NodeType::opUnEqual) {
        node->getExp2()->accept(this);
        node->getOpExp()->accept(this);
        code << "NOT" << endl;
    }
    else {
        node->getExp2()->accept(this);
        node->getOpExp()->accept(this);
    }
}

void VisitorMakeCode::visitNode(NodeExp2 *node) {
}

//EXP2 ::= ( EXP )
void VisitorMakeCode::visitNode(NodeExp2Parenthesis *node) {
    node->getExp()->accept(this);
}

//EXP2 ::= ! EXP2
void VisitorMakeCode::visitNode(NodeExp2Exclamation *node) {
    node->getExp2()->accept(this);
    code << " NOT " << endl;
}

//EXP2 ::= identifier INDEX
void VisitorMakeCode::visitNode(NodeExp2Identifier *node) {
    code << "LA " << "$" << node->getIdentifier()->getInformation() << endl;
    node->getIndex()->accept(this);
    code << "LV " << endl;
}

//EXP2 ::= integer
void VisitorMakeCode::visitNode(NodeExp2Integer *node) {
    code << "LC " << node->getInteger()->getValue() << endl;
}

//EXP2 ::= - EXP2
void VisitorMakeCode::visitNode(NodeExp2Minus *node) {
    code << "LC " << 0 << endl;
    node->getExp2()->accept(this);
    code << "SUB" << endl;
}

//
void VisitorMakeCode::visitNode(NodeIdentifier *node) {
}

//INDEX	::=	[ EXP	]){makeCode(EXP
void VisitorMakeCode::visitNode(NodeIndex *node) {
    node->getExp()->accept(this);
    code << "ADD" << endl;
}

void VisitorMakeCode::visitNode(NodeInteger *node) {

}

void VisitorMakeCode::visitNode(NodeOp *node) {
    switch (node->getType()) {
        case NodeType::opPlus:
            code << "ADD" << endl;
            break;
        case NodeType::opMinus:
            code << "SUB" << endl;
            break;
        case NodeType::opMultiplication:
            code << "MUL" << endl;
            break;
        case NodeType::opDivision:
            code << "DIV" << endl;
            break;
        case NodeType::opLess:
            code << "LES" << endl;
            break;
        case NodeType::opGreater: break;
        case NodeType::opEqual:
            code << "EQU" << endl;
            break;
        case NodeType::opUnEqual:
            code << "EQU" << endl;
            break;
        case NodeType::opAnd:
            code << "AND" << endl;
            break;
        default: break;
    }
}

//OP_EXP ::= OP	EXP
void VisitorMakeCode::visitNode(NodeOpExp *node) {
    node->getExp()->accept(this);
    node->getOp()->accept(this);
}

void VisitorMakeCode::visitNode(NodeStatement *node) {
}

//STATEMENT ::= identifier	INDEX := EXP
void VisitorMakeCode::visitNode(NodeStatementAssign *node) {
    node->getExp()->accept(this);
    code << "LA " << "$" << node->getIdentifier()->getInformation() << endl;
    node->getIndex()->accept(this);
    code << "STR " << endl;
}

//STATEMENT ::= { STATEMENTS } ){	makeCode(STATEMENTS);
void VisitorMakeCode::visitNode(NodeStatementBlock *node) {
    node->getStatements()->accept(this);
}

//STATEMENT ::= if	(	EXP ) STATEMENT else STATEMENT
void VisitorMakeCode::visitNode(NodeStatementIf *node) {
    unsigned long label1 = getLabelNumber(), label2 = getLabelNumber();
    node->getExp()->accept(this);
    code << "JIN " << "#label" << label1 << endl;
    node->getStatementIf()->accept(this);
    code << "JMP " << "#label" << label2 << endl;
    code << "#label" << label1 << " NOP " << endl;
    node->getStatementElse()->accept(this);
    code << "#label" << label2 << " NOP " << endl;
}

//STATEMENT ::= read( identifier INDEX	)
void VisitorMakeCode::visitNode(NodeStatementRead *node) {
    code << "REA " << endl;
    code << "LA " << "$" << node->getIdentifier()->getInformation() << endl;
    node->getIndex()->accept(this);
    code << "STR " << endl;
}

//STATEMENT ::= while	( EXP ) STATEMENT
void VisitorMakeCode::visitNode(NodeStatementWhile *node) {
    unsigned long label1 = getLabelNumber(), label2 = getLabelNumber();
    code << "#label" << label1 << " NOP " << endl;
    node->getExp()->accept(this);
    code << "JIN " << "#label" << label2 << endl;
    node->getStatement()->accept(this);
    code << "JMP " << "#label" << label1 << endl;
    code << "#label" << label2 << " NOP " << endl;
}

//STATEMENT ::=	write( EXP	)
void VisitorMakeCode::visitNode(NodeStatementWrite *node) {
    node->getExp()->accept(this);///////////////7/////
    code << "PRI " << endl;
}

//STATEMENTS ::=	STATEMENT ; STATEMENTS
void VisitorMakeCode::visitNode(NodeStatements *node) {
    node->getStatement()->accept(this);
    node->getStatements()->accept(this);
}
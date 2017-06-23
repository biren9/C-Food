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
    if (node->getStatements()!=0) {
        node->getStatements()->accept(this);
    }
    code << " STP ";
}

//ARRAY	::=	[ integer ] )
void VisitorMakeCode::visitNode(NodeArray *node) {
    code << node->getInteger();
}

//
void VisitorMakeCode::visitNode(NodeDecl *node) {
    code << " DS " <<  "$" << node->getIdentifier()->getInformation();
    if (node->getArray() != 0) {
        node->getArray()->accept(this);
    }
    else {
        code << 1;
    }
}
//DECLS	::=	DECL	; DECLS
void VisitorMakeCode::visitNode(NodeDecls *node) {
    node->getDecl()->accept(this);
    if (node->getDecls() != 0) {
        node->getDecls()->accept(this);
    }

}

void VisitorMakeCode::visitNode(NodeEpsilon *node) {

}

void VisitorMakeCode::visitNode(NodeExp *node) {
    if (node->getType() == NodeType::noType) {
        node->getExp2()->accept(this);
    }
    else if (node->getOpExp()->getOp()->getType() == NodeType::opGreater) {
        if (node->getOpExp() != 0) { node->getOpExp()->accept(this); }
        node->getExp2()->accept(this);
        code << "LES";
    }
    else if (node->getOpExp()->getOp()->getType() == NodeType::opUnEqual) {
        node->getExp2()->accept(this);
        if (node->getOpExp() != 0) {node->getOpExp()->accept(this);}
        code << "NOT";
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
    code << " NOT ";
}

//EXP2 ::= identifier INDEX
void VisitorMakeCode::visitNode(NodeExp2Identifier *node) {
    code << "LA " << "$" << node->getIdentifier()->getInformation();
    if (node->getIndex() != 0) {node->getIndex()->accept(this);}
    code << " LV ";
}

//EXP2 ::= integer
void VisitorMakeCode::visitNode(NodeExp2Integer *node) {
    code << " LC " << node->getInteger();
}

//EXP2 ::= - EXP2
void VisitorMakeCode::visitNode(NodeExp2Minus *node) {
    code << " LC " << 0;
    node->getExp2()->accept(this);
    code << " SUB ";
}

//
void VisitorMakeCode::visitNode(NodeIdentifier *node) {
}

//INDEX	::=	[ EXP	]){makeCode(EXP
void VisitorMakeCode::visitNode(NodeIndex *node) {
    node->getExp()->accept(this);
    code << " ADD";
}

void VisitorMakeCode::visitNode(NodeInteger *node) {

}

void VisitorMakeCode::visitNode(NodeOp *node) {
    switch (node->getType()) {
        case NodeType::opPlus: code << "ADD"; break;
        case NodeType::opMinus: code << "SUB"; break;
        case NodeType::opMultiplication: code << "MUL"; break;
        case NodeType::opDivision: code << "DIV"; break;
        case NodeType::opLess: code << "LES"; break;
        case NodeType::opGreater: break;
        case NodeType::opEqual: code << "EQU"; break;
        case NodeType::opUnEqual: code << "EQU"; break;
        case NodeType::opAnd: code << "AND"; break;
    }
}

//OP_EXP ::= OP	EXP
void VisitorMakeCode::visitNode(NodeOpExp *node) {
    if (node != 0) {
        node->getExp()->accept(this);
        node->getOp()->accept(this);
    }
}

void VisitorMakeCode::visitNode(NodeStatement *node) {
}

//STATEMENT ::= identifier	INDEX := EXP
void VisitorMakeCode::visitNode(NodeStatementAssign *node) {
    node->getExp()->accept(this);
    code <<	"LA" << "$" << node->getIdentifier()->getInformation();
    if (node->getIndex() != 0) {node->getIndex()->accept(this);}
    code <<	"STR";
}

//STATEMENT ::= { STATEMENTS } ){	makeCode(STATEMENTS);
void VisitorMakeCode::visitNode(NodeStatementBlock *node) {
    if (node->getStatements() != 0) {
        node->getStatements()->accept(this);
    }
    else {
        code << " NOP ";
    }
}

//STATEMENT ::= if	(	EXP ) STATEMENT else STATEMENT
void VisitorMakeCode::visitNode(NodeStatementIf *node) {
    unsigned long label1 = getLabelNumber(), label2 = getLabelNumber();
    node->getExp()->accept(this);
    code << " JIN " << "#" << label1;
    node->getStatementIf()->accept(this);
    code << " JMP " << "#" << label2;
    node->getStatementElse()->accept(this);
    code << "#" << label2 << " NOP " ;
}

//STATEMENT ::= read( identifier INDEX	)
void VisitorMakeCode::visitNode(NodeStatementRead *node) {
    code << " REA ";
    code << " LA " << "$" << node->getIdentifier()->getInformation();
    if (node->getIndex() != 0) {node->getIndex()->accept(this);}
    code << " STR ";
}

//STATEMENT ::= while	( EXP ) STATEMENT
void VisitorMakeCode::visitNode(NodeStatementWhile *node) {
    unsigned long label1 = getLabelNumber(), label2 = getLabelNumber();
    code << "#" << label1 << " NOP ";
    node->getExp()->accept(this);
    code << " JIN " << "#" << label2;
    node->getStatement()->accept(this);
    code << " JMP " << "#" << label1;
    code << "#" << label2 << " NOP ";
}

//STATEMENT ::=	write( EXP	)
void VisitorMakeCode::visitNode(NodeStatementWrite *node) {
    code << " PRI ";
}

//STATEMENTS ::=	STATEMENT ; STATEMENTS
void VisitorMakeCode::visitNode(NodeStatements *node) {
    node->getStatement()->accept(this);
    if (node->getStatements() != 0) {
        node->getStatements()->accept(this);
    } else {
        code << " NOP ";
    }
}
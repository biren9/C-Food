#include "../includes/VisitorTypeCheck.h"
#include "../../Scanner/includes/Token.h"
VisitorTypeCheck::VisitorTypeCheck() {
    //
}

VisitorTypeCheck::~VisitorTypeCheck() {
    //
}

void VisitorTypeCheck::typeCheck(NodeProg* prog) {
    visitNode(prog);
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
    if (node->getStatements() != 0) {node->getStatements()->accept(this);}
    node->setNodeType(NodeType::noType);
}
//ARRAY::=[integer])
void VisitorTypeCheck::visitNode(NodeArray* node) {
    if (node->getInteger()->getValue() > 0) {
        node->setNodeType(NodeType::arrayType);
    } else {
        error("no valid dimension", node->getInteger()->getLine(), node->getInteger()->getColumn());
    }
}
//DECL::=	int ARRAY identifier
//TODO store typinformation

void VisitorTypeCheck::visitNode(NodeDecl* node) {
    bool arrayDecl = false;
    if (node->getArray() !=0 ) {arrayDecl = true;}
    if (node->getIdentifier()->getToken()->getKey()->getType() != NodeType::noType) {
        error("identifier already defined",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
    }
    else if (arrayDecl && (node->getArray()->getType() == NodeType::errorType)) {
        node->setNodeType(NodeType::errorType);
    }
    else {
        node->setNodeType(NodeType::noType);
        if (arrayDecl && (node->getArray()->getType() == NodeType::arrayType)){
            node->getIdentifier()->getToken()->getKey()->storeType(NodeType::intArrayType);
        }
        else  {
            node->getIdentifier()->getToken()->getKey()->storeType(NodeType::intType);
        }
    }
}

//DECLS	::=	DECL; DECLS
void VisitorTypeCheck::visitNode(NodeDecls* node) {
    node->getDecl()->accept(this);
    if (node->getDecls() != 0){
        node->getDecls()->accept(this);
    }
    node->setNodeType(NodeType::noType);
}

void VisitorTypeCheck::visitNode(NodeEpsilon* node) {
    //
}
//EXP ::=	EXP2	OP_EXP
void VisitorTypeCheck::visitNode(NodeExp* node) {
    NodeExp2 *exp2 = node->getExp2();
    NodeOpExp *opExp = node->getOpExp();
    NodeType  exp2Type = (exp2 == 0) ? NodeType::noType : exp2->getType();
    NodeType  opExpType = (opExp == 0) ? NodeType::noType : opExp->getType();

    if(exp2 != 0) {
        exp2->accept(this);
    }
    if(opExp != 0) {
        opExp->accept(this);
    }

    if (opExpType == NodeType::noType) {
        node->setNodeType(exp2Type);
    }
    else if (exp2Type != opExpType) {
        node->setNodeType(NodeType::errorType);
    }
    else {
        node->setNodeType(exp2Type);
    }

}
//
void VisitorTypeCheck::visitNode(NodeExp2* node) {
}
//(EXP2 ::= ( EXP ))
void VisitorTypeCheck::visitNode(NodeExp2Parenthesis* node) {
    node->getExp()->accept(this);
    node->setNodeType(node->getExp()->getType());
}
//EXP2 ::= ! EXP2
void VisitorTypeCheck::visitNode(NodeExp2Exclamation* node) {
    NodeExp2 *exp2 = node->getExp2();
    NodeType exp2Type = exp2->getType();
    if (exp2!=0) {
        exp2->accept(this);
    }
    if (exp2Type != NodeType::intType) {
        node->setNodeType(NodeType::errorType);
    }
    else {
        node->setNodeType(NodeType::intType);
    }
}
//EXP2 ::= identifier INDEX
void VisitorTypeCheck::visitNode(NodeExp2Identifier* node) {
    NodeIndex *index = node->getIndex();
    NodeType indexType;
    NodeType identifierType = node->getIdentifier()->getToken()->getKey()->getType();
    (index == 0) ? indexType == NodeType ::noType : indexType= index->getType();
    if (index != 0) {
        index->accept(this);
    }
    if (identifierType == NodeType::noType) {
        error("identifier not defined",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
        node->setNodeType(NodeType::errorType);
    }
    else if ((identifierType ==  NodeType::intType) && (indexType == NodeType::noType)) {
        node->setNodeType(identifierType);
    }
    else if ((identifierType == NodeType ::intArrayType) &&(indexType ==NodeType::arrayType)) {
        node->setNodeType(NodeType::intType);
    }
    else {
        error("no primitive type",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
        node->setNodeType(NodeType::errorType);
    }

}
//EXP2 ::= integer
void VisitorTypeCheck::visitNode(NodeExp2Integer* node) {
    node->setNodeType(NodeType::intType);
}
//EXP2 ::= - EXP2
void VisitorTypeCheck::visitNode(NodeExp2Minus* node) {
    NodeExp2 *exp2 = node->getExp2();
    NodeType exp2Type = exp2->getType();
    if (exp2!=0) {
        exp2->accept(this);
    }
    (exp2 == 0) ? node->setNodeType(NodeType::noType): node->setNodeType(exp2Type);
}

void VisitorTypeCheck::visitNode(NodeIdentifier* node) {
    //
}
//INDEX ::= [ EXP ]
void VisitorTypeCheck::visitNode(NodeIndex* node) {
    NodeExp *exp = node->getExp();
    exp->accept(this);
    if (exp->getType() == NodeType::errorType) {
        node->setNodeType(NodeType::errorType);
    }
    else {
        node->setNodeType(NodeType::noType);
    }
}

void VisitorTypeCheck::visitNode(NodeInteger* node) {
    //
}

void VisitorTypeCheck::visitNode(NodeOp* node) {
    TokenType tokenType = node->getToken()->getType();
    switch (tokenType) {
        case TokenType::Plus: node->setNodeType(NodeType::opPlus); break;
        case TokenType::Minus: node->setNodeType(NodeType::opMinus); break;
        case TokenType::Multiply: node->setNodeType(NodeType::opMultiplication); break;
        case TokenType::Colon: node->setNodeType(NodeType::opDivision); break;
        case TokenType::Smaller: node->setNodeType(NodeType::opLess); break;
        case TokenType::Greater: node->setNodeType(NodeType::opGreater); break;
        case TokenType::Equal: node->setNodeType(NodeType::opEqual); break;
        case TokenType::EqualAssign: node->setNodeType(NodeType::opUnEqual); break;
        case TokenType::AndOP: node->setNodeType(NodeType::opAnd); break;
        default: node->setNodeType(NodeType::noType);

    }
}
//OP_EXP ::= OP	EXP
void VisitorTypeCheck::visitNode(NodeOpExp* node) {
    NodeOp *op = node->getOp();
    NodeExp *exp = node->getExp();
    op->accept(this);
    exp->accept(this);
    node->setNodeType(exp->getType());
}

//STATEMENT ::= identifier INDEX := EXP
void VisitorTypeCheck::visitNode(NodeStatement* node) {
    /*
    if (node->)
     */
}

void VisitorTypeCheck::visitNode(NodeStatementAssign* node) {
    if (node->getIdentifier()->getToken()->getKey()->getType() == NodeType::noType) {
        error("identifier not defined",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
        node->setNodeType(NodeType::errorType);
    }
    else if ((node->getExp()->getType() == NodeType::intType)&&
            ((node->getIdentifier()->getToken()->getKey()->getType() == NodeType::intType && node->getIndex() == 0)
             || (node->getIdentifier()->getToken()->getKey()->getType() == NodeType::intArrayType
                 && ((node->getIndex()!=0)&&(node->getIndex()->getType() == NodeType::arrayType) )))) {
        node->setNodeType(NodeType::noType);
    }
    else {
        error("incompatible types",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
        node->setNodeType(NodeType::errorType);
    }
}
//STATEMENT ::= { STATEMENTS }
void VisitorTypeCheck::visitNode(NodeStatementBlock* node) {
    NodeStatements *statements = node->getStatements();
    if (statements !=0) {
        node->accept(this);
    }
    node->setNodeType(NodeType::noType);
}
//STATEMENT ::= if	( EXP ) STATEMENT else STATEMENT
void VisitorTypeCheck::visitNode(NodeStatementIf* node) {
    NodeStatement *ifBlock = node->getStatementIf();
    NodeStatement *elseBlock = node->getStatementElse();
    NodeExp *exp = node->getExp();
    exp->accept(this);
    ifBlock->accept(this);
    elseBlock->accept(this);
    if (exp->getType() == NodeType::errorType) {
        node->setNodeType(NodeType::errorType);
    }
    else  {
        node->setNodeType(NodeType::noType);
    }
}
//(STATEMENT ::= read(	identifier INDEX)
void VisitorTypeCheck::visitNode(NodeStatementRead* node) {
    NodeType identifierType = node->getIdentifier()->getToken()->getKey()->getType();
    NodeIndex *index = node-> getIndex();
    if (index != 0) {
        index->accept(this);
    }
    if (identifierType == NodeType::noType) {
        error("identifier not defined",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
        node->setNodeType(NodeType::errorType);
    }
    else if (
            (identifierType == NodeType::intType) && (index == 0)
        ||  ((identifierType == NodeType::arrayType) && ((index != 0)&&(index->getType()==NodeType::arrayType)))
            ) {
        node->setNodeType(NodeType::noType);
    }
    else  {
        error("incompatible type",node->getIdentifier()->getLine(),node->getIdentifier()->getColumn());
        node->setNodeType(NodeType::errorType);
    }
}
//STATEMENT ::= while	(	EXP ) STATEMENT
void VisitorTypeCheck::visitNode(NodeStatementWhile* node) {
    NodeExp *exp = node->getExp();
    NodeStatement *statement = node->getStatement();
    if (exp->getType() == NodeType::errorType) {
        node->setNodeType(NodeType::errorType);
    }
    else {
        node->setNodeType(NodeType::noType);
    }
}

//STATEMENT ::=	write(	EXP )
void VisitorTypeCheck::visitNode(NodeStatementWrite* node) {
    node->getExp()->accept(this);
    node->setNodeType(NodeType::noType);
}

//STATEMENTS ::=	STATEMENT ; STATEMENTS
void VisitorTypeCheck::visitNode(NodeStatements* node) {
    node->getStatement()->accept(this);
    if (node->getStatements() != 0) {
        node->getStatements()->accept(this);
    }
    node->setNodeType(NodeType::noType);
}
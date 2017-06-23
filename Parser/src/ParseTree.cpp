#include "../includes/ParseTree.h"
#include "../includes/NodeDecl.h"
#include "../includes/NodeArray.h"
#include "../includes/NodeDecls.h"
#include "../includes/NodeInteger.h"
#include "../../Scanner/includes/Token.h"
#include "../includes/NodeStatement.h"




#include <iostream>
#include <stdlib.h>


ParseTree::ParseTree(Scanner *scanner) {
    this->scanner = scanner;
    this->currentToken = this->scanner->nextToken();
}

void ParseTree::parse() {
    this->progTree = prog();
}

void ParseTree::nextToken() {
    if (this->currentToken->getType() != EOL) {
        this->currentToken = this->scanner->nextToken();
        if (currentToken->getType() == Token::Comment) {
            nextToken();
        }
    }
}

/**
 * PROG ::= DECLS STATEMENTS
 */
NodeProg* ParseTree::prog() {

    switch(this->currentToken->getType()) {
        case IntToken:
        case OpenBracket:
        case OpenParenthesis:
        case OpenBrace:
        case ReadToken:
        case WriteToken:
        case IfToken:
        case WhileToken:
        case Plus:
        case Minus:
        case Multiply:
        case Smaller:
        case Greater:
        case Colon:
        case EqualAssign:
        case Equal:
        case ExclamationMark:
        case AndOP:
        case Integer:
        case Identifier:
            NodeProg* prog = new NodeProg();
            prog->addNode(decls());
            prog->addNode(statements());
            break;
        default:
            error();
    }
    return prog;
}





void ParseTree::error() {
    //cerr << "unexpected Token Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn() << " " << currentToken->typeToString() << endl;
    cerr << "stop" << endl;
    exit(EXIT_FAILURE);
}




NodeDecls* ParseTree::decls() {
    switch(this->currentType->getType()) {
    case IntToken:
        NodeDecls* nodeDecls = new NodeDecls();
        nodeDecls->addNode(decl());
        if(this->currentToken->getType() == Semicolon) {
            nextToken();
        } else {
            error();
        }
        nodeDecls->addNode(decls());
        return nodeDecls;
    case OpenBracket:
    case OpenParenthesis:
    case OpenBrace:
    case ReadToken:
    case WriteToken:
    case IfToken:
    case WhileToken:
    case Plus:
    case Minus:
    case Multiply:
    case Smaller:
    case Greater:
    case Colon:
    case EqualAssign:
    case Equal:
    case ExclamationMark:
    case AndOP:
    case Integer:
    case Identifier:
        return nullptr;
    default:
        error();
}

NodeDecl* ParseTree::decl() {
    nextToken();
    NodeDecl *nodeDecl = new NodeDecl();
    nodeDecl->addNode(array());
    if(currentToken->getType() == Identifier) {
        NodeIdentifier* nodeIdentifier = new NodeIdentifier(currentToken);
        nodeDecl->addNode(nodeIdentifier);
        nextToken();
    } else {
        error();
    }
    return nodeDecl;
}

NodeArray* ParseTree::array() {
    switch(this->currentType->getType()) {
        case OpenBracket:
            NodeArray* nodeArray = new NodeArray();
            nextToken();
            if(currentToken->getType() == Integer) {
                NodeInteger *nodeInteger = new NodeInteger(currentToken);
                nodeArray->addInteger(nodeInteger);
                nextToken();
                if(currentToken->getType() == CloseBracket) {
                    nextToken();
                } else {
                    error();
                }
            } else {
                error();
            }
            return nodeArray;
        case IntToken:
        case OpenParenthesis:
        case OpenBrace:
        case ReadToken:
        case WriteToken:
        case IfToken:
        case WhileToken:
        case Plus:
        case Minus:
        case Multiply:
        case Smaller:
        case Greater:
        case Colon:
        case EqualAssign:
        case Equal:
        case ExclamationMark:
        case AndOP:
        case Integer:
        case Identifier:
            return nullptr;
        default:
            error();
    }
}

    NodeStatements* ParseTree::statements() {
        switch(this->currentType->getType()) {
            case WriteToken:
            case ReadToken:
            case OpenBrace:
            case IfToken:
            case WhileToken:
            case Identifier:
                NodeStatements *nodeStatements = new NodeStatements();
                switch(this->currentType->getType()){
                    case Identifier: nodeStatements->addNode(statementAssign());
                    break;
                    case WhileToken: nodeStatements->addNode(statementWhile());
                        break;
                    case IfToken: nodeStatements->addNode(statementIf());
                        break;
                    case OpenBrace: nodeStatements->addNode(statementBlock());
                        break;
                    case ReadToken: nodeStatements->addNode(statementRead());
                        break;
                    case WriteToken: nodeStatements->addNode(statementWrite());
                    break;
                }
                if(this->currentToken->getType() == Semicolon) {
                    nextToken();
                } else {
                    error();
                }
                nodeStatements->addNode(statements());
                return nodeStatements;

            case OpenBracket:
            case IntToken:
            case OpenParenthesis:
            case Plus:
            case Minus:
            case Multiply:
            case Smaller:
            case Greater:
            case Colon:
            case EqualAssign:
            case Equal:
            case ExclamationMark:
            case AndOP:
            case Integer:
                return nullptr;
            default:
                error();
        }
    }


    NodeStatementAssign* ParseTree::statementAssign() {
        NodeIdentifier *nodeIdentifier = new NodeIdentifier(currentToken);
        NodeStatementAssign *nodeStatementAssign = new NodeStatementAssign();
        nodeStatementAssign->addNode(nodeIdentifier);
        nextToken();
        nodeStatementAssign->addNode(index());
        if(currentToken->getType() == Assign) {
            nextToken();
        } else {
            error();
        }
        nodeStatementAssign->addNode(exp());
        return nodeStatementAssign;
    }

    NodeIndex* ParseTree::index() {
        switch (this->currentType->getType()) {
            case OpenBracket:
                nextToken();
                NodeIndex *nodeIndex = new NodeIndex();
                nodeIndex->addNode(exp());
                if(currentToken->getType() == CloseBracket) {
                    nextToken();
                } else {
                    error();
                }
                return nodeIndex;
            case IntToken:
            case OpenParenthesis:
            case OpenBrace:
            case ReadToken:
            case WriteToken:
            case IfToken:
            case WhileToken:
            case Plus:
            case Minus:
            case Multiply:
            case Smaller:
            case Greater:
            case Colon:
            case EqualAssign:
            case Equal:
            case ExclamationMark:
            case AndOP:
            case Integer:
            case Identifier:
                return nullptr;
            default:
                error();
        }
    }


    NodeExp* ParseTree::exp() {
        switch(currentToken->getType()) {
            case OpenParenthesis:
            case Minus:
            case ExclamationMark:
            case Integer:
            case Identifier:
                NodeExp *nodeExp = new NodeExp();
                nodeExp->addNode(exp2());
                nodeExp->addNode(opExp());
            default:
                error();
        }
    }

    NodeExp2* ParseTree::exp2(){
        switch(currentToken->getType()) {
            case OpenParenthesis:
                nextToken();
                NodeExp2Parenthesis *nodeExp2Parenthesis = new NodeExp2Parenthesis();
                nodeExp2Parenthesis->addNode(exp());
                if(currentToken->getType() == CloseParenthesis) {
                    nextToken();
                } else {
                    error();
                }
                return nodeExp2Parenthesis;
            case Minus:
                nextToken();
                NodeExp2Minus *nodeExp2Minus = new NodeExp2Minus();
                nodeExp2Minus->addNode(exp2());
                return nodeExp2Minus;
            case ExclamationMark:
                nextToken();
                NodeExp2Exclamation *nodeExp2Exclamation = new NodeExp2Exclamation();
                nodeExp2Exclamation->addNode(exp2());
                return nodeExp2Exclamation;
            case Integer:
                NodeInteger *nodeInteger = new NodeInteger(currentToken);
                NodeExp2Integer *nodeExp2Integer = new NodeExp2Integer();
                nodeExp2Integer->addNode(nodeInteger);
                nextToken();
                return nodeExp2Integer;
            case Identifier:
                NodeExp2Identifier *nodeExp2Identifier = new NodeExp2Identifier();
                NodeIdentifier *nodeIdentifier = new NodeIdentifier(currentToken);
                nodeExp2Identifier->addNode(nodeIdentifier);
                nextToken();
                nodeExp2Identifier->addNode(index());
                return nodeExp2Identifier;
            default:
                error();
        }
    }

    NodeOpExp* ParseTree::opExp() {
        switch (this->currentType->getType()) {
            case Plus:
            case Minus:
            case Multiply:
            case Colon:
            case Smaller:
            case Greater:
            case EqualAssign:
            case Equal:
            case AndOP:
                NodeOpExp *nodeOpExp = new NodeOpExp();
                NodeOp *nodeOp = new NodeOp(currentToken);
                nodeOpExp->addNode(nodeOp);
                nextToken();
                nodeOpExp->addNode(exp());
                return nodeOpExp;
            case OpenBracket:
            case IntToken:
            case OpenParenthesis:
            case OpenBrace:
            case ReadToken:
            case WriteToken:
            case IfToken:
            case WhileToken:
            case ExclamationMark:
            case Integer:
            case Identifier:
                return nullptr;
            default:
                error();
        }
    }






}





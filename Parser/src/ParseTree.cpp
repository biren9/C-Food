#include "../includes/ParseTree.h"


ParseTree::ParseTree(Scanner *scanner) {
    this->scanner = scanner;
    this->currentToken = this->scanner->nextToken();
}

ParseTree::~ParseTree() {
    delete this->scanner;
}

NodeProg *ParseTree::parse() {
    this->progTree = prog();
    return progTree;
}

void ParseTree::nextToken() {
    if (this->currentToken->getType() != EOL) {
        this->currentToken = this->scanner->nextToken();
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
        case Identifier: {
            NodeProg *prog = new NodeProg();
            prog->addNode(decls());
            prog->addNode(statements());
            return prog;
        }
        case EOL:
            error("Prog Error: No code found");
            break;
        default:
            error("Prog Error");
    }
}





void ParseTree::error(std::string parseTreeError) {
    std::cerr << "ParseTree.cpp: " << parseTreeError << std::endl;
    std::cerr << " unexpected Token " << getName(this->currentToken->getType())
              << " Line: " << currentToken->getLine() << " Column: " << currentToken->getColumn()
              << std::endl;
    std::cerr << "stop" << std::endl;
    exit(EXIT_FAILURE);
}




NodeDecls* ParseTree::decls() {
    switch (this->currentToken->getType()) {
        case IntToken: {
            NodeDecls *nodeDecls = new NodeDecls();
            nodeDecls->addNode(decl());
            if (this->currentToken->getType() == Semicolon) {
                nextToken();
            } else {
                error("decls-Error: Expected ';' ");
            }
            nodeDecls->addNode(decls());
            return nodeDecls;
        }
        case ReadToken:
        case WriteToken:
        case OpenBrace:
        case IfToken:
        case WhileToken:
        case EOL:
        case Identifier: {
            return new NodeEpsilon(epsDecls);
        }
        default:
            error("decls-Error");
    }
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
        error("decl-Error: Expected Identifier");
    }
    return nodeDecl;
}

NodeArray* ParseTree::array() {
    switch (this->currentToken->getType()) {
        case OpenBracket: {
            NodeArray *nodeArray = new NodeArray();
            nextToken();
            if (currentToken->getType() == Integer) {
                NodeInteger *nodeInteger = new NodeInteger(currentToken);
                nodeArray->addInteger(nodeInteger);
                nextToken();
                if (currentToken->getType() == CloseBracket) {
                    nextToken();
                } else {
                    error("array-Error: Expected )");
                }
            } else {
                error("array-Error: Expected Integer");
            }
            return nodeArray;
        }
        case Identifier: {
            return new NodeEpsilon(epsArray);
        }
        default:
            error("Array-Error");
    }
}

    NodeStatements* ParseTree::statements() {
        switch (this->currentToken->getType()) {
            case WriteToken:
            case ReadToken:
            case OpenBrace:
            case IfToken:
            case WhileToken:
            case Identifier: {
                NodeStatements *nodeStatements = new NodeStatements();
                nodeStatements->addNode(statement());
                if (this->currentToken->getType() == Semicolon) {
                    nextToken();
                } else {
                    error("statements-Error: Expected ;");
                }
                nodeStatements->addNode(statements());
                return nodeStatements;
            }
            case EOL:
            case CloseBrace:
                return new NodeEpsilon(epsStatements);
            default:
                error("statements-Error");
        }
    }

    NodeStatement* ParseTree::statement() {
        switch (this->currentToken->getType()) {
            case Identifier: return statementAssign();
            case WhileToken: return statementWhile();
            case IfToken: return statementIf();
            case OpenBrace: return statementBlock();
            case ReadToken: return statementRead();
            case WriteToken: return statementWrite();
            default:
                error("statement-Error");
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
            error("Assign-Error: Expected :=");
        }
        nodeStatementAssign->addNode(exp());
        return nodeStatementAssign;
    }

    NodeIndex* ParseTree::index() {
        switch (this->currentToken->getType()) {
            case OpenBracket: {
                nextToken();
                NodeIndex *nodeIndex = new NodeIndex();
                nodeIndex->addNode(exp());
                if (currentToken->getType() == CloseBracket) {
                    nextToken();
                } else {
                    error("index-Error: Expected ]");
                }
                return nodeIndex;
            }
            case Semicolon:
            case CloseBracket:
            case CloseParenthesis:
            case Plus:
            case Minus:
            case Multiply:
            case Colon:
            case Smaller:
            case Greater:
            case Equal:
            case EqualAssign:
            case AndOP:
            case Assign:
            case ElseToken:
                return new NodeEpsilon(epsIndex);
            default:
                error("Index-error");
        }
    }


    NodeExp* ParseTree::exp() {
        switch(currentToken->getType()) {
            case OpenParenthesis:
            case Minus:
            case ExclamationMark:
            case Integer:
            case Identifier: {
                NodeExp *nodeExp = new NodeExp();
                nodeExp->addNode(exp2());
                nodeExp->addNode(opExp());
                return nodeExp;
            }
            default:
                error("exp-Error");
        }
    }

    NodeExp2* ParseTree::exp2(){
        switch(currentToken->getType()) {
            case OpenParenthesis: {
                nextToken();
                NodeExp2Parenthesis *nodeExp2Parenthesis = new NodeExp2Parenthesis();
                nodeExp2Parenthesis->addNode(exp());
                if (currentToken->getType() == CloseParenthesis) {
                    nextToken();
                } else {
                    error("exp2-Error: expected )");
                }
                return nodeExp2Parenthesis;
            }
            case Minus: {
                nextToken();
                NodeExp2Minus *nodeExp2Minus = new NodeExp2Minus();
                nodeExp2Minus->addNode(exp2());
                return nodeExp2Minus;
            }
            case ExclamationMark: {
                nextToken();
                NodeExp2Exclamation *nodeExp2Exclamation = new NodeExp2Exclamation();
                nodeExp2Exclamation->addNode(exp2());
                return nodeExp2Exclamation;
            }
            case Integer: {
                NodeInteger *nodeInteger = new NodeInteger(currentToken);
                NodeExp2Integer *nodeExp2Integer = new NodeExp2Integer();
                nodeExp2Integer->addNode(nodeInteger);
                nextToken();
                return nodeExp2Integer;
            }
            case Identifier: {
                NodeExp2Identifier *nodeExp2Identifier = new NodeExp2Identifier();
                NodeIdentifier *nodeIdentifier = new NodeIdentifier(currentToken);
                nodeExp2Identifier->addNode(nodeIdentifier);
                nextToken();
                nodeExp2Identifier->addNode(index());
                return nodeExp2Identifier;
            }
            default:
                error("exp2-Error");
        }
    }

    NodeOpExp* ParseTree::opExp() {
        switch (this->currentToken->getType()) {
            case Plus:
            case Minus:
            case Multiply:
            case Colon:
            case Smaller:
            case Greater:
            case EqualAssign:
            case Equal:
            case AndOP: {
                NodeOpExp *nodeOpExp = new NodeOpExp();
                NodeOp *nodeOp = new NodeOp(currentToken);
                nodeOpExp->addNode(nodeOp);
                nextToken();
                nodeOpExp->addNode(exp());
                return nodeOpExp;
            }
            case Semicolon:
            case CloseBracket:
            case CloseParenthesis:
            case ElseToken:
                return new NodeEpsilon(epsOpExp);
            default:
                error("OpExp-Error");
        }
    }

NodeStatementWhile *ParseTree::statementWhile() {
        nextToken();
        NodeStatementWhile *statementWhile = new NodeStatementWhile();
        if(this->currentToken->getType() == OpenParenthesis) {
            nextToken();
        } else {
            error("while-Error: Expected (");
        }
        statementWhile->addNode(exp());
        if(this->currentToken->getType() == CloseParenthesis) {
            nextToken();
        } else {
            error("while-Error: Expected )");
        }

        statementWhile->addNode(statement());
        return statementWhile;
    }

    NodeStatementIf* ParseTree::statementIf() {
        nextToken();
        NodeStatementIf *nodeStatementIf = new NodeStatementIf();
        if(this->currentToken->getType() == OpenParenthesis) {
            nextToken();
        } else {
            error("if-Error: Expected (");
        }

        nodeStatementIf->addNode(exp());

        if(this->currentToken->getType() == CloseParenthesis) {
            nextToken();
        } else {
            error("if-Error: Expected )");
        }
        nodeStatementIf->addNodeIf(statement());

        if(this->currentToken->getType() == ElseToken) {
            nextToken();
        } else {
            error("if-Error: Expected else");
        }

        nodeStatementIf->addNodeElse(statement());

        return nodeStatementIf;
    }

    NodeStatementBlock* ParseTree::statementBlock() {
        nextToken();
        NodeStatementBlock *nodeStatementBlock = new NodeStatementBlock();
        nodeStatementBlock->addNode(statements());

        if(this->currentToken->getType() == CloseBrace) {
            nextToken();
        } else {
            error("Block-Error: Expected }");
        }

        return nodeStatementBlock;

    }

    NodeStatementRead* ParseTree::statementRead() {
        NodeStatementRead *nodeStatementRead = new NodeStatementRead();
        nextToken();
        if(this->currentToken->getType() == OpenParenthesis) {
            nextToken();
        } else {
            error("Read-Error: Expected (");
        }

        if(this->currentToken->getType() == Identifier) {
            NodeIdentifier *nodeIdentifier = new NodeIdentifier(this->currentToken);
            nodeStatementRead->addNode(nodeIdentifier);
            nextToken();
        } else {
            error("Read-Error: Expected Identifier");
        }

        nodeStatementRead->addNode(index());

        if(this->currentToken->getType() == CloseParenthesis) {
            nextToken();
        } else {
            error("Read-Error: Expected )");
        }

        return nodeStatementRead;
    }

    NodeStatementWrite* ParseTree::statementWrite() {
        nextToken();
        NodeStatementWrite *nodeStatementWrite = new NodeStatementWrite();

        if(this->currentToken->getType() == OpenParenthesis) {
            nextToken();
        } else {
            error("Write-Error: Expected (");
        }

        nodeStatementWrite->addNode(exp());

        if(this->currentToken->getType() == CloseParenthesis) {
            nextToken();
        } else {
            error("Write-Error: Expected )");
        }

        return nodeStatementWrite;
    }


    std::string ParseTree::getName(TokenType type) {
        switch(type) {
            case Identifier:
                return "Identifier      ";
            case Assign:
                return "Assign         ";
            case Plus:
                return "Plus           ";
            case Integer:
                return  "Integer        ";
            case Semicolon:
                return "Semicolon      ";
            case Undefined:
                return "Undefined      ";
            case Minus:
                return "Minus          ";
            case Colon:
                return "Colon          ";
            case Equal:
                return "Equal          ";
            case EqualAssign:
                return "EqualAssign    ";
            case Comment:
                return "Comment        ";
            case Multiply:
                return "Multiply       ";
            case Bang:
                return "Bang           ";
            case ExclamationMark:
                return "ExclamationMark";
            case AndOP:
                return "AndOP          ";
            case Greater:
                return "Greater        ";
            case Smaller:
                return "Smaller        ";
            case OpenParenthesis:
                return "OpenParenthesis";
            case CloseParenthesis:
                return "CloseParenthesis";
            case OpenBracket:
                return "OpenBrackets   ";
            case CloseBracket:
                return "CloseBracket   ";
            case OpenBrace:
                return "OpenBrace      ";
            case CloseBrace:
                return "CloseBrace     ";
            case WhileToken:
                return "While          ";
            case IfToken:
                return "If             ";
            case ElseToken:
                return "Else           ";
            case ReadToken:
                return "Read           ";
            case WriteToken:
                return "Write          ";
            case IntToken:
                return "Int            ";
            case EOL:
                return "End File       ";
            default:
                return "               ";
        }
    }

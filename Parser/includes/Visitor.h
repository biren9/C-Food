
#ifndef PARSER_INCLUDES_PARSETREEVISITOR_H_
#define PARSER_INCLUDES_PARSETREEVISITOR_H_
class ParseTree;
class Node;
class NodeProg;
class NodeArray;
class NodeDecl;
class NodeDecls;
class NodeEpsilon;
class NodeExp;
class NodeExp2;
class NodeExp2Bracket;
class NodeExp2Exclamation;
class NodeExp2Identifier;
class NodeExp2Integer;
class NodeExp2Minus;
class NodeIdentifier;
class NodeIndex;
class NodeInteger;
class NodeOp;
class NodeOpExp;
class NodeStatement;
class NodeStatementAssign;
class NodeStatementBlock;
class NodeStatementIf;
class NodeStatementRead;
class NodeStatementWhile;
class NodeStatementWrite;
class NodeStatements;
class NodeOpExp;

/**
 * Abstrakte Basisklasse des Besuchers.
 * Alle Besucher müssen diese Klasse implementieren, um durch den Baum zu traversieren.
 * Mit der Methode "visitNode()" wird der entsprechende Knoten besucht, auf dem Operationen durchgeführt werden können.
 */
class Visitor {
public:
    virtual ~Visitor() {}
    virtual void visitNode(Node* node) = 0;
    virtual void visitNode(NodeProg* node) = 0;
    virtual void visitNode(NodeArray* node) = 0;
    virtual void visitNode(NodeDecl* node) = 0;
    virtual void visitNode(NodeDecls* node) = 0;
    virtual void visitNode(NodeEpsilon* node) = 0;
    virtual void visitNode(NodeExp* node) = 0;
    virtual void visitNode(NodeExp2* node) = 0;
    virtual void visitNode(NodeExp2Bracket* node) = 0;
    virtual void visitNode(NodeExp2Exclamation* node) = 0;
    virtual void visitNode(NodeExp2Identifier* node) = 0;
    virtual void visitNode(NodeExp2Integer* node) = 0;
    virtual void visitNode(NodeExp2Minus* node) = 0;
    virtual void visitNode(NodeIdentifier* node) = 0;
    virtual void visitNode(NodeIndex* node) = 0;
    virtual void visitNode(NodeInteger* node) = 0;
    virtual void visitNode(NodeOp* node) = 0;
    virtual void visitNode(NodeOpExp* node) = 0;
    virtual void visitNode(NodeStatement* node) = 0;
    virtual void visitNode(NodeStatementAssign* node) = 0;
    virtual void visitNode(NodeStatementBlock* node) = 0;
    virtual void visitNode(NodeStatementIf* node) = 0;
    virtual void visitNode(NodeStatementRead* node) = 0;
    virtual void visitNode(NodeStatementWhile* node) = 0;
    virtual void visitNode(NodeStatementWrite* node) = 0;
    virtual void visitNode(NodeStatements* node) = 0;
};


#endif /* PARSER_INCLUDES_PARSETREEVISITOR_H_ */

cmake_minimum_required(VERSION 3.7)
project(C_Food)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Automat/includes/Automat.h
        Automat/src/Automat.cpp
        Buffer/includes/Buffer.h
        Buffer/src/Buffer.cpp
        Parser/includes/Nodes/NodeArray.h
        Parser/includes/Nodes/NodeDecl.h
        Parser/includes/Nodes/NodeDecls.h
        Parser/includes/Nodes/NodeEpsilon.h
        Parser/includes/Nodes/NodeExp.h
        Parser/includes/Nodes/NodeExp2.h
        Parser/includes/Nodes/NodeExp2Exclamation.h
        Parser/includes/Nodes/NodeExp2Identifier.h
        Parser/includes/Nodes/NodeExp2Integer.h
        Parser/includes/Nodes/NodeExp2Minus.h
        Parser/includes/Nodes/NodeExp2Parenthesis.h
        Parser/includes/Nodes/NodeIdentifier.h
        Parser/includes/Nodes/NodeIndex.h
        Parser/includes/Nodes/NodeInteger.h
        Parser/includes/Nodes/NodeOp.h
        Parser/includes/Nodes/NodeOpExp.h
        Parser/includes/Nodes/NodeProg.h
        Parser/includes/Nodes/NodeStatement.h
        Parser/includes/Nodes/NodeStatementAssign.h
        Parser/includes/Nodes/NodeStatementBlock.h
        Parser/includes/Nodes/NodeStatementIf.h
        Parser/includes/Nodes/NodeStatementRead.h
        Parser/includes/Nodes/NodeStatements.h
        Parser/includes/Nodes/NodeStatementWhile.h
        Parser/includes/Nodes/NodeStatementWrite.h
        Parser/includes/Node.h
        Parser/includes/Parser.h
        Parser/includes/ParseTree.h
        Parser/includes/Visitor.h
        Parser/includes/VisitorMakeCode.h
        Parser/includes/VisitorTypeCheck.h
        Parser/src/Node.cpp
        Parser/src/ParseTree.cpp
        Parser/src/TestParser.cpp
        Parser/src/VisitorMakeCode.cpp
        Parser/src/VisitorTypeCheck.cpp
        Parser/src/Parser.cpp
        Scanner/includes/Scanner.h
        Scanner/includes/Token.h
        Scanner/src/Scanner.cpp
        Scanner/src/Token.cpp
        Symboltable/includes/InfoNode.h
        Symboltable/includes/Liste.h
        Symboltable/includes/StringTabelle.h
        Symboltable/includes/Symboltable.h
        Symboltable/src/Liste.cpp
        Symboltable/src/StringTabelle.cpp
        Symboltable/src/Symboltable.cpp)

add_executable(C_Food ${SOURCE_FILES})
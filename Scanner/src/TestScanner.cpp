#include "../includes/Scanner.h"
#include <iostream>


std::string getName(TokenType type) {
    switch(type) {
        case Identifier:
            return (char*)"Identifier      ";
        case Assign:
            return (char*) "Assign         ";
        case Plus:
            return (char*) "Plus           ";
        case Integer:
            return (char*) "Integer        ";
        case Semicolon:
            return (char*) "Semicolon      ";
        case Undefined:
            return (char*) "Undefined      ";
        case Minus:
            return (char*) "Minus          ";
        case Colon:
            return (char*) "Colon          ";
        case Equal:
            return (char*) "Equal          ";
        case EqualAssign:
            return (char*) "EqualAssign    ";
        case Comment:
            return (char*) "Comment        ";
        case Multiply:
            return (char*) "Multiply       ";
        case Bang:
            return (char*) "Bang           ";
        case ExclamationMark:
            return (char*) "ExclamationMark";
        case AndOP:
            return (char*) "AndOP          ";
        case Greater:
            return (char*) "Greater        ";
        case Smaller:
            return (char*) "Smaller        ";
        case OpenParenthesis:
            return (char*) "OpenParenthesis";
        case OpenBracket:
            return (char*) "OpenBrackets   ";
        case CloseBracket:
            return (char*) "CloseBracket   ";
        case OpenBrace:
            return (char*) "OpenBrace      ";
        case CloseBrace:
            return (char*) "CloseBrace     ";
        case WhileToken:
            return (char*) "While          ";
        case IfToken:
            return (char*) "If             ";
        case EOL:
            return (char*) "End File       ";
        default:
            return (char*)"                ";
    }
}

int main(int argc, char **argv) {


    Scanner *scanner = new Scanner("../TestFile/test1.txt");

    Token  *token = scanner->nextToken();
    while(token->getType() != EOL){
        std::cout << "Token " << getName(token->getType()) << "\tLine: " << token->getLine() << " Column: " << token->getColumn();

        if(token->getType() == 0) {
            std::cout << " \t" << " Lexem: "  << token->getTokenLiteral();
        }
        else if(token->getType() == 3) {
            std::cout << " \t" << " Value: "  << token->getTokenLiteral();
        }

        std::cout << std::endl;


        token = scanner->nextToken();
    }

    delete scanner;
}

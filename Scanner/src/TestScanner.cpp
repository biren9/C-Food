#include "../includes/Scanner.h"
#include <iostream>


std::string getName(TokenType type) {
    switch(type) {
        case Identifier:
            return "Identifier      ";
        case Assign:
            return  "Assign         ";
        case Plus:
            return  "Plus           ";
        case Integer:
            return  "Integer        ";
        case Semicolon:
            return  "Semicolon      ";
        case Undefined:
            return  "Undefined      ";
        case Minus:
            return  "Minus          ";
        case Colon:
            return  "Colon          ";
        case Equal:
            return  "Equal          ";
        case EqualAssign:
            return  "EqualAssign    ";
        case Comment:
            return  "Comment        ";
        case Multiply:
            return  "Multiply       ";
        case Bang:
            return  "Bang           ";
        case ExclamationMark:
            return  "ExclamationMark";
        case AndOP:
            return  "AndOP          ";
        case Greater:
            return  "Greater        ";
        case Smaller:
            return  "Smaller        ";
        case OpenParenthesis:
            return  "OpenParenthesis";
        case OpenBracket:
            return  "OpenBrackets   ";
        case CloseBracket:
            return  "CloseBracket   ";
        case OpenBrace:
            return  "OpenBrace      ";
        case CloseBrace:
            return  "CloseBrace     ";
        case WhileToken:
            return  "While          ";
        case IfToken:
            return  "If             ";
        case EOL:
            return  "End File       ";
        default:
            return "                ";
    }
}

int main(int argc, char **argv) {



    Scanner *scanner = new Scanner("../TestFile/test4.txt");

    Token  *token = scanner->nextToken();
    while(token->getType() != EOL){
        std::cout << "Token " << getName(token->getType()) << "\tLine: " << token->getLine() << " Column: " << token->getColumn() << "  " << "Value: "  << token->getTokenLiteral()<< std::endl;
        token = scanner->nextToken();
    }
}

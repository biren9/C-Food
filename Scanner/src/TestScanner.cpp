#include "../includes/Scanner.h"
#include <iostream>


void print(TokenType type) {
    std:: cout << "TokenType: ";
    switch(type) {
        case Identifier:
            std::cout << "Identifier" << std::endl;
            break;
        case Assign:
            std::cout << "Assign" << std::endl;
            break;
        case Plus:
            std::cout << "Plus" << std::endl;
            break;
        case Integer:
            std::cout << "Integer" << std::endl;
            break;
        case Semicolon:
            std::cout << "Semicolon" << std::endl;
            break;
        case Undefined:
            std::cout << "Undefined" << std::endl;
            break;
        case Minus:
            std::cout << "Minus" << std::endl;
            break;
        case Colon:
            std::cout << "Colon" << std::endl;
            break;
        case Equal:
            std::cout << "Equal" << std::endl;
            break;
        case EqualAssign:
            std::cout << "EqualAssign" << std::endl;
            break;
        case Comment:
            std::cout << "Comment" << std::endl;
            break;
        case Multiply:
            std::cout << "Multiply" << std::endl;
            break;
        case Bang:
            std::cout << "Bang" << std::endl;
            break;
        case ExclamationMark:
            std::cout << "ExclamationMark" << std::endl;
            break;
        case AndOP:
            std::cout << "AndOP" << std::endl;
            break;
        case Greater:
            std::cout << "Greater" << std::endl;
            break;
        case Smaller:
            std::cout << "Smaller" << std::endl;
            break;
        case OpenParenthesis:
            std::cout << "OpenParenthesis" << std::endl;
            break;
        case OpenBracket:
            std::cout << "OpenBrackets" << std::endl;
            break;
        case CloseBracket:
            std::cout << "CloseBracket" << std::endl;
            break;
        case OpenBrace:
            std::cout << "OpenBrace" << std::endl;
            break;
        case CloseBrace:
            std::cout << "CloseBrace" << std::endl;
            break;
        case WhileToken:
            std::cout << "While" << std::endl;
            break;
        case IfToken:
            std::cout << "If" << std::endl;
            break;
        case EOL:
            std::cout << "End File" << std::endl;
            break;
        default:
            break;
    }
}

int main(int argc, char **argv) {

	//Scanner* scanner;

	//scanner = new Scanner();


    Scanner *scanner = new Scanner("../TestFile/test4.txt");

    Token token = scanner->nextToken();
    while(token.getType() != EOL){
        print(token.getType());
        std::cout << "Line: " << token.getLine() << std::endl;
        std::cout << "Column: " << token.getColumn() << std::endl;
        token = scanner->nextToken();
    }



}

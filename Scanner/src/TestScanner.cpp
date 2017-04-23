#include "../includes/Scanner.h"
#include <iostream>


void print(TokenType type) {
    switch(type) {
        case Identifier:
            std::cout << "Identifier" << std::endl;
            break;
        case Assign:
            std::cout << "Test" << std::endl;
            break;
        case Plus:
            break;
        case Integer:
            break;
        case Semicolon:
            break;
        case Undefined:
            break;
        case Minus:
            break;
        case Colon:
            break;
        case Equal:
            break;
        case EqualAssign:
            break;
        case Comment:
            break;
        case Multiply:
            break;
        case Bang:
            break;
        case ExclamationMark:
            break;
        case AndOP:
            break;
        case Greater:
            break;
        case Smaller:
            break;
        case OpenParenthesis:
            break;
        case CloseParenthesis:
            break;
        case OpenBracket:
            break;
        case CloseBracket:
            break;
        case OpenBrace:
            break;
        case CloseBrace:
            break;
        case WhileToken:
            break;
        case IfToken:
            break;
        case EOL:
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
        std::cout << "TokenType: " << token.getType() << std::endl;
        std::cout << "Line: " << token.getLine() << std::endl;
        std::cout << "Column: " << token.getColumn() << std::endl;
        token = scanner->nextToken();
    }



}

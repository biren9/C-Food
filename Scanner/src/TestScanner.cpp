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


    Scanner *scanner = new Scanner("../TestFile/test2.txt");

    Token *token = NULL;

    token = scanner->nextToken();
    std::cout << "TokenType: " << token->getType() << std::endl;

    token = scanner->nextToken();
    std::cout << "TokenType: " <<token->getType() << std::endl;

    std::cout << static_cast<int>(token->getType()) << std::endl;
    while((token =scanner->nextToken()) != nullptr){
        std::cout << "TokenType: " << token->getType() << std::endl;
        std::cout << "Line: " << token->getLine() << std::endl;
        std::cout << "Column: " << token->getColumn() << std::endl;
    }

    TokenType typeToken1 = Assign;
    //print(typeToken1);

    std::cout << typeToken1 << std::endl;



}

std::ostream& operator<<(std::ostream& o, TokenType c)
{
    std::cout << static_cast<int>(c);
    return o;
}
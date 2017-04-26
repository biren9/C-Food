#include "../includes/Scanner.h"
#include <iostream>

/**
 * getName of TokenType
 */
std::string getName(TokenType type) {
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
        case EOL:
            return "End File       ";
        default:
            return "                ";
    }
}
/**
 * test the testFiles
 */
int main(int argc, char *argv[]) {

    try {
        Symboltable *symboltable = nullptr;
        Scanner *scanner = nullptr;
        for (int i = 1; i < argc; i++) {
            symboltable = new Symboltable();
            scanner = new Scanner(argv[i], symboltable);

            Token *token = scanner->nextToken();
            while (token->getType() != EOL) {
                std::cout << "Token " << getName(token->getType()) << "\tLine: " << token->getLine() << " Column: "
                          << token->getColumn() << "   ";

                if (token->getType() == Identifier) {
                    std::cout << "\t" << " Lexem: " << token->getTokenLiteral();
                } else if (token->getType() == Integer) {
                    std::cout << "\t" << " Value: " << token->getTokenLiteral();
                }

                std::cout << std::endl;
                delete token;
                token = scanner->nextToken();
            }
        }

        delete scanner;

    }
    catch (const char* msg) {
        std::cout << msg;
    }

    return 0;

}

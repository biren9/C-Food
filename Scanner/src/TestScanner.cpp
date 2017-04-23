#include "../includes/Scanner.h"
#include <iostream>
int main(int argc, char **argv) {

	//Scanner* scanner;

	//scanner = new Scanner();


    Scanner *scanner = new Scanner("../TestFile/test2.txt");

    Token *token = NULL;

    token = scanner->nextToken();
    std::cout << token->getType() << std::endl;
//    while((token =scanner->nextToken()) != nullptr){
//        std::cout << "TokenType: " << token->getType() << std::endl;
//        std::cout << "Line: " << token->getLine() << std::endl;
//        std::cout << "Column: " << token->getColumn() << std::endl;
//    }



}


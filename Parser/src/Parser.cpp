#include "../includes/Parser.h"

Parser::Parser(char *filename) {
    Symboltable *symboltable = new Symboltable();
    Scanner *scanner = new Scanner(filename, symboltable);
    this->parseTree = new ParseTree(scanner);
}

NodeProg *Parser::createTree() {
    return this->parseTree->parse();
}

int main(int argc, char *argv[]) {
    Parser *parser = new Parser(argv[1]);
    NodeProg *prog = parser->createTree();
    std::cout << "Success!";
}
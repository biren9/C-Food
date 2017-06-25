#include "../includes/Parser.h"
#include "../includes/VisitorTypeCheck.h"
#include "../includes/VisitorMakeCode.h"

Parser::Parser(char *filename) {
    Symboltable *symboltable = new Symboltable();

    std::cout << "Scanner..." << std::endl;
    Scanner *scanner = new Scanner(filename, symboltable);
    this->parseTree = new ParseTree(scanner);
}

Parser::~Parser() {
    delete this->parseTree;
}

NodeProg *Parser::createTree() {
    return this->parseTree->parse();
}

int main(int argc, char *argv[]) {
    std::string outname = argv[2];
    outname.append(".code");
    char *cstr = &outname[0u];

    Parser *parser = new Parser(argv[1]);

    std::cout << "Parser..." << std::endl;
    NodeProg *prog = parser->createTree();

    std::cout << "Type check..." << std::endl;
    VisitorTypeCheck *tc = new VisitorTypeCheck();
    tc->typeCheck(prog);

    std::cout << "Make code..." << std::endl;
    VisitorMakeCode *mc = new VisitorMakeCode();
    mc->makeCode(prog, cstr);

    std::cout << "Success!" << std::endl;

    delete mc;
    delete tc;
    delete parser;
}
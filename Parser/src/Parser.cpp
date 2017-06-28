#include "../includes/Parser.h"
#include "../includes/VisitorTypeCheck.h"
#include "../includes/VisitorMakeCode.h"
#include <ctime>

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
    clock_t begin = clock();
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

    clock_t end = clock();
    double elapsed_secs = (double(end - begin) / CLOCKS_PER_SEC);

    std::cout << "Duration: " << elapsed_secs << " S" << std::endl;
    delete mc;
    delete tc;
    delete parser;
}
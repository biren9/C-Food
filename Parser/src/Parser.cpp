#include "../includes/Parser.h"
#include "../includes/VisitorTypeCheck.h"
#include "../includes/VisitorMakeCode.h"

Parser::Parser(char *filename) {
    Symboltable *symboltable = new Symboltable();

    std::cout << "Scanner..." << std::endl;
    Scanner *scanner = new Scanner(filename, symboltable);
    this->parseTree = new ParseTree(scanner);
}

void Parser::startThread() {
    this->parseTree->startThread();
}

Parser::~Parser() {
    std::cout << "Parser Dekonstruktor" << std::endl;
    delete this->parseTree;
}

NodeProg *Parser::createTree() {
    return this->parseTree->parse();
}

void testThread1() {
    std::cout << "testThread" << std::endl;
}

int main(int argc, char *argv[]) {
    std::string outname = argv[2];
    outname.append(".code");
    char *cstr = &outname[0u];

    Parser *parser = new Parser(argv[1]);
    //std::thread t1(testThread1);
    parser->startThread();

    for(int i = 0; i < 1000000; i++ ){

    }

    std::cout << "Parser..." << std::endl;
    NodeProg *prog = parser->createTree();
//
//    std::cout << "Type check..." << std::endl;
//    VisitorTypeCheck *tc = new VisitorTypeCheck();
//    tc->typeCheck(prog);
//
//    std::cout << "Make code..." << std::endl;
//    VisitorMakeCode *mc = new VisitorMakeCode();
//    mc->makeCode(prog, cstr);
////
//    std::cout << "Success!" << std::endl;


    //t1.join();
//    delete mc;
//    delete tc;
    delete parser;
    return 0;
}
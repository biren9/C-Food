#ifndef PARSER_CLASS_
#define PARSER_CLASS_

#include "ParseTree.h"


class Parser {
public:
    Parser(char *filename);

    ~Parser();

    NodeProg *createTree();
    void startThread();

private:
    ParseTree *parseTree;

};

#endif
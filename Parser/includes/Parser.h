#ifndef PARSER_CLASS_
#define PARSER_CLASS_

#include "ParseTree.h"


class Parser {
public:
    Parser(char *filename);

    NodeProg *createTree();

private:
    ParseTree *parseTree;

};

#endif
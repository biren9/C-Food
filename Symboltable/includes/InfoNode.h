//
// Created by ninja on 17.04.2017.
//

#ifndef TESTPROJECT_INFONODE_H
#define TESTPROJECT_INFONODE_H
class StringTabelle;
struct InfoNode {
	StringTabelle* strTabelle;
	unsigned int Index;
    InfoNode *prev;
    InfoNode *next;
};
#endif //TESTPROJECT_INFONODE_H

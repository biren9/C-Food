//
// Created by ninja on 17.04.2017.
//

#ifndef TESTPROJECT_INFONODE_H
#define TESTPROJECT_INFONODE_H
struct InfoNode {
    char *stringTablePointer;
    InfoNode *prev;
    InfoNode *next;
};
#endif //TESTPROJECT_INFONODE_H

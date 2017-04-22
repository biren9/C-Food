//
// Created by ninja on 17.04.2017.
//

#include <iostream>
#include <cstring>
#ifndef TESTPROJECT_STRINGTABELLE_H
#define TESTPROJECT_STRINGTABELLE_H
constexpr unsigned int TABLE_START_SIZE = 10;

class StringTabelle {

public:
    StringTabelle();
    ~StringTabelle();
    char* insert(char* lexem);
    void debugPrintStringTable();
private:
    unsigned int size = TABLE_START_SIZE;
    unsigned int freePlace = TABLE_START_SIZE - 1;
    unsigned int freeSpotIndex = 0;
    char* stringArr;
    void updateFreePlace();

};


#endif //TESTPROJECT_STRINGTABELLE_H

//
// Created by ninja on 17.04.2017.
//


#ifndef TESTPROJECT_STRINGTABELLE_H
#define TESTPROJECT_STRINGTABELLE_H
constexpr unsigned int TABLE_START_SIZE = 10;

#include <iostream>
#include <cstring>
#include "../includes/Liste.h"

class StringTabelle {

public:
    StringTabelle();
    ~StringTabelle();
    unsigned int insert(const char* lexem);
    void debugPrintStringTable();
	char* stringArr;
private:
    unsigned int size = TABLE_START_SIZE;
    unsigned int freePlace = TABLE_START_SIZE - 1;
    unsigned int freeSpotIndex = 0;
    
    void updateFreePlace();

};


#endif //TESTPROJECT_STRINGTABELLE_H

//
// Created by ninja on 17.04.2017.
//
#include "../includes/StringTabelle.h"

StringTabelle::StringTabelle() {
    stringArr = new char[size];
}

StringTabelle::~StringTabelle() {
    delete[] stringArr;
}
//inserts lexem if  enough place in StringTable, otherwise create new dynamic array twice the size of the old Array.
unsigned int StringTabelle::insert(const char* lexem) {
    if (freePlace > strlen(lexem)) {
        unsigned int beginning = freeSpotIndex;
        for (unsigned int i = 0; lexem[i] != '\0'; ++i) {
            stringArr[freeSpotIndex++] = lexem[i];
        }
        stringArr[freeSpotIndex++] = '\0';
        updateFreePlace();
        return beginning;
    }
    else {
        unsigned int oldSize = size;
        size *= 2;
       char *newArr = new char[size];
        memcpy(newArr, stringArr, oldSize);
        delete[] stringArr;
        stringArr = newArr;
        updateFreePlace();
        return insert(lexem);
    }
}
//recompute free place in the Stringtable array
void StringTabelle::updateFreePlace() {
    freePlace = size -1 - freeSpotIndex;
}
//debug function printing the Stringtable with empty space.
void StringTabelle::debugPrintStringTable() {
    for (unsigned int j = 0; j < size; j++)
        std::cout << stringArr[j];

}
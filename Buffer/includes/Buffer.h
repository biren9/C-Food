/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <fstream>
#include <iostream>
#include <cstring>

class Buffer {
    public:
	    Buffer(const char*);
	    virtual ~Buffer();

	    char getNextChar();
        char getCurrentChar();
	    bool ungetChar();

        unsigned int getCol();
        unsigned int getRow();

    private:
        bool open(const char*);
	    bool read();
        void close();

        static constexpr unsigned int BUFFER_BLOCK = 1024;

        char buffCur[BUFFER_BLOCK]{};
        char buffPrev[BUFFER_BLOCK]{};
        char* prevChar;

        unsigned int currentChar;
        unsigned int rowCount;
        unsigned int colCount;
		unsigned int lastCol;

        bool isArraySwap;

        std::ifstream in;
};

#endif /* BUFFER_H_ */

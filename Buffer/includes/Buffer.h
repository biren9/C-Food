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

class Buffer {
    public:
	    Buffer(char*);
	    virtual ~Buffer();

	    char getChar();
	    bool ungetChar();

        unsigned int getRow();
        unsigned int getLine();

    private:
        bool open(char*);
	    bool read();
        void close();
        void debug(std::string);

        static const unsigned int BUFFER_BLOCK = 1024;

        char* buffCur;
        char* buffPrev;

        unsigned int currentChar;
        unsigned int rowCount;
        unsigned int lineCount;

        bool isArraySwap;

        std::ifstream in;
};

#endif /* BUFFER_H_ */

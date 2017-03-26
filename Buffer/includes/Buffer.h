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

    private:
        bool open(char*);
	    bool read();
        void close();
    void debug();

        static const unsigned int BUFFER_BLOCK = 5;

        char* buffCur;
        char* buffPrev;

        int currentChar;

        bool isArraySwitched;

        std::ifstream in;
};

#endif /* BUFFER_H_ */

/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"

using namespace std;

Buffer::Buffer(char* filename) {

    this->currentChar = 0;

    this->open(filename);

    this->read();
}

Buffer::~Buffer() {
	//delete [] this->buffCur;
    this->close();
}

bool Buffer::open(char* filename) {
    this->in.open(filename, ios::in | ios::binary);
    if (!this->in) {
        cout << "Cannot open file.\n";
        return false;
    }

    return true;
}

void Buffer::close() {
    this->in.close();
}

bool Buffer::read() {
    char ch;
    int i = 0;

    while(i <= Buffer::BUFFER_BLOCK) {

        if(this->in.get(ch)) {  // in will be false when eof is reached
            this->buffCur[i] = ch;
        }
        else {
            this->buffCur[i] = '\0';
            return false;
        }

        ++i;
    }


    return true;
}

char Buffer::getChar() {


    //buffer
    if(this->currentChar > Buffer::BUFFER_BLOCK) {
        memcpy(buffPrev, buffCur, Buffer::BUFFER_BLOCK);
        this->read();
        this->currentChar = 0;
    }

    char ret = this->buffCur[this->currentChar];
    if(this->buffCur[this->currentChar] != '\0') this->currentChar += 1;
    cout << "Get " << this->currentChar-1 << "->"<< ret << endl;
    return ret;
}

//BUG: after the last possible unget operation -> stuck in a loop throw array
bool Buffer::ungetChar() {
    this->currentChar -= 1;

    if(this->currentChar < 0) {
        memcpy(buffCur, buffPrev, Buffer::BUFFER_BLOCK);
        this->currentChar = BUFFER_BLOCK;
    }

    cout << "Unget " << this->currentChar << "->"<< this->buffCur[this->currentChar] << endl;
    return 0;
}
/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"

using namespace std;

Buffer::Buffer(char* filename) {

    this->buffCur = new char[BUFFER_BLOCK];
    this->buffPrev = new char[BUFFER_BLOCK];
    this->currentChar = 0;
    this->isArraySwitched = false;


    this->open(filename);

    this->read();
}

Buffer::~Buffer() {
	delete [] this->buffCur;
    delete [] this->buffPrev;
    this->close();

    //cout << sizeof(this->currentChar) << endl << BUFFER_BLOCK;
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

    while(i < Buffer::BUFFER_BLOCK) {

        if(this->in.get(ch)) {  // in will be false when eof is reached
            this->buffCur[i] = ch;
        }
        else {
            this->buffCur[i] = '\0';
            cout << endl << "EOD" << this->buffCur[this->currentChar] << endl;
            //return false;
        }

        ++i;
    }

    return true;
}

char Buffer::getChar() {

    //buffer
    if(this->currentChar >= Buffer::BUFFER_BLOCK) {

        this->currentChar = 0;

        if(this->isArraySwitched) {
            this->isArraySwitched = false;
            char* tmp = this->buffCur;
            this->buffCur = this->buffPrev;
            this->buffPrev = tmp;
        }
        else {
            memcpy(this->buffPrev, this->buffCur, BUFFER_BLOCK);
            this->read();
        }
        debug();
    }


    char ret = this->buffCur[this->currentChar];

    cout << "Get: " << this->currentChar << "  ->"<< ret << endl;

    debug();
    if(this->buffCur[this->currentChar] != '\0') this->currentChar += 1;
    return ret;
}

//BUG: after the last possible unget operation -> stuck in a loop throw array
bool Buffer::ungetChar() {
    this->currentChar -= 1;

    if(this->currentChar < 0) {

        //swap arrays
        char* tmp = this->buffCur;
        this->buffCur = this->buffPrev;
        this->buffPrev = tmp;

        this->isArraySwitched = true;

        this->currentChar = BUFFER_BLOCK-1;
    }

    cout << "Unget: " << this->currentChar << " ->" << this->buffCur[this->currentChar] << endl;

    debug();
    return 0;
}


void Buffer::debug() {//
    cout << "           ";
    for (int i = 0; i <= BUFFER_BLOCK; ++i) {
        if(this->buffPrev[i] != '\n'){
            cout << "{" << this->buffPrev[i] << "} ";
        }
        else {
            cout << "{" << "\\n" << "} ";
        }
    }

    cout << endl;
    cout << "           ";
    for (int i = 0; i <= BUFFER_BLOCK; ++i) {
        if(this->buffCur[i] != '\n'){
            cout << "{" << this->buffCur[i] << "} ";
        }
        else {
            cout << "{" << "\\n" << "} ";
        }
    }
    cout << endl;
}
/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"

using namespace std;


//Constructor
Buffer::Buffer(char* filename) {

    //Init variables

    this->currentChar = 0;
    this->rowCount = 1;
    this->lineCount = 1;
    this->prevChar = nullptr;
    this->isArraySwap = false;

    //Open the file & buffer the first X Bytes
    try {
        this->open(filename);
    }
    catch(char* msg) {
        cout << msg;
    }

    this->read();
}


//Destructor
Buffer::~Buffer() {

    //Close the file
    this->close();
}


//Open the file & save the instance
bool Buffer::open(char* filename) {

    //Try to open the file. Should throw exception on error
    this->in.open(filename, ios::in | ios::binary);
    if (!this->in) {
        throw "Cannot open file.\n";
    }

    return true;
}


//Close the file
void Buffer::close() {

    //Close the instance
    this->in.close();
}


//Read the file & put it in the buffer array
bool Buffer::read() {

    //overwrite buffer with NULL
    fill_n(this->buffCur, BUFFER_BLOCK, '\0');

    //Fill the buffer
    this->in.read(this->buffCur, BUFFER_BLOCK);

    return true;
}


//Public method: get next char -> buffer
char Buffer::getChar() {

    //If end of file is reached -> do not change pointer & line count
    if(this->prevChar != nullptr && *this->prevChar != '\0') {

        this->rowCount += 1;

        //Update row & line count
        //cout << endl << *(this->prevChar) << endl;
        if(*this->prevChar == '\n') {
            this->lineCount += 1;
            this->rowCount = 1;
        }

        this->currentChar += 1;
    }

    //Current char pointer -> end of array
    if(this->currentChar >= BUFFER_BLOCK) {

        //Set char pointer -> first element
        this->currentChar = 0;

        //Swap back
        if(this->isArraySwap) {

            //Swap
            swap(this->buffCur, buffPrev);
            this->isArraySwap = false;
        }
        else {

            //Copy every element to the previous array
            memcpy(buffPrev, this->buffCur, BUFFER_BLOCK);

            //Buffer new chars
            this->read();
        }
    }

    this->prevChar = &(this->buffCur[this->currentChar]);
    return this->buffCur[this->currentChar];
}


//Public method: put char back -> buffer
bool Buffer::ungetChar() {

    if(this->buffCur[this->currentChar] == '\n') {
        //Row count is now
        //throw ?
        throw "You cannot go back over a \\n";

    }

    //If Pointer is out of bounce
    if(this->currentChar == 0) {

        if(!this->isArraySwap) {
            //swap arrays
            swap(this->buffCur, buffPrev);

            //Set array swap flag to true
            this->isArraySwap = true;

            //Move Pointer to the right of the previous Array
            this->currentChar = BUFFER_BLOCK - 1;
        }
        else {
            throw "Buffer underflow! Increase the Buffer size!";
        }
    }
    else {

        //Move pointer to the left
        this->currentChar -= 1;
    }

    if(this->buffCur[this->currentChar] == '\n') this->lineCount -= 1;


    this->rowCount -= 1;

    this->prevChar = &(this->buffCur[this->currentChar]);

    return 0;
}


unsigned int Buffer::getRow() {

    return rowCount;
}


unsigned int Buffer::getLine() {

    return lineCount;
}
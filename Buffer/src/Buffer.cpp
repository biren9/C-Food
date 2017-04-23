/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"

//Constructor
Buffer::Buffer(const char* filename) {

    //Init variables

    this->currentChar = 0;
    this->colCount = 1;
    this->rowCount = 1;
    this->lastCol = 0;
    this->prevChar = nullptr;
    this->isArraySwap = false;

    //Open the file & buffer the first X Bytes
    try {
        this->open(filename);
    }
    catch(const char* msg) {
        std::cout << std::endl << msg;
        return;
    }

    this->read();
}


//Destructor
Buffer::~Buffer() {

    //Close the file
    this->close();
}


//Open the file & save the instance
bool Buffer::open(const char* filename) {

    //Try to open the file. Should throw exception on error
    this->in.open(filename, std::ios::in | std::ios::binary);
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
    std::fill_n(this->buffCur, BUFFER_BLOCK, '\0');

    //Fill the buffer
    this->in.read(this->buffCur, BUFFER_BLOCK);

    return true;
}


//Public method: get next char -> buffer
char Buffer::getNextChar() {

    //If end of file OR First char of File -> do not change pointer & line count
    if(this->prevChar != nullptr && this->buffCur[this->currentChar] != '\0') {

        //Update row & line count
        this->lastCol = this->colCount;
        this->colCount += 1;

        if(this->buffCur[this->currentChar] == '\n') {
            this->rowCount += 1;
            this->colCount = 1;
        }
        this->prevChar = &(this->buffCur[this->currentChar]);
        this->currentChar += 1;
    }
    else this->prevChar = &(this->buffCur[this->currentChar]);

    //Current char pointer -> end of array
    if(this->currentChar >= BUFFER_BLOCK) {

        //Set char pointer -> first element
        this->currentChar = 0;

        //Swap back
        if(this->isArraySwap) {

            //Swap
            std::swap(this->buffCur, buffPrev);
            this->isArraySwap = false;
        }
        else {

            //Copy every element to the previous array
            std::memcpy(buffPrev, this->buffCur, BUFFER_BLOCK);

            //Buffer new chars
            this->read();
        }
    }

    return this->buffCur[this->currentChar];
}

char Buffer::getCurrentChar() {
    return this->buffCur[this->currentChar];
}

//Public method: put char back -> buffer
bool Buffer::ungetChar() {

    //Error handling
    if (this->prevChar == nullptr) throw "nope";
    //if(*this->prevChar == '\n') throw "You cannot go back over a \\n";


    //If Pointer is out of bounce
    if(this->currentChar == 0) {

        if(!this->isArraySwap) {

            //swap arrays & set to true
            std::swap(this->buffCur, buffPrev);
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

    if(this->buffCur[this->currentChar] == '\n') this->rowCount -= 1;


    if(*this->prevChar == '\n') this->colCount -= 1;
    else  this->colCount = this->lastCol;

    this->prevChar = &((this->currentChar == 0) ? this->buffPrev[BUFFER_BLOCK-1]: this->buffCur[this->currentChar-1]);

    return true;
}


unsigned int Buffer::getCol() {

    return colCount;
}


unsigned int Buffer::getRow() {

    return rowCount;
}
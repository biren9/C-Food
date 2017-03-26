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
    this->buffCur = new char[BUFFER_BLOCK];
    this->buffPrev = new char[BUFFER_BLOCK];
    this->currentChar = 0;
    this->isArraySwap = false;

    //Open the file & buffer the first X Bytes
    this->open(filename);
    this->read();
}

//Destructor
Buffer::~Buffer() {

    //Cleanup & free up memory
	delete [] this->buffCur;
    delete [] this->buffPrev;

    //Close the file
    this->close();
}

//Open the file & save the instance
bool Buffer::open(char* filename) {

    //Try to open the file. Should throw exception on error
    this->in.open(filename, ios::in | ios::binary);
    if (!this->in) {
        cout << "Cannot open file.\n";
        return false;
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

    //local variables
    char ch;
    int i = 0;

    //Iterate throw the array
    while(i < Buffer::BUFFER_BLOCK) {

        //in will be false when eof (\0) is reached
        if(this->in.get(ch)) {
            this->buffCur[i] = ch;
        }
        else {
            //Fill up the array
            this->buffCur[i] = '\0';

            //Debug Info
            cout << endl << "EOD" << this->buffCur[this->currentChar] << endl;
        }

        ++i;
    }

    return true;
}

//Public method: get next char -> buffer
char Buffer::getChar() {

    //Current char pointer -> end of array
    if(this->currentChar >= Buffer::BUFFER_BLOCK) {

        //Set char pointer -> first element
        this->currentChar = 0;

        //Swap back
        if(this->isArraySwap) {
            this->isArraySwap = false;

            //Swap
            char* tmp = this->buffCur;
            this->buffCur = this->buffPrev;
            this->buffPrev = tmp;
        }
        else {
            //Copy every element to the previous array
            memcpy(this->buffPrev, this->buffCur, BUFFER_BLOCK);

            //Buffer new chars
            this->read();
        }

        //Debug output
        debug();
    }

    //Return variable
    char ret = this->buffCur[this->currentChar];

    //Debug
    cout << "Get: " << this->currentChar << "  ->"<< ret << endl;
    debug();

    //If end of file is reached -> do not move the pointer
    if(this->buffCur[this->currentChar] != '\0') this->currentChar += 1;

    return ret;
}

//Public method: put char back -> buffer
bool Buffer::ungetChar() {

    //Move pointer to the left
    this->currentChar -= 1;

    //If Pointer is out of bounce
    if(this->currentChar < 0) {

        //swap arrays
        char* tmp = this->buffCur;
        this->buffCur = this->buffPrev;
        this->buffPrev = tmp;

        //Set array swap flag to true
        this->isArraySwap = true;

        //Move Pointer to the right of the previous Array
        this->currentChar = BUFFER_BLOCK-1;
    }

    //debug
    cout << "Unget: " << this->currentChar << " ->" << this->buffCur[this->currentChar] << endl;
    debug();

    return 0;
}


//Debug method
void Buffer::debug() {
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
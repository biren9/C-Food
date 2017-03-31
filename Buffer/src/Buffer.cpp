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
    this->rowCount = 1;
    this->lineCount = 1;

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

    //overwrite buffer with NULL
    fill_n(buffCur, BUFFER_BLOCK, '\0');

    //Fill the buffer
    this->in.read(buffCur, BUFFER_BLOCK);

    return true;
}

//Public method: get next char -> buffer
char Buffer::getChar() {

    //Current char pointer -> end of array
    if(this->currentChar >= BUFFER_BLOCK) {

        //Set char pointer -> first element
        this->currentChar = 0;

        //Swap back
        if(this->isArraySwap) {

            //Swap
            swap(this->buffCur, this->buffPrev);
            this->isArraySwap = false;
        }
        else {

            //Copy every element to the previous array
            memcpy(this->buffPrev, this->buffCur, BUFFER_BLOCK);

            //Buffer new chars
            this->read();
        }
    }

    debug("Get");
    char ret = this->buffCur[this->currentChar];

    //If end of file is reached -> do not change pointer & line count
    if(this->buffCur[this->currentChar] != '\0') {

        this->rowCount += 1;

        //Update row & line count
        if(this->buffCur[this->currentChar] == '\n') {
            this->lineCount += 1;
            this->rowCount = 1;
        }

        this->currentChar += 1;
    }

    return ret;
}

//Public method: put char back -> buffer
bool Buffer::ungetChar() {

    //If Pointer is out of bounce
    if(this->currentChar == 0) {

        //swap arrays
        swap(this->buffCur, this->buffPrev);

        //Set array swap flag to true
        this->isArraySwap = true;

        //Move Pointer to the right of the previous Array
        this->currentChar = BUFFER_BLOCK-1;
    }
    else {

        //Move pointer to the left
        this->currentChar -= 1;
    }

    this->rowCount -= 1;

    if(this->buffCur[this->currentChar] == '\n') {
        //Row count ?:/
        this->lineCount -= 1;
    }

    //debug
    debug("Unget ");

    return 0;
}


unsigned int Buffer::getRow() {

    return rowCount;
}

unsigned int Buffer::getLine() {

    return lineCount;
}


//Debug method
void Buffer::debug(string str) {
    string t = (this->buffCur[this->currentChar] == '\n') ? "\\n" : string(1, this->buffCur[this->currentChar]);
    cout << str << "\nLine:" << this->lineCount << " Row:" << this->rowCount << "\n  -> " << t << endl;
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
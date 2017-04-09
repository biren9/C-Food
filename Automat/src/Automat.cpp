/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"


Automat::Automat(Buffer* input) {
    bufferInput = input;
    startColumn = input->getCol();
    startLine = input->getRow();
    tokenLiteral = "";
    //currentTokenType = null;
    currentState = startState;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
    delete this;
}


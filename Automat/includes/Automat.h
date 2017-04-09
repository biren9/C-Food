/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_

#include "../C-Food/Buffer/includes/Buffer.h"
#include "../C-Food/Scanner/src/String.h"

class Automat {
public:
	Automat(Buffer* input);
	virtual ~Automat();

    enum state {
        startState , identifier, identifierType, number,
        equalSign, equalColon, colonSign, commentStart,
        commentEnd, andSign, endState
    };

    void nextToken();
    String getTokenLiteral();
    //tokenType getCurrentTokenType();
    int getStartLine();
    int getStartColumn();
    state getCurrentState();


private:
    Buffer* bufferInput;
    unsigned int startLine, startColumn;
    String tokenLiteral;
    //tokenType currentTokenType;
    state currentState;

    void transient(char currentChar);
    void startTransient(char currentChar);
    void identifierTransient(char currentChar);
    void identifierTypeTransient(char currentChar);
    void numberTransient(char currentChar);
    void equalSignTransient(char currentChar);
    void equalColonTransient(char currentChar);
    void colonSignTransient(char currentChar);
    void commentStartTransient(char currentChar);
    void commentEndTransiend(char currentChar);
    void andSignTransient(char currentChar);

};

#endif /* Automat_H_ */

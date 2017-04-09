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
	Automat(Buffer);
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
    unsigned int startLine, startColumn;
    String tokenLiteral;
    //tokenType currentTokenType;
    state currentState;

    void startTransient();
    void identifierTransient();
    void identifierTypeTransient();
    void numberTransient();
    void equalSignTransient();
    void equalColonTransient();
    void colonSignTransient();
    void commentStartTransient();
    void commentEndTransiend();
    void andSignTransient();

};

#endif /* Automat_H_ */

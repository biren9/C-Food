/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_

#include "../../Buffer/includes/Buffer.h"
#include "../../lib/String.h"
#include "../../lib/Token.h"


enum State {
    startState , identifier, number,
    equalSign, equalColon, colonSign, commentStart,
    commentEnd, andSign, endState
};

class Automat {
public:
	Automat(Buffer* input);
	virtual ~Automat();

    void nextToken();
    String getTokenLiteral();
    TokenType getCurrentTokenType();
    int getStartLine();
    int getStartColumn();
    State getCurrentState();


private:
    Buffer* bufferInput;
    unsigned int startLine, startColumn;
    String tokenLiteral;
    TokenType currentTokenType;
    State currentState;

    void transient(char currentChar);
    void startTransient(char currentChar);
    void identifierTransient(char currentChar);
    void identifierType();
    void numberTransient(char currentChar);
    void equalSignTransient(char currentChar);
    void equalColonTransient(char currentChar);
    void colonSignTransient(char currentChar);
    void commentStartTransient(char currentChar);
    void commentEndTransiend(char currentChar);
    void andSignTransient(char currentChar);

};

#endif /* Automat_H_ */

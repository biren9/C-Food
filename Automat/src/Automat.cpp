/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"


Automat::Automat(Buffer* input) {
    bufferInput = input;
    startColumn = bufferInput->getCol();
    startLine = input->getRow();
    tokenLiteral = "";
    currentTokenType = Undefined;
    currentState = startState;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}

/*
 * Setzt den Automaten zurueck und startet das Einlesen des naechsten Tokens
 * Ruft abhaengig vom Zustand die entsprechende Zustandsuebergangsfunktion auf
 */
void Automat::nextToken(){
    char currentChar;
    this->tokenLiteral = "";
    this->currentState = startState;
    while (this->currentState != endState) {
        currentChar = bufferInput->getNextChar();
        switch (this->currentState) {
            case startState :
                startTransient(currentChar);
                break;
            case identifier :
                identifierTransient(currentChar);
                break;
            case number :
                numberTransient(currentChar);
                break;
            case equalSign :
                equalSignTransient(currentChar);
                break;
            case equalColon :
                equalColonTransient(currentChar);
                break;
            case colonSign :
                colonSignTransient(currentChar);
                break;
            case commentStart :
                commentStartTransient(currentChar);
                break;
            case commentEnd :
                commentEndTransiend(currentChar);
                break;
            case andSign :
                andSignTransient(currentChar);
                break;
            default:
                break;
        }
    }
}

std::string Automat::getTokenLiteral() {
    return this->tokenLiteral;
}

TokenType Automat::getCurrentTokenType() {
    return this->currentTokenType;
}

int Automat::getStartLine() {
    return this->startLine;
}

int Automat::getStartColumn() {
    return this->startColumn;
}

State Automat::getCurrentState() {
    return this->currentState;
}

/*
 * Uebergangsfunktion des Startzustands
 * Token bestehend aus einem Zeichen werden direkt abgehandelt
 * fuer Token aus mehreren Zeichen wird der entsprechende Zustand angenommen
 * speichert die Positition des aktuellen neuen Tokens
 */
void Automat::startTransient(char currentChar){
    this->startColumn = bufferInput->getCol();
    this->startLine = bufferInput->getRow();
    this->currentTokenType = Undefined;
    if (currentChar >= '0' && currentChar <= '9'){
        this->currentState = number;
        this->tokenLiteral += currentChar;
    }
    else if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z')){
        this->currentState = identifier;
        this->tokenLiteral += currentChar;
    }
    else {
        switch (currentChar) {
            case  ' ': this->currentState = startState;
                break;
            case '\t' : this->currentState = startState;
                break;
            case '\n' : this->currentState = startState;
                break;
            case '+' : this->currentState = endState;
                this->tokenLiteral = "+";
                this->currentTokenType = Plus;
                break;
            case '-' : this->currentState = endState;
                this->tokenLiteral = "-";
                this->currentTokenType = Minus;
                break;
            case ':' : this->currentState = colonSign;
                this->tokenLiteral = ":";
                break;
            case '*' : this->currentState = endState;
                this->tokenLiteral = "*";
                this->currentTokenType = Multiply;
                break;
            case '<' : this->currentState = endState;
                this->tokenLiteral = "<";
                this->currentTokenType = Smaller;
                break;
            case '>' : this->currentState = endState;
                this->tokenLiteral = ">";
                this->currentTokenType = Greater;
                break;
            case '=' : this->currentState = equalSign;
                this->tokenLiteral = "=";
                break;
            case '!' : this->currentState = endState;
                this->tokenLiteral = "!";
                this->currentTokenType = ExclamationMark;
                break;
            case '&' : this->currentState = andSign;
                this->tokenLiteral = "&";
                break;
            case '(' : this->currentState = endState;
                this->tokenLiteral = "(";
                this->currentTokenType = OpenParenthesis;
                break;
            case ')' : this->currentState = endState;
                this->currentTokenType = CloseParenthesis;
                this->tokenLiteral = ")";
                break;
            case '[' : this->currentState = endState;
                this->currentTokenType = OpenBracket;
                this->tokenLiteral = "[";
                break;
            case ']' : this->currentState = endState;
                this->tokenLiteral = "]";
                this->currentTokenType = CloseBracket;
                break;
            case '{' : this->currentState = endState;
                this->tokenLiteral = "{";
                this->currentTokenType = OpenBrace;
                break;
            case '}' : this->currentState = endState;
                this->currentTokenType = CloseBrace;
                this->tokenLiteral = "}";
                break;
            case ';' : this->currentState = endState;
                this->tokenLiteral = ";";
                this->currentTokenType = Semicolon;
                break;
            case '\0' : this->currentState = endState;
                this->currentTokenType = EOL;
                break;
            default: this->currentState = endState;
                this->tokenLiteral += currentChar;
                this->currentTokenType = Undefined;
        }
    }
}

/*
 * Uebergangsfunktion fuer den Identifier-Zustand.
 */
void Automat::identifierTransient(char currentChar){
    if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z') || (currentChar >= '0' && currentChar <= '9')){
        this->currentState = identifier;
        this->tokenLiteral += currentChar;
    }
    /*else if (currentChar == '\n') {
        identifierType();
        this->currentState = endState;
    }*/
    else {
        identifierType();
        bufferInput->ungetChar();
        this->currentState = endState;
    }
}

/*
 * prueft Identifier-Token auf Schluesselworte
 */
void Automat::identifierType(){
    if ((this->tokenLiteral == "while") || (this->tokenLiteral == "WHILE")) {
        this->currentTokenType = WhileToken;
    }
    else if (((this->tokenLiteral == "if")) || (this->tokenLiteral == "IF")) {
        this->currentTokenType = IfToken;
    }
    else {
        this->currentTokenType = Identifier;
    }
}

/*
 * Ubergangsfunktion fuer Integer-Token
 */
void Automat::numberTransient(char currentChar){
    if (currentChar >= '0' && currentChar <= '9'){
        this->currentState = number;
        this->tokenLiteral += currentChar;
    }
    /*else if (currentChar == '\n') {
        this->currentTokenType = Integer;
        this->currentState = endState;
    }*/
    else {
        this->currentTokenType = Integer;
        this->currentState = endState;
        bufferInput->ungetChar();
    }
}
/*
 * Uebergangsfunktion fuer ein eingelesenes = Zeichen
 */
void Automat::equalSignTransient(char currentChar){
    if (currentChar == ':') {
        this->currentState = equalColon;
        this->tokenLiteral += currentChar;
    }
    /*else if (currentChar == '\n') {
        this->currentState = endState;
        this->currentTokenType = Equal;
    }*/
    else {
        this->currentState = endState;
        bufferInput->ungetChar();
        this->currentTokenType = Equal;
    }
}

/*
 * Uebergangsfunktion fuer ein eingelesenes =:
 */
void Automat::equalColonTransient(char currentChar){
    if (currentChar == '=') {
        this->currentTokenType = EqualAssign;
        this->tokenLiteral += currentChar;
    }
    /*else if (currentChar == '\n') {
        this->currentState = endState;
        this->currentTokenType = Undefined;
    }*/
    else {
        this->tokenLiteral = "=";
        bufferInput->ungetChar();
        bufferInput->ungetChar();
        this->currentTokenType = Equal;
    }
    this->currentState = endState;
}

/*
 * Uebergangsfunktion fuer ein eingelesenen :
 */
void Automat::colonSignTransient(char currentChar){
    switch (currentChar){
        case '=' : this->currentTokenType = Assign;
            this->currentState = endState;
            this->tokenLiteral += currentChar;
            break;
        case '*' : this->currentState = commentStart;
            this->tokenLiteral = "";
            break;
        /*case '\n' : this->currentState = endState;
            this->currentTokenType = Colon;
            break;*/
        default: this->currentState = endState;
            bufferInput->ungetChar();
            this->currentTokenType = Colon;
    }
}

/*
 * Uebergangsfunktion fuer Kommentare, die mit :* gestartet werden
 */
void Automat::commentStartTransient(char currentChar){
    if (currentChar == '*'){
        this->currentState = commentEnd;
    }
    else if (currentChar == '\0'){
        this->currentState = endState;
        this->currentTokenType = EOL;
        this->tokenLiteral = "";
    }
}

/*
 * Uebergangsfunktion falls in einem Kommentar * eingelesen wurde
 */
void Automat::commentEndTransiend(char currentChar){
    if (currentChar == ':') {
        this->currentState = startState;
    }
    else if (currentChar == '\0'){
        this->currentState = endState;
        this->currentTokenType = EOL;
        this->tokenLiteral = "";
    }
    else {
        this->currentState = commentStart;
    }
}

/*
 * Uebergangsfunktion fuer ein eingelesenes &
 */
void Automat::andSignTransient(char currentChar){
    if (currentChar == '&') {
        this->currentTokenType = AndOP;
        this->tokenLiteral += currentChar;
    }
    /*else if (currentChar == '\n') {
        this->currentTokenType = Undefined;
    }*/
    else {
        bufferInput->ungetChar();
        this->currentTokenType = Undefined;
    }
    this->currentState = endState;
}
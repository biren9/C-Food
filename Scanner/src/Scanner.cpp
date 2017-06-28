#include "../includes/Scanner.h"
#include <string>
#include <cerrno>
#include <cstdlib>

std::mutex g_lock;
/**
 * initialize
 */

void testThread() {
    std::cout << "testThread" << std::endl;
}

Scanner::Scanner(const char* file,Symboltable* symboltable) {
    this->buffer = new Buffer(file);
    this->automat = new Automat(buffer);
    this->symbolTable = new Symboltable();

    //std::thread t1(testThread);
    //this->buildTokensThread = &t1;
}


/**
 * get data from automat to create Token
 */
Token* Scanner::nextT() {
    automat->nextToken();
    std::string tokenLiteral = automat->getTokenLiteral();
    TokenType tokenType = automat->getCurrentTokenType();
    int startLine = automat->getStartLine();
    int startColumn = automat->getStartColumn();

    Token *token = new Token(tokenType,startColumn,startLine,tokenLiteral);

    InfoNode *key = nullptr;
    if(tokenType == Identifier) {
        key  = symbolTable->insert(tokenLiteral.c_str());
        token->setKey(key);
    } else if(tokenType == Integer) {
        char *p;
        int value1 = strtol(tokenLiteral.c_str(),&p,10);

        if(errno == ERANGE) {
            errno = 0;
            std::cout << "Error: " << "Value is out of range" << std::endl;
            token->setType(Undefined);
        } else {
            token->setValue(value1);
        }
    }
    return token;

}

void Scanner::addToken(Token *token) {
    g_lock.lock();
    tokenList.push_back(token);
    g_lock.unlock();
}

Token* Scanner::getToken() {
    g_lock.lock();
    Token *token = this->tokenList.front();
    this->tokenList.pop_front();
    g_lock.unlock();
    return token;
}



void Scanner::buildTokenList() {
    Token *token = nextT();
    std::cout << "buildTokenList" << std::endl;
    while (token->getType() != EOL) {

        if (token->getType() == Identifier) {
            std::cout << "\t" << " Lexem: " << token->getTokenLiteral();
        } else if (token->getType() == Integer) {
            std::cout << "\t" << " Value: " << token->getValue();
        }

        std::cout << std::endl;
        switch(token->getType()) {
            case Identifier:
            case Integer:
            case Greater:
            case Multiply:
            case Plus:
            case Minus:
            case Colon:
            case EqualAssign:
            case Equal:
            case ExclamationMark:
            case CloseParenthesis:
            case OpenParenthesis:
            case OpenBrace:
            case CloseBrace:
                break;
            default:
                delete token;
                break;
        }
        addToken(token);
        token = nextT();
    }
}

Token* Scanner::nextToken() {
    return getToken();
}

/**
 * delete heap
 */
Scanner::~Scanner() {
    std::cout << "Scanner Dek" << std::endl;
    this->buildTokensThread->join();
    delete this->buffer;
    delete this->automat;
    delete this->symbolTable;
}
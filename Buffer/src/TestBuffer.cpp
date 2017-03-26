#include "../includes/Buffer.h"
#include <iostream>


using namespace std;

int main(int argc, char **argv) {

	Buffer*  buffer;

	buffer = new Buffer(argv[1]);

    cout << endl << "------------------" << endl;

    for (int i = 0; i < 55; ++i) {
        buffer->getChar();
    }
cout << "----------------------\n";



    for (int i = 0; i < 7; ++i) {
        buffer->ungetChar();
    }

    for (int i = 0; i < 10; ++i) {
        buffer->getChar();
    }

    delete buffer;
    return  0;
}

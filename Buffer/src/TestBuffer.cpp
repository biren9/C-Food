#include "../includes/Buffer.h"
#include <iostream>



using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {

    high_resolution_clock::time_point begin = high_resolution_clock::now();

	Buffer*  buffer;
	buffer = new Buffer(argv[1]);


    string a;
    for (int i = 0; i < 46; ++i) {
         a = buffer->getChar();
        cout << "GET: " << ((a == "\n")?"\\n": a) << "   Line: " << buffer->getLine() << "    Row: "  << buffer->getRow() << endl;
    }
cout << "----------------------\n";



    for (int i = 0; i < 9; ++i) {
        try {
            cout << "Unget... " << endl;
            buffer->ungetChar();
            cout << "Unget... " << endl;
            buffer->ungetChar();
        }
        catch (const char* msg) {
            cout << endl << msg << endl;
        }
        a = buffer->getChar();
        cout << "GET: " << ((a == "\n")?"\\n": a) << "   Line: " << buffer->getLine() << "    Row: "  << buffer->getRow() << endl;
    }
/*
    for (int i = 0; i < 10; ++i) {
        buffer->getChar();
    }


    cout << endl << "--------" << endl;
    buffer->ungetChar();
    buffer->ungetChar();
    //buffer->ungetChar();
    //buffer->ungetChar();
    buffer->getChar();


    cout << "Line: " << buffer->getLine() << "Row: " << buffer->getRow() << endl;

    buffer->getChar();
    buffer->getChar();

    cout << "Line: " << buffer->getLine() << " Row: " << buffer->getRow() << endl;
*/
    delete buffer;

    high_resolution_clock::time_point end = high_resolution_clock::now();

    cout << endl << duration_cast<microseconds>( end - begin).count() / 1000.0 << "ms";

    return  0;
}

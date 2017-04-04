#include "../includes/Buffer.h"


using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {

    high_resolution_clock::time_point begin = high_resolution_clock::now();

	Buffer*  buffer;
	buffer = new Buffer("../TestFile/test2.txt");


    string a;
    for (int i = 0; i < 48; ++i) {
         a = buffer->getNextChar();
        cout << "GET: " << ((a == "\n")?"\\n": a) << "   Row: " << buffer->getRow() << "    Col: "  << buffer->getCol() << endl;
    }
cout << "----------------------\n";



    for (int i = 0; i < 20; ++i) {
        try {
            cout << "Unget... " << endl;
            buffer->ungetChar();
            cout << "Unget... " << endl;
            buffer->ungetChar();
        }
        catch (const char* msg) {
            cout << endl << msg << endl;
        }
        a = buffer->getCurrentChar();
        cout << "GET CUR: " << ((a == "\n")?"\\n": a) << "   Row: " << buffer->getRow() << "    Col: "  << buffer->getCol() << endl;

        a = buffer->getNextChar();
        cout << "GET NXT: " << ((a == "\n")?"\\n": a) << "   Row: " << buffer->getRow() << "    Col: "  << buffer->getCol() << endl;
    }


    delete buffer;

    high_resolution_clock::time_point end = high_resolution_clock::now();

    cout << endl << duration_cast<microseconds>( end - begin).count() / 1000.0 << "ms";

    return  0;
}

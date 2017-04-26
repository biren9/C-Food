#include <iostream>
#include "../includes/Liste.h"
#include "../includes/StringTabelle.h"
#include "../includes/Symboltable.h"
#include "../includes/InfoNode.h"
#include <cmath>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>

std::string generateRandomString(size_t length)
{
    const char* charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const size_t charmapLength = strlen(charmap);
    auto generator = [&](){ return charmap[rand()%charmapLength]; };
    std::string result;
    result.reserve(length);
    generate_n(back_inserter(result), length, generator);
    std:: cout << "Result: " << result << std::endl;
    return result;
}
int main() {
//	Symboltable symt;
//
//	InfoNode *testNode = nullptr;
//	std::string test = "Test";
//	std::string test2 = "Test";
//	symt.insert("Test");
//	symt.insert("Test2");
//	symt.insert("Test2");
//    symt.insert("Test");

    std::cout << "Symboltable HashCode Test" << std::endl;

    std::map<int,int> map; //<HashCode,Counter>
    Symboltable symboltable;
    for(int i = 0; i < 2000000; i++) {
        std::string randomStr = generateRandomString(10);

        //symboltable.insert(randoStr.);
        int hashCode = symboltable.hash(randomStr.c_str());

        if (map.find(hashCode) == map.end()) {
            // not found
            map[hashCode] = 0;
        } else {
            auto counterP = map.find(hashCode);
            map[hashCode] = counterP->second + 1;
        }

    }


        //Ausgabe
        std::vector<int> v;
        for(std::map<int,int>::iterator it = map.begin(); it != map.end(); ++it) {
            v.push_back(it->first);
            //std::cout << "Key: "<< it->first << "\n";
            //auto value = map.find(it->first);
            std::cout << "Value: "<< it->second << std::endl;
        }



	
//	InfoNode *testNode2 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode3 = symboltable.insert("nochEinTest");
//	InfoNode *testNode4 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode5 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode6 = symboltable.insert("philippMachtSchlechteMutterWitze");
	
//	std::cout << &(testNode2->strTabelle->stringArr[testNode2->Index]) << std::endl;
//	std::cout << &(testNode3->strTabelle-> stringArr[testNode3->Index]) << std::endl;
//
//
//	symboltable.stringTabelle->debugPrintStringTable();
//	getchar();

//	Symboltable symboltable;
//	InfoNode *testNode = symboltable.insert("testEingabe");
//	InfoNode *testNode2 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode3 = symboltable.insert("nochEinTest");
//	InfoNode *testNode4 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode5 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode6 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	std::cout << testNode->stringTablePointer << std::endl;
//	std::cout << testNode2->stringTablePointer << std::endl;
//	std::cout << testNode3->stringTablePointer << std::endl;
//	std::cout << testNode4->stringTablePointer << std::endl;
//	std::cout << testNode5->stringTablePointer << std::endl;
//	std::cout << testNode6->stringTablePointer << std::endl;
//
//	symboltable.stringTabelle->debugPrintStringTable();
	
	return 0;

}
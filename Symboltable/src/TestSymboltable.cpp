#include <iostream>
#include "../includes/Liste.h"
#include "../includes/StringTabelle.h"
#include "../includes/Symboltable.h"
#include "../includes/InfoNode.h"
#include "../../lib/String.h"

int main() {

	String test = "Test";
	Symboltable symboltable;
	InfoNode *testNode = symboltable.insert(test.getString());
//	InfoNode *testNode2 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode3 = symboltable.insert("nochEinTest");
//	InfoNode *testNode4 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode5 = symboltable.insert("philippMachtSchlechteMutterWitze");
//	InfoNode *testNode6 = symboltable.insert("philippMachtSchlechteMutterWitze");
	std::cout << &(testNode->strTabelle->stringArr[testNode->Index]) << std::endl;
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
//	getchar();
	return 0;

}
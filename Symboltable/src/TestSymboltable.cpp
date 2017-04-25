#include <iostream>
#include "../includes/Liste.h"
#include "../includes/StringTabelle.h"
#include "../includes/Symboltable.h"
#include "../includes/InfoNode.h"

int main() {
	Symboltable symt;

	//InfoNode *testNode = nullptr;
	std::string test = "Test";
	std::string test2 = "Test";
	symt.insert("Test");
	symt.insert("Test2");
	symt.insert("Test2");
    symt.insert("Test");
	
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
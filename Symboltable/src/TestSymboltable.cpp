#include <iostream>
#include "Liste.h"
#include "StringTabelle.h"
#include "Symboltable.h"
#include "InfoNode.h"

int main() {
	Symboltable symboltable;
	InfoNode *testNode = symboltable.insert("testEingabe");
	InfoNode *testNode2 = symboltable.insert("philippMachtSchlechteMutterWitze");
	InfoNode *testNode3 = symboltable.insert("nochEinTest");
	InfoNode *testNode4 = symboltable.insert("philippMachtSchlechteMutterWitze");
	InfoNode *testNode5 = symboltable.insert("philippMachtSchlechteMutterWitze");
	InfoNode *testNode6 = symboltable.insert("philippMachtSchlechteMutterWitze");
	std::cout << &(testNode->strTabelle->stringArr[testNode->Index]) << std::endl;
	std::cout << &(testNode2->strTabelle->stringArr[testNode2->Index]) << std::endl;
	std::cout << &(testNode3->strTabelle-> stringArr[testNode3->Index]) << std::endl;
	

	symboltable.stringTabelle->debugPrintStringTable();
	getchar();
	return 0;

}
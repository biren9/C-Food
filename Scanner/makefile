# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug


AUTOMATDIR = ../Automat

BUFFERDIR = ../Buffer

SYMBOLTABLEDIR = ../Symboltable


## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Scanner.o \
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o


## Variante mit wenig Makefile-Kenntnissen
# 
## linken der Object-files 
#makeTestScanner: $(OBJDIR)/Scanner.o $(OBJDIR)/TestScanner.o
#	g++ -std=c++11 -g $(OBJDIR)/Scanner.o $(OBJDIR)/TestScanner.o   $(PROJECTOBJDIR)/Automat/*.o $(PROJECTOBJDIR)/Buffer/*.o $(PROJECTOBJDIR)/Symboltable/*.o -o $(BINDIRTEST)/ScannerTest
##	
##	
##	
### compilieren der source-files
#$(OBJDIR)/Scanner.o :  $(SRCDIR)/Scanner.cpp $(HEADERDIR)/Scanner.h
#	@echo "g++ -std=c++11 $*.cpp"
#	g++ -std=c++11 -g  -c -Wall  -o $(OBJDIR)/Scanner.o  $(SRCDIR)/Scanner.cpp
#	cp $(OBJDIR)/Scanner.o $(PROJECTOBJDIR)/Scanner
##
#$(OBJDIR)/TestScanner.o :  $(SRCDIR)/TestScanner.cpp 
#	@echo "g++ -std=c++11 $*.cpp"
#	g++ -std=c++11 -g  -c -Wall  -o $(OBJDIR)/TestScanner.o  $(SRCDIR)/TestScanner.cpp
#
# Variante mit guten Makefile-Kenntnissen

makeTestScanner:  TokenTarget ScannerTarget ScannerTest


ScannerTest:  $(SRCDIR)/TestScanner.cpp $(HEADERDIR)/Scanner.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -Wall src/TestScanner.cpp -o $(OBJDIR)/TestScanner.o -pthread
	g++ -std=c++11 -g $(OBJDIR)/TestScanner.o $(OBJDIR)/Scanner.o $(OBJDIR)/Token.o ../Symboltable/$(OBJDIR)/StringTabelle.o ../Symboltable/$(OBJDIR)/Liste.o ../Symboltable/$(OBJDIR)/Symboltable.o  $(AUTOMATDIR)/$(OBJDIR)/Automat.o  $(BUFFERDIR)/$(OBJDIR)/Buffer.o -o $(BINDIRTEST)/ScannerTest -pthread

TokenTarget :  $(SRCDIR)/Token.cpp  $(HEADERDIR)/Token.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -Wall src/Token.cpp -o $(OBJDIR)/Token.o -pthread

ScannerTarget :  $(SRCDIR)/Scanner.cpp $(HEADERDIR)/Scanner.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -Wall src/Scanner.cpp -o $(OBJDIR)/Scanner.o -pthread

cleanCompileScanner:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) ScannerTest

cleanScanner:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*

## objs fuer GesamtProjekt neu erzeugen
ScannerOBJTarget:
	$(MAKE) makeTestScanner



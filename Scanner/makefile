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
makeTestScanner: $(OBJS) TokenTarget ScannerTest


$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
	@echo "g++ -std=c++11 $*.cpp"
	g++ -std=c++11 -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


ScannerTest: $(SRCDIR)/TestScanner.cpp $(HEADERDIR)/Scanner.h
	g++ -std=c++11 -g  -c -Wall src/TestScanner.cpp -o $(BINDIRTEST)/TestScanner.o
	g++ -std=c++11 -g $(BINDIRTEST)/TestScanner.o $(BINDIRTEST)/Token.o ../Symboltable/objs/StringTabelle.o ../Symboltable/objs/Liste.o ../Symboltable/objs/Symboltable.o    $(OBJDIR)/*.o $(AUTOMATDIR)/$(OBJDIR)/Automat.o $(AUTOMATDIR)/$(OBJDIR)/String.o $(BUFFERDIR)/$(OBJDIR)/*.o -o $(BINDIRTEST)/ScannerTest

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu erstellen

TokenTarget :  src/Token.cpp ../lib/Token.h
	g++ -std=c++11 -g  -c -Wall src/Token.cpp -o $(BINDIRTEST)/Token.o

cleanScanner:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeTestScanner



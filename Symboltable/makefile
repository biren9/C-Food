# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug


## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

LIB = ../lib
#
#		Targets zum Bauen des Tests
#

# Variante mit geringen Makefile-Kenntnissen

## Linken der Object-Files
#makeTestSymboltable: $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o
#	g++ -std=c++11 -g $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o -o $(BINDIR)/SymboltableTest
#   cp $(OBJDIR)/Symboltable.o ../projectOBJs
#
#	
## compilieren der Source-files
#
#$(OBJDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp $(HEADERDIR)/Symboltable.h
#	@echo "g++ -std=c++11 $*.cpp"
#	g++ -std=c++11 -g  -c -Wall  -o $(OBJDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp
#
#
#$(OBJDIR)/TestSymboltable.o :  $(SRCDIR)/TestSymboltable.cpp $(SRCDIR)/Symboltable.h
#	@echo "g++ -std=c++11 $*.cpp"
#	g++ -std=c++11 -g  -c -Wall  -o $(OBJDIR)/TestSymboltable.o  $(SRCDIR)/TestSymboltable.cpp
#


# Variante mit guten Makefile-Kenntnissen

makeSymboltable: SymboltableTarget TestSymboltableTarget ListTarget StringTabelleTarget
	g++ -std=c++11 -g -Wall $(OBJDIR)/Symboltable.o $(OBJDIR)/Liste.o  $(OBJDIR)/StringTabelle.o $(OBJDIR)/TestSymboltable.o -o $(BINDIRTEST)/SymboltableTest




ListTarget :  $(SRCDIR)/Liste.cpp $(HEADERDIR)/Liste.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -Wall  $(SRCDIR)/Liste.cpp -o $(OBJDIR)/Liste.o

StringTabelleTarget :  $(SRCDIR)/StringTabelle.cpp $(HEADERDIR)/StringTabelle.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -Wall  $(SRCDIR)/StringTabelle.cpp -o $(OBJDIR)/StringTabelle.o


TestSymboltableTarget: $(SRCDIR)/TestSymboltable.cpp $(HEADERDIR)/Symboltable.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -Wall $(SRCDIR)/TestSymboltable.cpp -o $(OBJDIR)/TestSymboltable.o

SymboltableTarget: $(SRCDIR)/Symboltable.cpp $(HEADERDIR)/Symboltable.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -Wall $(SRCDIR)/Symboltable.cpp -o $(OBJDIR)/Symboltable.o


# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu compilieren

cleanCompileSymboltable:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeSymboltable
	
cleanSymboltable:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	
## objs fuer GesamtProjekt neu erzeugen
SymboltableOBJTarget:
	$(MAKE) makeSymboltable

	
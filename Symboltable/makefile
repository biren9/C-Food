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

OBJS = $(OBJDIR)/Symboltable.o \
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o


#
#		Targets zum Bauen des Tests
#

# Variante mit geringen Makefile-Kenntnissen

## Linken der Object-Files
#makeTestSymboltable: $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o
#	g++ -g $(OBJDIR)/Symboltable.o $(OBJDIR)/TestSymboltable.o -o $(BINDIR)/SymboltableTest
#   cp $(OBJDIR)/Symboltable.o ../projectOBJs
#
#	
## compilieren der Source-files
#
#$(OBJDIR)/Symboltable.o :  $(SRCDIR)/Symboltable.cpp $(HEADERDIR)/Symboltable.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/Symboltable.o  $(SRCDIR)/Symboltable.cpp
#
#
#$(OBJDIR)/TestSymboltable.o :  $(SRCDIR)/TestSymboltable.cpp $(SRCDIR)/Symboltable.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/TestSymboltable.o  $(SRCDIR)/TestSymboltable.cpp
#


# Variante mit guten Makefile-Kenntnissen

makeTestSymboltable: SymboltableTarget TestSymboltableTarget
	g++ -g $(OBJDIR)/*.o $(BINDIRTEST)/TestSymboltable.o  -o $(BINDIRTEST)/SymboltableTest

SymboltableTarget: $(OBJS)

# $@ name des object files = name auf der linken Seite vom Doppelpunkt des Targets
# $< erste abhaengigkeit, $< das erste Element in der Liste der Abhaengigkeiten
# $@ --> linke Seite vom Doppelpunkt
# $^ --> rechte Seite vom Doppelpunkt

$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
	g++ -g  -c -Wall  $<  -o $@



TestSymboltableTarget: $(SRCDIR)/TestSymboltable.cpp $(HEADERDIR)/Symboltable.h
	g++ -g  -c -Wall $(SRCDIR)/TestSymboltable.cpp -o $(BINDIRTEST)/TestSymboltable.o  
	


# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu compilieren

cleanSymboltable:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeTestSymboltable
	
	
	
## objs fuer GesamtProjekt neu erzeugen
SymboltableOBJTarget:
	$(MAKE) SymboltableTarget

	
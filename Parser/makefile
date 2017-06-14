# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files fuer das Gesamtprojekt
OBJDIR = objs

# enthaelt die Objectfiles und das ausfuehrbare File zum Testen des Teilprojekts
BINDIRTEST = debug


makeTestParser: ParserTarget TestParserTarget
	g++ -std=c++11 -g $(OBJDIR)/Parser.o $(BINDIRTEST)/TestParser.o ../Scanner/$(OBJDIR)/Scanner.o ../Scanner/$(OBJDIR)/Token.o ../Symboltable/$(OBJDIR)/StringTabelle.o ../Symboltable/$(OBJDIR)/Liste.o ../Symboltable/$(OBJDIR)/Symboltable.o  ../Automat/$(OBJDIR)/Automat.o  ../Buffer/$(OBJDIR)/Buffer.o -o $(BINDIRTEST)/ParserTest

ParserTarget :  $(SRCDIR)/Parser.cpp $(HEADERDIR)/Parser.h
	g++ -std=c++11 -g  -c -Wall  $(SRCDIR)/Parser.cpp -o $(OBJDIR)/Parser.o

#TestBuffer.o ist abhaengig von TestBuffer.cpp und Buffer.h
TestParserTarget :  $(SRCDIR)/TestParser.cpp $(HEADERDIR)/Parser.h
	g++ -std=c++11 -g  -c -Wall $(SRCDIR)/TestParser.cpp -o $(BINDIRTEST)/TestParser.o

cleanCompileParser:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIRTEST)/*
	$(MAKE) makeTestParser

cleanParser:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIRTEST)/*
# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer GesamtProjekt loeschen und dann neu erzeugen
ParserOBJTarget:
	$(MAKE) makeTestParser

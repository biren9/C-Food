# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files fuer das Gesamtprojekt
OBJDIR = objs

# enthaelt die Objectfiles und das ausfuehrbare File zum Testen des Teilprojekts
BINDIRTEST = debug


makeTestParser: Node ParserTarget TestParserTarget ParseTreeTarget VisitorMakeCode VisitorTypeCheck
	g++ -std=c++11 -g $(OBJDIR)/Node.o $(OBJDIR)/ParseTree.o $(OBJDIR)/VisitorMakeCode.o $(OBJDIR)/VisitorTypeCheck.o $(OBJDIR)/Parser.o $(OBJDIR)/TestParser.o ../Scanner/$(OBJDIR)/Scanner.o ../Scanner/$(OBJDIR)/Token.o ../Symboltable/$(OBJDIR)/StringTabelle.o ../Symboltable/$(OBJDIR)/Liste.o ../Symboltable/$(OBJDIR)/Symboltable.o  ../Automat/$(OBJDIR)/Automat.o  ../Buffer/$(OBJDIR)/Buffer.o -o $(BINDIRTEST)/ParserTest -pthread

Node :  $(SRCDIR)/Node.cpp $(HEADERDIR)/Node.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -w  $(SRCDIR)/Node.cpp -o $(OBJDIR)/Node.o -pthread

ParserTarget :  $(SRCDIR)/Parser.cpp $(HEADERDIR)/Parser.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -w  $(SRCDIR)/Parser.cpp -o $(OBJDIR)/Parser.o -pthread

TestParserTarget :  $(SRCDIR)/TestParser.cpp $(HEADERDIR)/Parser.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -w $(SRCDIR)/TestParser.cpp -o $(OBJDIR)/TestParser.o -pthread

ParseTreeTarget :  $(SRCDIR)/ParseTree.cpp $(HEADERDIR)/ParseTree.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -w $(SRCDIR)/ParseTree.cpp -o $(OBJDIR)/ParseTree.o -pthread

VisitorMakeCode :  $(SRCDIR)/VisitorMakeCode.cpp $(HEADERDIR)/VisitorMakeCode.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -w $(SRCDIR)/VisitorMakeCode.cpp -o $(OBJDIR)/VisitorMakeCode.o -pthread

VisitorTypeCheck :  $(SRCDIR)/VisitorTypeCheck.cpp $(HEADERDIR)/VisitorTypeCheck.h
	g++ -Wl,--stack=1200194304 -std=c++11 -g  -c -w $(SRCDIR)/VisitorTypeCheck.cpp -o $(OBJDIR)/VisitorTypeCheck.o -pthread


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

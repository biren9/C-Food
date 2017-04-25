# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files fuer das Gesamtprojekt
OBJDIR = objs

# enthaelt die Objectfiles und das ausfuehrbare File zum Testen des Teilprojekts
BINDIRTEST = debug

#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von AutomatTarget und TestAutomatTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

LIB = ../lib

BufferDIR = ../Buffer

makeTestAutomat: AutomatTarget TestAutomatTarget BufferTarget
	g++ -std=c++11 -g $(OBJDIR)/Automat.o $(BINDIRTEST)/TestAutomat.o $(OBJDIR)/Buffer.o  -o $(BINDIRTEST)/TestAutomat

# compilieren der Source-files
# Buffer.o ist abhaengig von Automat.cpp und Automat.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)


AutomatTarget :  $(SRCDIR)/Automat.cpp $(HEADERDIR)/Automat.h
	g++ -std=c++11 -g  -c -Wall  $(SRCDIR)/Automat.cpp -o $(OBJDIR)/Automat.o

#TestAutomat.o ist abhaengig von TestAutomat.cpp und Automat.h
TestAutomatTarget :  $(SRCDIR)/TestAutomat.cpp $(HEADERDIR)/Automat.h
	g++ -std=c++11 -g  -c -Wall $(SRCDIR)/TestAutomat.cpp -o $(BINDIRTEST)/TestAutomat.o

BufferTarget :  $(SRCDIR)/Buffer.cpp $(HEADERDIR)/Buffer.h
	g++ -std=c++11 -g  -c -Wall  $(BufferDIR)/$(SRCDIR)/Buffer.cpp -o $(OBJDIR)/Buffer.o


# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu compilieren

cleanCompileAutomat:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIRTEST)/*
	$(MAKE) makeTestAutomat

cleanAutomat:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIRTEST)/*


# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer GesamtProjekt loeschen und dann neu erzeugen
AutomatOBJTarget:
	$(MAKE) AutomatTarget

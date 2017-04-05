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

# Linken der Object-files, abhaengig von BufferTarget und TestBufferTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

LIB = ../lib

makeTestAutomat: AutomatTarget 	TestAutomatTarget
	g++ -std=c++11 -g $(OBJDIR)/Automat.o $(OBJDIR)/String.o 	$(BINDIRTEST)/TestAutomat.o  -o $(BINDIRTEST)/TestAutomat
	./$(BINDIRTEST)/TestAutomat

String :  $(LIB)/String.cpp $(LIB)/String.h
	g++ -std=c++11 -g  -c -Wall $(LIB)/String.cpp -o objs/String.o
# compilieren der Source-files
# Buffer.o ist abhaengig von Buffer.cpp und Buffer.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)


AutomatTarget :  $(SRCDIR)/Automat.cpp $(HEADERDIR)/Automat.h
	g++ -std=c++11 -g  -c -Wall  $(SRCDIR)/Automat.cpp -o $(OBJDIR)/Automat.o

#TestBuffer.o ist abhaengig von TestBuffer.cpp und Buffer.h
TestAutomatTarget :  $(SRCDIR)/TestAutomat.cpp $(HEADERDIR)/Automat.h
	g++ -std=c++11 -g  -c -Wall $(SRCDIR)/TestAutomat.cpp -o $(BINDIRTEST)/TestAutomat.o



# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu compilieren

cleanAutomat:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIRTEST)/*
	$(MAKE) makeTestAutomat


# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer GesamtProjekt loeschen und dann neu erzeugen
AutomatOBJTarget:
	$(MAKE) AutomatTarget

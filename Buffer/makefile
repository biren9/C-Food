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

makeTestBuffer: BufferTarget 	TestBufferTarget
	g++ -g $(OBJDIR)/Buffer.o 	$(BINDIRTEST)/TestBuffer.o  -o $(BINDIRTEST)/BufferTest
	

# compilieren der Source-files
# Buffer.o ist abhaengig von Buffer.cpp und Buffer.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)

BufferTarget :  $(SRCDIR)/Buffer.cpp $(HEADERDIR)/Buffer.h 
	g++ -g  -c -Wall  $(SRCDIR)/Buffer.cpp -o $(OBJDIR)/Buffer.o

#TestBuffer.o ist abhaengig von TestBuffer.cpp und Buffer.h
TestBufferTarget :  $(SRCDIR)/TestBuffer.cpp $(HEADERDIR)/Buffer.h
	g++ -g  -c -Wall $(SRCDIR)/TestBuffer.cpp -o $(BINDIRTEST)/TestBuffer.o




# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu compilieren

cleanBuffer:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIRTEST)/*
	$(MAKE) makeTestBuffer
	

# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer GesamtProjekt loeschen und dann neu erzeugen
BufferOBJTarget:
	$(MAKE) BufferTarget

	
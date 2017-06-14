#
#	baut das komplette Scanner Projekt
#
OBJDIR = objs

AUTOMATDIR = Automat

BUFFERDIR = Buffer

SYMBOLTABLEDIR = Symboltable

SCANNERDIR = Scanner

PARSERDIR = Parser


all:	clean automatOBJs bufferOBJs symboltableOBJs scanner parser run
	@echo "target all"

	
# rm 	remove
# -f	force, ohne nachfragen
clean:
	rm -f $(AUTOMATDIR)/$(OBJDIR)/*.o
	rm -f $(BUFFERDIR)/$(OBJDIR)/*.o
	rm -f $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/debug/*
	rm -f $(AUTOMATDIR)/debug/*
	rm -f $(SYMBOLTABLEDIR)/debug/*
	rm -f $(BUFFERDIR)/debug/*
	rm -f $(PARSERDIR)/debug/*
	rm -f $(PARSERDIR)/$(OBJDIR)/*.o
	

automatOBJs: FORCE
	$(MAKE) -C $(AUTOMATDIR) AutomatOBJTarget
	
bufferOBJs: FORCE
	$(MAKE) -C $(BUFFERDIR) BufferOBJTarget
	
symboltableOBJs: FORCE
	$(MAKE) -C $(SYMBOLTABLEDIR) SymboltableOBJTarget

scanner: FORCE
	$(MAKE) -C $(SCANNERDIR) ScannerOBJTarget

parser: FORCE
	$(MAKE) -C $(PARSERDIR) ParserOBJTarget

run:
	$(PARSERDIR)/debug/parserTest

FORCE:

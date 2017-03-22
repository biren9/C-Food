#
#	baut das komplette Scanner Projekt
#
OBJDIR = objs

AUTOMATDIR = Automat

BUFFERDIR = Buffer

SYMBOLTABLEDIR = Symboltable

SCANNERDIR = Scanner



all:	automatOBJs bufferOBJs symboltableOBJs scanner  
	@echo "target all"

	
# rm 	remove
# -f	force, ohne nachfragen
clean:
	rm -f $(AUTOMATDIR)/$(OBJDIR)/*.o
	rm -f $(BUFFERDIR)/$(OBJDIR)/*.o
	rm -f $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/debug/*
	

automatOBJs:
	$(MAKE) -C $(AUTOMATDIR) AutomatOBJTarget
	
	
bufferOBJs:
	$(MAKE) -C $(BUFFERDIR) BufferOBJTarget

	
symboltableOBJs:
	$(MAKE) -C $(SYMBOLTABLEDIR) SymboltableOBJTarget
	

scanner: 
	$(MAKE) -C $(SCANNERDIR) makeTestScanner

	
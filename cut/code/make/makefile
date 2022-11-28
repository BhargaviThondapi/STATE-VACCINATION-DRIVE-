







IDIR =../include
CC=gcc
BDIR=../bin
ODIR=../obj
SDIR=../src
OFILES=$(ODIR)/vaccination_drive_main.o $(ODIR)/vaccination_drive_func.o $(ODIR)/vaccination_drive_func1.o

vaccineapp: $(OFILES)
	$(CC) -o $(BDIR)/vaccineapp $(OFILES)

$(ODIR)/vaccination_drive_main.o: $(SDIR)/vaccination_drive_main.c $(IDIR)/*
	$(CC) -o $(ODIR)/vaccination_drive_main.o -c $(SDIR)/vaccination_drive_main.c

$(ODIR)/vaccination_drive_func.o: $(SDIR)/vaccination_drive_func.c $(IDIR)/*
	$(CC) -o $(ODIR)/vaccination_drive_func.o -c $(SDIR)/vaccination_drive_func.c

$(ODIR)/vaccination_drive_func1.o: $(SDIR)/vaccination_drive_func1.c $(IDIR)/*
	$(CC) -o $(ODIR)/vaccination_drive_func1.o -c $(SDIR)/vaccination_drive_func1.c

clean:
	rm $(ODIR)/*

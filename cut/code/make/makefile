vaccineapp: vaccination_drive_main.o vaccination_drive_func.o vaccination_drive_func1.o
	gcc -o vaccineapp vaccination_drive_main.o vaccination_drive_func.o vaccination_drive_func1.o

vaccination_drive_main.o: vaccination_drive_main.c vaccination_drive_header.h
	gcc -o vaccination_drive_main.o -c vaccination_drive_main.c

vaccination_drive_func.o: vaccination_drive_func.c vaccination_drive_header.h
	gcc -o vaccination_drive_func.o -c vaccination_drive_func.c

vaccination_drive_func1.o: vaccination_drive_func1.c vaccination_drive_header.h
	gcc -o vaccination_drive_func1.o -c vaccination_drive_func1.c

clean:
	rm *.o

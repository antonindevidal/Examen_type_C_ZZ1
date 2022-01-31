CC=gcc
exos:exos.o code.o teZZt.o
	$(CC) -o exos exos.o code.o teZZt.o -lm 
	@echo "Lancer le programme avec  ./exos" 
teZZt.o:teZZt.h teZZt.c
	$(CC) -c teZZt.c -o teZZt.o
exos.o:exos.c code.h 
	$(CC) -c exos.c -g -Wall -Wextra
code.o:code.h code.c
	$(CC) -c code.c -g -Wall -Wextra 
clean:
	rm -rf exos code.o examen.o *.gch

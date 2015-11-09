all: main

dfa: main.o funciones.o
	gcc -o dfa main.o funciones.o

main.o: main.c funciones.h
	gcc -c main.c

funciones.o: funciones.c
	gcc -c funciones.c

clean:
	rm *.o *~ main

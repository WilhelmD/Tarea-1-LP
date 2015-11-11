all: main

main: main.o funciones.o nodes.o
	gcc -o main main.o funciones.o nodes.o

main.o: main.c funciones.h nodes.h
	gcc -c main.c

funciones.o: funciones.c
	gcc -c funciones.c

nodes.o: nodes.c
	gcc -c nodes.c

clean:
	rm *.o *~ main

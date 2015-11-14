#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"
#include "funciones.h"

void listaInsertarPrimero(ListaNodo **ptrCabecera, char *string ,ArbolNodo *ptrArbol) {
	ListaNodo *ptrNuevo;
	puts("1");
	ptrNuevo = malloc(sizeof(ListaNodo));
	puts("2");

	ptrNuevo->data = ptrArbol;
	puts("3");
	ptrNuevo->siguiente = *ptrCabecera;
	puts("4");
	*ptrCabecera = ptrNuevo;
	puts("5");
	ptrArbol->word = malloc(sizeof(char) * (strlen(string) + 1));
	puts("6");
	strcpy(ptrArbol->word,string);
	puts("7");
}//sirve ctm!

void listaInsertar(ListaNodo *ptrPrevio, char *string , ArbolNodo *ptrArbol){
	ListaNodo *ptrNuevo;
	printf("hola ctm!");
	ptrNuevo = malloc(sizeof(ListaNodo));
	ptrNuevo->data = ptrArbol;
	ptrNuevo->siguiente = ptrPrevio->siguiente;
	ptrPrevio->siguiente = ptrNuevo;
}

/*ListaNodo* listaBuscar(ListaNodo *ptrCabecera,char **palabras ,size_t largo_array){
	ListaNodo *ptr;
	size_t contador;
	for (contador;contador<largo_array;contador++){
		for (ptr = ptrCabecera; ptr != NULL; ptr = ptr->siguiente)
			if (palabras[contador] == ptr->data) return ptr;
	}
		return NULL;
}*/


void insertar_nodo(ArbolNodo *ptrarbol, char **palabras, size_t largo_array){
	int n_callback;
	ListaNodo *ptrCabecera = NULL;
	for(int i=0;i<largo_array;i++){
		if(i==0) n_callback=string_to_int(palabras[0]);
		else if(i==1){
		    listaInsertarPrimero(&ptrCabecera,palabras[1],ptrarbol);

			puts(ptrarbol->word);
		}
		else{
 			puts(ptrarbol->word);
		}
	}
	}

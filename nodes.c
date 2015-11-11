#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"
#include "funciones.h"

//void insertar_lista(ListaNodo )


void insertar_nodo(ArbolNodo arbol, char **palabras, size_t largo_array){
	int n_callback;
	for(int i=0;i<largo_array;i++){
		for(int j=0;j<largo_array;j++){
			n_callback=string_to_int(&palabras[0][0]);
			if(i==1){
				palabras[1]=arbol->children;

			}
		}
	}
}

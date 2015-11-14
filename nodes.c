#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"
#include "funciones.h"

void crear_arbol(ListaNodo *ptrCabecera,ArbolNodo *ptrArbol,char **matriz/*,int contador*/,size_t numero_palabras)/*,char **matriz,int contador,int len*/{
	//int resultado;
	ptrArbol = malloc(sizeof(ArbolNodo));
	ptrArbol->word = NULL;
	ptrArbol->children = NULL;
	ptrCabecera = malloc(sizeof(ListaNodo));
	ptrCabecera->data = ptrArbol;
	ptrCabecera->siguiente = NULL;
};

void listaInsertarPrimero(ListaNodo **ptrCabecera, char *string ,ArbolNodo *ptrArbol) {
	ListaNodo *ptrNuevo;
	ptrNuevo = malloc(sizeof(ListaNodo));
	ptrNuevo->data = ptrArbol;
	ptrNuevo->siguiente = *ptrCabecera;
	*ptrCabecera = ptrNuevo;
	ptrArbol->word = malloc(sizeof(char) * (strlen(string) + 1));
	strcpy(ptrArbol->word,string);
}

/*void listaInsertar(ListaNodo *ptrPrevio, char *string , ArbolNodo *ptrArbol){
	ListaNodo *ptrNuevo;
	printf("hola ctm!");
	ptrNuevo = malloc(sizeof(ListaNodo));
	ptrNuevo->data = ptrArbol;
	ptrNuevo->siguiente = ptrPrevio->siguiente;
	ptrPrevio->siguiente = ptrNuevo;
}*/

/*int recorrer_lista(ListaNodo **ptrCabecera,char *string,ArbolNodo *ptrarbol ){
	for(; *ptrCabecera->data->word != string && *ptrCabecera->siguiente != NULL; *ptrCabecera = *ptrCabecera->siguiente){
		if(strcmp(*ptrCabecera->data->word,string)){
			puts("wtf!?");
			listaInsertarPrimero(&ptrCabecera->data->children, string,ptrarbol);
		}
		else{
			puts("Trabja mierda");
		}
	}

}*/


void insertar_nodo(ArbolNodo *ptrarbol, char **palabras, size_t largo_array){
	int n_callback;
	//if(strcmp(ptrarbol,NULL)) puts("sos grande lukas")
	ListaNodo *ptrCabecera = NULL;
	for(int i=0;i<largo_array;i++){
		n_callback=string_to_int(palabras[0]);
		listaInsertarPrimero(&ptrCabecera,palabras[1],ptrarbol);
		//recorrer_lista
		for(; ptrCabecera->data->word != palabras[i] && ptrCabecera->siguiente != NULL; ptrCabecera = ptrCabecera->siguiente){
			if(strcmp(ptrCabecera->data->word,palabras[i])){
				//puts("wtf!?");
				listaInsertarPrimero(&ptrCabecera->data->children, palabras[i],ptrarbol);
			}
			else{

			}
		}













	}
}

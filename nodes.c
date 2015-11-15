#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"
#include "funciones.h"

void crear_arbol(ListaNodo **ptrCabecera,ArbolNodo **ptrArbol,char **matriz/*,int contador*/,size_t numero_palabras)/*,char **matriz,int contador,int len*/{
	ListaNodo *ptrAuxLista;
	ArbolNodo *ptrAuxArbol;
	ptrAuxArbol = malloc(sizeof(ArbolNodo));
	ptrAuxLista = malloc(sizeof(ListaNodo));
	ptrAuxArbol->children=NULL;
	ptrAuxArbol->word="ROOT";
	ptrAuxLista->data=ptrAuxArbol;
	ptrAuxLista->siguiente=NULL;
	*ptrArbol=ptrAuxArbol;
	*ptrCabecera=ptrAuxLista;
};

void listaInsertarPrimero(ListaNodo **ptrCabecera, ArbolNodo *ptrArbol, char *string ) {
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


void insertar_nodo(ListaNodo **ptrCabecera, ArbolNodo **ptrarbol, char **palabras, size_t largo_array){
	int n_callback;
	//if(strcmp(ptrarbol,NULL)) puts("sos grande lukas")
	ListaNodo *ptrAuxLista = NULL;
	ArbolNodo *ptrAuxArbol = NULL;
	for(int i=0;i<largo_array;i++){
		n_callback=string_to_int(palabras[0]);
		listaInsertarPrimero(&*ptrCabecera,&*ptrarbol,palabras[1]);
		//recorrer_lista
		/*for(; ptrCabecera->data->word != palabras[i] && ptrCabecera->siguiente != NULL; ptrCabecera = ptrCabecera->siguiente){
			if(strcmp(ptrCabecera->data->word,palabras[i])){
				//puts("wtf!?");
				listaInsertarPrimero(&ptrCabecera->data->children,&ptrarbol, palabras[i]);//revisar ptrarbol!
			}
			else{

			}*/
	}
}

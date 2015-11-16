#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"
#include "funciones.h"

void insertar_nodo(ListaNodo **ptrCabecera, ArbolNodo **ptrarbol, char **palabras, size_t largo_array, int contador){
	int n_callback;
	if(*ptrarbol==NULL){
		ListaNodo *ptrAuxLista=NULL;
		ArbolNodo *ptrAuxArbol=NULL;
		ptrAuxArbol = malloc(sizeof(ArbolNodo));
		ptrAuxLista = malloc(sizeof(ListaNodo));
		ptrAuxArbol->children=NULL;
		ptrAuxArbol->word="ROOT";
		ptrAuxLista->data=ptrAuxArbol;
		ptrAuxLista->siguiente=NULL;
		*ptrarbol=ptrAuxArbol;
		*ptrCabecera=ptrAuxLista;
		}
	else{
		ArbolNodo *ptrAuxArbol=*ptrarbol;
		ListaNodo *ptrAuxLista=*ptrCabecera;
		if(ptrAuxArbol->children==NULL && contador<largo_array){
			n_callback=string_to_int(palabras[0]);
			//ListaNodo *ptrAuxLista=*ptrCabecera;
			ptrAuxLista = malloc(sizeof(ListaNodo));
			ptrAuxArbol = malloc(sizeof(ArbolNodo));
			ptrAuxArbol->word=malloc(sizeof(char) * (strlen(palabras[contador]) + 1)); //completar con callbacks
			strcpy(ptrAuxArbol->word,palabras[contador]);//revisar cuando llamamos recursivamente
			ptrAuxArbol->children=NULL;
			//*ptrArbol=ptrAuxArbol;
			ptrAuxLista->data = ptrAuxArbol;
			ptrAuxLista->siguiente = NULL;
			(*ptrarbol)->children=ptrAuxLista;
			//puts("ahora es cuando!");
			insertar_nodo(&ptrAuxArbol->children, &ptrAuxLista->data,palabras,largo_array,contador+1);
		}
	}
}

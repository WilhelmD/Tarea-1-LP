#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"
#include "funciones.h"

int buscar_arbol(ArbolNodo *ptrArbol, ListaNodo *ptrCabecera, char **palabras, size_t largo_array){
	for(int i=0;i<largo_array;i++){
		for(; ptrCabecera->data->word != palabras[i] && ptrCabecera->siguiente != NULL; ptrCabecera = ptrCabecera->siguiente){
			puts("ojala wn !");
			if(strcmp(ptrCabecera->data->word,palabras[i])) return 1;
		}
	}
	return 0;
}

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
		n_callback=string_to_int(palabras[0]);
		//ListaNodo *ptrAuxLista=*ptrCabecera;
		ArbolNodo *ptrAuxArbol=*ptrarbol;
		ListaNodo *ptrIterador=*ptrCabecera;
		printf("%d",contador);
		if(ptrAuxArbol->children==NULL && contador<largo_array){
			ListaNodo *ptrAuxLista=NULL;
			ArbolNodo *ptrAuxArbol=NULL;
			ptrAuxLista = malloc(sizeof(ListaNodo));
			ptrAuxArbol = malloc(sizeof(ArbolNodo));
			ptrAuxArbol->word=malloc(sizeof(char) * (strlen(palabras[contador]) + 1)); //completar con callbacks
			for (; !strcmp(ptrIterador->data->word,palabras[contador]) && ptrIterador->siguiente != NULL; ptrIterador = ptrIterador->siguiente){
				if(strcmp(ptrIterador->data->word,palabras[contador])){
					insertar_nodo(&ptrIterador->data->children, &ptrIterador->data,palabras,largo_array,contador+1);
					break;
				}
				else{
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

		}

}

#include <stdlib.h>
#include <stdio.h>
#include "nodes.h"
#include "funciones.h"

void listaInsertarPrimero(ListaNodo **ptrCabecera, ArbolNodo **ptrArbol, char *string, char **palabras,int i ) {
	ListaNodo *ptrAuxLista=NULL;
	ArbolNodo *ptrAuxArbol=NULL;
	ptrAuxLista = malloc(sizeof(ListaNodo));
	ptrAuxArbol = malloc(sizeof(ArbolNodo));
	ptrAuxArbol->word=malloc(sizeof(char) * (strlen(string) + 1));
	strcpy(ptrAuxArbol->word,string);
	ptrAuxArbol->children=NULL;
	*ptrArbol=ptrAuxArbol;
	ptrAuxLista->data = *ptrArbol;
	ptrAuxLista->siguiente = NULL; //podria cambiarse =ptrCabecera
	*ptrCabecera = ptrAuxLista;
	ptrAuxArbol=*ptrArbol;
	puts("Numerito:");
	ptrAuxLista=*ptrCabecera;

	printf("%d",i);
	i+=1;
	if(ptrAuxLista->data->word == palabras[i] && ptrAuxLista->siguiente == NULL) {
		puts("Dime si entraste wn");
	};
	listaInsertarPrimero(&ptrAuxArbol->children,&ptrAuxLista->data,palabras[i],palabras,i);

	//*ptrArbol->word = malloc(sizeof(char) * (strlen(string) + 1));
	//strcpy(*ptrArbol->word,string);
}

int buscar_arbol(ArbolNodo *ptrArbol, ListaNodo *ptrCabecera, char **palabras, size_t largo_array){
	for(int i=0;i<largo_array;i++){
		for(; ptrCabecera->data->word != palabras[i] && ptrCabecera->siguiente != NULL; ptrCabecera = ptrCabecera->siguiente){
			puts("ojala wn !");
			if(strcmp(ptrCabecera->data->word,palabras[i])) return 1;
		}
	}
	return 0;
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
	int n_callback,contador;

	for(int i=0;i<largo_array;i++){
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
			if(ptrAuxArbol->children==NULL ){
				ListaNodo *ptrAuxLista=NULL;
				ArbolNodo *ptrAuxArbol=NULL;
				ptrAuxLista = malloc(sizeof(ListaNodo));
				ptrAuxArbol = malloc(sizeof(ArbolNodo));
				ptrAuxArbol->word=malloc(sizeof(char) * (strlen(palabras[i]) + 1));
				strcpy(ptrAuxArbol->word,palabras[i]);
				ptrAuxArbol->children=NULL;
				//*ptrArbol=ptrAuxArbol;
				ptrAuxLista->data = ptrAuxArbol;
				ptrAuxLista->siguiente = NULL;
				ptrarbol->children=ptrAuxLista; //linea ctm!
				insertar_nodo(&ptrAuxArbol->children, &ptrAuxLista->data,palabras,largo_array);
			}
			//listaInsertarPrimero(&ptrAuxLista,&ptrAuxArbol,palabras[i],palabras,i);
			/*if(ptrAuxLista->data->word == palabras[i]) {
				puts("será la recusrion?");
				insertar_nodo(&ptrAuxLista,&ptrAuxArbol,palabras,largo_array);
			}
			else{
				puts("EL else?");
				ptrAuxLista =ptrAuxLista->siguiente;
				puts(ptrAuxLista->data->word);
			}*/
			/*for(; ptrAuxLista->data->word != palabras[i] && ptrAuxLista->siguiente != NULL; ptrAuxLista = ptrAuxLista->siguiente){
				puts("Sera el if?");
				if(strcmp(ptrAuxLista->data->word,palabras[i])) {
					puts("INSERTA CTM!");
					insertar_nodo(&ptrAuxLista,&ptrAuxArbol,palabras,largo_array);

				}
			}*/
		}
	}
}

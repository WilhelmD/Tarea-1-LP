#include <stdlib.h>
#include "nodes.h"

void insertar_nodo(ArbolNodo *ptrCabecera,char *palabra){	
	ArbolNodo *ptrNuevo;
	if (ptrCabecera == NULL){
		ptrNuevo = malloc(sizeof(ArbolNodo));
		ptrNuevo->word = palabra;
		ptrNuevo->children = NULL;
		ptrCabecera = ptrNuevo;
	}
};
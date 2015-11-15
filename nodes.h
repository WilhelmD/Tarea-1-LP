#ifndef NODES_H
#define NODES_H

#include <string.h>


typedef struct l_node ListaNodo;
typedef struct t_node ArbolNodo;


struct t_node {
	ListaNodo *children;
	char *word;
	void (*callback)(const char *);
};

struct l_node{
	ArbolNodo *data;
	ListaNodo *siguiente;
};

void listaInsertarPrimero(ListaNodo **ptrCabecera, ArbolNodo *ptrArbol, char *string );
void insertar_nodo(ListaNodo **ptrCabecera, ArbolNodo **ptrarbol, char **palabras, size_t largo_array);
void crear_arbol(ListaNodo **ptrCabecera,ArbolNodo **ptrArbol,char **matriz/*,int contador*/,size_t numero_palabras);



#endif // NODES_H

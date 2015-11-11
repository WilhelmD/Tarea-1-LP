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


#endif // NODES_H

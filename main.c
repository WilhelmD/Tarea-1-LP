#include "funciones.h"
#include "nodes.h"
#define MAX_BUFFER 1000

int main(){
	int n_comandos;
	ArbolNodo *ptrarbol=NULL;
	ListaNodo *ptrCabecera=NULL;
	char **a;
	printf("");

	scanf("%d",&n_comandos);
	getchar();

	char *string = NULL;
	char delimitador=' ';
	size_t largo;
	ssize_t lenstr = 0;
	size_t n_palabras;

	for(int i=0; i<n_comandos; i++){
		printf(">>");
		getline(&string, &largo, stdin);
		//printf("%s",string);
		a=split(string,largo,delimitador,&n_palabras);
		crear_arbol(&ptrCabecera,&ptrarbol,a,n_palabras);
		insertar_nodo(&ptrarbol,a,n_palabras);

}





	return 0;
}

#include "funciones.h"
#include "nodes.h"
#define MAX_BUFFER 1000

int main(){
	int n_comandos,contador=0;
	ArbolNodo *raiz=NULL;
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
		insertar_nodo(&ptrCabecera,&raiz,a,n_palabras,contador);
		puts("terminamos el primero comando perro!");
		contador=0;

}





	return 0;
}

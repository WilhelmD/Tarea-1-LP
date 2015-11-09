#include "funciones.c"
#include "nodes.h"
#define MAX_BUFFER 1000

int main(){
	int n_comandos;
	printf("");
	scanf("%d",&n_comandos);
	char string[MAX_BUFFER];
	char *ptrstring;
	ptrstring=string;
	for(int i=0;i<n_comandos;i++){
		printf(">> ");
		scanf("%s", ptrstring);
		getchar();
		puts(ptrstring);
	}

	return 0;
}

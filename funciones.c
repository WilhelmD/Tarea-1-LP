#include "funciones.h"
#include <math.h>

char **split(char *phrase, const size_t length, const char delimiter, size_t *n_tokens)
{
    int words = 1;

    size_t n;
    for (n = 0; n < length; n++)
        words += phrase[n] == delimiter;

    char **input = malloc(sizeof(char*) * words);

    int j = 0;
    char *token = strtok(phrase, &delimiter);
    while (token != NULL) {
        input[j] = malloc(sizeof(char) * strlen(token) + sizeof(char));
        strcpy(input[j++], token);
        token = strtok(NULL, &delimiter);
    }

    *n_tokens = words;
    return input;
}

char *linea_archivo(FILE *archivo){ //entrega un string con la linea de un archivo.
	int i = 1;
	char c,*linea;
	linea = malloc(sizeof(char)); //c para cada caracter, linea para la linea entera.
	while (1){
		c = fgetc(archivo);
		if (c == '\n' || c == EOF) break;
		else{
			linea = (char *) realloc(linea,sizeof(char) * i); //memoria para un caracter mas.
			linea[i-1] = c;
			i++;
		}
	}
	return linea;
}

FILE *leer_archivo(char *string){
	size_t *n,valor,largo;
	const char *filename;
	char **arreglo;
	FILE *archivo;

	valor = 0;
	n = &valor;
	largo = strlen((const char*) string);
	arreglo = split(string,largo,' ',n);
	filename = arreglo[((int) *n )-1];
	archivo = fopen(filename,"r");
	free(arreglo);
	return archivo;
}

int string_to_int(char *string){
	int suma,valor;
	size_t largo;

	largo = (int) strlen(string);
	suma = 0;

	for (int i=0;i<largo;i++){
		valor = (int) string[i] - '0';
		valor *= pow(10,largo-1-i);
		suma += valor;
	}
	return suma;
}

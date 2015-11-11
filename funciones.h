#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int power(int base,int potencia);

char **split(char *phrase, const size_t length, const char delimiter, size_t *n_tokens);

char *linea_archivo(FILE *archivo);

char *nombre_archivo(char *string);

int string_to_int(char *string);

void Terminar_programa(char *string);

void Mostrar_por_linea(char *string);

void Crear_archivo(char *string);

void Eliminar_archivo(char *string);

void Truncar_archivo(char *string);


#endif

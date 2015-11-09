#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split(char *phrase, const size_t length, const char delimiter, size_t *n_tokens);

char *linea_archivo(FILE *archivo);

FILE *leer_archivo(char *string);

int string_to_int(char *string);

#endif

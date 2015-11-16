#include "funciones.h"

int power(int base,int potencia){
	int i,resultado = 1;
	for (i=0;i<potencia;i++){
		resultado *= base;
	}
	return resultado;
}

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
			linea = realloc(linea,sizeof(char) * i); //memoria para un caracter mas.
			linea[i-1] = c;
			i++;
		}
	}
	return linea;
}

char *nombre_archivo(char *string){ //entrega el ultimo token (generalmente el nombre del archivo)
	int i,largo_nombre;	
	size_t valor,*n,largo;
	char **tokens,*filename;

	valor = 0;
	n = &valor;
	largo = strlen(string);
	tokens = split(string,largo,' ',n);		//LIBERAR ESTO Y PROBAR DE NUEVO.

	largo = strlen(tokens[(int) *n -1]);
	largo_nombre = (int) largo;
	filename = malloc(sizeof(char) * largo_nombre);
	for (i = 0;i<largo_nombre;i++) filename[i] = tokens[(int) *n -1][i];

	return filename;
}

int string_to_int(char *string){ // convierte un string a entero, asumiendo que el entero va desde -X a +Y.
	int i,suma,valor;
	size_t largo;

	largo = (int) strlen(string);
	suma = 0;

	for (i=0;i<largo;i++){
		valor = (int) string[i] - '0';
		valor *= power(10,largo-1-i);
		suma += valor;
	}
	return suma;
}

void Terminar_programa(char *string){ //leer archivo, imprimir texto.
	char *nombre,noargs[] = "noargs";
	nombre = nombre_archivo(string);

	if (strcmp(nombre,noargs) != 0){
		FILE *input;
		input = fopen(nombre,"r");

		if (input == NULL){
			printf("Archivo %s no existe\n",nombre);
			free(nombre);
			exit(0);
		}

		char *texto;

		texto = linea_archivo(input);
		printf("%s",texto);//asumiendo que el archivo tiene 1 sola linea.

		fclose(input);
		free(texto);
	}
	free(nombre);

  //liberar memoria almacenada en el arbol.

	exit(0);
}

void Insertar(char *string){
	int linea;
	char *nombre;
	FILE *input,*archivo;

	nombre = nombre_archivo(string);
	input = fopen(nombre,"r");

	if (input != NULL){
		while (1){//recorre las lineas del archivo de input.
			char **palabras,*filename,*file_line;//palabras = archivo linea dato 1... dato n
			size_t *n,valor;	//datos = c/linea de c/archivo especificado en input, filename = palabras[0], file_line = cada linea del archivo input.

			file_line = malloc( sizeof(char) * 128);//designar tamaño maximo para las lineas del archivo de input.
			file_line = fgets(file_line, sizeof(char) * 128, input);
			valor = 0;
			n = &valor;

			if (feof(input)) break;

			palabras = split(file_line,strlen(file_line),' ',n);
			filename = palabras[0];
			linea = string_to_int(palabras[1]);
			archivo = fopen(filename,"r");// archivo en el cual se debe insertar una linea.

			if (archivo == NULL){
				printf("Archivo %s no encontrado.\n",filename);
				continue;
			}
			else{
				//recorrer archivo, escribir todas sus lineas en aux.txt, al llegar a la dichosa linea escribirla en aux.txt y seguir hasta el final.
				FILE *temp = fopen("aux.txt", "w");
				char *datos;
				int i,insertada = 0,cont = 0;

				datos = malloc( sizeof(char) * 128);//designar tamaño maximo para lineas del archivo a insertar.
				datos = fgets(datos, sizeof(char) * 128, archivo);

				while (1){

					if (cont == linea){
						for (i = 2; i < valor; i++){
							fprintf(temp, "%s", palabras[i]);

							if (i != valor -1) fprintf(temp,"%c", ' ');

						}

						insertada = 1;
					}

					fprintf(temp,"%s",datos);
					//free(datos);

					datos = fgets(datos, sizeof(char) * 128, archivo);//linea_archivo(archivo);
					cont++;

					if ( feof(archivo) ){
						if (linea < 0){
							for (i = 2; i < valor; i++){
								fprintf(temp, "%s", palabras[i]);

								if (i != valor -1) fprintf(temp,"%c", ' ');

							}

							insertada = 1;
						}

						if (insertada == 0){
							printf("Linea %d no existe en %s\n",linea,filename);
							fclose(temp);
							remove("aux.txt");
						}
						break;
					}
				}

				fclose(archivo);
				if (insertada == 1){
					fclose(temp);
					remove(filename);
					rename("aux.txt",filename);
				}
			}

			free(file_line);
			free(palabras);
			free(filename);
		}

	}

}

void Eliminar_por_linea(char *string){
	int linea;
	char *nombre;
	FILE *input,*archivo;

	nombre = nombre_archivo(string);
	input = fopen(nombre,"r");

	if (input != NULL){
		while (1){//recorre las lineas del archivo de input.
			char **palabras,*filename,*file_line,**aux;//palabras = archivo linea dato 1... dato n
			size_t *n,valor;	//datos = c/linea de c/archivo especificado en input, filename = palabras[0], file_line = cada linea del archivo input.
			int i,largo;

			file_line = malloc( sizeof(char) * 32);//designar tamaño maximo para las lineas del archivo de input.
			file_line = fgets(file_line, sizeof(char) * 32, input);
			valor = 0;
			n = &valor;

			if (feof(input)) break;

			palabras = split(file_line,strlen(file_line),' ',n);
			aux = split(palabras[1],strlen(palabras[1]),'\n',n);
			
			filename = palabras[0];
			linea = string_to_int(aux[0]);
			free(aux);
			archivo = fopen(filename,"r");// archivo en el cual se debe insertar una linea.

			if (archivo == NULL){
				printf("Archivo %s no encontrado.\n",filename);
				continue;
			}
			else{
				int cont,eliminada;
				char *datos;
				FILE *temp;

				temp = fopen("aux.txt","w");
				datos = malloc( sizeof(char) * 128 );
				datos = fgets(datos, sizeof(char) * 128, archivo);
				cont = 0;

				while (1){

					if (cont == linea){
						datos = fgets(datos, sizeof(char) * 128, archivo);
						eliminada = 1;
					}
					if (feof(archivo)){
						if (eliminada != 1){
							printf("linea %d no encontrada en %s\n",linea,filename);
							eliminada = 0;
						}
						break;
					}

					fprintf(temp,"%s",datos);
					datos = fgets(datos, sizeof(char) * 128, archivo);
					cont++;
				}

				free(datos);
				fclose(temp);
				fclose(archivo);
				if (eliminada == 1){
					remove(filename);
					rename("aux.txt",filename);
				}

			}
		}
	}
}

void Eliminar_por_coincidencia(char *string){
	char *nombre;
	FILE *input,*archivo;

	nombre = nombre_archivo(string);
	input = fopen(nombre,"r");

	if (input != NULL){
		while (1){//recorre las lineas del archivo de input.
			char **palabras,**aux,*filename,*file_line,*keyword;//palabras = archivo linea dato 1... dato n
			size_t *n,valor;	//datos = c/linea de c/archivo especificado en input, filename = palabras[0], file_line = cada linea del archivo input.
			int i,indice,largo;

			file_line = malloc( sizeof(char) * 64);//designar tamaño maximo para las lineas del archivo de input.
			file_line = fgets(file_line, sizeof(char) * 64, input);
			valor = 0;
			n = &valor;

			if (feof(input)) break;

			palabras = split(file_line,strlen(file_line),' ',n);
			aux = split(palabras[2],strlen(palabras[2]),'\n',n);
			
			filename = palabras[0];
			keyword = aux[0];
			indice = string_to_int(palabras[1]);
			archivo = fopen(filename,"r");// archivo en el cual se debe insertar una linea.

			if (archivo == NULL){
				printf("Archivo %s no encontrado.\n",filename);
				continue;
			}
			else{
				int eliminada;
				char *datos;	//buscar si la keyword esta en la linea, eliminar si esta ahi.
				FILE *temp;

				temp = fopen("aux.txt","w");
				datos = malloc( sizeof(char) * 128 );
				datos = fgets(datos, sizeof(char) * 128, archivo);

				while (1){
					char **tokens,**ultimo;
					int i;
					size_t *n,valor = 0;
					n = &valor;

					tokens = split(datos,strlen(datos),' ',n);
					ultimo = split(tokens[valor-1],strlen(tokens[valor-1]),'\n',n);
					if (!strcmp(keyword,tokens[indice])){
						datos = fgets(datos, sizeof(char) * 128, archivo);
						eliminada = 1;
					}
					if (indice = (int)valor -1){
						if (!strcmp(keyword,ultimo[0])){
							datos = fgets(datos, sizeof(char) * 128, archivo);
							eliminada = 1;
						}
					}

					free(ultimo);
					free(tokens);

					if (feof(archivo)){
						if (eliminada != 1){
							printf("keyword %s no encontrado en %s\n",keyword,filename);
							eliminada = 0;
						}
						break;
					}
					fprintf(temp,"%s",datos);
					datos = fgets(datos, sizeof(char) * 128, archivo);
				}

				free(datos);
				fclose(temp);
				fclose(archivo);
				if (eliminada == 1){
					remove(filename);
					rename("aux.txt",filename);
				}
				if (eliminada == 0) remove("aux.txt");

			}
		}
	}

}

void Mostrar_por_linea(char *string){//caso en que linea no existe.
	int linea;
	char *nombre;
	FILE *input,*archivo;

	nombre = nombre_archivo(string);
	input = fopen(nombre,"r");

	if (input != NULL){
		while (1){	//recorriendo el archivo de input linea a linea.
			char **palabras,*datos,*filename,*file_line = linea_archivo(input);
			size_t *n,valor;
			valor = 0;
			n = &valor;

			if (feof(input)) break;

			palabras = split(file_line,strlen(file_line),' ',n); //separar nombre del archivo de la linea que se busca.
			filename = palabras[0];
			linea = string_to_int(palabras[1]);
			archivo = fopen(filename,"r");

			if (archivo != NULL){
				int i;
				for (i = 0;i < linea;i++){ 	//recorriendo el archivo.
					datos = linea_archivo(archivo);
					if (i == linea-1){	//linea buscada.
						printf("%s: %s\n",filename,datos);
						free(datos);
						break;
					}
					if (feof(archivo)){	//final del archivo.
						printf("Linea %d no existe en '%s'\n",linea,filename);
						free(datos);
						break;
					}			//liberar memoria si la linea no es la buscada.
					if (i != linea -1 && datos != NULL) free(datos);
				}
				fclose(archivo);
			}
			else{
				printf("Archivo '%s' no encontrado\n",filename);
				fclose(archivo);
			}
			free(palabras);
			free(file_line);
		}
	}
	else printf("%s","Archivo de input no encontrado\n");
	fclose(input);
	free(nombre);
}

void Crear_archivo(char *string){//leer archivo de input y crear un archivo por cada linea.
	FILE *input,*archivo;
	char *nombre;

	nombre = nombre_archivo(string);
	input = fopen(nombre,"r");

	if (input != NULL){
		while (1){
			char *line = linea_archivo(input);

			if (feof(input)) break;

			archivo = fopen(line,"w");
			fclose(archivo);
			printf("Archivo '%s' creado\n",line);
			free(line);
		}
	}

	else printf("%s","Archivo de input no encontrado\n");
	fclose(input);
	free(nombre);
}

void Eliminar_archivo(char *string){//string es el input completo: <token> ... <token> <nombre archivo>
	FILE *input;	//archivos en directorio db;
	char *nombre;

	nombre = nombre_archivo(string);
	input = fopen(nombre,"r");

	if (input != NULL){
		while (1){
			int r;
			char *line = linea_archivo(input);

			if (feof(input)) break;
			r = remove(line);

			if (r == 0) printf("Archivo '%s' eliminado exitosamente.\n",line);
			else printf("Error al intentar eliminar %s\n",line);
			free(line);
		}
	}

	else printf("%s","Archivo de input no encontrado\n");
	fclose(input);
	free(nombre);
}

void Truncar_archivo(char *string){	
	FILE *input,*archivo;
	char *nombre;

	nombre = nombre_archivo(string);
	input = fopen(nombre,"r");

	if (input != NULL){
		while (1){
			char *line = linea_archivo(input);

			if (feof(input)) break;

			archivo = fopen(line,"r");
			if (archivo != NULL){
				archivo = freopen(line,"w",archivo);
				fclose(archivo);
				printf("Archivo '%s' limpiado\n",line);
			}
			else{
				printf("Archivo '%s' no encontrado\n",line);
				fclose(archivo);
			}
			free(line);
		}
	}
	else printf("%s","Archivo de input no encontrado\n");
	fclose(input);
	free(nombre);
}

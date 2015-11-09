#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Mostrar_por_linea(char *string){
	int linea;
	FILE *input,*archivo;

	input = leer_archivo(string);

	if (input != NULL){
		while (1){	//recorriendo el archivo de input linea a linea.
			char **arreglo,*datos,*filename,*file_line = linea_archivo(input);
			size_t *n,valor;
			valor = 0;
			n = &valor;

			if (feof(input)) break;

			arreglo = split(file_line,strlen(file_line),' ',n); //separar nombre del archivo de la linea que se busca.
			filename = arreglo[0];
			linea = string_to_int(arreglo[1]);
			archivo = fopen(filename,"r");

			if (archivo != NULL){
				for (int i = 0;i < linea;i++){ 	//recorriendo el archivo.
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
			free(arreglo);
			free(file_line);
		}
	}
	else printf("%s","Archivo de input no encontrado\n");
	fclose(input);
}
	
void Crear_archivo(char *string){//leer archivo de input y crear un archivo por cada linea.
	/*size_t *n,valor,largo;
	const char *filename;
	char **arreglo;*/
	FILE *input,*archivo;

	/*funcion para esta wea?
	valor = 0;
	n = &valor;
	largo = strlen((const char*) string);
	arreglo = split(string,largo,' ',n);
	filename = arreglo[((int) *n )-1];
	input = fopen(filename,"r");
	free(arreglo);
	*/
	input = leer_archivo(string);

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
}

void Eliminar_archivo(char *string){//string es el input completo: <token> ... <token> <nombre archivo>
	/*size_t *n,valor,largo;
	const char *filename;
	char **arreglo;*/
	FILE *input;	//archivos en directorio db;

	/*valor = 0;
	n = &valor;
	largo = strlen((const char*) string);
	arreglo = split(string,largo,' ',n);
	filename = arreglo[((int) *n )-1];
	free(arreglo);*/
	input = leer_archivo(string);

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
}

void Truncar_archivo(char *string){
	/*size_t *n,valor,largo;
	const char *filename;
	char **arreglo;*/
	FILE *input,*archivo;

	/*valor = 0;
	n = &valor;
	largo = strlen((const char*) string);
	arreglo = split(string,largo,' ',n);
	filename = arreglo[((int) *n )-1];
	input = fopen(filename,"r");
	free(arreglo);*/
	input = leer_archivo(string);

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
}

int main(){	//testear estupideces con strings.
	/*size_t valor,*tokens;
	valor = 0;
	tokens = &valor;
	char **palabras,string[] = "esto es un string en C \n";
	palabras = split(string,24,' ',tokens);//ARREGLOS BIDIMENSIONALES CON PUNTEROS!!!
	for (int i=0;i<*tokens;i++){
		printf("%s",strcat(palabras[i]," "));
	}*/
	char archivo[] = "1234523524";
	printf("%d\n",string_to_int(archivo));
	//callback4(archivo);
	return 0;
}

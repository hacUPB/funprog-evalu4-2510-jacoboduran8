// Análisis de Texto en Consola
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define max_L 512
#define max_A 100
#define max_P 100


char *leerarchivo(const char *nombre){
    FILE *archivo = fopen(nombre, "r");
    if(!archivo){
        printf("No se puede abrir el archivo\n");
        return 1;
    }

    char linea[max_L];
    char *texto = NULL;
    int tamtotal = 0;

    while (fgets(linea, max, archivo)){
        int largo = strlen(linea);
        char *nuevo = malloc(tamtotal + largo + 1);

        if(texto){
            strcpy(nuevo, texto);
            strcat(nuevo, linea);
            free(texto);
        } else {
            strcpy(nuevo, linea)
        }

        texto = nuevo;
        tamtotal = tamtotal + largo;
    }

    fclose(archivo);
    return texto;
}


void analizartexto(const char *texto, int *caracteres, int *palabras, int *espacios, int *lineas, int vocales[5]){
    int dentro_palabra = 0;

    *caracteres = 0;
    *palabras = 0;
    *espacios = 0;
    *lineas = 0;

    for(int i = 0; texto[i] != '\0'; i++){
        char c = texto[i];

        if(c != '\n') (*caracteres)++;
        if(c == ' ') (*espacios)++;
        if(c == '\n') (*lineas)++;

        if(!isspace(c) && !dentro_palabra){ //isspace es una nueva función que comprueba si un caracter es un espacio en blanco
            (*palabra)++;
            dentro_palabra = 1
        } else if(isspace(c)){
            dentro_palabra = 0;
        }

        c = tolower(c);
        if(c == 'a') vocales[0]++;
        if(c == 'e') vocales[1]++;
        if(c == 'i') vocales[2]++;
        if(c == 'o') vocales[3]++;
        if(c == 'u') vocales[4]++;
    }

}

char *reemplzarpalabra(const char *texto, const char *viejo, const char *nuevo){
    int repeticion = 0;
    int largo_viejo, largo_nuevo;
    const char *ptr = texto;
    int nuevo_tam;
    char *resultado;
    char *destino;

    largo_viejo = strlen(viejo);
    largo_nuevo = strlen(nuevo);

    while((ptr = strstr(ptr, viejo)) != NULL){
        repeticion++;
        ptr = ptr + largo_viejo;
    }

    nuevo_tam = strlen(texto) + veces * (largo_nuevo - largo_viejo) + 1;
    resultado = malloc(nuevo_tam);
    destino = resultado;

    while(*texto){
        if(strstr(texto, viejo) == texto){
            strcpy(destino, nuevo);
            destino = destino + largo_nuevo;
            texto = texto + largo_viejo;
        } else {
            *destino++ = *texto++;
        }
    }
    *destino = '\0';

    return resultado;

}

void guardar(const char *nombre, const char *texto, in caracteres, int palabras, int espacios, int lineas, int vocales[5]){
    FILE *archivo = fopen (*nombre, "w");
    if(!archivo){
        printf("No se pude cargar el archivo");
        return 1;
    }

    fprintf(archivo, "Caracteres: %d\n", caracteres);
    fprintf(archivo, "Palabras: %d\n", palabras);
    fprintf(archivo, "Espacios: %d\n", espacios);
    fprintf(archivo, "Lineas: %d\n", lineas);
    fprintf(archivo,"\nVocales\n");
    fprintf(archivo, "a: %d\n", vocales[0]);
    fprintf(archivo, "e: %d\n", vocales[1]);
    fprintf(archivo, "i: %d\n", vocales[2]);
    fprintf(archivo, "o: %d\n", vocales[3]);
    fprintf(archivo, "u: %d\n", vocales[4]);
    fprintf(archivo, "%s", texto);

    fclose(archivo);
}

int main(){
    int opcion;
    int caracteres, palabras, espacios, lineas;
    int vocales[5] = {0};
    int cargado = 0;
    int modificado = 0;
    char archivo_entrada[max_A], archivo_salida[max_A];
    char *texto = NULL;
    char *texto_final = NULL;
    char palabra_vieja[max_P], palabra_nueva[max_P];


    do{
        printf("1. Cargar archivo\n");
        printf("2. Ver estadisticas del texto\n");
        printf("3. Ver frecuencia de vocales\n");
        printf("4. Reemplazar palabras\n");
        printf("5. Guardar\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                printf("Ingrese el nombre del archivo .txt: ");
                fgets(archivo_entrada, max_A, stdin);
                archivo_entrada[strcspn(archivo_entrada, "\0")] = '\0'; //strcspn --> Sirve para encontrar la longitud de la subcadena inicial de una cadena de caracteres
                texto = leerarchivo(archivo_entrada);
                if(texto){
                    printf("Cargado exitos\n");
                    cargado = 1;
                    if(texto_final) free(texto_final);
                    texto_final = texto;
                }
                break;
            
            case 2:
                if(!cargado){
                    printf("Tienes que cargar un archivo\n");
                    break;
                }

                analizartexto(texto_final, &caracteres, &palabras, &espacios, &lineas, vocales);
                printf("Palabras: %d\n", palabras);
                printf("Espacios: %d\n", espacios);
                printf("Caracteres: %d\n", caracteres);
                printf("Lineas: %d\n", lineas);
                printf("\nVocales\n");
                printf("a: %d\n", vocales[0]);
                printf("e: %d\n", vocales[1]);
                printf("i: %d\n", vocales[2]);
                printf("o: %d\n", vocales[3]);
                printf("u: %d\n", vocales[4]);

                break;

            case 3:
                if(!cargado){
                    printf("Tienes que cargar un archivo\n");
                    break;
                }

                printf("Palabra que deseas cambiar: ");
                fgets(palabra_vieja, max_P, stdin);
                palabra_vieja[strcspn(palabra_vieja, "\n")] = '\0';

                printf("Palabra por la que la deseas cambiar: ");
                fgets(palabra_nueva, max_P, stdin);
                palabra_nueva[strcspn(palabra_nueva, "\n")] = '\0';

                char *nuevo_texto = reemplzarpalabra(texto_final, palabra_vieja, palabra_nueva);
                if(texto_final != texto) free(texto_final);
                texto_final = nuevo_texto;
                modificado = 1;
                break;

            case 4:
                if(!cargado){
                    printf("Tienes que cargar un archivo\n");
                    break;
                }

                printf("Nombre archivo de salida: ");
                fgets(archivo_salida, max_A, stdin);
                archivo_salida[strcspn(archivo, "\n")] = '\0';

                analizartexto(texto_final, &caracteres, &palabras, &espacios, &lineas, vocales);
                guardar(archivo_salida, texto_final, caracteres, palabras, espacios, lineas, vocales);
                printf("Guardado en %s\n", archivo_salida);
                break;

            case 5;
                printf("Saliendo del programa\n");
                break;

            default:
             printf("Opcion no valida");

        }
    } while (opcion != 5);

    if(texto && texto != texto_final) free(texto);
    if(texto_final) free(texto_final);

    return 0;
}

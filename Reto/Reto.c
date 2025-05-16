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

char *reemplzarpalabra(){

}

void guardar(){

}

int main(){
    int opcion;
    char 

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

        }
    }

    return 0;
}
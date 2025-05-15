// Análisis de Texto en Consola
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void analizartexto(){

}

char *leerarchivo(const char *nombre){
    FILE *archivo = fopen(nombre, "r");
    if(!archivo){
        printf("No se puede abrir el archivo\n");
        return 1;
    }

    char linea[];
    char *texto = NULL;
    int tamtotal = 0;
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
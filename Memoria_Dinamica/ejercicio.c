#include <stdio.h>
#include <stdlib.h>

int main(void){
    /*
    Preguntar al usuario cuantas letras tiene su nombre y apellido.
    Reservamos memoria para almacenar esos datos (malloc)
    Le pedimos al usuario que ingrese su nombre y apellido
    y lo imprimimos en pantalla con saludo adicional
    */
    int size;
    char *nombre_2;

    printf("Cuantas letras tiene su nombre:\n");
    scanf("%d", &size);
    nombre_2 = (char*) malloc((size + 2)*(sizeof(char)));
    printf("Ingrese su nombre:\n");
    fflush(stdin);
    fgets(nombre_2, size + 2, stdin);
    printf("Buenas tardes %s\n", nombre_2);\
    
    free(nombre_2);

    return 0;
}
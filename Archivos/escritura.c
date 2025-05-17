#include <stdio.h>
#include <string.h>

int main(){
    FILE *p_archivo;
    char Nombre[30];
    int edad;

    p_archivo = fopen("Texto1.txt", "w"); // Aqui tambien se pone la direccion donde se quiere crear el archivo
    fprintf(stdout, "Ingrese su nombre: \n"); //Escribir en el archivo "pantalla"
    fgets(Nombre, sizeof(Nombre), stdin);
    Nombre[strlen(Nombre)-1] = '\0'; //Reemplaza \n por \0
    fprintf(stdout, "Cuantos años tienes: \n");
    scanf("%d", &edad);
    if(p_archivo != NULL){
        printf("Se crea el archivo.\n");
        //Escribir una cadena de caracteres
        fprintf(p_archivo,"Este texto de prueba para el archivo Texto1.txt\n");
        //Escribir texto y variables
        fprintf(p_archivo, "Hola %s Bienvenido al curso\n", Nombre);
        //Escribir variables tipo int
        fprintf(p_archivo, "Edad = %d\n", edad);
    }

    fclose(p_archivo);

    return 0;
}
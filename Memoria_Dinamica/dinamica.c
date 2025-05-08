#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int i; // Están quedando guardadas en la pila
    int *puntero, tamano; // Tambien se guardan en la pila

    printf("Ingrese tamaño:");
    scanf("%d",&tamano);
    printf("\n");
    puntero = (int *) malloc(tamano*sizeof(int));
    // tamaño*sizeof(int) --> Tamaño en bytes a reservar
    // (int *) --> casting a puntero a entero
    for(i=0;i<tamano;i++){
          puntero[i]=i+1;
          printf("%d\n",puntero[i]);
    }
    free(puntero); // Liberar la memoria del heap
    return 0;
}
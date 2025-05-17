#include <stdio.h>
#include <stdlib.h>

int main(void){
    int cant_resist;
    float *resistencias, erres, denominador, resultado;

    printf("Ingrese cantidad de resistencias:\n");
    scanf("%d", &cant_resist);

    resistencias = (float*)calloc(cant_resist, sizeof(float));

    for(int i = 0; i < cant_resist; i++){
        printf("Ingrese la resistencia:\n");
        scanf("%f", &resistencias[i]);
    }

    for(int i = 0; i < cant_resist; i++){
        erres = 1 / resistencias[i];
        denominador = denominador + erres;
    }

    resultado = 1 / denominador;
    
    printf("La resistencia del circuito es: %f\n", resultado);

    free(resistencias);

    return 0;
}
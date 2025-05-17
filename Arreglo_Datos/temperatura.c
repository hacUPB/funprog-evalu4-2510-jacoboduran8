#include <stdio.h>
#include <time.h>
# include <stdlib.h>

int main(){
    srand(time(NULL)); // Generamos la semilla - Hace que el contador inicie siempre en un número diferente
    int temp[24]; // Con esto tenemos ya declara las 24 variables
    float media = 0;
    int hora;
    int max = 0; // Se inicializo el max en 0 para llevar conteo de la mayor temperatura
    int menor;

    /* Ahora tenemos que dar el valor de cada una */
    for(hora = 0; hora < 24; hora++)
    {
        temp[hora]= (rand() % ((35 -14) + 1)) + 14;
        media += temp[hora];

        if (temp[hora] > max){ //Se hace el condicional que cada vez que halla un número mayor que el max, se reescribe el valor de max
            max = temp[hora];
        }

        printf("\n%d", temp[hora]);
    }
    media = media / 24;

    /* También se puede hacer de la siguiente manera*/
    // mayor = temp[0]
    // for (int i = 0; i < 24; i++){
    // if (temp[i] > mayor){
    //mayor = temp[i]; }
    //}

    /* Ahora vamos a hacer el menor con el segundo metodo*/

    menor = temp[0];
    for (int i = 0; i < 24; i++){
        if (temp[i] < menor){ // Este es el condicional para que se cumpla la condicion
            menor = temp[i];
        }
    }

    printf("\nLa temperatura media es %f\n", media);
    printf("\nLa temperatura maxima en el dia fue: %d", max);
    printf("\nLa temperatura menor fue: %d", menor);

    // (rand() % (lim_sup - lim_inf + 1)) + limn_inf --> Operacion para generar un número aleatorio en un rango de números

    return 0;
}
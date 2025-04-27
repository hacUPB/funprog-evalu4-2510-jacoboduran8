#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ejercio 1
int main(){
    char frase[100];
    int contador = 0;
    char letra;

    //Pedimos al ususraio que ingrese una frase
    printf("Ingrese una frase: \n");
    fgets(frase, sizeof(frase), stdin);
    printf("%s\n", frase);

    for (int i = 0; i < strlen(frase); i++){

        letra = tolower(frase[i]); // Se hace para que todas las letras de la cadena se conviertan minusculas y que el contador sea más preciso y eficiente
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
            contador ++;
        }
    }

    printf("En la frase hay %d vocales\n", contador);

    return 0;
}

int main(){
    
}
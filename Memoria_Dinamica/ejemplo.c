#include <stdio.h>
#include <stdlib.h>

void func(void);

int main(void){
    func();
    func();
    func();
    func();
}

void func(void){
    static int cont = 0; // "static" le asigna un espacio diferente a la variable en la RAM, por lo que sirve para que no se reinicie cada vez que se llama a la función
    cont++;
    printf("Cont = %d\n", cont);
}

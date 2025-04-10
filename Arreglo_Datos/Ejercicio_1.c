#include <stdio.h>

int main(){
    int array_de_10[10];

    for (int i = 0; i < 10; i++){

        array_de_10[i] = i + 11;

        printf("%d\n", array_de_10[i]);
    }

    return 0;
}
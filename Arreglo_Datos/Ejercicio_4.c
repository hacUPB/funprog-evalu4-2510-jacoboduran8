#include <stdio.h>

int main(){
    int array_1[5];
    int array_2[5];
    int array_tot[10];
    int num;

    for (int i = 0; i <= 5; i++){
        printf("Di el numero:\n");
        scanf("%d", num);
        array_1[i] = num;
    }

    for (int i = 0; i <= 5; i++){
        printf("Di el numero:\n");
        scanf("%d", num);
        array_2[i] = num;
    }

    for (int i = 0; i <= 5; i++){
        array_tot[i] = array_1[i];
        printf("%d\n", array_tot[i]);
    }

    for (int i = 0; i <= 5; i++){
        array_tot[i] = array_2[i];
        printf("%d\n", array_tot[i]);
    }

    return 0;
}
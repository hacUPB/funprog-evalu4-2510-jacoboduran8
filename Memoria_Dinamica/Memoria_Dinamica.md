# Memoria Dinamica

## Función malloc( )
- Prototipo:
    `void *malloc(size_t size);`

- Parametros:
    size: número de bytes a asignar

- Retorno:

    --> Puntero al bloque de memoria asignado

    --> NULL - Si no se puede lograr

- Ejemplo:

        int *arr = (int *)malloc(5 * sizeof(int));
            if (arr == NULL) {
        }

## Función free( )
- Prototipo:
    `void free(void *ptr);`

- Parametros:
    Puntero a memoria ya asignada por malloc(), calloc(), realloc()

- Retorno: Ninguno porque es tipo `void`

- Ejemplo

        free(arr)


## Función calloc( )
- Prototipo:
    `void *calloc(size_t num, size_t size);`

- Parametros: 

    Numeros de elementos (num)

    Tamaño de bytes de cada elemento (size)

- Retorno: 
    Puntero a la memoria asignada e inicializa en cero (Tipo `void`)

- Ejemplo:

        int *arr = (int *)calloc(5, sizeof(int));
        if (arr == NULL) {
        }

## Función realloc( )
- Prototipo:
    `void *realloc(void *ptr, size_t new_size);`

- Parametros:

    Puntero a memoria previamente asignada (ptr)

    Nuevo tamaño en bytes (new_size)

- Retorno:
    Puntero al nuevo bloque de memoria

- Ejemplo

        arr = (int *)realloc(arr, 10 * sizeof(int));
        if (arr == NULL) {
        }

## Ejemplo de Clase

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

        free(resistencia);

        return 0;
    }

## Ejercicio

--> Reservar memoria para ingresar el nombre de un curso de la carrera

--> Solicitar y guardar el nombre

--> Redimensionar memoria para que el nombre quepa exacto

--> Solicitar el código NRC del curso

--> Redimensionar la memoria para guardar el nuevo dato
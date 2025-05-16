# Analisis de Reto Unidad 4

|Contenido|
|---------|
|[Lectura del Archivo](#lectura-del-archivo)|
|[Analisis de Texto](#analisis-de-un-texto)|

## Lectura del archivo

El proposito de esta función es que abra ek archivo y lo lea linea por linea. Despues une todo el contenido del archibo y lo retorna en una sola cadena de texto (char *texto). Para así poder analizarlo

### Ahora se analizara línea por línea el código de esta función, para entender su funcionamiento

        FILE *archivo = fopen(nombre, "r");

- Esta línea lo que hace es que abre el archivo en modo lectura (`r`) y archivo es un puntero a `FILE`.

        if(!archivo){
            printf("No se puede abrir el archivo\n");
            return 1;
        }

- En esta línea se comprueba si el archivo se puede abrir, si no se puede abrir retorna error.

        char linea[max_L];
        char *texto = NULL;
        int tamtotal = 0;

- Estas son otras variables con las que se trabajara en otro condicional:
    - `char linea` --> Es un buffer (lugar de memoria para guardar datos de manera temporal) para leer línea por línea el archivo.
    - `char *texto = NULL` --> Este puntero almacena el contenido que se pondra en una sola cadena de texto.
    - `int tamtotal = 0` --> Este es un contador, para contar el tamaño total del texto

            while (fgets(linea, max, archivo)){
                int largo = strlen(linea);
                char *nuevo = malloc(tamtotal + largo + 1);

                if(texto){
                    strcpy(nuevo, texto);
                    strcat(nuevo, linea);
                    free(texto);
                } else {
                    strcpy(nuevo, linea)
                }

                texto = nuevo;
                tamtotal = tamtotal + largo;
            }

- En este bucle lo que se hace es que con `fgets`se lee una línea del archivo y se guarda en `linea` y se repite hasta que llegue al final del archivo. Con `int largo = strlen(linea);`, se guard ala cantidad de caracteres de la línea que acabo de leer el bucle. Después con `char *nuevo = malloc(tamtotal + largo + 1);`, se reserva un nuevo espacio de memoria que incluye la línea anterior y el texto anterior, y a su vez agrega uno más por el caracter nulo. 

    Ya después el proposito del siguiente bucle es concatenar, asi que copia el texto anterior, se le añade la nueva línea y se libera la memoria de la línea anterior. Y si es la primera linea, solo se copia la línea en el nuevo bloque. 

    Y por último para guardar los cambios se actualiza el puntero y se aumenta el contador del tamaño.

    ## Analisis de un texto

    Lo que se busca hacer con esta función es que haga un analisis completo de un texto dado, su cantidad de palabras, espacios, lineas, y vocales. Cabe recalcar que para el desarrollo de esta funcion se usó una función nueva llamada `isspace`, que se encarga de comprobar si un caracter es un espacio en blanco y si es verdadero devuelve algo difente a 0 y si es falso devuelve un 0.  

            for(int i = 0; texto[i] != '\0'; i++)

- 
# Analisis de Reto Unidad 4

|Contenido|
|---------|
|[Datos generales del Reto](#datos-generales-del-reto)|
|[Lectura del Archivo](#lectura-del-archivo)|
|[Analisis de Texto](#analisis-de-un-texto)|
|[Reemplazar palabra](#reemplazar-palabra)|
|[Guardar](#guardar)|

## Datos generales del Reto

Para este reto fue muyu importante la investigación de nuevas funciones para poder optimizar el código lo más que se pueda. Cosas como `#define` y funciones de bibliotecas ya trabajadas en clase fueron clave. Sin embargo, la investigación y consulta de como se puede optimizar o el código fue crucial para terminarlo en el tiempo dado, ya que este reto si presentaba un mayor requerimiento de nivel y conocimiento previo que cualquiera de los anteriores. Aún así fue divertido implementar todo lo aprendido durante el semestre en un solo reto.

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

- Este bucle va por todo el texto caracter por caracter hasta que se encuenrtre con `\0`.

            char c = texto[i];

            if(c != '\n') (*caracteres)++;
            if(c == ' ') (*espacios)++;
            if(c == '\n') (*lineas)++;

- Este bucle cuenta los caracteres, espacios y lineas, sumando en cada uno de sus contadores.

            if(!isspace(c) && !dentro_palabra){
                (*palabra)++;
                dentro_palabra = 1
            } else if(isspace(c)){
                dentro_palabra = 0;}

- Lo que hace este bucle es que detecta si estamos en el inicio de una palabra o no, utilizando la nueva función aprendida `isspace`.

            c = tolower(c);
            if(c == 'a') vocales[0]++;
            if(c == 'e') vocales[1]++;
            if(c == 'i') vocales[2]++;
            if(c == 'o') vocales[3]++;
            if(c == 'u') vocales[4]++;

- Aquí con ya una función conocida se convierte la letra que se este analizando a miniuscula, y si es vocal, se suma en el arreglo de datos y en su respectiva posición.


## Reemplazar palabra

El proposito de esta funcion es es que reemplaza una palabra por otr y devuelve el texto con los camboios hechos.

Lo primero que se declara son las variables. Asi que `repeticion = 0`, es cantidad de veces que aparece la palabra que se quiere reemplzar. Y con `strlen()`, se calcula el largo de ambas palabras, la vieja y la nueva. 

            while((ptr = strstr(ptr, viejo)) != NULL){
                repeticion++;
                ptr = ptr + largo_viejo;
            }

- Para este condicional se uso una función nueva, `strstr`. Esta función se usa para encontrar la primera ocurrencia de una subcadena y devuelve un puntero la inicio de la subcadena encontrada.

Así que este pedazo de código cuenta cuantas veces aparece la palabra vieja usando esa función nueva.

            nuevo_tam = strlen(texto) + veces * (largo_nuevo - largo_viejo) + 1;
            resultado = malloc(nuevo_tam);
            destino = resultado;

- Aqui lo que hace es que calcula la diferencia de caracteres o tamaño entre la palabra vieja y la nueva, para así reservar el espacio de memoria.

- Y ya para finalizar lo que hace el resto de la función es verificar si encuentra la palabra vieja, la reemplza por la nueva, sino sigue su copiado normal.

## Guardar

El proposito de esta función es escribir en un archivo la estadisticas del texto.

Lo primero que hace la función es abrir el archivo en modo escritura `w`. Si no lo puede abrir retorna error. Después escribe las estadisticas del archivo una por una y después escribe el texto final ya modificado.
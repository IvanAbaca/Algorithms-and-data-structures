#include <stdio.h>
#include <stdlib.h>

// Cuando hago un fread del archivo lo cargo en un buffer, osea, que ademas de traerse el registro q le pedi, trae el resto del archivo
// Esto supone un problema cuando el archivo es pesado o tiene muchos registros por lo tanto lo mejor seria tener un indice el cual es una estructura mas liviana.
// Los indices los guardo en un archivo solo cuando el programa se cierra, para no tener que levantar una lista todo el tiempo, el objetivo es trabajar en memoria.
// Los arboles binarios optimizan las busquedas, y mayormente utilizan indices.

int main()
{
    printf("Hello world!\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

int main()
{
    tArbol arbol;
    int i;

    int vec[] = {100,50,25,75,125,150};

    crearArbol(&arbol);

    for(i=0; i<6; i++)
        insertarOrdenado(&arbol, vec+i, sizeof(int), cmpEnteros);

    recorrerArbolOrdenadoRID(&arbol, mostrarArbolEntero, NULL);

    return 0;
}

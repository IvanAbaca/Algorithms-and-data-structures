#include <stdio.h>
#include <stdlib.h>
#include "Clase1.h"

//Las instrucciones preprocesador son instruciones de texto (#).

// void qsort(void *base, size_t nmemb, size_t tamanyo,int (*comparar)(const void *, const void *));

// Cuando tengo una funcion sin definir quiere decir que mi archivo de header esta bien y pudo ser compilador pero al momento
// de hacer el link no pudo encontrar el codigo de la funcion para ejecutarlo.

// Hay 3 pasos Preparacion -> Compilacion -> Link-edicion.

int main()
{

    t_resultado vec[] = {{"HL", 4},
                        {"SM", 2},
                        {"JB", 5},
                        {"PB", 6},
                        {"JM", 1},
                        {"IU", 6}};

    mostrarEstructura(vec, sizeof(vec)/sizeof(t_resultado), sizeof(t_resultado));

    //qsort(vec, sizeof(vec)/sizeof(t_resultado), sizeof(t_resultado), (void*)cmpEstructura);
    ordenarSeleccion(vec, sizeof(vec)/sizeof(t_resultado), sizeof(t_resultado), (void*)cmpEstructura);

    puts("Ordenado: ");

    mostrarEstructura(vec, sizeof(vec)/sizeof(t_resultado), sizeof(t_resultado));


    return 0;
}

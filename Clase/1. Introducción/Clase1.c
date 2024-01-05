#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Clase1.h"

void mostrarEstructura(void* vec, unsigned ce, size_t tam)
{
    t_resultado* estr = (t_resultado*)vec;
    int i;

    for(i=0; i<ce; i++)
    {
        printf("%s, %d\n", estr->nyap, estr->puesto);
        estr++;
    }
}

int cmpEstructura(void* vec1, void* vec2)
{
    t_resultado* estr1 = (t_resultado*)vec1;
    t_resultado* estr2 = (t_resultado*)vec2;

    if(estr1->puesto != estr2->puesto)
        return estr1->puesto - estr2->puesto;

    else
        return strcmp(estr1->nyap, estr2->nyap);

}

void ordenarSeleccion(void* vec, size_t ce, size_t tam, int* cmpEstructura(void*, void*)) //(fin-vec)/tam -> me da la cantidad de elementos del vector.
{
    void* menor;
    void* fin = vec+(ce-1)*tam; // Calculo el final del vector.

    while(vec != fin) //Mientras mi puntero al inicio del vector sea diferente del final, sigo ordenando.
    {
        menor = buscarMenor(vec, fin, tam, (void*)cmpEstructura);

        if(menor != vec)
            intercambio(vec, menor, tam);

        vec+=tam;
    }
}



void intercambio(void* ele1, void* ele2, size_t tam)
{
    char* c1 = (char*)ele1;
    char* c2 = (char*)ele2;
    char aux;
    int i;

    for(i=0; i<tam; i++)
    {
        aux = *c1;
        *c1 = *c2;
        *c2 = aux;
        c1++;
        c2++;
    }
}

void* buscarMenor(void* vec, void* fin, size_t tam, int cmp(const void*, const void*))
{
    void* menor  = vec;
    vec+=tam;

    while(vec != fin)
    {
        if(cmp(vec, menor) < 0)
            menor = vec;

        vec+=tam;
    }

    return menor;
}

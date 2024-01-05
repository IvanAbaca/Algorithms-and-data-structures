#include "Funciones.h"

void crearLista(tLista* pl)
{
    *pl = NULL;
}

int poner_al_inicio(tLista* pl, const void* info, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam);
    nue->tam = tam;
    nue->sig = *pl;
    *pl = nue;

    return 1;
}

int pone_al_final(tLista* pl, const void* info, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    while(*pl)
        pl = &((*pl)->sig);

    memcpy(nue->info, info, tam);
    nue->tam = tam;
    nue->sig = NULL;

    *pl = nue;

    return 1;
}

int sacar_del_inicio(tLista* pl, void* info, size_t tam)
{
    return 1;
}

int sacar_del_final(tLista* pl, void* info, size_t tam)
{
    return 1;
}

void vaciarLista(tLista* pl)
{

}

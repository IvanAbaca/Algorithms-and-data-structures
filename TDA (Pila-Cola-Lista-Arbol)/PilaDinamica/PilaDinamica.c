#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PilaDinamica.h"

void crearPila(tPila* pp)
{
    pp = NULL;
}

int ponerEnPila(tPila* pp, const void* info, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 1;
    nue->info = malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 1;
    }
    nue->tam = tam;
    nue->sig = *pp;

    memcpy(nue->info, info, tam);

    *pp = nue;

    return 0;
}

int sacarDePila(tPila* pp, void* info, size_t tam)
{
    tNodo* elim = *pp;

    if(!elim)
        return 1;

    memcpy(info, elim->info, min(tam, elim->tam));

    *pp = elim->sig;

    free(elim->info);
    free(elim);

    return 0;
}

int verTopeDePila(const tPila* pp, void* info, size_t tam)
{
    if(!*pp)
        return 1;

    memcpy(info, (*pp)->info, min(tam, (*pp)->tam));

    return 0;
}

int pilaLlena(const tPila* pp, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 1;
    nue->info = malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 1;
    }

    free(nue->info);
    free(nue);

    return 0;
}

int pilaVacia(const tPila* pp)
{
    if(!*pp)
        return 1;
    return 0;
}

void vaciarPila(tPila* pp)
{
    tNodo* elim;

    while(*pp)
    {
        elim = *pp;

        *pp = elim->sig;

        free(elim->info);
        free(elim);
    }
}



/*

void crearPila(tPila* pp)
{
    *pp=NULL;
}

int ponerEnPila(tPila* pp, const void* info, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));
    void* elem = malloc(tam);

    if(!nue || !elem)
    {
        free(nue->info);
        free(nue);
        return -1;
    }

    memcpy(elem, info, tam);

    nue->info = elem;
    nue->tam = tam;
    nue->sig = *pp;

    *pp= nue;

    return 1;
}

int sacarDePila(tPila* pp, void* info, size_t tam)
{
    if(!*pp)
        return -1;

    tNodo* nae = *pp;
    *pp= nae->sig;

    memcpy(info,nae->info,min(tam,nae->tam));
    free(nae->info);
    free(nae);

    return 1;

}

int verTopeDePila(const tPila* pp, void* info, size_t tam)
{
    if(!*pp)
        return -1;

    tNodo* tope = *pp;

    memcpy(info, tope->info, min(tam, tope->tam));

    return 1;
}

int pilaLlena(const tPila* pp, size_t tam)
{
    tNodo* nodo = malloc(sizeof(tNodo));
    void* elem = malloc(tam);

    free(elem);
    free(nodo);

    return !nodo || !elem;
}

int pilaVacia(const tPila* pp)
{
    return (!*pp);
}

void vaciarPila(tPila* pp)
{
    tNodo* nae;

    while(*pp)
    {
        nae=*pp;
        *pp=nae->sig;
        free(nae->info);
        free(nae);
    }
}
*/

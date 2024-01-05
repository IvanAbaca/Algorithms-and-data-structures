#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ColaDinamica.h"

void crearCola(tCola* pc)
{
    pc->fondo = NULL;
    pc->frente = NULL;
}

int ponerEnCola(tCola* pc, const void* info, size_t tam)
{

    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 1;

    nue->info = malloc(tam);

    if(!(nue->info))
    {
        free(nue);
        return 1;
    }

    memcpy(nue->info, info, tam);
    nue->tam = tam;
    nue->sig = NULL;

    if(!pc->fondo)
        pc->frente = nue;
    else
        pc->fondo->sig = nue;
    pc->fondo = nue;

    return 0;
}

int sacarDeCola(tCola* pc, void* info, size_t tam)
{
    tNodo* elim = pc->frente;

    if(!pc->frente)
        return 1;

    memcpy(info, pc->frente->info, min(tam, pc->frente->tam));

    pc->frente = pc->frente->sig;

    if(!pc->frente)
        pc->fondo=NULL;

    free(elim->info);
    free(elim);
    return 0;
}

int verFrenteDeCola(const tCola* pc, void* info, size_t tam)
{
    memcpy(info, pc->frente->info, min(tam, pc->frente->tam));
    return 0;
}

int colaVacia(const tCola* pc)
{
    if(pc->fondo)
        return 1;
    return 0;
}

int colaLlena(const tCola* pc, size_t tam)
{
    tNodo* test = malloc(sizeof(tNodo));
    if(!test)
        return 1;

    test->info = malloc(tam);
    if(!test->info)
    {
        free(test);
        return 1;
    }

    free(test->info);
    free(test);

    return 0;
}

void vaciarCola(tCola* pc)
{
    tNodo* elim;

    while(pc->frente)
    {
        elim = pc->frente;
        pc->frente = pc->frente->sig;
        free(elim->info);
        free(elim);
    }
}































/*
void crearCola(tCola* pc)
{
    pc->fondo=NULL;
    pc->frente=NULL;
}

int ponerEnCola(tCola* pc, const void* info, size_t tam)
{
    if(!pc->frente)
        return -1;

    tNodo* nue = malloc(sizeof(tNodo));
    void* elem = malloc(tam);

    if(!nue || !elem)
    {
        free(elem);
        free(nue);
        return -1;
    }

    memcpy(elem, info, tam);

    nue->info = elem;
    nue->tam = tam;

    if(!pc->fondo)
        pc->frente= nue;
    else
        pc->fondo->sig= nue;

    pc->fondo=nue;

    return 1;
}

int sacarDeCola(tCola* pc, void* info, size_t tam)
{
    if(!pc->frente)
        return -1;

    tNodo* nae = pc->frente;
    pc->frente = nae->sig;

    if(!pc->frente)
        pc->fondo=NULL;

    memcpy(info, nae->info, min(tam, nae->tam));

    free(nae->info);
    free(nae);

    return 1;
}

int verFrenteDeCola(const tCola* pc, void* info, size_t tam)
{
    if(!pc->frente)
        return -1;

    const tNodo* frente = pc->frente;
    memcpy(info, frente->info, min(tam, frente->tam));

    return 1;
}

int colaVacia(const tCola* pc)
{
    return (!pc->frente);
}

int colaLlena(const tCola* pc, size_t tam)
{
    tNodo* nodo = malloc(sizeof(tNodo));
    void* elem = malloc(tam);

    free(elem);
    free(nodo);

    return !nodo || !elem;
}

void vaciarCola(tCola* pc)
{
    tNodo* nae;

    while(pc->frente)
    {
        nae =  pc->frente;
        pc->frente = nae->sig;
        free(nae->info);
        free(nae);
    }

    pc->fondo = NULL;
    pc->frente = NULL;

}
*/

#include "Funciones.h"
/*

void crearLista(tLista* pl)
{
    pl = NULL;
}

int poner_al_inicio(tLista* pl, const void* info, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam);

    nue->tam = tam;

    nue->sig = pl;

    *pl = nue;

    return 1;
}

int poner_en_una_pos(tLista* pl, const void* info, size_t tam, unsigned pos)
{
    tLista* aux = *pl;

    while(*pl && pos)
    {
        pl = &(*pl)->sig;
        pos--;
    }

    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam);

    nue->tam = tam;

    nue->sig = *pl;

    *pl->sig = nue;

    return 1;
}

int poner_en_orden(tLista* pl, const void* info, size_t tam, int* cmp(const void*, const void*))
{
    tLista* aux = *pl;
    // int comp;

    while(*pl && (comp = cmp(pd, (*pl)->info)) > 0)
        pl = &(*pl)->sig;

    // if(*pl && !comp) return dup;

    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam);

    nue->tam = tam;

    nue->sig = *pl;

    *pl->sig = nue;

    return 1;
}

int poner_al_final(tLista* pl, const void* info, size_t tam)
{
    tLista* aux = *pl;

    while(*pl)
        pl = &(*pl)->sig;

    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam);

    nue->tam = tam;

    nue->sig = NULL;

    *pl->sig = nue;

    return 1;
}

int sacar_del_inicio(tLista* pl, void* info, size_t tam)
{
    tNodo* elim = pl;

    if(!pl)
        return 0;

    memcpy(info, elim->info, min(elim->tam, tam));

    pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

int sacar_del_final(tLista* pl, void* info, size_t tam)
{
    tNodo* elim;

    if(!pl)
        return 0;

    while((*pl)->sig)
        pl = &(*pl)->sig;


    elim = *pl;

    memcpy(info, (*pl)->sig->, min(elim->tam, tam));

    *pl = elim->sig;

    free(elim->info);
    free(elim);

}

int sacar_elem_de_lista_ord(tLista* pl, void* info, size_t tam, int (*cmp)(const void*, const void*))
{
    tNodo* elim;
    int comp;

    if(!pl)
        return 0;

    while(*pl && (comp = cmp(info, (*pl)->info)) != 0) // while(*pl && cmp(info, (*pl)->info) -- if(!*pl)
        pl = &(*pl)->sig;


    if(!*pl || comp)
        return 0;

    elim = *pl;
    *pl = elim->sig;

    memcpy(info, elim->info, min(elim->tam, tam));

    free(elim->info);
    free(elim);

    return 1;
}

void vaciarLista(tLista* pl)
{

}
*/

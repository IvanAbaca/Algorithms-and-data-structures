#include "ListaH.h"

int insertarOrdenado(tListaD* pl, const void* info, size_t tam, int(*cmp)(const void*, const void*))
{
    tNodo* nue = malloc(sizeof(tNodo));
    tNodo* aux_sig = *pl;
    tNodo* aux_ant = aux_sig ? aux_sig->ant : NULL;

    while(aux_ant && cmp(info, aux_ant->info) < 0)
    {
        aux_sig = aux_ant;
        aux_ant = aux_ant->ant;
    }

    while(aux_sig && cmp(info, aux_sig->info) > 0)
    {
        aux_ant = aux_sig;
        aux_sig = aux_sig->sig;
    }

    if((aux_sig && cmp(info, aux_sig->info) == 0) || (aux_ant && cmp(info, aux_ant->info)))
    {
        return 0; // Duplicado.
    }

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

    nue->sig = aux_sig;

    nue->ant = aux_ant;

    if(*aux_ant)
        aux_ant->sig = nue;

    if(*aux_sig)
        aux_sig->ant = nue;

    *pl = nue;

    return 1;
}

int sacarDeListaD(tListaD* pl, void* info, size_t tam, int(*cmp)(const void*, const void*))
{
    tNodo* elim = *pl;

    while(elim && cmp(info, elim->info) < 0)
        elim = elim->ant;

    while(elim && cmp(info, elim->info) > 0)
        elim = elim->sig;

    if(elim || cmp(info, elim->info) != 0)
        return 0;

    memcpy(info, elim->info, min(elim->tam, tam));

    if(elim->ant)
        elim->ant->sig = elim->sig;

    if(elim->sig)
        elim->sig->ant = elim->ant;

    *pl = elim->sig ? elim->sig : elim->ant;

    free(elim->info);
    free(elim);

    return 1;
}

int primeroLista(tListaD* pl, void* info, size_t tam)
{
    if(!*pl)
        return 0;

    while((*pl)->ant)
        *pl = (*pl)->ant;

    memcpy(info, (*pl)->info, min(tam, (*pl)->tam));

    return 1;
}

int ultimoListaD(tListaD* pl, void* info, size_t tam)
{
    if(!*pl)
        return 0;

    while((*pl)->sig)
        *pl = (*pl)->sig;

    memcpy(info, (*pl)->info, min(tam, (*pl)->tam));

    return 1;
}

int siguienteListaD(tListaD* pl, void* info, size_t tam)
{

    if(!*pl || !(*pl)->sig)
        return 0;

    *pl = (*pl)->sig;

    memcpy(info, (*pl)->info, min(tam, (*pl)->tam));

    return 1;
}

int anteriorListaD(tListaD* pl, void* info, size_t tam)
{
    if(!*pl || !(*pl)->ant)
        return 0;

    *pl = (*pl)->ant;

    memcpy(info, (*pl)->info, min(tam, (*pl)->tam));

    return 1;
}

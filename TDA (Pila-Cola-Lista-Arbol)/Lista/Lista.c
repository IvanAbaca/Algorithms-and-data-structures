#include "Lista.h"
#include "Producto.h"

void crearLista(tLista* pl)
{
    *pl = NULL;
}

int insertarInicioLista(tLista* pl, const void* info, size_t tam)
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

    nue->tam = tam;
    memcpy(nue->info, info, tam);
    nue->sig = NULL;

    nue->sig = *pl;

    *pl = nue;

    return 1;
}

int insertarFinalLista(tLista* pl, const void* info, size_t tam)
{
    while(*pl)
        pl = &(*pl)->sig;

    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    memcpy(nue->info, info, tam);
    nue->sig = NULL;

    *pl = nue;

    return 1;
}

int insertarPosLista(tLista* pl, const void* info, size_t tam, unsigned pos)
{
    while(*pl && pos--)
        pl = &(*pl)->sig;

    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    memcpy(nue->info, info, tam);


    nue->sig = *pl;

    *pl = nue;

    return 1;
}

int insertarOrdenadoLista(tLista* pl, const void* info, size_t tam, int(* cmp)(const void*, const void*))
{
    while(*pl && cmp(info, (*pl)->info) > 0)
        pl = &(*pl)->sig;

    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    memcpy(nue->info, info, tam);


    nue->sig = *pl;

    *pl = nue;

    return 1;
}

int insertarOrdenadoSDup(tLista* pl, const void* info, size_t tam, int(* cmp)(const void*, const void*))
{
    while(*pl && cmp(info, (*pl)->info) > 0)
        pl = &(*pl)->sig;

    if(cmp(info, (*pl)->info) == 0)
        return 0;

    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue)
        return 0;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tam = tam;
    memcpy(nue->info, info, tam);

    nue->sig = *pl;

    *pl = nue;

    return 1;
}

int sacarInicioLista(tLista* pl, void* info, size_t tam)
{
    tNodo* elim;

    if(!*pl)
        return 0;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    elim = *pl;

    *pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

int sacarFinalLista(tLista* pl, void* info, size_t tam)
{
    tNodo* elim;

    if(!*pl)
        return 0;

    while((*pl)->sig)
        pl = &(*pl)->sig;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    elim = *pl;

    *pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

int sacarPosLista(tLista* pl, void* info, size_t tam, unsigned pos)
{
    tNodo* elim;

    if(!*pl)
        return 0;

    while(*pl && --pos)
        pl = &(*pl)->sig;

    if(pos>0)
        return 0;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    elim = *pl;

    *pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

int sacarElemLista(tLista* pl, void* info, size_t tam, int(* cmp)(const void*, const void*))
{
    tNodo* elim;

    if(!*pl)
        return 0;

    int comp = cmp(info, (*pl)->info);

    while(*pl && comp != 0)
    {
        pl = &(*pl)->sig;
        comp = cmp(info, (*pl)->info);
    }

    if(comp != 0)
        return 0;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    elim = *pl;

    *pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

int verInicioLista(const tLista* pl, void* info, size_t tam)
{
    if(!*pl)
        return 0;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    return 1;
}

int verFinalLista(const tLista* pl, void* info, size_t tam)
{
    if(!*pl)
        return 0;

    while((*pl)->sig)
        pl = &(*pl)->sig;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    return 1;
}

int verPosLista(const tLista* pl, void* info, size_t tam, unsigned pos)
{
    if(!*pl)
        return 0;

    while(*pl && pos--)
        pl = &(*pl)->sig;

    if(pos>0)
        return 0;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    return 1;
}

int buscarElemListaOrd(const tLista* pl, void* info, size_t tam, int(* cmp)(const void*, const void*))
{
    if(!*pl)
        return 0;

    int comp = cmp(info, (*pl)->info);

    while(*pl && comp != 0)
    {
        if(comp < 0)
            return 0;
        pl = &(*pl)->sig;
        comp = cmp(info, (*pl)->info);
    }

    if(comp != 0)
        return 0;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    return 1;
}

int buscarElemListaDesord(const tLista* pl, void* info, size_t tam, int(* cmp)(const void*, const void*))
{
    if(!*pl)
        return 0;

    int comp = cmp(info, (*pl)->info);

    while((*pl)->sig && comp != 0)
    {
        pl = &(*pl)->sig;
        comp = cmp(info, (*pl)->info);
    }

    if(comp != 0)
        return 0;

    memcpy(info, (*pl)->info, MIN(tam, (*pl)->tam));

    return 1;
}

int ordenarInfoLista(tLista* pl, int(* cmp)(const void*, const void*))
{
    if(!*pl)
        return 0;

    tNodo* ini = *pl;
    tNodo* menor;

    while(ini)
    {
        pl = &ini;
        menor = *pl;

        while(*pl)
        {
            if(cmp(menor->info, (*pl)->info) > 0)
                menor = *pl;

            pl = &(*pl)->sig;
        }

        if(ini != menor)
            intercambiarInfo(ini, menor);

        ini = ini->sig;
    }

    return 1;
}

int ordenarNodosLista(tLista* pl, int(* cmp)(const void*, const void*))
{
    tLista* pri = pl;
    if(*pl == NULL)
        return 1;

    while((*pl)->sig)
    if(cmp((*pl)->info, (*pl)->sig->info) == 1)
    {
        tLista *q = pri;
        tNodo *aux = (*pl)->sig;

        (*pl)->sig = aux->sig;

        while(cmp((*q)->info, aux->info) == -1)
            q = &(*q)->sig;

        aux->sig = *q;
        *q = aux;
    }
    else
        pl = &(*pl)->sig;
    return 0;
}

int ordenarListaAuxL(tLista* pl, int(* cmp)(const void*, const void*))
{
    if(!*pl)
        return 0;

    tLista* nue;

    *nue = NULL;

    tNodo* ini = *pl;
    tNodo* menor;

    while(ini)
    {
        pl = &ini;
        menor = *pl;

        while(*pl)
        {
            if(cmp(menor->info, (*pl)->info) > 0)
                menor = *pl;

            pl = &(*pl)->sig;
        }

        *nue = menor;
        nue = &(nue)->sig;

        ini = ini->sig;
    }

    return 1;
}

void intercambiarInfo(tNodo* pl, tNodo* menor)
{
    tNodo aux;

    aux.info = pl->info;
    aux.tam = pl->tam;

    pl->info = menor->info;
    pl->tam = menor->tam;

    menor->info = aux.info;
    menor->tam = aux.tam;
}

int mapLista(tLista* pl, void(* accion)(void*, unsigned, void*), void* param)
{
    if(!*pl)
        return 0;

    while(*pl)
    {
        accion((*pl)->info, (*pl)->tam, param);
        pl = &(*pl)->sig;
    }

    return 1;
}

int listaVacia(tLista* pl)
{
    if(!*pl)
        return 1;

    return 0;
}

void vaciarLista(tLista* pl)
{
    tNodo* elim;

    while(*pl)
    {
        elim = *pl;
        pl = &(*pl)->sig;
        free(elim->info);
        free(elim);
    }
}

int cargarListaDesdeArch(tLista* pl, const char* path, size_t tam)
{
    FILE* pf = fopen(path, "rb");
    if(!pf)
        return 0;

    tProd aux;

    fread(&aux, tam, 1, pf);

    while(!feof(pf))
    {
        insertarFinalLista(pl, &aux, tam);
        fread(&aux, tam, 1, pf);
    }

    fclose(pf);
    return 1;
}

int grabarArchDesdeLista(tLista* pl, const char* path, size_t tam)
{
    if(!*pl)
        return 0;

    FILE* pf = fopen(path, "wb");
    if(!pf)
        return 0;

    tProd aux;

    while(sacarInicioLista(pl, &aux, tam))
        fwrite(&aux, tam, 1, pf);

    fclose(pf);
    return 1;
}

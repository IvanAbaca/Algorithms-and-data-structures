#include "Arbol.h"

void crearArbolBinBusq(tArbol* pa)
{
    *pa = NULL;
}

int insertarArbolBinBusq(tArbol* pa, const void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    return 0;
}

int insertarRecArbolBinBusq(tArbol* pa, const void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    if(*pa && cmp((*pa)->info, d) == 1)
        return insertarRecArbolBinBusq(&(*pa)->hIzq, d, tam, cmp);

    if(*pa && cmp((*pa)->info, d) == -1)
        return insertarRecArbolBinBusq(&(*pa)->hDer, d, tam, cmp);

    if(*pa && cmp((*pa)->info, d) == 0)
        return 0;

    tNodoA* nue = malloc(sizeof(tNodoA));

    if(!nue)
        return 1;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 1;
    }

    memcpy(nue->info, d, tam);
    nue->hIzq = NULL;
    nue->hDer = NULL;

    *pa = nue;

    return 0;
}

void recorrerEnOrdenArbolBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{
    if(!*pa)
        return;

    recorrerEnOrdenArbolBinBusq(&((*pa)->hIzq), params, accion);
    accion((*pa)->info, 0, 0, params);
    recorrerEnOrdenArbolBinBusq(&((*pa)->hDer), params, accion);
}

void recorrerIRDBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{
    if(!*pa)
        return;

    recorrerEnOrdenArbolBinBusq(&((*pa)->hIzq), params, accion);
    accion((*pa)->info, 0, 0, params);
    recorrerEnOrdenArbolBinBusq(&((*pa)->hDer), params, accion);
}

void recorrerIDRArbolBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{
    if(!*pa)
        return;

    recorrerEnOrdenArbolBinBusq(&((*pa)->hIzq), params, accion);
    recorrerEnOrdenArbolBinBusq(&((*pa)->hDer), params, accion);
    accion((*pa)->info, 0, 0, params);
}

void recorrerRIDBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{
    if(!*pa)
        return;

    accion((*pa)->info, 0, 0, params);
    recorrerEnOrdenArbolBinBusq(&((*pa)->hIzq), params, accion);
    recorrerEnOrdenArbolBinBusq(&((*pa)->hDer), params, accion);
}

void recorrerEnOrdenSimpleArbolBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, void*))
{

}

void recorrerPreOrdenSimpleArbolBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, void*))
{

}

void recorrerPosOrdenSimpleArbolBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, void*))
{

}

int eliminarRaizArbolBinBusq(tArbol* pa)
{
    return 0;

}

int eliminarElemArbolBinBusq(tArbol* pa, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    int hi, hd;
    tArbol* reemp;
    tNodoA* elim;

    if(!*pa)
        return 1;

    memcpy(d, (*pa)->info, MIN(tam, (*pa)->tam));
    free((*pa)->info);

    if(!(*pa)->info)
    {
        free(pa);
        *pa = NULL;
        return 1;
    }

    hi = alturaArbolBin(&(*pa)->hIzq);
    hd = alturaArbolBin(&(*pa)->hDer);

    reemp = hi>hd? mayorNodo(&(*pa)->hIzq) : menorNodo(&(*pa)->hDer);

    elim = *reemp;
    (*pa)->info = elim->info;
    (*pa)->tam = elim->tam;

    *reemp = elim->hIzq ? elim->hIzq : elim->hDer;

    free(elim);

    return 0;
}

int buscarElemArbolBinBusq(const tArbol* pa, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    return 0;
}

int buscarElemNoClaveArbolBinBusq(const tArbol* pa, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    return 0;
}

int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbol* pa, FILE* pf, unsigned tamInfo)
{
    return 0;
}

int cargarArchivoBinOrdenadoArbolBinBusq(tArbol* pa, const char* path, unsigned tamInfo)
{
    return 0;
}

int cargarDesdeDatosOrdenadosArbolBinBusq(tArbol* pa, void* ds, unsigned cantReg, unsigned(* leer)(void**, void*, unsigned, void* params), void* params)
{
    return 0;
}

int mayorElemNoClaveArbolBinBusq(const tArbol* pa, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    return 0;
}

int menorElemNoClaveArbolBinBusq(const tArbol* pa, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    return 0;
}

unsigned alturaArbolBin(const tArbol* pa)
{
    int h1, h2;
    if(!*pa)
        return 0;

    h1 = alturaArbolBin(&((*pa)->hIzq));
    h2 = alturaArbolBin(&((*pa)->hDer));

    return MAX(h1, h2) + 1;
}

unsigned cantNodosArbolBin(const tArbol* pa)
{
    return 0;
}

unsigned cantNodosHastaNivelArbolBin(const tArbol* pa, int n)
{
    return 0;
}

int mayorElemArbolBinBusq(const tArbol* pa, void* d, unsigned tam)
{
    if(!*pa)
        return 1;

    while((*pa)->hDer)
        pa = &((*pa)->hDer);

    memcpy(d, (*pa)->info, MIN(tam, (*pa)->tam));
    return 0;
}

tNodoA** mayorNodo(tArbol* pa)
{
    if(!*pa)
        return 0;


    while((*pa)->hDer)
        pa = &((*pa)->hDer);

    return pa;
}

tNodoA** menorNodo(tArbol* pa)
{
    if(!*pa)
        return 0;


    while((*pa)->hIzq)
        pa = &((*pa)->hIzq);

    return pa;
}

int menorElemArbolBinBusq(const tArbol* pa, void* d, unsigned tam)
{
    if(!*pa)
        return 1;

    while((*pa)->hIzq)
        pa = &((*pa)->hIzq);

    memcpy(d, (*pa)->info, MIN(tam, (*pa)->tam));
    return 0;
}

int esCompletoArbolBin(const tArbol* pa)
{
    return 0;
}

int esBalanceadoArbolBin(const tArbol* pa)
{
    return 0;
}

int esAVLArbolBin(const tArbol* pa)
{
    return 0;
}

int esCompleto2ArbolBin(const tArbol* pa)
{
    return 0;
}

int esBalanceado2ArbolBin(const tArbol* pa)
{
    return 0;
}

int esAVL2ArbolBin(const tArbol* pa)
{
    return 0;
}

void mostrarInt(void* info, unsigned a, unsigned b, void* c)
{
    printf("\nNodo: %d", *(int*)info);
}

int cmpInt(const void* a, const void*b)
{
    if(*(int*)a < *(int*)b)
        return -1;
    if(*(int*)a > *(int*)b)
        return 1;
    return 0;
}

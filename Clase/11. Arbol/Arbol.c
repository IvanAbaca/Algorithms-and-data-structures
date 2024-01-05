#include "Arbol.h"

void crearArbol(tArbol* pa)
{
    *pa = NULL;
}

int insertarOrdenado(tArbol* pa, const void* info, size_t tam, int(* cmp)(const void*, const void*))
{


    if(*pa) // Si uso un while pasa a ser iterativo y no recursivo.
    {
        if(cmp(info, (*pa)->info) < 0)
            //pa = &(*pa)->izq;
            return insertarOrdenado(&(*pa)->izq, info, tam, cmp); // Para hacerlo recursivo, devuelvo la direccion del hijo izq, osea, donde deberia esta parado en mi siguiente arbol (siguiente padre) -> Son otros arboles.

        else if(cmp(info, (*pa)->info) > 0)
            //pa = &(*pa)->der;
            return insertarOrdenado(&(*pa)->der, info, tam, cmp); // Para hacerlo recursivo, devuelvo la direccion del hijo der, osea, donde deberia esta parado en mi siguiente arbol (siguiente padre) -> Son otros arboles.

        else
            return 0;
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

    nue->izq = nue->der = NULL;

    *pa = nue;

    return 1;
}

void recorrerArbolOrdenadoIRD(const tArbol* pa, void(* accion)(void*, void*), void* param) // Si lo imprimo asi, es muy probable de que no pueda llegar al mismo orden si lo quiero re-construir, me va a quedar un arbol balanceado, pero diferente.
{
    if(!*pa)
        return;

    recorrerArbolOrdenadoIRD(&(*pa)->izq, accion, param);

    accion((*pa)->info, param);

    recorrerArbolOrdenadoIRD(&(*pa)->der, accion, param);
}


void recorrerArbolOrdenadoIDR(const tArbol* pa, void(* accion)(void*, void*), void* param) // Hay algunas aplicacion, sirven mas que nada para los arboles de expresion.
{
    // La recorrida en pos-orden me mantiene el mismo arbol en caso de reconstruirlo insertandolo ordenadamente.

    if(!*pa)
        return;

    recorrerArbolOrdenadoIDR(&(*pa)->izq, accion, param);

    recorrerArbolOrdenadoIDR(&(*pa)->der, accion, param);

    accion((*pa)->info, param);

}

void recorrerArbolOrdenadoRID(const tArbol* pa, void(* accion)(void*, void*), void* param)
{


    if(!*pa)
        return;

    accion((*pa)->info, param);

    recorrerArbolOrdenadoRID(&(*pa)->izq, accion, param);

    recorrerArbolOrdenadoRID(&(*pa)->der, accion, param);
}

// Si no tengo un camino directo entonces estoy hablando de que voy a tener que recurrir a la recursividad.

void podarNivel(tArbol* pa, int n)
{
    if(!*pa)
        return;

    podarNivel(&(*pa)->izq, n-1);

    podarNivel(&(*pa)->der, n-1);

    if(n<0)
    {
        free((*pa)->info);
        free(*pa);
        *pa = NULL;
    }

}

int contarNodos(tArbol* pa)
{
    if(!*pa)
        return 0;

    return contarNodos(&(*pa)->izq) + contarNodos(&(*pa)->der) + 1;
}

int alturaArbol(tArbol* pa)
{
    int hi, hd;

    if(!*pa)
        return 0;

    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    return max(hi,hd) + 1;
}

tNodo** mayor(tArbol* pa)
{
    if(!*pa)
        return NULL;

    while((*pa)->der)
        pa = &(*pa)->der;

    return pa;
}

tNodo** menor(tArbol* pa)
{
    if(!*pa)
        return NULL;

    while((*pa)->izq)
        pa = &(*pa)->izq;

    return pa;
}

int eliminarRaiz(tArbol* pa, void* info, size_t tam)
{
    int hi, hd;
    tArbol* reemp;
    tNodo* elim;

    if(!*pa)
        return 0;

    memcpy(info, (*pa)->info, min(((*pa)->tam), tam));
    free((*pa)->info);

    if(!(*pa)->der && !(*pa)->izq)
    {

        free(pa);
        *pa = NULL;

        return 1;
    }

    // Tengo que elegir el nodo a eliminar de aquel arbol que sea mas alto, osea calculo las alturas y me fijo cual de los 2 que me den mas proximos es mas alto, esto es para  quede lo mas balanceado posible.

    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    reemp = hi > hd ? mayor(&(*pa)->izq) : menor(&(*pa)->der);

    elim = *reemp;

    (*pa)->info = elim->info;
    (*pa)->tam = elim->tam;

    *reemp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return 1;
}


void vaciarArbol(tArbol* pa)
{
    if(!*pa)
        return;

    vaciarArbol(&(*pa)->izq);

    vaciarArbol(&(*pa)->der);

    free((*pa)->info);
    free(*pa);
    *pa = NULL;
}


void mostrarArbolEntero(void* info, void* a)
{
    printf("%d\n", *(int*)info);
}

int cmpEnteros(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}


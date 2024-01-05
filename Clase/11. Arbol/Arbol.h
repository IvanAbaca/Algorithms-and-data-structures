#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define max(x,y) x > y ? x : y
#define min(x,y) x < y ? x : y
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct sNodo // Estaria parado en el padre, yo seria el padre.
{
    void* info;
    size_t tam;
    struct sNodo* izq, *der;

} tNodo;

typedef tNodo* tArbol;

void crearArbol(tArbol* pa);
int insertarOrdenado(tArbol* pa, const void* info, size_t tam, int(*cmp)(const void*, const void*));
void recorrerArbolOrdenadoIRD(const tArbol* pa, void (*accion)(void*, void*), void* param); // Siempre va a ser Izq -> Raiz -> Derecha y despues la raiz del padre a ese sub-arbol que acabamos de recorrer.
void recorrerArbolOrdenadoIDR(const tArbol* pa, void (*accion)(void*, void*), void* param); // Siempre va a ser Izq -> Derecha -> Raiz y despues la raiz del padre a ese sub-arbol que acabamos de recorrer.
void recorrerArbolOrdenadoRID(const tArbol* pa, void(* accion)(void*, void*), void* param);
void vaciarArbol(tArbol* pa);
tNodo** menor(tArbol* pa);
tNodo** mayor(tArbol* pa);
int cmpEnteros(const void* e1, const void* e2);
void mostrarArbolEntero(void* info, void* a);

#endif // ARBOL_H_INCLUDED

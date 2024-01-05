#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (x-y)?x:y
#define MAX(x,y) (x>y)?x:y
typedef struct sNodo
{
    struct sNodo* hIzq;
    void* info;
    size_t tam;
    struct sNodo* hDer;

}tNodoA;

typedef tNodoA* tArbol;

void crearArbolBinBusq(tArbol *pa);

int insertarArbolBinBusq(tArbol *pa, const void *d, unsigned tam,int (*cmp)(const void *, const void *));
int insertarRecArbolBinBusq(tArbol *pa, const void *d, unsigned tam,int (*cmp)(const void*, const void *));

void recorrerEnOrdenArbolBinBusq(const tArbol * pa, void * params,void (*accion)(void *, unsigned, unsigned, void*));
void recorrerRIDBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, unsigned, void*));
void recorrerIDRArbolBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, unsigned, void*));
void recorrerIRDBinBusq(const tArbol* pa, void* params, void(* accion)(void*, unsigned, unsigned, void*));
void recorrerEnOrdenSimpleArbolBinBusq(const tArbol *pa, void *params,void (*accion)(void *, unsigned, void *));
void recorrerPreOrdenSimpleArbolBinBusq(const tArbol *pa, void *params,void (*accion)(void *, unsigned, void *));
void recorrerPosOrdenSimpleArbolBinBusq(const tArbol *pa, void *params,void (*accion)(void *, unsigned, void *));

int eliminarRaizArbolBinBusq(tArbol *pa);
int eliminarElemArbolBinBusq(tArbol *pa, void *d, unsigned tam,int (*cmp)(const void *, const void *));

int buscarElemArbolBinBusq(const tArbol *pa, void *d, unsigned tam,int (*cmp)(const void *, const void *));
int buscarElemNoClaveArbolBinBusq(const tArbol *pa, void *d, unsigned tam,int (*cmp)(const void *, const void *));

int cargarArchivoBinOrdenadoAbiertoArbolBinBusq(tArbol *pa, FILE *pf,unsigned tamInfo);
int cargarArchivoBinOrdenadoArbolBinBusq(tArbol * pa, const char * path,unsigned tamInfo);
int cargarDesdeDatosOrdenadosArbolBinBusq(tArbol *pa,void *ds, unsigned cantReg,unsigned (*leer)(void **, void *, unsigned, void *params),void * params);

int mayorElemNoClaveArbolBinBusq(const tArbol *pa, void *d, unsigned tam,int (*cmp)(const void *, const void *));
int menorElemNoClaveArbolBinBusq(const tArbol *pa, void *d, unsigned tam,int (*cmp)(const void *, const void *));


//Utils
unsigned alturaArbolBin(const tArbol *pa);
unsigned cantNodosArbolBin(const tArbol *pa);
unsigned cantNodosHastaNivelArbolBin(const tArbol *pa, int n);
int mayorElemArbolBinBusq(const tArbol *pa, void *d, unsigned tam);
int menorElemArbolBinBusq(const tArbol *pa, void *d, unsigned tam);
int esCompletoArbolBin(const tArbol *pa);
int esBalanceadoArbolBin(const tArbol *pa);
int esAVLArbolBin(const tArbol *pa);
int esCompleto2ArbolBin(const tArbol *pa);
int esBalanceado2ArbolBin(const tArbol *pa);
int esAVL2ArbolBin(const tArbol *pa);

int cmpInt(const void* a, const void*b);
void mostrarInt(void* info, unsigned a, unsigned b, void* c);
tNodoA** mayorNodo(tArbol* pa);
tNodoA** menorNodo(tArbol* pa);

#endif // ARBOL_H_INCLUDED

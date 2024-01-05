#ifndef ARBOLDOSS_H_INCLUDED
#define ARBOLDOSS_H_INCLUDED


//||======================||    Librerias   ||==========================||

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//||======================||    Definiciones de macros   ||==========================||

#define TODO_OK 1
#define SIN_MEM 2
#define ERROR_ARCHIVO 3
#define DUPLICADO 4
#define NO_EXISTE 5
#define SIN_INICIALIZAR 6
#define FALSO 0

#define MIN(x,y) ((x<y)?(x):(y))
#define MAX(x,y) ((x>y)?(x):(y))
#define MOD(x) ((x>0)?(x):(-x))

//||======================||    Tipo de dato - estructura   ||==========================||

typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,*der;
}tNodoArbol;

typedef tNodoArbol *tArbol;

//||======================||    TDA Arbol   ||==========================||

//crear
void crearArbol(tArbol *p);
//insertar
int insertarArbol(tArbol *p, const void *d, unsigned tam, int (*cmp)(const void *, const void *));
int insertarRecArbol(tArbol *p, const void *d, unsigned tam, int (*cmp)(const void*, const void *));
//recorrer
void recorrerEnOrdenArbol(const tArbol * p, void * params, void (*accion)(void *, unsigned, unsigned, void *));
void recorrerEnOrdenInversoArbol(const tArbol * p, void * params, void (*accion)(void *, unsigned, unsigned, void *));
void recorrerPreOrdenArbol(const tArbol * p, void * params, void (*accion)(void *, unsigned, unsigned, void *));
void recorrerPosOrdenArbol(const tArbol * p, void * params, void (*accion)(void *, unsigned, unsigned, void *));
//eliminar
int eliminarRaizArbol(tArbol* p, void* d, size_t tam, int(*cmp)(const void*, const void*));
int eliminarElemArbol(tArbol *p, void *d, unsigned tam, int (*cmp)(const void *, const void *));
//buscar
int buscarElemArbol(const tArbol *p, void *d, unsigned tam,int (*cmp)(const void *, const void *));
//cargar en archivo
int cargarArchivoBinOrdenadoAbiertoArbol(tArbol *p, FILE *pf,unsigned tamInfo);
int cargarArchivoBinOrdenadoArbol(tArbol * p, const char * path,unsigned tamInfo);
int cargarDesdeDatosOrdenadosArbol(tArbol *p,void *ds, unsigned cantReg,unsigned (*leer)(void **, void *, unsigned, void *params),void * params);
int cargarDesdeArchivoPreOrdenArbol(tArbol * p, const char * path, unsigned tamInfo, int (*cmp)(const void *, const void *));
int cargarDesdeDatosPreOrdenArbol(tArbol *p, void *ds, unsigned cantReg,unsigned (*leer)(void **, void *, unsigned, void *params),
                                 int (*cmp)(const void *, const void *), void * params);
//grabar en archivo
int grabarEnArchivoOrdenadoArbolBin(tArbol *p, const char * path);

//||======================||    Utils   ||==========================||

//Altura y nodos
unsigned alturaArbolBin(const tArbol *p);
unsigned cantNodosArbolBin(const tArbol *p);
unsigned cantNodosHastaNivelArbolBin(const tArbol *p, int n);
//Caracteristicas de arbol
int completoHastaNivelArbolBin(const tArbol* p, int n);
int esCompletoArbolBin(const tArbol *p);
int esBalanceadoArbolBin(const tArbol *p);
int esAVLArbolBin(const tArbol *p);
//Vaciar
void vaciarArbolBin(tArbol *p);
//Buscar Mayor/Menor
int mayorElemArbol(const tArbol *p, void *d, unsigned tam);
int menorElemArbol(const tArbol *p, void *d, unsigned tam);
tNodoArbol** mayorNodo(tArbol* p);
tNodoArbol** menorNodo(tArbol* p);
tNodoArbol** buscarNodoArbol(tArbol* p, void*d,int (*cmp)(const void*, const void*));

//||======================||    Extras para arbol   ||==========================||

int cmpInt(const void* a, const void* b);
void mostrarInt(void* info, unsigned a, unsigned b, void* c);
void imprimirMensaje(int res);
void cargarEnArchBin(void* info, unsigned a, unsigned b, void* c);
int cargarDatosDesdeArch(tArbol* p, void* orig, unsigned tam, int li, int ls,
                         int(*acccion)(void*, void*, unsigned, int));
int copiarDatoArch(void* info, void* orig, unsigned tam, int media);
int mostrarArbolProd(tArbol* pa, int(*mostrar)(void*, unsigned, unsigned, void*));
void arbolGrafico(const tArbol *p, void(*mostrar)(const void *));


#endif

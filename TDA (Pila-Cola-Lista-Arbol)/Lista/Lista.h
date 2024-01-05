#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


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

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;

}tNodo;

typedef tNodo* tLista;

//||======================||    TDA Lista   ||==========================||

void crearLista(tLista* pl);

int insertarInicioLista(tLista* pl, const void* info, size_t tam);
int insertarFinalLista(tLista* pl, const void* info, size_t tam);
int insertarPosLista(tLista* pl, const void* info, size_t tam, unsigned pos);
int insertarOrdenadoLista(tLista* pl, const void* info, size_t tam, int(*cmp)(const void*, const void*));
int insertarOrdenadoSDup(tLista* pl, const void* info, size_t tam, int(*cmp)(const void*, const void*));

int sacarInicioLista(tLista* pl, void* info, size_t tam);
int sacarFinalLista(tLista* pl, void* info, size_t tam);
int sacarPosLista(tLista* pl, void* info, size_t tam, unsigned pos);
int sacarElemLista(tLista* pl, void* info, size_t tam, int(*cmp)(const void*, const void*));

int verInicioLista(const tLista* pl, void* info, size_t tam);
int verFinalLista(const tLista* pl, void* info, size_t tam);
int verPosLista(const tLista* pl, void* info, size_t tam, unsigned pos);
int buscarElemListaOrd(const tLista* pl, void* info, size_t tam, int(*cmp)(const void*, const void*));
int buscarElemListaDesord(const tLista* pl, void* info, size_t tam, int(*cmp)(const void*, const void*));

int ordenarInfoLista(tLista* pl, int(*cmp)(const void*, const void*));
int ordenarNodosLista(tLista* pl, int(*cmp)(const void*, const void*));
int ordenarListaAuxL(tLista* pl, int(*cmp)(const void*, const void*));

void intercambiarInfo(tNodo* pl, tNodo* menor);

int mapLista(tLista* pl, void(*accion)(void*, unsigned, void*), void* param);

int listaVacia(tLista* pl);
void vaciarLista(tLista* pl);

//||===================================||     Extras      ||==============================||

int cargarListaDesdeArch(tLista* pl, const char* path, size_t tam);
int grabarArchDesdeLista(tLista* pl, const char* path, size_t tam);


#endif // LISTA_H_INCLUDED

#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y) (x-y)?x:y

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    char codProd[8];
    int encu;
    int zona;
}t_encuesta;

typedef struct
{
    char codProd[8];
    char nombre[50];
}t_prod;

int crearArchBin(const char* arch);
int crearArchTxt(const char* arch);
int cargarDeArchBin(t_encuesta* encu, const char* arch);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;
    struct sNodo* ant;

}tNodo;

typedef tNodo* tListaD;

void crearLista(tListaD* pl);

int insertarInicioLista(tListaD* pl, const void* info, size_t tam);
int insertarFinalLista(tListaD* pl, const void* info, size_t tam);
int insertarPosLista(tListaD* pl, const void* info, size_t tam, unsigned pos);
int insertarOrdenadoLista(tListaD* pl, const void* info, size_t tam, int(*cmp)(void*, const void*));
int insertarOrdenadoSDup(tListaD* pl, const void* info, size_t tam, int(*cmp)(void*, const void*));

int sacarInicioLista(tListaD* pl, void* info, size_t tam);
int sacarFinalLista(tListaD* pl, void* info, size_t tam);
int sacarPosLista(tListaD* pl, void* info, size_t tam, unsigned pos);
int sacarElemLista(tListaD* pl, void* info, size_t tam, int(*cmp)(void*, const void*));

int verInicioLista(const tListaD* pl, void* info, size_t tam);
int verFinalLista(const tListaD* pl, void* info, size_t tam);
int verPosLista(const tListaD* pl, void* info, size_t tam, unsigned pos);
int buscarElemListaOrd(const tListaD* pl, void* info, size_t tam, int(*cmp)(void*, const void*));
int buscarElemListaDesord(const tListaD* pl, void* info, size_t tam, int(*cmp)(void*, const void*));

//int mapLista();
//int filterLista();
//int reduceLista();
//
int ordenarInfoLista(tListaD* pl, int(*cmp)(void*, const void*));
int ordenarNodosLista(tListaD* pl, int(*cmp)(void*, const void*));
int ordenarListaAuxL(tListaD* pl, int(*cmp)(void*, const void*));
//
int listaLlena(const tListaD* pl, size_t tam);
int listaVacia(const tListaD* pl);
//
void vaciarLista(tListaD* pl);

int cmpInt(void* a, const void* b);
void mostrarLista(tListaD* pl);
void mostrarListaIni(tListaD* pl);
#endif // LISTADOBLE_H_INCLUDED

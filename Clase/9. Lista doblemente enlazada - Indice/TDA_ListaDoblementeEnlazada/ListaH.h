#ifndef LISTAH_H_INCLUDED
#define LISTAH_H_INCLUDED

#define min(x,y) x < y ? x : y

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Mi puntero a la lista puede quedar en cualquier nodo, entonces lo que hago es dejarlo en el ultimo nodo que inserte.

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig, *ant;

} tNodo;

typedef tNodo* tListaD;

int insertarOrdenado(tListaD* pl, const void* info, size_t tam, int(*cmp)(const void*, const void*));
int sacarDeListaD(tListaD* pl, void* info, size_t tam, int(*cmp)(const void*, const void*));
int primeroLista(tListaD* pl, void* info, size_t tam);
int ultimoListaD(tListaD* pl, void* info, size_t tam);
int siguienteListaD(tListaD* pl, void* info, size_t tam);
int anteriorListaD(tListaD* pl, void* info, size_t tam);


#endif // LISTAH_H_INCLUDED

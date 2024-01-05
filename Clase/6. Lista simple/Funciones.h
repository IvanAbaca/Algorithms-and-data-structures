#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define min(x,y) x < y ? x : y

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;

} tNodo;

typedef tNodo* tLista;

void crearLista(tLista* pl);
int poner_al_inicio(tLista* pl, const void* info, size_t tam);
int pone_al_final(tLista* pl, const void* info, size_t tam);
int sacar_del_inicio(tLista* pl, void* info, size_t tam);
int sacar_del_final(tLista* pl, void* info, size_t tam);
void vaciarLista(tLista* pl);

#endif // FUNCIONES_H_INCLUDED

#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define min(x,y) ((x)<(y))? (x) : (y)

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tPila;

void crearPila(tPila* pp);
int ponerEnPila(tPila* pp, const void* info, size_t tam);
int sacarDePila(tPila* pp, void* info, size_t tam);
int verTopeDePila(const tPila* pp, void* info, size_t tam);
int pilaLlena(const tPila* pp, size_t tam);
int pilaVacia(const tPila* pp);
void vaciarPila(tPila* pp);

#endif // PILADINAMICA_H_INCLUDED

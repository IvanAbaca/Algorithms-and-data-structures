#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define min(x,y) ((x)<(y))? (x) : (y)

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;

}tNodo;

typedef struct
{
    struct sNodo* frente;
    struct sNodo* fondo;

}tCola;

void crearCola(tCola* pc);
int ponerEnCola(tCola* pc, const void* info, size_t tam);
int sacarDeCola(tCola* pc, void* info, size_t tam);
int verFrenteDeCola(const tCola* pc, void* info, size_t tam);
int colaVacia(const tCola* pc);
int colaLlena(const tCola* pc, size_t tam);
void vaciarCola(tCola* pc);

#endif // COLADINAMICA_H_INCLUDED

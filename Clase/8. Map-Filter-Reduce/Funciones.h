#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;

} tNodo;

typedef tNodo* tPila;

#endif // FUNCIONES_H_INCLUDED

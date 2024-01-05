#ifndef LISTAH_H_INCLUDED
#define LISTAH_H_INCLUDED

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

typedef struct
{
    int dni;
    char nyap[50];
    float promedio;

} tAlumno;

typedef tNodo* tLista;

void crear_lista(tLista* pl);
int poner_al_inicio(tLista* pl, const void* info, size_t tam);
int poner_al_final(tLista* pl, const void* info, size_t tam);
int poner_en_una_pos(tLista* pl, const void* info, size_t tam, unsigned pos);
int poner_en_orden(tLista* pl, const void* info, size_t tam, int (*cmp)(const void*, const void*));
int sacar_del_inicio(tLista* pl, void* info, size_t tam);
int sacar_del_final(tLista* pl, void* info, size_t tam);
int sacar_un_elem(tLista* pl, void* info, size_t tam, void* elem, int (*cmp)(const void*, const void*));
int lista_vacia(const tLista* pl);
int lista_llena(const tLista* pl, size_t tam);
int ver_inicio_lista(tLista* pl, void* info, size_t tam);
int ver_ultimo_lista(tLista* pl, void* info, size_t tam);
void vaciar_lista(tLista* pl);
int cmpEnteros(const void* e1, const void* e2);
int cmpCadenas(const void* s1, const void* s2);

void map_lista(const tLista* pl, void(*accion)(void*, void*), void* param);
void grabar_arch_bin(void* vinfo, void* vpf);

#endif // LISTAH_H_INCLUDED


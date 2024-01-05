#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TAM_COLA 40
#define min(x,y) x > y ? y : x

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char vec[TAM_COLA];
    unsigned frente;
    unsigned fondo;
    unsigned tam_disp;

}tCola;

void crear_cola(tCola* pc);
int poner_en_cola(tCola* pc, const void* info, size_t tam);
int sacar_de_cola(tCola* pc, void* info, size_t tam);
int ver_frente_de_cola(tCola* pc, void* info, size_t tam);
void vaciar_cola(tCola* pc);
int cola_llena(const tCola* pc, size_t tam);
int cola_vacia(const tCola* pc);


#endif // FUNCIONES_H_INCLUDED

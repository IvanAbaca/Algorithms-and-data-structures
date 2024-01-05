#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// Archivo binario q tiene el stock, quiere q guardemos el pedido y que si con el stock q hay se puede realizar el pedido, si esto se valida, hay que actualizar el stock y guardar el pedido en el archivo de pedidos a entregar.
// Si el pedido no se puede realizar, guardarlo en un archivo de errores o de sin stock.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MEN(x,y) x < y ? x : y

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;

} tNodo;

typedef struct
{
    tNodo* pri;
    tNodo* ult;

} tCola;

typedef struct
{
    int nro_ped;
    char cod_prod[20];
    int cant;
    int precio;

} tProd;

void crear_cola(tCola* pc);
int poner_en_cola(tCola* pc, const void* info, size_t tam);
int sacar_de_cola(tCola* pc, void* pd, size_t tam);
int cola_llena(const tCola* pc, size_t tam);
int cola_vacia(const tCola* pc);
void vaciar_cola(tCola* pc);
int frente_de_cola(const tCola* pc, void* info, size_t tam);

//----------------------------------------------------------------------------------------------

void crearArchivoBin(const char* arch);


#endif // FUNCIONES_H_INCLUDED

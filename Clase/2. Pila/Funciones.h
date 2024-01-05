#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAM_PILA 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEN(x,y) (x < y)? (x) : (y)
#define archbin "emp.bin"


typedef struct
{
    char nyap[50];
    int legajo;
    float sueldo;
}tEmpleado;

//-------------------------PILA ESTATICA---------------------
typedef struct
{
    char vec[TAM_PILA];
    unsigned tope;

} tPila;

int ponerEnPila(tPila* pp, const void* elem, size_t tam);
int sacarDePila(tPila* pp, void* elem, size_t tam);
void crearPila(tPila* pp);
void vaciarPila(tPila* pp);
int verTope(const tPila* pp, void* elem, size_t tam);
int pilaLlena(const tPila* pp, size_t tam);
int pilaVacia(const tPila* pp);


/*-------------------------PILA DINAMICA---------------------

typedef struct sNodo
{
    size_t tam;
    void* elem;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tPila;

int     din_apilar      (tPila* pp, const void* elem, size_t tam);
int     din_desapilar   (tPila* pp, void* elem, size_t tam);
int     din_verTope     (const tPila* pp, void* elem, size_t tam);
void    din_crear       (tPila* pp);
int     din_llena       (const tPila* pp, size_t tam);
int     din_vacia       (const tPila* pp);
void    din_vaciar      (tPila* pp);*/

//Ejercicio 4
int crearBin(const char* arch);
int leerBin(tPila* pp, const char* arch);
int escribirBin(tPila* pp, const char* arch);
void mostrarEmpleado(const char* arch);

/*
Ejercicio 2.4
Escriba un programa que al comenzar lea (si lo puede abrir) un archivo de binario <"datos">, y lo
cargue en una pila con implementación estática de memoria. El archivo debe ser cerrado al terminar
la carga de la pila. A continuación, y valiéndose de una función de menú:
cargar más
tope de la pila
sacar de la pila
salir del menú.
Al salir del menú, se terminará de cargar el archivo con la información que aún quede en la pila.
Si el archivo resultara vacío, deberá ser eliminado.
Pruebe repetidamente el programa, hasta que logre que el archivo quede con información.

*/

#endif // FUNCIONES_H_INCLUDED

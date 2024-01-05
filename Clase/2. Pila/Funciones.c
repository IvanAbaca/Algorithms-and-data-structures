#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarEmpleado(const char* arch)
{
    tEmpleado aux;

    FILE* pf = fopen(arch, "rb");

    fread(&aux, sizeof(tEmpleado), 1, pf);

    while(!feof(pf))
    {
        printf("Nombre y Apellido: %s\nLegajo: %d\nSueldo: %.2f\n\n", aux.nyap, aux.legajo, aux.sueldo);
        fread(&aux, sizeof(tEmpleado), 1, pf);

    }

    fclose(pf);
}


int crearBin(const char* arch)
{
    tEmpleado empleado[] = {{"Pepin Pepon", 111, 120.5},
                            {"Pepin Pepan", 112, 220.5},
                            {"Pepin Pepun", 113, 320.5},
                            {"Pepin Pepin", 114, 720.5},
                            {"Pepin Pepen", 115, 520.5},
                            {"Pepin Pepln", 116, 420.5},
                           };
    FILE* pf = fopen(arch, "wb");
    if(!pf)
        return 0;
    fwrite(empleado, sizeof(tEmpleado), sizeof(empleado)/sizeof(tEmpleado), pf);
    fclose(pf);
    return 1;
}

int leerBin(tPila* pp, const char* arch)
{
    FILE* pf = fopen(arch, "rb");
    if(!pf)
        return 0;
    tEmpleado emp;

    fread(&emp, sizeof(tEmpleado), 1, pf);
    while(!feof(pf))
    {
        ponerEnPila(pp, &emp, sizeof(tEmpleado));
        fread(&emp, sizeof(tEmpleado), 1, pf);
    }
    fclose(pf);
    return 1;
}


int escribirBin(tPila* pp, const char* arch)
{
    if(pilaVacia(pp))
    {
        remove(archbin);
        return 1;
    }

    tEmpleado emp;

    FILE* pf = fopen(arch, "wb");

    if(!pf)
        return 0;

    while(!pilaVacia(pp))
    {
        sacarDePila(pp, &emp, sizeof(tEmpleado));
        fwrite(&emp, sizeof(tEmpleado), 1, pf);
    }

    fclose(pf);

    return 1;
}


/*-------------------------PILA DINAMICA---------------------

void din_crear(tPila* pp)
{
    *pp=NULL;
}

int din_apilar (tPila* pp, const void* elem, size_t tam)
{
    tNodo* aux = malloc(sizeof(tNodo)); //Reservo
    if(!aux) //Compruebo si lo guarda
    {
        free(aux);
        return 0;
    }
    aux->elem = malloc(tam); //Reservo

    if(!aux->elem)   //Compruebo si lo guarda
    {
        free(aux->elem);
        free(aux);
        return 0;
    }

    memcpy(aux->elem, elem, tam); //Me copio el elemento en la mem dinamica
    aux->tam = tam; //Me copio el tamaño
    aux->sig = *pp; //Asigno como siguiente mi anterior nodo

    *pp = aux;  //Pongo como primer elemento el nodo actual

    return 1;
}

int din_desapilar(tPila* pp, void* elem, size_t tam)
{
    if(!*pp)    //reviso que tenga algun nodo
        return 0;

    tNodo* aux = *pp; //inicializo un auxiliar para guardar la direccion del nodo
    *pp=aux->sig;

    memcpy(elem, aux->elem, MEN(tam, aux->tam));
    free(aux->elem);
    free(aux);
    return 1;
}

int din_verTope (const tPila* pp, void* elem, size_t tam)
{
    if(!*pp)    //reviso que tenga algun nodo
        return 0;
    memcpy(elem, (*pp)->elem, MEN(tam, (*pp)->tam)); //Guardo el elem

    return 1;
}

int din_llena(const tPila* pp, size_t tam)
{
    tNodo* aux = malloc(sizeof(tNodo)); //reservo para el tnodo
    aux->elem = malloc(sizeof(tam)); //reservo para elem

    free(aux->elem); //libero ambos
    free(aux);

    return !aux || !aux->elem; //Si alguno es nulo tonces está lleno
}


int din_vacia(const tPila* pp)
{
    if(*pp)         //reviso que tenga algun nodo
        return 0;   //Si no me da nulo entonces tiene algo la pila
    return 1;       //Si me da nulo entonces es falso y significa que la pila esta vacia
}

void din_vaciar(tPila* pp)
{
    tNodo* aux = *pp; //creo aux
    while(*pp)  //Cuando sea nulo me voy
    {
        *pp = aux->sig;     //guardo el siguiente nodo
        free(aux->elem);    //Libero el elemento del actual
        free(aux);          //Libero el nodo
        aux = *pp;          //Me paro en el siguiente nodo
    }
}
*/

//-------------------------PILA ESTATICA---------------------
void crearPila(tPila* pp)
{
    pp->tope = TAM_PILA;
}

int ponerEnPila(tPila* pp, const void* elem, size_t tam)
{
    if(pp->tope < tam+sizeof(size_t))
    {
        return 0;
    }

    pp->tope -= tam;

    memcpy(((pp->vec)+(pp->tope)), elem, tam);

    pp->tope -= sizeof(size_t);

    memcpy(((pp->vec)+(pp->tope)), &tam, sizeof(size_t));

    return 1;
}

int sacarDePila(tPila* pp, void* elem, size_t tam)
{
    size_t tamElem;

    if(pp->tope == TAM_PILA)
        return 0;

    memcpy(&tamElem, (pp->vec + pp->tope), sizeof(size_t));

    pp->tope += sizeof(size_t);

    memcpy(elem, (pp->vec + pp->tope), MEN(tam, tamElem));

    pp->tope += tamElem;

    return 1;
}

int verTope(const tPila* pp, void* elem, size_t tam)
{
    size_t tamElem;

    if(pp->tope == TAM_PILA)
        return 0;

    memcpy(&tamElem, (pp->vec + pp->tope), sizeof(size_t));

    memcpy(elem, (pp->vec + pp->tope + sizeof(size_t)), MEN(tam, tamElem));

    return 1;
}

int pilaLlena(const tPila* pp, size_t tam)
{
    if(pp->tope < tam + sizeof(size_t))
        return 1;

    return 0;
}

int pilaVacia(const tPila* pp)
{
    if(pp->tope == TAM_PILA)
        return 1;

    return 0;
}

void vaciarPila(tPila* pp)
{
    pp->tope = TAM_PILA;
}


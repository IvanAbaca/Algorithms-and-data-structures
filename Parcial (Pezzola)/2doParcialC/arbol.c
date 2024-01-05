#include <tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <arbol.h>

#define MIN(x,y) ((x<y)?(x):(y))
#define MAX(x,y) ((x>y)?(x):(y))
//||==============================================||    Punto A: Baja    ||================================================||

//Voy a necesitar la funcion eliminarElem
//Para eliminarElem necesito eliminarRaiz
//Para eliminarRaiz necesito AlturaArbol, MayorNodo y MenorNodo
//E implementar todo en la funcion baja

int eliminarRaizArbolBinBusq(tArbolBinBusq *p)
{
    tNodoArbol** reemp;
    tNodoArbol* elim;

    if(!*p)
        return NO_EXISTE;

    free((*p)->info);

    if(!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p = NULL;
        return TODO_OK;
    }

    int hi = alturaArbolBin(&(*p)->izq);
    int hd = alturaArbolBin(&(*p)->der);

    reemp = hi > hd ? mayorRecNodoArbol(&(*p)->izq) : menorRecNodoArbol(&(*p)->der);

    elim = *reemp;

    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;

    *reemp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return TODO_OK;
}

int eliminarElemArbolBinBusq(tArbolBinBusq *p, void *d, unsigned tam,
                             int (*cmp)(const void *, const void *))
{
    if(!*p)
        return NO_EXISTE;

    int comp = cmp(d, (*p)->info);

    if(comp > 0)
        return eliminarElemArbolBinBusq(&(*p)->der, d, tam, cmp);

    if(comp < 0)
        return eliminarElemArbolBinBusq(&(*p)->izq, d, tam, cmp);

    memcpy(d, (*p)->info, MIN(tam, (*p)->tamInfo));

    return eliminarRaizArbolBinBusq(p);
}

unsigned alturaArbolBin(const tArbolBinBusq *p)
{
    if(!*p)
        return 0;

    int hi = alturaArbolBin(&(*p)->izq);
    int hd = alturaArbolBin(&(*p)->der);

    return MAX(hi, hd) + 1;
}

tNodoArbol** mayorRecNodoArbol(tArbolBinBusq* p)
{
    if(*p && (*p)->der)
        return mayorRecNodoArbol(&(*p)->der);
    return p;
}

tNodoArbol** menorRecNodoArbol(tArbolBinBusq* p)
{
    if(*p && (*p)->izq)
        return menorRecNodoArbol(&(*p)->izq);
    return p;
}

//||===========================================||    Punto B: GrabarEnArch    ||===========================================||


//Voy a necesitar recorrer y crear una accion que grabe en el archivo

int grabarEnArchivoOrdenadoArbolBin(tArbolBinBusq* p, const char* path)
{
    FILE* pf = fopen(path, "wb");

    if(!pf)
        return ERROR_ARCHIVO;

    recorrerEnOrdenArbolBinBusq(p, pf, (void*)copiarDatoAlArchivo);

    fclose(pf);

    return TODO_OK;
}

void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq* p, void* params, void(*accion)(const void*, unsigned, unsigned, const void*))
{//IRD

    if(!*p)     //Corto cuando no tengo mas nodos
        return;

    recorrerEnOrdenArbolBinBusq(&(*p)->izq, params, accion);    //Nodo de la izquierda
    accion((*p)->info, (*p)->tamInfo, 0, params);               //Nodo actual
    recorrerEnOrdenArbolBinBusq(&(*p)->der, params, accion);    //Nodo de la derecha
}

void copiarDatoAlArchivo(const void* info, unsigned tam, unsigned x, const void* orig)
{
    FILE* pf = (FILE*)orig;

    fwrite(info, tam, 1, pf);
}


//||============================================||    Punto C: VaciarArbol    ||===========================================||

void vaciarArbolBin(tArbolBinBusq *p)
{
    if(!*p)
        return;

    vaciarArbolBin(&(*p)->izq);
    vaciarArbolBin(&(*p)->der);

    free((*p)->info);
    free(*p);

    *p = NULL;
}

//||============================================||    Punto Extra: darAlta    ||=========================================||


//Necesito poder insertar en orden en el arbol

int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam, int (*cmp)(const void*, const void *))
{
    if(*p && cmp(d, (*p)->info) > 0)
        return insertarRecArbolBinBusq(&(*p)->der, d, tam, cmp);

    if(*p && cmp(d, (*p)->info) < 0)
        return insertarRecArbolBinBusq(&(*p)->izq, d, tam, cmp);

    if(*p && cmp(d, (*p)->info) == 0)
        return DUPLICADO;

    tNodoArbol* nue = malloc(sizeof(tNodoArbol));
    if(!nue)
        return SIN_MEM;

    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }

    nue->der = nue->izq = NULL;
    nue->tamInfo = tam;
    memcpy(nue->info, d, tam);

    *p = nue;

    return TODO_OK;
}


//||============================================||    Punto Extra: AgregarMateria    ||=========================================||

//Para agregar materia requiero la funcion buscar para conseguir el nroReg
//Leo el registro del archivo, divido el promedio por la cant de materias actuales, le sumo la nota y o divido por la cantidad de materias nuevas
//Escribo el registro y termina mi funcion


int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam, int (*cmp)(const void *, const void *))
{
    if(!*p)
        return NO_EXISTE;

    int comp = cmp(d, (*p)->info);

    if(*p && comp > 0)
        return buscarElemArbolBinBusq(&(*p)->der, d, tam, cmp);

    if(*p && comp < 0)
        return buscarElemArbolBinBusq(&(*p)->izq, d, tam, cmp);

    memcpy(d, (*p)->info, MIN(tam, (*p)->tamInfo));

    return TODO_OK;
}

//||============================================||    Punto Extra: AgregarMateria    ||=========================================||

int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq * p, const char * path, unsigned tamInfo)
{
    FILE* pf = fopen(path, "rb");

    if(!pf)
        return ERROR_ARCHIVO;

    fseek(pf, 0L, SEEK_END);

    int cantReg = ftell(pf) / tamInfo;

    int r;

    if((r=cargarDatosDesdeArch(p, pf, tamInfo, 0, cantReg-1, (void*)copiarArchAlArbol)) != TODO_OK)
        return r;

    fclose(pf);

    return r;
}

int cargarDatosDesdeArch(tArbolBinBusq* p, void* orig, size_t tam, int li, int ls, int(*accion)(void*, void*, unsigned, int))
{
    if(li > ls)
        return TODO_OK;

    int media = (li + ls)/2;

    int r;

    tNodoArbol* nue =  malloc(sizeof(tNodoArbol));

    if(!nue)
        return SIN_MEM;

    nue->info = malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }

    nue->der = nue->izq = NULL;
    nue->tamInfo = tam;

    accion(nue->info, orig, tam, media);

    *p = nue;

    if((r=cargarDatosDesdeArch(&(*p)->izq, orig, tam, li, media-1, accion))!=TODO_OK)
        return r;

    return cargarDatosDesdeArch(&(*p)->der, orig, tam, media+1, ls, accion);
}

int copiarArchAlArbol(void* info, void* orig, unsigned tam, int media)
{
    int r;

    FILE* pf = (FILE*)orig;

    fseek(pf, tam*media, SEEK_SET);

    if((r = fread(info, tam, 1, pf)) == 0)
        return ERROR_ARCHIVO;

    return TODO_OK;
}

//||============================================||    Punto Extra: GraficarArbol    ||=========================================||

void arbolGrafico(const tArbolBinBusq *p, void(*mostrar)(const void *))
{
    graficarArbol(p, mostrar, 0);
}

void graficarArbol(const tArbolBinBusq *p, void(*mostrar)(const void *), int nivel)
{
    if(!*p)
        return;

    int i;

    graficarArbol(&(*p)->der, mostrar, nivel+1);
    for(i=0; i<nivel; i++)
        printf("    ");
    mostrar((*p)->info);
    puts("");
    graficarArbol(&(*p)->izq, mostrar, nivel+1);
}








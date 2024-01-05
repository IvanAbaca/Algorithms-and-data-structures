#include "ArbolDoss.h"
/*
void crearArbol(tArbol* p)
{
    *p = NULL;
}

int insertarArbol(tArbol* p, const void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    tNodoArbol* nue = malloc(sizeof(tNodoArbol));
    if(!nue)
        return SIN_MEM;
    nue->info = malloc(tam);

    if(!(nue->info))
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = tam;
    memcpy(nue->info, p, tam);
    nue->der = nue->izq = NULL;

    while(*p)
    {
        if(cmp(d, (*p)->info) > 0)
            p = &(*p)->der;
        else if(cmp(d, (*p)->info) < 0)
            p = &(*p)->izq;
        else if(cmp(d, (*p)->info) == 0)
            return DUPLICADO;
    }

    *p = nue;

    return TODO_OK;
}

int insertarRecArbol(tArbol* p, const void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    if(*p && cmp(d, (*p)->info) > 0)
        return insertarRecArbol(&(*p)->der, d, tam, cmp);

    if(*p && cmp(d, (*p)->info) < 0)
        return insertarRecArbol(&(*p)->izq, d, tam, cmp);

    if(*p && cmp(d, (*p)->info) == 0)
        return DUPLICADO;

    tNodoArbol* nue = malloc(sizeof(tNodoArbol));
    if(!nue)
        return SIN_MEM;

    nue->info = malloc(tam);
    if(!(nue->info))
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = tam;
    nue->izq = nue->der = NULL;
    memcpy(nue->info, d, tam);

    *p = nue;

    return TODO_OK;
}

void recorrerEnOrdenArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//IRD
    if(!*p)
        return;
    recorrerEnOrdenArbol(&(*p)->izq, params, accion);
    accion((*p)->info, (*p)->tamInfo, 0, params);
    recorrerEnOrdenArbol(&(*p)->der, params, accion);
}

void recorrerEnOrdenInversoArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//DRI
    if(!*p)
        return;
    recorrerEnOrdenInversoArbol(&(*p)->der, params, accion);
    accion((*p)->info, (*p)->tamInfo, 0, params);
    recorrerEnOrdenInversoArbol(&(*p)->izq, params, accion);
}

void recorrerPreOrdenArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//RID
    if(!*p)
        return;
    accion((*p)->info, (*p)->tamInfo, 0, params);
    recorrerPreOrdenArbol(&(*p)->izq, params, accion);
    recorrerPreOrdenArbol(&(*p)->der, params, accion);
}

void recorrerPosOrdenArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//IDR
    if(!*p)
        return;
    recorrerPosOrdenArbol(&(*p)->izq, params, accion);
    recorrerPosOrdenArbol(&(*p)->der, params, accion);
    accion((*p)->info, (*p)->tamInfo, 0, params);
}

int eliminarRaizArbol(tArbol* p, void* d, size_t tam, int(*cmp)(const void*, const void*))
{
    tNodoArbol** reemp;
    tNodoArbol* elim;

    if(!*p)
        return NO_EXISTE;

    memcpy(d, (*p)->info, MIN(tam, (*p)->tamInfo));
    free((*p)->info);

    if(!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p = NULL;
        return TODO_OK;
    }

    int altIzq = alturaArbolBin(&(*p)->izq);
    int altDer = alturaArbolBin(&(*p)->der);

    reemp = (altIzq > altDer)? mayorNodo(&(*p)->izq) : menorNodo(&(*p)->der);

    elim = *reemp;

    (*p)->tamInfo = elim->tamInfo;
    (*p)->info = elim->info;

    *reemp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return TODO_OK;
}

int eliminarElemArbol(tArbol* p, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    if(!*p)
        return NO_EXISTE;

    if(cmp(d, (*p)->info) > 0)
        return eliminarElemArbol(&(*p)->der, d, tam, cmp);

    if(cmp(d, (*p)->info) < 0)
        return eliminarElemArbol(&(*p)->izq, d, tam, cmp);

    eliminarRaizArbol(p, d, tam, cmp);

    return TODO_OK;
}

int buscarElemArbol(const tArbol* p, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    if(!*p)
        return NO_EXISTE;

    if(cmp(d, (*p)->info) > 0)
        return buscarElemArbol(&(*p)->der, d, tam, cmp);

    if(cmp(d, (*p)->info) < 0)
        return buscarElemArbol(&(*p)->izq, d, tam, cmp);

    memcpy(d, (*p)->info, MIN(tam, (*p)->tamInfo));

    return TODO_OK;
}

int cargarArchivoBinOrdenadoAbiertoArbol(tArbol* p, FILE* pf, unsigned tamInfo) //Ete
{
    fseek(pf, 0, SEEK_END);
    int cantReg = ftell(pf)/tamInfo - 1;

    return cargarDatosDesdeArch(p, pf, tamInfo, 0, cantReg, (void*)cargarDatos);
}

int cargarDatosDesdeArch(tArbol* p, void* orig, unsigned tam, int li, int ls,
                         int(*accion)(void*, void*, unsigned, int))
{
    int media = (ls + li)/2;

    if(li > ls)
        return TODO_OK;

    tNodoArbol* nue = malloc(sizeof(tNodoArbol));
    if(!nue)
        return SIN_MEM;

    nue->info = malloc(tam);
    if(!(nue->info))
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = tam;
    nue->der = nue->izq = NULL;

    int r = accion(nue->info, orig, tam, media);

    if(r != TODO_OK)
        return r;

    *p = nue;

    r = cargarDatosDesdeArch(&(*p)->izq, orig, tam, li, media-1, accion);

    if(r != TODO_OK)
        return r;

    return cargarDatosDesdeArch(&(*p)->der, orig, tam, media+1, ls, accion);
}

int cargarDatos(void* info, void* orig, unsigned tam, int media)
{
    FILE* pf = (FILE*)orig;

    fseek(pf, media*tam, SEEK_SET);

    int r = fread(info, tam, 1, pf);

    if(r == 0)
        return ERROR_ARCHIVO;

    return TODO_OK;
}

int cargarArchivoBinOrdenadoArbol(tArbol* p, const char* path, unsigned tamInfo)
{
    if(*p)
        return ERROR_ARCHIVO;

    FILE* pf = fopen(path, "rb");

    fseek(pf, 0, SEEK_END);
    int cantReg = ftell(pf)/tamInfo - 1;
    int r = cargarDatosDesdeArch(p, pf, tamInfo, 0, cantReg, (void*)cargarDatos);

    fclose(pf);
    return r;
}

int cargarDesdeDatosOrdenadosArbol(tArbol* p, void* ds, unsigned cantReg, unsigned(* leer)(void**, void*, unsigned, void* params), void* params)
{
    return 1;
}

int cargarDesdeArchivoPreOrdenArbol(tArbol* p, const char* path, unsigned tamInfo, int(* cmp)(const void*, const void*))
{
    return 1;
}

int cargarDesdeDatosPreOrdenArbol(tArbol* p, void* ds, unsigned cantReg, unsigned(* leer)(void**, void*, unsigned, void* params), int(* cmp)(const void*, const void*), void* params)
{
    return 1;
}

int grabarEnArchivoOrdenadoArbolBin(tArbol* p, const char* path)
{
    FILE* pf = fopen(path, "wb");
    recorrerEnOrdenArbol(p, pf, cargarEnArchBin);
    fclose(pf);
    return TODO_OK;
}

unsigned alturaArbolBin(const tArbol *p)
{
    if(!*p)
        return 0;

    int hi = alturaArbolBin(&(*p)->izq);
    int hd = alturaArbolBin(&(*p)->der);


    return MAX(hi, hd) + 1;
}

unsigned cantNodosArbolBin(const tArbol *p)
{
    if(!*p)
        return 0;

    return cantNodosArbolBin(&(*p)->izq) + cantNodosArbolBin(&(*p)->der) + 1;
}

unsigned cantNodosHastaNivelArbolBin(const tArbol *p, int n)
{
    if(!*p || n < 0)
        return 0;

    return cantNodosHastaNivelArbolBin(&(*p)->izq, n-1) + cantNodosHastaNivelArbolBin(&(*p)->der, n-1) + 1;
}

int mayorElemArbol(const tArbol* p, void* d, unsigned tam)
{
    if(!*p)
        return NO_EXISTE;

    while((*p)->der)
        p = &(*p)->der;

    memcpy(d, (*p)->info, MIN(tam, (*p)->tamInfo));

    return TODO_OK;
}

int menorElemArbol(const tArbol* p, void* d, unsigned tam)
{
    if(!*p)
        return NO_EXISTE;

    while((*p)->izq)
        p = &(*p)->izq;

    memcpy(d, (*p)->info, MIN(tam, (*p)->tamInfo));

    return TODO_OK;
}

int completoHastaNivelArbolBin(const tArbol* p, int n)
{
    if(!*p)
        return 0;

    if(n == 0)
        return TODO_OK;

    return completoHastaNivelArbolBin(&(*p)->izq, n-1) && completoHastaNivelArbolBin(&(*p)->der, n-1);
}

int esCompletoArbolBin(const tArbol* p)
{
    return completoHastaNivelArbolBin(p, alturaArbolBin(p)-1);
}

int esBalanceadoArbolBin(const tArbol* p)
{
    return completoHastaNivelArbolBin(p,alturaArbolBin(p)-2);
}

int esAVLArbolBin(const tArbol* p)
{
    if(!*p)
        return TODO_OK;

    int hi = alturaArbolBin(&(*p)->izq);
    int hd = alturaArbolBin(&(*p)->der);

    if((MOD(hi-hd)) > 1)
        return FALSO;

    if(!esAVLArbolBin(&(*p)->izq) || !esAVLArbolBin(&(*p)->der))
        return FALSO;

    return TODO_OK;
}

void vaciarArbolBin(tArbol* p)
{
    if(!*p)
        return;

    vaciarArbolBin(&(*p)->izq);
    vaciarArbolBin(&(*p)->der);

    free((*p)->info);
    free(*p);

    *p = NULL;
}

void arbolGrafico(const tArbol* p, void(* mostrar)(const void*))
{

}

tNodoArbol** mayorNodo(tArbol* p)
{
    while((*p)->der)
        p = &(*p)->der;
    return p;
}

tNodoArbol** menorNodo(tArbol* p)
{
    while((*p)->izq)
        p = &(*p)->izq;
    return p;
}



//||======================||    Extras para arbol   ||==========================||



int cmpInt(const void* a, const void*b)
{
    int na = *(int*)a, nb = *(int*)b;

    if(na > nb)
        return 1;
    else if(na < nb)
        return -1;
    return 0;
}


void mostrarInt(void* info, unsigned a, unsigned b, void* c)
{
    printf("\nNodo: %d", *(int*)info);
}

void imprimirMensaje(int res)
{
    switch(res)
    {
        case TODO_OK: printf("\nOperacion realizada correctamente.\n");
                break;
        case SIN_MEM: printf("\nError de memoria.\n");
                break;
        case ERROR_ARCHIVO: printf("\nError en el archivo.\n");
                break;
        case DUPLICADO: printf("\nRegistro duplicado.\n");
                break;
        case NO_EXISTE: printf("\nRegistro inexistente.\n");
                break;
        case FALSO: printf("\nEnunciado falso.\n");
                break;
        case SIN_INICIALIZAR: printf("\nNo inicializado.\n");
                break;
        break;
    }
}

void cargarEnArchBin(void* info, unsigned tam, unsigned b, void* c)
{
    FILE* pf = (FILE*)c;

    fwrite(info, tam, 1, pf);
}

//||======================||    Extras para archivos   ||==========================||


int mostrarArbolProd(tArbol* pa, int(*mostrar)(void*, unsigned, unsigned, void*))
{
    if(!*pa)
        return NO_EXISTE;

    printf("\n\n||=============||\tProductos\t||=============||\n\n");
    printf("\n      Codigo\t   Descripcion\t\tPrecio\n");
    printf("--------------------------------------------------------");
    recorrerEnOrdenArbol(pa, pa, (void*)mostrar);
    printf("\n--------------------------------------------------------");
    return TODO_OK;
}
*/

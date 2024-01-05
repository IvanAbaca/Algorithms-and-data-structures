#include "ListaDoble.h"

void crearLista(tListaD* pl)
{
    *pl = NULL;
}


int crearArchTxt(const char* arch)
{
    int i;

    t_prod prod[] =
    {
        {"K1028",   "Balizas Verde Agua"},
        {"A5",      "Cereales"},
        {"F125",    "Cable de Yeso"},
        {"J173",    "Destornillador"},
        {"B92",     "Aspiradora"},
        {"M320",    "Luz LED"},
    };

    FILE* pf = fopen(arch, "wt");

    if(!pf)
        return 1;

    for(i=0; i<sizeof(prod)/sizeof(t_prod); i++)
        fprintf(pf, "%s~%s\n", prod[i].codProd, prod[i].nombre);

    fclose(pf);

    return 0;
}


int crearArchBin(const char* arch)
{
    t_encuesta encu[] =
    {
        {"K1028", 24, 7},   {"K1028", 73, 2},   {"A5", 13, 5},
        {"B92", 1, 18},     {"A5", 9, 2},       {"K1028", 24, 7},
        {"M320", 9, 3},     {"K1028", 24, 17},  {"K1028", 24, 13},
        {"J173", 5, 11},    {"K1028", 24, 7},   {"K1028", 10, 10},
        {"M320", 1, 6},
    };

    FILE* pf = fopen(arch, "wb");

    if(!pf)
        return 1;

    fwrite(&encu, sizeof(encu), sizeof(encu)/sizeof(t_encuesta), pf);

    fclose(pf);
    return 0;
}

int cargarDeArchBin(t_encuesta* encu, const char* arch)
{
    FILE* pf = fopen(arch, "rb");

    if(!pf)
        return 1;

    int i=0;

    fread(encu, sizeof(t_encuesta), 1, pf);
    while(!feof(pf))
        fread(&(encu[i]), sizeof(t_encuesta), 1, pf);

    return 0;
}







int insertarInicioLista(tListaD* pl, const void* info, size_t tam)
{

    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue)
        return 1;

    nue->info = malloc(tam);

    if(!(nue->info))
    {
        free(nue);
        return 1;
    }

    memcpy(nue->info, info, tam);
    nue->tam = tam;
    nue->ant = NULL;

    while(*pl && (*pl)->ant)
        pl = &((*pl)->ant);

    nue->sig = *pl;

    if(*pl)
        (*pl)->ant = nue;


    *pl = nue;
    return 0;
}

int insertarFinalLista(tListaD* pl, const void* info, size_t tam)
{
    return 0;
}

int insertarPosLista(tListaD* pl, const void* info, size_t tam, unsigned pos)
{
    return 0;
}

int insertarOrdenadoLista(tListaD* pl, const void* info, size_t tam, int(* cmp)(void*, const void*))
{
    tNodo* ant = *pl;
    tNodo* sig = *pl;
    tNodo* aux = *pl;

    while(ant && cmp(ant->info, info) == 1)
    {
        aux = ant;
        ant = ant->ant;
    }

    while(sig && cmp(sig->info, info) == -1)
    {
        aux = sig;
        sig = sig->sig;
    }

    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 1;

    nue->info = malloc(tam);

    if(!(nue->info))
    {
        free(nue);
        return 1;
    }

    memcpy(nue->info, info, tam);
    nue->tam = tam;

    if(cmp(aux->info, info) == -1)
    {
        nue->sig = sig;
        nue->ant = aux;
        aux->sig = nue;

    }
    else if(cmp(aux->info, info) == 1)
    {
        nue->ant = ant;
        nue->sig = aux;
        aux->ant = nue;
    }

    *pl = nue;
    return 0;
}

int insertarOrdenadoSDup(tListaD* pl, const void* info, size_t tam, int(* cmp)(void*, const void*))
{
    return 0;
}

int sacarInicioLista(tListaD* pl, void* info, size_t tam)
{
    return 0;
}

int sacarFinalLista(tListaD* pl, void* info, size_t tam)
{
    return 0;
}

int sacarPosLista(tListaD* pl, void* info, size_t tam, unsigned pos)
{
    return 0;
}

int sacarElemLista(tListaD* pl, void* info, size_t tam, int(* cmp)(void*, const void*))
{
    if(!*pl)
        return 0;

    tNodo* elim = *pl;

    while(elim && cmp(info, elim->info) == -1)
        elim = elim->ant;

    while(elim && cmp(info, elim->info) == 1)
        elim = elim->sig;

    if(cmp(info, elim->info) != 0)
        return 0;

    memcpy(info, elim->info, MIN(elim->tam, tam));

    if(elim->ant)
        elim->ant->sig = elim->sig;

    if(elim->sig)
        elim->sig->ant = elim->ant;

    *pl = elim->sig ? elim->sig : elim->ant;

    free(elim->info);
    free(elim);

    return 1;
}

int verInicioLista(const tListaD* pl, void* info, size_t tam)
{
    return 0;
}

int verFinalLista(const tListaD* pl, void* info, size_t tam)
{
    return 0;
}

int verPosLista(const tListaD* pl, void* info, size_t tam, unsigned pos)
{
    return 0;
}

int buscarElemListaOrd(const tListaD* pl, void* info, size_t tam, int(* cmp)(void*, const void*))
{
    return 0;
}

int buscarElemListaDesord(const tListaD* pl, void* info, size_t tam, int(* cmp)(void*, const void*))
{
    return 0;
}

int ordenarInfoLista(tListaD* pl, int(* cmp)(void*, const void*))
{
    return 0;
}

int ordenarNodosLista(tListaD* pl, int(* cmp)(void*, const void*))
{
    return 0;
}

int ordenarListaAuxL(tListaD* pl, int(* cmp)(void*, const void*))
{
    return 0;
}

int listaLlena(const tListaD* pl, size_t tam)
{
    return 0;
}

int listaVacia(const tListaD* pl)
{
    return 0;
}

void vaciarLista(tListaD* pl)
{

}

int cmpInt(void* a, const void* b)
{
    if(*(int*)a < *(int*)b)
        return -1;
    if(*(int*)a > *(int*)b)
        return 1;
    return 0;
}

void mostrarLista(tListaD* pl)
{
    int cont = 1;
    while(*pl)
    {
        printf("Nodo %d: value = %5d\n", cont++, *(int*)((*pl)->info));
        pl = &((*pl)->sig);
    }
}

void mostrarListaIni(tListaD* pl)
{
    int cont = 1;

    while(*pl && (*pl)->ant)
        pl = &((*pl)->ant);
    while(*pl)
    {
        printf("Nodo %d: value = %5d\n", cont++, *(int*)((*pl)->info));
        pl = &((*pl)->sig);
    }
}

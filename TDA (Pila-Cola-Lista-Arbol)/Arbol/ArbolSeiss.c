
#include "ArbolDoss.h"


void crearArbol(tArbol* p)
{
    *p =NULL;
}

int insertarRecArbol(tArbol* p, const void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    tNodoArbol* nue;
    int comp;

    if(*p)
    {
        comp= cmp(d, (*p)->info);
        if(comp<0)
            return insertarArbol(&(*p)->izq,d,tam,cmp);
        if(comp>0)
            return insertarArbol(&(*p)->der,d,tam,cmp);
        return DUPLICADO;
    }

    nue = malloc(sizeof(tNodoArbol));
    nue->info = malloc(tam);

    if(!nue || !(nue->info))
    {
        free(nue->info);
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = tam;
    memcpy(nue->info,d,tam);
    nue->der = nue->izq = NULL;

    *p = nue;

    return TODO_OK;

}

void recorrerEnOrdenArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//IRD
    if(!*p)
        return 0;

    recorrerEnOrdenArbol(&(*p)->izq,params,accion);
    accion((*p)->info, (*p)->tamInfo, 0, params);
    recorrerEnOrdenArbol(&(*p)->der,params,accion);
}

void recorrerEnOrdenInversoArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//DRI
    if(!*p)
        return 0;

    recorrerEnOrdenInversoArbol(&(*p)->der,params,accion);
    accion((*p)->info, (*p)->tamInfo, 0, params);
    recorrerEnOrdenInversoArbol(&(*p)->izq,params,accion);
}

void recorrerPreOrdenArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//RID
    if(!*p)
        return 0;

    accion((*p)->info, (*p)->tamInfo, 0, params);
    recorrerPreOrdenArbol(&(*p)->izq,params,accion);
    recorrerPreOrdenArbol(&(*p)->der,params,accion);
}

void recorrerPosOrdenArbol(const tArbol* p, void* params, void(* accion)(void*, unsigned, unsigned, void*))
{//IDR
    if(!*p)
        return 0;

    recorrerPosOrdenArbol(&(*p)->izq,params,accion);
    recorrerPosOrdenArbol(&(*p)->der,params,accion);
    accion((*p)->info, (*p)->tamInfo, 0, params);
}

int eliminarRaizArbol(tArbol* p, void* d, size_t tam, int(*cmp)(const void*, const void*))
{
    tNodoArbol** reemp;
    tNodoArbol* elim;
    int hi,hd;

    if(!(*p))
        return 0;

    free((*p)->info);

    if(!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p=NULL;
        return TODO_OK;
    }

    hi = alturaArbolBin(&(*p)->izq);
    hd = alturaArbolBin(&(*p)->der);

    reemp = (hi>hd)? mayorNodo(&(*p)->izq) : menorNodo(&(*p)->der);

    elim = *reemp;
    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;

    *reemp = (elim->izq)? elim->izq : elim->der;

    free(elim);

    return TODO_OK;
}

int eliminarElemArbol(tArbol* p, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    p = buscarNodoArbol(p, d,cmp);

    if(!p)
        return 0;

    memcpy(d,(*p)->info,MIN(tam,(*p)->tamInfo));
    return eliminarRaizArbol(p);
}

int buscarElemArbol(const tArbol* p, void* d, unsigned tam, int(* cmp)(const void*, const void*))
{
    p = buscarNodoArbol(p,d, cmp);

    if(!p)
        return 0;

    memcpy(d,(*p)->info,MIN(tam,(*p)->tam));
    return TODO_OK;
}

tNodoArbol** buscarNodoArbol(tArbol* p, void*d,int (*cmp)(const void*, const void*))
{
    if(!*p)
        return NULL;
    int comp;

    if(*p)
    {
        comp = cmp(d,(*p)->info);
        if(comp<0)
            return buscarNodoArbol(&(*p)->izq,d,cmp);
        if(comp>0)
            return buscarNodoArbol(&(*p)->der,d,cmp);
    }

    return p;
}

int cargarArchivoBinOrdenadoAbiertoArbol(tArbol* p, FILE* pf, unsigned tamInfo)
{
    int cantReg, r;

    if(*p)
        return SIN_INICIALIZAR;

    fseek(pf,0,SEEK_END);
    cantReg = ftell(pf) / tamInfo;

    if((r= cargarDatosDesdeArch(p,pf,&tamInfo,0,cantReg-1,leerDesdeArchivoBin))!= TODO_OK)
        return r;

    return TODO_OK;
}

int cargarArchivoBinOrdenadoArbol(tArbol* p, const char* path, unsigned tamInfo)
{

}

int cargarDatosDesdeArch(tArbol* p, void* orig, unsigned tam, int li, int ls, int(*accion)(void**, void*, unsigned, void*))
{
    int medio = (li+ls)/2;

    if(li>ls)
        return TODO_OK;

    (*p) = malloc(sizeof(tNodoArbol));

    (*p)->tamInfo = accion(&(*p)->info, pf, tam, medio);

    if(!*p || !(*p)->tamInfo )
    {
        free(*p);
        return SIN_MEM;
    }

    (*p)->izq = (*p)->der = NULL;

    if( (r= cargarDatosDesdeArch(&(*p)->izq,pf,tam,li,medio-1,accion))!= TODO_OK)
        return r;
    return cargarDatosDesdeArch(&(*p)->der,pf,tam,medio+1,ls,accion);
}

 unsigned leerDesdeArchivoBin(void ** d, void * pf, unsigned pos, void * params)
 {
    unsigned tam = *((int*)params);


    *d = malloc(tam);

    if(!*d)
        return 0;

    fseek((FILE*)pf, pos*tam, SEEK_SET);

    return fread(*d, tam, 1, (FILE*)pf);

 }
int cargarDesdeDatosOrdenadosArbol(tArbol* p, void* ds, unsigned cantReg, unsigned(* leer)(void**, void*, unsigned, void* params), void* params)
{
    return TODO_OK; //NO
}

int cargarDesdeArchivoPreOrdenArbol(tArbol* p, const char* path, unsigned tamInfo, int(* cmp)(const void*, const void*))
{
    return TODO_OK; //NO
}

int cargarDesdeDatosPreOrdenArbol(tArbol* p, void* ds, unsigned cantReg, unsigned(* leer)(void**, void*, unsigned, void* params), int(* cmp)(const void*, const void*), void* params)
{
    return TODO_OK; //NO
}

int grabarEnArchivoOrdenadoArbolBin(tArbol* p, const char* path)
{

}

unsigned alturaArbolBin(const tArbol *p)
{

}

unsigned cantNodosArbolBin(const tArbol *p)
{

}

unsigned cantNodosHastaNivelArbolBin(const tArbol *p, int n)
{

}

int mayorElemArbol(const tArbol* p, void* d, unsigned tam)
{

}

int menorElemArbol(const tArbol* p, void* d, unsigned tam)
{

}

int completoHastaNivelArbolBin(const tArbol* p, int n)
{

}

int esCompletoArbolBin(const tArbol* p)
{
}

int esBalanceadoArbolBin(const tArbol* p)
{

}

int esAVLArbolBin(const tArbol* p)
{

}

void vaciarArbolBin(tArbol* p)
{

}

void arbolGrafico(const tArbol* p, void(* mostrar)(const void*))
{

}

tNodoArbol** mayorNodo(tArbol* p)
{

}

tNodoArbol** menorNodo(tArbol* p)
{

}

//||======================||    Extras para arbol   ||==========================||

int cmpInt(const void* a, const void*b)
{
    return *(int*)a - *(int*)b;
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


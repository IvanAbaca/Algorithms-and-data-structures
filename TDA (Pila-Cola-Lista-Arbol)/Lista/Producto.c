#include "Lista.h"
#include "Producto.h"

void mostrarProd(void* info, unsigned tam, void* orig)
{
    tProd aux = *(tProd*)info;

    printf("\n|\t%02d\t|\t%s\t|\t%.2f\t\t|\n|\t\t|\t\t|\t\t\t|", aux.cod, aux.desc, aux.precio);
}

int crearArchBin(char* path)
{
    FILE* pf = fopen(path, "wb");

    if(!pf)
        return ERROR_ARCHIVO;

    tProd v[] =
    {
        { 7, "G", 130.14}, { 8, "H", 140.81}, { 9, "I", 930.31},
        {13, "M", 160.16}, {14, "N", 560.31}, {15, "O", 500.41},
        { 1, "A", 100.12}, { 2, "B", 700.61}, { 3, "C", 810.51},
        {10, "J", 154.15}, {11, "K", 156.91}, {12, "L", 600.15},
        { 4, "D", 200.13}, { 5, "E", 130.71}, { 6, "F", 132.16},
    };

    fwrite(v, sizeof(tProd), sizeof(v)/sizeof(tProd), pf);

    fclose(pf);

    return TODO_OK;
}

int cmpProd(const void* a, const void*b)
{
    tProd na = *(tProd*)a, nb = *(tProd*)b;

    if(na.cod > nb.cod)
        return 1;
    else if(na.cod < nb.cod)
        return -1;
    return 0;
}

int mostrarListaProductos(tLista* pl, int(*mostrar)(void*, unsigned, void*), void* param)
{
    if(!*pl)
        return NO_EXISTE;

    printf("\n\n||=============||\tProductos\t||=============||\n\n");
    printf("\n      Codigo\t   Descripcion\t\tPrecio\n");
    printf("--------------------------------------------------------");
    mapLista(pl, (void*)mostrar, NULL);
    printf("\n--------------------------------------------------------");
    return TODO_OK;
}

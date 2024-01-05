#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    int cod;
    char desc[20];
    float precio;
}tProd;

void mostrarProd(void*, unsigned, void*);
int crearArchBin(char* path);
int cmpProd(const void* a, const void* b);
int mostrarListaProductos(tLista* pl, int(*mostrar)(void*, unsigned, void*), void* param);
#endif

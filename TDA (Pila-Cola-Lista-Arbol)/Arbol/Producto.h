#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    int cod;
    char desc[20];
    float precio;
}tProd;

int mostrarProd(void*, unsigned, unsigned, void*);
int crearArchBin(char* path);
int cmpProd(const void* a, const void* b);

#endif

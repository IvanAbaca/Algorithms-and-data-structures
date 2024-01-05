#ifndef CLASE1_H_INCLUDED
#define CLASE1_H_INCLUDED

typedef struct
{
    char nyap[30];
    int puesto;

} t_resultado;

void mostrarEstructura(void* vec, unsigned ce, size_t tam);
int cmpEstructura(void* vec1, void* vec2);
void ordenarSeleccion(void* vec, size_t ce, size_t tam, int* cmpEstructura(void*, void*));
void intercambio(void* ele1, void* ele2, size_t tam);
void* buscarMenor(void* vec, void* ce, size_t tam, int cmp(const void*, const void*));

#endif // CLASE1_H_INCLUDED

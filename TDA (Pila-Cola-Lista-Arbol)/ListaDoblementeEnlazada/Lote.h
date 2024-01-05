#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED


typedef struct
{
    char codProd[8];
    int coEncu;
    int zona;
}tEncu;

int crearArchBin(const char*);
int crearArchTxT(const char*);

#endif // LOTE_H_INCLUDED

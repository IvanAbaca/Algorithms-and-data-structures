#include "Funciones.h"

int main()
{
    tLista lista;
    int i = 0;

    crearLista(&lista);
    for(i=0; i<9; i++)
        poner_al_inicio(&lista, &i, sizeof(i));

    pone_al_final(&lista, &i, sizeof(i));

    return 0;
}

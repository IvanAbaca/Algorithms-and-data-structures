#include "ColaDinamica.h"

int main()
{
    int v[] = {1,2,3,4,5,6,7,8,9};
    int ce = sizeof(v)/sizeof(int);
    int tam = sizeof(int);
    int i;
    int info;

    tCola pc;

    //Inicializa con NULL
    crearCola(&pc);

    //Llena la cola
    for(i=0; i<ce; i++)
        ponerEnCola(&pc, v+i, tam);

    //Vacia la cola
    for(i=0; i<ce; i++)
    {
        sacarDeCola(&pc, &info, tam);
        printf("%d\n", info);
    }

    //resetea la cola
    for(i=0; i<ce; i++)
        ponerEnCola(&pc, v+i, tam);

    verFrenteDeCola(&pc, &info, tam);
    printf("\nVer frente de cola: %d\n", info);

    if(colaVacia(&pc))
        printf("\nCola vacia\n");

    if(colaLlena(&pc, tam))
        printf("\nCola llena\n");

    vaciarCola(&pc);

    if(colaVacia(&pc))
        printf("\nCola vacia :3333\n");
    else
        printf("\nSe supone que tiene que dar vacia :CCCCC\n");


    return 0;
}

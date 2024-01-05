#include "PilaDinamica.h"

int main()
{

    int v[] = {1,2,3,4,5,6,7,8,9};
    int ce = sizeof(v)/sizeof(int);
    int tam = sizeof(int);
    int i;
    int info;

    tPila pp;

    //Inicializa con NULL
    crearPila(&pp);

    //Llena la cola
    for(i=0; i<ce; i++)
        ponerEnPila(&pp, v+i, tam);

    //Vacia la cola
    for(i=0; i<ce; i++)
    {
        sacarDePila(&pp, &info, tam);
        printf("%d\n", info);
    }

    //resetea la cola
    for(i=0; i<ce; i++)
        ponerEnPila(&pp, v+i, tam);

    verTopeDePila(&pp, &info, tam);
    printf("\nVer frente de pila (Espero un 9): %d\n", info);

    if(pilaVacia(&pp))
        printf("\nPila vacia\n");

    if(pilaLlena(&pp, tam))
        printf("\nPila llena\n");

    vaciarPila(&pp);

    if(pilaVacia(&pp))
        printf("\nPila vacia :3333\n");
    else
        printf("\nSe supone que tiene que dar vacia :CCCCC\n");


    return 0;
}

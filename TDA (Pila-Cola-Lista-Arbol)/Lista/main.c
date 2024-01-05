#include "Lista.h"
#include "Producto.h"
#define archBin "prod.bin"
#define archBinActualizado "prod2.bin"


int main()
{
    tLista l;
    tLista* pl = &l;
    crearLista(pl);
    int tam = sizeof(tProd);
    tProd info = {7,"", 0};
    int pos = 5;

//||======================||    Practica Con Archivos   ||==========================||

    crearArchBin(archBin);

    cargarListaDesdeArch(pl, archBin, tam);

    mostrarListaProductos(pl, (void*)mostrarProd, NULL);

    printf("\nCarga la lista desde un archivo y la muestra\n");
    getchar();
    system("cls");

    sacarInicioLista(pl, &info, tam);
    printf("\nSaca elemento ini: %d/%s/%.2f\n", info.cod, info.desc, info.precio);
    sacarFinalLista(pl, &info, tam);
    printf("\nSaca elemento fin: %d/%s/%.2f\n", info.cod, info.desc, info.precio);
    sacarPosLista(pl, &info, tam, pos);
    printf("\nSaca elemento pos(%d): %d/%s/%.2f\n", pos, info.cod, info.desc, info.precio);
    info.cod = 10;
    printf("\nSaca elemento elem(%d/%s/%.2f): ", info.cod, info.desc, info.precio);
    sacarElemLista(pl, &info, tam, cmpProd);
    printf("%d/%s/%.2f\n", info.cod, info.desc, info.precio);

    mostrarListaProductos(pl, (void*)mostrarProd, NULL);
    getchar();
    system("cls");

    printf("\nOrdena la lista:\n");
//    ordenarInfoLista(pl, cmpProd);
    ordenarListaAuxL(pl, cmpProd);
//    ordenarNodosLista(pl, cmpProd);

    mostrarListaProductos(pl, (void*)mostrarProd, NULL);
    getchar();
    system("cls");

    grabarArchDesdeLista(pl, archBinActualizado, tam);

    printf("\nGraba en arch, vacia y muestra que esta vacio\n");
    vaciarLista(pl);
    mostrarListaProductos(pl, (void*)mostrarProd, NULL);
    getchar();
    system("cls");

    cargarListaDesdeArch(pl, archBinActualizado, tam);

    mostrarListaProductos(pl, (void*)mostrarProd, NULL);
    printf("\nLee el archivo actualizado grabado y lo muestra\n\n\n");


    return 0;
}

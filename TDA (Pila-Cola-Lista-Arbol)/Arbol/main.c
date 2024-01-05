#include "ArbolDoss.h"
#include "Producto.h"
#define archBin "prod.bin"
#define archBinActualizado "prod2.bin"


int main()
{

    tArbol a;
    tArbol* pa = &a;
    int tam = sizeof(tProd);
    int r;
    tProd info = {7,"", 0};
    crearArbol(pa);


//||======================||    Practica Con Archivos   ||==========================||

    if((r = crearArchBin(archBin)) != TODO_OK)
        imprimirMensaje(r);

    if((r = cargarArchivoBinOrdenadoArbol(pa, archBin, tam)) != TODO_OK)
        imprimirMensaje(r);

    if((r = eliminarElemArbol(pa, &info, tam, cmpProd)) != TODO_OK)
        imprimirMensaje(r);

    if((r = mostrarArbolProd(pa, (void*)mostrarProd)) != TODO_OK)
        imprimirMensaje(r);

    printf("\nCrea un binario, lo carga ordenado, elimina el registro %d y lo muestra.", info.cod);
    getchar();

    info.cod = 16;

    if((r = insertarRecArbol(pa, &info, tam, cmpProd)) != TODO_OK)
        imprimirMensaje(r);

    if((r = grabarEnArchivoOrdenadoArbolBin(pa, archBinActualizado)) != TODO_OK)
        imprimirMensaje(r);

    vaciarArbolBin(pa);

    if((r = mostrarArbolProd(pa, (void*)mostrarProd)) != TODO_OK)
        puts("\nArbol vacio\n");
    printf("Carga un registro %d, lo inserta ordenado en el arbol, graba el arbol en el archivo, vacia el arbol y lo muestra", info.cod);
    getchar();
    system("cls");

    if((r = cargarArchivoBinOrdenadoArbol(pa, archBinActualizado, tam)) != TODO_OK)
        imprimirMensaje(r);

    if((r = mostrarArbolProd(pa, (void*)mostrarProd)) != TODO_OK)
        imprimirMensaje(r);
    printf("\nCarga el arbol con el archivo que tiene el registro %d y lo muestra", info.cod);
    getchar();
    system("cls");

    int i = 1;
    puts("Caracteristicas del arbol: ");puts("");

    printf("Es completo hasta nivel %d?", i);
    imprimirMensaje(completoHastaNivelArbolBin(pa, i));
    puts("");puts("");

    printf("Es completo?");
    imprimirMensaje(esCompletoArbolBin(pa));
    puts("");puts("");

    printf("Es balanceado?");
    imprimirMensaje(esBalanceadoArbolBin(pa));
    puts("");puts("");

    printf("Es AVL?");
    imprimirMensaje(esAVLArbolBin(pa));
    puts("");puts("");

    printf("Cantidad de nodos: %d", cantNodosArbolBin(pa));
    puts("");puts("");

    printf("Altura: %d", alturaArbolBin(pa));
    puts("");puts("");

    return 0;
}


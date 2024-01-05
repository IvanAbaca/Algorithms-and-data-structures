#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define arch "ArchProd.bin"
#define arch2 "ArchMayor100.bin"
#define arch3 "ArchMenor100.bin"

// Tengo un archivo binario el cual viene ordenado por:
// num pedido -> ordenado por este campo
// cod_prod
// cant
// precio
// Guardar los pedidos que tienen mas de 100 pesos en un archivo, y los que tienen menos en otro.

// guardo en una cola mientras voy sumando los valores, si la suma da +100 guardo en determinado archivo.


int main()
{
    tCola cola;

    crearArchivoBin(arch);



    return 0;
}

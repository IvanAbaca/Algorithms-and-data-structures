#include "Funciones.h"
// Funcion que se llama a si misma.

// Tengo que buscar el caso base, que es aquella condicion que corta nuestro llamado.
// Antes de cada problema tengo que fijarme como podria resolverlo de forma recursiva! uwu ^w^

// -----------------------------------------------------------------------------------------------

// Arbol, es una estructura que almacena datos en la cual tengo una jerarquia, tengo un nodo padre, el cual puede tener hijos o no.
// El nodo padre es conocido como el nodo raiz, lo nodos que no tienen hijos se los conoce como hoja.
// Tenemos un concepto conocido como altura (cant max de saltos que voy a dar en ese arbol para alcanzar un nodo). (Niveles).
// Vamos a ver arboles binarios, los cuales tienen como maximo 2 hijos, los cuales estan diferenciados x hijo izq e hijo derecho.
// Tenemos arboles de expresion y arboles binarios de busqueda (en este nos vamos a centrar).
// Las busquedas en los arboles binarios de busqueda son mas eficientes (tiene q estar balanceado).
// En todos los hijos izquierdos las claves son mas chicas que la razin, y los hijos derechos son mas grandes que el nodo raiz (la clave).
// Las funciones van a tratar de que el arbol quede lo mas balanceado posible.
// Hay 3 tipos de balanceos.
// Arbol balanceado: Esta completo hasta el ante-ultimo nivel.
// Arbol completo: Esta completo, por ejemplo, tiene 7 nodos (15, etc).
// Balanceo AVL: Es mas rapido de balancear, este dice, que la diferencia de alturas entre los arboles izq y derecho nunca es mayor a 1.

// Todos los arboles completos con balanceados, y todos los balanceados son balanceados AVL.

int main()
{
    char cad[5] = "abcd";
    int num = 1234;

    printf("\nCadena: %s\nNumero: %d\n\n", cad, num);

//    mostrarTodoAdelanteYReves(cad);
//    puts("");
//    mostrarCadReverso(cad);
//    puts("");
//    mostrarCadIdaVuelta(cad);
//    puts("");
//    mostrarCadIdaVueltaSinRepetir(cad);
//    puts("");
//    mostrarCadFlecha(cad);
//    puts("");
//    mostrarUniNumeros(num);

    return 0;
}

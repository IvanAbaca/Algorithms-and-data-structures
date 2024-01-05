#include "Funciones.h"

double factorial(unsigned n)
{
    if(n<=1)
        return 1;

    return n * factorial(n-1);
}

int mcd(unsigned n, unsigned m)
{
    if(n%m == 0)
        return m;

    return mcd(m, n%m);
}

void mostrarCadReverso(char* cad)
{
    if(*cad != '\0')
        mostrarCadReverso(cad+1);
    printf("%c", *cad);
}

void mostrarTodoAdelanteYReves(char* cad)
{
    if(*cad == '\0')
        return;


    printf("%s\n", cad);
    mostrarTodoAdelanteYReves(cad+1);
    printf("%s\n", cad);

}

void mostrarCadIdaVuelta(char* cad)
{
    if(*cad != '\0')
    {
        printf("%c", *cad);
        mostrarCadIdaVuelta(cad+1);
    }

    printf("%c", *cad);
}

void mostrarCadIdaVueltaSinRepetir(char* cad)
{
    if(*(cad+1) != '\0')
    {
        printf("%c", *cad);
        mostrarCadIdaVueltaSinRepetir(cad+1);
    }

    printf("%c", *cad);
}

void mostrarUniNumeros(int num)
{
    if(!num)
        return;

    printf("%d", num%10);

    mostrarUniNumeros(num/10);
}

void mostrarCadFlecha(char* cad)
{
    mostrarCadFlecha_r(cad, 0);
}

void mostrarCadFlecha_r(char* cad, int esp)
{
    if(*(cad+1))
    {
        printf("%*s%c\n",esp, "",*cad);
        mostrarCadFlecha_r(cad+1, esp+1);
    }

    printf("%*s%c\n",esp--, "",*cad);
}

#include "Funciones.h"

// TDA : tipo de dato el cual el usuario utiliza pero no le importa como esta implementado, tiene sus propias propiedades (datos) y comportamientos (funciones). -> no tiene que revelar la informacion interna.

// Interfaz: Firma de las funciones, nombre del tipo de dato.
// Tengo dos numeros de maximo 128 dig(mentira pueden ser mas), en arch de texto. Programa que haga la suma de dos nros grandes.


int main()
{

    crearBin(archbin);
    tPila pp;
    crearPila(&pp);
    leerBin(&pp, archbin);

    tEmpleado emp;
    int i=1;

    while(i!=0)
    {

        printf("1. Cargar\n2. Tope\n3. Sacar\n0. Salir\n\nIngrese la opcion: ");
        scanf("%d", &i);

        if(i==1)
        {
            printf("\nIngrese apellido: ");
            scanf("%s", emp.nyap);
            printf("\nIngrese legajo: ");
            scanf("%d", &(emp.legajo));
            printf("\nIngrese sueldo: ");
            scanf("%f", &(emp.sueldo));
            ponerEnPila(&pp, &emp, sizeof(tEmpleado));
        }

        if(i==2)
        {
            verTope(&pp, &emp, sizeof(tEmpleado));
            printf("\nNyAp= %s\tLegajo= %d\tSueldo= %.2f\n", emp.nyap, emp.legajo, emp.sueldo);
        }

        if(i==3)
        {
            sacarDePila(&pp, &emp, sizeof(tEmpleado));
            printf("\nElemento eliminado");
        }
    }
    escribirBin(&pp, archbin);
    mostrarEmpleado(archbin);


/*-------------------------PILA DINAMICA---------------------

    char n1[128] = "129837234987123234987";
    char n2[128] = "198271239872349812382";
    char num1;
    char num2;
    int res;
    int carry=0;
    int i;

    tPila pila1;
    tPila pila2;
    tPila pila3;

    din_crear(&pila1);
    din_crear(&pila2);
    din_crear(&pila3);

    for(i=0; i<strlen(n1); i++)
        din_apilar(&pila1, n1+i, sizeof(char));
    for(i=0; i<strlen(n2); i++)
        din_apilar(&pila2, n2+i, sizeof(char));

    while(!din_vacia(&pila1) || !din_vacia(&pila2))
    {
        din_desapilar(&pila1, &num1, sizeof(char));
        din_desapilar(&pila2, &num2, sizeof(char));
        num1-=48;
        num2-=48;
        res = (num1 + num2 + carry)%10;
        carry = (num1 + num2 + carry)/10;
        din_apilar(&pila3, &res, sizeof(int));
        num1=48;
        num2=48;
    }

    while(!din_vacia(&pila3))
    {
        din_desapilar(&pila3, &res, sizeof(int));
        printf("%d", res);
    }*/

/*-------------------------PILA ESTATICA---------------------
    char n1[128] = "129837234987123234987";
    char n2[128] = "198271239872349812382";
    char num1;
    char num2;
    int res;
    int carry=0;
    int i;

    tPila pila1;
    tPila pila2;
    tPila pila3;

    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pila3);

    for(i=0; i<strlen(n1); i++)
        ponerEnPila(&pila1, n1+i, sizeof(char));
    for(i=0; i<strlen(n2); i++)
        ponerEnPila(&pila2, n2+i, sizeof(char));

    while(!pilaVacia(&pila1) || !pilaVacia(&pila2))
    {
        sacarDePila(&pila1, &num1, sizeof(char));
        sacarDePila(&pila2, &num2, sizeof(char));
        num1-=48;
        num2-=48;
        res = (num1 + num2 + carry)%10;
        carry = (num1 + num2 + carry)/10;
        ponerEnPila(&pila3, &res, sizeof(int));
        num1=48;
        num2=48;
    }

    while(!pilaVacia(&pila3))
    {
        sacarDePila(&pila3, &res, sizeof(int));
        printf("%d", res);
    }
*/
    return 0;
}

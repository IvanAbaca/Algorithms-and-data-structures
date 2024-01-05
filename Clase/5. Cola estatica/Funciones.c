#include "Funciones.h"

void crear_cola(tCola* pc)
{
    pc->fondo = 0;
    pc->frente = 0;
    pc->tam_disp = TAM_COLA;
}

int poner_en_cola(tCola* pc, const void* info, size_t tam)
{
    int ini, fin;

    if(pc->tam_disp < sizeof(size_t) + tam)
        return 0;

    if((ini = min(TAM_COLA - pc->fondo, sizeof(size_t))) != 0) // Calculo mi ini, el cual va a ser la cantidad de bytes que puedo copiar al final de mi vector, es decir, o todo el size_t o algo menor.
        memcpy(pc->vec + pc->fondo, &tam, ini); // Copio desde el fondo, el tamanio y "ini" bytes que me entren.


    if((fin = sizeof(size_t) - ini) != 0) // Si no entro entero, quiere decir que tengo que ponerlo al inicio, por lo tanto calculo desde lo que me quedo del tamanio del dato, cuanto tengo que copiar.
        memcpy(pc->vec, (char*)&tam + ini, fin); // Desde el inicio de mi vector, me muevo con un puntero a la parte del tam del dato que no copie, y copio los "fin" bytes que me quedaron.


    pc->fondo = fin ? fin : pc->fondo + ini; // Tengo que volver a apuntar mi fondo, si mi fin es != 0 le pongo la cantidad de bytes que copie, sino, me muevo desde el fondo, los "ini" bytes que copie (osea un sizeof(size_t)).

    if((ini = min(TAM_COLA - pc->fondo, tam)) != 0) // Me fijo si al final de mi vector puedo copiar mi dato entero, sino me quedo con el minimo que pueda entrar.
        memcpy(pc->vec + pc->fondo, info, ini); // Copio el dato desde el fondo, "ini" bytes que haya calculado, o todo, o algo menor a tam.


    if((fin = tam - ini) != 0) // Si no entro, tengo que calcular cuantos bytes me quedaron para copiar desde el inicio del vector.
        memcpy(pc->vec, (char*)info + ini, fin); // Copio desde el inicio del vector, "fin" bytes que me hayan quedado, puede ser o el tamanio entero, o una parte.

    pc->fondo = fin ? fin : pc->fondo + ini;

    pc->tam_disp -= tam + sizeof(size_t);

    return 1;
}

int sacar_de_cola(tCola* pc, void* info, size_t tam)
{
    int tam_dato_cola, ini, fin;

    if(TAM_COLA == pc->tam_disp)
        return 0;

    if((ini = min(TAM_COLA - pc->frente, sizeof(size_t))))
       memcpy(&tam_dato_cola, pc->vec + pc->frente, ini);

    if((fin = sizeof(size_t) - ini))
        memcpy((char*)&tam_dato_cola + ini, pc->vec, fin);

    pc->frente = fin ? fin : pc->frente + sizeof(size_t);

    if((ini = min(TAM_COLA - pc->frente, tam_dato_cola)))
       memcpy(info, pc->vec + pc->frente, min(tam, ini));

    if((fin = tam_dato_cola - ini) && tam > ini)
        memcpy((char*)&tam_dato_cola + ini, pc->vec, min(tam-ini, fin));

    pc->frente = fin ? fin : pc->frente + tam_dato_cola;

    pc->tam_disp += sizeof(size_t) + tam_dato_cola;

    return 1;
}

int ver_frente_de_cola(tCola* pc, void* info, size_t tam)
{
    int tam_dato_cola, ini, fin;

    if(TAM_COLA == pc->tam_disp)
        return 0;

    if((ini = min(TAM_COLA - pc->frente, sizeof(size_t))))
       memcpy(&tam_dato_cola, pc->vec + pc->frente, ini);

    if((fin = sizeof(size_t) - ini))
        memcpy((char*)&tam_dato_cola + ini, pc->vec, fin);

    pc->frente = fin ? fin : pc->frente + sizeof(size_t);

    if((ini = min(TAM_COLA - pc->frente, tam_dato_cola)))
       memcpy(info, pc->vec + pc->frente, min(tam, ini));

    if((fin = tam_dato_cola - ini) && tam > ini)
        memcpy((char*)&tam_dato_cola + ini, pc->vec, min(tam-ini, fin));

    pc->frente = fin ? fin : pc->frente + tam_dato_cola;

    return 0;
}

void vaciar_cola(tCola* pc)
{
    pc->frente = 0;
    pc->fondo = 0;
    pc->tam_disp = TAM_COLA;


}

int cola_llena(const tCola* pc, size_t tam)
{
    if(TAM_COLA < tam + sizeof(size_t))
        return 1;

    return 0;
}

int cola_vacia(const tCola* pc)
{
    if(pc->tam_disp == TAM_COLA)
        return 1;

    return 0;
}

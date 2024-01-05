#include "Funciones.h"

void crear_cola(tCola* pc)
{
    pc->pri = NULL;
    pc->ult = NULL;
}

int poner_en_cola(tCola* pc, const void* info, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam);
    nue->tam = tam;
    nue->sig = NULL; // Le pongo null al siguiente ya que luego del que acabo de ingresar no tengo nada.

    if(pc->ult)
        pc->ult->sig = nue; // Si mi puntero al ultimo no es nulo, las siguiente del ultimo actual (osea el anterior a nue), lo hago apuntar a nue, para no perder el enlace.

    else
        pc->pri = nue; // Si mi cola estaba vacia, pongo ambos punteros apuntando al nuevo nodo.

    pc->ult = nue; // La ultimo la pongo la direccion del nuevo, que es el ultimo nodo actual.

    return 1;

}

int cola_vacia(const tCola* pc)
{
    if(pc->pri == NULL && pc->ult == NULL)
        return 1;

    return 0;
}

int sacar_de_cola(tCola* pc, void* pd, size_t tam)
{
    tNodo* elim = pc->pri;

    if(!pc->pri)
        return 0;

    memcpy(pd, elim->info, MEN(tam, elim->tam));

    pc->pri = elim->sig;

    if(!pc->pri)
        pc->ult = NULL;

    free(elim->info);
    free(elim);

    return 1;
}

void crearArchivoBin(const char* arch)
{
    tProd prod[] = {{01, "martillo", 1, 10},
                     {01, "destornillador", 2, 20},
                     {01, "tornillos", 50, 5},
                     {02, "martillo", 1, 10},
                     {02, "clavos", 100, 5},
                     {02, "taladro", 1, 95},
                     {03, "taladro", 1, 95},
                     {03, "clavos", 20, 5},
                     {04, "taladro", 1, 95},
                    };

    FILE* pf = fopen(arch, "wb");

    fwrite(&prod, sizeof(tProd), sizeof(prod)/sizeof(tProd), pf);

    fclose(pf);
}

int ordenarArchEnCola(const char* arch, const char* arch2, const char* arch3, tCola* cola)
{
    tProd aux, aux_arch;
    int nro_ped;
    int total_pedido = 0;

    FILE* pf = fopen(arch, "rb");

    FILE* pf2 = fopen(arch2, "wb");

    FILE* pf3 = fopen(arch3, "wb");

    if(!pf || !pf2 || pf3)
        return 0;


    fread(&aux, sizeof(tProd), 1, pf);

    while(!feof(pf))
    {
        nro_ped = aux.nro_ped;
        total_pedido = 0;

        while(!feof(pf) && aux.nro_ped == nro_ped)
        {
            total_pedido+= aux.cant*aux.precio;

            poner_en_cola(cola, &aux, sizeof(tProd));

            fread(&aux, sizeof(tProd), 1, pf);
        }

        if(total_pedido >= 100)
        {
            while(!cola_vacia(cola))
            {
                sacar_de_cola(cola, &aux_arch, sizeof(tProd));

                fwrite(&aux_arch, sizeof(tProd), 1, pf2);

            }
        }
        else
        {
            while(!cola_vacia(cola))
            {
                sacar_de_cola(cola, &aux_arch, sizeof(tProd));

                fwrite(&aux_arch, sizeof(tProd), 1, pf3);

            }
        }
    }

    fclose(pf);
    fclose(pf2);
    fclose(pf3);

    return 1;

}

#include "ListaH.h"

void crear_lista(tLista* pl)
{
    *pl = NULL;
}

int poner_al_inicio(tLista* pl, const void* info, size_t tam)
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

    memcpy(nue->info, info, tam); // Copio el dato en el nuevo nodo creado.

    nue->tam = tam; // Le asigno el tamanio del dato al nuevo nodo.

    nue->sig = *pl; // Al siguiente del nuevo nodo que acabo de agregar, le pongo lo que tenia anteriormente *pl (osea, la lista), si ya tenia elementos, le voy a poner la direccion del nodo que este antes, y sino, le voy a poner null.

    *pl = nue; // Como estoy insertando al inicio, mi lista ahora va a apuntar a este nuevo nodo.

    return 1;
}

int poner_al_final(tLista* pl, const void* info, size_t tam)
{
    while(*pl)
        pl = &(*pl)->sig; // Al pl (ya q es la copia del puntero a lista que llega por parametro) le pongo la direccion del *pl->sig, si yo le pusiese solo el contenido, estaria avanzando nodos enteros, y cuando llegue al NULL, me voy a caer de la lista por un nodo, por eso debo de asignar la direccion y no directamente el contenido.
                          // Si yo modifico *pl, estaria perdiendo el enlace a la lista y moviendo el puntero.

    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam); // Copio el dato.

    nue->tam = tam; // Asigno el tamanio.

    nue->sig = NULL; // Como estoy insertando al final, no voy a tener nada despues del nodo que estoy metiendo, asiq le pongo nulo.

    *pl = nue; // Y como estoy parando en el siguiente pero del nodo anterior, en ese contenido de ese lugar, pongo la direccion del nodo nuevo.

    return 1;

}

int poner_en_una_pos(tLista* pl, const void* info, size_t tam, unsigned pos)
{
    while(*pl && pos) // Para insertar en una posicion, voy a tener que recorrar la lista, asiq vuelvo a trabajar de la misma forma que insertando al final, osea, con la copia del puntero a la lista q llega por parametro.
    {
        pl = &(*pl)->sig;
        pos--;
    }

    // Pueden ocurrir 2 cosas, que mi posicion llegue a 0 y encuentre la posicion donde tengo que ingresar el dato, o que llegue al final de la lista y lo inserte al final.

    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 0;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tam); // Copio el dato.

    nue->tam = tam; // Asigno el tamanio.

    nue->sig = *pl; // Como estoy insertando en una posicion o al final, antes de perder el enlace, al siguiente del nuevo nodo que voy a poner, le asigno *pl el cual tiene la direccion del nodo que le sigue al nuevo que voy a ingresar.

    *pl = nue; // Luego de haber linkeado el nodo nuevo con el siguiente, al *pl (nodo anterior al nuevo), le pongo en ese lugar, la direccion del nuevo nodo, asi queda toda la lista enlazada.

    return 1;
}

int poner_en_orden(tLista* pl, const void* info, size_t tam, int(* cmp)(const void*, const void*)) // Solo sirve si ya vengo insertando en orden.
{
    int comp;

    while(*pl && ((comp = cmp(info, ((*pl)->info))) > 0)) // Recorro la lista hasta que me quede sin lista, o hasta que encuentre un elemento que sea mayor al que tenga que insertar.
        pl = &(*pl)->sig;

    if(!comp) // Si comp = 0, quiere decir que encontre un duplicado, por lo tanto, retorno.
        return 0;

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

    nue->sig = *pl; // Como estoy insertando en una posicion o al final, antes de perder el enlace, al siguiente del nuevo nodo que voy a poner, le asigno *pl el cual tiene la direccion del nodo que le sigue al nuevo que voy a ingresar.

    *pl = nue; // Si comp = 0, quiere decir que encontre un duplicado, por lo tanto, retorno.

    return 1;
}

int sacar_del_inicio(tLista* pl, void* info, size_t tam) // Esencialmente, lo mismo que sacar de pila.
{
    tNodo* elim = *pl;

    if(!*pl)
        return 0;

    memcpy(info, elim->info, min(elim->tam, tam));

    *pl = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

int sacar_del_final(tLista* pl, void* info, size_t tam)
{
    tNodo* elim;

    if(!*pl)
        return 0;

    while((*pl)->sig) // Tengo que recorrer la lista hasta el final, sin embargo no puedo moverme hasta el elemento que quiero sacar, ya que no tendria forma de volver para atras y re-acomodar los links de la lista.
        pl = &(*pl)->sig; // Por lo tanto, en vez de preguntar por el nodo en si, pregunto si el siguiente, del nodo en el que estoy es el ultimo, en caso de serlo, me quedo en el nodo anterior.

    elim = *pl;

    memcpy(info, elim->info, min(elim->tam, tam));

    *pl = NULL; // Como estoy parado en el nodo anterior, en donde esta pl, le tengo que poner null, ya que pl esta parado en donde yo tengo la direccion del nodo siguiente.
                // Pero el nodo siguiente lo voy a borrar, por lo tanto le pongo null.

    free(elim->info);
    free(elim);

    return 1;
}

int sacar_un_elem(tLista* pl, void* info, size_t tam, void* elem, int (*cmp)(const void*, const void*))
{
    int comp;
    tNodo* elim;

    if(!*pl)
        return 0;

    while((*pl)->sig && (comp = cmp(elem, ((*pl)->info)) != 0)) // Tengo que recorrer la lista para encontrar el elemento que quiero eliminar, asiq mientras la comparacion de != 0, o tenga lista, sigo buscandolo.
        pl = &(*pl)->sig;

    if(!*pl) // Si el puntero quedo en null luego de recorrer, quiere decir que me quede sin lista y no encontre el elemento, por lo tanto, retorno error.
        return 0;

    // Caso contrario, lo elimino.

    elim = *pl;

    memcpy(info, elim->info, min(elim->tam, tam)); // Me copio el elemento.

    *pl = elim->sig; // Como tengo que eliminar un nodo, antes de borrarlo y perder el enlace, al *pl (que es el nodo anterior al que quiero eliminar), en su siguiente debo de poner la direccion del nodo siguiente al que voy a borrar.

    // Ej: 1,2,3 -> borro 2, a 1 en siguiente le tengo que poner la dir de 3.

    free(elim->info);
    free(elim);

    return 1;
}

int lista_vacia(const tLista* pl)
{
    if(*pl)
        return 0;

    return 1;
}

int lista_llena(const tLista* pl, size_t tam)
{
    tNodo* nue = malloc(sizeof(tNodo));

    if(!nue)
        return 1;

    nue->info = malloc(sizeof(tam));

    if(!nue->info)
    {
        free(nue);
        return 1;
    }

    return 0;
}

int ver_inicio_lista(tLista* pl, void* info, size_t tam)
{
    if(!*pl) // Si la lista esta vacia, retorno.
        return 0;

    memcpy(info, (*pl)->info, min(((*pl)->tam), tam)); // Es lo mismo que ver tope, copio directamente la informacion que tengo en el puntero de la lista, osea, del nodo, ya que va a ser el primero.

    return 1;
}

int ver_ultimo_lista(tLista* pl, void* info, size_t tam)
{
    if(!*pl)
        return 0;

    while((*pl)->sig) // Tengo que recorrer toda la lista hacia el final, sin embargo, me tengo que parar en el nodo anterior, ya que si voy hasta el ultimo no tengo forma de volver hacia atras para ver la info del ultimo nodo en si.
        pl = &(*pl)->sig;

    memcpy(info, (*pl)->info, min((*pl)->tam, tam));

    return 1;
}

void vaciar_lista(tLista* pl)
{
    tNodo* elim;

    while(*pl) // Hasta que no llegue al ultimo nodo (es decir, me caiga de la lista) voy a seguir eliminando.
    {
        elim = *pl; // Asigno a elim el primer nodo a eliminar.
        *pl = elim->sig; // Antes de eliminar, tengo que hacer que mi puntero de la lista, apunte al siguiente nodo que voy a eliminar para no perder los enlaces.
        free(elim->info);
        free(elim);
    }
}

int cmpEnteros(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int cmpCadenas(const void* s1, const void* s2)
{
    return strcmp((char*)s1, (char*)s2);
}

void map_lista(const tLista* pl, void(*accion)(void*, void*), void* param)
{
    while(*pl)
    {
        accion((*pl)->info, param);
        pl = &(*pl)->sig;
    }
}

void filter_lista(tLista* pl, int(*filtro)(const void*, void*), void* param)
{
    while(*pl)
    {
        if(!filtro((*pl)->info, param)) // Si cumple con la condicion de filtro, lo tengo que sacar, osea que me va a devolver 0 pero lo transformo en 1.
        {
            tNodo* elim = *pl;

            *pl = elim->sig;

            free(elim->info);
            free(elim);
        }
        else
            pl = &(*pl)->sig; // Si no lo tiene que eliminar avanzo al siguiente elemento.
    }
}

int reduce_lista(const tLista* pl, void* ret, int(*reduccion)(const void*, void*, void*), void* param)
{
    int r = 1;

    while(*pl && r)
    {
        r = reduccion((*pl)->info, ret, param);
        pl = &(*pl)->sig;
    }
    return 0;
}

int promedio_alu(const void* valu, void* vprom, void* vcant_alu)
{
    tAlumno* alu = (tAlumno*)valu;

    int* prom = (int*)vprom, *cant_alu = (int*)vcant_alu;

    *prom = ((*prom) * (*cant_alu) + alu->promedio) / (*cant_alu + 1);

    (*cant_alu)++;

    return 1;
}

void grabar_arch_bin(void* vinfo, void* vpf)
{
    FILE* pf = (FILE*)vpf;

    // Ver la version que devuelve el return de una variable en el fwrite para ver si hubo un error o no;

    fwrite(vinfo, sizeof(tAlumno), 1, pf);
}

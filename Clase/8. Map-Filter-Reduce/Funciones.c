

int poner_en_pila(tPila* pp, const void* info, size_t tam)
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

    if(!*pp)
        *pp = nue;

    else
        nue->sig = (*pp)->sig;

    *pp->sig = nue;

    return 1;
}

int sacar_de_pila(tPila* pp, void* info, size_t tam)
{
    tNodo* elim;

    if(!*pp)
        return 0;

    elim = *pp->sig;

    memcpy(info, elim->info, min(elim->tam, tam));

    if(elim == elim->sig)
        *pp = NULL;

    *pp->sig = elim->sig;

    free(elim->info);
    free(elim);

    return 1;
}

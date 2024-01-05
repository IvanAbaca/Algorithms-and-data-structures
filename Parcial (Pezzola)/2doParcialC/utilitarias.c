#include<utilitarias.h>
#include<string.h>
#include<varias.h>

int alta(tAlumno* alu, FILE* arch, tArbolBinBusq* pa)
{
    tRegInd ind = {alu->dni, 1384615};

    fseek(arch, 0L, SEEK_END);

    ind.nro_reg = ftell(arch) / sizeof(tAlumno);

    fwrite(alu, sizeof(tAlumno), 1, arch);

    int r;

    if((r=insertarRecArbolBinBusq(pa, &ind, sizeof(tRegInd), cmpInd))!= TODO_OK)
        return r;

    return TODO_OK;
}

int baja(tAlumno* alu, FILE* arch, tArbolBinBusq* pa)
{
    tRegInd ind = {alu->dni, 1515341};

    int r;

    if((r=eliminarElemArbolBinBusq(pa, &ind, sizeof(tRegInd), cmpInd)) != TODO_OK)
        return r;

    fseek(arch, ind.nro_reg*sizeof(tAlumno), SEEK_SET);

    if(fread(alu, sizeof(tAlumno), 1, arch) == 0)
        return ERROR_ARCHIVO;

    alu->estado = 'B';

    fseek(arch, ind.nro_reg*sizeof(tAlumno), SEEK_SET);

    fwrite(alu, sizeof(tAlumno), 1, arch);

    return TODO_OK;
}

int baja_ultimo(FILE* arch, tArbolBinBusq* pa)
{
    tAlumno auxAlu;
    tRegInd ind;
    int r;

    fseek(arch, -(long)(sizeof(tAlumno)), SEEK_END);
    if((r=fread(&auxAlu, sizeof(tAlumno), 1, arch) == 0))
       return ERROR_ARCHIVO;

    auxAlu.estado = 'B';

    ind.dni = auxAlu.dni;

    printf("\nDni: %d\nNombre Y Apellido: %s\nMaterias: %d\nPromedio: %.2f\nEstado: %c\n", auxAlu.dni, auxAlu.apyn, auxAlu.cant_materias, auxAlu.promedio, auxAlu.estado);

    fseek(arch, -(long)(sizeof(tAlumno)), SEEK_END);
    fwrite(&auxAlu, sizeof(tAlumno), 1, arch);

    eliminarElemArbolBinBusq(pa, &ind, sizeof(tRegInd), cmpInd);

    return TODO_OK;
}


int agregar_materia(FILE* arch, tArbolBinBusq* pindice)
{
    tAlumno alu;
    tRegInd ind;
    int r;

    ingresar_dni_alumno(&alu);

    ind.dni = alu.dni;

    if((r=buscarElemArbolBinBusq(pindice, &ind, sizeof(tRegInd), cmpInd) != TODO_OK))
        return r;

    fseek(arch, ind.nro_reg*sizeof(tAlumno), SEEK_SET);

    if(fread(&alu, sizeof(tAlumno), 1, arch) == 0)
        return ERROR_ARCHIVO;

    ingresar_nueva_materia(&alu);

    fseek(arch, ind.nro_reg*sizeof(tAlumno), SEEK_SET);
    fwrite(&alu, sizeof(tAlumno), 1, arch);

    return TODO_OK;
}

int compactar_y_reindexar(FILE** arch, tArbolBinBusq* pindice, const char* path)
{
    tRegInd ind;
    tAlumno alu;
    int cont = 0;
    int r;

    FILE* temp = fopen("temp.bin", "wb");

    if(!temp)
        return ERROR_ARCHIVO;

    fseek(*arch, 0L, SEEK_SET);

    vaciarArbolBin(pindice);

    if((r=fread(&alu, sizeof(tAlumno), 1, *arch))!=TODO_OK)
        return r;

    while(!feof(*arch))
    {
        if(alu.estado == 'A')
        {
            fwrite(&alu, sizeof(tAlumno), 1, temp);

            ind.dni = alu.dni;
            ind.nro_reg = cont++;

            if((r=insertarRecArbolBinBusq(pindice, &ind, sizeof(tRegInd), cmpInd))!=TODO_OK)
                return r;
        }

        if((r=fread(&alu, sizeof(tAlumno), 1, *arch))!=TODO_OK)
        return r;
    }

    fclose(temp);
    fclose(*arch);

    remove(path);
    rename("temp.bin", path);

    *arch = fopen(path, "r+b");

    return TODO_OK;
}

void ingresar_alumno(tAlumno* alu)
{
    ingresarDniAlumno_res(alu);
    printf("\nIngrese el Apellido y Nombre: ");
    fflush(stdin);
    gets(alu->apyn);
    printf("\nIngrese la cantidad de materias: ");
    scanf("%d", &(alu->cant_materias));
    printf("\nIngrese el promedio: ");
    scanf("%f", &(alu->promedio));
    alu->estado = 65;
}

void ingresar_dni_alumno(tAlumno* alu)
{
    printf("\nIngrese el DNI: ");
    scanf("%d", &(alu->dni));
}

void ingresar_nueva_materia(tAlumno* auxAlu)
{
    printf("\nDni: %d\nNombre Y Apellido: %s\nMaterias: %d\nPromedio: %.2f\nEstado: %c\n", auxAlu->dni, auxAlu->apyn, auxAlu->cant_materias, auxAlu->promedio, auxAlu->estado);

    float nota;

    printf("\nIngrese la nota: ");
    scanf("%f", &nota);

    auxAlu->promedio = ((auxAlu->promedio * auxAlu->cant_materias) + nota) / (auxAlu->cant_materias + 1);
    auxAlu->cant_materias++;

    printf("\nDni: %d\nNombre Y Apellido: %s\nMaterias: %d\nPromedio: %.2f\nEstado: %c\n", auxAlu->dni, auxAlu->apyn, auxAlu->cant_materias, auxAlu->promedio, auxAlu->estado);
}


void imprimir_alumno(const tAlumno* alu)
{

}


void mostrar_dni(const tRegInd* r)
{

}

void imprimir_archivo(FILE* arch)
{

}

void imprimir_archivo_ordenado(FILE* arch, tArbolBinBusq* pa)
{

}

int cmpInd(const void* a, const void* b)
{
    tRegInd ia = *(tRegInd*)a;
    tRegInd ib = *(tRegInd*)b;

    if(ia.dni > ib.dni)
        return 1;

    if(ia.dni < ib.dni)
        return -1;

    return 0;
}

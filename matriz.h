#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define Matriz struct _Matriz
#define INDEX a->I
#define INDMAX a->MAX
#define TIPO a->tipo
#define TAM a->T
#include "pila.h"


struct _Matriz
{
    char tipo;
    int I;
    int MAX;
    int *T;
    char **C;
    int **V;
    float **F;
};

void salir(char *q);
int tam(Matriz *a);
void nuevaMatriz (Matriz *a);
void cargarMatriz (Matriz *a);
void cargarMatrizRan (Matriz *a);
void mostrarMatriz (Matriz *a);
void sumarMatriz (Matriz *a);
void promedioMatriz (Matriz *a);
void buscarEnMatriz (Matriz *a);

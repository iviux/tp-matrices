#include <stdio.h>
#include <malloc.h>
#define Pila struct _Pila
#define P_Pila struct _Pila *

struct _Pila
{
    int *valores;
    int postope;
};

void inicpila(P_Pila p);
void apilar(P_Pila p, int dato);
void apilar(P_Pila p, int dato);
int desapilar(P_Pila p);
int tope(P_Pila p);
int pilavacia(P_Pila p);
void leer (P_Pila p);
void mostrar(P_Pila p);
void invertir(P_Pila p);
void mover(P_Pila p, int posAnt, int posDes);
void subir(P_Pila p, int bloque);
void cargarPila (Pila *carga);
void pasarPila(Pila *vieja, Pila *nueva);
void transferirPila(Pila *vieja, Pila *nueva);
int buscarMenor(P_Pila p);
void transferirPilaOrdenada(P_Pila p, P_Pila p2);
void ordenar(P_Pila p);
void insertar(P_Pila p, int n);
void ordenarInsercion(P_Pila p, P_Pila p2);
int sumarUltimos2(Pila p);
int suma (Pila p);
int contar (Pila p);
float division (int suma, int cantidad);
void promedio (P_Pila p);
int aDecimal (Pila p);

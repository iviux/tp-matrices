#include "array.h"


void inicpila(P_Pila p)
{
    int *aux;
    aux = (int *)malloc(50*sizeof(int));
    p->valores = aux;
    p->postope=0;
}

void apilar(P_Pila p, int dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int desapilar(P_Pila p)
{
    int z = p->valores[p->postope -1];
    p->postope--;
    return z;
}

int tope(P_Pila p)
{
    return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
    return (p->postope == 0);
}

void leer (P_Pila p)
{
    int aux = 0;
    if (p->postope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    }
    else
        printf("Error: la pila esta llena");
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}

void invertir(P_Pila p)
{
    int index = (*p).postope;
    int valoresInvertidos[index];
    for (int i = 0; i < index; i++)
    {
        valoresInvertidos[i] = (*p).valores[(index - 1) - i];
    }
    for (int i = 0; i < index; i++)
    {
        (*p).valores[i] = valoresInvertidos[i];
    }
}

void mover(P_Pila p, int posAnt, int posDes)
{
    posAnt -= 1;
    posDes -= 1;
    int aux = (*p).valores[posAnt];
    (*p).valores[posAnt] = (*p).valores[posDes];
    (*p).valores[posDes] = aux;

}

void subir(P_Pila p, int bloque)
{
    bloque -= 1;

    int index = (*p).postope;
    int pilaMovida[index];

    for (int i = 0; i < index; i++)
    {
        if (i < bloque)
        {
            pilaMovida[i] = (*p).valores[i];
        }
        else if (i >= bloque && i < index - 1)
        {
            pilaMovida[i] = (*p).valores[i+1];
        }
        else
        {
            pilaMovida[i] = (*p).valores[bloque];
        }
    }
    for (int i = 0; i < index; i++)
    {
        (*p).valores[i] = pilaMovida[i];
    }

}

void cargarPila (P_Pila p)
{
    int elementos;
    printf("Cuantos elementos desea agregar a la pila? ");
    fflush(stdin);
    scanf("%d", &elementos);

    for (int i = 0; i < elementos; i ++)
    {
        leer(p);
    }

    printf("La pila fue cargada con %d elementos.\n", elementos);
}

void pasarPila(P_Pila p, P_Pila p2)
{
    while (!pilavacia(p))
    {
        apilar(p2, desapilar(p));
    }

}

void transferirPila(P_Pila p, P_Pila p2)
{
    while (!pilavacia(p))
    {
        apilar(p2, desapilar(p));
    }

    invertir(p2);
}

int buscarMenor(P_Pila p)
{
    Pila aux;
    inicpila(&aux);
    int menor = tope(p);

    while (!pilavacia(p))
    {
        if(tope(p)>=menor)
        {
            apilar(&aux, desapilar(p));
        }
        else
        {
            menor=tope(p);
        }
    }
    while(!pilavacia(&aux))
    {
        if(tope(&aux)!= menor)
        {
            apilar(p, desapilar(&aux));
        }
        else
        {
            desapilar(&aux);
        }
    }

    return menor;
}

void transferirPilaOrdenada (P_Pila p, P_Pila p2)
{
    Pila aux;
    inicpila(&aux);
    int menor;

    while (!pilavacia(p))
    {
        menor = tope(p);

        while (!pilavacia(p))
        {
            if(tope(p)>=menor)
            {
                apilar(&aux, desapilar(p));
            }
            else
            {
                menor=tope(p);
            }
        }

        while(!pilavacia(&aux))
        {
            if(tope(&aux)!= menor)
            {
                apilar(p, desapilar(&aux));
            }
            else
            {
                apilar(p2, desapilar(&aux));
            }
        }

    }

}

void ordenar (P_Pila p)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);
    int menor;

    while (!pilavacia(p))
    {
        apilar(&aux, desapilar(p));
    }

    while (!pilavacia(&aux))
    {
        menor = tope(&aux);

        while (!pilavacia(&aux))
        {
            if(tope(&aux) >= menor)
            {
                apilar(&aux2, desapilar(&aux));
            }
            else
            {
                menor = tope(&aux);
            }
        }

        while(!pilavacia(&aux2))
        {
            if(tope(&aux2)!= menor)
            {
                apilar(&aux, desapilar(&aux2));
            }
            else
            {
                apilar(p, desapilar(&aux2));
            }
        }
    }
}

void insertar(P_Pila p, int n)
{
    apilar(p, n);
    ordenar(p);
}

void ordenarInsercion(P_Pila p, P_Pila p2)
{
    while(!pilavacia(p))
    {
        insertar(p2, desapilar(p));
    }
}

int sumarUltimos2(Pila p)
{
    int suma = 0;
    for(int i = 0; i < 2; i++)
    {
        suma += tope(&p);
        desapilar(&p);
    }
    return suma;
}

int suma (Pila p)
{
    int suma = 0;
    while (!pilavacia(&p))
    {
        suma += tope(&p);
        desapilar(&p);
    }

    return suma;
}

int contar (Pila p)
{
    int i = 0;
    while (!pilavacia(&p))
    {
        i++;
        desapilar(&p);
    }

    return i;
}

float division (int suma, int cantidad)
{
    float promedio = (float) suma / cantidad;

    return promedio;
}

void promedio (P_Pila p)
{
    int sum = suma(*p);
    int cant = contar(*p);
    float prom = division(sum, cant);
    printf("El promedio de la pila es %.2f\n", prom);
}

int aDecimal (Pila p)
{
    int dec = 0;
    int i = 1;

    while (!pilavacia(&p))
    {
        dec += (tope(&p)) * i;
        i = i * 10;
        desapilar(&p);
    }

    return dec;
}

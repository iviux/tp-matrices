#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "matriz.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    int r = 0;
    char q;
    Matriz matrix;
    nuevaMatriz(&matrix);


    do
    {
        system("cls");
        printf("Trabajo Practico de Funciones con Matrices.\n\n");
        printf("Seleccione el ejercicio que desea visualizar: \n\n");
        printf("  1) Cargar la Matriz.\n");
        printf("  2) Mostrar la Matriz.\n");
        printf("  3) Cargar aleatorio.\n");
        printf("  4) Sumar la Matriz.\n");
        printf("  5) Calcular el promedio de la Matriz.\n");
        printf("  6) Buscar en la Matriz. \n");
        printf("  7) Ordenar Matriz.\n");
        printf("  8) Mostrar determinante.\n");
        printf("  9) Verificar si tiene inversa.\n");

        fflush(stdin);
        scanf("%d", &r);
        system("cls");

        switch(r)
        {
            case 0:
            {
                q = 'q';

                break;
            }
            case 1:
            {
                printf("  1) Cargar la Matriz.\n\n");

                cargarMatriz (&matrix);

                break;
            }
            case 2:
            {
                printf("2) Mostrar la Matriz.\n\n");

                mostrarMatriz(&matrix);

                salir(&q);

                break;
            }
            case 3:
            {
                printf("3) Cargar aleatorio\n\n");

                cargarMatrizRan(&matrix);

                salir(&q);

                break;
            }
            case 4:
            {
                printf("4) Sumar la Matriz.\n\n");

                sumarMatriz (&matrix);

                salir(&q);

                break;
            }
            case 5:
            {
                printf("5) Calcular el promedio de la Matriz.\n\n");

                promedioMatriz (&matrix);

                salir(&q);

                break;
            }
            case 6:
            {
                printf("6) Buscar en la Matriz. \n\n");

                buscarEnMatriz (&matrix);

                salir(&q);

                break;
            }
            case 7:
            {
                printf("7) Ordenar Matriz.\n\n");

                salir(&q);

                break;
            }
            case 8:
            {
                printf("8) Mostrar determinante.\n\n");

                salir(&q);

                break;
            }
            case 9:
            {
                printf("9) Verificar si tiene inversa.\n\n");

                salir(&q);

                break;
            }
            default:
            {

            }
        }

    }while(q != 'q');



    return 0;
}

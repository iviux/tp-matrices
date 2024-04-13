#include "matriz.h"

void salir(char *q)
{
    // Funcion para decidir si se desea seguir editando un arreglo o volver a la seleccion

    printf("\nPresione una tecla para continuar, q para salir.");
    fflush(stdin);
    *q = getch();

    system("cls");
}

int tam(Matriz *a)
{
    // Funcion para que el usuario seleccione el tamaño del arreglo

    int t;
    printf("Ingrese el tamaño de la fila %d: ", INDEX+1);
    scanf("%d", &t);
    printf("\n");
    return t;
}

void nuevaMatriz(Matriz *a)
{

    // Seleccionar el tipo de dato que almacenara el arreglo
    while(TIPO != 'c' && TIPO != 'i' && TIPO != 'f' && TIPO != 's')
    {
        printf("Que tipo de arreglo se va a usar? (c, i, f, s)\n");
        fflush(stdin);
        TIPO = getch();
    }

    TAM = (int *) malloc(10*sizeof(int));

    if(TIPO == 'c' || TIPO == 's')
    {
        a->C = (char **) malloc(10*sizeof(char*));
    }
    else if (TIPO == 'i')
    {
        a->V =(int **) malloc(10*sizeof(int*));
    }
    else if (TIPO == 'f')
    {
        a->F =(float **) malloc(10*sizeof(float*));
    }

    INDMAX = 0;

}

void cargarMatriz (Matriz *a)
{
    char q;

    do
    {
        system("cls");

        if (TIPO == 'c')
        {
            TAM[INDEX] = tam(a);

            a->C[INDEX] = (char *) malloc((TAM[INDEX]+1)*sizeof(char));

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                printf("Ingrese el caracter %d de la fila %d: ", i+1, INDEX+1);
                fflush(stdin);
                scanf(" %c", &a->C[INDEX][i]);
                printf("\033[F\033[K");
            }

            a->C[INDEX][TAM[INDEX]] = 0;
        }
        else if (TIPO == 'i')
        {
            TAM[INDEX] = tam(a);

            a->V[INDEX] = (int *) malloc(TAM[INDEX]*sizeof(int));

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                printf("Ingrese el numero %d de la fila %d: ", i+1, INDEX +1);
                scanf("%d", &(a->V[INDEX][i]));
                printf("\033[F\033[K");
            }
        }
        else if (TIPO == 'f')
        {
            TAM[INDEX] = tam(a);

            a->F[INDEX] = (float *) malloc(TAM[INDEX]*sizeof(float));

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                printf("Ingrese el float %d de la fila %d: ", i+1, INDEX +1);
                scanf("%f", &(a->F[INDEX][i]));
                printf("\033[F\033[K");
            }
        }
        else if (TIPO == 's')
        {
            a->C[INDEX] = (char *) malloc(20*sizeof(char));

            printf("Ingrese el String de la fila %d: ", INDEX+1);
            fflush(stdin);
            scanf("%s", a->C[INDEX]);
        }

        INDMAX ++;
        INDEX ++;

        salir(&q);

    }while (q != 'q');

    system("cls");
    printf("La Matriz fue cargada con %d elementos.\n", INDMAX);
    system("pause");

}

void cargarMatrizRan (Matriz *a)
{
    srand(time(NULL));

    int filas = rand() % 9 + 2;
    INDMAX = filas;

    if (TIPO == 'c' || TIPO == 's')
    {
        for (INDEX = 0; INDEX < filas; INDEX++)
        {
            int columnas = rand() % 10 + 1;
            TAM[INDEX] = columnas;

            a->C[INDEX] = (char *) malloc(columnas+1*sizeof(char));

            for (int i = 0; i < columnas; i++)
            {
                int randchar = rand() % 25 + 98;
                a->C[INDEX][i] = randchar;
                a->C[INDEX][i+1] = 0;
            }
        }
    }
    else if (TIPO == 'i')
    {
        for (INDEX = 0; INDEX < filas; INDEX++)
        {
            int columnas = rand() % 10 + 1;
            TAM[INDEX] = columnas;

            a->V[INDEX] = (int *) malloc(columnas*sizeof(int));

            for (int i = 0; i < columnas; i++)
            {
                a->V[INDEX][i] = rand() % 10 + 1;
            }
        }
    }
    else if (TIPO == 'f')
    {
        for (INDEX = 0; INDEX < filas; INDEX++)
        {
            int columnas = rand() % 10 + 1;
            TAM[INDEX] = columnas;

            a->F[INDEX] = (float *) malloc(columnas*sizeof(float));

            for (int i = 0; i < columnas; i++)
            {
                a->F[INDEX][i] =(double) rand() / RAND_MAX * 10;
            }
        }
    }

    system("cls");
    printf("La Matriz fue cargada con %d elementos.\n", INDMAX);
}

void mostrarMatriz (Matriz *a)
{
    if (TIPO == 'c')
    {
        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                //if(i % 10 == 0)
                //{
                //printf("  \n");
                //}
                printf("| %c ", a->C[INDEX][i]);
            }
            printf("\n\n");
        }
    }
    else if (TIPO == 'i')
    {
        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                //if(i % 10 == 0)
                //{
                //printf("  \n");
                //}
                printf("| %d ", a->V[INDEX][i]);
            }
            printf("\n\n");

        }
    }
    else if (TIPO == 'f')
    {
        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                //if(i % 10 == 0)
                //{
                //printf("  \n");
                //}
                printf("| %.2f ", a->F[INDEX][i]);
            }
            printf("\n\n");
        }
    }
    else
    {
        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {

            printf("%d) %s", INDEX+1, a->C[INDEX]);

            printf("\n\n");
        }
    }
}

void sumarMatriz (Matriz *a)
{
    if (TIPO == 'i')
    {
        int suma = 0;

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                suma += a->V[INDEX][i];
            }
        }

        printf("La suma de la Matriz es %d", suma);
    }
    else if (TIPO == 'f')
    {
        float suma = 0;

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                suma += a->F[INDEX][i];
            }
        }

        printf("La suma de la Matriz es %.2f", suma);
    }
    else
    {
        printf("El arreglo no se puede sumar.\n");
    }
}

void promedioMatriz (Matriz *a)
{
    if (TIPO == 'i')
    {
        int suma = 0;
        float promedio = 0;

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                suma += a->V[INDEX][i];
            }
            promedio += TAM[INDEX];
        }
        promedio = suma / promedio;

        printf("El promedio de la Matriz es %.2f", promedio);
    }
    else if (TIPO == 'f')
    {
        float suma = 0;
        float promedio = 0;

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                suma += a->F[INDEX][i];
            }
            promedio += TAM[INDEX];
        }
        promedio = suma / promedio;

        printf("El promedio de la Matriz es %.2f", promedio);
    }
    else
    {
        printf("El arreglo no se puede promediar.\n");
    }
}

void buscarEnMatriz (Matriz *a)
{
    if (TIPO == 'c')
    {
        int flag = 0;
        char buscar;

        printf("Ingrese el elemento que desea buscar en la matriz: ");
        fflush(stdin);
        scanf(" %c", &buscar);

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                if (a->C[INDEX][i] == buscar)
                {
                    flag++;
                }
            }
        }

        if(flag == 0)
        {
            printf("El elemento %c no se encuentra en la Matriz.", buscar);
        }
        else
        {
            printf("El elemento %c se encuentra %d veces en la Matriz.", buscar, flag);
        }
    }
    else if (TIPO == 'i')
    {
        int flag = 0, buscar = 0;

        printf("Ingrese el elemento que desea buscar en la matriz: ");
        scanf("%d", &buscar);

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                if (a->V[INDEX][i] == buscar)
                {
                    flag++;
                }
            }
        }

        if(flag == 0)
        {
            printf("El elemento %d no se encuentra en la Matriz.", buscar);
        }
        else
        {
            printf("El elemento %d se encuentra %d veces en la Matriz.", buscar, flag);
        }
    }
    else if (TIPO == 'f')
    {
        int flag = 0;
        float buscar = 0;

        printf("Ingrese el elemento que desea buscar en la matriz: ");
        scanf("%f", &buscar);

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            for (int i = 0; i < TAM[INDEX]; i++)
            {
                if (a->F[INDEX][i] == buscar)
                {
                    flag++;
                }
            }
        }

        if(flag == 0)
        {
            printf("El elemento %.2f no se encuentra en la Matriz.", buscar);
        }
        else
        {
            printf("El elemento %.2f se encuentra %d veces en la Matriz.", buscar, flag);
        }
    }
    else
    {
        int esta = 1, flag = 0;
        char *buscar;

        printf("Ingrese el string que desea buscar en la matriz: ");
        fflush(stdin);
        scanf("%s", buscar);

        for (INDEX = 0; INDEX < INDMAX; INDEX ++)
        {
            esta = strcmp(a->C[INDEX], buscar);
            if(esta == 0)
            {
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("El elemento '%s' no se encuentra en la Matriz.", buscar);
        }
        else
        {
            printf("El elemento '%s' se encuentra en la Matriz.", buscar);
        }
    }
}


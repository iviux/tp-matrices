#include "array.h"

void salir(char *q)
{
    // Funcion para decidir si se desea seguir editando un arreglo o volver a la seleccion

    printf("\nPresione una tecla para continuar editando el arreglo, q para salir.");
    fflush(stdin);
    *q = getch();

    system("cls");
}

int tam()
{
    // Funcion para que el usuario seleccione el tamaño del arreglo

    int t;
    printf("Ingrese el tamaño de su arreglo: ");
    scanf("%d", &t);
    printf("\n");
    return t;
}


void nuevoArreglo(Arreglo *a)
{

    // Seleccionar el tipo de dato que almacenara el arreglo
    while(TIPO != 'c' && TIPO != 'i' && TIPO != 'f' && TIPO != 'r')
    {
        printf("Que tipo de arreglo se va a usar? (c, i, f, r)\n");
        fflush(stdin);
        TIPO = getch();
    }

    TAM = (int *) malloc(10*sizeof(int));

    if(TIPO == 'c')
    {
        a->C = (char **) malloc(10*sizeof(char*));
    }
    else if (TIPO == 'i')
    {
        a->V =(int **) malloc(10*sizeof(int*));
    }
    else if ((TIPO == 'f' || TIPO == 'r'))
    {
        a->F =(float **) malloc(10*sizeof(float*));
    }

    INDMAX = 0;

}

void selecArreglo(Arreglo *a)
{
    // Crear un arreglo o seleccionar un arreglo existente.
    // Control para que solo se pueda ingresar a arreglos existentes o crear el arreglo consecutivo al ultimo creado

    do
    {
        for (int i = 0; i < INDMAX; i++)
        {
            INDEX = i;
            mostrarArreglo(a);
        }

        scanf("%d", &INDEX);
    }
    while (INDEX > INDMAX + 1 || INDEX <= 0);

    INDEX = INDEX -1;

    // Si el numero del arreglo es igual al indice de arreglos existentes, incremento el indice creando uno nuevo
    if (INDEX == INDMAX)
    {
        INDMAX++;
        cargarArreglo(a);
    }

}

void cargarArreglo(Arreglo *a)
{
    system("cls");

    // Establezco el tamaño que va a tener el arreglo seleccionado (INDEX = indice de arreglo)
    TAM[INDEX] = tam();

    if (TIPO == 'c')
    {
        a->C[INDEX] = (char *) malloc((TAM[INDEX]+1)*sizeof(char));

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("Ingrese el caracter N%d: ", i+1);
            fflush(stdin);
            scanf(" %c", &a->C[INDEX][i]);
            printf("\033[F\033[K");
        }

        a->C[INDEX][TAM[INDEX]] = '\0';
    }
    else if (TIPO == 'i')
    {
        a->V[INDEX] = (int *) malloc(TAM[INDEX]*sizeof(int));

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("Ingrese el numero %d: ", i+1);
            scanf("%d", &(a->V[INDEX][i]));
            printf("\033[F\033[K");
        }
    }
    else if (TIPO == 'f')
    {
        a->F[INDEX] = (float *) malloc(TAM[INDEX]*sizeof(float));

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            printf("Ingrese el float %d: ", i+1);
            scanf("%f", &(a->F[INDEX][i]));
            printf("\033[F\033[K");
        }
    }
    else if (TIPO == 'r')
    {
        srand(time(NULL));

        a->F[INDEX] = (float *) malloc(TAM[INDEX]*sizeof(float));

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            a->F[INDEX][i] =(double) rand() / RAND_MAX * 100;
        }
    }

    printf("\033[F\033[K");
    printf("\nEl arreglo fue cargado con %d elementos.\n", TAM[INDEX]);

}

void mostrarArreglo(Arreglo *a)
{
    if (TIPO == 'c')
    {
        printf("\n%d: ", INDEX+1);
        for (int i = 0; i < TAM[INDEX]; i++)
        {
//            if(i % 10 == 0)
//            {
//                printf("  \n");
//            }
            printf("%c |", a->C[INDEX][i]);
        }
        printf("\n\n");
    }
    else if (TIPO == 'i')
    {
        printf("\n%d: ", INDEX+1);
        for (int i = 0; i < TAM[INDEX]; i++)
        {
//            if(i % 10 == 0)
//            {
//                printf("  \n");
//            }
            printf("| %d ", a->V[INDEX][i]);
        }
        printf("\n\n");
    }
    else
    {
        printf("\n%d: ", INDEX+1);
        for (int i = 0; i < TAM[INDEX]; i++)
        {
//            if(i % 10 == 0)
//            {
//                printf("  \n");
//            }
            printf("| %.2f ", a->F[INDEX][i]);
        }
        printf("\n\n");
    }
}

void sumarArreglo(Arreglo *a)
{
    if (TIPO == 'i')
    {
        int suma = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            suma += a->V[INDEX][i];
        }

        printf("\nLa suma de los elementos del arreglo es %d.", suma);
    }
    else if (TIPO == 'f' || TIPO == 'r')
    {
        float suma = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            suma += a->F[INDEX][i];
        }

        printf("\nLa suma de los elementos del arreglo es %.2f", suma);
    }


}

void arregloAPila(Arreglo *a, Pila *p)
{
    for (int i = 0; i < TAM[INDEX]; i++)
    {
        apilar(p, a->V[INDEX][i]);
    }

    printf("Arreglo:\n\n");
    mostrarArreglo(a);

    printf("\nPILITA:\n");
    mostrar(p);
}

void buscar(Arreglo *a)
{
    int flag = 0;
    printf("Que elemento desea buscar en el arreglo? ");

    if (TIPO == 'i')
    {
        int n = 0;

        scanf("%d",&n);

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->V[INDEX][i] == n)
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl elemento %d no se encuentra en el arreglo.\n", n);
            mostrarArreglo(a);
        }
        else
        {
            printf("\nEl elemento %d se encuentra en el arreglo.\n", n);
            mostrarArreglo(a);
        }
    }
    else if (TIPO == 'c')
    {
        char n;

        fflush(stdin);
        scanf("%c",&n);

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->C[INDEX][i] == n)
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl elemento %c no se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
        else
        {
            printf("\nEl elemento %c se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
    }
    else if (TIPO == 'f')
    {
        float n = 0;

        scanf("%f",&n);

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->F[INDEX][i] == n)
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl elemento %.2f no se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
        else
        {
            printf("\nEl elemento %.2f se encuentra en el arreglo.", n);
            mostrarArreglo(a);
        }
    }
}

void ordenarArreglo (Arreglo *a)
{
    printf("Con que metodo desea ordenar el arreglo? (i, s) \n");
    fflush(stdin);
    char o = getch();

    while (o != 'i' && o != 's')
    {
        printf("\033[F\033[K");
        printf("Valor incorrecto, con que metodo desea ordenar el arreglo? (i, s) \n");
        fflush(stdin);
        o = getch();
    }


    if (o == 's')
    {
        if (TIPO == 'c')
        {
            char ordenada;

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                ordenada = a->C[INDEX][i];
                for (int j = i; j < TAM[INDEX]; j++)
                {
                    if (a->C[INDEX][j] < ordenada)
                    {
                        ordenada = a->C[INDEX][j];
                        a->C[INDEX][j] = a->C[INDEX][i];
                        a->C[INDEX][i] = ordenada;
                    }
                }
            }
        }
        else if (TIPO == 'i')
        {
            int ordenada = 0;

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                ordenada = a->V[INDEX][i];
                for (int j = i; j < TAM[INDEX]; j++)
                {
                    if (a->V[INDEX][j] < ordenada)
                    {
                        ordenada = a->V[INDEX][j];
                        a->V[INDEX][j] = a->V[INDEX][i];
                        a->V[INDEX][i] = ordenada;
                    }
                }
            }
        }
        else
        {
            float ordenada = 0;

            for (int i = 0; i < TAM[INDEX]; i++)
            {
                ordenada = a->F[INDEX][i];
                for (int j = i; j < TAM[INDEX]; j++)
                {
                    if (a->F[INDEX][j] < ordenada)
                    {
                        ordenada = a->F[INDEX][j];
                        a->F[INDEX][j] = a->F[INDEX][i];
                        a->F[INDEX][i] = ordenada;
                    }
                }
            }
        }
    }
    else
    {
        if (TIPO == 'c')
        {
            char ordenada;

            for (int i = 1; i < TAM[INDEX]; i++)
            {
                ordenada = a->C[INDEX][i];
                int j = i - 1;

                while (j >= 0 && a->C[INDEX][j] > ordenada)
                {
                    a->C[INDEX][j + 1] = a->C[INDEX][j];
                    j--;
                }

                a->C[INDEX][j + 1] = ordenada;
            }
        }
        else if (TIPO == 'i')
        {
            int ordenada;

            for (int i = 1; i < TAM[INDEX]; i++)
            {
                ordenada = a->V[INDEX][i];
                int j = i - 1;

                while (j >= 0 && a->V[INDEX][j] > ordenada)
                {
                    a->V[INDEX][j + 1] = a->V[INDEX][j];
                    j--;
                }

                a->V[INDEX][j + 1] = ordenada;
            }
        }
        else
        {
            float ordenada;

            for (int i = 1; i < TAM[INDEX]; i++)
            {
                ordenada = a->F[INDEX][i];
                int j = i - 1;

                while (j >= 0 && a->F[INDEX][j] > ordenada)
                {
                    a->F[INDEX][j + 1] = a->F[INDEX][j];
                    j--;
                }

                a->F[INDEX][j + 1] = ordenada;
            }
        }
    }

}

void insertarArreglo(Arreglo *a)
{
    int ins = 0, t = 0;

    if (TIPO == 'c')
    {
        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = TAM[INDEX];
        TAM[INDEX] += ins;



        for (int i = t; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            fflush(stdin);
            scanf("%c", &(a->C[INDEX][i]));

        }
        a->C[INDEX][TAM[INDEX]] = '\0';

    }
    else if (TIPO == 'i')
    {
        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = TAM[INDEX];
        TAM[INDEX] += ins;



        for (int i = t; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            scanf("%d", &(a->V[INDEX][i]));
        }
    }
    else
    {
        printf("Cuantos elementos desea agregar al arreglo? ");
        scanf("%d", &ins);

        t = TAM[INDEX];
        TAM[INDEX] += ins;



        for (int i = t; i < TAM[INDEX]; i++)
        {
            printf("Ingrese un elemento para insertar al arreglo: ");
            scanf("%f", &(a->F[INDEX][i]));
        }
    }

    printf("Se cargaron %d elementos en el arreglo.", ins);

}

void buscarMayorArreglo(Arreglo *a)
{
    if (TIPO == 'c')
    {
        char mayor;
        mayor = a->C[INDEX][0];

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->C[INDEX][i] > mayor)
            {
                mayor = a->C[INDEX][i];
            }
        }

        printf("El mayor elemento del arreglo es: %c\n", mayor);
    }
    else if (TIPO == 'i')
    {
        int mayor;
        mayor = a->V[INDEX][0];

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->V[INDEX][i] > mayor)
            {
                mayor = a->V[INDEX][i];
            }
        }

        printf("El mayor elemento del arreglo es: %d\n", mayor);
    }
    else
    {
        float mayor;
        mayor = a->F[INDEX][0];

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->F[INDEX][i] > mayor)
            {
                mayor = a->F[INDEX][i];
            }
        }

        printf("El mayor elemento del arreglo es: %.2f\n", mayor);
    }
}

void esCapicua(Arreglo *a)
{
    if (TIPO == 'c')
    {
        int flag = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->C[INDEX][i] != a->C[INDEX][TAM[INDEX] - (i + 1)])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl arreglo es capicúa.\n");
        }
        else
        {
            printf("\nEl arreglo no es capicúa.\n");
        }
    }
    else if (TIPO == 'i')
    {
        int flag = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->V[INDEX][i] != a->V[INDEX][TAM[INDEX] - (i + 1)])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl arreglo es capicúa.\n");
        }
        else
        {
            printf("\nEl arreglo no es capicúa.\n");
        }
    }
    else
    {
        int flag = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (a->F[INDEX][i] != a->F[INDEX][TAM[INDEX] - (i + 1)])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("\nEl arreglo es capicúa.\n");
        }
        else
        {
            printf("\nEl arreglo no es capicúa.\n");
        }
    }
}

void invertirArreglo(Arreglo *a)
{
    if (TIPO == 'c')
    {
        for (int i = 0; i < TAM[INDEX]/2; i++)
        {
            a->C[INDEX][i] = a->C[INDEX][i] + a->C[INDEX][TAM[INDEX] - (i+1)];

            a->C[INDEX][TAM[INDEX] - (i+1)] = a->C[INDEX][i] - a->C[INDEX][TAM[INDEX] - (i+1)];

            a->C[INDEX][i] = a->C[INDEX][i] - a->C[INDEX][TAM[INDEX] - (i+1)];
        }
    }
    else if (TIPO == 'i')
    {
        for (int i = 0; i < TAM[INDEX]/2; i++)
        {
            a->V[INDEX][i] = a->V[INDEX][i] + a->V[INDEX][TAM[INDEX] - (i+1)];

            a->V[INDEX][TAM[INDEX] - (i+1)] = a->V[INDEX][i] - a->V[INDEX][TAM[INDEX] - (i+1)];

            a->V[INDEX][i] = a->V[INDEX][i] - a->V[INDEX][TAM[INDEX] - (i+1)];
        }
    }
    else
    {
        for (int i = 0; i < TAM[INDEX]/2; i++)
        {
            a->F[INDEX][i] = a->F[INDEX][i] + a->F[INDEX][TAM[INDEX] - (i+1)];

            a->F[INDEX][TAM[INDEX] - (i+1)] = a->F[INDEX][i] - a->F[INDEX][TAM[INDEX] - (i+1)];

            a->F[INDEX][i] = a->F[INDEX][i] - a->F[INDEX][TAM[INDEX] - (i+1)];
        }
    }
}

void combinarArreglos(Arreglo *a)
{
    int index[2], tamtotal = 0;
    system("cls");
    printf("Elija el primer arreglo a combinar: ");

    selecArreglo(a);
    index[0] = INDEX;
    tamtotal += TAM[INDEX];

    system("cls");
    printf("Elija el segundo arreglo a combinar: ");

    selecArreglo(a);
    index[1] = INDEX;
    tamtotal += TAM[INDEX];

    system("cls");
    printf("Elija un arreglo de destino: ");

    INDEX ++;
    INDMAX ++;
    TAM[INDEX] = tamtotal;

    system("cls");

    if (TIPO == 'c')
    {
        a->C[INDEX] = (char *) malloc((TAM[INDEX])*sizeof(char));

        int j = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (i < TAM[index[0]])
            {
               a->C[INDEX][j] = a->C[index[0]][i];
               j++;
            }
            if (i < TAM[index[1]])
            {
              a->C[INDEX][j] = a->C[index[1]][i];
              j++;
            }
        }

        a->C[INDEX][TAM[INDEX]] = '\0';
    }
    else if (TIPO == 'i')
    {
        a->V[INDEX] = (int *) malloc(TAM[INDEX]*sizeof(int));

        int j = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (i < TAM[index[0]])
            {
               a->V[INDEX][j] = a->V[index[0]][i];
               j++;
            }
            if (i < TAM[index[1]])
            {
              a->V[INDEX][j] = a->V[index[1]][i];
              j++;
            }
        }
    }
    else if (TIPO == 'f')
    {
        a->F[INDEX] = (float *) malloc(TAM[INDEX]*sizeof(float));

        int j = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            if (i < TAM[index[0]])
            {
               a->F[INDEX][j] = a->F[index[0]][i];
               j++;
            }
            if (i < TAM[index[1]])
            {
              a->F[INDEX][j] = a->F[index[1]][i];
              j++;
            }
        }
    }

    ordenarArreglo(a);
}

void sumarAnteriores(Arreglo *a)
{
    INDEX++;
    INDMAX++;
    TAM[INDEX] = TAM[INDEX-1];

    if (TIPO == 'i')
    {
        a->V[INDEX] = (int *) malloc(TAM[INDEX]*sizeof(int));

        int suma = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            suma = 0;

            for (int j = 0; j <= i; j++)
            {
                suma += a->V[INDEX - 1][j];
            }

            a->V[INDEX][i] = suma;


        }

        mostrarArreglo(a);
    }
    else if (TIPO == 'f' || TIPO == 'r')
    {
        a->F[INDEX] = (int *) malloc(TAM[INDEX]*sizeof(int));

        float suma = 0;

        for (int i = 0; i < TAM[INDEX]; i++)
        {
            suma = 0;

            for (int j = 0; j <= i; j++)
            {
                suma += a->F[INDEX - 1][j];
            }

            a->F[INDEX][i] = suma;


        }

        mostrarArreglo(a);
    }
}

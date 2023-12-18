#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#define LIMITE 200

char *tablaDeSimbolos[LIMITE];
int posicionLibre = 0;

int contiene_identificador(char *identificador)
{
    for (int i = 0; i < posicionLibre; i++)
    {
        if (!strcmp(tablaDeSimbolos[i], identificador))
            return 1;
    }
    return 0;
}

void agregar_identificador(char *identificador)
{
    if (posicionLibre < LIMITE)
    {
        tablaDeSimbolos[posicionLibre] = identificador;
        posicionLibre++;
    }
    else
    {
        printf("Tabla de símbolos completa.");
    }
}
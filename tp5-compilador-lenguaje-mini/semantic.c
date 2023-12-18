#include "semantic.h"
#include <string.h>

char buffer[120];
int cantidadTemporales = 0;

void empezar(char *nombrePrograma)
{
    generar_pseudo_ensamblador("Load", "rtlib", nombrePrograma, "");
    return;
}

void asignar(char *valorL, char *valorR)
{
    generar_pseudo_ensamblador("Store", valorR, valorL, "");
    free(valorL);
    free(valorR);
    return;
}

void leer(char *valorL)
{
    generar_pseudo_ensamblador("Read", valorL, "Integer", "");
    free(valorL);
    return;
}

void escribir(char *identificador)
{
    generar_pseudo_ensamblador("Write", identificador, "Integer", "");
    free(identificador);
    return;
}

void finalizar()
{
    generar_pseudo_ensamblador("Exit", "", "", "");
    return;
}

void generar_pseudo_ensamblador(char *codigoPseudo, char *primerParametro, char *segundoParametro, char *tercerParametro)
{
    if (tercerParametro[0] == '\0')
        printf("%s %s,%s\n", codigoPseudo, primerParametro, segundoParametro);
    else
        printf("%s %s,%s,%s\n", codigoPseudo, primerParametro, segundoParametro, tercerParametro);
    return;
}

int entero(char *identificador)
{
    if (!contiene_identificador(identificador))
    {
        agregar_identificador(identificador);
        generar_pseudo_ensamblador("Reserve", identificador, "4", "");
        return 0;
    }
    notificar_error_semantico(identificador, "ya");
    return 1;
}

int procesar_identificador(char *identificador)
{
    if (!contiene_identificador(identificador))
    {
        notificar_error_semantico(identificador, "no");
        return 1;
    }
    return 0;
}

void notificar_error_semantico(char *identificador, char *estado)
{
    yysemerrs++;
    sprintf(buffer, "Error semántico: identificador %s %s declarado", identificador, estado);
    yyerror(buffer);
    return;
}

char *nuevo_temporal()
{
    sprintf(buffer, "Temp@%d", ++cantidadTemporales);
    char *temporal = strdup(buffer);
    entero(temporal);
    return temporal;
}

char *generar_infijo(char *operandoIzquierda, int operador, char *operandoDerecha)
{
    char *temporal = nuevo_temporal();
    switch (operador)
    {
    case '+':
        generar_pseudo_ensamblador("ADD", operandoIzquierda, operandoDerecha, buffer);
        break;
    case '-':
        generar_pseudo_ensamblador("SUB", operandoIzquierda, operandoDerecha, buffer);
        break;
    case '*':
        generar_pseudo_ensamblador("MUL", operandoIzquierda, operandoDerecha, buffer);
        break;
    case '/':
        generar_pseudo_ensamblador("DIV", operandoIzquierda, operandoDerecha, buffer);
        break;
    case '%':
        generar_pseudo_ensamblador("MOD", operandoIzquierda, operandoDerecha, buffer);
        break;
    }
    return temporal;
}

char *generar_unario(char *operando)
{
    char *temporal = nuevo_temporal();
    generar_pseudo_ensamblador("INV", operando, "", buffer);
    return temporal;
}
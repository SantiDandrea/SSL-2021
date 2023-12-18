/* Grupo 10:
 * Integrantes:
 * - Santiago D'Andrea
 * - Tomás D'Andrea
 * - Marcos Federico Marano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main()
{

    int token;

    do
    {
        char salida[50];
        token = yylex();
        switch (token)
        {
        case LEER:
            strcpy(salida, "Token: Leer");
            break;
        case ENTERO:
            strcpy(salida, "Token: Entero");
            break;
        case ESCRIBIR:
            strcpy(salida, "Token: Escribir");
            break;
        case PROGRAMA:
            strcpy(salida, "Token: Programa");
            break;
        case FINPROGRAMA:
            strcpy(salida, "Token: Fin-Programa");
            break;
        case IDENTIFICADOR:
            strcpy(salida, "Token: Identificador\tlexema: ");
            strcat(salida, yytext);
            break;
        case CONSTANTE:
            strcpy(salida, "Token: Constante\tlexema: ");
            strcat(salida, yytext);
            break;
        case ASIGNACION:
            strcpy(salida, "Token: Asignación");
            break;
        case '+':
            strcpy(salida, "Token: \'+\'");
            break;
        case '-':
            strcpy(salida, "Token: \'-\'");
            break;
        case '*':
            strcpy(salida, "Token: \'*\'");
            break;
        case '/':
            strcpy(salida, "Token: \'/\'");
            break;
        case '%':
            strcpy(salida, "Token: \'%\'");
            break;
        case '(':
            strcpy(salida, "Token: \'(\'");
            break;
        case ')':
            strcpy(salida, "Token: \')\'");
            break;
        case ',':
            strcpy(salida, "Token: \',\'");
            break;
        case ';':
            strcpy(salida, "Token: \';\'");
            break;
        case FDT:
            strcpy(salida, "Token: Fin de Archivo");
            break;
        }

        puts(salida);

    } while (token != FDT);

    return EXIT_SUCCESS;
}

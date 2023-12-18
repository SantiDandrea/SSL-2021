/*

Grupo 10:

Integrantes:
 - Santiago D'Andrea
 - Tomás D'Andrea
 - Marcos Federico Marano

*/

#include "parser.h"

extern int yynerrs;
int yylexerrs = 0;
int yysemerrs = 0;

int main()
{
    switch (yyparse())
    {
    case 0:
        printf("Compilación terminada con éxito\n");
        break;
    case 1:
        printf("Errores de compilación\n");
        break;
    case 2:
        printf("Memoria insuficiente\n");
        break;
    }
    printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semánticos: %d\n", yynerrs, yylexerrs, yysemerrs);
    return EXIT_SUCCESS;
}

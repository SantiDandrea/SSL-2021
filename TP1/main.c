#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int main()
{
    enum tipoToken tok;
    
    do
    {
        tok = get_token();
        switch (tok)
        {
        case CAD:
            printf("Cadena: %s \n", buffer);
            buffer[0] = '\0';
            break;
        case SEP:
            printf("Separador: %c \n", buffer[0]);
            break;
        default:
            printf("Fin de Texto \n");
            break;
        }
    } while (!feof(stdin));

return EXIT_SUCCESS;
}


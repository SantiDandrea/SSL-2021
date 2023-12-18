#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int get_token()
{
   char caracter;

   while (isspace(caracter = getchar()));

   if (caracter == EOF) 
   
       return FDT;

   else if (caracter == ',')
   {
       buffer[0] = caracter;
       buffer[1] = '\0';
       return SEP;
   }
   else 
   {
       int i = 0;
       do
       {
           buffer[i] = caracter;
           caracter = getchar();
           i++;
       } while (!isspace(caracter) && caracter != ',');
       
       ungetc(caracter, stdin);
       buffer[i] = '\0';
       return CAD;
   }
}


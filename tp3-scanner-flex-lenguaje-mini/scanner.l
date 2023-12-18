%top{
#include "tokens.h"
}
%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput

Digito              [[:digit:]]
Letra               [[:alpha:]]
Espacio             [[:space:]]
Otros               [[:^alnum:]]{-}[[:space:]]{-}[-+*/();,<%]
Identificador       {Letra}({Letra}|{Digito})*
ConstanteEntera     {Digito}+

%%
leer                                                            return LEER;
entero                                                          return ENTERO;
escribir                                                        return ESCRIBIR;
programa                                                        return PROGRAMA;
fin-programa                                                    return FINPROGRAMA;
{Identificador}                                                 return IDENTIFICADOR;
{ConstanteEntera}                                               return CONSTANTE;
"<<"                                                            return ASIGNACION;
"+"                                                             return '+';
"-"                                                             return '-';
"*"                                                             return '*';
"/"                                                             return '/';
"%"                                                             return '%';
"("                                                             return '(';
")"                                                             return ')';
","                                                             return ',';
";"                                                             return ';';
{Identificador}{Otros}({Letra}|{Digito}|{Otros})*               printf("Error léxico: identificador inválido: %s\n", yytext);
{ConstanteEntera}({Letra}|{Digito})*                            printf("Error léxico: constante inválida: %s\n", yytext);
{Espacio}+                                                      ;
"//".*                                                          ;
{Otros}+                                                        |
.                                                               printf("Error léxico: cadena desconocida: %s\n", yytext);

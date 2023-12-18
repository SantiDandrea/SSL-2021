%{
#include "parser.h"
char message[120];
%}
%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput
%option yylineno

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
{Identificador}                                                 {yylval = strdup(yytext); return IDENTIFICADOR;}
{ConstanteEntera}                                               {yylval = strdup(yytext); return CONSTANTE;}
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
{Identificador}{Otros}({Letra}|{Digito}|{Otros})*               {yylexerrs++; sprintf(message, "Error léxico: identificador inválido: %s", yytext); yyerror(message);}
{ConstanteEntera}({Letra}|{Digito})*                            {yylexerrs++; sprintf(message, "Error léxico: constante inválida: %s", yytext); yyerror(message);}
{Espacio}+                                                      ;
"//".*                                                          ;
{Otros}+                                                        |
.                                                               {yylexerrs++; sprintf(message, "Error léxico: cadena desconocida: %s", yytext); yyerror(message);}

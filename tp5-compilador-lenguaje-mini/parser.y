%code top {
#include "scanner.h"
#include "symbol.h"
#include "semantic.h"
}

%code provides {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(const char *);
extern int yylexerrs;
extern int yysemerrs;
}

%defines "parser.h"
%output "parser.c"
%define api.value.type {char *}
%define parse.error verbose
%start programa-inicio

%token LEER ENTERO ESCRIBIR PROGRAMA FINPROGRAMA IDENTIFICADOR CONSTANTE
%token ASIGNACION "<<"
%left '+' '-'
%left '*' '/' '%'
%precedence NEG

%%

programa-inicio         : PROGRAMA IDENTIFICADOR { empezar($2); } lista-sentencias FINPROGRAMA { finalizar(); if (yynerrs || yylexerrs || yysemerrs) YYABORT; else YYACCEPT; }
                        ;
lista-sentencias        : sentencia lista-sentencias
                        | sentencia
                        ;
sentencia               : identificador "<<" expresion ';' { asignar($1, $3); }
                        | ENTERO IDENTIFICADOR ';' { if(entero($2)) YYERROR; }
                        | LEER '(' lista-identificadores ')' ';'
                        | ESCRIBIR '(' lista-expresiones ')' ';'
                        | error ';'
                        ;
lista-expresiones       : lista-expresiones ',' expresion { escribir($3); }
                        | expresion { escribir($1); }
                        ;
lista-identificadores   : lista-identificadores ',' identificador { leer($3); }
                        | identificador { leer($1); }
                        ;
expresion               : expresion '+' expresion { $$ = generar_infijo($1, '+', $3); }
                        | expresion '-' expresion { $$ = generar_infijo($1, '-', $3); }
                        | expresion '*' expresion { $$ = generar_infijo($1, '*', $3); }
                        | expresion '/' expresion { $$ = generar_infijo($1, '/', $3); }
                        | expresion '%' expresion { $$ = generar_infijo($1, '%', $3); }
                        | '-' expresion %prec NEG { $$ = generar_unario($2); }
                        | '(' expresion ')' { $$ = $2; }
                        | identificador
                        | CONSTANTE
                        ;
identificador           : IDENTIFICADOR { if(procesar_identificador($1)) YYERROR; }
                        ;

%%

void yyerror(const char *s) {
    printf("Línea #%d: %s\n", yylineno, s);
    return;
}
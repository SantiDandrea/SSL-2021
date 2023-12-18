%code top {
#include <stdio.h>
#include "scanner.h"
}
%code provides {
void yyerror(const char *);
extern int yylexerrs;
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

programa-inicio         : PROGRAMA IDENTIFICADOR { printf("programa %s\n", yylval); } lista-sentencias FINPROGRAMA { if (yynerrs || yylexerrs) YYABORT; else YYACCEPT; }
                        ;
lista-sentencias        : sentencia lista-sentencias
                        | sentencia
                        ;
sentencia               : IDENTIFICADOR "<<" expresion ';' {printf("asignación\n");}
                        | ENTERO IDENTIFICADOR ';' {printf("entero %s\n", yylval);}
                        | LEER '(' lista-identificadores ')' ';' {printf("leer\n");}
                        | ESCRIBIR '(' lista-expresiones ')' ';' {printf("escribir\n");}
                        | error ';'
                        ;
lista-expresiones       : lista-expresiones ',' expresion
                        | expresion
                        ;
lista-identificadores   : lista-identificadores ',' IDENTIFICADOR
                        | IDENTIFICADOR
                        ;
expresion               : expresion '+' expresion {printf("suma\n");}
                        | expresion '-' expresion {printf("resta\n");}
                        | expresion '*' expresion {printf("multiplicación\n");}
                        | expresion '/' expresion {printf("división\n");}
                        | expresion '%' expresion {printf("módulo\n");}
                        | '-' expresion %prec NEG {printf("inversión\n");}
                        | '(' expresion ')' {printf("paréntesis\n");}
                        | IDENTIFICADOR
                        | CONSTANTE
                        ;

%%

void yyerror(const char *s) {
    printf("Línea #%d: %s\n", yylineno, s);
    return;
}
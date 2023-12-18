#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

#include "parser.h"
#include "symbol.h"

void empezar(char *);
void asignar(char *, char *);
void leer(char *);
void escribir(char *);
void finalizar();
void generar_pseudo_ensamblador(char *, char *, char *, char *);
int entero(char *);
int procesar_identificador(char *);
void notificar_error_semantico(char *, char *);
char *nuevo_temporal();
char *generar_infijo(char *, int, char *);
char *generar_unario(char *);

#endif // SEMANTIC_H_INCLUDED
#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

enum tipoToken {FDT, CAD, SEP};

char buffer[100];

int get_token();

#endif // SCANNER_H_INCLUDED


#include "element.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } Boolean;

#define RESULT int
#define RESULT_FINE 0
#define RESULT_STAMPA -1
#define RESULT_OK 1

RESULT leggi(Booking* dest);
int leggiPrenotazioni(Booking elenco[], int lengthElenco);
int assegna(Booking elenco[], int dim, int* lengthElenco, char* nome, int pref);
void stampaElenco(Booking elenco[], int dim);
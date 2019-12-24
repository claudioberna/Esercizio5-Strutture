#include "gestione.h"
#define DIM_ELENCO 8

int main(void) {
	Booking elenco[DIM_ELENCO];
	int logicDim = leggiPrenotazioni(elenco, DIM_ELENCO);
	return 0;
}
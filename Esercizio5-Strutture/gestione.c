#include "gestione.h"

RESULT leggi(Booking* dest)
{
	RESULT result = RESULT_FINE;
	printf("Inserisci nome prenotazione: ");
	scanf_s("%s", dest->nome, LENGTH_NOME_STRING);
	if (strcmp(dest->nome, "fine") == 0) {
		result = RESULT_FINE;
	}
	else if (strcmp(dest->nome, "stampa") == 0) {
		result = RESULT_STAMPA;
	}
	else {
		int temp = 0;
		do {
			printf("Inserisci posto desiderato: ");
			scanf_s("%d", &temp);
			if (temp > 0) {
				dest->posto = temp;
				result = RESULT_OK;
			}
			else {
				printf("Inserisci posto maggiore di 0.\n");
			}
		} while (temp <= 0);
	}
	return result;
}

int leggiPrenotazioni(Booking elenco[], int lengthElenco)
{
	int count = 0;
	if (lengthElenco > 0) {
		RESULT res;
		Boolean libero;
		do {
			Booking temp;
			res = leggi(&temp);
			if (res == RESULT_OK && count < lengthElenco) {
				libero = assegna(elenco, lengthElenco, &count, temp.nome, temp.posto);
				if (!libero) {
					printf("Posto gia oocupato.\n");
				}
			}
			else if (res == RESULT_STAMPA) {
				stampaElenco(elenco, count);
			}
		} while (res != RESULT_FINE && count < lengthElenco);
	}
	else {
		printf("Errore dimensione vettore.\n");
		exit(1);
	}
	return count;
}

int assegna(Booking elenco[], int dim, int* lengthElenco, char* nome, int pref)
{
	Boolean libero = true;
	if (*lengthElenco == 0) {
		libero = true;
	}
	else if (*lengthElenco == 1) {
		if (elenco[0].posto == pref) {
			libero = false;
		}
		else {
			libero = true;
		}
	}
	else {
		for (int count = 0; (count < *lengthElenco) && libero; count++) {
			if (elenco[count].posto == pref) {
				libero = false;
			}
		}
	}
	if (libero) {
		strcpy_s(elenco[*lengthElenco].nome, LENGTH_NOME_STRING, nome);
		elenco[*lengthElenco].posto = pref;
		(*lengthElenco)++;
	}
	return libero;
}

void stampaElenco(Booking elenco[], int dim) {
	if (dim > 0) {
		printf("------------------ ELENCO Prenotazioni :---------------------- \n");
		for (int count = 0; count < dim; count++) {
			printf("---------------------------------------- \n");
			printf("Nome prenotazione: %s \n", elenco[count].nome);
			printf("Posto prenotazione: %d \n", elenco[count].posto);
			printf("---------------------------------------- \n");
		}
	}
	else {
		printf("Nessun elemento da stampare.\n");
	}
}

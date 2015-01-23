/*
	Leggo in input 10 numeri, poi li stampo non ripetendo quelli
	inseriti più volte,
*/

#include <iostream>

using namespace std;

// Costanti
const int LUNGHEZZA_ARRAY = 10;
const int MASSIMO_NUMERO_INSERIBILE = 100;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Scrivi l'elemento ";
char TITOLO_OUTPUT[] = "Elemento ";
char DUE_PUNTI[] = " : ";

// Funzione per creare un array riempito con numeri inseriti dall'utente.
int * creaArray() {
	static int array[LUNGHEZZA_ARRAY];

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		cout << SUGGERIMENTO_INPUT << i << DUE_PUNTI;
		cin >> array[i];
	}

	return array;
}

// Funzione per stampare un array non ripetendo gli elementi duplicati.
void outputSenzaDuplicati(int * array) {
	// Creo l'array delle frequenze, inizializzando tutti i valori a 0
	int frequenze[MASSIMO_NUMERO_INSERIBILE] = {0};

	// Leggo l'array
	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		// Creo per praticità una variabile per il numero corrente
		int numero = array[i];

		// Se il numero non è ancora comparso, allora lo stampo e increm.
		// la sua frequenza.
		if (frequenze[numero] == 0) {
			cout << TITOLO_OUTPUT << i << DUE_PUNTI << numero << endl;
			frequenze[numero]++;
		}
	}
}

int main() {
	outputSenzaDuplicati(creaArray());
}

/*
	Ordino in modo crescente un array di numeri interi.
*/

#include <iostream>

using namespace std;

// Costanti
const int LUNGHEZZA_ARRAY = 5;
const int MASSIMO_NUMERO_INSERIBILE = 100;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Scrivi l'elemento ";
char TITOLO_OUTPUT[] = "Elemento ";
char DUE_PUNTI[] = " : ";

// Funzione per creare un array riempito con numeri inseriti dall'utente.
int * creaArray() {
	static int array[10];

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		cout << SUGGERIMENTO_INPUT << i << DUE_PUNTI;
		cin >> array[i];
	}

	return array;
}

// Funzione per ordinare un array
int * ordinaArray(int * array) {
	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		for (int j = 0; j < LUNGHEZZA_ARRAY; ++j) {
			if (array[i] < array[j]) {
				int temporaneo = array[i];
				array[i] = array[j];
				array[j] = temporaneo;
			}
		}
	}

	return array;
}

// Funzione per stampare un array.
void leggiArray(int * array) {
	// Leggo l'array
	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		cout << TITOLO_OUTPUT << i << DUE_PUNTI << array[i] << endl;
	}
}

int main() {
	leggiArray(ordinaArray(creaArray()));
}

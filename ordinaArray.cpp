/*
	Ordino in modo crescente un array di numeri interi.
*/

#include <iostream>

using namespace std;

// Costanti
const int LUNGHEZZA_ARRAY = 5;
const int INTERO_MASSIMO = numeric_limits<int>::max();

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

// Funzione per ordinare un array determinando il suo numero minimo più volte.
int * ordinaArray(int * array) {
	static int arrayOrdinato[LUNGHEZZA_ARRAY];

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		// Inizializzo le variabili per individuare il numero minimo.
		int minimoCorrente = INTERO_MASSIMO;
		int indiceMinimoCorrente;

		// Individuo il numero minimo nell'array.
		for (int j = 0; j < LUNGHEZZA_ARRAY; ++j) {
			if (array[j] < minimoCorrente) {
				minimoCorrente = array[j];
				indiceMinimoCorrente = j;
			}
		}

		// Inserisco il minimo ottenuto nel nuovo array e alla sua posizione
		// nel vecchio inserisco un numero molto grande per 'eliminarlo' dal
		// calcolo successivo del minimo.
		arrayOrdinato[i] = minimoCorrente;
		array[indiceMinimoCorrente] = INTERO_MASSIMO;
	}

	return arrayOrdinato;
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

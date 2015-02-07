/*
	Inverto l'ordine degli elementi di un array.
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

// Funzione per invertire un array
int * invertiArray(int * array) {
	for (int i = 0; i < LUNGHEZZA_ARRAY / 2; ++i) {
		// Trovo l'indice dell'elemento opposto a quello corrente
		int j = LUNGHEZZA_ARRAY-i-1;

		// Inverto gli elementi dell'array
		int temporaneo = array[i];
		array[i] = array[j];
		array[j] = temporaneo;
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
	leggiArray(invertiArray(creaArray()));
}

/*
	Determino unione e intersezione di due array trattati come insiemi matematici.
*/

#include <iostream>
#include <ctime>

using namespace std;

const int LUNGHEZZA_ARRAY = 5;
const int LUNGHEZZA_ARRAY_MASSIMA = LUNGHEZZA_ARRAY * 2;

char TITOLO_OUTPUT[] = "Elemento ";
char DUE_PUNTI[] = " : ";
char TITOLO_UNIONE[] = "Array unione: ";
char TITOLO_INTERSEZIONE[] = "Array intersezione: ";

int contUnione, contIntersezione;

bool elementoPresente(int * array, int elemento, int lunghezza) {
	bool elementoPresente = false;

	for (int i = 0; i < lunghezza; ++i) {
		if (array[i] == elemento) {
			elementoPresente = true;
		}
	}

	return elementoPresente;
}

int * unioneArray(int * primoArray, int * secondoArray) {
	static int arrayUnione[LUNGHEZZA_ARRAY_MASSIMA];

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		int numeroDaInserire = primoArray[i];

		if (!elementoPresente(arrayUnione, numeroDaInserire, contUnione)) {
			arrayUnione[contUnione] = numeroDaInserire;
			contUnione++;
		}
	}

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		int numeroDaInserire = secondoArray[i];

		if (!elementoPresente(arrayUnione, numeroDaInserire, contUnione)) {
			arrayUnione[contUnione] = numeroDaInserire;
			contUnione++;
		}
	}

	return arrayUnione;
}

int * intersezioneArray(int * primoArray, int * secondoArray) {
	static int arrayIntersezione[LUNGHEZZA_ARRAY];

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		int numeroDaInserire = primoArray[i];

		if (elementoPresente(secondoArray, numeroDaInserire, LUNGHEZZA_ARRAY) && 
			!elementoPresente(arrayIntersezione, numeroDaInserire, contIntersezione)) {
			arrayIntersezione[contIntersezione] = numeroDaInserire;
			contIntersezione++;
		}
	}

	return arrayIntersezione;
}

void leggiArray(int * array, int lunghezza, char titolo[]) {
	cout << titolo << endl;

	for (int i = 0; i < lunghezza; ++i) {
		cout << TITOLO_OUTPUT << i << DUE_PUNTI << array[i] << endl;
	}

	cout << endl;
}

int main() {
	int mPrimoArray[LUNGHEZZA_ARRAY] = {1, 3, 3, 7, 2};
	int mSecondoArray[LUNGHEZZA_ARRAY] = {2, 13, 3, 21, 5};

	leggiArray(unioneArray(mPrimoArray, mSecondoArray), contUnione, TITOLO_UNIONE);
	leggiArray(intersezioneArray(mPrimoArray, mSecondoArray), contIntersezione, TITOLO_INTERSEZIONE);
}
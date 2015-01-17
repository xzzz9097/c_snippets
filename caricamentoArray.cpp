/*
	Carico tre array in 3 modi diversi: nella dichiarazione, con l'input
	da parte dell'utente e con dei numeri casuali.
*/

#include <iostream>
#include <ctime>

using namespace std;

// Costanti
const int LUNGHEZZA_ARRAY = 5;
const int RICHIESTA_ARRAY_INPUT = 1;
const int RICHIESTA_ARRAY_CASUALI = 2;
const int CASUALE_MASSIMO = 10;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Inserisci l'elemento ";
char TITOLO_ARRAY_PRECARICATO[] = "Array precaricato: ";
char TITOLO_ARRAY_INPUT[] = "Array caricato dall'utente: ";
char TITOLO_ARRAY_CASUALI[] = "Array casuali: ";
char TITOLO_ELEMENTO[] = "Elemento ";
char DUE_PUNTI[] = " : ";

void caricaNumeriCasuali() {
	srand(time(NULL));
}

int * creaArray(int richiesta) {
	// Definisco un array
	static int array[LUNGHEZZA_ARRAY];

	// Uso il costrutto 'switch' per distinguere il caso
	// del caricamento con input o con i casuali.
	switch(richiesta) {
		case RICHIESTA_ARRAY_INPUT:
		for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
			cout << SUGGERIMENTO_INPUT << i << DUE_PUNTI;
			cin >> array[i];
		}
		break;
		case RICHIESTA_ARRAY_CASUALI:
		for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
			array[i] = rand() % CASUALE_MASSIMO;
		}
		break;
	}

	// Ritorno l'array costruito
	return array;
}

void leggiArray(int * array, char * titolo) {
	// Stampo il titolo dell'array
	cout << endl << titolo << endl;

	// Stampo gli elementi dell'array
	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		cout << TITOLO_ELEMENTO << i << DUE_PUNTI << array[i] << endl;
	}
}

int main() {
	// Dichiarazione variabili
	int mArrayPrecaricato[LUNGHEZZA_ARRAY] = {1, 2, 3, 4, 5};

	// Preparo la funzione dei numeri casuali
	caricaNumeriCasuali();

	// Creo e stampo gli array
	leggiArray(creaArray(RICHIESTA_ARRAY_INPUT), TITOLO_ARRAY_INPUT);
	leggiArray(mArrayPrecaricato, TITOLO_ARRAY_PRECARICATO);
	leggiArray(creaArray(RICHIESTA_ARRAY_CASUALI), TITOLO_ARRAY_CASUALI);

	return 0;
}	
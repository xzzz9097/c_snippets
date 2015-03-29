/*
	Ordinamento array.
*/

#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int LUNGHEZZA_ARRAY = 1000;
const int NUMERO_MASSIMO = 100;
const int INIZIO_ARRAY = 0;
const int FINE_ARRAY = LUNGHEZZA_ARRAY - 1;

const int ORDINAMENTO_RAPIDO = 0;
const int ORDINAMENTO_BOLLA = 1;
const int ORDINAMENTO_INSERIMENTO = 2;
const int ORDINAMENTI = 3;

char SPAZIO[] = " ";
char TITOLO_ARRAY_PARTENZA[] = "Array di partenza: ";
char TITOLO_ARRAY_ORDINATO[] = "Array ordinato: ";
string TEMPI_ORDINAMENTI[ORDINAMENTI] = {
	"Tempo ordinamento rapido: ",
	"Tempo ordinamento bolla: ",
	"Tempo ordinamento inserimento: "
};

int * creaArrayCasuali() {
	srand(time(NULL));

	static int array[LUNGHEZZA_ARRAY];

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		array[i] = rand() % NUMERO_MASSIMO;
	}

	return array;
}

void copiaArray(int arrayDaCopiare[], int arrayCopiato[]) {
	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		arrayCopiato[i] = arrayDaCopiare[i];
	}
}

void scambiaElementi(int array[], int primaPosizione, int secondaPosizione) {
	int temp = array[primaPosizione];
	array[primaPosizione] = array[secondaPosizione];
	array[secondaPosizione] = temp;
}

void leggiArray(int array[], char titolo[]) {
	cout << titolo;

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		cout << SPAZIO << array[i];
	}

	cout << endl;
}

void ordinamentoRapido(int array[], int inizioPartizione, int finePartizione) {
	int centro = array[(inizioPartizione + finePartizione) / 2];
	int indiceSinistra = inizioPartizione;
	int indiceDestra = finePartizione;

	while (indiceSinistra <= indiceDestra) {
	    while (array[indiceSinistra] < centro) indiceSinistra++;

	    while (array[indiceDestra] > centro) indiceDestra--;

	    if (indiceSinistra < indiceDestra) {
	    	scambiaElementi(array, indiceSinistra, indiceDestra);
	    }

	    if (indiceSinistra <= indiceDestra) {
	    	indiceSinistra++;
			indiceDestra--;
	    }
	}

	if (inizioPartizione < indiceDestra) {
		ordinamentoRapido(array, inizioPartizione, indiceDestra);
	}

	if (indiceSinistra < finePartizione) {
		ordinamentoRapido(array, indiceSinistra, finePartizione);
	}
}

void ordinamentoBolla(int array[]) {
	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
        for (int j = 0; j < i; ++j) {
			if (array[j] > array[i]) {
				scambiaElementi(array, i, j);
			}
		}
	}
}

void ordinamentoInserimento(int array[]) {
	for (int i = 1; i < LUNGHEZZA_ARRAY; ++i) {
		int j = i - 1;
		int valore = array[i];

		while (j >= 0 && array[j] > valore) {
		    array[j + 1] = array[j];
		    j--;
		}

		array[j + 1] = valore;
	}
}

void ordinaCatturandoTempo(int array[], int inizioPartizione, int finePartizione) {
	int arrayDaOrdinare[LUNGHEZZA_ARRAY];

	for (int i = 0; i < ORDINAMENTI; ++i) {
		copiaArray(array, arrayDaOrdinare);

		// Registro il tempo prima di lanciare la funzione
		auto tempoIniziale = high_resolution_clock::now();
    
    	// Eseguo la funzione
		switch (i) {
			case ORDINAMENTO_RAPIDO:
			ordinamentoRapido(arrayDaOrdinare, INIZIO_ARRAY, FINE_ARRAY);
			break;
			case ORDINAMENTO_BOLLA:
			ordinamentoBolla(arrayDaOrdinare);
			break;
			case ORDINAMENTO_INSERIMENTO:
			ordinamentoInserimento(arrayDaOrdinare);
			break;
		}

		// Registro il tempo una volta completata la funzione
    	auto tempoFinale = high_resolution_clock::now();

    	// Calcolo il tempo trascorso
		auto mioTempo = duration_cast<nanoseconds>(tempoFinale.time_since_epoch()).count() - 
						duration_cast<nanoseconds>(tempoIniziale.time_since_epoch()).count();

		// Stampo il tempo trascorso
    	cout << TEMPI_ORDINAMENTI[i] << mioTempo << endl;
	}

	leggiArray(arrayDaOrdinare, TITOLO_ARRAY_ORDINATO);
}

int main() {
	ordinaCatturandoTempo(creaArrayCasuali(), INIZIO_ARRAY, FINE_ARRAY);
}
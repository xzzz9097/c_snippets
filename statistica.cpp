/*
  Calcolo la media degli elementi di un array.
*/

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

// Costanti
const int LUNGHEZZA_ARRAY = 10;
const int NUMERO_MASSIMO = 10;

// Stringhe
char OUTPUT_MEDIA[] = "La media e' ";
char OUTPUT_MEDIA_QUADRATICA[] = "La media quadratica e' ";
char OUTPUT_SCARTO_QUADRATICO[] = "Lo scarto quadratico e' ";
char OUTPUT_MEDIANA[] = "La mediana e' ";
char OUTPUT_MODA[] = "La moda e' ";
char SPAZIO[] = " ";

// Riempio l'array con numeri casuali.
void riempiArray(int array[]) {
    srand(time(NULL));

    for (int i = 0; i < LUNGHEZZA_ARRAY; i++) {
        array[i] = rand() % NUMERO_MASSIMO;
    }
}

// Posiziono gli elementi dell'array in ordine crescente.
int * ordinaArray(int array[]) {
	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
        for (int j = 0; j < LUNGHEZZA_ARRAY; ++j) {
			if (array[j] > array[i]) {
				int temporaneo = array[i];
                array[i] = array[j];
				array[j] = temporaneo;
			}
		}
	}

    return array;
}

// Calcolo la media algebrica.
float calcolaMedia(int array[]) {
    float somma = 0;

    for (int i = 0; i < LUNGHEZZA_ARRAY; i++) {
        somma += array[i];
    }

    return somma / LUNGHEZZA_ARRAY;
}

// Calcolo la media quadratica.
float calcolaMediaQuadratica(int array[]) {
    float sommaQuadrati = 0;

    for (int i = 0; i < LUNGHEZZA_ARRAY; i++) {
        sommaQuadrati += array[i] * array[i];
    }

    return sqrt(sommaQuadrati / LUNGHEZZA_ARRAY);
}

// Calcolo lo scarto quadratico medio.
float calcolaScartoQuadratico(int array[]) {
    float media = calcolaMedia(array);
    float sommaScarti = 0;

    for (int i = 0; i < LUNGHEZZA_ARRAY; i++) {
        sommaScarti += (array[i] - media) * (array[i] - media);
    }

    return sqrt(sommaScarti / LUNGHEZZA_ARRAY);
}

// Trovo la mediana come media dei due elementi centrali se l'array ha
// lunghezza pari, nell'elemento centrale se la lunghezza è dispari.
float calcolaMediana(int array[]) {
    return (LUNGHEZZA_ARRAY % 2 == 0) ? 
        ((float) array[LUNGHEZZA_ARRAY / 2] + (float) array[LUNGHEZZA_ARRAY / 2 - 1]) / 2 : 
        (array[LUNGHEZZA_ARRAY / 2]);
}

// Determino la moda con un array per le frequenze dei valori.
int calcolaModa(int array[]) {
    int arrayFrequenze[NUMERO_MASSIMO] = {0};
    int moda = -1;

    for (int i = 0; i < LUNGHEZZA_ARRAY; i++) {
        arrayFrequenze[array[i]]++;
    }

    for (int i = 0; i < NUMERO_MASSIMO; i++) {
        moda = arrayFrequenze[i] > arrayFrequenze[moda] ? i : moda;
    }

    return moda;
}

void leggiArray(int array[]) {
     for (int i = 0; i < LUNGHEZZA_ARRAY; i++) {
         cout << SPAZIO << array[i];
     }

     cout << endl;
}

void leggiValore(float valore, char titolo[]) {
     cout << titolo << valore << endl;
}

int main() {
    int mArray[LUNGHEZZA_ARRAY];
    riempiArray(mArray);

    // Leggo l'array e i dati statistici
    leggiArray(mArray);
    leggiValore(calcolaMedia(mArray), OUTPUT_MEDIA);
    leggiValore(calcolaMediaQuadratica(mArray), OUTPUT_MEDIA_QUADRATICA);
    leggiValore(calcolaScartoQuadratico(mArray), OUTPUT_SCARTO_QUADRATICO);
    leggiValore(calcolaModa(mArray), OUTPUT_MODA);
    leggiArray(ordinaArray(mArray));
    leggiValore(calcolaMediana(ordinaArray(mArray)), OUTPUT_MEDIANA);
}

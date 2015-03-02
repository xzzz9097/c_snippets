/*
	Converto due numeri dalla forma decimale a quella binaria mediante
	due array di cifre intere e li sommo.
*/

#include <iostream>

using namespace std;

const int LUNGHEZZA_ARRAY = 10;

char SPAZIO[] = " ";
char SUGGERIMENTO_INPUT[] = "Inserisci due numeri: ";
char OUTPUT_PRIMO_NUMERO[] = "Primo numero: ";
char OUTPUT_SECONDO_NUMERO[] = "Secondo numero: ";
char OUTPUT_SOMMA[] = "Somma: ";

int primoNumeroDecimale = 0;
int secondoNumeroDecimale = 0;

void richiediNumeri() {
	cout << SUGGERIMENTO_INPUT << endl;

	cin >> primoNumeroDecimale;
	cin >> secondoNumeroDecimale;
}

void convertiDecimale(int array[], int numero) {
	int i = 0;
	while (numero > 0) {
		array[LUNGHEZZA_ARRAY - i - 1] = numero % 2;
		numero /= 2;
		i++;
	}
}

void leggiCifreBinario(int array[], char titolo[]) {
	cout << titolo;

	bool numeroIniziato = false;

	for (int i = 0; i < LUNGHEZZA_ARRAY; ++i) {
		if (!numeroIniziato && array[i] != 0) {
			numeroIniziato = true;
		}

		if (numeroIniziato) {
			cout << array[i] << SPAZIO;
		}
	}

	cout << endl;
}

int * sommaBinari(int primoArray[], int secondoArray[]) {
	static int array[LUNGHEZZA_ARRAY] = {0};

	for (int i = LUNGHEZZA_ARRAY - 1; i >= 0; --i) {
		array[i] += primoArray[i] + secondoArray[i];

		if (array[i] > 1) {
			array[i - 1] += array[i] - 1;
			array[i] = (array[i] % 2);
		}
	}

	return array;
}

int main() {
	int primoNumero[LUNGHEZZA_ARRAY] = {0};
	int secondoNumero[LUNGHEZZA_ARRAY] = {0};

	richiediNumeri();

	convertiDecimale(primoNumero, primoNumeroDecimale);
	convertiDecimale(secondoNumero, secondoNumeroDecimale);

	leggiCifreBinario(primoNumero, OUTPUT_PRIMO_NUMERO);
	leggiCifreBinario(secondoNumero, OUTPUT_SECONDO_NUMERO);

	leggiCifreBinario(
		sommaBinari(primoNumero, secondoNumero),
		OUTPUT_SOMMA
	);
}	
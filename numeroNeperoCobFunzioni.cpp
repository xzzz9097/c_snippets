/*
	Approssimo il numero di Nepero con due funzioni.
*/

#include <iostream>

using namespace std;

// Stringhe
char SUGGERIMENTO_INPUT_TENTATIVI[] = "Con quanti tentativi vuoi effettuare? ";
char SUGGERIMENTO_INPUT_CIFRE[] = "Quante cifre decimali vuoi mostrare? ";

// Costanti
const double VALORE_INIZIALE = 1.0;

// Funzione per calcolare numeri fattoriali
double calcolaFattoriale(int numero) {
	double numeroFattoriale = VALORE_INIZIALE;

	if (numero > VALORE_INIZIALE) {
		numeroFattoriale = numero * calcolaFattoriale(numero - 1);
	}

	return numeroFattoriale;
}

// Funzione per approssimare il numero di Nepero in base al numero di tentativi
// usando un ciclo for e la funzione calcolaFattoriale.
double calcolaNumeroDiNepero(int numeroTentativi) {
	double numeroNepero = VALORE_INIZIALE;

	for (int i = 1; i <= numeroTentativi; i++) {
		numeroNepero += (1 / calcolaFattoriale(i));
	}

	return numeroNepero;
}

// Funzione per impostare il numero di cifre decimali in output agendo sul parametro
// 'cout.precision'.
void impostaCifreDecimali(int cifre) {
	cout.precision(cifre);
}

// Funzione per stampare il risultato approssimato al numero desiderato di tentativi.
void outputRisultato(int numeroTentativi) {
	cout << "e(" << numeroTentativi << ") = " << calcolaNumeroDiNepero(numeroTentativi);
	cout << endl;
}

int main() {
	// Dichiarazione variabili
	int mNumeroTentativi, mCifreDecimali;

	// Input numero di tentativi;
	cout << SUGGERIMENTO_INPUT_TENTATIVI;
	cin >> mNumeroTentativi;

	// Input cifre decimali desiderate
	cout << SUGGERIMENTO_INPUT_CIFRE;
	cin >> mCifreDecimali;

	// Imposto le cifre desiderate
	impostaCifreDecimali(mCifreDecimali);

	// Calcolo e output
	outputRisultato(mNumeroTentativi);

	return 0;
}
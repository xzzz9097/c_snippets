/*
	Calcolo l'età di una persona in base al suo anno di nascita
*/

#include <iostream>

using namespace std;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Inserisci l'anno di nascita: ";
char TITOLO_OUTPUT[] = "L'età è ";

// Costanti
const int ANNO_CORRENTE = 2014;

int calcolaEtà(int annoDiNascita) {
	return ANNO_CORRENTE - annoDiNascita;
}

int main() {
	int mAnnoDiNascita;

	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mAnnoDiNascita;

	cout << TITOLO_OUTPUT << calcolaEtà(mAnnoDiNascita) << endl;

	return 0;
}	
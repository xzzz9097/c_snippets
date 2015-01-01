/*
	Calcolo il prezzo scontato di un prodotto in base al prezzo di partenza e alla
	percentuale di sconto.
*/

#include <iostream>

using namespace std;

// Costanti
char SUGGERIMENTO_INPUT[] = "Inserisci il prezzo di vendita e la percentuale di sconto:";
char TITOLO_OUTPUT[] = "Il prezzo scontato e' ";

// Funzione per calcolare il prezzo scontato
float calcolaPrezzoScontato(float prezzoVendita, float percentualeSconto) {
	return prezzoVendita * (1 - percentualeSconto/100);
}

int main() {
	// Dichiarazione variabili
	float mPrezzoVendita, mPercentualeSconto;

	// Input dati
	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mPrezzoVendita >> mPercentualeSconto;

	// Calcolo e output
	cout << TITOLO_OUTPUT << calcolaPrezzoScontato(mPrezzoVendita, mPercentualeSconto) << endl;

	return 0;
}
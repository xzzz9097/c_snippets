/*
	Calcolo il numero di Nepero con una successione.
	Il risultato più preciso si ottiene dal diciottesimo tentativo; per aumentare le cifre
	significative vanno usate librerie esterne per trattare i numeri complessi a causa dei 
	limiti del tipo double.
*/
#include <iostream>
using namespace std;

// Funzione per calcolare numeri fattoriali
double calcolaFattoriale(int numero) {
	// Dichiarazione variabili
	double numeroFattoriale = numero;
	double numeroTemporaneo = numero;

	// Ciclo per calcolare il numero fattoriale
	while (numeroTemporaneo > 1) {
		numeroTemporaneo -= 1;
		numeroFattoriale *= numeroTemporaneo;
	}

	return numeroFattoriale;
}

// Programma
int main() {
	// Dichiarazione variabili
	double mNumeroNepero = 1.0;
	int mNumeroTentativi;

	// Input del numero di tentativi desiderato
    cout << "Quanti tentativi vuoi effettuare? ";
    cin >> mNumeroTentativi;

    // Imposto il numero di cifre decimali
    cout.precision(16);
    
    // Successione
	for (int i = 1; i <= mNumeroTentativi; i++) {
		// Output del tentativo corrente
		cout << "Tentativo " << i << ": " << mNumeroNepero << endl;
		// Aggiungo a(i)
		mNumeroNepero += (1 / calcolaFattoriale(i));
	}
	
	// Blocco prompt comandi
	system("pause");

	return 0;
}
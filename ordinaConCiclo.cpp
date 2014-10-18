/*
	ordinaConCiclo.cpp: scrive in ordine crescente due numeri con un ciclo for
*/

#include <iostream>
using namespace std;

int main() {
	// Definizione variabili
	int mA, mB;
	bool mSecondoMaggiore;
	
	// Ciclo
	for (int i = 0; i < 2; i++)
	{
		// Input
		cout << "Inserisci un numero: ";
		int mNumero;
		cin >> mNumero;

		// Determino il maggiore
		if (i == 1) {
			mB = mNumero;
			mSecondoMaggiore = mNumero > mA;
		} else {
			mA = mNumero;
		}
	}

	// Output
	if (mSecondoMaggiore) {
		cout << mA << ", " << mB << endl;
	} else {
		cout << mB << ", " << mA << endl;
	}

	// Risultato di uscita
	return 0;
}	
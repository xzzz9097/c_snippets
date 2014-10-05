/*
	Calcolo circonferenza e area di un cerchio dato il raggio.
*/

#include <iostream>
using namespace std;

// Definizione costanti
const float PI = 3.14;

int main()
{
	// Definizione variabili
	float mRaggio, mDoppioRaggio, mQuadratoRaggio;
	float mCirconferenza, mArea;

	// Input
	cout << "Inserisci la lunghezza del raggio: ";
	cin >> mRaggio;

	// Condizione raggio
	if(mRaggio > 0) {
		// Calcolo
		mDoppioRaggio = 2 * mRaggio;
		mCirconferenza = PI * mDoppioRaggio;
		mQuadratoRaggio = mRaggio * mRaggio;
		mArea = PI * mQuadratoRaggio;

		// Output
		cout << "Raggio = " << mRaggio << " -> ";
		cout << "Circonferenza = " << mDoppioRaggio << "π = " << mCirconferenza << " | ";
		cout << "Area = " << mQuadratoRaggio << "π = " << mArea << endl;
	} else {
		// Errore
		cout << "Nessuna circonferenza con raggio = " << mRaggio << endl;
	}

	// Risultato di uscita
	return 0;
}
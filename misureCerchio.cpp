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
	int mRaggio;
	float mCirconferenza, mArea;

	// Input
	cout << "Inserisci la lunghezza del raggio: ";
	cin >> mRaggio;

	// Calcolo
	mCirconferenza = 2 * PI * mRaggio;
	mArea = PI * PI * mRaggio;

	// Output
	cout << "Raggio = " << mRaggio << " -> " << " Circonferenza = " << mCirconferenza 
		 << " Area = " << mArea << endl;

	// Risultato di uscita
	return 0;
}
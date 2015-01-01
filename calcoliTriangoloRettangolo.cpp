/*
	Calcolo ipotenusa, perimetro e area di un triangolo rettangolo dati due cateti.
*/

#include <iostream>
#include <cmath>

using namespace std;

// Costanti
char SUGGERIMENTO_INPUT[] = "Inserisci le misure dei due cateti:";
char TITOLO_OUTPUT_IPOTENUSA[] = "Ipotenusa = ";
char TITOLO_OUTPUT_AREA[] = "Area = ";
char TITOLO_OUTPUT_PERIMETRO[] = "Perimetro = ";

// Funzione per calcolare l'ipotenusa
float calcolaIpotenusa(float a, float b) {
	return sqrt(pow(a, 2.0) + pow(b, 2.0));
}

// Funzione per calcolare l'area
float calcolaArea(float a, float b) {
	return (a * b) / 2;
}

// Funzione per calcolare il perimetro
float calcolaPerimetro(float a, float b) {
	return a + b + calcolaIpotenusa(a, b);
}

// Funzione per scrivere in output il risultato
void leggiRisultato(char titolo[], float risultato) {
	cout << titolo << risultato << endl;
}

int main() {
	// Dichiarazione variabili
	float mA, mB;

	// Input cateti
	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mA >> mB;

	// Calcolo e output
	leggiRisultato(TITOLO_OUTPUT_IPOTENUSA, calcolaIpotenusa(mA, mB));
	leggiRisultato(TITOLO_OUTPUT_AREA, calcolaArea(mA, mB));
	leggiRisultato(TITOLO_OUTPUT_PERIMETRO, calcolaPerimetro(mA, mB));

	return 0;
}	
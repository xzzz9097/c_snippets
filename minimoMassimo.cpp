/*
	Calcolo minimo e massimo tra due numeri con tre funzioni
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Scrivi due numeri: ";
char OUTPUT_MINIMO[] = "Il minimo e' ";
char OUTPUT_MASSIMO[] = "Il massimo e' ";
char OUTPUT_NUMERI_IN_ORDINE[] = "I numeri sono in ordine ";

// Funzione per determinare il minimo (con operatore ternario)
float determinaMinimo(float a, float b) {
	return b < a ? b : a;
}

// Funzione per determinare il massimo (con operatore ternario)
float determinaMassimo(float a, float b) {
	return b > a ? b : a;
}

// Creo una stringa con i numeri in ordine crescente
string determinaMinimoMassimo(float a, float b) {
	// Uso il tipo 'stringstream' che permette di creare una stringa con una sintassi
	// simile a quella della funzione 'cout'.
	stringstream flussoStringa;

	// Costruisco la stringa appendendo al flusso il minimo, una virgola e il massimo
	flussoStringa << determinaMinimo(a, b) << ", " << determinaMassimo(a, b);

	// Ritorno il flusso convertito a stringa con la funzione fornita dalla libreria sstream
	return flussoStringa.str();
}

int main() {
	// Dichiarazione variabili
	float mA, mB;

	// Input numeri
	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mA >> mB;

	// Output
	cout << OUTPUT_MINIMO << determinaMinimo(mA, mB) << endl;
	cout << OUTPUT_MASSIMO << determinaMassimo(mA, mB) << endl;
	cout << OUTPUT_NUMERI_IN_ORDINE << determinaMinimoMassimo(mA, mB) << endl;

	return 0;
}
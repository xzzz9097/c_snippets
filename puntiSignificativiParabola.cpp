/*
	Calcolo i punti significativi di una parabola y = ax^2 + bx + c
*/

#include <iostream>
#include <cmath>

using namespace std;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Inserisci i parametri a, b e c di una parabola y = ax^2 + bx + c: ";
char TITOLO_FUOCO[] = "Fuoco";
char TITOLO_VERTICE[] = "Vertice";
char TITOLO_INTERSEZIONI[] = "Intersezioni";
char NO_INTERSEZIONI[] = "La parabola non ha intersezioni con l'asse X.";

// Costanti
const int DIM_ARR_INTERSEZIONI = 4;
const int DIM_ARR_PUNTO = 2;

float calcolaDelta(float a, float b, float c) {
	return (pow(b, 2.0) - 4 * a * c);
}

bool possiedeIntersezioni(int delta) {
	return delta >= 0;
}

float togliSegnoSeZero(float numero) {
	// Per evitare di avere in output xF o Xv = -0
	return (numero == -0.0f) ? 0.0f : numero;
}

float * creaArrayIntersezioni(float a, float b, float delta) {
	// Uso l'attributo static per impedire l'alterazione dell'array al di fuori della funzione
	static float arraySoluzioni[DIM_ARR_INTERSEZIONI];

	// Assegno le celle dell'array
	arraySoluzioni[0] = (- b - sqrt(delta)) / (2 * a);
	arraySoluzioni[2] = (- b + sqrt(delta)) / (2 * a);
	/*
		arraySoluzioni[1] e arraySoluzioni[3] contengono le y delle intersezioni con l'asse x,
		che sono pari a 0 e non è quindi necessario assegnare manualmente (0 è il valore di default).
	*/	

	return arraySoluzioni;
}

float * creaArrayFuoco(float a, float b, float delta) {	
	static float arrayFuoco[DIM_ARR_PUNTO];

	arrayFuoco[0] = togliSegnoSeZero((- b) / (2 * a));
	arrayFuoco[1] = togliSegnoSeZero((1 - delta) / (4 * a));

	return arrayFuoco;
}

float * creaArrayVertice(float a, float b, float delta) {
	static float arrayVertice[DIM_ARR_PUNTO];

	arrayVertice[0] = togliSegnoSeZero((- b) / (2 * a));
	arrayVertice[1] = togliSegnoSeZero((- delta) / (4 * a));

	return arrayVertice;
}

void leggiCoordinate(float * puntatoreArray, float lunghezzaArray, char titoloOutput[]) {
	for (int i = 0; i < lunghezzaArray; i+=2) {
		// Il puntatore può essere letto come un array, ponendo l'indice fra parentesi quadre
		cout << titoloOutput << ": (" << puntatoreArray[i] << "; " << puntatoreArray[i+1] << ")" << endl;
	}
}

int main() {
	// Dichiarazione variabili
	float mA, mB, mC;

	// Input
	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mA >> mB >> mC;

	// Calcolo delta
	float mDelta = calcolaDelta(mA, mB, mC);

	// Output fuoco e vertice
	leggiCoordinate(creaArrayFuoco(mA, mB, mDelta), DIM_ARR_PUNTO, TITOLO_FUOCO);
	leggiCoordinate(creaArrayVertice(mA, mB, mDelta), DIM_ARR_PUNTO, TITOLO_VERTICE);

	// Output intersezioni asse X se presenti
	if(possiedeIntersezioni(mDelta)) {
		leggiCoordinate(creaArrayIntersezioni(mA, mB, mDelta), DIM_ARR_INTERSEZIONI, TITOLO_INTERSEZIONI);
	} else {
		cout << NO_INTERSEZIONI << endl; 
	}

	return 0;
}
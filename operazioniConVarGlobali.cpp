/*
	Programma che calcola somma, prodotto, quoziente e divisione con resto
	su due interi
*/

#include <iostream>

using namespace std;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Inserisci due numeri interi: ";
char OPERATORE_MOLTIPLICAZIONE[] = " * ";
char OPERATORE_ADDIZIONE[] = " + ";
char OPERATORE_DIVISIONE[] = " / ";
char OPERATORE_DIVISIONE_C_R[] = " : ";
char OPERATORE_RESTO[] = " MOD ";
char UGUALE[] = " = ";

// Costanti (per l'array della divisione con resto)
const int DIM_ARRAY = 2;
const int POS_QUOTO = 0;
const int POS_RESTO = 1;


// Funzione per calcolare la somma
int calcolaSomma(int a, int b) {
	return a + b;
}

// Funzione per calcolare il prodotto
int calcolaProdotto(int a, int b) {
	return a * b;
}

// Funzione per calcolare il quoziente
float calcolaQuoziente(float a, float b) {
	return a / b;
}

// Funzione per calcolare la divisione con il resto
int * calcolaDivisioneConResto(int a, int b) {
	static int array[DIM_ARRAY];

	array[POS_QUOTO] = a / b;
	array[POS_RESTO] = a % b;

	return array;
}

// Funzione unica per stampare un'operazione dati i 2 numeri, l'operatore e il risultato
void leggiRisultato(int a, int b, char operatore[], float risultato) {
	cout << a << operatore << b << UGUALE << risultato << endl;
}

int main() {
	// Dichiarazione variabili
	int mA, mB;

	// Input variabili
	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mA >> mB;

	// Calcolo valori e output
	leggiRisultato(mA, mB, OPERATORE_ADDIZIONE, calcolaSomma(mA, mB));
	leggiRisultato(mA, mB, OPERATORE_MOLTIPLICAZIONE, calcolaProdotto(mA, mB));
	leggiRisultato(mA, mB, OPERATORE_DIVISIONE, calcolaQuoziente(mA, mB));
	leggiRisultato(mA, mB, OPERATORE_DIVISIONE_C_R, calcolaDivisioneConResto(mA, mB)[POS_QUOTO]);
	leggiRisultato(mA, mB, OPERATORE_RESTO, calcolaDivisioneConResto(mA, mB)[POS_RESTO]);

	return 0;
}
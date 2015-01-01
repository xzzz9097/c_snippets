/*
	Programma che calcola somma, prodotto, quoziente e divisione con resto
	su due interi
*/

#include <iostream>

using namespace std;

// Stringhe e operatori
char SUGGERIMENTO_INPUT[] = "Inserisci due numeri interi: ";
char OP_MOLT[] = " * ";
char OP_ADD[] = " + ";
char OP_DIV[] = " / ";
char OP_DIV_C_R[] = " : ";
char OP_RESTO[] = " MOD ";
char UGUALE[] = " = ";

// Costanti (per l'array della divisione con resto)
const int DIM_ARRAY = 2;
const int POS_QUOTO = 0;
const int POS_RESTO = 1;

// Funzione per calcolare la somma
void calcolaSomma(int a, int b, int *somma) {
	*somma = a + b;
}

// Funzione per calcolare il prodotto
void calcolaProdotto(int a, int b, int *prodotto) {
	*prodotto = a * b;
}

// Funzione per calcolare il quoziente
void calcolaQuoziente(float a, float b, float *quoziente) {
	*quoziente = a / b;
}

// Funzione per calcolare la divisione con il resto
void calcolaDivConResto(int a, int b, int array[]) {
	array[POS_QUOTO] = a / b;
	array[POS_RESTO] = a % b;
}

// Funzione unica per stampare un'operazione dati i 2 numeri,
// l'operatore e il risultato
void leggiRisultato(int a, int b, char operatore[], float risultato) {
	cout << a << operatore << b << UGUALE << risultato << endl;
}

int main() {
	// Dichiarazione variabili
	int mA, mB;
	int mSomma, mProdotto;
	float mQuoziente;
	int mDivConResto[DIM_ARRAY];

	// Input variabili
	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mA >> mB;

	// Assegnazione risultati usando funzioni con parametro-puntatore.
	// Il valore puntato viene modificato all'interno della funzione,
	// fornendo il risultato utilizzabile nel main().
	calcolaSomma(mA, mB, &mSomma);
	calcolaProdotto(mA, mB, &mProdotto);
	calcolaQuoziente(mA, mB, &mQuoziente);
	calcolaDivConResto(mA, mB, mDivConResto);

	// Output
	leggiRisultato(mA, mB, OP_ADD, mSomma);
	leggiRisultato(mA, mB, OP_MOLT, mProdotto);
	leggiRisultato(mA, mB, OP_DIV, mQuoziente);
	leggiRisultato(mA, mB, OP_DIV_C_R, mDivConResto[POS_QUOTO]);
	leggiRisultato(mA, mB, OP_RESTO, mDivConResto[POS_RESTO]);

	return 0;
}
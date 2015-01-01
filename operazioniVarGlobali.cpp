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

// Variabili globali
int mA, mB;
int mSomma, mProdotto;
float mQuoziente;
int mDivisioneConResto[DIM_ARRAY];

// Funzione per calcolare la somma
void calcolaSomma() {
	mSomma = mA + mB;
}

// Funzione per calcolare il prodotto
void calcolaProdotto() {
	mProdotto = mA * mB;
}

// Funzione per calcolare il quoziente
void calcolaQuoziente() {
	mQuoziente = (float) mA / (float) mB;
}

// Funzione per calcolare la divisione con il resto
void calcolaDivisioneConResto() {
	mDivisioneConResto[POS_QUOTO] = mA / mB;
	mDivisioneConResto[POS_RESTO] = mA % mB;
}

// Funzione unica per stampare un'operazione dati i 2 numeri, l'operatore e il risultato
void leggiRisultato(char operatore[], float risultato) {
	cout << mA << operatore << mB << UGUALE << risultato << endl;
}

int main() {
	// Input variabili
	cout << SUGGERIMENTO_INPUT << endl;
	cin >> mA >> mB;

	// Assegnazione risultati
	calcolaSomma();
	calcolaProdotto();
	calcolaQuoziente();
	calcolaDivisioneConResto();

	// Output
	leggiRisultato(OPERATORE_ADDIZIONE, mSomma);
	leggiRisultato(OPERATORE_MOLTIPLICAZIONE, mProdotto);
	leggiRisultato(OPERATORE_DIVISIONE, mQuoziente);
	leggiRisultato(OPERATORE_DIVISIONE_C_R, mDivisioneConResto[POS_QUOTO]);
	leggiRisultato(OPERATORE_RESTO, mDivisioneConResto[POS_RESTO]);

	return 0;
}
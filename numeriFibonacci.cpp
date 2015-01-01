/*
	Stampo la successione di Fibonacci con una funzione ricorsiva
*/	

#include <iostream>

using namespace std;

// Stringhe
char SUGGERIMENTO_INPUT[] = "Quanti numeri della successione di Fibonacci vuoi mostrare? ";
char SPAZIO[] = " ";

/* 
	Funzione ricorsiva per stampare la sequenza di Fibonacci
	i: variabile-contatore che permette di rendere ricorsiva la funzione
	numeroAttuale: il numero da stampare
	numeroPrecedente: il numero stampato al "ciclo" precedente
*/	
int calcolaFibonacci(int i, int numeroAttuale, int numeroPrecedente) {
	// Inizializzo il prossimo numero di Fibonacci a 0
	int numeroFibonacci = 0;
    
	// Uso la condizione (i > 0) per uscire dalla funzione quando necessario
	if (i > 0) {
		// Stampo il numero attuale ricevuto come parametro
		cout << SPAZIO << numeroAttuale;
		// Creo il prossimo numero con i parametri aggiornati
		numeroFibonacci = calcolaFibonacci(
						// Decremento il "contatore"
						i - 1,
						// Uso come 'numeroAttuale' la somma
						// fra quello attuale e il precedente
						numeroAttuale + numeroPrecedente,
						// Uso come 'numeroPrecedente' quello attuale
						numeroAttuale
					);
	}
    
	// Restituisco il prossimo numero di Fibonacci
	return numeroFibonacci;
}

int main() {
    // Dichiarazione e inizializzazione variabili
    int mNumeroTentativi;
    int mNumeroAttuale = 1;
    int mNumeroPrecedente = 0;
    
    // Input numero tentativi
    cout << SUGGERIMENTO_INPUT;
    cin >> mNumeroTentativi;
    
    // Avvio funzione
    calcolaFibonacci(mNumeroTentativi, mNumeroAttuale, mNumeroPrecedente);

    // Fine riga
    cout << endl;
     
    return 0;   
}
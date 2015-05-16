/*
	Uso un file come sorgente di input.
*/

// Import
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Stringhe
char INPUT[] = "Inserisci il nome del file di testo: ";
char ERRORE_FILE_NON_TROVATO[] = "file non trovato";
char OUTPUT[] = "Output: ";

string richiediNomeFile() {
	string nome;

	cout << INPUT;
	cin >> nome;

	return nome;
}

/* 
	Creo il flusso e ne ritorno il puntatore che verrà poi usato
	nelle altre funzioni. Non posso ritornare direttamente il flusso
	in quanto la funzione di copiatura in memoria ha accesso privato.
*/
ifstream * apriFile() {
	string nome = richiediNomeFile();

	return new ifstream(nome); // Funziona anche senza c_str()?
}

void chiudiFile(ifstream * file) {
	file -> close(); // Uso le funzioni dell'oggetto del punt. con '->'
}

string ricavaStringaDaFile(ifstream * file) {
	string stringaRicavata;

	// Verifico che il file sia aperto
	if (file -> is_open()) {
		*file >> stringaRicavata; // Ricavo l'oggetto dal puntatore

		chiudiFile(file);
	} else {
		stringaRicavata = ERRORE_FILE_NON_TROVATO;
	}

	return stringaRicavata;
}

void output(char titolo[], string valore) {
	cout << titolo << valore << endl;
}

int main() {
	output(OUTPUT, ricavaStringaDaFile(apriFile()));
}

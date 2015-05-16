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
	C++11 permette la return dei flussi senza ricorrere a puntatori.
	La return non invoca la la funzione "copy" ma quella "move".
*/
ifstream apriFile() {
	string nome = richiediNomeFile();

	return ifstream(nome);
}

void chiudiFile(ifstream file) {
	file.close();
}

string ricavaStringaDaFile(ifstream file) {
	string stringaRicavata;

	// Verifico che il file sia aperto
	if (file.is_open()) {
		file >> stringaRicavata;

		// Uso la funzione "move" per passare il flusso come parametro
		chiudiFile(move(file));
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

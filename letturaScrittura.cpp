/*
    Scrittura e lettura (con array) di un file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char INPUT_NOME_FILE[] = "Inserisci il nome del file: ";
char INPUT_LINEE_TESTO[] = "Inserisci il numero di linee di testo: ";
char INPUT_LINEA_TESTO[] = "Linea: ";

string richiediTesto(char SUGGERIMENTO[]) {
    string testo;

    cout << SUGGERIMENTO;
    cin >> testo;

    return testo;
}

int richiediIntero(char SUGGERIMENTO[]) {
    int intero;

    cout << SUGGERIMENTO;
    cin >> intero;

    return intero;
}

ifstream * apriFileLettura(string nome) {
    return new ifstream(nome.c_str());
}

ofstream * apriFileScrittura(string nome) {
    return new ofstream(nome.c_str());
}

// Uso un "template" per l'argomento della funzione chiudiFile()
// per poterla usare sia con "ifstream" sia con "ofstream".
template <typename filestream>
void chiudiFile(filestream * file) {
    file -> close();
}

void scriviFile(ofstream * file, int LUNGHEZZA, char SUGGERIMENTO[]) {
    for (int i = 0; i < LUNGHEZZA; i++) {
        string linea = richiediTesto(SUGGERIMENTO);
        *file << linea << endl;
    }

    chiudiFile(file);
}

string * leggiFile(ifstream * file) {
    const int LUNGHEZZA_MASSIMA_ARRAY = 100;
    static string arrayLinee[LUNGHEZZA_MASSIMA_ARRAY];

    int i = -1;
    while (!(file -> eof())) {
        i++;
        *file >> arrayLinee[i];
    }

    chiudiFile(file);

    return arrayLinee;
}

void leggiArray(string * array, int LUNGHEZZA) {
    for (int i = 0; i < LUNGHEZZA; i++) {
        cout << array[i] << endl;
    }
}

int main() {
    // Richiedo il nome del file
    string mNomeFile = richiediTesto(INPUT_NOME_FILE);
    int mLunghezzaFile = richiediIntero(INPUT_LINEE_TESTO);

    // Apro i flussi di lettura e scrittura
    // Non serve valutare la presenza del file con is_open() perchè
    // se mancante viene creato automaticamente.
    ofstream * mFileScrittura = apriFileScrittura(mNomeFile);
    ifstream * mFileLettura = apriFileLettura(mNomeFile);

    // Scrivo e leggo il file, chiudendo i flussi
    scriviFile(mFileScrittura, mLunghezzaFile, INPUT_LINEA_TESTO);
    string * mArrayFile = leggiFile(mFileLettura);

    // Stampo l'array con il contenuto del file
    leggiArray(mArrayFile, mLunghezzaFile);
}

#include <iostream>
#include <ctime>

using namespace std;

static int VOTO_RIFERIMENTO = 6;
static const int MASSIMO_VOTI = 3;
static const int MASSIMO_STUDENTI = 3;
static string NOMI_ALUNNI[MASSIMO_STUDENTI] = {"Luca", "Tommaso", "Massimo"};

class Studente
{
private:
	string nomeStudente;
	int votiStudente[MASSIMO_VOTI];
	double mediaStudente;
public:
	Studente() {
		nomeStudente = "";
		
		for (int i = 0; i < MASSIMO_VOTI; ++i) {
			votiStudente[i] = 0;
		}

		mediaStudente = 0;
	}

	Studente(string nome, int voti[]) {
		setNome(nome);

		setVoti(voti);

		calcolaMedia();
	}

	void setNome(string nome) {
		nomeStudente = nome;
	}

	void setVoti(int voti[]) {
		int i = 0;
		while (voti[i] > 0 && voti[i] < 11) {
			votiStudente[i] = voti[i];			
			i++;
		}
	}

	void calcolaMedia() {
		int i = 0;
		
		mediaStudente = 0;
		while (votiStudente[i] > 0 && votiStudente[i] < 11) {
			mediaStudente += votiStudente[i];
			i++;
		}

		mediaStudente /= (i);
	}

	float getMedia() {
		return mediaStudente;
	}

	void stampaDati() {
		// Stampo il nome
		cout << "Nome: " << nomeStudente << endl;

		// Stampo la media dei voti
		cout << "Media voti: " << mediaStudente;

		// Stampo l'esito
		if (mediaStudente < VOTO_RIFERIMENTO) {
			cout << " Insufficiente" << endl;
		} else {
			cout << " Sufficiente" << endl;
		}

		cout << endl;
	}
};

void caricaCasuali() {
	srand(time(NULL));
}

void stampaMediaTotale(Studente studenti[]) {
	float mediaStudenti = 0;
	for (int i = 0; i < MASSIMO_STUDENTI; ++i) {
		mediaStudenti += studenti[i].getMedia();
	}

	mediaStudenti /= 3;

	cout << "Media totale: " << mediaStudenti << endl;
}

int * arrayVotiCasuali() {
	static int voti[MASSIMO_VOTI] = {0};
		for (int i = 0; i < MASSIMO_STUDENTI; ++i) {
		 	voti[i] = rand() % 10 + 1;
	}

	return voti;
}

int main() {
	caricaCasuali();

	Studente mStudenti[MASSIMO_STUDENTI] = {Studente()};

	for (int i = 0; i < MASSIMO_STUDENTI; ++i) { 
		mStudenti[i] = Studente(NOMI_ALUNNI[i], arrayVotiCasuali());
	}

	for (int i = 0; i < MASSIMO_STUDENTI; ++i) {
		mStudenti[i].stampaDati();
	}

	stampaMediaTotale(mStudenti);
}
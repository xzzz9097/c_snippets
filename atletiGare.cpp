#include <iostream>
#include <ctime>

using namespace std;

static const int ATLETI = 10;
static const int GARE = 3;

class Gara {
public:
    static const int PARTECIPANTI = ATLETI;

    static const int TEMPO_MINIMO = 50;
    static const int TEMPO_MASSIMO = 70;
    static const int TEMPO_AMMISSIONE = 60;
private:
    int tempiAtleti[PARTECIPANTI];
public:
    Gara() {};

    Gara(int tempi[]) {
        setTempi(tempi);
    }

    void setTempi(int tempi[]) {
        for (int i = 0; i < PARTECIPANTI; i++) {
            tempiAtleti[i] = tempi[i];
        }
    }

    int getTempo(int indice) {
        return tempiAtleti[indice];
    }
};

class Atleta {
public:
    static const int TEMPI = GARE;
private:
    int indiceAtleta;
    int tempiAtleta[TEMPI];
    float mediaAtleta;
    bool atletaAmmesso;
public:
    Atleta() {};

    Atleta(int indice, int tempi[]) {
        setIndiceAtleta(indice);
        setTempi(tempi);
        setMedia();
        setAmmesso();
    }

    void setIndiceAtleta(int indice) {
        indiceAtleta = indice;
    }

    int getIndiceAtleta() {
        return indiceAtleta;
    }

    void setTempi(int tempi[]) {
        for (int i = 0; i < TEMPI; i++) {
            tempiAtleta[i] = tempi[i];
        }
    }

    void setMedia() {
        mediaAtleta = 0;

        for (int i = 0; i < TEMPI; i++) {
            mediaAtleta += tempiAtleta[i];
        }

        mediaAtleta /= TEMPI;
    }

    float getMedia() {
        return mediaAtleta;
    }

    void setAmmesso() {
        if (mediaAtleta < Gara().TEMPO_AMMISSIONE) {
            atletaAmmesso = true;
        } else {
            atletaAmmesso = false;
        }
    }

    bool getAmmesso() {
        return atletaAmmesso;
    }

    void stampaDatiAtleta() {
        cout <<
                "Atleta " <<
                getIndiceAtleta() + 1 <<
                " " <<
                getMedia() <<
                " " <<
                getAmmesso() <<
        endl;
    }
};

int * creaArrayTempi() {
    static int tempi[ATLETI];

    for (int i = 0; i < ATLETI; i++) {
        tempi[i] = Gara().TEMPO_MINIMO + rand() % (Gara().TEMPO_MINIMO - Gara().TEMPO_MASSIMO);
    }

    return tempi;
}

void caricaCasuali() {
    srand(time(NULL));
}

int main() {
    caricaCasuali();

    Gara mGare[GARE] = {Gara()};
    Atleta mAtleti[ATLETI] = {Atleta()};

    for (int i = 0; i < GARE; i++) {
        mGare[i] = Gara(creaArrayTempi());
    }

    for (int i = 0; i < ATLETI; i++) {
        int mTempiAtleta[GARE];

        for (int j = 0; j < GARE; j++) {
            mTempiAtleta[j] = mGare[j].getTempo(i);
        }

        mAtleti[i] = Atleta(i, mTempiAtleta);
    }

    for (int i = 0; i < ATLETI; i++) {
        mAtleti[i].stampaDatiAtleta();
    }
}

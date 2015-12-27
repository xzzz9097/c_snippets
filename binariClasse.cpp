#include <iostream>
#include <cmath>

using namespace std;

class NumeroBinario {
protected:
    static const int CIFRE = 8;
    int numeroIntero = 0;
    int numeroBinario[CIFRE] = {0};
public:
    int getCifra(int posizione) {
        return numeroBinario[posizione];
    }

    void daIntero(int numero) {
        numeroIntero = numero;

        int i = CIFRE - 1;
        while (numeroIntero > 0) {
            numeroBinario[i] = numeroIntero % 2;
            i--;
            numeroIntero /= 2;
        }
    }

    NumeroBinario(int numero) {
        daIntero(numero);
    }

    void somma(NumeroBinario binario);

    void leggi() {
        for (int i = 0; i < CIFRE; i++) {
            cout << numeroBinario[i];
        }

        cout << endl;
    }
};

void NumeroBinario :: somma(NumeroBinario binario) {
    for (int i = CIFRE - 1; i >= 0; i--) {
        numeroBinario[i] += binario.getCifra(i);

        if (getCifra(i) > 1) {
            numeroBinario[i-1] += numeroBinario[i] - 1;
            numeroBinario[i] %= 2;
        }
    }
}

class NumeroEsadecimale : public NumeroBinario {
    // Un numero esadecimale è un insieme di cifre binarie scelte 4 a 4
    static const int CIFRE_ESADECIMALI = CIFRE / 4;
    char numeroEsadecimale[CIFRE_ESADECIMALI] = {"g"};

    char NUMERAZIONE_ESADECIMALE[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                                        '9', 'A', 'B', 'C', 'D', 'E', 'F'};
public:
    void daBinario() {
        int decimale = 0;
        int j = 0;

        for (int i = 0; i < CIFRE; i++) {
            decimale += numeroBinario[i] * pow(2, 3 - j);
            j++;
            if (j == 4) {
                numeroEsadecimale[i/4] = NUMERAZIONE_ESADECIMALE[decimale];
                decimale = 0;
                j = 0;
            }
        }
    }

    NumeroEsadecimale(int numero) : NumeroBinario(numero) {
        daBinario();
    }

    void leggi() {
        for (int i = 0; i < CIFRE_ESADECIMALI; i++) {
            cout << numeroEsadecimale[i];
        }

        cout << endl;
    }
};

int main() {
    NumeroBinario mPrimoBinario(20);
    NumeroBinario mSecondoBinario(5);
    NumeroEsadecimale mNumeroEsadecimale(20);

    mPrimoBinario.leggi();

    mPrimoBinario.somma(mSecondoBinario);
    mPrimoBinario.leggi();

    mNumeroEsadecimale.leggi();
}

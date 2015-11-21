#include <iostream>

using namespace std;

class Rettangolo {
    string NOME;
    float a,b;
public:
    void setNome(string nome) {
        NOME = nome;
    }

    Rettangolo(float a, float b) {
        this -> a = a;
        this -> b = b;
        setNome("Rettangolo ");
    }

    float calcolaPerimetro() {
        return (a+b)*2;
    }

    float calcolaArea() {
        return a*b;
    }

    void stampaDati() {
        cout << NOME << a << " x " << b << endl;
        cout << "Perimetro = " << calcolaPerimetro() << endl;
        cout << "Area = " << calcolaArea() << endl;
    }
};

class Quadrato : public Rettangolo {
public:
    Quadrato(float lato) : Rettangolo(lato, lato) {
        setNome("Quadrato ");
    }
};

int main() {
    Rettangolo mRettangolo(2,3);
    mRettangolo.stampaDati();

    Quadrato mQuadrato(4);
    mQuadrato.stampaDati();
}

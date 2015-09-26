#include <iostream>

using namespace std;

class Calcolatrice {
    double x, y;
public:
    Calcolatrice(double primoNumero, double secondoNumero) {
        x = primoNumero>secondoNumero ? primoNumero : secondoNumero;
        y = secondoNumero<primoNumero ? secondoNumero : primoNumero;
    }

    double somma() {
        return x+y;
    }

    double differenza() {
        return x-y;
    }

    double moltiplicazione() {
        return x*y;
    }

    double quoziente() {
        return x/y;
    }

    double resto() {
        return x - (int)quoziente()*y;
    }

    void stampaValori() {
        cout << x << " + " << y << " = " << somma() << "\n";
        cout << x << " - " << y << " = " << differenza() << "\n";
        cout << x << " / " << y << " = " << quoziente() << "\n";
        cout << x << " MOD " << y << " = " << resto() << "\n";
    }
};

int main() {
    Calcolatrice mCalcolatrice = Calcolatrice(3.0, 10.0);

    mCalcolatrice.stampaValori();
}

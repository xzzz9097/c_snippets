#include <iostream>
#include <cmath>

using namespace std;

class PuntoPiano {
protected:
    int x,y;
public:
    void setX(int x) {
        this -> x = x;
    }

    void setY(int y) {
        this -> y = y;
    }

    PuntoPiano(int x, int y) {
        setX(x);
        setY(y);
    }

    float calcolaDistanzaOrigine() {
        return sqrt(x*x+y*y);
    }
};

class PuntoSpazio : public PuntoPiano {
protected:
    int z;
public:
    void setZ(int z) {
        this -> z = z;
    }

    PuntoSpazio(int x, int y, int z) : PuntoPiano(x, y) {
        setZ(z);
    }

    float calcolaDistanzaOrigine() {
        return sqrt(x*x+y*y+z*z);
    }
};

int main() {
    PuntoPiano mPuntoPiano(2, 3);
    PuntoSpazio mPuntoSpazio(2, 3, 4);

    cout << "Distanza punto (2, 3): " << mPuntoPiano.calcolaDistanzaOrigine() << endl;
    cout << "Distanza punto (2, 3, 4): " << mPuntoSpazio.calcolaDistanzaOrigine() << endl;
}

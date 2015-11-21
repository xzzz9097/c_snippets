#include <iostream>

using namespace std;

string TIPO[3] = {"Citta'","Fuori citta'","Autostrada"};
float DISTANZA[3] = {10,50,200};
float CARBURANTE[3] = {0.8,2.3,12};

class Automobile {
    float chilometri, litri;
public:
    Automobile() {
        chilometri = 0.0;
        litri = 0.0;
    }

    void setChilometri(float chilometri) {
        this -> chilometri = chilometri;
    }

    void setLitri(float litri) {
        this -> litri = litri;
    }

    float getChilometri() {
        return chilometri;
    }

    float getLitri() {
        return litri;
    }

    float calcolaMedia() {
        return chilometri / litri;
    }
};

int main() {
    Automobile mAutomobile = Automobile();

    for (int i = 0; i < 3; i++) {
        mAutomobile.setChilometri(DISTANZA[i]);
        mAutomobile.setLitri(CARBURANTE[i]);

        cout << TIPO[i] << ": " << mAutomobile.calcolaMedia() << "km/l" << endl;
    }
}

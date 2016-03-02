#include <iostream>
#include "punto_spazio.h"

using namespace std;

int main() {
    PuntoSpazio p = PuntoSpazio(1, 1, 1);

    cout << p.calcolaDistanza() << endl;
}

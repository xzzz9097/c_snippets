#include "punto_piano.h"

PuntoPiano::PuntoPiano(double x, double y) {
    setX(x);
    setY(y);
}

double PuntoPiano::calcolaDistanza() {
    return sqrt(pow(getX(), 2.0) + pow(getY(), 2.0));
}

void PuntoPiano::setX(double x) {
    PuntoPiano::x = x;
}

double PuntoPiano::getX() {
    return x;
}

void PuntoPiano::setY(double y) {
    PuntoPiano::y = y;
}

double PuntoPiano::getY() {
    return y;
}

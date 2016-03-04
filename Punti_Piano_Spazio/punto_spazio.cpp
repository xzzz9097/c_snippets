#include "punto_spazio.h"

PuntoSpazio::PuntoSpazio(double x, double y, double z) : PuntoPiano(x, y) {
    setZ(z);
}

double PuntoSpazio::calcolaDistanza() {
    return sqrt(pow(getX(), 2.0) + pow(getY(), 2.0) + pow(getZ(), 2.0));
}

void PuntoSpazio::setZ(double z) {
    PuntoSpazio::z = z;
}

double PuntoSpazio::getZ() const {
    return z;
}

PuntoSpazio PuntoSpazio::operator+(const PuntoSpazio &p) {
    return PuntoSpazio(getX() + p.getX(), getY() + p.getY(), getZ() + p.getZ());
}

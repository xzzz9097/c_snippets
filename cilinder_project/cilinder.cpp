// Implementation file for Cilinder class

#include <math.h>
#include "cilinder.h"

Cilinder::Cilinder(double r, double h) : Circle(r) {
    Cilinder::setHeigth(h);
}

void Cilinder::setHeigth(double h) {
    heigth = h;
}

double Cilinder::getHeigth() {
    return heigth;
}

double Cilinder::getLateralSurface() {
    return 2 * M_PI * radius * heigth;
}

double Cilinder::getSurface() {
    return Circle::getSurface() * Cilinder::getLateralSurface();
}

double Cilinder::getVolume() {
    return Circle::getSurface() * heigth;
}

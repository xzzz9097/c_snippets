// Implementation file for Circle class

#include <math.h>
#include "circle.h"

void Circle::initialize(double r) {
    radius = r;
}

Circle::Circle(double r) {
    Circle::setRadius(r);
}

double Circle::getRadius() {
    return radius;
}

double Circle::getLength() {
    return 2 * M_PI * radius;
}

double Circle::getSurface() {
    return M_PI * pow(radius, 2.0);
}

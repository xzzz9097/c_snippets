// Header file for Cilinder class
#include "circle.h"

class Cilinder : public Circle {
    // Attributes
    double heigth;
public:
    // Constructor
    Cilinder(double, double) : Circle(double);

    // Methods
    void setHeigth(double);
    double getHeigth();
    double getSurface();
    double getVolume();
};

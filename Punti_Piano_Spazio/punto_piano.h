#include <math.h>

class PuntoPiano {
    double x, y;
public:
    PuntoPiano(double, double);
    double calcolaDistanza();
    void setX(double);
    double getX();
    void setY(double);
    double getY();
};

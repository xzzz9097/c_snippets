#include <math.h>

class PuntoPiano {
    double x, y;
public:
    PuntoPiano(double, double);
    double calcolaDistanza();
    void setX(double);
    double getX() const;
    void setY(double);
    double getY() const;
    PuntoPiano operator+(const PuntoPiano &);
};

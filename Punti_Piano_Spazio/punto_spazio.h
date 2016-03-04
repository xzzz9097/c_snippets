#include "punto_piano.h"

class PuntoSpazio : public PuntoPiano {
    double z;
public:
    PuntoSpazio(double, double, double);
    double calcolaDistanza();
    void setZ(double);
    double getZ() const;
    PuntoSpazio operator+(const PuntoSpazio &);
};

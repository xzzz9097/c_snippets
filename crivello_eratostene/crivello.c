/* File implementazione per Crivello di Eratostene */

#include "crivello.h"

bool *crivelloEratostene() {
    static bool numeriPrimi[PRIMI_MASSIMI] = {false};

    for (int i = SETACCIO_CRIVELLO; i < PRIMI_MASSIMI; i++) {
        if (!numeriPrimi[i]) {
            for (int j = SETACCIO_CRIVELLO; i * j < PRIMI_MASSIMI; j++) {
                numeriPrimi[i*j] = true;
            }
        }
    }

    return numeriPrimi;
}

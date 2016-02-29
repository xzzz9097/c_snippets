/* File implementazione per Crivello di Eratostene */

#include "crivello.h"

bool divisibile(int n, int *d, const int l) {
    bool divisibile = false;

    int i = 0;
    // Verifico che il numero sia divisibile per
    // almeno uno degli elementi dell'array
    while (!divisibile && i < l) {
        divisibile = (n % d[i]) == 0;
        i++;
    }

    return divisibile;
}

int *numeriPrimi(int max) {
    static int numeriPrimi[PRIMI_MASSIMI] = {0};

    int n = 0;
    for (int i = SETACCIO_CRIVELLO; i <= max; i++) {
        if ((i == SETACCIO_CRIVELLO) | !divisibile(i, numeriPrimi, n)) {
            numeriPrimi[n] = i;
            n++;
        }
    }

    return numeriPrimi;
}

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

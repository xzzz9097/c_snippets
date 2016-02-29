/* File implementazione per Crivello di Eratostene */

#include "crivello.h"

bool nonDivisibile(int n, int *d, const int l) {
    bool nonDivisibile = true;

    int i = 0;
    while (nonDivisibile && i < l) {
        nonDivisibile = (n % d[i]) != 0;
        i++;
    }

    return nonDivisibile;
}

int *numeriPrimi(int max) {
    static int numeriPrimi[PRIMI_MASSIMI] = {0};

    int n = 0;
    for (int i = SETACCIO_CRIVELLO; i <= max; i++) {
        if ((i == SETACCIO_CRIVELLO) | nonDivisibile(i, numeriPrimi, n)) {
            numeriPrimi[n] = i;
            n++;
        }
    }

    return numeriPrimi;
}

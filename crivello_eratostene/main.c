#include <stdio.h>
#include <time.h>
#include "crivello.h"

int main() {
    clock_t inizio = clock();

    bool *mNumeriPrimi = crivelloEratostene();

    for (int i = SETACCIO_CRIVELLO; i < PRIMI_MASSIMI; i++) {
        if (!mNumeriPrimi[i]) {
            printf("%d ", i);
        }
    }

    clock_t fine = clock();
    double trascorso = (double) (fine - inizio) / CLOCKS_PER_SEC;

    printf("%f\n", trascorso);
}

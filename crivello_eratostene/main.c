#include <stdio.h>
#include <time.h>
#include "crivello.h"

int main() {
    clock_t inizio = clock();

    int *mNumeriPrimi = numeriPrimi(100);

    int i = 0;
    while (mNumeriPrimi[i] > 0) {
        printf("%d ", mNumeriPrimi[i]);
        i++;
    }

    clock_t fine = clock();
    double trascorso = (double) (fine - inizio) / CLOCKS_PER_SEC;

    printf("%f\n", trascorso);
}

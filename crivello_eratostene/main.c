#include <stdio.h>
#include "crivello.h"

int main() {
    int *mNumeriPrimi = numeriPrimi(100);

    int i = 0;
    while (mNumeriPrimi[i] > 0) {
        printf("%d\n", mNumeriPrimi[i]);
        i++;
    }
}

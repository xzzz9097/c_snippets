#include <stdio.h>
#include "crivello.h"

int main() {
    bool *mNumeriPrimi = crivelloEratostene();

    for (int i = SETACCIO_CRIVELLO; i < PRIMI_MASSIMI; i++) {
        if (!mNumeriPrimi[i]) {
            printf("%d ", i);
        }
    }
}

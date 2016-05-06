#include <stdio.h>
#include "quick_sort.h"

int main() {
    int mArray[10] = {1, 9, 3, 2, 8, 4, 15, 7, 6, 10};

    quickSort(mArray, 0, 9);

    for (int i = 0; i < 10; i++) {
        printf("%d ", mArray[i]);
    }
}

/* File implementazione per Quick Sort */

#include <stdio.h>
#include "quick_sort.h"

void scambia(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int quickSort(int *array, int inizio, int fine) {
    if (fine > inizio) {
        int i = inizio;
        int j = fine;
        int perno = inizio;

        while (i < j) {
            while (array[i] <= array[perno] && i <= fine) {
                i++;
            }

            while (array[j] > array[perno] && i >= inizio) {
                j--;
            }

            if (i < j) {
                scambia(array, i, j);
            }
        }

        scambia(array, perno, j);
        quickSort(array, inizio, j - 1);
        quickSort(array, j + 1, fine);
    }
}

/* 
	arrays.cpp: just a simple arrays test
*/

#include <iostream>
using namespace std;

const int ARRAY_LENGTH = 5;

void fillArray(int array[]) {
	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		array[i] = i;
	}
}

void readArray(int array[]) {
	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		cout << i << " element: " << array[i] << endl;
	}
}

int main() {
	// Variables declaration
	int mArray[ARRAY_LENGTH];

	// Fill the array
	fillArray(mArray);

	// Read and print the array
	readArray(mArray);

	return 0;
}	
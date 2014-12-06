/* 
	secondDegreeEquations.cpp: solves a 2nd degree equations based on parameters
*/

#include <iostream>
#include <cmath>	
using namespace std;

// Constants definition
const int ARRAY_LENGTH = 2;
const char INPUT_PARAMETERS_HINT[] = "Insert a, b and c from ax + by + c = 0";
const char OUTPUT_SOLUTION_HEADER[] = " solution: ";
const char OUTPUT_NO_SOLUTIONS[] = "No solutions.";

float calculateDelta(float a, float b, float c) {
	return (pow(b, 2.0) - 4 * a * c);
}

bool hasSolutions(int delta) {
	return delta >= 0;
}

float * createSolutionsArray(float a, float b, float delta) {
	// Remember to set the static attribute to our array
	static float solutionsArray[ARRAY_LENGTH];

	// Normal array element assignment
	solutionsArray[0] = (- b - sqrt(delta)) / (2 * a);
	solutionsArray[1] = (- b + sqrt(delta)) / (2 * a);

	return solutionsArray;
}

void readArray(float * arrayStart) {
	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		/* This is interesting: arrayStart is the pointer to the first memory cell 
		   occupied by the array: we retrieve the values by deferencing pointer obtained
		   by (arrayStart + i), which is the first element for i = 0, the second for
		   i = 1. Nice! */	
		cout << i << OUTPUT_SOLUTION_HEADER << arrayStart[i] << endl;
	}
}

int main() {
	// Variables declaration
	float mA, mB, mC;

	// Parameters input
	cout << INPUT_PARAMETERS_HINT << endl;
	cin >> mA >> mB >> mC;

	// Execution
	float mDelta = calculateDelta(mA, mB, mC);

	// Check if equation has solutions
	if (hasSolutions(mDelta)) {
		// Get the solutions array
		float * mArrayPointer = createSolutionsArray(mA, mB, mDelta);
		// Read and print the array
		readArray(mArrayPointer);
	} else {
		// No solutions
		cout << OUTPUT_NO_SOLUTIONS << endl;
	}

	return 0;
}	
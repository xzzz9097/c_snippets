/*
	Simple program that sums two numbers given in input.
	Uses input/output library.
*/	
 
#include <iostream>
using namespace std;

int main()
{
    // Initialize vars
    int mFirstNumber = 0, mSecondNumber = 0;

    // Get the inputs
    cout << "Write first number: ";
    cin >> mFirstNumber;
    cout << "Write second number: ";
    cin >> mSecondNumber;
    bool isSecondNumberPositive = mSecondNumber > 0;

    // Do the math
    int mSum = mFirstNumber + mSecondNumber;

    // Just a bit of polish for the negative 2nd number case
    string mSign = isSecondNumberPositive ? " + " : " - ";
    mSecondNumber = isSecondNumberPositive ? mSecondNumber : -mSecondNumber;
    // Output the operation
    // We append a intro, the operation and the newline char
    cout << mFirstNumber << mSign << mSecondNumber << " = " << mSum << "\n";

    // Return statement
    return 0;
}
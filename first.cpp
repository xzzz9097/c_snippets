/*
	Simple program that sums two numbers given in input.
	Uses input/output library.
*/	
 
#include <iostream>
using namespace std;

int main()
{
	// Initialize vars
	int a = 0, b = 0;

	// Get the inputs
	cout << "Write first number: ";
	cin >> a;
	cout << "Write second number: ";
  cin >> b;
  bool isSecondNumberPositive = b > 0;

  // Do the math
  int sum = a + b;

  // Just a bit of polish for the negative 2nd number case
	string sign = isSecondNumberPositive ? " + " : " - ";
  b = isSecondNumberPositive ? b : -b;
  // Output the operation
  // We append a intro, the operation and the newline char
  cout << a << sign << b << " = " << sum << "\n";

  // Return code
  return 0;
}